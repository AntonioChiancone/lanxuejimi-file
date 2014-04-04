// ArmySoldierProto.h: interface for the ArmySoldierProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARMYSOLDIERPROTO_H__AA7C06ED_3B8E_4AE4_8A9D_C1035E8C5F15__INCLUDED_)
#define AFX_ARMYSOLDIERPROTO_H__AA7C06ED_3B8E_4AE4_8A9D_C1035E8C5F15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2008_12_18--
//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

#include "Army_Type.h"

//--����
typedef struct ArmySoldierProto ASP;
struct ArmySoldierProto  
//class ArmySoldierProto  
: public GW_T_ProtoType
{
//--	uint32	Id;//--Soldier Id/ESoldierType
//--	uint32	Level;//--����/�ȼ�
//--	uint32	Type2;//--��ϵ/�Ƽ���Ӧ��ϵ

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
	//int		Value6;//	����	int	0	NOT NULL
	union
	{
		//int Value6;
		int WeightCarry;
	};
	//int		Value7;//	����	int	0	NOT NULL
	union
	{
		//int Value7;
		int FoodNeed;
	};

	int		ForceExp;//--��ļ��Ҫ��սѫֵ

	int		Worth;//	��ļ�ļ۸񣨰�����	int	0	NOT NULL
	//int		Needs;//	��ļ�ļ۸񣨰�����	int	0	NOT NULL
//--	float	Multiple;//	�����е�ǰ���ֵ�����£�����ļ�ļ۸���	float	0	NOT NULL
	int		RecruitTime;//	��ļʱ�䣨�룩	int	0	NOT NULL
private:
	void ArmySoldierProto_reset()
	{
		memset(((char*)this)+sizeof(GW_T_ProtoType)
			, 0
			, sizeof(*this)-sizeof(GW_T_ProtoType)
			);
	}
public:
	void dump();
	//ArmySoldierProto();
	//virtual 
	~ArmySoldierProto();
	ArmySoldierProto(int id = 0);

	//--{//--format
public:
	void formatASP(DP &dp);
	//--}//--format
};

#endif // !defined(AFX_ARMYSOLDIERPROTO_H__AA7C06ED_3B8E_4AE4_8A9D_C1035E8C5F15__INCLUDED_)
