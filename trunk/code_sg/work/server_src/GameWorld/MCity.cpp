// MCity.cpp: implementation of the MCity class.
//
//////////////////////////////////////////////////////////////////////

#include "MCity.h"

GuardMutex_CityUpdate MCity::m_lockCityUpdate;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void MCity::dump()
{
	ACE_DEBUG((LM_DEBUG, " city[%08X(x=%d,y=%d)] %s %d %d\n"
		, m_AreaID
		, X_OF_AREA_ID(m_AreaID)
		, Y_OF_AREA_ID(m_AreaID)
		, m_Name.c_str()
		, _Foods(), _Silvers()
		));
}
//MCity::MCity()
//{
//
//}
MCity::MCity(uint32 AreaID, Player *player/* = 0*/)
: MCUnit(AreaID, player)
{
	//--m_btechs/init
	memset(m_TechLevel, 0, sizeof(m_TechLevel));
	memset(m_btechs, 0, sizeof(m_btechs));
	{
		static GW_BTProtos protos = gwBTProto;

		uint32 id = 0;
		uint32 level = 0;
		for (int i = BTech_Start; i <= BTech_End; ++i)
		{
			id = i;
			level = 0;

			uint32 protoid = protos.GetProtoId(id, level);
			ACE_ASSERT(protoid);

			m_btechs[i].UpdateProto(protoid);
		}
	}

	//--buildings/init
	{
		static GW_BCProtos protos = gwBCProto;

		uint32 id = 0;
		uint32 level = 0;
		for (int i = BID_Start; i <= BID_End; ++i)
		{
			id = i;
			level = 0;

			uint32 protoid = protos.GetProtoId(id, level);
			ACE_ASSERT(protoid);

			m_buildings[i]->UpdateProto(protoid);
		}
	}
	Building_DoUpgrade(BID_Palace);


	//--
	m_ArmyLibrary.SetArmyOwner(this);

	memset(villages, 0, sizeof(villages));

//--xx2009_2_6--	m_VilValue1 = m_VilValue2 = 0;

	//--init
	m_Name = "�³ǳ�";

	Food_set( gwconfig.initFoodValue );
	FoodMax_set( gwconfig.maxFoodValue );
	FoodRate_set( 0 );

	Silver_set( gwconfig.initSilverValue );
	SilverMax_set( gwconfig.maxSilverValue );
	SilverRate_set( 0 );

	Culture_set( gwconfig.initCultureValue );
//--xx2009_2_3--	CultureMax_set( gwconfig.maxCultureValue );
	CultureRate_set( 0 );

	Happy_set( gwconfig.initHappyValue );
//--xx2009_2_3--	HappyMax_set( gwconfig.maxHappyValue );
	//HappyRate_set( gwconfig.rateHappyValue );

	People_set( 0 );
//--xx2009_2_3--	//PeopleMax_set( 0 );
//--xx2009_2_3--	//PeopleRate_set( 0 );

	Update_VilValues();

//	dump_city();
	DO_TRACERROR__WAIT1("�����ݿ��������");

	//--Update_City_RateValue
	Update_RateValues();


	//--test
	{
		for (int i = Soldier_Start; i <= Soldier_End; ++i)
		{
			ArmyIncrease(ESoldierType(i), 100000);
		}
		AssistIncrease(Assist_Taoist, 10);
		AssistIncrease(Assist_Doctor, 10);
		AssistIncrease(Assist_Teacher, 10);

		ArmyLayout layout;
		{
			for (int i = 0; i < MAX_ARMY_LAYOUT; ++i)
			{
				layout[i].Amount = 1000;
				layout[i].SoldierId = Soldier_Cavalry+i;
			}
		}
		ArmyAssist assist;
		{
			for (int i = Assist_Start
				; i <= Assist_End// && i < MAX_ARMY_LAYOUT
				; ++i
			)
			{
				assist[i] = 2;
			}
		}

		if ( m_pOwner )
			Army_Separate(m_pOwner, layout, assist);

		Hero *pHero = Hero_Employ();
		ACE_ASSERT( pHero );
		Army_Separate(pHero, layout, assist);
	}
}

MCity::~MCity()
{
	//release();
}
void MCity::dump_city()
{
	//ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) MCity::dump...\n", this));
	{
		uint32 id = m_AreaID;
		uint16 x = X_OF_AREA_ID(m_AreaID);
		uint16 y = Y_OF_AREA_ID(m_AreaID);

		ACE_DEBUG((LM_DEBUG, " city[%08X(x=%d,y=%d)] %s\n"
			
//--xx2009_2_3--			"_GeneralID(�سǽ���ID)=%d/_GeneralTypeID(�س�����)=%d\n"
			"(��ǰ��ʳ)=%d/(��ʳ����)=%d/(��ʳ����)=%d\n"
			"(��ǰ����)=%d/(��������)=%d/(��������)=%d\n"
			"(��ǰ�Ļ�)=%d\n"
			"(��ǰ����)=%d\n"
			"(�˿�)=%d\n"
			//--
			, id, x, y, m_Name.c_str()
//--xx2009_2_3--			, _GeneralID(), _GeneralTypeID()
			, _Foods(), _FoodMax(), _FoodRate()
			, _Silvers(), _SilverMax(), _SilverRate()
			, _Cultures(), _CultureRate()
			, _Happys()
			, _Peoples()
			));
		return;
		//--heros/city
		dump_heros();
//--		for (int i = 0; i < CITY_MAX_HERO_SIZE; ++i)
//--		{
//--			if (heros[i])
//--			{
//--				ACE_DEBUG((LM_DEBUG, "Ӣ��[%d]%s=%@\t"
//--					, i
//--					, (Is_General(heros[i]))?("(�سǽ���)"):("")
//--					, heros[i]
//--					));
//--				heros[i]->dump();
//--			}
//--		}
		//--����
		{
			int t = 0;
			for (int i = BID_Start; i <= BID_End; ++i)
			{
				++t;
				m_buildings[i]->dump();
			}
			if (0 == t)
			{
				ACE_DEBUG((LM_DEBUG, "�ճ� 0 ������\n"));
			}
		}
		//--����
		dump_armys();
	}
	//ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) MCity::dump...ok\n", this));
}
