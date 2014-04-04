// CityProperty.h: interface for the CityProperty class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CITYPROPERTY_H__56605DFB_1474_439A_81F8_CA42F52C9639__INCLUDED_)
#define AFX_CITYPROPERTY_H__56605DFB_1474_439A_81F8_CA42F52C9639__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//--xx2009_2_3--
#include "xDefProperty.h"
#include "GameWorld.h"

class _eResType {};
enum eResType
{
	Res_Food	= 0,
	Res_Silver,//
	Res_Culture,
	Res_Happy,
	Res_People,
	Res_Type_MAX,
};

class MCityProperty {};
//struct CityProperty
class CityProperty  
{
	friend class CityRefresh;
	friend class PlayerItems;
public:
	union
	{
		uint32 m_ResValue[Res_Type_MAX];
		//--private
		struct
		{
			uint32	m_Foods;//--��ǰ����
			uint32	m_Silvers;//--��ǰ����
			uint32	m_Cultures;//--��ǰ�Ļ�ֵ
			uint32	m_Happys;//--��ǰ����ֵ
			uint32	m_Peoples;//--��ǰ�˿�
		};
	};
private:
	inline uint32 SetResValue(eResType etype, uint32 value)
	{
		ACE_ASSERT( etype >= 0 && etype < Res_Type_MAX );
		return m_ResValue[etype] = value;
	}
	inline uint32 & _ResValue(eResType etype) { return m_ResValue[etype]; }
public:
	inline uint32 & Foods() { return m_ResValue[Res_Food]; }
	inline uint32 & Silvers() { return m_ResValue[Res_Silver]; }
	inline uint32 & Cultures() { return m_ResValue[Res_Culture]; }
	inline uint32 & Happys() { return m_ResValue[Res_Happy]; }
	inline uint32 & Peoples() { return m_ResValue[Res_People]; }

public:
	union
	{
		uint32 m_ResMax[Res_Type_MAX];
		//--private
		struct
		{
			uint32	m_FoodMax;//--��ʳ����
			uint32	m_SilverMax;//--��������
//--			uint32	m_CultureMax;//--�Ļ�ֵ����
//--			uint32	m_HappyMax;//--����ֵ����
//--			uint32	m_PeopleMax;//--�˿�����
		};
	};
private:
	inline uint32 SetResMax(eResType etype, uint32 value)
	{
		ACE_ASSERT( etype >= 0 && etype < Res_Type_MAX );
		return m_ResMax[etype] = value;
	}
	inline uint32 & _ResMax(eResType etype) { return m_ResMax[etype]; }

public:
	union
	{
		long m_ResRate[Res_Type_MAX];
		//--private
		struct
		{
			long	m_FoodRate;//--��ʳ����
			long	m_SilverRate;//--��������
			long	m_CultureRate;//--�Ļ�ֵ����
//--			long	m_HappyRate;//--����ֵ����
//--			long	m_PeopleRate;//--�˿ڲ���
		};
	};
private:
	inline long SetResRate(eResType etype, uint32 value)
	{
		ACE_ASSERT( etype >= 0 && etype < Res_Type_MAX );
		return m_ResRate[etype] = value;
	}
	inline long & _ResRate(eResType etype) { return m_ResRate[etype]; }

	//--CurValue1	��ǰ��ʳ	bigint	0	NOT NULL
	//--MaxValue1	��ʳ����	bigint	0	NOT NULL
	//--RateValue1	��ʳ������ÿСʱ��	int	0	NOT NULL
private:
//--	uint32	m_Foods;//--��ǰ����
protected:
	inline uint32 & _Foods() { return m_Foods; }
public:
	Property_INC(Food, m_Foods);//--Food_Inc
	Property_DEC(Food, m_Foods);//--Food_Dec
	//Property_get(Food, m_Foods);//--Food_get
	Property_get_uint32(Food, m_Foods);//--Food_get
	Property_set(Food, m_Foods);//--Food_set
private:
//--	uint32	m_FoodMax;//--��ʳ����
protected:
	inline uint32 & _FoodMax() { return m_FoodMax; }
public:
	//Property_get(FoodMax, m_FoodMax);//--FoodMax_get
	Property_get_uint32(FoodMax, m_FoodMax);//--FoodMax_get
	Property_set(FoodMax, m_FoodMax);//--FoodMax_set
private:
//--	long	m_FoodRate;//--��ʳ����
protected:
	inline long & _FoodRate() { return m_FoodRate; }
public:
	//Property_get(FoodRate, m_FoodRate);//--FoodRate_get
	Property_get_long(FoodRate, m_FoodRate);//--FoodRate_get
	Property_set(FoodRate, m_FoodRate);//--FoodRate_set

	//--CurValue2	��ǰ����	bigint	0	NOT NULL
	//--MaxValue2	��������	bigint	0	NOT NULL
	//--RateValue2	����������ÿСʱ��	int	0	NOT NULL
private:
//--	uint32	m_Silvers;//--��ǰ����
protected:
	inline uint32 & _Silvers() { return m_Silvers; }
public:
	Property_INC(Silver, m_Silvers);//--Silver_Inc
	Property_DEC(Silver, m_Silvers);//--Silver_Dec
	//Property_get(Silver, m_Silvers);//--Silver_get
	Property_get_uint32(Silver, m_Silvers);//--Silver_get
	Property_set(Silver, m_Silvers);//--Silver_set
private:
//--	uint32	m_SilverMax;//--��������
protected:
	inline uint32 & _SilverMax() { return m_SilverMax; }
public:
	//Property_get(SilverMax, m_SilverMax);//--SilverMax_get
	Property_get_uint32(SilverMax, m_SilverMax);//--SilverMax_get
	Property_set(SilverMax, m_SilverMax);//--SilverMax_set
private:
//--	long	m_SilverRate;//--��������
protected:
	inline long & _SilverRate() { return m_SilverRate; }
public:
	//Property_get(SilverRate, m_SilverRate);//--SilverRate_get
	Property_get_long(SilverRate, m_SilverRate);//--SilverRate_get
	Property_set(SilverRate, m_SilverRate);//--SilverRate_set

	//--CurValue3	��ǰ�Ļ�ֵ	int	0	NOT NULL
	//--RateValue3	�Ļ�ֵ������ÿСʱ��	int	0	NOT NULL
	//--�Ļ�/�����˿�/����Ҫ����
private:
//--	uint32	m_Cultures;//--��ǰ�Ļ�ֵ
protected:
	inline uint32 & _Cultures() { return m_Cultures; }
	Property_INC(Culture, m_Cultures);//--Culture_Inc
	Property_DEC(Culture, m_Cultures);//--Culture_Dec
public:
	//Property_get(Culture, m_Cultures);//--Culture_get
	Property_get_uint32(Culture, m_Cultures);//--Culture_get
	Property_set(Culture, m_Cultures);//--Culture_set
//--private:
//--	uint32	m_CultureMax;//--�Ļ�ֵ����
//--protected:
//--	inline uint32 & _CultureMax() { return m_CultureMax; }
//--public:
//--	//Property_get(CultureMax, m_CultureMax);//--CultureMax_get
//--	Property_get_uint32(CultureMax, m_CultureMax);//--CultureMax_get
//--	Property_set(CultureMax, m_CultureMax);//--CultureMax_set
private:
//--	long	m_CultureRate;//--�Ļ�ֵ����
protected:
	inline long & _CultureRate() { return m_CultureRate; }
public:
	//Property_get(CultureRate, m_CultureRate);//--CultureRate_get
	Property_get_long(CultureRate, m_CultureRate);//--CultureRate_get
	Property_set(CultureRate, m_CultureRate);//--CultureRate_set

	//--CurValue4	��ǰ����ֵ	int	0	NOT NULL
	//--RateValue4	����ֵ������ÿСʱ��	int	0	NOT NULL
	//--����ֵ/û�в���/����Ҫ����/��������(�������ط�����)
private:
//--	uint32	m_Happys;//--��ǰ����ֵ
protected:
	inline uint32 & _Happys() { return m_Happys; }
	Property_INC(Happy, m_Happys);//--Happy_Inc
	Property_DEC(Happy, m_Happys);//--Happy_Dec
public:
	//Property_get(Happy, m_Happys);//--Happy_get
	Property_get_uint32(Happy, m_Happys);//--Happy_get
	Property_set(Happy, m_Happys);//--Happy_set
//--private:
//--//--	uint32	m_HappyMax;//--����ֵ����
//--protected:
//--	inline uint32 & _HappyMax() { return m_HappyMax; }
//--public:
//--	//Property_get(HappyMax, m_HappyMax);//--HappyMax_get
//--	Property_get_uint32(HappyMax, m_HappyMax);//--HappyMax_get
//--	Property_set(HappyMax, m_HappyMax);//--HappyMax_set
//--private:
//--//--	long	m_HappyRate;//--����ֵ����
//--protected:
//--	inline long & _HappyRate() { return m_HappyRate; }
//--public:
//--	//Property_get(HappyRate, m_HappyRate);//--HappyRate_get
//--	Property_get_long(HappyRate, m_HappyRate);//--HappyRate_get
//--	Property_set(HappyRate, m_HappyRate);//--HappyRate_set

	//--CurValue5	��ǰ�˿�ֵ	int	0	NOT NULL
private:
//--	uint32	m_Peoples;//--��ǰ�˿�
protected:
	inline uint32 & _Peoples() { return m_Peoples; }
	Property_INC(People, m_Peoples);//--People_Inc
	Property_DEC(People, m_Peoples);//--People_Dec
public:
	//Property_get(People, m_Peoples);//--People_get
	Property_get_uint32(People, m_Peoples);//--People_get
	Property_set(People, m_Peoples);//--People_set
//--private:
//--//--	uint32	m_PeopleMax;//--�˿�����
//--protected:
//--	inline uint32 & _PeopleMax() { return m_PeopleMax; }
//--public:
//--	//Property_get(PeopleMax, m_PeopleMax);//--PeopleMax_get
//--	Property_get_uint32(PeopleMax, m_PeopleMax);//--PeopleMax_get
//--	Property_set(PeopleMax, m_PeopleMax);//--PeopleMax_set
//--private:
//--//--	long	m_PeopleRate;//--�˿ڲ���
//--protected:
//--	inline long & _PeopleRate() { return m_PeopleRate; }
//--public:
//--	//Property_get(PeopleRate, m_PeopleRate);//--PeopleRate_get
//--	Property_get_long(PeopleRate, m_PeopleRate);//--PeopleRate_get
//--	Property_set(PeopleRate, m_PeopleRate);//--PeopleRate_set

protected:
	CityProperty()
	{
		memset(this, 0, sizeof(*this));
	}
public:
	//CityProperty();
	//virtual ~CityProperty();
	~CityProperty();
public:

//--private://--must
//--	inline City * __City();//--must
};

#endif // !defined(AFX_CITYPROPERTY_H__56605DFB_1474_439A_81F8_CA42F52C9639__INCLUDED_)
