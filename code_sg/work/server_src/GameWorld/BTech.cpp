// BTech.cpp: implementation of the BTech class.
//
//////////////////////////////////////////////////////////////////////

#include "BTech.h"

#include "Building.h"
#include "WorldTimer.h"
#include "MCity.h"

bool BTech::Upgrade(time_t curTime, City* pCity)
{
	typedef BTP Proto;
	static GW_BTProtos protos = gwBTProto;

	ACE_ASSERT(m_pProto);
	if (!m_pProto)
		return false;

	if (m_UpgradeTime <= 0)
		return false;
	
	int RemainTime = m_UpgradeTime+m_BeginTime-curTime;
	if (RemainTime > 0)
		return false;

	const Proto * pProtoUp = protos.GetProtoUp(m_ProtoId);
	//ACE_ASSERT(pProtoUp);
	if (!pProtoUp)
		return false;
	uint32 protoid = pProtoUp->ProtoId;

	//--ok
	m_BeginTime = 0;
	m_UpgradeTime = 0;

	UpdateProto(protoid);//m_ProtoId	= pProtoUp->ProtoId;

	m_Upgrade = EBTU_OK;

//--	ACE_ASSERT(pCity);
//--	if (pCity)
//--		pCity->Update_City_RateValue();

	uint32 id = pProtoUp->TypeId;
	uint32 level = pProtoUp->Level;
	if (id >= BTech_Start && id <= BTech_End)
	{
		if (pCity)
			pCity->m_TechLevel[id] = level;
	}
	switch (id)
	{
	case BTech_Infantry://	= 1,//--�����о�
	case BTech_Archer://	= 2,//--�����о�
	case BTech_Cavalry://	= 3,//--����о�
	case BTech_Daobing://	= 4,//--�����о�
	case BTech_Pikeman://	= 5,//--ǹ���о�
		if (pCity)
			pCity->m_SoldierLevel[id] = level;
		break;
	//--
	case BTech_Infantry2://	= 15,//--��ʿ�о�
	case BTech_Archer2://	= 16,//--������о�
	case BTech_Cavalry2://	= 17,//--�ɹ������о�
	case BTech_Daobing2://	= 18,//--İ�����о�
	case BTech_Pikeman2://	= 19,//--���Ӫ�о�
	//--��е/Machinery/��ϵ������е
	case BTech_BaggageCar://= 20,//--��س��о�
	case BTech_TrafficCar://= 21,//--Ҫ�����о�
	case BTech_WarVehicle://= 22,//--����о�
	case BTech_Artillery://	= 23,//--�����о�
	case BTech_Truck://		= 24,//--ľţ�����о�
		if (pCity)
			pCity->m_SoldierLevel[id] = 1;
		break;
//--xx2009_1_5--
//--	//--��������
//--	Soldier_Infantry= 1,//--����
//--	Soldier_Archer	= 2,//--����
//--	Soldier_Cavalry	= 3,//--���
//--	Soldier_Daobing	= 4,//--����
//--	Soldier_Pikeman	= 5,//--ǹ��
//--
//--	//--�������/��ϵ����ĳ����������
//--	Soldier_Infantry2	= 6,//--��ʿ
//--	Soldier_Archer2		= 7,//--�����
//--	Soldier_Cavalry2	= 8,//--�ɹ�����
//--	Soldier_Daobing2	= 9,//--İ����
//--	Soldier_Pikeman2	= 10,//--���Ӫ
//--
//--	//--��е/Machinery/��ϵ������е
//--	Soldier_BaggageCar	= 11,//--��س�
//--	Soldier_TrafficCar	= 12,//--Ҫ����
//--	Soldier_WarVehicle	= 13,//--���
//--	Soldier_Artillery	= 14,//--����
//--	Soldier_Truck		= 15,//--ľţ����
//--	//--��ӱ����о�������
//--	BTech_Infantry	= 1,//--�����о�
//--	BTech_Archer	= 2,//--�����о�
//--	BTech_Cavalry	= 3,//--����о�
//--	BTech_Daobing	= 4,//--�����о�
//--	BTech_Pikeman	= 5,//--ǹ���о�
//--	//--
//--	BTech_Infantry2	= 6,//--��ʿ�о�
//--	BTech_Archer2	= 7,//--������о�
//--	BTech_Cavalry2	= 8,//--�ɹ������о�
//--	BTech_Daobing2	= 9,//--İ�����о�
//--	BTech_Pikeman2	= 10,//--���Ӫ�о�
//--	//--��е/Machinery/��ϵ������е
//--	BTech_BaggageCar= 11,//--��س��о�
//--	BTech_TrafficCar= 12,//--Ҫ�����о�
//--	BTech_WarVehicle= 13,//--����о�
//--	BTech_Artillery	= 14,//--�����о�
//--	BTech_Truck		= 15,//--ľţ�����о�
//--xx2009_1_5--
	}

	ACE_DEBUG((LM_DEBUG, "�Ƽ�/����(%s...���) BTech::Upgrade...\n", m_pProto->Name.c_str()));
//--	if (pCity)
//--		pCity->dump_city();

	return true;
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void BTech::dump()
{
	static WorldTimer &timer = worldTimer;

	if (!m_pProto)
	{
		DO_TRACERROR1_WARNING2("�����⣿���˿Ƽ���Ȼ������");
		return;
	}

	((BTP*)m_pProto)->dump();
	if (EBTU_OK == m_Upgrade)
	{
		ACE_DEBUG((LM_DEBUG, "BTech m_ProtoId=%d m_Upgrade=%d m_BeginTime=%d m_UpgradeTime=%d\n"
			, m_ProtoId, m_Upgrade, m_BeginTime, m_UpgradeTime
			));
	}
	else
	{
		ACE_DEBUG((LM_DEBUG, "BTech m_ProtoId=%d m_Upgrade=%d m_BeginTime=%d m_UpgradeTime=%d (RemainTime=%d)\n"
			, m_ProtoId, m_Upgrade, m_BeginTime, m_UpgradeTime
			, max(0, m_UpgradeTime+m_BeginTime-timer.GetTime())
			));
	}
}
//--BTech::BTech()
//--{
//--
//--}

BTech::~BTech()
{

}
BTech::BTech(uint32 protoid/* = 0*/)
: m_pProto(0)
//, m_ProtoId(protoid)
{
	memset(this, 0, sizeof(BTech));
	UpdateProto(protoid);
}

void BTech::UpdateProto(int protoid)
{
	memset(this, 0, sizeof(*this));
	if (protoid)
	{
		m_ProtoId = protoid;
		m_pProto = _GetProto();
		return;
	}
//--xx2009_1_20--	//--
//--xx2009_1_20--	m_ProtoId	= 0;
//--xx2009_1_20--	m_pProto	= 0;
}

bool BTech::CanUpgrade()
{
	typedef BTP Proto;
	static GW_BTProtos protos = gwBTProto;

	if (m_Upgrade > EBTU_OK)//--�������������
		return false;

	if (NULL == m_pProto)
		return false;

	if ( !(m_pProto->Upgrade) )//--��������
		return false;

	if (NULL == protos.GetProtoUp( m_pProto->ProtoId ))
		return false;

	return true;
}
bool BTech::DoUpgrade()
{
	static WorldTimer &timer = worldTimer;
	time_t curTime = timer.GetTime();

	m_BeginTime	= curTime;
	m_UpgradeTime	= m_pProto->NeedTime;
	//RemainTime = m_UpgradeTime+m_BeginTime-curTime;

	m_Upgrade = EBTU_Upgrade;
	return true;
}

