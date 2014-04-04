//--xx2009_2_4--
//#include "_defBuildingId.h"

#ifndef DEF_BuildingId_HPP_
#define DEF_BuildingId_HPP_
class __DEF_BuildingId_HPP {};

class _eBuildingType {};
//--Building Id/��������붨��
enum eBuildingType
{
	BID_NULL	= 0,//--0/(����)
	BID_Start	= 1,//--0/(����)
	//--
	BID_Palace	= 1,//--1������Palace
	BID_Temple	= 2,//--2������Temple
	BID_Square	= 3,//--3���㳡Square
	BID_Bill	= 4,//--4����ʾ��Bill
	BID_Prison	= 5,//--5������Prison
	BID_College	= 6,//--6��̫ѧԺCollege
	BID_Workman	= 7,//--7��������Workman
	BID_Drill	= 8,//--8��������Drill
	BID_Charity	= 9,//--9������ԺCharity
	BID_Constellations	= 10,//--10������̨Constellations
	BID_Music	= 11,//--11���ָ�Music
	BID_Market	= 12,//--12���г�Market
	BID_Ally	= 13,//--13������Ally
	BID_Army	= 14,//--14����ӪArmy
	BID_Bar		= 15,//--15���ƹ�Bar
	BID_Martial	= 16,//--16�����Martial
	BID_Taoist	= 17,//--17������Taoist
	BID_Hospital= 18,//--18��ҽԺHospital
	BID_Cellar	= 19,//--19���ؽ�Cellar
	BID_Barn	= 20,//--20���ֿ�Barn
	BID_Walls	= 21,//--21����ǽWalls
	//--
	BID_End		= 21,
	BID_Type_MAX,//--22
};
#define MAX_Buildings	BID_Type_MAX
typedef enum eBuildingType BtType;
//--xx2009_2_17--typedef enum eBuildingType EBuildingType;
//--
inline const char* BuildingIdName(int id)
{
	if (id < BID_Start || id > BID_End)
		return "Unknown_Building";
	static char* s[MAX_Buildings]= 
	{
		"����",

		"����",
		"����",
		"�㳡",
		"��ʾ��",
		"����",
		"̫ѧԺ",
		"������",
		"������",
		"����Ժ",
		"����̨",
		"�ָ�",
		"�г�",
		"����",
		"��Ӫ",
		"�ƹ�",
		"���",
		"����",
		"ҽԺ",
		"�ؽ�",
		"�ֿ�",
		"��ǽ",
	};
	return s[id];
}

#endif
