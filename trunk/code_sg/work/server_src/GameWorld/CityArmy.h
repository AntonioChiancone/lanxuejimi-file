// CityArmy.h: interface for the CityArmy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CITYARMY_H__EE3BD096_C2FB_46BB_99FA_6FF4ED31D0FF__INCLUDED_)
#define AFX_CITYARMY_H__EE3BD096_C2FB_46BB_99FA_6FF4ED31D0FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_9--
//#include "GameWorld.h"
#include "Army.h"

#define	CIT_MAX_ARMYS	10	//--����������

class MCityArmy {};
//struct CityArmy
class CityArmy
{
public:
	int AssistIncrease(EAssistType t, int amount);//--��ļ
	int AssistReduce(EAssistType t, int amount);//--��ɢ

public:
	int Army_Return(Army *pArmy);
	int Army_Recall(Army * pArmy);//--�ٻ�

	bool Army_Starting(uint32 to, Army *pArmy, EArmyOp op
		, uint32 carry_foods = 0
		, uint32 carry_silvers = 0
		);//--����
	//--
	bool Army_Starting_League(Army *pArmy);//--������ս
	bool HasArmyLeague();//--

	bool Army_Starting_LMatch(Army *pArmy);//--��������
	bool HasArmyLMatch();

	int ArmyIncrease(ESoldierType t, int amount);//--�������
	int ArmyReduce(ESoldierType t, int amount);//--����ɢ

	//--��m_ArmyLibrary�ֳ�һ֧����/���ƾ���
	Army* Army_Separate(Hero* pHero
		, ArmyLayout & layout, ArmyAssist & assist
		);

public:
	ArmyLibrary	m_ArmyLibrary;//--����

	Army	*m_pDefenseArmy;// = NULL;//--�سǾ���/פ��֮һ
	inline void DefenseArmy_Set(Army * pArmy) { m_pDefenseArmy = pArmy; }
	inline Army *DefenseArmy_Get() { return m_pDefenseArmy; }
	//--
	inline void DefenseArmy_Null() { m_pDefenseArmy = NULL; }

protected:
	CityArmy()
	{
		m_pDefenseArmy = 0;
	}
public:
	int dump_armys();
	//CityArmy();
	//virtual ~CityArmy();
	~CityArmy();
public:

private://--must
	inline City * __City();//--must
};
//--xx2009_2_9--
#endif // !defined(AFX_CITYARMY_H__EE3BD096_C2FB_46BB_99FA_6FF4ED31D0FF__INCLUDED_)
