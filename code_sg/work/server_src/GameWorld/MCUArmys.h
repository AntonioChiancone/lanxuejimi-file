// MCUArmys.h: interface for the MCUArmys class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCUARMYS_H__C258D3C6_F106_4F0B_95AD_ABA4F1607297__INCLUDED_)
#define AFX_MCUARMYS_H__C258D3C6_F106_4F0B_95AD_ABA4F1607297__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_6--
#include "GameWorld.h"

//--MCUnit Armys
class MCUArmys  
{
public:
	listArmy m_Armys;//--פ��/���10֧?
	bool IsArmyExist(Army * pArmy);
	Army * ArmyAdd(Army * const pArmy);
	Army * ArmyRemove(Army * const pArmy);

	listArmy m_EnemyArmys;//--�о�/���(������)
	Army * EnemyArmyAdd(Army * const pArmy);
	Army * EnemyArmyRemove(Army * const pArmy);

	listArmy m_FriendArmys;//--����פ��/���10֧
	Army * FriendArmyAdd(Army * const pArmy);
	Army * FriendArmyRemove(Army * const pArmy);

protected:
	MCUArmys();
public:
	//MCUArmys();
	//virtual ~MCUArmys();
	~MCUArmys();
public:

//--private://--must
//--	inline MCUnit * __MCUnit();//--must
};
//--xx2009_2_6--
#endif // !defined(AFX_MCUARMYS_H__C258D3C6_F106_4F0B_95AD_ABA4F1607297__INCLUDED_)
