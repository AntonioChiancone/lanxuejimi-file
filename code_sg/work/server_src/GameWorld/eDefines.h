//--xx2009_1_5--
//#include "eDefines.h"
#ifndef _enum_DEFINES_H_
#define _enum_DEFINES_H_
class __enumDefines {};

//--enum & Macro definition

//--time seconds of...time
#define	TM_SS_DAY	86400	//--1������
#define	TM_SS_HOUR	3600	//--1Сʱ����
#define	TM_SS_MINUTE	60	//--1��������

//--����(ÿСʱ)��Ӧ��ʱ�����/��ĸ/Denominator
#define	RATIO_TIME_DENO	(3600)

//--PlayerProperty/m_OfficialID/OfficialUp
enum eOfficialType
{
	EOT_NULL	= 0,//--·��δȷ��
	EOT_VALIANT	= 1,//--���·��
	EOT_WISDOM	= 2,//--�Ĺ�·��
};

//--Upgrade Status
class _eUpgradeStatus {};
//--Building/Tech/Upgrade Flag
enum EBTUFlag
{
	//Upgrade_NULL= 0,//--default/NULL
	EBTU_NULL	= 0,//--default/������
	
	EBTU_OK		= 1,//--OK
	Upgrade_OK	= 1,//--OK
		
	EBTU_Upgrade= 2,//--Upgrade/Create
	Upgrade_Create=2,//--�������������ִ�������

//--xx2009_1_20--	//--
//--xx2009_1_20--	EBTU_Destroy= 3,//--Destroy
};

//--����
enum ELeagueLevel
{
	LL_NULL	= 0,//--��Ա(Ĭ��)
	LL_Manager	= 0x01,//--��Ա(����)
	LL_ManageIn	= 0x11,//--������
	LL_ManageOut= 0x21,//--ָ�ӹ�
	LL_OWNER	= 0xFF,//--����
};

class _TRTypes {};
//--��������
enum ETradeTypes
{
	TRType_Null	= 0,//--
	//--����
	TRType_Food	= 1,//--����
	TRType_Share= 2,//--�ɷ�
	//--��������/����
	MRType_Res	= 3,//--��Դ
	MRType_War	= 4,//--ս��
};
//--����״̬
enum ETradeStatus
{
	TRStatu_Null	= 0,//--
	TRStatu_Sale	= 1,//--����/������������
	TRStatu_Saled	= 2,//--�۳�/����/����������
	//--
	TRStatu_OK	= TRStatu_Null,//--�����Ѿ����
};

#include "_defItemId.h"
#include "_defBuildingId.h"

#endif//--
