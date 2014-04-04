// MisReward.cpp: implementation of the MisReward class.
//
//////////////////////////////////////////////////////////////////////

#include "MisReward.h"

#include "GW_ObjectMgr.h"

#include "World.h"
#include "CPlayer.h"

void MisReward::PublishNewID()
{
	static int id = 0;
	m_ID = ++id;
	DO_TRACERROR1_MSG( "�������� ID ?" );
}

int MisReward::Timeout()
{
	//--(��Update���õ�����)����Ҫ����

	//--test
	DO_TRACERROR1_MSG( "����������� - �Զ�ȡ��" );

	if (TRStatu_Sale != m_statu
		&& TRStatu_Saled != m_statu
		)
	{
		DO_TRACERROR1_MSG( "�������� - �����Զ�ȡ�� - �����Ѿ���ɻ�ʧЧ(����/�Զ�ȡ��)" );
		return 0;//--false
	}

	if (TRStatu_Saled == m_statu)
	{
		Player * pBuyer = player_of_Buyer();
		if (pBuyer)
		{
			pBuyer->MR_Accept_clear(m_ID);

			pBuyer->Gold_Inc(0.8*m_gold);
			//--
			ACE_DEBUG((LM_DEBUG, " %s ����δ��������������Զ�ȡ�����������(80%Ѻ��)=%d\n"
				, pBuyer->m_Name.c_str()
				, int(0.8*m_gold)
				));
		}
	}

	Player * pSaler = player_of_Saler();
	if (pSaler)
	{
		pSaler->MR_Publish_clear(m_ID);

		pSaler->Gold_Inc(m_gold);
		//--
		ACE_DEBUG((LM_DEBUG, " %s �������񣬹����Զ�ȡ�����������(����)=%d\n"
			, pSaler->m_Name.c_str()
			, m_gold
			));
	}

	m_statu	= TRStatu_Null;

	return true;
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//MisReward::MisReward()
//{
//
//}

MisReward::~MisReward()
{

}

int MisReward::TradeOK()
{
	//--(��Update���õ�����)����Ҫ����

	if (TRStatu_Saled != m_statu)
	{
		DO_TRACERROR1_MSG( "�������� - OK��Ч - ����δ����" );
		return 0;//--false
	}

	Player * pSaler = player_of_Saler();
	if (!pSaler)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}
	Player * pBuyer = player_of_Buyer();
	if (!pBuyer)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	m_statu	= TRStatu_OK;

	pBuyer->Gold_Inc(2*m_gold);
	//--
	ACE_DEBUG((LM_DEBUG, " %s �����������ɹ�����ý��(Ѻ��+����)=%d\n"
		, pBuyer->m_Name.c_str()
		, (2*m_gold)
		));

	pBuyer->MR_Accept_clear(m_ID);
	pSaler->MR_Publish_clear(m_ID);

	DEF_STATIC_REF(GW_ObjectMgr, omgr, GWobjmgr);
	omgr.MRD_remove(m_ID);
	delete this;

	return true;
}
	
int MisReward::TradeCancel()
{
	//--������Ҫ����?/��

	if (TRStatu_Sale != m_statu)
	{
		DO_TRACERROR1_MSG( "�������� - ����ȡ�� - �����Ѿ���ɻ�ʧЧ(����/�Զ�ȡ��)" );
		return 0;//--false
	}

	Player * pSaler = player_of_Saler();
	if (!pSaler)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	m_statu	= TRStatu_Null;

	pSaler->Gold_Inc(m_gold);
	//--
	ACE_DEBUG((LM_DEBUG, " %s ȡ���������񣬷������(����)=%d\n"
		, pSaler->m_Name.c_str()
		, m_gold
		));

	pSaler->MR_Publish_clear(m_ID);

	DEF_STATIC_REF(GW_ObjectMgr, omgr, GWobjmgr);
	omgr.MRD_remove(m_ID);
	delete this;

	return true;
}
