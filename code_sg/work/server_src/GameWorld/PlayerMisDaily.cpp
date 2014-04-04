// PlayerMisDaily.cpp: implementation of the PlayerMisDaily class.
//
//////////////////////////////////////////////////////////////////////

#include "PlayerMisDaily.h"
#include "World.h"

#include "_eErrcode.h"

void PlayerMisDaily::formatMisDaily(DP &dp)
{
	dp << uint32( GetMisRemainBuy() );//--uint32/�ɹ���������

	int count = GetCurMisCount();
	dp << uint32( count );//--uint32/��ǰ������
	if (count <= 0)
		return;

	if (m_MisCur.m_ProtoId && m_MisCur.m_pProto)
	{
		MisDaily & t = m_MisCur;
		if (t.m_ProtoId && t.m_pProto)
		{
			dp << t.m_ProtoId;//--uint32
			dp << t.m_pProto->Name;//--string
			dp << t.m_pProto->Desc;//--string
			dp << t.m_pProto->m_NeedTime;//--uint32
			dp << t.m_Upgrade;//--uint8/2==��������ִ��
		}
	}
	for (vector<uint32>::iterator it = m_MisSelect.begin()
		; m_MisSelect.end() != it
		; ++it
		)
	{
		MisDaily t(*it);
		if (t.m_ProtoId && t.m_pProto)
		{
			dp << t.m_ProtoId;//--uint32
			dp << t.m_pProto->Name;//--string
			dp << t.m_pProto->Desc;//--string
			dp << t.m_pProto->m_NeedTime;//--uint32
			dp << t.m_Upgrade;//--uint8/2==��������ִ��
		}
	}
}

void PlayerMisDaily::MisDailyReport(MisDaily * pMisDaily)
{
	if (!pMisDaily || !(pMisDaily->m_pProto) )
		return;

	++m_MisTodayCount;
	++m_MisOKTimes;
	__Player()->Exp_Inc( pMisDaily->m_MisAward );

	Player * player = __Player();
	ACE_ASSERT( player );
	if (player
		&& player->m_PlaySession
		&& player->m_PlaySession->session_sb
		)
	{
		DP dp(GW_MISDAILY_GET);
		formatMisDaily(dp);
		player->SendDP(&dp);
		return;
	}

	DO_TRACERROR1_MSG( "��Ҫ������洢���񱨸�" );

	ACE_DEBUG((LM_DEBUG, " ���񱨸棺%s ��þ���(%d)\n"
		, (
		(pMisDaily->m_MisResult)
		?( pMisDaily->m_pProto->m_ReportSuccess.c_str() )
		:(  pMisDaily->m_pProto->m_ReportFailure.c_str())
		)
		, pMisDaily->m_MisAward
		));
}
void PlayerMisDaily::MisDailyOK(MisDaily * pMisDaily)
{
	ACE_ASSERT(&m_MisCur == pMisDaily);

	ACE_ASSERT( __Player() );
	m_MisCur.MisDailyOK( __Player() );
	MisDaily_remove(m_MisCur.m_ProtoId);
	m_MisCur.UpdateProto(0);
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Player * PlayerMisDaily::__Player()
{
	//Player* p = (Player*)this;//--test
	return (Player*)this;
}

PlayerMisDaily::PlayerMisDaily()
{
	reset_clear();

	//--test
	//m_MisCur.UpdateProto(1);
	//m_MisCur.DoUpgrade();
	MisDaily_add(1);
	MisDaily_add(2);
	MisDaily_add(1);
	MisDaily_add(3);
	MisDaily_add(1);
	MisDaily_add(2);
}

PlayerMisDaily::~PlayerMisDaily()
{

}
int PlayerMisDaily::SpendAutoMisDaily()
{
	Player * player = __Player();
	ACE_ASSERT( player );
	if (player)
		return player->GoldSpend(10);
	return EE_ERROR_CODE;//-1;
}
int PlayerMisDaily::SpendBuyMisDaily()
{
	Player * player = __Player();
	ACE_ASSERT( player );
	if (player)
		return player->GoldSpend(5);
	return EE_ERROR_CODE;//-1;
}

int PlayerMisDaily::MisDailyStart(uint32 MisDaily_ID/*ProtoId*//* = 0*/)
{
	if (!m_MisCur.m_ProtoId)
	{
		for (vector<uint32>::iterator it = m_MisSelect.begin()
			; m_MisSelect.end() != it
			; ++it
			)
		{
			if (0 == MisDaily_ID)
			{
				m_MisCur.UpdateProto(*it);
				m_MisCur.DoUpgrade();
				m_MisSelect.erase(it);

				ACE_DEBUG((LM_DEBUG, " һ������%s ����ִ�У�ʣ�� %d ������\n"
					, m_MisCur.m_pProto->Name.c_str()
					, m_MisSelect.size()
					));

				return 1;
				break;
			}
			if (MisDaily_ID == *it)
			{
				m_MisCur.UpdateProto(MisDaily_ID);
				m_MisCur.DoUpgrade();
				m_MisSelect.erase(it);

				ACE_DEBUG((LM_DEBUG, " һ������%s ����ִ�У�ʣ�� %d ������\n"
					, m_MisCur.m_pProto->Name.c_str()
					, m_MisSelect.size()
					));

				return 1;
				break;
			}
		}
		ACE_DEBUG((LM_DEBUG, " ���񲻴��ڣ��޷�ִ��\n"));
		return -1;
	}
	ACE_DEBUG((LM_DEBUG, " ����ִ������\n"));
	return -1;
}
int PlayerMisDaily::MisDailyCancel()
{
	if (m_MisCur.m_ProtoId)
	{
		m_MisCur.UpdateProto(0);
		return 1;
	}
	return -1;
}

int PlayerMisDaily::MisDailyAuto()
{
	//--guard

	if (GetCurMisCount() <= 0)
	{
		DO_TRACERROR1_MSG( "��ǰû������" );
		return EE_ERROR_CODE;//-1;
	}

	DO_TRACERROR1_MSG( "��Ҫ������۽��" );
	if ( SpendAutoMisDaily() < 0)
	{
		DO_TRACERROR1_MSG( "��Ҳ���" );
		return EE_NOMONEY_GOLD;
	}

	Player * player = __Player();
	ACE_ASSERT( player );

	m_MisCur.MisDailyOK( player );
	//MisDaily_remove(m_MisCur.m_ProtoId);
	m_MisCur.UpdateProto(0);

	for (vector<uint32>::iterator it = m_MisSelect.begin()
		; m_MisSelect.end() != it
		; ++it
		)
	{
		MisDaily t(*it);
		t.MisDailyOK(player);
	}
	m_MisSelect.clear();

	return 0;
}
int PlayerMisDaily::MisDailyBuy()//;//--���������
{
	if (GetMisRemainBuy() <= 0)
	{
		DO_TRACERROR1_MSG( "�������5�������Ѿ�����" );
		return EE_MISDAILY_BUY5;
	}

	uint32 MisDaily_ID/*ProtoId*/ = 0;
	{
		MisDaily t(0);
		t.RandomMisDaily();
		MisDaily_ID = t.m_ProtoId;
	}
	if (!MisDaily_ID)
	{
		DO_TRACERROR1_MSG( "û������" );
		return EE_MISDAILY_NULL;
	}

	if ( SpendBuyMisDaily() < 0)
	{
		DO_TRACERROR1_MSG( "��Ҳ���" );
		return EE_NOMONEY_GOLD;
	}

	++m_MisTodayBuy;

	ACE_DEBUG((LM_DEBUG, " ��������ɹ�\n"));
	MisDaily_buy(MisDaily_ID);
	return 0;
}
