package server;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import common.Command;
import common.Missile;
import common.Packet;
import common.StringUtil;
import common.Tank;

public class PacketQueue implements Runnable {

	static Logger logger = LoggerFactory.getLogger(PacketQueue.class);
	private BlockingQueue<Packet> queue = new LinkedBlockingQueue<>();

	private Thread thread;
	private boolean isRunning = false;

	public PacketQueue() {
		this.isRunning = true;
		thread = new Thread(this);
		thread.start();
	}

	public void pushPacket(Packet packet) {
		queue.add(packet);
	}

	private void handlePacket(Packet packet) {
		short cmd = packet.getCmd();
		int clientId = packet.getClient().getClientId();
		UserSession session = ServerMain.getServer().getUserSession(clientId);
		switch (cmd) {
		case Command.C_LOGIN: {
			String name = StringUtil.getString(packet.getByteBuffer());
			User user = new User(name);

			session.setUser(user);
			
			GameWorld game = ServerMain.getServer().findProperGameWorld(session);
			int gameId = game.getId();
			user.setGameWorldIndex(gameId);
			
			game.join(session);
			logger.debug("LOGIN, name:{}", name);
			game.getPalyersName().add(name);
			Tank tank =game.initUserTank(clientId);

			Packet writePacket2 = new Packet(Command.S_NEW_TANK,
					Short.MAX_VALUE);
			tank.serialize(writePacket2.getByteBuffer());
			game.sendAllName(writePacket2.getByteBuffer());
			game.broadcast(writePacket2);

			Packet writePacket = new Packet(Command.S_LOGIN, Short.MAX_VALUE);
			writePacket.getByteBuffer().putInt(gameId);
			writePacket.getByteBuffer().putInt(clientId);
			game.serializeAllTanks(writePacket.getByteBuffer());
			game.serializeAllMissiles(writePacket.getByteBuffer());
			packet.getClient().pushWritePacket(writePacket);

		}
			break;
		case Command.C_MOVE: {
			int id = packet.getByteBuffer().getInt();
			int angle = packet.getByteBuffer().getInt();
			logger.debug("C_MOVE, id:{}, angle:{}", id, angle);

			User user = session.getUser();
			GameWorld game = ServerMain.getServer().getGameWorld(user.getGameWorldIndex());
			game.move(clientId, id, angle);

			Packet writePacket = new Packet(Command.S_MOVE, Short.MAX_VALUE);
			writePacket.getByteBuffer().putInt(clientId);
			writePacket.getByteBuffer().putInt(id);
			writePacket.getByteBuffer().putInt(angle);
			game.broadcast(writePacket);

		}
			break;
		case Command.C_STOP: {
			int tankId = packet.getByteBuffer().getInt();
			User user = session.getUser();
			GameWorld game = ServerMain.getServer().getGameWorld(user.getGameWorldIndex());
			game.stop(clientId, tankId);
			logger.debug("C_STOP, id:{}", tankId);

			Packet writePacket = new Packet(Command.S_STOP, 8);
			writePacket.getByteBuffer().putInt(clientId);
			writePacket.getByteBuffer().putInt(tankId);
			game.broadcast(writePacket);
		}
			break;
		case Command.C_NEW_MISSILE: {
			int tankId = packet.getByteBuffer().getInt();
			logger.debug("C_NEW+MISSILE, tanlId:" + tankId);
			User user = session.getUser();
			GameWorld game = ServerMain.getServer().getGameWorld(user.getGameWorldIndex());
			Missile missile = game.initTankMissile(tankId);

			Packet writePacket = new Packet(Command.S_NEW_MISSILE);
			writePacket.getByteBuffer().putInt(tankId);
			writePacket.getByteBuffer().putInt(missile.getId());

				game.broadcast(writePacket);

		}
			break;
		default:
			break;
		}
	}

	@Override
	public void run() {
		logger.info("PacketQueue started....");
		while (isRunning) {
			try {
				Packet packet = queue.take();
				handlePacket(packet);
			} catch (InterruptedException e) {
				e.printStackTrace();
				break;
			}
		}
	}
}
