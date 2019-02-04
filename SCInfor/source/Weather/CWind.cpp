//  __________________________________
// | CWind.cpp - class implementation |
// | Jack Flower - April 2014         |
// |__________________________________|
//

#include "CWind.h"

namespace weather
{
	namespace wind
	{

		RTTI_IMPL_NOPARENT(CWind);

		//Konstruktor
		CWind::CWind()
		:
			m_wind_speed	(0.0f),
			m_duration_wind	(0.0f)
		{
		}

		//Konstruktor kopiuj¹cy
		CWind::CWind(const CWind& CWindCopy)
		:
			m_wind_speed	(CWindCopy.m_wind_speed),
			m_duration_wind	(CWindCopy.m_duration_wind)
		{
		}

		//Destruktor
		CWind::~CWind()
		{
			m_wind_speed	= 0.0f;
			m_duration_wind	= 0.0f;
		}

		//Metoda zwraca prêdkoœæ wiatru
		const float CWind::getWindSpped() const
		{
			return m_wind_speed;
		}

		//Metoda ustawia prêdkoœæ wiatru
		void CWind::setWindSpped(float wind_speed)
		{
			m_wind_speed = wind_speed;
		}

		//Metoda zwraca czas trwania wiatru
		const float CWind::getWindDuriation() const
		{
			return m_duration_wind;
		}

		//Metoda ustawia czas trwania wiatru
		void CWind::setWindDuriation(float duration_wind)
		{
			m_duration_wind = duration_wind;
		}
	}//namespace wind
}//namespace weather