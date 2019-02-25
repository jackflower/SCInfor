//  _________________________________________
// | CTemperature.cpp - class implementation |
// | Jack Flower - May 2014                  |
// |_________________________________________|
//

#include "CTemperature.h"
#include "CWeather.h"
#include <iostream>

namespace weather
{
	namespace temperature
	{
		RTTI_IMPL_NOPARENT(CTemperature);

		//Konstruktor
		CTemperature::CTemperature(void)
		:
			m_temperature				(0.0f),
			m_absolute_temperature		(0.0f),
			m_temperature_fluctuations	(0.0f)
		{
		}

		//Konstruktor kopiuj�cy
		CTemperature::CTemperature(const CTemperature & CTemperatureCopy)
		:
			m_temperature				(CTemperatureCopy.m_temperature),
			m_absolute_temperature		(CTemperatureCopy.m_absolute_temperature),
			m_temperature_fluctuations	(CTemperatureCopy.m_temperature_fluctuations)
		{
		}

		//Destruktor
		CTemperature::~CTemperature(void)
		{
			m_temperature				= 0.0f;
			m_absolute_temperature		= 0.0f;
			m_temperature_fluctuations	= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CTemperature::GetType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca temperatur�
		const float CTemperature::getTemperature() const
		{
			return m_temperature;
		}

		//Metoda ustawia temperatur�
		void CTemperature::setTemperature(float temperature)
		{
			m_temperature = temperature;
		}

		//Metoda zwraca temperatur� absolutn�
		const float CTemperature::getAbsoluteTemperature() const
		{
			return m_absolute_temperature;
		}

		//Metoda ustawia temperatur� absolutn�
		void CTemperature::setAbsoluteTemperature(float absolute_temperature)
		{
			m_absolute_temperature = absolute_temperature;
		}

		//Metoda zwraca wsp�czynnik waha� temperatury
		const float CTemperature::getFluctuationTemperature() const
		{
			return m_temperature_fluctuations;
		}

		//Metoda ustawia wsp�czynnik waha� temperatury
		void CTemperature::setFluctuationTemperature(float temperature_fluctuations)
		{
			m_temperature_fluctuations = temperature_fluctuations;
		}

		//Metoda aktualizuje logik� obiektu
		void CTemperature::update(float dt)
		{
			m_temperature = (gWeather.getSolarEnergyFactor() * m_temperature_fluctuations) + m_absolute_temperature;
		}
	}//namespace temperature
}//namespace weather
