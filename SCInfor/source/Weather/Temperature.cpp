//  ________________________________________
// | Temperature.cpp - class implementation |
// | Jack Flower - May 2014                 |
// |________________________________________|
//

#include "Temperature.h"
#include "Weather.h"
#include <iostream>

namespace weather
{
	namespace temperature
	{
		RTTI_IMPL_NOPARENT(Temperature);

		//Konstruktor
		Temperature::Temperature()
		:
			m_temperature{ 0.0f },
			m_absolute_temperature{ 0.0f },
			m_temperature_fluctuations{ 0.0f }
		{
		}

		//Konstruktor kopiujący
		Temperature::Temperature(const Temperature & copy)
		:
			m_temperature{ copy.m_temperature },
			m_absolute_temperature{ copy.m_absolute_temperature },
			m_temperature_fluctuations{ copy.m_temperature_fluctuations }
		{
		}

		//Konstruktor przenoszący
		Temperature::Temperature(Temperature && other)
		:
			m_temperature{ other.m_temperature },
			m_absolute_temperature{ other.m_absolute_temperature },
			m_temperature_fluctuations{ other.m_temperature_fluctuations }
		{
			//zerujemy składowe obiektu źródłowego...
			other.m_temperature = 0.0f;
			other.m_absolute_temperature = 0.0f;
			other.m_temperature_fluctuations = 0.0f;
		}

		//Destruktor
		Temperature::~Temperature(void)
		{
			m_temperature = 0.0f;
			m_absolute_temperature = 0.0f;
			m_temperature_fluctuations = 0.0f;
		}

		//Przeciążony operator przypisania kopiowania
		Temperature & Temperature::operator=(const Temperature & copy)
		{
			if (this != &copy)
			{
				m_temperature = copy.m_temperature;
				m_absolute_temperature = copy.m_absolute_temperature;
				m_temperature_fluctuations = copy.m_temperature_fluctuations;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Temperature & Temperature::operator=(Temperature && other)
		{
			if (this != &other)
			{
				m_temperature = other.m_temperature;
				m_absolute_temperature = other.m_absolute_temperature;
				m_temperature_fluctuations = other.m_temperature_fluctuations;
				//zerowanie obiektu źródłowego
				other.m_temperature = 0.0f;
				other.m_absolute_temperature = 0.0f;
				other.m_temperature_fluctuations = 0.0f;
			}
			return *this;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Temperature::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca temperaturę
		const float Temperature::getTemperature() const
		{
			return m_temperature;
		}

		//Metoda ustawia temperaturę
		void Temperature::setTemperature(float temperature)
		{
			m_temperature = temperature;
		}

		//Metoda zwraca temperaturę absolutną
		const float Temperature::getAbsoluteTemperature() const
		{
			return m_absolute_temperature;
		}

		//Metoda ustawia temperaturę absolutną
		void Temperature::setAbsoluteTemperature(float absolute_temperature)
		{
			m_absolute_temperature = absolute_temperature;
		}

		//Metoda zwraca współczynnik wahań temperatury
		const float Temperature::getFluctuationTemperature() const
		{
			return m_temperature_fluctuations;
		}

		//Metoda ustawia współczynnik wahań temperatury
		void Temperature::setFluctuationTemperature(float temperature_fluctuations)
		{
			m_temperature_fluctuations = temperature_fluctuations;
		}

		//Metoda aktualizuje logikę obiektu
		void Temperature::update(float dt)
		{
			m_temperature = (gWeather.getSolarEnergyFactor() * m_temperature_fluctuations) + m_absolute_temperature;
		}
	}//namespace temperature
}//namespace weather
