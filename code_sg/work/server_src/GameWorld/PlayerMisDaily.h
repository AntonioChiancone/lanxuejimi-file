// PlayerMisDaily.h: interface for the PlayerMisDaily class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYERMISDAILY_H__96328262_DAA4_49AB_A907_FA91E0DE67C8__INCLUDED_)
#define AFX_PLAYERMISDAILY_H__96328262_DAA4_49AB_A907_FA91E0DE67C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_1_19--
//#include "GameWorld.h"
#include "MisDaily.h"

//--Mission Daily
class CPlayerMisDaily {};
//struct PlayerMisDaily
class PlayerMisDaily  
{
public:
	void formatMisDaily(DP &dp);

public:
	int MisDailyStart(uint32 MisDaily_ID/*ProtoId*/ = 0);//--��ʼ����
	int MisDailyCancel();//--ȡ������
	int MisDailyAuto();//--�Զ����/Accomplish

	int MisDailyBuy();//--(�����)������
private:
	int SpendAutoMisDaily();//--Auto
	int SpendBuyMisDaily();//--Buy
	//--
	inline int GetMisRemainBuy();
	inline int GetMisRemain();
public:
	inline int GetCurMisCount();//--��ǰ������
public:
	uint32	m_MisOKTimes;// = 0;//--ִ�������ܴ���
	//--
	time_t	m_MisTime;// = 0;//--ǰһ�������ʱ/��24Сʱ����Ϊ��ǰʱ��

	int	m_MisTodayCount;// = 1;//--�������������

	vector<uint32>	m_MisSelect;
	MisDaily	m_MisCur;//--���ڽ�������/����ֻ��һ��һ���Ľ���

	int	m_MisTodayLimit;// = 1;//--������������/-����/���ݽ����ȼ���ȷ��

	//--extra Buy/��������
	//--��ҿ��Զ����������5�����񣬵�����Ҫ���Ľ�ҡ�ÿ������5��ҡ�
	int	m_MisTodayBuy;// = 0;//--�����Ѿ�����������

private:
	void reset_clear()
	{
		m_MisOKTimes= 0;
		m_MisTime	= 0;

		m_MisTodayCount	= 0;

		m_MisTodayLimit	= 3;

		m_MisTodayBuy	= 0;
	}
protected:
	PlayerMisDaily();
public:
	//PlayerMisDaily();
	//virtual ~PlayerMisDaily();
	~PlayerMisDaily();

public:
	void MisDailyOK(MisDaily * pMisDaily);
	void MisDailyReport(MisDaily * pMisDaily);

	void MisDaily_add(uint32 MisDaily_ID/*ProtoId*/)
	{
		if (GetMisRemain() > 0)
			m_MisSelect.push_back(MisDaily_ID);
	}
private:
	void MisDaily_buy(uint32 MisDaily_ID/*ProtoId*/)
	{
		if (GetMisRemainBuy() >= 0)
			m_MisSelect.push_back(MisDaily_ID);
	}
	void MisDaily_remove(uint32 MisDaily_ID/*ProtoId*/)
	{
		for (vector<uint32>::iterator it = m_MisSelect.begin()
			; m_MisSelect.end() != it
			; ++it
			)
		{
			if (MisDaily_ID == *it)
			{
				m_MisSelect.erase(it);
				break;
			}
		}
	}

private://--must
	inline Player * __Player();//--must
};
inline int PlayerMisDaily::GetMisRemainBuy()
{
	return (5-m_MisTodayBuy);
}
inline int PlayerMisDaily::GetMisRemain()
{
	int t = m_MisTodayLimit;
	t -= ( (m_MisCur.m_ProtoId && m_MisCur.m_pProto)?(1):(0) );
	t -= m_MisTodayCount;
	t -= m_MisSelect.size();
	return t;
}
inline int PlayerMisDaily::GetCurMisCount()
{
	return ( m_MisSelect.size()
		+ ( (m_MisCur.m_ProtoId && m_MisCur.m_pProto)?(1):(0) )
		);
}

#endif // !defined(AFX_PLAYERMISDAILY_H__96328262_DAA4_49AB_A907_FA91E0DE67C8__INCLUDED_)
