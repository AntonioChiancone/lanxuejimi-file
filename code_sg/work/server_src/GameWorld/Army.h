// Army.h: interface for the Army class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARMY_H__62697014_FED2_46BE_A2B7_E9FB3F82C712__INCLUDED_)
#define AFX_ARMY_H__62697014_FED2_46BE_A2B7_E9FB3F82C712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
using namespace std;

#include "GameWorld.h"

#include "Army_Type.h"
#include "Army_Assist.h"
#include "Army_Layout.h"
#include "Army_Amount.h"

#include "Army_Level.h"
#include "Army_TechsLevel.h"

#include "ArmyAssistProto.h"
#include "ArmyTechProto.h"
#include "ArmySoldierProto.h"


enum EBattleResult
{
	Battle_Draw	= 0,//--ƽ��
	Battle_Win	= 1,//--���ط�ʤ
	Battle_Lost	= 2,//--������ʤ
};
inline const char* get_BattleResult(int id)
{
	if (id < 0 || id > 2)
		return "--";
	static char * s[3] =
	{
		"ƽ��",
		"���ط�ʤ",
		"������ʤ",
	};
	return s[id];
}

const int BATTLE_ROUND_MAX	= 10;	//--���غ�
const int BATTLE_ROUND_HARASS	= 1;//--ɧ��
const int BATTLE_STRENGTH_ATTENUATION = 10;//--����(�ӳ�)˥��

struct ArmyBattleReportA
{
	string cityName;
	uint32 cityAreaID;
	
	string heroName;
	uint32 heroForce;
	uint32 heroLead;
	uint32 heroBrain;
	
	uint32 worth;
	uint32 worth2;//--ʣ���ֵ
};
struct ArmyBattleReportB
{
	string SoldierName;
	uint32 Attack;
	uint32 Strength;
	uint32 Health;
	uint32 AttackRange;

	uint32 Amount;
};
struct ArmyBattleReportC
{
	ArmyLayout Layout;

	uint32 Attack;
	uint32 Surplus;

	int dieLayout;
	uint32 dieAmount;
};
struct ArmyBattleReport
{
	uint32 m_AreaID;//--ս������

	ArmyBattleReportA	inA, guA;

	ArmyBattleReportB	inB[MAX_ARMY_LAYOUT], guB[MAX_ARMY_LAYOUT];

	ArmyBattleReportC	inC[BATTLE_ROUND_MAX], guC[BATTLE_ROUND_MAX];

	int round;
	int result;
	
	void reset() { memset(this, 0, sizeof(ArmyBattleReport)); }
	ArmyBattleReport() { reset(); }
	void dump();
};

//--Ӣ�ۼӳ�
const int HERO_ATTACK_ADDI	= 10;
const int HERO_LEAD_ADDI	= 5;
const int HERO_BRAIN_ADDI	= 5;

//--���ƾ��ӱ�����Hero/�������������
class Army;
//--��������
struct ArmyProperty
{
	uint32	m_ArmyID;

	Hero	*m_pHero;//--�������ӱ����н���
	inline Hero * GetArmyHero() { return m_pHero; }
	inline void SetArmyHero(Hero * hero) { m_pHero = hero; }

	//--����(����)Ŀ��Ŀ��
	uint32	m_From;//--
	uint32	m_To;//--����ʱȷ��/���仯/Ŀ��ݵ㽫��¼�þ���
	uint8	m_ArmyOp;

	ArmyLayout	m_ArmyLayout;

	ArmyAssist	m_AssistAmount;
	//--IsAssist1	�Ƿ�Я����ʿ	int	0	NOT NULL
	//--IsAssist2	�Ƿ�Я��ҽʦ	int	0	NOT NULL
	//--IsAssist3	�Ƿ�Я����ͷ	int	0	NOT NULL

	//uint32	m_NumValue1;//	Я��������	int	0	NOT NULL
	union
	{
		//uint32	m_NumValue1;//	Я��������	int	0	NOT NULL
		uint32	m_Food;
	};
	//uint32	m_NumValue2;//	Я���İ���	int	0	NOT NULL
	union
	{
		//uint32	m_NumValue2;//	Я���İ���	int	0	NOT NULL
		uint32	m_Silver;
	};

	inline uint32 GetCarryFood() { return m_Food; }
	inline void SetCarryFood(uint32 value) { m_Food = value; }
	inline uint32 GetCarrySilver() { return m_Silver; }
	inline void SetCarrySilver(uint32 value) { m_Silver = value; }

	uint32	m_StartTime;//	����ʱ��	datatime		NOT NULL
	//uint32	m_EndTime;//	���ʱ��	datatime		NOT NULL
	uint32	m_NeedTime;//--��ʱ
	//--RemainTime = m_NeedTime+m_StartTime-curTime;

	//--����״̬
	uint8	m_ArmyIn;

	void ArmyProperty_reset()
	{
		memset(this, 0, sizeof(ArmyProperty));
		m_From	= INVALID_AREAID;
		m_To	= INVALID_AREAID;
	}
//--public:
//--	ArmyProperty()
//--	{
//--		ArmyProperty_reset();
//--	}
//--	~ArmyProperty()
//--	{
//--		//--
//--	}
};
//--����
class Army  
: public ArmyProperty
{
	friend class ArmyBattle;
public:
//--xx2009_2_2--	int Battle(Army * pEnemy, ArmyBattleReport & report);//--
	int Battle(ArmyBattleReport & report, Army * pEnemy, uint32 areaid/* = INVALID_AREAID*/);

public:
	const ASP * GetSoldierProto(uint8 SoldierId);
private:
	//--Get (ArmySoldierProto+ArmyTechProto) to asp/return true ok
	bool GetSoldierProto_Tech(uint8 SoldierId, ASP & aspProto);
	//--Get (ArmySoldierProto+ArmyTechProto+...+point) to asp/return true ok
	bool GetSoldierProto_AddPoint(uint8 SoldierId, ASP & aspProto);
	//--Get ((ArmySoldierProto+ArmyTechProto+...+point)*percent) to asp/return true ok
	bool GetSoldierProto_Full(uint8 SoldierId, ASP & aspProto);

	//--{//--Property
public:
	City *m_pArmyOwner;// = 0;
	inline City * GetArmyOwner() { return m_pArmyOwner; }
	//inline void SetArmyOwner(City * city) { m_pArmyOwner = city; }
	void SetArmyOwner(City * city);
	//--}//--Property

public:
	//--Ŀ��ݵ�
	City * Get_Op_City();
	Alert * Get_Op_Alert();
	Fort * Get_Op_Fort();

	//--����
private:
	void _Army_Return_OK();
public:
	void Army_Return() { _Army_Return_OK(); };
	bool Army_ToReturn();
public:
	bool Starting(uint32 to, EArmyOp op
		, int carry_foods = 0
		, int carry_silvers = 0
		);//--����
	//--
	bool Starting_League();//--������ս
	bool Starting_LMatch();//--��������

	void Army_release();

	League * LeagueGet();

	//--{//--Property
	//--��̬(�Ǽ�ʱ)����
public:
	int	m_Speed;//--�ٶ�
	int Update_Speed();//--�����ٶ�

	int	m_Weight;//--����
	int Update_Weight();//--���㸺��
	int GetWeight() { return m_Weight; }//;//--����/Update_Weight

	int	m_Food;//--����
	int Update_Food();//--�������

	int m_Worth;//--��ֵ
	int Update_Worth();//--�����ֵ
	int GetWorth() { return m_Worth; }//;//--��ֵ/Update_Worth
	//--}//--Property
	void UpdateData();

	inline bool WeightBeyond()//--����
	{ return ( (m_Food+m_Silver) > m_Weight ); }

protected:
	ArmyLevel	*m_pSoldierLevel;//--from city
	ArmyTechs	*m_pSoldierTechs;//--from city

private:
	void Army_reset()
	{
		m_pEnemyArmy= 0;
		m_EnemyWelcomes.clear();

		m_pArmyOwner	= 0;

		m_Speed	= MARCH_SPEED_MAX;
		m_Weight= 0;
		m_Food	= 0;
		
		m_pSoldierLevel = 0;
		m_pSoldierTechs = 0;
	}
public:
	virtual void dump();
	//Army();
	virtual ~Army();
//protected:
	Army(uint32 from/* = INVALID_AREAID*/, City * city/* = 0*/);

	//--{//--ӭս
	//--���������ʵ��
public:
	Army	*m_pEnemyArmy;//--Ŀ�����/Army_OP_Against	= 5,//--ӭս
	listArmy m_EnemyWelcomes;//--�о�/���(������)//--��ӭս
	//--}//--ӭս
};

class ArmyLibrary : public Army  
{
public:
	ArmyAmount	m_SoldierAmount;
public:
	virtual void dump();
	ArmyLibrary()
		: Army(INVALID_AREAID, NULL)
	{
		memset(m_SoldierAmount, 0, sizeof(m_SoldierAmount));
	}
	virtual ~ArmyLibrary();

};

#endif // !defined(AFX_ARMY_H__62697014_FED2_46BE_A2B7_E9FB3F82C712__INCLUDED_)
