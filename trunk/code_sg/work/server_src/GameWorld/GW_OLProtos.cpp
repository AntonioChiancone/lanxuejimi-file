// GW_OLProtos.cpp: implementation of the GW_OLProtos class.
//
//////////////////////////////////////////////////////////////////////

#include "GW_OLProtos.h"

#include <cmath>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void GW_OLProtos::dump()
{
	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) GW_OLProtos::dump...\n", this));
	GW_TProtos<ProtoType>::dump();
	ACE_DEBUG((LM_DEBUG, "[p%@](P%P)(t%t) GW_OLProtos::dump...ok\n", this));
}
GW_OLProtos::GW_OLProtos()
{

}

GW_OLProtos::~GW_OLProtos()
{

}
bool GW_OLProtos::DB_Load()
{
	//--test
	static int id = 0;
	{
		ProtoType t(0);
		t.ProtoId = ++id;

		t.TypeId= EOT_NULL;
		t.Level	= 0;

		t.Name	= "--";//--��û�й�ְ0->1��
		t.Desc	= "1����ְ";//--��û�й�ְ0->1��

		add(t);
	}
	//--�Ĺ�/EOT_WISDOM
	{
		int valueNeedExp = 0;
		for (int i = 0; i < 19; ++i)
		{
			ProtoType t(0);
			t.ProtoId = ++id;
			
			t.Desc	= "�Ĺ�";
			t.TypeId= EOT_WISDOM;
			t.Level	= i;

			if (i > 0)
			{
			valueNeedExp	= 0.999+pow(1.9, i)*510+valueNeedExp;
			t.m_NeedExps		= valueNeedExp;//--����Ҫ��
			
			t.m_GetGolds	= 2+i;//--��������ң�
			//--��������
			t.m_GetForceValue	= i;//--����
			t.m_GetLeadValue	= i;//--ͳ˧
			t.m_GetBrainValue	= 0;//--����
			}

			add(t);
		}
	}
	//--���/EOT_VALIANT
	{
		int valueNeedExp = 0;
		for (int i = 0; i < 19; ++i)
		{
			ProtoType t(0);
			t.ProtoId = ++id;
			
			t.Desc	= "���";
			t.TypeId= EOT_VALIANT;
			t.Level	= i;

			if (i > 0)
			{
			valueNeedExp	= 0.999+pow(1.9, i)*510+valueNeedExp;
			t.m_NeedExps		= valueNeedExp;//--����Ҫ��
			
			t.m_GetGolds	= 2+i;//--��������ң�
			//--��������
			t.m_GetForceValue	= 0;//--����
			t.m_GetLeadValue	= i;//--ͳ˧
			t.m_GetBrainValue	= i;//--����
			}

			add(t);
		}
	}

	ACE_DEBUG((LM_INFO, "[p%@](P%P)(t%t) GW_RLProtos::DB_Load...\n"
		" ������������/�������\n"
		" ����(%d)/������������\n"
		, this
		, count()
		));

	dump();
	return true;
}

bool GW_OLProtos::DB_Save()
{
	return false;
}
