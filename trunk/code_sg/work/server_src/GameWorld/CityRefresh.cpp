// CityRefresh.cpp: implementation of the CityRefresh class.
//
//////////////////////////////////////////////////////////////////////

#include "CityRefresh.h"
#include "MCity.h"

int CityRefresh::Update_Food_Silver(int food/*add*/, int silver/*add*/)
{
	City * city = __City();
	ACE_ASSERT( city );
	if (!city)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	//--Guard Lock
	//--����Ҫ�޸�����/���ܻ��world update��ͻ������
	//--�����������/������/�ڵ�����Ҫ�ĵط�����
	//Guard_CityUpdate();
	city->Food_Inc( food );
	city->Silver_Inc( silver );

	return true;//--ok
}
//--��/����
int CityRefresh::Update_CurValues(int elapsedTime/* = 1*/)
{
	Update_Res_Value(Res_Food, elapsedTime);
	Update_Res_Value(Res_Silver, elapsedTime);
	Update_Res_Value(Res_Culture, elapsedTime);
//	ACE_DEBUG((LM_DEBUG, "(��/����...���)[p%@](P%P)(t%t) MCity::Refresh...\n", this));
	return true;
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
City * CityRefresh::__City()
{
	//City* p = (City*)this;//--test
	return (City*)this;
}

//CityRefresh::CityRefresh()
//{
//
//}

CityRefresh::~CityRefresh()
{

}

int CityRefresh::Update_Res_Value(eResType etype, int elapsedTime/* = 1*/)
{
	ACE_ASSERT( !(etype < 0 || etype >= Res_Type_MAX) );
	if ( etype < 0 || etype >= Res_Type_MAX )
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	City * city = __City();
	ACE_ASSERT( city );
	if (!city)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	long valueRate	= city->_ResRate(etype);

	long & remain = RemainUpdateRes[etype];
	remain += (valueRate*elapsedTime);

	long value = remain/RATIO_TIME_DENO;
	if (value >= 1 || value <= -1)
	{
		remain = remain%RATIO_TIME_DENO;

		long valueCur	= city->_ResValue(etype);

		valueCur += value;

		valueCur = max( valueCur, 0 );
		valueCur = min( valueCur, city->_ResMax(etype) );
		city->SetResValue( etype, valueCur );
	}
	return true;
}

//--����/���㽨���ӳ�/����/�˿�������ʳ��
int CityRefresh::Update_RateValues()
{
	City * city = __City();
	ACE_ASSERT( city );
	if (!city)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	int value1 = 5000;//--��ʳ
	int value2 = -5000;//--����
	//int value3 = 0;//--�Ļ�
	//int value4 = 0;//--����
	int value5 = 0;//--�˿�
	//--Value/�����ӳ�/������
	{
		for (int i = BID_Start; i <= BID_End; ++i)
		{
//--xx2009_2_11--			Building & building = city->m_buildings[i];
			Building * ptr = city->m_buildings[i];
			if (ptr && ptr->m_pProto)
			{
				if (ptr->m_Upgrade < EBTU_OK)
					continue;

				value1 += ptr->m_pProto->Value1;
				value2 += ptr->m_pProto->Value2;
				//value3 += building->m_pProto->Value3;
				//value4 += building->m_pProto->Value4;
				value5 += ptr->m_pProto->Value5;
			}
		}

		//--�˿�/��
		city->People_set( value5 );
		//--�Ļ�/����
		static float ratioPopCulture = gwconfig.ratioPopCulture;
		city->CultureRate_set( value5*ratioPopCulture );
	}

	{
		//--��ׯ�ɷݼӳ�
//		Update_VilValues();
	}
	{
		//--����/�˿�������ʳ
		//DO_TRACERROR__WAIT1("MCity::Refresh ����/�˿�������ʳ");
	}

	//--�˿�/û�в���/����Ҫ����
	//_RateValue5() = value5;
	//--����ֵ/û�в���/����Ҫ����/��������(�������ط�����)
//--xx2009_2_3--	//Happy_set( value4 );
	//--�Ļ�/�����˿�/����Ҫ����
//--xx2009_2_3--	//Culture_set( value3 );

	value1 += city->m_VilValue1;
	value2 += city->m_VilValue2;

	//--�漣/�ӳ�
	{
		League * league = city->LeagueGet();
		if (league)
		{
			if (value1 > 0 && league->m_LWFoodsAddi > 100)
				value1 = (value1*league->m_LWFoodsAddi)/100;

			if (value2 > 0 && league->m_LWSilversAddi > 100)
				value2 = (value2*league->m_LWSilversAddi)/100;
		}
	}

	//--��ֵ/�ӳ�
	{
		if (value1 > 0 && city->m_pOwner)
			value1 = (value1*city->m_pOwner->TNB_Food(1))/100;
	}

//--xx2009_2_3--	m_FoodRate	= value1;//--���ݲ���
//--xx2009_2_3--	m_SilverRate= value2;//--��������

	//--��ʳ
	city->FoodRate_set( value1 );
	//--����
	city->SilverRate_set( value2 );

	return true;
}

int CityRefresh::Update_Upgrade(time_t curTime)
{
	City * city = __City();
	ACE_ASSERT( city );
	if (!city)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	//--Upgrade/��������/����
	{
		for (int i = BID_Start; i <= BID_End; ++i)
		{
//--xx2009_2_11--			Building & t = city->m_buildings[i];
//--xx2009_2_11--			if (t.Upgrade(curTime, city))
			Building * ptr = city->m_buildings[i];
			if (ptr// && ptr->m_pProto
				&& ptr->Upgrade(curTime, city)
				)
			{
				if (city->m_pOwner
					&& city->m_pOwner->m_PlaySession
					&& city->m_pOwner->m_PlaySession->session_sb
					)
				{
					DP dp;
					city->formatBuildingGet(dp, i);
					city->m_pOwner->SendDP(&dp);
				}
			}
		}
	}
	//--Upgrade/�Ƽ�����
	{
		for (int i = BTech_Start; i <= BTech_End; ++i)
		{
			BTech & t = city->m_btechs[i];
			if (t.Upgrade(curTime, city))
			{
				if (city->m_pOwner
					&& city->m_pOwner->m_PlaySession
					&& city->m_pOwner->m_PlaySession->session_sb
					)
				{
					DP dp;
					city->formatBTechGet(dp, i);
					city->m_pOwner->SendDP(&dp);
				}
			}
		}
	}
	return true;
}

int CityRefresh::Update_Armys(time_t curTime)
{
	City * city = __City();
	ACE_ASSERT( city );
	if (!city)
	{
		DO_TRACERROR1_WARNING();
		return 0;//--false
	}

	//--��������
	MRD * pMR = 0;
	if (city->m_pOwner
		&& city->m_pOwner->m_MRId
		)
	{
		pMR = city->m_pOwner->MR_Accept_Get();
	}

	listArmy & armys = city->m_Armys;

	//--����/�ж�
	for (listArmy::iterator it = armys.begin()
		; armys.end() != it
		;// ++it//--���ܻ��ڵ�ǰѭ�������б�ɾ��
		)
	{
		Army & army = *(*it);

		++it;

		//DO_TRACERROR__WAIT1("�����ж� - ��Ҫ����");
		
		if (army.m_StartTime
			&& army.m_NeedTime >= 0
			&& curTime >= (army.m_StartTime + army.m_NeedTime)
			)
		{
			//;
		}
		else
		{
			continue;
		}

		if (Army_IN_ToReturn == army.m_ArmyIn)//--����
		{
			army.Army_Return();//--�Ѿ�����
			continue;
		}
		//else
		switch (army.m_ArmyOp)
		{
		case Army_OP_Transport://--����
			{
				City * pOpCity = army.Get_Op_City();
				if (pOpCity && this != pOpCity
					&& (army.m_Food > 0 || army.m_Silver > 0)
					)
				{
					//pCity->dump();//--test
					pOpCity->Update_Food_Silver(army.m_Food, army.m_Silver);
					//pCity->dump();//--test

					//--��������
					if (pMR
						&& MRType_Res == pMR->m_type
						&& IS_VALID_AREAID(army.m_To)
						&& army.m_To == pMR->m_target
						&& army.m_Silver >= pMR->m_silver
						)
					{
						ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) [%08X]������Դ����...�����������\n", this, pOpCity->m_AreaID));
						pMR->TradeOK();
					}

					army.m_Food = 0;
					army.m_Silver = 0;
				}
				//	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) �����ж�...���䵽��...�������ڷ���\n", this));
				army.Army_ToReturn();

				continue;
			}
			break;

		case Army_OP_League://--
			{
				//DO_TRACERROR1_MSG( "����ս�� - ������ս" );
				continue;
			}
			break;
		case Army_OP_LMatch://--
			{
				//DO_TRACERROR1_MSG( "����ս�� - ��������" );
				continue;
			}
			break;

		default:
			{
				City * pOpCity = army.Get_Op_City();
				if (pOpCity && this != pOpCity)
				{
					DO_TRACERROR__WAIT1("ս��");
					//--ս��
					if ( pOpCity->Battle(&army) )
					{
						ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) [%08X]����ս��...����ʧ��\n", this, pOpCity->m_AreaID));
					}
					else
					{
						ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) [%08X]����ս��...���ֳɹ�\n", this, pOpCity->m_AreaID));
					}
				}
				else
				{
				//DO_TRACERROR__WAIT1("�����ж�");
				//army.m_NeedTime	= 0;
				//army.m_StartTime	= 0;
				//	army.Army_ToReturn();
				}
			}
			break;
		}
	}
	return true;
}
