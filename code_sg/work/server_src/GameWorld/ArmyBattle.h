// ArmyBattle.h: interface for the ArmyBattle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARMYBATTLE_H__88A4C885_4958_4569_AF44_0047B30E76AE__INCLUDED_)
#define AFX_ARMYBATTLE_H__88A4C885_4958_4569_AF44_0047B30E76AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Army.h"

class ArmyBattle  
{
public:
	//ArmyBattleReport report;
	ArmyBattleReport & report;

private:
	Army & m_guArmy;//--guard/��
	Army & m_inArmy;//--invasion/����
	//--
	uint32 m_AreaID;//--ս������

	//--pancratium/�Ƕ�/����
public:
//--xx2009_2_2--	ArmyBattle(Army & guard, Army & invasion, ArmyBattleReport & r)//;
//--xx2009_2_2--		: m_guArmy(guard), m_inArmy(invasion)
//--xx2009_2_2--		, report(r)
	ArmyBattle(ArmyBattleReport & r
		, Army & guard, Army & invasion
		, uint32 areaid/* = INVALID_AREAID*/
		)//;
		: report(r)
		, m_guArmy(guard), m_inArmy(invasion)
		, m_AreaID(areaid)
	{
	}
	virtual ~ArmyBattle();

	//--����/EBattleResult
	int Battle();

private:
	//--����army��targetArmy�Ĺ����˺�/�����ӳ�
	void Attack(Army & army//--����
		, Army & targetArmy//--����
		, ArmyUnit & targetArmyUnit//--����ArmyUnit
		, int & attackHarm//--�����˺�
		, int & defenseAddi//--�����ӳ�
		);
	//--��������ʿ������
	int Death(Army & army
		, ArmyUnit & armyunit
		, int harm
		, int & surplus//--ʣ�๥��
		);
};

#endif // !defined(AFX_ARMYBATTLE_H__88A4C885_4958_4569_AF44_0047B30E76AE__INCLUDED_)
