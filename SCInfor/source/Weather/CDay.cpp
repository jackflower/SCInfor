//  _________________________________
// | CDay.cpp - class implementation |
// | Jack Flower - June 2014         |
// |_________________________________|
//

#include "CDay.h"

namespace weather
{
	//Konstruktor
	CDay::CDay()
	:
		m_day_duration	(0.0f)
	{
	}

	//Konstruktor kopiuj¹cy
	CDay::CDay(const CDay & CDayCopy)
	:
		m_day_duration	(CDayCopy.m_day_duration)
	{
	}

	//Destruktor
	CDay::~CDay()
	{
		m_day_duration = 0.0f;
	}

	//Metoda zwraca czas trwania doby
	const float CDay::getDayDuration() const
	{
		return m_day_duration;
	}

	//Metoda ustawia czas trwania doby
	void CDay::setDayDuration(float day_duration)
	{
		m_day_duration = day_duration;
	}

}//namespace weather
