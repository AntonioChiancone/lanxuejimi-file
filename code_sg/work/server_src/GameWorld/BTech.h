// BTech.h: interface for the BTech class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BTECH_H__0EB18B05_99AD_4535_B9DD_CB607B3162E2__INCLUDED_)
#define AFX_BTECH_H__0EB18B05_99AD_4535_B9DD_CB607B3162E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "BTechProto.h"
#include "GW_BTProtos.h"

class BTech  
{
public:
	const BTP * m_pProto;//--don't modify data/can't modify data
	uint32	m_ProtoId;
	void UpdateProto(int protoid);

public:
	void dump();
//--	BTech();
//--	virtual ~BTech();
	BTech(uint32 protoid = 0);
	~BTech();

	inline BTP const * GetProto() { return m_pProto; }

private:
	inline BTP const * _GetProto()
	{
		static GW_BTProtos btps = gwBTProto;
		return btps.GetProto( m_ProtoId );
	}

	//--{//--Upgrade
public:
	bool Upgrade(time_t curTime, City* pCity);//--second
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
//--(Building)Techs Level/BTechs
typedef	BTech BTechs[MAX_BTECH_TYPE];

#endif // !defined(AFX_BTECH_H__0EB18B05_99AD_4535_B9DD_CB607B3162E2__INCLUDED_)
