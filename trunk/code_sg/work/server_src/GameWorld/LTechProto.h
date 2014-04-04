// LTechProto.h: interface for the LTechProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LTECHPROTO_H__518248FB_0EFF_464E_AD29_2732AFCDC15F__INCLUDED_)
#define AFX_LTECHPROTO_H__518248FB_0EFF_464E_AD29_2732AFCDC15F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_1_5--
//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

#define	LIMIT_MAX_LTPS	1

//--League Tech Proto
typedef struct LTechProto LTP;
struct LTechProto  
//class LTechProto  
: public GW_T_ProtoType
{
//--	uint8	Id;//--LTech Id/ELTechType
//--	uint8	Level;//--�ȼ�
//--	uint8	Type2;//--

	uint8	m_CanUpgrade;//--�Ƿ��������

	//--��������
	//uint32	m_NeedGold;//--�������

	uint32	m_NeedSilver;//--��������

	uint32	m_NeedValue;//--����Ҫ��

	//--����ǰ������
	uint32	m_NeedLTechs[LIMIT_MAX_LTPS];//--Need (LTP) Proto Id

	//--
	uint32	m_NeedTime;//--

private:
	void reset_clear()
	{
		memset(((char*)this)+sizeof(GW_T_ProtoType)
			, 0
			, sizeof(*this)-sizeof(GW_T_ProtoType)
			);
	}
public:
	void dump();
	//LTechProto();
	//virtual ~LTechProto();
	~LTechProto();
	LTechProto(int id = 0);

};
//--
class _LT_Type {};
//--League Tech Id
enum ELTechType
{
	LTech_Null	= 0,//--

	LTech_Start	= 1,//--
	//--
	LTech_Manage	= 1,//--���˹���
	LTech_Attack	= 2,//--��������
	LTech_Defense	= 3,//--Эͬ����
	LTech_Speed		= 4,//--���½���
	LTech_Reaction	= 5,//--����Ч��
	//--
	LTech_End	= 5,//--
	LTech_Type_MAX,//--6
};
#define	MAX_LTECH_TYPE	LTech_Type_MAX
//--
inline const char* get_LTP_name(int id)
{
	if (id < LTech_Start || id > LTech_End)
		return "���˿Ƽ�0";
	static char * s[MAX_LTECH_TYPE] =
	{
		"���˿Ƽ�0",

		"���˹���",
		"��������",
		"Эͬ����",
		"���½���",
		"����Ч��",
	};
	return s[id];
}

//--League/Tech Level/LTechLevel
//typedef	uint8 LTechLevel[MAX_LTECH_TYPE];//--�ȼ�/League

#endif // !defined(AFX_LTECHPROTO_H__518248FB_0EFF_464E_AD29_2732AFCDC15F__INCLUDED_)
