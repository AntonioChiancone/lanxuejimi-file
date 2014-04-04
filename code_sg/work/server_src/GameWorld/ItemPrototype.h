// ItemPrototype.h: interface for the ItemPrototype class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEMPROTOTYPE_H__199CDF96_D031_4E29_AD9A_4167AD6758C9__INCLUDED_)
#define AFX_ITEMPROTOTYPE_H__199CDF96_D031_4E29_AD9A_4167AD6758C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_4--
//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

//--Item Prototype/����
typedef struct ItemPrototype ITEM;
struct ItemPrototype  
//class ItemPrototype  
: public GW_T_ProtoType
{
	//--
//public:
//--	uint32	ProtoId;//--ProtoΨһ��ʾ(����ID)/itemid
		//--
//--	uint32	TypeId;//--���ͷ����(����)
//--	uint32	Level;//--�ȼ�(����)/�����Ҫ
//--	uint32	Type2;//--����(����)

	uint8	itemHide;// = 0;//--�Ƿ����ع���(����)/����ʹ�ã�������ʾ
	int	Gold;//--���

public:
	void dump();
	//ItemPrototype();
	//virtual ~ItemPrototype();
	~ItemPrototype();
	ItemPrototype(int id = 0)
		: GW_T_ProtoType(id)
	{
//--		memset(((char*)this)+sizeof(GW_T_ProtoType)
//--			, 0
//--			, sizeof(*this)-sizeof(GW_T_ProtoType)
//--			);
		Name	= "����(��ֵ)";
		Desc	= "���﹦�ܽ���";
	}
};
//--xx2009_2_4--
#endif // !defined(AFX_ITEMPROTOTYPE_H__199CDF96_D031_4E29_AD9A_4167AD6758C9__INCLUDED_)
