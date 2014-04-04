// PlayerMisReward.cpp: implementation of the PlayerMisReward class.
//
//////////////////////////////////////////////////////////////////////
//--xx2009_1_24--
#include "PlayerMisReward.h"
#include "CPlayer.h"
#include "MCity.h"
//#include "World.h"

#include "GW_ObjectMgr.h"
#include "WorldTimer.h"

MRD * PlayerMisReward::MR_Get(uint32 id)
{
	DEF_STATIC_REF(GW_ObjectMgr, omgr, GWobjmgr);
	return omgr.MRD_get(id);
}
int PlayerMisReward::MR_Publish_Cancel(uint32 id)
{
	if (m_MRList.end() == find(m_MRList.begin(), m_MRList.end(), id) )
	{
		DO_TRACERROR1_MSG( "�����ҷ������������� - �Ҳ���ȡ��" );
		return 0;//--false
	}

	MRD * pMR = MR_Get(id);
	if (pMR)
		return pMR->TradeCancel();
	
	return 0;//--false
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Player * PlayerMisReward::__Player()
{
	//Player* p = (Player*)this;//--test
	return (Player*)this;
}

PlayerMisReward::PlayerMisReward()
: m_MRId(0)
{

}

PlayerMisReward::~PlayerMisReward()
{

}

int PlayerMisReward::MR_Publish_Res(int gold, uint32 target, int silver)
{
	Player * player = __Player();
	ACE_ASSERT( player );
	if (!player)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	if (m_MRList.size() >= 2)
	{
		DO_TRACERROR1_MSG( "ÿ�����ֻ�ܷ���2���������� - ���ܷ�����������" );
		return 0;//--false
	}

	if (gold < 5)
	{
		DO_TRACERROR1_MSG( "��������������Ҫ����5�����" );
		return 0;//--false
	}

	if (player->Gold_get() < gold)
	{
		DO_TRACERROR1_MSG( "��������������Ҫ��� - ��Ҳ���" );
		return 0;//--false
	}

	City * city = player->GetCity();
	ACE_ASSERT( city );
	if (!city)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}
	
	MRD * ptr = new MRD(target, MRType_Res, city->m_AreaID);
	ACE_ASSERT(ptr);
	if (!ptr)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	DEF_STATIC_REF(GW_ObjectMgr, omgr, GWobjmgr);
	DEF_STATIC_REF(WorldTimer, timer, worldTimer);
	//time_t curtime = timer.GetTime();

	if (player->GoldSpend(gold) >= 0)
	{
		ACE_DEBUG((LM_DEBUG, " %s ������������ɹ���(��ʱ)�۳����(����)=%d\n"
			, player->m_Name.c_str()
			, gold
			));

		ptr->m_target	= target;

		ptr->m_gold		= gold;
		ptr->m_silver	= silver;

		ptr->m_BeginTime= timer.GetTime();
		ptr->m_NeedTime	= 30;//TM_SS_DAY;

		m_MRList.push_back(ptr->m_ID);
		omgr.MRD_put(ptr);

		return ptr->m_ID;
	}
	DO_TRACERROR1_MSG( "��������������Ҫ��� - ��Ҳ���" );
	delete ptr;
	return 0;//--false
}
int PlayerMisReward::MR_Publish_War(int gold, uint32 target, int worth)
{
	Player * player = __Player();
	ACE_ASSERT( player );
	if (!player)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	if (m_MRList.size() >= 2)
	{
		DO_TRACERROR1_MSG( "ÿ�����ֻ�ܷ���2���������� - ���ܷ�����������" );
		return 0;//--false
	}

	if (gold < 5)
	{
		DO_TRACERROR1_MSG( "��������������Ҫ����5�����" );
		return 0;//--false
	}

	if (player->Gold_get() < gold)
	{
		DO_TRACERROR1_MSG( "��������������Ҫ��� - ��Ҳ���" );
		return 0;//--false
	}

	City * city = player->GetCity();
	ACE_ASSERT( city );
	if (!city)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}
	
	MRD * ptr = new MRD(target, MRType_War, city->m_AreaID);
	ACE_ASSERT(ptr);
	if (!ptr)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	DEF_STATIC_REF(GW_ObjectMgr, omgr, GWobjmgr);
	DEF_STATIC_REF(WorldTimer, timer, worldTimer);
	//time_t curtime = timer.GetTime();

	if (player->GoldSpend(gold) >= 0)
	{
		ACE_DEBUG((LM_DEBUG, " %s ������������ɹ���(��ʱ)�۳����(����)=%d\n"
			, player->m_Name.c_str()
			, gold
			));

		ptr->m_target	= target;

		ptr->m_gold		= gold;
		ptr->m_worth	= worth;

		ptr->m_BeginTime= timer.GetTime();
		ptr->m_NeedTime	= 3*30;//TM_SS_DAY;

		m_MRList.push_back(ptr->m_ID);
		omgr.MRD_put(ptr);

		return ptr->m_ID;
	}
	DO_TRACERROR1_MSG( "��������������Ҫ��� - ��Ҳ���" );
	delete ptr;
	return 0;//--false
}

bool PlayerMisReward::MR_Accept(uint32 id)
{
	Player * player = __Player();
	ACE_ASSERT( player );
	if (!player)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	if (m_MRId)
	{
		DO_TRACERROR1_MSG( "ͬһʱ��ֻ�ܽ�һ����������" );
		return 0;
	}

	MRD* pMis = MR_Get(id);
	if (!pMis)
	{
		DO_TRACERROR1_MSG( "�������񲻴���" );
		return 0;
	}

	if (pMis->player_of_Saler() == player)
	{
		DO_TRACERROR1_MSG( "���ܽ� - �Լ���������������" );
		return 0;
	}
	
	if (TRStatu_Sale != pMis->m_statu)//--m_TRStatu
	{
		DO_TRACERROR1_MSG( "��������״̬����������-��ȡ���򱻽�����" );
		return 0;
	}

	int gold = pMis->m_gold;

	if (player->Gold_get() < gold)
	{
		DO_TRACERROR1_MSG( "��������������ҪѺ�� - ��� - ��Ҳ���" );
		return 0;//--false
	}

	if (player->GoldSpend(gold) >= 0)
	{
		pMis->m_Buyer	= player->GetCityID();
		pMis->m_statu	= TRStatu_Saled;//--m_TRStatu
		m_MRId	= id;
		
		ACE_DEBUG((LM_DEBUG, " ������������(%d)\n", id));
		return true;
	}
	DO_TRACERROR1_MSG( "��������������ҪѺ�� - ��� - ��Ҳ���" );
	return 0;//--false
}
