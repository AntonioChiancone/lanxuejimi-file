// DataPacketCmd.h: interface for the DataPacketCmd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATAPACKETCMD_H__914FA28B_A0C3_467F_AA09_D1DCC46C6604__INCLUDED_)
#define AFX_DATAPACKETCMD_H__914FA28B_A0C3_467F_AA09_D1DCC46C6604__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DataPacketCmd  
{
public:
	DataPacketCmd();
	virtual ~DataPacketCmd();

	//--helper
};
enum eDataPacketCmd
{
	GWCMD_NULL			= 0,
	GWCMD_KEEPALIVE		= 1,
	GWCMD_PING			= 2,
	GWCMD_TEST			= 3,//--debug

	//--FirstLoginGetSvr//--(��1��)��½��֤��ȡ���������Ϣ
	GWCMD_LOGIN_1_AUTH	= 4,
	
	//--Login2GameServer//--(��2��)��½(����)��Ϸ����
	GWCMD_LOGIN_2_LOGON	= 5,

	//--������ɫ/�״ε�½
	GWCMD_LOGIN_3_LOGON_CROLE	= 6,//--Create Role

	//--����/interior
	GWCMD_OVERVIEW	= 7,//--3.	����---�ſ�

//--	GWCMD_BUILDING_CREATE	= 8,//--���콨��
	GWCMD_BUILDING_UPGRADE	= 9,//--��������
	GWCMD_BUILDING_GET	= 10,//--ȡ(��������������)�����б�

	GWCMD_BUILDING_GET_PROTO= 11,//--ȡ(��������������)��������(������ȫ������)
	//--
	GWCMD_MAP_GET_CENTER		= 101,//--get world map
	GWCMD_MAP_GET		= 102,//--


//	GWCMD_CREATE_ACC	= 102,//--2.	�����µĽ�ɫ

	//--
	GWCMD_MESSAGE	= 201,//--��Ϣ
	//--����
	GWCMD_MSGCHAT	= 201,//--��Ϣ/����
	//--�ż�
	GWCMD_MSGMAILTO	= 202,//--�ż�/����
	GWCMD_MSGMAIL	= 203,//--�ż�/��ʾ/����
	GWCMD_MSGMAILREAD=204,//--�ż�/����

	//--�ճ�����
	GW_MISDAILY_BUY	= 205,//--�����ճ�����
	GW_MISDAILY_GET	= 206,//--ȡ���ճ�����
	GW_MISDAILY_START=207,//--ִ���ճ�����
	GW_MISDAILY_CANCEL=208,//--ȡ���ճ�����
	GW_MISDAILY_AUTO= 209,//--�Զ�����ճ�����
};

#endif // !defined(AFX_DATAPACKETCMD_H__914FA28B_A0C3_467F_AA09_D1DCC46C6604__INCLUDED_)
