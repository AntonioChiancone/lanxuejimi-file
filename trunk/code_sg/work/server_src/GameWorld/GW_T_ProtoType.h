// GW_T_ProtoType.h: interface for the GW_T_ProtoType class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GW_T_PROTOTYPE_H__41B5B9C6_147A_4E72_A6BE_22E2FEBF02D1__INCLUDED_)
#define AFX_GW_T_PROTOTYPE_H__41B5B9C6_147A_4E72_A6BE_22E2FEBF02D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameWorld.h"

struct GW_T_ProtoType  
//class GW_T_ProtoType  
{
	uint32	ProtoId;//--ProtoΨһ��ʾ(�޾��庬��)
	//--
	uint32	TypeId;//--���ͷ����
	uint32	Level;//--�ȼ�(...)/�����Ҫ
	uint32	Type2;//--����(...)

	std::string	Name;
	std::string	Desc;
public:
	//GW_T_ProtoType();
	//virtual 
	~GW_T_ProtoType();
	GW_T_ProtoType(int id)
		: ProtoId(0)
		//--
		, TypeId(id)
		//--
		, Level(0), Type2(0)
		//, Name(""), Desc("")
	{
		//--test
		static int tProtoId = 0;
		ProtoId = ++tProtoId;
	}

	//--{//--format
public:
	void format_T_ProtoType(DP &dp);
	//--}//--format
};

#endif // !defined(AFX_GW_T_PROTOTYPE_H__41B5B9C6_147A_4E72_A6BE_22E2FEBF02D1__INCLUDED_)
