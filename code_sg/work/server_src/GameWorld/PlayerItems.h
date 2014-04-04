// PlayerItems.h: interface for the PlayerItems class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYERITEMS_H__42EE46DE_8D54_41B5_AC07_B2578351FDF7__INCLUDED_)
#define AFX_PLAYERITEMS_H__42EE46DE_8D54_41B5_AC07_B2578351FDF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_2--
//#include "GameWorld.h"
#include "GW_Items.h"
#include "ItemsIdCount.h"

//--���������
struct ItemBoxResult
{
	//int	iboxGold;
	int	iboxExp;
	int	iboxForceExp;
	ItemsIdCount iboxItems;
};

//--Player Items/����(����)
class CPlayerItems {};
//struct PlayerItems
class PlayerItems  
: public ItemsIdCount
{
public:
	bool formatItems(DP &dp);
	bool formatIBoxs(DP &dp);

	inline ITEM const * ItemProto(int itemid)//--��������(����)
	{
		DEF_STATIC_REF(GW_Items, protos, gwItems);
		return protos.GetProto( itemid );
	}

public:
	int Use_Item(int itemid, int count = 1);//--ʹ�õ���
	//--
	int Use_Item_Happy10(int count = 1);//--ʹ���ʵ¿�
	int Use_Item_NoWar(int count = 1);//--ʹ����ս��

	bool IBox_Open(int itemid, ItemBoxResult & iboxRes);//--������
private:
	bool IBox_Open_Copper(ItemBoxResult & iboxRes);//--��������ͭ����
	bool IBox_Open_Silver(ItemBoxResult & iboxRes);//--������
	bool IBox_Open_Gold(ItemBoxResult & iboxRes);//--������
	bool IBox_Open_Kirin(ItemBoxResult & iboxRes);//--������

	bool IBox_OK(ItemBoxResult & iboxRes);//--��ñ��俪�����Ķ���

protected:
	PlayerItems()
	{
	}
public:
	//PlayerItems();
	//virtual ~PlayerItems();
	~PlayerItems();

private://--must
	inline Player * __Player();//--must
};
//--xx2009_2_4--
#endif // !defined(AFX_PLAYERITEMS_H__42EE46DE_8D54_41B5_AC07_B2578351FDF7__INCLUDED_)
