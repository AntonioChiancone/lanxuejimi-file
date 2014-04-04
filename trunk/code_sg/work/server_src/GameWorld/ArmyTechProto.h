// ArmyTechProto.h: interface for the ArmyTechProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARMYTECHPROTO_H__7296DFFC_D40D_45B1_AC82_B74A94D70767__INCLUDED_)
#define AFX_ARMYTECHPROTO_H__7296DFFC_D40D_45B1_AC82_B74A94D70767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2008_12_18--
//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

#include "Army_Type.h"

//--���¿Ƽ�/����/����
//--Army Soldier Tech Proto
typedef struct ArmyTechProto ATP;
struct ArmyTechProto
//class ArmyTechProto
: public GW_T_ProtoType  
{
//--	uint8	Id;//--ArmyTech Id/EArmyTechType
//--	uint8	Level;//--�ȼ�
//--	uint8	Type2;//--��ϵ

	//int		Value1;//	����	int	0	NOT NULL
	union
	{
		//int Value1;
		int Attack;
	};
	//int		Value2;//	����	int	0	NOT NULL
	union
	{
		//int Value2;
		int Strength;
	};
	//int		Value3;//	����	int	0	NOT NULL
	union
	{
		//int Value3;
		int Health;
	};
	//int		Value4;//	�ٶ�	int	0	NOT NULL
	union
	{
		//int Value4;
		int Speed;
	};
	//int		Value5;//	������Χ	int	0	NOT NULL
	union
	{
		//int Value5;
		int AttackRange;
	};

	//--���¿Ƽ���������������(ǰ������)

private:
	void ArmyTechProto_reset()
	{
		memset(((char*)this)+sizeof(GW_T_ProtoType)
			, 0
			, sizeof(*this)-sizeof(GW_T_ProtoType)
			);
	}
public:
	void dump();
	//ArmyTechProto();
	//virtual 
	~ArmyTechProto();
	ArmyTechProto(int id = 0);

};

#endif // !defined(AFX_ARMYTECHPROTO_H__7296DFFC_D40D_45B1_AC82_B74A94D70767__INCLUDED_)
