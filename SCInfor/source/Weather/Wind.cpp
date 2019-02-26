//  _________________________________
// | Wind.cpp - class implementation |
// | Jack Flower - April 2014        |
// |_________________________________|
//

#include "Wind.h"

namespace weather
{
	namespace wind
	{

		RTTI_IMPL_NOPARENT(Wind);

		//Konstruktor
		Wind::Wind()
		:
			m_wind_speed{ 0.0f },
			m_duration_wind{ 0.0f }
		{
		}

		//Konstruktor kopiujący
		Wind::Wind(const Wind & copy)
		:
			m_wind_speed{ copy.m_wind_speed },
			m_duration_wind{ copy.m_duration_wind }
		{
		}

		//Konstruktor przenoszący
		Wind::Wind(Wind && other)
		:
			m_wind_speed{ other.m_wind_speed },
			m_duration_wind{ other.m_duration_wind }
		{
			//zerujemy składowe obiektu źródłowego...
			other.m_wind_speed = 0.0f;
			other.m_duration_wind = 0.0f;
		}


		//Destruktor
		Wind::~Wind()
		{
			m_wind_speed = 0.0f;
			m_duration_wind	= 0.0f;
		}

		//Przeciążony operator przypisania kopiowania
		Wind & Wind::operator=(const Wind & copy)
		{
			if (this != &copy)
			{
				m_wind_speed = copy.m_wind_speed;
				m_duration_wind = copy.m_duration_wind;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Wind & Wind::operator=(Wind && other)
		{
			if (this != &other)
			{
				m_wind_speed = other.m_wind_speed;
				m_duration_wind = other.m_duration_wind;
				//zerowanie obiektu źródłowego
				other.m_wind_speed = 0.0f;
				other.m_duration_wind = 0.0f;
			}
			return *this;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Wind::getType() const
		{
			return rtti.getNameClass();
		}


		//Metoda zwraca prędkość wiatru
		const float Wind::getWindSpped() const
		{
			return m_wind_speed;
		}

		//Metoda ustawia prędkość wiatru
		void Wind::setWindSpped(float wind_speed)
		{
			m_wind_speed = wind_speed;
		}

		//Metoda zwraca czas trwania wiatru
		const float Wind::getWindDuriation() const
		{
			return m_duration_wind;
		}

		//Metoda ustawia czas trwania wiatru
		void Wind::setWindDuriation(float duration_wind)
		{
			m_duration_wind = duration_wind;
		}
	}//namespace wind
}//namespace weather
