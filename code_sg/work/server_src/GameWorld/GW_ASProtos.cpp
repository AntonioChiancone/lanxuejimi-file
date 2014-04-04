// GW_ASProtos.cpp: implementation of the GW_ASProtos class.
//
//////////////////////////////////////////////////////////////////////

#include "GW_ASProtos.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void GW_ASProtos::dump()
{
	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) GW_ASProtos::dump...\n", this));
	GW_TProtos<ProtoType>::dump();
	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) GW_ASProtos::dump...ok\n", this));
}
GW_ASProtos::GW_ASProtos()
{

}

GW_ASProtos::~GW_ASProtos()
{

}

bool GW_ASProtos::DB_Load()
{
	static int id = 0;
	{
		int level = SOLDIER_LEVEL_DEFAULT;//--����/�ȼ�
		for (level = SOLDIER_LEVEL_DEFAULT; level <= SOLDIER_LEVEL_MAX; ++level)
		{
			int type2 = ArmyTech_Null;//--��ϵ
			for (int i = Soldier_Start; i <= Soldier_End; ++i)
			{
				type2 = get_SS_ArmySoldierId(i);//--��ϵ
				
				ArmySoldierProto t(i);
				
				t.ProtoId = ++id;
				
				//t.Id = i;
				t.Level = level;//SOLDIER_LEVEL_DEFAULT;//--����/�ȼ�
				t.Type2 = type2;//--��ϵ
				
				t.Attack	= 100+1+level*1;
				t.Strength	= 100+2+level*2;
				t.Health	= 100+3+level*3;
				t.Speed		= 100+4+level*4;

				//t.Value5	= 100+5+level*5;
				t.AttackRange=1;
				if (SSeries2Archer == type2) t.AttackRange = 10;
				
				t.WeightCarry=100+level*150;
				t.FoodNeed	= 100+level*50;

				t.Worth		= 100+level*50;

				t.Name = get_ASP_name(t.TypeId, t.Level);
				
				add(t);
			}
		}
	}
	
	ACE_DEBUG((LM_INFO, "[p%@](P%P)(t%t) GW_ASProtos::DB_Load...\n"
		" Ĭ�ϱ��ֶ���/�������\n"
		" ����(%d)Ĭ�ϱ��ֶ���\n"
		, this
		, count()
		));

	//dump();
	return true;
}

bool GW_ASProtos::DB_Save()
{
	return false;
}
