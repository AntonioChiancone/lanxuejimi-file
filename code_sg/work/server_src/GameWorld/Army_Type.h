// Army_Type.h: interface for the Army_Type class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARMY_TYPE_H__A1E77368_84DB_4899_8456_8E1628B84334__INCLUDED_)
#define AFX_ARMY_TYPE_H__A1E77368_84DB_4899_8456_8E1628B84334__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameWorld.h"

class Army_Type  
{
public:
	Army_Type();
	virtual ~Army_Type();

};

//#include "Army_Level.h"
//--Army Soldier Level/SoldierLevel/ArmyLevel
#define	SOLDIER_LEVEL_DEFAULT	0	//--����/�ȼ�(Ĭ��)
#define	SOLDIER_LEVEL_MAX	3	//--����/�ȼ�/���

//#include "Army_TechsLevel.h"
//--Army Soldier Techs Level/ArmyTechs/SoldierTechs
#define	ARMYTECH_LEVEL_DEFAULT	0	//--���¿Ƽ�/�ȼ�/Ĭ��
#define	ARMYTECH_LEVEL_MAX	2	//--���¿Ƽ�/�ȼ�/���

const int MARCH_NEEDTIME_DEFAULT = 5;//--Ĭ�Ͼ����ж���Ҫʱ��/test

const int MARCH_SPEED_MAX = 100;//--����о��ٶ�

//--�ӳ�/�ٷֱ�%1000
const int Assist_Teacher_Value = 50;
const int Assist_Taoist_Value = 50;
const int Assist_Doctor_Value = 50;
//--
class Army__AssistType {};
//--��ʿ/ҽʦ/��ͷ
enum EAssistType
{
	Assist_Null	= 0,//--

	Assist_Start	= 1,//--
	//--
	Assist_Teacher	= 1,//--��ͷ
	Assist_Taoist	= 2,//--��ʿ
	Assist_Doctor	= 3,//--ҽʦ
	//--
	Assist_End	= 3,//--
	Assist_Type_MAX,//--4
};
#define	MAX_ASSIST_TYPE	Assist_Type_MAX
//--
inline const char* get_AAP_name(int id)
{
	if (id < Assist_Start || id > Assist_End)
		return "��";
	static char * s[MAX_ASSIST_TYPE] =
	{
		"��",

		"��ͷ",
		"��ʿ",
		"ҽʦ",
	};
	return s[id];
}

class Army__Op {};
//--����Ŀ��Ŀ��
enum EArmyOp
{
	Army_OP_Null	= 0,//--û��Ŀ��/���ƾ���/���о���/פ��/���ص�

	Army_OP_Start	= 1,//--
	//--
	Army_OP_Sizhan	= 1,//--��ս
	Army_OP_Besiege	= 2,//--Χ��
	Army_OP_Plunder	= 3,//--�Ӷ�
	Army_OP_Harass	= 4,//--ɧ��
	Army_OP_Against	= 5,//--ӭս
	Army_OP_Spying	= 6,//--��̽
	Army_OP_Aid		= 7,//--��Ԯ/��ǲ
	Army_OP_Transport=8,//--����
	Army_OP_Build	= 9,//--����

	//--
	Army_OP_LMatch	= 10,//--��������
	Army_OP_League	= 11,//--������ս

	//--
	Army_OP_End		= 11,//--
	Army_OP_MAX,//--12
};
#define	MAX_ARMY_OP	Army_OP_MAX
//--
inline const char* get_ArmyOp_name(int id)
{
	if (id < Army_OP_Start || id > Army_OP_End)
		return "���о���";
	static char * s[MAX_ARMY_OP] =
	{
		"���о���",
			
			"��ս",
			"Χ��",
			"�Ӷ�",
			"ɧ��",
			"ӭս",
			"��̽",
			"��Ԯ",
			"����",
			"����",

			"��������",
			"������ս",
	};
	return s[id];
}

class Army__In {};
//--����״̬
enum EArmyIn
{
	Army_IN_Null	= 0,//--

	Army_IN_Start	= 0,//--
	//--
	Army_IN_Troops	= 0,//--פ��(פ������/���о���)

	Army_IN_Free	= 1,//--(only)����

	Army_IN_Friend	= 2,//--�˾�(פ�������Ѽҵľ��Ӻ�����פ�����Լ��ҵľ���)

	Army_IN_March	= 3,//--�о�
	Army_IN_War		= 4,//--��ս/
	Army_IN_ToReturn= 5,//--����

	//--
	Army_IN_End		= 5,//--
	Army_IN_MAX,//--6
};
#define	MAX_ARMY_IN	Army_IN_MAX
//--
inline const char* get_ArmyIn_name(int id)
{
	if (id < Army_IN_Start || id > Army_IN_End)
		return "פ��";//--����״̬
	static char * s[MAX_ARMY_IN] =
	{
		"פ��",

			"����",
			"�˾�",
			"�о�",
			"��ս",
			"����",
	};
	return s[id];
}

class Army__SoldierSeries {};
//--��ϵ
enum ESoldierSeries
{
	SSeries_Null	= 0,//--

	SSeries_Start	= 1,//--
	//--
	SSeries1Infantry= 1,//--����ϵ
	SSeries2Archer	= 2,//--����ϵ
	SSeries3Cavalry	= 3,//--���ϵ
	SSeries4Daobing	= 4,//--����ϵ
	SSeries5Pikeman	= 5,//--ǹ��ϵ
	SSeries6Machinery=6,//--��еϵ
	//--
	SSeries_End	= 6,//--
	SSeries_Max,//--7
};
#define	MAX_SOLDIER_SERIES	SSeries_Max

#define	SOLDIER_SERIES_DEFAULT	1	//--��ϵ/Ĭ��

//--���¿Ƽ�(����)(����ʿ��������)
class _ArmySoldierTech {};
//--���¿Ƽ�/ArmyTechId
enum EArmyTechType
{
	ArmyTech_Null	= 0,//--

	//--ÿ����ϵ�ĿƼ�����������һ��

	ArmyTech_Start	= 1,//--
	//--����ϵ
	ArmyTech_Infantry_Start	= 1,//--
	ArmyTech_Infantry1	= 1,//--����ǿ��
	ArmyTech_Infantry2	= 2,//--����ǿ��
	ArmyTech_Infantry3	= 3,//--����ǿ��
	ArmyTech_Infantry4	= 4,//--�ٶ�ǿ��
	ArmyTech_Infantry5	= 5,//--����ǿ��
	ArmyTech_Infantry_End=5,//--
	//--����ϵ
	ArmyTech_Archer_Start= 6,//--
	ArmyTech_Archer1	= 6,//--����ǿ��
	ArmyTech_Archer2= 7,//--����ǿ��
	ArmyTech_Archer3= 8,//--����ǿ��
	ArmyTech_Archer4= 9,//--�ٶ�ǿ��
	ArmyTech_Archer5= 10,//--����ǿ��
	ArmyTech_Archer_End=10,//--
	//--���ϵ
	ArmyTech_Cavalry_Start	= 11,//--
	ArmyTech_Cavalry1	= 11,//--����ǿ��
	ArmyTech_Cavalry2	= 12,//--����ǿ��
	ArmyTech_Cavalry3	= 13,//--����ǿ��
	ArmyTech_Cavalry4	= 14,//--�ٶ�ǿ��
	ArmyTech_Cavalry5	= 15,//--����ǿ��
	ArmyTech_Cavalry_End= 15,//--
	//--����ϵ
	ArmyTech_Daobing_Start	= 16,//--
	ArmyTech_Daobing1	= 16,//--����ǿ��
	ArmyTech_Daobing2	= 17,//--����ǿ��
	ArmyTech_Daobing3	= 18,//--����ǿ��
	ArmyTech_Daobing4	= 19,//--�ٶ�ǿ��
	ArmyTech_Daobing5	= 20,//--����ǿ��
	ArmyTech_Daobing_End= 20,//--
	//--ǹ��ϵ
	ArmyTech_Pikeman_Start= 21,//--
	ArmyTech_Pikeman1	= 21,//--����ǿ��
	ArmyTech_Pikeman2	= 22,//--����ǿ��
	ArmyTech_Pikeman3	= 23,//--����ǿ��
	ArmyTech_Pikeman4	= 24,//--�ٶ�ǿ��
	ArmyTech_Pikeman5	= 25,//--����ǿ��
	ArmyTech_Pikeman_End= 25,//--
	//--��еϵ
	ArmyTech_Machinery_Start	= 26,//--
	ArmyTech_Machinery1	= 26,//--����ǿ��
	ArmyTech_Machinery2	= 27,//--����ǿ��
	ArmyTech_Machinery3	= 28,//--����ǿ��
	ArmyTech_Machinery4	= 29,//--�ٶ�ǿ��
	ArmyTech_Machinery5	= 30,//--����ǿ��
	ArmyTech_Machinery_End=30,//--
	//--
	ArmyTech_End	= 30,//--
	ArmyTech_Type_MAX,//--16
};
#define	MAX_ARMYTECH_TYPE	ArmyTech_Type_MAX

class Army__SoldierType {};
//--����/SoldierId
enum ESoldierType
{
	Soldier_Null	= 0,//--

	Soldier_Start	= 1,//--
	//--��������
	Soldier_Infantry= 1,//--����
	Soldier_Archer	= 2,//--����
	Soldier_Cavalry	= 3,//--���
	Soldier_Daobing	= 4,//--����
	Soldier_Pikeman	= 5,//--ǹ��

	//--�������/��ϵ����ĳ����������
	Soldier_Infantry2	= 6,//--��ʿ
	Soldier_Archer2		= 7,//--�����
	Soldier_Cavalry2	= 8,//--�ɹ�����
	Soldier_Daobing2	= 9,//--İ����
	Soldier_Pikeman2	= 10,//--���Ӫ

	//--��е/Machinery/��ϵ������е
	Soldier_BaggageCar	= 11,//--��س�
	Soldier_TrafficCar	= 12,//--Ҫ����
	Soldier_WarVehicle	= 13,//--���
	Soldier_Artillery	= 14,//--����
	Soldier_Truck		= 15,//--ľţ����
	//--
	Soldier_End	= 15,//--
	Soldier_Type_MAX,//--16
};
#define	MAX_SOLDIER_TYPE	Soldier_Type_MAX

//--
inline const char* get_SS_name(int id)
{
	if (id < SSeries_Start || id > SSeries_End)
		return "�ں�֮��";//--��ϵ
	static char * s[MAX_SOLDIER_SERIES] =
	{
			"�ں�֮��",//--��ϵ

			"����",
			"����",
			"���",
			"����",
			"ǹ��",
			"��е",
	};
	return s[id];
}
//--���ݱ�ϵȷ���ñ�ϵ���¿Ƽ�(��Χ)
inline bool get_SS_ArmyTech(int series, int & tech_start, int & tech_end)
{
	if (series < SSeries_Start || series > SSeries_End)
	{
		//ACE_ASSERT(0);
		tech_start = ArmyTech_Null;
		tech_end = ArmyTech_Null;
		return false;
	}
	tech_start = 1+5*(series-1);
	tech_end = 4+tech_start;
	return true;
}
//--���ݾ��¿Ƽ�ȷ����ϵ
inline int get_SS_ArmyTech(int tech, int & series)
//inline bool get_SS_ArmyTech(int tech, int & series)
{
	if (tech < ArmyTech_Start || tech > ArmyTech_End)
	{
		//ACE_ASSERT(0);
		return series = SSeries_Null;//0;
		//return false;
	}
	return series = 1+(tech-1)/5;
	//return true;
}
//--
inline const char* get_ATP_name(int id)
{
	if (id < ArmyTech_Start || id > ArmyTech_End)
		return "��";
	static char * s[MAX_ARMYTECH_TYPE] =
	{
			"��",

			"��������ǿ��",
			"��������ǿ��",
			"��������ǿ��",
			"�����ٶ�ǿ��",
			"��������ǿ��",

			"��������ǿ��",
			"��������ǿ��",
			"��������ǿ��",
			"�����ٶ�ǿ��",
			"��������ǿ��",

			"�������ǿ��",
			"�������ǿ��",
			"�������ǿ��",
			"����ٶ�ǿ��",
			"�������ǿ��",

			"��������ǿ��",
			"��������ǿ��",
			"��������ǿ��",
			"�����ٶ�ǿ��",
			"��������ǿ��",

			"ǹ������ǿ��",
			"ǹ������ǿ��",
			"ǹ������ǿ��",
			"ǹ���ٶ�ǿ��",
			"ǹ������ǿ��",

			"��е����ǿ��",
			"��е����ǿ��",
			"��е����ǿ��",
			"��е�ٶ�ǿ��",
			"��е����ǿ��",
	};
	return s[id];
}
//--
inline const char* get_ASP_name(int id)
{
	if (id < Soldier_Start || id > Soldier_End)
		return "��";//--����
	static char * s[MAX_SOLDIER_TYPE] =
	{
			"��",//--����

			"����",
			"����",
			"���",
			"����",
			"ǹ��",

			"��ʿ",
			"�����",
			"�ɹ�����",
			"İ����",
			"���Ӫ",

			"��س�",
			"Ҫ����",
			"���",
			"����",
			"ľţ����",
	};
	return s[id];
}
inline const char* get_ASP_name(int id, int level/* = SOLDIER_LEVEL_DEFAULT*/)
{
	if (level < 0//--SOLDIER_LEVEL_DEFAULT
		|| level > SOLDIER_LEVEL_MAX
		)
		return "��-1";

	if (id < Soldier_Start || id > Soldier_End)
		return "��";
	static char * s[1+SOLDIER_LEVEL_MAX][MAX_SOLDIER_TYPE] =
	{
			"��0",//--����

			"����0��Ҫ�о�",
			"����0��Ҫ�о�",
			"���0��Ҫ�о�",
			"����0��Ҫ�о�",
			"ǹ��0��Ҫ�о�",

			"��ʿ0��Ҫ�о�",
			"�����0��Ҫ�о�",
			"�ɹ�����0��Ҫ�о�",
			"İ����0��Ҫ�о�",
			"���Ӫ0��Ҫ�о�",

			"��س�0��Ҫ�о�",
			"Ҫ����0��Ҫ�о�",
			"���0��Ҫ�о�",
			"����0��Ҫ�о�",
			"ľţ����0��Ҫ�о�",

			"��1",//--����

			"�Ჽ��",
			"�ṭ��",
			"�����",
			"�ᵶ��",
			"��ǹ��",

			"��ʿ",
			"�����",
			"�ɹ�����",
			"İ����",
			"���Ӫ",

			"��س�",
			"Ҫ����",
			"���",
			"����",
			"ľţ����",

			"��2",//--����-

			"�ز���",
			"������",
			"�����",
			"������",
			"��ǹ��",

			"��ʿ",
			"�����",
			"�ɹ�����",
			"İ����",
			"���Ӫ",

			"��س�",
			"Ҫ����",
			"���",
			"����",
			"ľţ����",

			"��2",//--����-

			"������",
			"���",
			"������",
			"�󵶱�",
			"ǹ�ܱ�",

			"��ʿ",
			"�����",
			"�ɹ�����",
			"İ����",
			"���Ӫ",

			"��س�",
			"Ҫ����",
			"���",
			"����",
			"ľţ����",
	};
	return s[level][id];
}
//--���ݱ���ȷ����ϵ
inline int get_SS_ArmySoldierId(int soldierid/*, int & series*/)
{
	if (soldierid < Soldier_Start || soldierid > Soldier_End)
	{
		//ACE_ASSERT(0);
		return SSeries_Null;//series = SSeries_Null;//0;
		//return false;
	}
	static int s[MAX_SOLDIER_TYPE] =
	{
		0,//--SSeries_Null

		1,//SSeries1Infantry= 1,//--����ϵ
		2,//SSeries2Archer	= 2,//--����ϵ
		3,//SSeries3Cavalry	= 3,//--���ϵ
		4,//SSeries4Daobing	= 4,//--����ϵ
		5,//SSeries5Pikeman	= 5,//--ǹ��ϵ

		1,//SSeries1Infantry= 1,//--����ϵ
		2,//SSeries2Archer	= 2,//--����ϵ
		3,//SSeries3Cavalry	= 3,//--���ϵ
		4,//SSeries4Daobing	= 4,//--����ϵ
		5,//SSeries5Pikeman	= 5,//--ǹ��ϵ

		6,//SSeries6Machinery=6,//--��еϵ
		6,//SSeries6Machinery=6,//--��еϵ
		6,//SSeries6Machinery=6,//--��еϵ
		6,//SSeries6Machinery=6,//--��еϵ
		6,//SSeries6Machinery=6,//--��еϵ
	};
	return s[soldierid];//series = s[soldierid];
	//return true;
}

#endif // !defined(AFX_ARMY_TYPE_H__A1E77368_84DB_4899_8456_8E1628B84334__INCLUDED_)
