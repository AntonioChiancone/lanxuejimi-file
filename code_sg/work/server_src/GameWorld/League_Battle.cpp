
#include "League.h"

#include "Army.h"

#include "GW_ObjectMgr.h"
#include "WorldTimer.h"

bool League::LBattle(League * pLeague)//;//--Battle
{
	//DO_TRACERROR1_MSG( "������ս" );
	if (!pLeague)
		return 0;
	ACE_DEBUG((LM_DEBUG, " ��ʼ ������ս %d VS %d\n"
		, m_LeagueID
		, pLeague->m_LeagueID
		));

	m_LBattle_report.clear();

	DO_TRACERROR__WAIT1( "���Ӱ���ֵ����" );

	sort_listArmy_worth(m_LBattleArmys);
	sort_listArmy_worth(pLeague->m_LBattleArmys);

	int countBattle = 0;
	int t = min( m_LBattleArmys.size(), pLeague->m_LBattleArmys.size() );
	if (t > 0)
	{
		listArmy::iterator itAttack = m_LBattleArmys.begin();
		listArmy::iterator itDefense = pLeague->m_LBattleArmys.begin();
		for (int i = 0; i < t; ++i)
		{
			if (m_LBattleArmys.end() == itAttack
				|| pLeague->m_LBattleArmys.end() == itDefense)
				break;
			
			ArmyBattleReport report;
			(*itDefense)->Battle(report, *itAttack, INVALID_AREAID);
			m_LBattle_report.push_back(report);

			++countBattle;

			++itAttack;
			++itDefense;
		}
	}
	{
		for (listArmy::iterator it = m_LBattleArmys.begin()
			; m_LBattleArmys.end() != it
			;// ++it
			)
		{
			if (NULL == *it)
				continue;
			
			if ( (*it)->GetWorth() <= 0 )
			{
				Army * army = *it;
				++it;
				army->Army_release();
			}
			else
			{
				++it;
			}
		}
	}
	{
		for (listArmy::iterator it = pLeague->m_LBattleArmys.begin()
			; pLeague->m_LBattleArmys.end() != it
			;// ++it
			)
		{
			if (NULL == *it)
				continue;
			
			if ( (*it)->GetWorth() <= 0 )
			{
				Army * army = *it;
				++it;
				army->Army_release();
			}
			else
			{
				++it;
			}
		}
	}

	if (countBattle > 0)
	{
		DO_TRACERROR1_MSG( "������ս���� - ����ս��" );
	}
	else
	{
		DO_TRACERROR1_MSG( "������ս���� - û�з���ս��" );
	}

	LBattle_OK();
	pLeague->LBattle_OK();

	{
		ACE_DEBUG((LM_DEBUG, " ������ս ս��\n"));
		for (int i = 0; i < m_LBattle_report.size(); ++i)
		{
			ACE_DEBUG((LM_DEBUG, " �� %d ��\n", 1+i));
		//	m_LBattle_report[i].dump();
		}
	}

	return true;
}

bool League::LBattle_To(uint32 leagueid)//;//--��ս
{
	if (InLB_NULL != m_inLBattle)
	{
		DO_TRACERROR1_MSG( "��ǰ�����Ѿ�������ս����ս״̬ - ������ս" );
		return 0;
	}

	DEF_STATIC_REF(GW_ObjectMgr, omgr, GWobjmgr);
	League * league = omgr.League_get(leagueid, league);
	if (!league)
		return 0;

	if (InLB_NULL != league->m_inLBattle)
	{
		DO_TRACERROR1_MSG( "�Է������Ѿ�������ս����ս״̬ - ������ս" );
		return 0;
	}

	//--��ս
	DEF_STATIC_REF(WorldTimer, timer, worldTimer);
	//time_t curTime = timer.GetTime();
	time_t timeReady= timer.GetTime();
	time_t timeWait	= 10;

	m_LBattleID = leagueid;
	league->m_LBattleID = m_LeagueID;

	m_inLBattle = InLB_Attack;
	league->m_inLBattle = InLB_Defense;

	m_TimeWait	= timeWait;
	league->m_TimeWait	= timeWait;

	m_TimeReady	= timeReady;
	league->m_TimeReady	= timeReady;

	DO_TRACERROR1_MSG( "��ս�ɹ� - ����ս������48Сʱ����" );
	return true;
}

void League::LBattle_army(Army * pArmy)
{
	if (pArmy)
		m_LBattleArmys.push_back(pArmy);
}
void League::LBattle_remove(Army * pArmy)
{
	if (pArmy)
		m_LBattleArmys.remove(pArmy);
}
void League::LBattle_recall(Army * pArmy)
{
	if (pArmy)
	{
		m_LBattleArmys.remove(pArmy);

		pArmy->Army_ToReturn();
	}
}
void League::LBattle_OK()//;//--��ս����
{
	m_inLBattle = InLB_NULL;
	m_LBattleID	= 0;
	m_TimeReady	= 0;
	m_TimeWait	= 0;

	for (listArmy::iterator it = m_LBattleArmys.begin()
		; m_LBattleArmys.end() != it
		; ++it)
	{
		if (NULL == *it)
			continue;

		(*it)->Army_ToReturn();
	}
	m_LBattleArmys.clear();
}
