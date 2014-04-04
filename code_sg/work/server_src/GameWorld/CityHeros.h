// CityHeros.h: interface for the CityHeros class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CITYHEROS_H__7187F874_ED80_44D6_B29C_69251D462BCF__INCLUDED_)
#define AFX_CITYHEROS_H__7187F874_ED80_44D6_B29C_69251D462BCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_6--
//#include "GameWorld.h"
#include "CPlayer.h"

#define CITY_MAX_HERO_SIZE 10

class MCityHeros {};
//struct CityHeros
class CityHeros  
{
private:
	string GenerateName();
public:
	Hero * Hero_Employ(uint32 heroid = 0);

//--xx2009_2_12--public:
//--xx2009_2_12--	Hero* m_pHeroOffice;//--�سǽ���(����)
protected:
	Hero* m_heros[CITY_MAX_HERO_SIZE];//--���HeroӢ������
	inline int hero_size_limit()
	{
		static int size = sizeof(m_heros)/sizeof(*m_heros);
		return size;
	}
public:
	bool hero_attach(Hero* pHero);
	bool hero_detach(Hero* pHero);
	
//--xx2009_2_12--	bool SetOfficeHero(Hero* pHero);//--���������سǽ���

protected:
	CityHeros();
public:
	void dump_heros();
	//CityHeros();
	//virtual ~CityHeros();
	~CityHeros();

public:
	//--�����ж�
	bool IsDefenseHero(Hero* pHero);
	//--�ж��Ƿ񱾳ǽ���
	inline bool IsCityHero(Hero* pHero)
	{
		if (!pHero)
			return 0;//--false

		int size = hero_size_limit();
		for (int i = 0; i < size; ++i)
		{
			if (pHero == m_heros[i])
				return true;
		}
		return 0;//--false
	}
	//--�ж��Ƿ��Ƿ��п�λ�÷Ÿ��ཫ��
	inline bool IsHeroRoom()
	{
		int size = hero_size_limit();
		for (int i = 0; i < size; ++i)
		{
			if (NULL == m_heros[i])
				return true;
		}
		return 0;//--false
	}

private://--must
	inline City * __City();//--must
};

#endif // !defined(AFX_CITYHEROS_H__7187F874_ED80_44D6_B29C_69251D462BCF__INCLUDED_)
