// RoleLevelUpProto.h: interface for the RoleLevelUpProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROLELEVELUPPROTO_H__DBE2D8DC_B5DE_4244_A957_716BFB88A28B__INCLUDED_)
#define AFX_ROLELEVELUPPROTO_H__DBE2D8DC_B5DE_4244_A957_716BFB88A28B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_12--
//#include "GameWorld.h"
#include "GW_T_ProtoType.h"


//--Role LevelUp Proto
typedef struct RoleLevelUpProto RLP;
struct RoleLevelUpProto  
//class RoleLevelUpProto  
: public GW_T_ProtoType
{
//public:
//--	uint8	TypeId;//--
//--	uint8	Level;//--
//--	uint8	Type2;//--

	//--ֻʹ��Level������Ĭ�����Զ���0

public:
	uint32	m_NeedExps;//--����Ҫ��
	//--
	int		m_GetForceExps;//--������սѫֵ��
	int		m_GetFreeValue;//--����������Է����

public:
	void dump();
	//RoleLevelUpProto();
	//virtual ~RoleLevelUpProto();
	~RoleLevelUpProto();
	RoleLevelUpProto(int id = 0);
};
//--xx2009_2_12--
#endif // !defined(AFX_ROLELEVELUPPROTO_H__DBE2D8DC_B5DE_4244_A957_716BFB88A28B__INCLUDED_)
