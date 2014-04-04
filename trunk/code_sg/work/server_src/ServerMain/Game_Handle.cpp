
// Game_Handle1.cpp: implementation of the Game_Handle class.
//
//////////////////////////////////////////////////////////////////////

#include "Game_Handle.h"
#include "../GameWorld/World.h"

//class Game_Handle {};
//--Game_Task_Worker Handle
#include "Game_Task_Worker.h"

#include "DPHandle.h"

#include "../GameWorld/RoleSession.h"
#include "../GameWorld/GW_ObjectMgr.h"


#include "DPHandle.h"

//--xx2009_2_16--#include "GS_Building.h"

#include "../GameWorld/AuthSession.h"
#include "../GameWorld/RoleSession.h"
#include "../GameWorld/GW_ObjectMgr.h"

#include "../GameWorld/WorldTimer.h"

#include "Game_Task_Worker.h"
#include "DPHandle.h"

//--xx2009_2_16--#include "GS_Building.h"

#include "../GameWorld/AuthSession.h"
#include "../GameWorld/RoleSession.h"
#include "../GameWorld/GW_ObjectMgr.h"

#include "DBMysql.h"

#include "../GameWorld/MCity.h"

int Game_Handle::HandleLogon(RSSS& rs, DP &dp)
{
	ACE_DEBUG((LM_DEBUG, " GTWorker::HandleLogon...\n"));

	//ACE_ASSERT( rs.session_sb );
	SB &sb = *rs.session_sb;

	//ACE_ASSERT( rs.player );
	//Player &player = *rs.player;
	
	//--{//--params
	ASSS session;
	dp >> session.sid;//--roleid
	dp >> session.key.keys[0]
		>> session.key.keys[1]
		>> session.key.keys[2]
		>> session.key.keys[3]
		;
	ACE_DEBUG((LM_DEBUG, " roleid=%d session=%08X %08X %08X %08X\n"
		, session.sid
		, session.key.keys[0], session.key.keys[1]
		, session.key.keys[2], session.key.keys[3]
		));
	//--}//--params
	dp.reset();

	uint32 sid = session.sid;//--roleid

	//--
	if (sid <= 0 || 0xFFFFFFFF == sid) sid = 1;
	//--sid
	if (sid <= 0 || 0xFFFFFFFF == sid)
	{
		return _LoginInvalidSid(sb, dp);
//--xx2009_2_16--		return DPHandle(dp, sb).LoginInvalidSid();
	}

	if ( true != ASSS::auth(session) )
	{
		return _LoginInvalidSid1(sb, dp);
//--xx2009_2_16--		return DPHandle(dp, sb).LoginInvalidSid1();
	}

	do {//--while (0);
		
		RSSS *pSession = 0;
		objmgr.RSSS_get(&sb, pSession);
		if (!pSession)
		{
			ACE_DEBUG((LM_DEBUG, " GTWorker::HandleLogon...RoleSession null\n"));
			
			//--Player
			//--GetPlayer
			Player *pPlayer = objmgr.GetPlayer(sid);
			//--
			if (!pPlayer)
			{
				RSSS rs_tmp(rs.session_sb, 0);
				rs_tmp.session_sid = sid;
				if ( FirstLogon(rs_tmp, dp) )
				{
					DPHandle(dp, sb).SendPacket();//_ok();
					break;
				}
				return DPHandle(dp, sb).error_msg(0, "--���ȴ�����ɫ--");
			}
			ACE_ASSERT(pPlayer);
			//--fatal
			if (!pPlayer)
			{
				return DPHandle(dp, sb).error_close();
				//break;
			}

ACE_DEBUG((LM_DEBUG, "��ʵ��(��Ҫ���������Ӷ���½����/��ʱ�Ȳ���)%l:%N:[p%@](P%P)(t%t) GTWorker::HandleLogon...\n", this));
			
			//--new session
			pSession = new RoleSession(&sb, pPlayer);
			ACE_ASSERT(pSession);
			//--fatal
			if (!pSession)
			{
				return DPHandle(dp, sb).error_close();
				//break;
			}
			
			//--set sid
			pSession->session_sid = sid;
			//--set session
			objmgr.RSSS_put(pSession);
			
			//--test/check
			{
				RSSS *p = 0;
				objmgr.RSSS_get(&sb, p);

			//	rs = *pSession;
			}
		}
		
		//--sid
		if ( true != pSession->Valid(sid) )
		{
			return _LoginInvalidSid2(sb, dp);
//--xx2009_2_16--			return DPHandle(dp, sb).LoginInvalidSid2();
			//break;
		}

		ACE_ASSERT(pSession);
		ACE_ASSERT(pSession->session_player);
		ACE_ASSERT(pSession->session_sb);
		ACE_ASSERT(pSession->session_sid);

		pSession->session_player->dump_player();
		
		if (true != LogonOK(*pSession, dp))
		{
			return DPHandle(dp, sb).error_close(0, "��½ʧ��");
		}
		
	} while (0);
	
	ACE_DEBUG((LM_DEBUG, " GTWorker::HandleLogon...ok.\n"));
	return 0;
}
int Game_Handle::HandleLogonCRole(RSSS& rs, DP &dp)
{
	static World &world = worldWorld;
	ACE_DEBUG((LM_DEBUG, " GTWorker::HandleLogonCRole...\n"));

	//ACE_ASSERT( rs.session_sb );
	SB &sb = *rs.session_sb;

	//return DPHandle(dp, sb).test();

	//ACE_ASSERT( rs.player );
	//Player &player = *rs.player;
	
	//--{//--params
	ASSS session;
	dp >> session.sid;//--roleid
	dp >> session.key.keys[0]
		>> session.key.keys[1]
		>> session.key.keys[2]
		>> session.key.keys[3]
		;
	string roleName;//--��������
	dp >> roleName;
	string cityName;//--�ǳ�����
	dp >> cityName;
	int code;//--ѡ�����򣨺�ָ̨�����ĸ�����
	dp >> code;
	//--}//--params
	dp.reset();

	ACE_DEBUG((LM_DEBUG, " roleid=%d session=%08X %08X %08X %08X\n"
		, session.sid
		, session.key.keys[0], session.key.keys[1]
		, session.key.keys[2], session.key.keys[3]
		));
	ACE_DEBUG((LM_DEBUG, " roleName=%s\t cityName=%s code=%d\n"
		, roleName.c_str()
		, cityName.c_str()
		, code
		));
	if (roleName.size() < 1)
	{
		return DPHandle(dp, sb).error_close(0, "name invalid �û�����Ч");
	}

	uint32 sid = session.sid;//--roleid

	//--
	if (sid <= 0 || 0xFFFFFFFF == sid) sid = 1;
	//--sid
	if (sid <= 0 || 0xFFFFFFFF == sid)
	{
		return _LoginInvalidSid(sb, dp);
//--xx2009_2_16--		return DPHandle(dp, sb).LoginInvalidSid();
	}

	if ( true != ASSS::auth(session) )
	{
		return _LoginInvalidSid1(sb, dp);
//--xx2009_2_16--		return DPHandle(dp, sb).LoginInvalidSid1();
	}

	if (DBHandleGame::role_name(sid).size() > 0)
	{
		return DPHandle(dp, sb).error_close(0, "name exist ʧ�� �û����Ѿ�����");
	}

	if (true != DBHandleGame::role_name(sid, roleName))
	{
		return DPHandle(dp, sb).error_close(0, "craete name ʧ�� �����û���ʧ��");
		//break;
	}

	do {//--while (0);
		
		RSSS *pSession = 0;
		objmgr.RSSS_get(&sb, pSession);
		if (!pSession)
		{
			ACE_DEBUG((LM_DEBUG, " GTWorker::HandleLogon...RoleSession null\n"));
			
			//--Player
			//--GetPlayer
			Player *pPlayer = objmgr.GetPlayer(sid);
			//--CreatePlayer
			if (!pPlayer)
			{
				pPlayer = world.CreatePlayer(INVALID_AREA_ID
					, roleName.c_str()
					, cityName.c_str()
					, sid
					);
			}
			ACE_ASSERT(pPlayer);
			//--fatal
			if (!pPlayer)
			{
				return DPHandle(dp, sb).error_close();
				//break;
			}

ACE_DEBUG((LM_DEBUG, "��ʵ��(��Ҫ���������Ӷ���½����/��ʱ�Ȳ���)%l:%N:[p%@](P%P)(t%t) GTWorker::HandleLogonCRole...\n", this));
			
			//--new session
			pSession = new RoleSession(&sb, pPlayer);
			ACE_ASSERT(pSession);
			//--fatal
			if (!pSession)
			{
				return DPHandle(dp, sb).error_close();
				//break;
			}
			
			//--set sid
			pSession->session_sid = sid;
			//--set session
			objmgr.RSSS_put(pSession);
			
			//--test/check
			{
				RSSS *p = 0;
				objmgr.RSSS_get(&sb, p);
			}
		}
		
		//--sid
		if ( true != pSession->Valid(sid) )
		{
			return _LoginInvalidSid2(sb, dp);
//--xx2009_2_16--			return DPHandle(dp, sb).LoginInvalidSid2();
			//break;
		}
		
		ACE_ASSERT(pSession);
		ACE_ASSERT(pSession->session_player);
		ACE_ASSERT(pSession->session_sb);
		ACE_ASSERT(pSession->session_sid);

		pSession->session_player->dump_player();

		if (true != LogonOK(*pSession, dp))
		{
			return DPHandle(dp, sb).error_close(0, "������ɫ��½ʧ��");
		}
		
	} while (0);
	
	ACE_DEBUG((LM_DEBUG, " GTWorker::HandleLogonCRole...ok.\n"));
	return 0;
}

//--xx2009_2_16--int DPHandle::LoginInvalidSid()
//--xx2009_2_16--{
//--xx2009_2_16--	ACE_DEBUG((LM_DEBUG, " DPHandle::LoginInvalidSid...\n"));
//--xx2009_2_16--
//--xx2009_2_16--	_dp << "--Server LoginInvalidSid--";
//--xx2009_2_16--
//--xx2009_2_16--//--xx2009_1_13--	_dp.header.status = 0;
//--xx2009_2_16--	_dp.header.error();
//--xx2009_2_16--	_sb.send(&_dp, _dp.header.len);
//--xx2009_2_16--	ACE_DEBUG((LM_DEBUG, "----------------------send close--------------------\n"));
//--xx2009_2_16--	_dp.dump();
//--xx2009_2_16--
//--xx2009_2_16--	_sb.close();
//--xx2009_2_16--	return 0;
//--xx2009_2_16--}
//--xx2009_2_16--int DPHandle::LoginInvalidSid1()
//--xx2009_2_16--{
//--xx2009_2_16--	ACE_DEBUG((LM_DEBUG, " DPHandle::LoginInvalidSid1...\n"));
//--xx2009_2_16--
//--xx2009_2_16--	_dp << "--Server LoginInvalidSid1--";
//--xx2009_2_16--
//--xx2009_2_16--//--xx2009_1_13--	_dp.header.status = 0;
//--xx2009_2_16--	_dp.header.error();
//--xx2009_2_16--	_sb.send(&_dp, _dp.header.len);
//--xx2009_2_16--	ACE_DEBUG((LM_DEBUG, "----------------------send close--------------------\n"));
//--xx2009_2_16--	_dp.dump();
//--xx2009_2_16--
//--xx2009_2_16--	_sb.close();
//--xx2009_2_16--	return 0;
//--xx2009_2_16--}
//--xx2009_2_16--int DPHandle::LoginInvalidSid2()
//--xx2009_2_16--{
//--xx2009_2_16--	ACE_DEBUG((LM_DEBUG, " DPHandle::LoginInvalidSid2...\n"));
//--xx2009_2_16--
//--xx2009_2_16--	//_dp.header.status = 0;
//--xx2009_2_16--	_dp << "--Server LoginInvalidSid2--";
//--xx2009_2_16--
//--xx2009_2_16--//--xx2009_1_13--	_dp.header.status = 0;
//--xx2009_2_16--	_dp.header.error();
//--xx2009_2_16--	_sb.send(&_dp, _dp.header.len);
//--xx2009_2_16--	ACE_DEBUG((LM_DEBUG, "----------------------send close--------------------\n"));
//--xx2009_2_16--	_dp.dump();
//--xx2009_2_16--
//--xx2009_2_16--	_sb.close();
//--xx2009_2_16--	return 0;
//--xx2009_2_16--}
int Game_Handle::_LoginInvalidSid(SB & sb, DP & dp)
{
	ACE_DEBUG((LM_DEBUG, " Game_Handle::LoginInvalidSid...\n"));

	dp << "--Server LoginInvalidSid--";

//--xx2009_1_13--	_dp.header.status = 0;
	dp.header.error();
	sb.send(&dp, dp.header.len);
	ACE_DEBUG((LM_DEBUG, "----------------------send close--------------------\n"));
	dp.dump();

	sb.close();
	return 0;
}
int Game_Handle::_LoginInvalidSid1(SB & sb, DP & dp)
{
	ACE_DEBUG((LM_DEBUG, " Game_Handle::LoginInvalidSid1...\n"));

	dp << "--Server LoginInvalidSid1--";

//--xx2009_1_13--	_dp.header.status = 0;
	dp.header.error();
	sb.send(&dp, dp.header.len);
	ACE_DEBUG((LM_DEBUG, "----------------------send close--------------------\n"));
	dp.dump();

	sb.close();
	return 0;
}
int Game_Handle::_LoginInvalidSid2(SB & sb, DP & dp)
{
	ACE_DEBUG((LM_DEBUG, " Game_Handle::LoginInvalidSid2...\n"));

	//_dp.header.status = 0;
	dp << "--Server LoginInvalidSid2--";

//--xx2009_1_13--	_dp.header.status = 0;
	dp.header.error();
	sb.send(&dp, dp.header.len);
	ACE_DEBUG((LM_DEBUG, "----------------------send close--------------------\n"));
	dp.dump();

	sb.close();
	return 0;
}
bool Game_Handle::LogonOK(RSSS& rs, DP &dp)
{
	//ACE_ASSERT( rs.session_sb );
	SB &sb = *rs.session_sb;
	Player * player = rs.session_player;
	//ACE_ASSERT( player );
//--xx2009_2_16--	City * city = player->GetCity();
//--xx2009_2_16--	ACE_ASSERT(city);
//--xx2009_2_16--	if (!city)
//--xx2009_2_16--	{
//--xx2009_2_16--		DO_TRACERROR1_WARNING();
//--xx2009_2_16--		return 0;//--false
//--xx2009_2_16--	}
	
	//--more
	return player->OnLogonOK(dp);

//--xx2009_1_13--	DEF_STATIC_REF(World, world, worldWorld);
//--xx2009_1_13--	world.ChatWorld(&player, "hi ��Һ�==");
	
//--xx2009_2_16--	City * pCity = player->GetCity();
//--xx2009_2_16--	ACE_ASSERT(pCity);
//--xx2009_2_16--	if (!pCity)
//--xx2009_2_16--	{
//--xx2009_2_16--		ACE_DEBUG((LM_DEBUG, " LogonOK...null city\n"));
//--xx2009_2_16--		return false;
//--xx2009_2_16--	}
//--xx2009_2_16--	City & city = *pCity;
//--xx2009_2_16--	
//--xx2009_2_16--	//--ok
//--xx2009_2_16--	
//--xx2009_2_16--	dp.reset();
//--xx2009_2_16--	logon(dp, *player, city, rs.session_sid);
//--xx2009_2_16--	sb.Auth(true);
//--xx2009_2_16--	DPHandle(dp, sb).SendPacket();
	
//--xx2009_2_16--	dp.reset();
//--xx2009_2_16--	if (GS_Building::BuildingGetProto(player.m_RoleID, city.m_AreaID, INVALID_BUILDING_ID, dp))
//--xx2009_2_16--		DPHandle(dp, sb).SendPacket();

	return true;
}

bool Game_Handle::FirstLogon(RSSS& rs, DP &dp)
{
	ACE_DEBUG((LM_DEBUG, " FirstLogon...sid=%d\n", rs.session_sid));

	dp.reset();
//--xx2009_1_13--	dp.header.status = dp.header.cmd;

	//--uint8	�Ƿ�Ϊ��һ�ε�½���Ƿ�������ң�	1�ǵ�һ�ε�½
	dp << uint8( 1 );

	return true;
}

bool Game_Handle::logon(DP &dp, Player &player, City &city, uint32 roleid)
{
	static WorldTimer &timer = worldTimer;

	ACE_DEBUG((LM_DEBUG, " logon...roleid=%d\n", roleid));

	dp.reset();

	//--uint8	�Ƿ�Ϊ��һ�ε�½���Ƿ�������ң�	1�ǵ�һ�ε�½
	//dp << uint8( player.LoginCount() < 1 );
	dp << uint8( 0 );
	++(player.m_LoginCount);
	//--
	//--uint32	������ʱ��
	dp << uint32(timer.GetTime());
	//--
	//--uint32	��ɫID
	dp << roleid;
	//--string	��ɫ����
	dp << "���007";
	//--string	��ɫ��λ
	dp << "����";
	//--string	��ɫ��ְ
	dp << "��Ʒ����";
	//--
	//--string	��ɫͷ��URL
	dp << "http://www.google.cn/intl/zh-CN/images/logo_cn.gif";
	//--uint8	�Ƿ��������ֱ�����	1��
	dp << uint8(1);
	//--uint32	��ɫսѫֵ
	dp << uint32(123);
	//--
	//--uint32	��ɫ��������
	dp << uint32(city.m_AreaID);
	//--uint16	���б���ͼID
	dp << uint16(1);
	//--string	��������
	dp << city.m_Name;
	//--uint32	��ɫӵ�лƽ���
	dp << uint32(0);
	//--uint32	��ɫ��ǰ��ʳ����
	dp << uint32( city.Food_get() );
	//--uint32	��ɫ��ǰ��ʳ����
	dp << uint32( city.FoodRate_get() );
	//--uint32	��ɫ��ǰ��ʳ�������
	dp << uint32( city.FoodMax_get() );

	//--uint32	��ɫ��ǰ��������
	dp << uint32( city.Silver_get() );
	//--uint32	��ɫ��ǰ��������
	dp << uint32( city.SilverRate_get() );
	//--uint32	��ɫ��ǰ�����������
	dp << uint32( city.SilverMax_get() );

	//--uint32	��ɫ��ǰ�Ļ�ֵ
	dp << uint32( city.Culture_get() );
	//--uint32	��ɫ���е�ǰ�˿�
	dp << uint32( city.People_get() );
	//--uint8	��ɫ���п���ֵ
	dp << uint8( city.Happy_get() );
	//--
	//--uint8	�Ƿ�����Ա����ľ����ж�
	dp << uint8( 1 );
	//--uint8	�Ƿ����ż�
	dp << uint8( 1 );

	//--

	//--�������б�
	city.formatBuildingGet(dp);

	return true;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Game_Handle::Game_Handle()
{

}

Game_Handle::~Game_Handle()
{

}


int Game_Handle::HandleKeepalive(RSSS& rs, DP &dp)
{
	ACE_DEBUG((LM_DEBUG, " Game_Handle::HandleKeep...\n"));

	SB &sb = *rs.session_sb;
//--xx2009_2_16--	Player * player = rs.session_player;
//--xx2009_2_16--	//ACE_ASSERT( player );
//--xx2009_2_16--	City * city = player->GetCity();
//--xx2009_2_16--	ACE_ASSERT(city);
//--xx2009_2_16--	if (!city)
//--xx2009_2_16--	{
//--xx2009_2_16--		DO_TRACERROR1_WARNING();
//--xx2009_2_16--		return 0;//--false
//--xx2009_2_16--	}
	
	DPHandle(dp, sb).SendPacket();

	ACE_DEBUG((LM_DEBUG, " Game_Handle::HandleKeep...ok.\n"));
	return 0;
}
int Game_Handle::HandlePing(RSSS& rs, DP &dp)
{
	ACE_DEBUG((LM_DEBUG, " Game_Handle::HandlePing...\n"));

	//ACE_ASSERT( rs.session_sb );
	SB &sb = *rs.session_sb;

	//ACE_ASSERT( rs.player );
	//Player &player = *rs.player;
	
	DPHandle(dp, sb).SendPacket();

	ACE_DEBUG((LM_DEBUG, " Game_Handle::HandlePing...ok.\n"));
	return 0;
}

int Game_Handle::HandleUnknown(RSSS& rs, DP &dp)
{
	ACE_DEBUG((LM_DEBUG, " Game_Handle::HandleUnknown...\n"));

	//ACE_ASSERT( rs.session_sb );
	SB &sb = *rs.session_sb;

	//ACE_ASSERT( rs.player );
	//Player &player = *rs.player;
	
	DPHandle(dp, sb).error_close();
	
	//ACE_DEBUG((LM_DEBUG, " Game_Handle::HandleUnknown...ok.\n"));
	return 0;
}
