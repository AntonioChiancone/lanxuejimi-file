// ItemsIdCount.h: interface for the ItemsIdCount class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEMSIDCOUNT_H__C9DCCB6B_B546_46A2_A7C2_12DDB900761E__INCLUDED_)
#define AFX_ITEMSIDCOUNT_H__C9DCCB6B_B546_46A2_A7C2_12DDB900761E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_4--
#include "GameWorld.h"

typedef	
std::map<int//--itemid
, int//--count
> itemid_count;
class ItemsIdCount  
{
public:
	itemid_count id_count_items;
	int AddItems(ItemsIdCount & t);
public:
	void Items_dump();
	//ItemsIdCount();
	//virtual ~ItemsIdCount();
	~ItemsIdCount();
	ItemsIdCount()
	{
		//--test
		Item_Set(ITEM_NOWAR, 5);
		Item_Set(ITEM_ISPEAK, 100);

		Item_Set(ITEM_IHAPPY10, 2);
	}

	//--�������
public:
	inline int OnlyOne_Item_Set(int itemid)
	{
		switch (itemid)
		{
			//--	//--�����˳	ũҵֵ+10%	1��
			//--	TNB_FOOD110,	//--HideItem/only one item
		case TNB_FOOD110:
			//--	//--������ʳ	��ҵֵ+10%	1��
			//--	TNB_SILVER110,	//--HideItem/only one item
		case TNB_SILVER110:
			//--	//--�����Ļ�	�Ļ�ֵ+10%	1��
			//--	TNB_CULTURE110,	//--HideItem/only one item
		case TNB_CULTURE110:
			//--	//--�˶�����	����������2	8Сʱ
			//--	TNB_HAPPY200,	//--HideItem/only one item
		case TNB_HAPPY200:
			//--	//--������Ϣ	��ս	8Сʱ
			//--	TNB_REST_NOWAR,	//--HideItem/only one item
		case TNB_REST_NOWAR:
			return id_count_items[itemid] = 1;
			//break;
		default:
			break;
		}
		return 0;
	}
	inline int OnlyOne_Item_Clear(int itemid)
	{
		switch (itemid)
		{
			//--	//--�����˳	ũҵֵ+10%	1��
			//--	TNB_FOOD110,	//--HideItem/only one item
		case TNB_FOOD110:
			//--	//--������ʳ	��ҵֵ+10%	1��
			//--	TNB_SILVER110,	//--HideItem/only one item
		case TNB_SILVER110:
			//--	//--�����Ļ�	�Ļ�ֵ+10%	1��
			//--	TNB_CULTURE110,	//--HideItem/only one item
		case TNB_CULTURE110:
			//--	//--�˶�����	����������2	8Сʱ
			//--	TNB_HAPPY200,	//--HideItem/only one item
		case TNB_HAPPY200:
			//--	//--������Ϣ	��ս	8Сʱ
			//--	TNB_REST_NOWAR,	//--HideItem/only one item
		case TNB_REST_NOWAR:
			return id_count_items[itemid] = 0;
			//break;
		default:
			break;
		}
		return 0;
	}


public:
	//--����ӵ�е��߸���
	inline int Item_Get(int itemid)
	{
		itemid_count::iterator it = id_count_items.find(itemid);
		if (id_count_items.end() != it)
			return ( (*it).second );
		return 0;
	}
	inline int Item_Set(int itemid, int count)
	{
		if (count > 0)
			return id_count_items[itemid] += count;
		//--
		itemid_count::iterator it = id_count_items.find(itemid);
		if (id_count_items.end() != it)
			id_count_items.erase(it);
		return 0;
	}
	//--����((count>0)�����(count<0)
	inline int Item_Change(int itemid, int count)
	{
		if (0 == count)
			return Item_Get(itemid);
		else
		{
			if (count > 0)
				return id_count_items[itemid] += count;
			else// if (count < 0)
			{
				if ( Item_Get(itemid) > (-1*count) )
					return id_count_items[itemid] += count;
				else
					return Item_Set(itemid, 0);
			}
		}
	}
//--	//--(����)����ĳЩ�����Ҫ����0������(���)
//--	inline int Item_Set0(int itemid)
//--	{
//--		return ( id_count_items[itemid] = 0 );
//--	}
};

#endif // !defined(AFX_ITEMSIDCOUNT_H__C9DCCB6B_B546_46A2_A7C2_12DDB900761E__INCLUDED_)
