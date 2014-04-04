// MapCell.h: interface for the MapCell class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPCELL_H__64B20FB3_3EF5_44B5_9E7D_6AABB5A0E4E7__INCLUDED_)
#define AFX_MAPCELL_H__64B20FB3_3EF5_44B5_9E7D_6AABB5A0E4E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_6--
#include "GameWorld.h"
#include "GWA_MCUnit.h"

enum EMCellType
{
	CELL_NULL	= 0,//--default/�յ�
	CELL_BLANK	= 0,//--�յ�/CELL_NULL

	CELL_DESERT	= 1,//--��Į
	//--test/����
	CELL_PLAIN	= 2,//--ƽԭ
	CELL_MOUNTAIN=3,//--ɽ��
	CELL_LAKE	= 4,//--����
	CELL_RIVER	= 5,//--����
	CELL_FOREST	= 6,//--ɭ��
	//--
	CELL_Type_MAX,//--7
};
inline const char* get_MCell_Name(int id)
{
	if (id < 0 || id >= CELL_Type_MAX)
		return "-����-";
	static char * s[CELL_Type_MAX] =
	{
		"�յ�",

		"��Į",
		"ƽԭ",
		"ɽ��",
		"����",
		"����",
		"ɭ��",
	};
	return s[id];
}
enum EMCUnitType
{
	MCUNIT_NULL	= 0,//--

	MCUNIT_CITY	= 1,//--�ǳ�
	MCUNIT_ALERT= 2,//--���
	MCUNIT_FORT	= 3,//--Ҫ��
	MCUNIT_VILLAGE=4,//--��ׯ
};

struct MapCell  
//class MapCell  
{
	//--{//--GetMap
public:
	void formatMapGetCenter(DP &dp);
	void formatMapGet(uint32 roleid, DP &dp);
	//--}//--GetMap

public:
	//uint32	RoleID;
	union
	{
		uint32	AreaID;
		AIDP	xyArea;
	};

	uint8	AreaCode;//--��/��
	//uint8	cc[3];//--

	uint16	PhotoCode;

	uint8	CellType;//--����
	//uint8	CellType:4;//--����
private:
	//uint8	UnitType:4;//--
private:
	uint8	CellLevel;//--reserved

public:
	MCUnit* m_pMCU;// = 0;
public:
	MapCell()//;
	{
		memset(this, 0, sizeof(*this));
		AreaID	= INVALID_AREAID;
	}
	//virtual ~MapCell();
	~MapCell();
	MapCell(MapCell & cell)
		: AreaID(cell.AreaID)
		//--
		, CellType(cell.CellType)
		, CellLevel(cell.CellLevel)
		, PhotoCode(cell.PhotoCode)
	{
	}

public:
	inline string const Name() const
	{
		return ( (m_pMCU)?(m_pMCU->Name()):(get_MCell_Name(CellType)) );
	}
	inline string const RoleName() const
	{
		return ( (m_pMCU)?(m_pMCU->RoleName()):("--") );
	}
	inline string const LeagueName() const
	{
		return ( (m_pMCU)?(m_pMCU->LeagueName()):("--") );
	}
	//--
	string const AreaName() const;
private:
	inline string const MCellName() const
	{
		return (
			(m_pMCU)
			?( string(get_MCell_Name(CellType) ) + "/" + m_pMCU->MCUnitName() )
			:( get_MCell_Name(CellType) )
			);
	}
	friend class WorldMap;
};

#endif // !defined(AFX_MAPCELL_H__64B20FB3_3EF5_44B5_9E7D_6AABB5A0E4E7__INCLUDED_)

//--xx2008_12_5--inline const char* MapCell::get_Name()
//--xx2008_12_5--{
//--xx2008_12_5--	switch (CellType)
//--xx2008_12_5--	{
//--xx2008_12_5--	case Cell_unknown:
//--xx2008_12_5--		return "��Į";
//--xx2008_12_5--		break;
//--xx2008_12_5--	case Cell_blank:
//--xx2008_12_5--		return "�յ�";
//--xx2008_12_5--		break;
//--xx2008_12_5--	case Cell_city:
//--xx2008_12_5--		return "�ǳ�";
//--xx2008_12_5--		break;
//--xx2008_12_5--	case Cell_alert:
//--xx2008_12_5--		return "���";
//--xx2008_12_5--		break;
//--xx2008_12_5--	case Cell_fort:
//--xx2008_12_5--		return "Ҫ��";
//--xx2008_12_5--		break;
//--xx2008_12_5--	case Cell_village:
//--xx2008_12_5--		return "��ׯ";
//--xx2008_12_5--		break;
//--xx2008_12_5--	default:
//--xx2008_12_5--		return "--";
//--xx2008_12_5--		break;
//--xx2008_12_5--	}
//--xx2008_12_5--	return "--";
//--xx2008_12_5--}
//--xx2008_12_5--private:
//--xx2008_12_5--
//--xx2008_12_5--public:
//--xx2008_12_5--	const char* get_RoleName();
//--xx2008_12_5--	inline uint32 get_AreaID() { return AreaID; }
//--xx2008_12_5--	inline uint32 get_RoleID() { return RoleID; }
//--xx2008_12_5--	inline const char* get_Name();// { return Name.c_str(); }

//--xx2008_12_5--public:
//--xx2008_12_5--	inline bool Is_valid(const uint32 id) { return (id == AreaID); }
//--xx2008_12_5--	inline bool Is_invalid() { return (INVALID_AREA_ID == AreaID); }
//--xx2008_12_5--private:
//--xx2008_12_5--	//--make invalid
//--xx2008_12_5--	inline void invalid() { AreaID = INVALID_AREA_ID; }
//--xx2008_12_5--public:
//--xx2008_12_5--	inline uint16 map_X() { return X_OF_AREA_ID(AreaID); }
//--xx2008_12_5--	inline uint16 map_Y() { return Y_OF_AREA_ID(AreaID); }
//--xx2008_12_5--	inline uint32 map_AreaID(){ return AreaID; }

//--xx2008_12_5--public:
//--xx2008_12_5--	static inline uint16 make_x(uint32 id) { return X_OF_AREA_ID(id); }
//--xx2008_12_5--	static inline uint16 make_y(uint32 id) { return Y_OF_AREA_ID(id); }
//--xx2008_12_5--	static inline uint32 make_id(uint16 x, uint16 y)
//--xx2008_12_5--	{ return MAKE_AREA_ID(x, y); }

//--xx2008_12_5--	//--flag Set CellType
//--xx2008_12_5--public:
//--xx2008_12_5--	inline void flag_blank()	{ CellType = Cell_blank; }
//--xx2008_12_5--
//--xx2008_12_5--	inline void flag(uint8 f)	{ CellType = f; }
//--xx2008_12_5--	//--
//--xx2008_12_5--	inline void flag_city()	{ CellType = Cell_city; }
//--xx2008_12_5--	inline void flag_fort()	{ CellType = Cell_fort; }
//--xx2008_12_5--	inline void flag_alert(){ CellType = Cell_alert; }
//--xx2008_12_5--	//--
//--xx2008_12_5--	inline void flag_village()	{ CellType = Cell_village; }
//--xx2008_12_5--
//--xx2008_12_5--	//--check CellType
//--xx2008_12_5--public:
//--xx2008_12_5--	inline bool Is_blank()
//--xx2008_12_5--	{ return !(CellType < Cell_blank0 || CellType > Cell_blank1); }
//--xx2008_12_5--
//--xx2008_12_5--	inline bool Is_city() { return Cell_city == CellType; }
//--xx2008_12_5--	inline bool Is_fort() { return Cell_fort == CellType; }
//--xx2008_12_5--	inline bool Is_alert() { return Cell_alert == CellType; }
//--xx2008_12_5--
//--xx2008_12_5--	inline bool Is_village() { return Cell_village == CellType; }
//--xx2008_12_5--
//--xx2008_12_5--	inline bool Is_unknown();// { return Cell_unknown == CellType; }
//--xx2008_12_5--inline bool MapCell::Is_unknown()
//--xx2008_12_5--{
//--xx2008_12_5--	if (Cell_unknown == CellType)
//--xx2008_12_5--		return true;
//--xx2008_12_5--	else if (Is_blank())
//--xx2008_12_5--		return false;
//--xx2008_12_5--	else if (Is_city())
//--xx2008_12_5--		return false;
//--xx2008_12_5--	else if (Is_fort())
//--xx2008_12_5--		return false;
//--xx2008_12_5--	else if (Is_alert())
//--xx2008_12_5--		return false;
//--xx2008_12_5--	else if (Is_village())
//--xx2008_12_5--		return false;
//--xx2008_12_5--	else if (Is_village())
//--xx2008_12_5--		return false;
//--xx2008_12_5--	else
//--xx2008_12_5--		return true;
//--xx2008_12_5--}

//--//--MapCell Type
//--enum EMCType
//--{
//--	Cell_unknown= 0,//--must
//--
//--	//--Map Cell Type(MCT)
//--	//--�յ�
//--	Cell_blank	= 1,//--�յ�
//--	//--(����)
//--	Cell_blank0	= 1,//--�յ�
//--	Cell_blank1	= 1,//9,//--�յ�
//--//	//--ɽ��
//--//	Cell_mountain= 11,//--ɽ��
//--//	Cell_mountain0=11,//--ɽ��
//--//	Cell_mountain1=19,//--ɽ��
//--//	//--����
//--//	Cell_reserve= 21,//--����
//--//	Cell_reserve0=21,//--����
//--//	Cell_reserve1=99,//--����
//--
//--	//--Map Cell Unit(MCU)
//--	Cell_city	= 2,//101,//--�ǳ�
//--	Cell_alert	= 3,//102,//--���
//--	Cell_fort	= 4,//103,//--Ҫ��
//--
//--	Cell_village= 5,//151,//--��ׯ
//--
//--	//--Map Cell Unit NPC(MCU)
//--	//Cell_NPCity	= 6,//201,//--NPC�ǳ�
//--	//Cell_NPCalert=202,//--(����)NPC���
//--	//Cell_NPCfort= 203,//--(����)NPCҪ��
//--	//--
//--	Cell_limit//	= 255,//--limit
//--};
