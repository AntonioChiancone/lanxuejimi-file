//--xx2008_9_23--
//--xx2008_9_23--
//--xx2008_9_23--
//#include "packet.h"

#ifndef _xxPACKET_H_
#define _xxPACKET_H_
class _xxPACKET_H {};

#include "datatype.h"
//--
//--typedef	uint32	PacketPushCommand;
//--
//--//--���ݰ�ͷ�����
//--enum PacketCommand
//--{	PCMD_NULL	= 0,	//--null
//--
//--//--�ͻ���(C)
//--//--�����(S)
//--//--����ͻ���(Cs)
//--
//--//--��ͷ����
//--
//--//--������˫��������Ҫ��Ӧ����Ӧ
//--PCMD_KEEPALIVE	= 0x01,//--������(C<->S)
//--//--�����һ��ʱ��(3-5����)δ�յ��������������ر�����
//--
//--//--�û���½�ɹ�/�������Ӧ���½��(�ɹ����)/Ȼ����ͻ�����(PUSH)����
//--PCMD_LOGIN		= 0x02,//--�û���½��(C->S->C)
//--
//--PCMD_LOGOUT		= 0x03,//--�û��˳���(C->S)
//--
//--PCMD_PUSHDATA	= 0x04,//--��(PUSH)����(C<->S)
//--
//--PCMD_LOGOFF		= 0x05,//--֪ͨ�û�����(S->C)/�����ط���½��ԭ��
//--
//--//--һЩ����Ϸ�߼��޹ص�ͨѶЭ����ڰ�ͷ����
//--
//--PCMD_EMAIL		= 0x06,//--�ż�ϵͳ(C->S->C)
//--PCMD_CHAT		= 0x07,//--����ϵͳ(C->S->Cs)
//--
//--
//--//--
//--PCMD_MAX		= 0xFF,//--(����)��ʹ��(���������)
//--};
//--
//--//--���ݰ�ͷ�����
//--enum PushCommand
//--{	PUSH_NULL	= 0,	//--null
//--PUSH_KEEPALIVE	= PCMD_KEEPALIVE,//--��ʹ��
//--
//--PUSH_LOGIN		= PCMD_LOGIN,//--�û���½��(C->S->C)
//--
//--PUSH_LOGOUT		= PCMD_LOGOUT,//--��ʹ��
//--
//--PUSH_PUSHDATA	= PCMD_PUSHDATA,//--��(PUSH)����(C<->S)
//--
//--PUSH_LOGOFF		= PCMD_LOGOFF,//--֪ͨ�û�����(S->C)/�����ط���½��ԭ��
//--
//--PUSH_PCMD		= 0x100,//--(����)��ʹ��/PUSHDATA��ʼ
//--//--�����￪ʼPUSH��Ϸ����
//--};

#endif
