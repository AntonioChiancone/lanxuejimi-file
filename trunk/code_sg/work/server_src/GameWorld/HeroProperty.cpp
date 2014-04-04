// HeroProperty.cpp: implementation of the HeroProperty class.
//
//////////////////////////////////////////////////////////////////////

#include "HeroProperty.h"

#include "Random.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Hero * HeroProperty::__Hero()
{
	//Hero* p = (Hero*)this;//--test
	return (Hero*)this;
}

//HeroProperty::HeroProperty()
//{
//
//}

HeroProperty::~HeroProperty()
{

}
HeroProperty::HeroProperty()
{
	DEF_STATIC_REF(Random, randomor, gwRandom);

	memset(this, 0, sizeof(*this));

	m_HeroStatu	= HERO_OK;
	
	m_Force	= 1;
	m_Lead	= 1;
	m_Brain	= 1;

	//��ǰ����
	m_LifeCurrent	= 100;
	//�������
	m_Life	= 100;

	//--�ҳ�
	m_Loyalty	= 60;
	//--����
	//m_Physical	= 100;

	//	������������
	m_Layouts	= randomor.get(4, 6);

	//����
	//DO_TRACERROR__WAIT1( "����" );

	//ͷ��
	m_HeadPhotoID	= randomor.get(1, 30);
}
