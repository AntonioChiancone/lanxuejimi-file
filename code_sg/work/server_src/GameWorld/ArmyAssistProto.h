// ArmyAssistProto.h: interface for the ArmyAssistProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARMYASSISTPROTO_H__89F8CD18_2FEB_440F_91FC_8C43B6DE1688__INCLUDED_)
#define AFX_ARMYASSISTPROTO_H__89F8CD18_2FEB_440F_91FC_8C43B6DE1688__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2008_12_19--
//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

#include "Army_Type.h"

//--��ʿ/ҽʦ/��ͷ
typedef struct ArmyAssistProto AAP;
struct ArmyAssistProto  
//class ArmyAssistProto  
: public GW_T_ProtoType
{
//--	uint32	Id;//--AssistId/EAssistType
//--	uint32	Level;//--
//--	uint32	Type2;//--

	//--
	int	Needs;//	��ļ�ļ۸񣨰�����	int	0	NOT NULL
	int	RecruitTime;//	��ļʱ�䣨�룩	int	0	NOT NULL

	int	Value1;//Rate	��Ѫ���ļӳɣ�%��	int	0	NOT NULL
	int	Value2;//Rate	�Թ����ļӳɣ�%��	int	0	NOT NULL
	int	Value3;//Rate	�Է����ļӳɣ�%��	int	0	NOT NULL
private:
	void ArmyAssistProto_reset()
	{
		memset(((char*)this)+sizeof(GW_T_ProtoType)
			, 0
			, sizeof(*this)-sizeof(GW_T_ProtoType)
			);
	}
public:
	void dump();
	//ArmyAssistProto();
	//virtual 
	~ArmyAssistProto();
	ArmyAssistProto(int id = 0);

};

#endif // !defined(AFX_ARMYASSISTPROTO_H__89F8CD18_2FEB_440F_91FC_8C43B6DE1688__INCLUDED_)
