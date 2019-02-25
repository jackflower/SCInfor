/*
 _______________________________________________
| CEntityTemperature.cpp - implementacja klasy. |
| Jack Flower - June 2014.                      |
|_______________________________________________|

*/

#include "CEntityTemperature.h"

namespace universe
{
	RTTI_IMPL_NOPARENT(CEntityTemperature);

	//Konstruktor
	CEntityTemperature::CEntityTemperature(void)
	:
		m_entity_temperature	(0.0f)
	{
	}

	//Konstruktor kopiuj¹cy
	CEntityTemperature::CEntityTemperature(const CEntityTemperature & CEntityTemperatureCopy)
	:
		m_entity_temperature	(CEntityTemperatureCopy.m_entity_temperature)
	{
	}

	//Destruktor
	CEntityTemperature::~CEntityTemperature(void)
	{
		m_entity_temperature	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEntityTemperature::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca temperaturê
	const float CEntityTemperature::getEntityTemperature() const
	{
		return m_entity_temperature;
	}

	//Metoda ustawia temperaturê
	void CEntityTemperature::setEntityTemperature(float entity_temperature)
	{
		m_entity_temperature = entity_temperature;
	}

}//namespace universe