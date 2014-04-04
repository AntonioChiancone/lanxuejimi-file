// Building.h: interface for the Building class.
//
//////////////////////////////////////////////////////////////////////
//--xx2008_12_8--

#if !defined(AFX_BUILDING_H__43E55C00_2679_43A3_8D29_8783CDED3FCD__INCLUDED_)
#define AFX_BUILDING_H__43E55C00_2679_43A3_8D29_8783CDED3FCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "BuildingProto.h"
#include "GW_BCProtos.h"

//--Building of City Unit(...)/BCUnit
class Building
{
public:
	//--�Ѹ������Ĺ������Զ��ŵ�һ��(����)ʵ��
	//--
	typedef int (Building::*fptrBtTimer)(time_t curTime);
protected:
	fptrBtTimer	m_fptrBtTimer;//--ʱ����ص�����
public:
	inline int OnTimerEvent(time_t curTime)
	{
		if (m_fptrBtTimer)
			return (this->*m_fptrBtTimer)(curTime);
		return 0;
	}
private:
	//--��������Ҫ����ʵ�����Ƶ�Timer����(�����Ҫ�ù���)���ڹ���ʱ��ʼ��
	//--defalut/Building/do nothing
	int _Timer(time_t curTime);

	//--only for test
	typedef int (Building::*fptrBuilding)(void * ptr/* = 0*/);
	//fptrBuilding	m_fptrBt[MAX_Buildings];
	fptrBuilding	m_fptrBt[2];
private:
	int _Bt(void * ptr = 0);

	//--{//--Upgrade
public:
	bool Upgrade(time_t curTime, City* pCity);//--second
	bool DoUpgrade(City* pCity);
	bool CanUpgrade();
	uint8	m_Upgrade;//--����״̬
	time_t	m_BeginTime;//--(����)��ʼʱ��
	time_t	m_UpgradeTime;// = prototype.UpgradeTime;
	//--���洢�����ݿ�
	//--RemainTime = m_UpgradeTime+m_BeginTime-curTime;
	//--ϵͳά����������Ҫ����(m_BeginTime)���¼���(RemainTime)
	//--}//--Upgrade

public:
	const BCP * m_pProto;//--don't modify data/can't modify data
	uint32	m_ProtoId;
	void UpdateProto(int protoid);

	//--
	uint8	m_BuildingId;
	City*	m_pCity;
private:
	void _reset_clear()
	{
		m_pProto	= 0;
		m_ProtoId	= 0;
		m_Upgrade	= 0;
		m_BeginTime	= 0;
		m_UpgradeTime=0;
	}
public:
	void dump();
	//Building();
	//virtual ~Building();
	~Building();
//--xx2009_2_11--	Building(/*uint32 protoid = 0*/);
	Building(City * pCity, BtType BtId);

	inline BCP const * GetProto() { return m_pProto; }
private:
	inline BCP const * _GetProto()
	{
		static GW_BCProtos protos = gwBCProto;
		return protos.GetProto( m_ProtoId );
	}
};
//--
//--xx2009_2_11--typedef	Building Buildings[MAX_Buildings];
typedef	Building* BuildingPtr;
typedef	BuildingPtr Buildings[MAX_Buildings];

#endif // !defined(AFX_BUILDING_H__43E55C00_2679_43A3_8D29_8783CDED3FCD__INCLUDED_)
