//  ________________________________
// | Day.cpp - class implementation |
// | Jack Flower - June 2014        |
// |________________________________|
//

#include "Day.h"

namespace weather
{
	RTTI_IMPL_NOPARENT(Day);

	//Konstruktor
	Day::Day()
	:
		m_day_duration	(0.0f)
	{
	}

	//Konstruktor kopiujący
	Day::Day(const Day & copy)
	:
		m_day_duration	(copy.m_day_duration)
	{
	}

	//Konstruktor przenoszący
	Day::Day(Day && other)
	:
		m_day_duration{ other.m_day_duration }
	{
		//zerujemy składowe obiektu źródłowego...
		other.m_day_duration = 0.f;
	}

	//Destruktor
	Day::~Day()
	{
		m_day_duration = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Day::getType() const
	{
		return rtti.getNameClass();
	}

	//Przeciążony operator przypisania kopiowania
	Day & Day::operator=(const Day & copy)
	{
		if (this != &copy)
		{
			m_day_duration = copy.m_day_duration;
		}
		return *this;
	}

	//Przeciążony operator przypisania przenoszenia
	Day & Day::operator=(Day && other)
	{
		if (this != &other)
		{
			m_day_duration = other.m_day_duration;
			//zerowanie obiektu źródłowego
			other.m_day_duration = 0.0f;
		}
		return *this;
	}

	//Metoda zwraca czas trwania doby
	const float Day::getDayDuration() const
	{
		return m_day_duration;
	}

	//Metoda ustawia czas trwania doby
	void Day::setDayDuration(float day_duration)
	{
		m_day_duration = day_duration;
	}

}//namespace weather
