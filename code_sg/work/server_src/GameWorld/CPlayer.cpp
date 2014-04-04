// CPlayer.cpp: implementation of the CPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "CPlayer.h"
#include "MCity.h"

#include "GW_ObjectMgr.h"

#include "WorldTimer.h"

void CPlayer::dump()
{
	DEF_STATIC_REF(GW_ObjectMgr, omgr, GWobjmgr);

	Hero::dump();
	ACE_DEBUG((LM_DEBUG, " Player::dump...RoleID[%d]%s ����[%d](%s)\n"
		, m_RoleID
		, m_Name.c_str()
		, GetLeagueID(), omgr.League_Name(GetLeagueID())
		));
}
void CPlayer::dump_player()
{
	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) Player::dump_player...\n", this));
	dump();
	{
		ACE_DEBUG((LM_DEBUG, " ��ҳǳ�\n"));
		if (m_pCity)
			m_pCity->dump();
	}
	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) Player::dump_player...ok\n", this));
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//CPlayer::CPlayer()
//{
//
//}

CPlayer::~CPlayer()
{

}
CPlayer::CPlayer(const char * name, uint32 roleid)
: Hero(name, 0, 0)
{
	DEF_STATIC_REF(GW_ObjectMgr, omgr, GWobjmgr);
	m_RoleID = ( (roleid)?(roleid):( omgr.GenerateGuid(GUID_PLAYER) ) );

	//--�ҳ�
	//m_Loyalty	= 60;
	//--����
	m_Physical	= 100;
}

//--void CPlayer::release()
//--{
//--	for (int i = 0; i < PLAYER_MAX_CITY_SIZE; ++i)
//--	{
//--		if (citys[i])
//--			citys[i]->release();
//--	}
//--	init_player();
//--
//--//	{
//--//		objmgr.release_Hero( HeroID(), false);
//--//		objmgr.release_Player( RoleID(), false);
//--//	}
//--}

bool CPlayer::_logon(DP & dp)
{
	static WorldTimer &timer = worldTimer;

	City * city = GetCity();
	ACE_ASSERT( city );
	if (!city)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

//	DP dp(GWCMD_LOGIN_2_LOGON);
	dp.reset();

	//--uint8	�Ƿ�Ϊ��һ�ε�½���Ƿ�������ң�	1�ǵ�һ�ε�½
	//dp << uint8( player.LoginCount() < 1 );
	dp << uint8( 0 );
	++m_LoginCount;
	//--
	//--uint32	������ʱ��
	dp << uint32(timer.GetTime());
	//--
	//--uint32	��ɫID
	dp << m_RoleID;
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
	dp << uint32(city->m_AreaID);
	//--uint16	���б���ͼID
	dp << uint16(1);
	//--string	��������
	dp << city->m_Name;
	//--uint32	��ɫӵ�лƽ���
	dp << uint32(0);
	//--uint32	��ɫ��ǰ��ʳ����
	dp << uint32( city->Food_get() );
	//--uint32	��ɫ��ǰ��ʳ����
	dp << uint32( city->FoodRate_get() );
	//--uint32	��ɫ��ǰ��ʳ�������
	dp << uint32( city->FoodMax_get() );

	//--uint32	��ɫ��ǰ��������
	dp << uint32( city->Silver_get() );
	//--uint32	��ɫ��ǰ��������
	dp << uint32( city->SilverRate_get() );
	//--uint32	��ɫ��ǰ�����������
	dp << uint32( city->SilverMax_get() );

	//--uint32	��ɫ��ǰ�Ļ�ֵ
	dp << uint32( city->Culture_get() );
	//--uint32	��ɫ���е�ǰ�˿�
	dp << uint32( city->People_get() );
	//--uint8	��ɫ���п���ֵ
	dp << uint8( city->Happy_get() );
	//--
	//--uint8	�Ƿ�����Ա����ľ����ж�
	dp << uint8( 1 );
	//--uint8	�Ƿ����ż�
	dp << uint8( 1 );

	//--

	//--�������б�
	city->formatBuildingGet(dp);

	SendPacket(&dp);

	dp.reset();
	dp.header.cmd_ok( GWCMD_BUILDING_GET_PROTO );
	if (city->formatBuildingGetProto(dp, INVALID_BUILDING_ID))
		SendPacket(&dp);

	return true;
}
