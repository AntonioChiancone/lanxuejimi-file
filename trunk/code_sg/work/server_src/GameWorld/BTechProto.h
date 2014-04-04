// BTechProto.h: interface for the BTechProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BTECHPROTO_H__079041C4_60C6_4942_805D_44F7B41EF1E0__INCLUDED_)
#define AFX_BTECHPROTO_H__079041C4_60C6_4942_805D_44F7B41EF1E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

#define	LIMIT_MAX_BTPS	1
#define	LIMIT_MAX2_BPIDS	3

//--����/�Ƽ�/����
//--(Building)Tech Proto
typedef struct BTechProto BTP;
struct BTechProto  
//class BTechProto  
: public GW_T_ProtoType
{
//--	uint8	Id;//--BTech Id/EBTechType
//--	uint8	Level;//--�ȼ�
//--	uint8	Type2;//--

	int		EffectValue;

	uint8	Upgrade;//--�Ƿ��������

	//--��������
	uint32	NeedValues;//--(�Ļ�)����
	uint32	NeedSilver;//--��������
	uint32	NeedGold;//--�������

	//--����ǰ������
	uint32	m_NeedBTechs[LIMIT_MAX_BTPS];//--Need (BTP) Proto Id
	uint32	m_NeedBPIds[LIMIT_MAX2_BPIDS];//--Need (Building) Proto Id

	//--
	uint32	NeedTime;//--

private:
	void BTechProto_reset()
	{
		memset(((char*)this)+sizeof(GW_T_ProtoType)
			, 0
			, sizeof(*this)-sizeof(GW_T_ProtoType)
			);
	}
public:
	void dump();
	//BTechProto();
	//virtual ~BTechProto();
	~BTechProto();
	BTechProto(int id = 0);

};
//--
class _BTechType {};
//--BTech Id
enum EBTechType
{
	BTech_Null	= 0,//--

	BTech_Start	= 1,//--
//--xx2009_1_5--
//--	//--��������
//--	Soldier_Infantry= 1,//--����
//--	Soldier_Archer	= 2,//--����
//--	Soldier_Cavalry	= 3,//--���
//--	Soldier_Daobing	= 4,//--����
//--	Soldier_Pikeman	= 5,//--ǹ��
//--
//--	//--�������/��ϵ����ĳ����������
//--	Soldier_Infantry2	= 6,//--��ʿ
//--	Soldier_Archer2		= 7,//--�����
//--	Soldier_Cavalry2	= 8,//--�ɹ�����
//--	Soldier_Daobing2	= 9,//--İ����
//--	Soldier_Pikeman2	= 10,//--���Ӫ
//--
//--	//--��е/Machinery/��ϵ������е
//--	Soldier_BaggageCar	= 11,//--��س�
//--	Soldier_TrafficCar	= 12,//--Ҫ����
//--	Soldier_WarVehicle	= 13,//--���
//--	Soldier_Artillery	= 14,//--����
//--	Soldier_Truck		= 15,//--ľţ����
	//--��ӱ����о�������
	BTech_Infantry	= 1,//--�����о�
	BTech_Archer	= 2,//--�����о�
	BTech_Cavalry	= 3,//--����о�
	BTech_Daobing	= 4,//--�����о�
	BTech_Pikeman	= 5,//--ǹ���о�
	//--
	BTech_Infantry2	= 6,//--��ʿ�о�
	BTech_Archer2	= 7,//--������о�
	BTech_Cavalry2	= 8,//--�ɹ������о�
	BTech_Daobing2	= 9,//--İ�����о�
	BTech_Pikeman2	= 10,//--���Ӫ�о�
	//--��е/Machinery/��ϵ������е
	BTech_BaggageCar= 11,//--��س��о�
	BTech_TrafficCar= 12,//--Ҫ�����о�
	BTech_WarVehicle= 13,//--����о�
	BTech_Artillery	= 14,//--�����о�
	BTech_Truck		= 15,//--ľţ�����о�
//--xx2009_1_5--
	//--
	BTech_Spying	= 16,//--��̽
	BTech_Irrigation= 17,//--���
	BTech_Rotation	= 18,//--����
	BTech_Trade		= 19,//--ó��
	BTech_CChamber	= 20,//--�̻�
	BTech_Paper		= 21,//--��ֽ
	BTech_Printing	= 22,//--ӡˢ
	BTech_Civil		= 23,//--��ľ
	BTech_Centra	= 24,//--��Ȩ/Centralization
	//--
	BTech_End	= 24,//--
	BTech_Type_MAX,//--25

};
#define	MAX_BTECH_TYPE	BTech_Type_MAX
//--
inline const char* get_BTP_name(int id)
{
	if (id < BTech_Start || id > BTech_End)
		return "�Ƽ�0";
	static char * s[MAX_BTECH_TYPE] =
	{
		"�Ƽ�0",

//--xx2009_1_5--
		//--��ӱ����о�������
		"�����о�",
		"�����о�",
		"����о�",
		"�����о�",
		"ǹ���о�",
		//--
		"��ʿ�о�",
		"������о�",
		"�ɹ������о�",
		"İ�����о�",
		"���Ӫ�о�",
		//--
		"��س��о�",
		"Ҫ�����о�",
		"����о�",
		"�����о�",
		"ľţ�����о�",
//--xx2009_1_5--
		"��̽",
		"���",
		"����",
		"ó��",
		"�̻�",
		"��ֽ",
		"ӡˢ",
		"��ľ",
		"��Ȩ",
	};
	return s[id];
}

//--Building/Tech Level/SoldierLevel/TechLevel
typedef	uint8 TechLevel[MAX_BTECH_TYPE];//--�ȼ�/�����ǳ�

#endif // !defined(AFX_BTECHPROTO_H__079041C4_60C6_4942_805D_44F7B41EF1E0__INCLUDED_)
