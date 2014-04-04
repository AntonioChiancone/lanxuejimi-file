// LWonderProto.h: interface for the LWonderProto class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LWONDERPROTO_H__A71178A1_4FB6_4A32_8C0A_84179C3FB8AD__INCLUDED_)
#define AFX_LWONDERPROTO_H__A71178A1_4FB6_4A32_8C0A_84179C3FB8AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_1_6--
//#include "GameWorld.h"
#include "GW_T_ProtoType.h"

//--League Wonder Proto
typedef struct LWonderProto LWP;
struct LWonderProto  
//class LWonderProto  
: public GW_T_ProtoType
{
//--	uint8	Id;//--Wonder Id/ELWonderType
//--	uint8	Level;//--�ȼ�
//--	uint8	Type2;//--

	uint8	m_CanUpgrade;//--�Ƿ��������

	//--��������
	//uint32	m_NeedGold;//--�������

	uint32	m_NeedSilver;//--��������

	uint32	m_NeedValue;//--����Ҫ��

	//--����ǰ������
	//uint32	m_NeedLTechs[LIMIT_MAX_LTPS];//--Need (LTP) Proto Id

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
	//LWonderProto();
	//virtual ~LWonderProto();
	~LWonderProto();
	LWonderProto(int id = 0);

};
//--
class _LW_Type {};
//--League Wonder Id
enum ELWonderType
{
	LWonder_Null	= 0,//--

	LWonder_Start	= 1,//--
	//--
	LWonder_qinshihuang	= 1,//--����ٸ
	LWonder_TheArtofWar	= 2,//--���ӱ���
	LWonder_ForbiddenCity=3,//--�Ͻ���
	LWonder_SilkRoad	= 4,//--˿��֮·
	LWonder_Dujiangyan	= 5,//--������
	LWonder_GrandCanal	= 6,//--�������˺�
	//--
	LWonder_End	= 6,//--
	LWonder_Type_MAX,//--7
};
#define	MAX_LWONDER_TYPE	LWonder_Type_MAX
//--
inline const char* get_LWP_name(ELWonderType etype)
{
	if (etype < LWonder_Start || etype > LWonder_End)
		return "�����漣";
	static char * s[MAX_LWONDER_TYPE] =
	{
		"�����漣",

		"����ٸ",
		"���ӱ���",
		"�Ͻ���",
		"˿��֮·",
		"������",
		"�������˺�",
	};
	return s[etype];
}

//--League/Wonder Level/LWonderLevel
//typedef	uint8 LWonderLevel[MAX_LWONDER_TYPE];//--�ȼ�/League

#endif // !defined(AFX_LWONDERPROTO_H__A71178A1_4FB6_4A32_8C0A_84179C3FB8AD__INCLUDED_)
