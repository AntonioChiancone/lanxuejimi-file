// MisReward.h: interface for the MisReward class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MISREWARD_H__0BC5C664_C7FF_4017_B666_E78DAC3494C4__INCLUDED_)
#define AFX_MISREWARD_H__0BC5C664_C7FF_4017_B666_E78DAC3494C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_1_23--
#include "GameWorld.h"
//#include "MisRewardProto.h"
//#include "GW_MRProtos.h"
#include "baseTrade.h"

typedef	class MisReward	MRD;
//--Mission Reward/��������/��һ�ֽ���
class MisReward//--MRD
: public baseTrade
{
	friend class WorldUpdate;

	//--24Сʱ����/��Ҫ�Զ�ȡ��
	int Timeout();
public:
	virtual int TradeOK();// { DO_TRACERROR1_WARNING(); return false; }// = 0;
	virtual int TradeCancel();// { DO_TRACERROR1_WARNING(); return false; }// = 0;

public:
	//--Ŀ������
	union
	{
		uint32	m_target;//--AreaID
		AIDP	m_targetAP;
	};

	//--����/reward
	int	m_gold;//--���

	union
	{
		//--��Դ
		int	m_silver;//--���������������
		//--ս��
		int	m_worth;//--������������Ŀ�겿�Ӽ�ֵ����
	};
	//--��Դ
	//int	m_food;//--����������������

public:
	//MisReward();
	//virtual ~MisReward();
	~MisReward();
	MisReward(uint32 target, ETradeTypes type, uint32 saler)
		: baseTrade(type, saler)
		//--
		, m_target(target)
	{
		PublishNewID();//--test

		m_gold	= 0;

		m_silver	= 0;
		//--
		//m_worth		= 0;
	}
	virtual void PublishNewID();
//	{
//		static int id = 0;
//		m_ID = ++id;
//		DO_TRACERROR1_WARNING();
//	}
};
typedef ACE_Hash_Map_Manager<ACE_INT32, MisReward*
, ACE_SYNCH_NULL_MUTEX>
HM_MRDS;//--Hash Map MisRewards
//--xx2009_1_23--
#endif // !defined(AFX_MISREWARD_H__0BC5C664_C7FF_4017_B666_E78DAC3494C4__INCLUDED_)
