// GW_RLProtos.cpp: implementation of the GW_RLProtos class.
//
//////////////////////////////////////////////////////////////////////

#include "GW_RLProtos.h"

#include <cmath>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void GW_RLProtos::dump()
{
	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) GW_RLProtos::dump...\n", this));
	GW_TProtos<ProtoType>::dump();
	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) GW_RLProtos::dump...ok\n", this));
}
GW_RLProtos::GW_RLProtos()
{

}

GW_RLProtos::~GW_RLProtos()
{

}
bool GW_RLProtos::DB_Load()
{
	static int id = 0;
	{
		int valueNeedExp = 0;
		int valueForceExps = 0;
		int valueFreeValue = 3;
		for (int i = 0; i < 100; ++i)
		{
			ProtoType t(0);
			t.ProtoId = ++id;
			
			t.Level	= i;

			if (i > 0)
				valueNeedExp	= 0.999+pow(1.15, i)*53+valueNeedExp;
			t.m_NeedExps		= valueNeedExp;//--����Ҫ��
			
			if (i > 0)
				valueForceExps	= (1+i)*3-2-valueForceExps;
			t.m_GetForceExps	= valueForceExps;//--������սѫֵ��

			if (i > 0)
				valueFreeValue	= 1+i/30;
			t.m_GetFreeValue	= valueFreeValue;//--����������Է����
			
			add(t);
		}
	}

	ACE_DEBUG((LM_INFO, "[p%@](P%P)(t%t) GW_RLProtos::DB_Load...\n"
		" ����������������/�������\n"
		" ����(%d)/����������������\n"
		, this
		, count()
		));

	dump();
	return true;
}

bool GW_RLProtos::DB_Save()
{
	return false;
}
