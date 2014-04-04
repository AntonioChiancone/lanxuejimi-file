// ProtoOfficial.h: interface for the ProtoOfficial class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROTOOFFICIAL_H__FCF026C1_3758_4EAE_9E3E_87D9297DE11E__INCLUDED_)
#define AFX_PROTOOFFICIAL_H__FCF026C1_3758_4EAE_9E3E_87D9297DE11E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_13--
//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

//--Proto Official(LevelUp)
typedef struct ProtoOfficial POL;
struct ProtoOfficial  
//class ProtoOfficial  
: public GW_T_ProtoType
{
//public:
//--	uint8	TypeId;//--
//--	uint8	Level;//--
//--	uint8	Type2;//--

	//--TypeId�����Ĺ���٣�Level��ְ

public:
	uint32	m_NeedExps;//--����Ҫ��
	//--
	int		m_GetGolds;//--��������ң�
	//--��������
	int		m_GetForceValue;//--����
	int		m_GetLeadValue;//--ͳ˧
	int		m_GetBrainValue;//--����

public:
	void dump();
	//ProtoOfficial();
	//virtual ~ProtoOfficial();
	~ProtoOfficial();
	ProtoOfficial(int id = 0);
};
//--xx2009_2_13--
#endif // !defined(AFX_PROTOOFFICIAL_H__FCF026C1_3758_4EAE_9E3E_87D9297DE11E__INCLUDED_)
