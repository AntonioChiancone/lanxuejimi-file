// LeagueTech.h: interface for the LeagueTech class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEAGUETECH_H__09F2A376_2A54_41D4_996F_01DCFDEE15F8__INCLUDED_)
#define AFX_LEAGUETECH_H__09F2A376_2A54_41D4_996F_01DCFDEE15F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GW_LTProtos.h"

//--League Tech
class LTech  
{
//--	League * m_pLeague;// = 0;

	typedef	LTP	Proto;
	typedef	GW_LTProtos	Protos;
public:
	const Proto * m_pProto;//--don't modify data/can't modify data
	uint32	m_ProtoId;
	void UpdateProto(int protoid);

public:
	void dump();
//--	LTech();
//--	virtual ~LTech();
	LTech(uint32 protoid = 0);
	~LTech();

	inline Proto const * GetProto() { return m_pProto; }

private:
	inline Proto const * _GetProto()
	{
		DEF_STATIC_REF(Protos, protos, gwLTProto);
		return protos.GetProto( m_ProtoId );
	}

	//--{//--Upgrade
public:
	bool Upgrade(time_t curTime, League* pLeague);//--second
	bool DoUpgrade();
	bool CanUpgrade();
	uint8	m_Upgrade;//--����״̬
	time_t	m_BeginTime;//--(����)��ʼʱ��
	time_t	m_UpgradeTime;// = prototype.UpgradeTime;
	//--���洢�����ݿ�
	//--RemainTime = m_UpgradeTime+m_BeginTime-curTime;
	//--ϵͳά����������Ҫ����(m_BeginTime)���¼���(RemainTime)
	//--}//--Upgrade
};
typedef	LTech LTechs[MAX_LTECH_TYPE];

#endif // !defined(AFX_LEAGUETECH_H__09F2A376_2A54_41D4_996F_01DCFDEE15F8__INCLUDED_)
