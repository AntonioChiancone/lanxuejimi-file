// BuildingProto.h: interface for the BuildingProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUILDINGPROTO_H__250ABA9E_DC3C_4E2F_8310_D61E451A0B92__INCLUDED_)
#define AFX_BUILDINGPROTO_H__250ABA9E_DC3C_4E2F_8310_D61E451A0B92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameWorld.h"

enum EProtoBuildingValue
{
	//--additional more
    PBV_ValueAdd1	= 0,//--
    PBV_ValueAdd2	= 1,//--
    PBV_ValueAdd3	= 2,//--

	PBV_End,//--3
};
#define MAX_PBVALUES	PBV_End

//#define	MAXUpgradeLimit	5	//--
#define	LIMIT_MAX_BPIDS	1

//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

//--����/����/����/����
//--Building Create/Upgrade Proto
typedef struct BuildingProto BCP;
struct BuildingProto  
//class BuildingProto  
: public GW_T_ProtoType
{
	void formatBuildingGetProto(uint8 canUpgrade, DP &dp);

//--
//--	uint32	ProtoId;
//--
//--	uint8	Id;//BuildingId;//--eBuildingType/BtType
//--	uint8	Level;
//--
//--	std::string	Name;
//--	std::string	Desc;

	uint16	PhotoCode;//--��������ʾͼƬ���루4λӢ�Ļ����֣�
	int		Value1;
	int		Value2;
	int		Value3;
	int		Value4;
	int		Value5;

	//--����/������Ҫ��ǰ�ý�����(ProtoId)/����(ProtoId)��ѯ���������ȼ�
	uint8	Upgrade;//--�Ƿ��������
//--xx2008_12_29--	uint32	UpdateNeeds;//--����/����(���¼�)��Ҫ�۸�(����)
	uint32	NeedSilver;//--����/����(���¼�)��Ҫ�۸�(����)
//--xx2008_12_29--	uint32	UpgradeTime;//--����/����(���¼�)��Ҫʱ��(��)
	uint32	NeedTime;//--����/����(���¼�)��Ҫʱ��(��)
//--xx2008_12_29--	uint32	UpgradeLimit[MAXUpgradeLimit];//--ProtoId/����(����)����(����������ϵ)
//--xx2008_12_29--	//--��������(�ϼ�����)
//--xx2008_12_29--	//--����������(����Դ����)

	//--����ǰ������
	uint32	m_NeedBPIds[LIMIT_MAX_BPIDS];//--Need (Building) Proto Id

	BuildingProto(uint32 id = 0)
		: GW_T_ProtoType(id)
	{
		memset(((char*)this)+sizeof(GW_T_ProtoType)
			, 0
			, sizeof(*this)-sizeof(GW_T_ProtoType)
			);

		Upgrade		= 1;
	}

	int		Values[MAX_PBVALUES];
public:
	void dump();
	//BuildingProto();
	//virtual
	~BuildingProto();

//	inline int ValueAdd1() { return Values[PBV_ValueAdd1]; }
//	inline int ValueAdd2() { return Values[PBV_ValueAdd2]; }
//	inline int ValueAdd3() { return Values[PBV_ValueAdd3]; }
//
//	inline int Agriculture() { return Value1; }
//	inline int Commerce() { return Value2; }
//	inline int Culture() { return Value3; }
//	inline int Happy() { return Value4; }
//	inline int Population() { return Value5; }
};

#endif // !defined(AFX_BUILDINGPROTO_H__250ABA9E_DC3C_4E2F_8310_D61E451A0B92__INCLUDED_)
