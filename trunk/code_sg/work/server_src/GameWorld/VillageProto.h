// VillageProto.h: interface for the VillageProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VILLAGEPROTO_H__7465DEC8_8892_46B5_8949_AB4B2613940B__INCLUDED_)
#define AFX_VILLAGEPROTO_H__7465DEC8_8892_46B5_8949_AB4B2613940B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameWorld.h"

typedef struct VillageProto VIP;
struct VillageProto  
{
	uint32	ProtoId;

	uint8	TypeId;//VillageId;
	uint8	Level;

	std::string	Name;
	std::string	Desc;


	//int		Value1;//-ũҵֵ
	union
	{
		//int		Value1;//-ũҵֵ
		int		FoodValue;//-ũҵֵ
	};
	//int		Value2;//--��ҵֵ
	union
	{
		//int		Value2;//--��ҵֵ
		int		SilverValue;//--��ҵֵ
	};

	uint32	BaseValue;//--��������(�����ϼ�UpdateValue)

	uint8	Upgrade;//--�Ƿ��������
	uint32	UpdateValue;//--����/����(���¼�)��Ҫ�۸�(����)

	int		max_investors;//--���Ͷ������

public:
	void dump();
	VillageProto()
	{
		ProtoId		= 0;

		TypeId		= 0;
		Level		= 0;

		Name		= "��ׯ";
		Desc		= "--";

		FoodValue	= 200;
		SilverValue	= 100;

		BaseValue	= 0;

		Upgrade		= 1;
		UpdateValue	= 1000;

		max_investors=10;
	}
	//virtual 
		~VillageProto();

};

#endif // !defined(AFX_VILLAGEPROTO_H__7465DEC8_8892_46B5_8949_AB4B2613940B__INCLUDED_)
