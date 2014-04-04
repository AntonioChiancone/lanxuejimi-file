// GWA_HCUnit.h: interface for the GWA_HCUnit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GWA_HCUNIT_H__C8A33156_D4A1_41F9_B99F_33B886A9F592__INCLUDED_)
#define AFX_GWA_HCUNIT_H__C8A33156_D4A1_41F9_B99F_33B886A9F592__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "Item.h"
//--xx2009_1_14--#include "Bag.h"

//--GameWorld Abstract class Unit(Hero/Character/Player/Role...)
class GWA_HCUnit
{
	friend class GW_ObjectMgr;
public:
	//void dump();
	GWA_HCUnit()
	{
	}
	virtual void release() {};
protected:
	//virtual ~GWA_HCUnit();
	~GWA_HCUnit();
};
//--xx2009_1_14--
//--xx2009_1_14--//--GameWorld Abstract class Unit(Hero/Character/Player/Role...)
//--xx2009_1_14--class GWA_HCUnit
//--xx2009_1_14--{
//--xx2009_1_14--	friend class GW_ObjectMgr;
//--xx2009_1_14--
//--xx2009_1_14--	//--{//--Property
//--xx2009_1_14--public:
//--xx2009_1_14--//--xx2009_1_14--	uint32	m_HeroID;
//--xx2009_1_14--//--xx2009_1_14--	uint32	m_RoleID;
//--xx2009_1_14--//--xx2009_1_14--
//--xx2009_1_14--//--xx2009_1_14--	//int Value1;//	����	int	0	NOT NULL
//--xx2009_1_14--//--xx2009_1_14--	union
//--xx2009_1_14--//--xx2009_1_14--	{
//--xx2009_1_14--//--xx2009_1_14--		//int Value1;
//--xx2009_1_14--//--xx2009_1_14--		int Attack;
//--xx2009_1_14--//--xx2009_1_14--	};
//--xx2009_1_14--//--xx2009_1_14--	//int Value3;//	ͳ˧	int	0	NOT NULL
//--xx2009_1_14--//--xx2009_1_14--	union
//--xx2009_1_14--//--xx2009_1_14--	{
//--xx2009_1_14--//--xx2009_1_14--		//int Value2;
//--xx2009_1_14--//--xx2009_1_14--		int Lead;
//--xx2009_1_14--//--xx2009_1_14--	};
//--xx2009_1_14--//--xx2009_1_14--	//int Value2;//	����	int	0	NOT NULL
//--xx2009_1_14--//--xx2009_1_14--	union
//--xx2009_1_14--//--xx2009_1_14--	{
//--xx2009_1_14--//--xx2009_1_14--		//int Value3;
//--xx2009_1_14--//--xx2009_1_14--		int Brain;
//--xx2009_1_14--//--xx2009_1_14--	};
//--xx2009_1_14--
//--xx2009_1_14--//--	int Value4;//	��ǰ����	int	0	NOT NULL
//--xx2009_1_14--//--	int Value5;//	�������	int	0	NOT NULL
//--xx2009_1_14--//--	int Value6;//	�ҳϣ����ֵΪ100��	int	0	NOT NULL
//--xx2009_1_14--//--	int Value7;//	������������	int	0	NOT NULL
//--xx2009_1_14--
//--xx2009_1_14--//--xx2009_1_14--	std::string m_Name;
//--xx2009_1_14--//--xx2009_1_14--	//--}//--Property
//--xx2009_1_14--//--xx2009_1_14--	//--{//--release
//--xx2009_1_14--//--xx2009_1_14--public:
//--xx2009_1_14--//--xx2009_1_14--	virtual void release() {};
//--xx2009_1_14--//--xx2009_1_14--	//--}//--release
//--xx2009_1_14--
//--xx2009_1_14--	//--{//--Create/_Create
//--xx2009_1_14--//public:
//--xx2009_1_14--//--xx2009_1_14--protected:
//--xx2009_1_14--//--xx2009_1_14--	//--Hero/return this
//--xx2009_1_14--//--xx2009_1_14--	Hero* HeroCreate(uint32 roleid, uint32 guidlow/* = 0*/);//--guidlow(is hero id)
//--xx2009_1_14--//--xx2009_1_14--protected:
//--xx2009_1_14--//--xx2009_1_14--	virtual HCUnit* HC_Create(uint32 roleid, uint32 guidlow);
//--xx2009_1_14--//--xx2009_1_14--	//--}//--Create/_Create
//--xx2009_1_14--public:
//--xx2009_1_14--//--	virtual void dump();
//--xx2009_1_14--	GWA_HCUnit();
//--xx2009_1_14--protected:
//--xx2009_1_14--	virtual ~GWA_HCUnit();
//--xx2009_1_14--
//--xx2009_1_14--private:
//--xx2009_1_14--	Item* TackOnItemSetItem( Item *pItem );//--װ������ʱ���õ��߸�������
//--xx2009_1_14--	Item* TackOffItemSetItem( Item *pItem );//--ж�µ���ʱ���õ��߸�������
//--xx2009_1_14--
//--xx2009_1_14--	//--hero/player
//--xx2009_1_14--public:
//--xx2009_1_14--	virtual Item* GetItemByPos( uint8 bag, uint8 slot );
//--xx2009_1_14--	Item* GetItemByPos( uint16 pos );
//--xx2009_1_14--
//--xx2009_1_14--	//--����(1��)�µ���(��װ����)
//--xx2009_1_14--	virtual Item* CreateItem( uint32 protoid, uint32 count = 1 );
//--xx2009_1_14--
//--xx2009_1_14--	virtual uint8 FindFreeSlot()//;
//--xx2009_1_14--	{
//--xx2009_1_14--		return NULL_SLOT;
//--xx2009_1_14--	}
//--xx2009_1_14--
//--xx2009_1_14--	virtual Item* StoreItem( uint16 pos, Item *pItem )//;
//--xx2009_1_14--	{
//--xx2009_1_14--		return 0;
//--xx2009_1_14--	}
//--xx2009_1_14--	virtual uint32 GetFreeSlots()// const//;
//--xx2009_1_14--	{
//--xx2009_1_14--		return 0;
//--xx2009_1_14--	}
//--xx2009_1_14--public:
//--xx2009_1_14--	uint8 GetItemEquipSlot( uint32 protoid );// const;
//--xx2009_1_14--	//--�鿴ĳ�����Ƿ���װ����ĳ��λ��(slot)/(slot = NULL_SLOT)���ص�һ������װ����λ��(slot)
//--xx2009_1_14--	//--���ؿ�װ����λ��/��(NULL_SLOT)����װ��
//--xx2009_1_14--	uint8 FindEquipSlot(ItemPrototype const* proto, uint32 slot = NULL_SLOT);// const;
//--xx2009_1_14--	uint8 FindEquipSlot(uint32 protoid, uint32 slot = NULL_SLOT);// const;
//--xx2009_1_14--
//--xx2009_1_14--public:
//--xx2009_1_14--	//--װ������
//--xx2009_1_14--	virtual Item* EquipItemTackOn( Item *pItem );//--װ������
//--xx2009_1_14--	virtual Item* EquipItemTackOff( uint16 pos );//--ж�µ���
//--xx2009_1_14--
//--xx2009_1_14--//--	Item* StoreNewItem( uint16 pos, uint32 item, uint32 count, bool update,int32 randomPropertyId = 0 );
//--xx2009_1_14--//--	Item* StoreItem( uint16 pos, Item *pItem, bool update );
//--xx2009_1_14--//--	Item* EquipNewItem( uint16 pos, uint32 item, uint32 count, bool update );
//--xx2009_1_14--
//--xx2009_1_14--//--	uint8 GetEquipItemSlot( Item *pItem );
//--xx2009_1_14--//--	bool CanEquipItem( uint16 pos, Item *pItem );
//--xx2009_1_14--
//--xx2009_1_14--protected:
//--xx2009_1_14--	int Protos[MAX_PROTOS];//--
//--xx2009_1_14--	int ProtosAdd[MAX_PROTOS];//--additional
//--xx2009_1_14--
//--xx2009_1_14--public:
//--xx2009_1_14--//--xx2009_1_14--	inline const char* get_Name() const { return m_Name.c_str(); }
//--xx2009_1_14--
//--xx2009_1_14--
//--xx2009_1_14--public:
//--xx2009_1_14--//--xx2009_1_14--	inline bool Is_valid(const uint32 id) { return (id == Identifier()); }
//--xx2009_1_14--//--xx2009_1_14--	inline bool Is_invalid() { return (INVALID_HERO_ID == Identifier()); }
//--xx2009_1_14--private:
//--xx2009_1_14--//--xx2009_1_14--	//--make invalid
//--xx2009_1_14--//--xx2009_1_14--	inline void invalid() { Identifier(INVALID_HERO_ID); }
//--xx2009_1_14--	//--Identifier
//--xx2009_1_14--	//inline uint32& Identifier() { return HeroID(); }
//--xx2009_1_14--	//inline void Identifier(uint32 id) { HeroID(id); }
//--xx2009_1_14--//--xx2009_1_14--	virtual uint32& Identifier() { return m_HeroID; }
//--xx2009_1_14--//--xx2009_1_14--	virtual void Identifier(uint32 id) { m_HeroID = (id); }
//--xx2009_1_14--protected:
//--xx2009_1_14--	//--hero items
//--xx2009_1_14--	int itemsize;// = EQUIPMENT_SLOT_END;
//--xx2009_1_14--	Item** m_items;//[EQUIPMENT_SLOT_END];//--Ӣ������(װ����)����
//--xx2009_1_14--	//Item* m_items[EQUIPMENT_SLOT_END];//--Ӣ������(װ����)����
//--xx2009_1_14--	//--player(��ɫ)ӵ�еĵ���/����װ���ڽ�ɫ����(Ӣ��)���ϵĵ���/������װ������ɫ��ӵ��Ӣ�����ϵĵ���
//--xx2009_1_14--	//Item* m_items;//[PLAYER_SLOTS_COUNT];//--����hero items
//--xx2009_1_14--	//Item** m_items;//[PLAYER_SLOTS_COUNT];//--����hero items
//--xx2009_1_14--	//int itemsize;// = PLAYER_SLOTS_COUNT;
//--xx2009_1_14--public:
//--xx2009_1_14--
//--xx2009_1_14--//--//{mangos
//--xx2009_1_14--public:
//--xx2009_1_14--//	static bool IsInventoryPos( uint16 pos ) { return IsInventoryPos(pos >> 8,pos & 255); }
//--xx2009_1_14--//	static bool IsInventoryPos( uint8 bag, uint8 slot );
//--xx2009_1_14--	static bool IsEquipmentPos( uint16 pos ) { return IsEquipmentPos(pos >> 8,pos & 255); }
//--xx2009_1_14--	static bool IsEquipmentPos( uint8 bag, uint8 slot );
//--xx2009_1_14--	static bool IsBagPos( uint16 pos );
//--xx2009_1_14--//	static bool IsBankPos( uint16 pos ) { return IsBankPos(pos >> 8,pos & 255); }
//--xx2009_1_14--//	static bool IsBankPos( uint8 bag, uint8 slot );
//--xx2009_1_14--//	static bool IsBankBagPos( uint8 bag, uint8 slot );
//--xx2009_1_14--//	static bool IsWeaponSlot( uint8 slot ) { return slot==EQUIPMENT_SLOT_MAINHAND || slot==EQUIPMENT_SLOT_OFFHAND || slot==EQUIPMENT_SLOT_RANGED; }
//--xx2009_1_14--//	bool HasBankBagSlot( uint8 slot ) const;
//--xx2009_1_14--//	bool HasItemCount( uint32 item, uint32 count ) const;
//--xx2009_1_14--//	bool HasItemEquipped( uint32 item ) const;
//--xx2009_1_14--//	uint32 GetFreeSlots() const;
//--xx2009_1_14--//--//}mangos
//--xx2009_1_14--
//--xx2009_1_14--//--xx2008_12_5--	//--{//--Property
//--xx2009_1_14--//--xx2008_12_5--public:
//--xx2009_1_14--//--xx2008_12_5--	//--RoleID
//--xx2009_1_14--//--xx2008_12_5--	//inline uint32& RoleID() { return GetUInt32Value( OBJECT_FIELD_ROLEID ); }
//--xx2009_1_14--//--xx2008_12_5--	//inline void RoleID(const uint32 id) { SetUInt32Value( OBJECT_FIELD_ROLEID, id ); }
//--xx2009_1_14--//--xx2008_12_5--
//--xx2009_1_14--//--xx2008_12_5--	//--Identifier
//--xx2009_1_14--//--xx2008_12_5--	//--HeroID/Identifier
//--xx2009_1_14--//--xx2008_12_5--	inline uint32& HeroID() { return GetUInt32Value( HC_UNIT_FIELD_HEROID ); }
//--xx2009_1_14--//--xx2008_12_5--	inline void HeroID(const uint32 id) { SetUInt32Value( HC_UNIT_FIELD_HEROID, id ); }
//--xx2009_1_14--//--xx2008_12_5--
//--xx2009_1_14--//--xx2008_12_5--	//--AreaID
//--xx2009_1_14--//--xx2008_12_5--	inline uint32& AreaID() { return GetUInt32Value(HC_UNIT_FIELD_AREAID); }
//--xx2009_1_14--//--xx2008_12_5--	inline void AreaID(uint32 id) { SetUInt32Value(HC_UNIT_FIELD_AREAID, id); }
//--xx2009_1_14--//--xx2008_12_5--
//--xx2009_1_14--//--xx2008_12_5--	//--SkillID1,//--����ID1
//--xx2009_1_14--//--xx2008_12_5--	inline uint32& SkillID1() { return GetUInt32Value(HC_UNIT_FIELD_SkillID1); }
//--xx2009_1_14--//--xx2008_12_5--	inline void SkillID1(uint32 id) { SetUInt32Value(HC_UNIT_FIELD_SkillID1, id); }
//--xx2009_1_14--//--xx2008_12_5--	//--SkillLevel1,//--���ܼ���1
//--xx2009_1_14--//--xx2008_12_5--	inline uint32& SkillLevel1() { return GetUInt32Value(HC_UNIT_FIELD_SkillLevel1); }
//--xx2009_1_14--//--xx2008_12_5--	inline void SkillLevel1(uint32 id) { SetUInt32Value(HC_UNIT_FIELD_SkillLevel1, id); }
//--xx2009_1_14--//--xx2008_12_5--	//--SkillID2,//--����ID2
//--xx2009_1_14--//--xx2008_12_5--	inline uint32& SkillID2() { return GetUInt32Value(HC_UNIT_FIELD_SkillID2); }
//--xx2009_1_14--//--xx2008_12_5--	inline void SkillID2(uint32 id) { SetUInt32Value(HC_UNIT_FIELD_SkillID2, id); }
//--xx2009_1_14--//--xx2008_12_5--	//--SkillLevel2,//--���ܼ���2
//--xx2009_1_14--//--xx2008_12_5--	inline uint32& SkillLevel2() { return GetUInt32Value(HC_UNIT_FIELD_SkillLevel2); }
//--xx2009_1_14--//--xx2008_12_5--	inline void SkillLevel2(uint32 id) { SetUInt32Value(HC_UNIT_FIELD_SkillLevel2, id); }
//--xx2009_1_14--//--xx2008_12_5--
//--xx2009_1_14--//--xx2008_12_5--	//--HeadPhotoID,//--ͷ��ID
//--xx2009_1_14--//--xx2008_12_5--	inline uint32& HeadPhotoID() { return GetUInt32Value(HC_UNIT_FIELD_HeadPhotoID); }
//--xx2009_1_14--//--xx2008_12_5--	inline void HeadPhotoID(uint32 id) { SetUInt32Value(HC_UNIT_FIELD_HeadPhotoID, id); }
//--xx2009_1_14--//--xx2008_12_5--
//--xx2009_1_14--//--xx2008_12_5--	//--}//--Property
//--xx2009_1_14--};
//--xx2009_1_14--//--
//--xx2009_1_14--/*
//--xx2009_1_14--����Ӣ�۵��ߵĴ��
//--xx2009_1_14--����Ӣ����һ�����߰�(INVENTORY_SLOT_BAG_0/ֻ�Ǽ���)�����е���(���������İ�)������������(INVENTORY_SLOT_BAG_0)��
//--xx2009_1_14--*/
//--xx2009_1_14--//--
#endif // !defined(AFX_GWA_HCUNIT_H__C8A33156_D4A1_41F9_B99F_33B886A9F592__INCLUDED_)
