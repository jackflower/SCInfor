//  ___________________________________
// | Switch.cpp - class implementation |
// | Jack Flower June 2014             |
// |___________________________________|
//

#include "Switch.h"
#include "../Utilities/Random/CRandom.h"

namespace equipment
{
	RTTI_IMPL_NOPARENT(Switch);

	//Konstruktor
	Switch::Switch()
	:
		m_state(false),
		m_time_to_run_range(m_time_to_run_first, m_time_to_run_second),
		m_time_to_run(gRandom.Rndf(m_time_to_run_range.first, m_time_to_run_range.second)),
		m_elapsed_time(0.0f)
	{
	}

	//Konstruktor
	Switch::Switch(bool state)
	:
		m_state(state),
		m_time_to_run_range(m_time_to_run_first, m_time_to_run_second),
		m_time_to_run(gRandom.Rndf(m_time_to_run_range.first, m_time_to_run_range.second)),
		m_elapsed_time(0.0f)
	{
	}

	//Konstruktor kopiujący
	Switch::Switch(const Switch & SwitchCopy)
	:
		m_state(SwitchCopy.m_state),
		m_time_to_run_range(SwitchCopy.m_time_to_run_range),
		m_time_to_run(SwitchCopy.m_time_to_run),
		m_elapsed_time(SwitchCopy.m_elapsed_time)
	{
	}

	//Destruktor
	Switch::~Switch()
	{
		m_state= false;
		m_time_to_run_range.first = 0.0f;
		m_time_to_run_range.second	= 0.0f;
		m_time_to_run = 0.0f;
		m_elapsed_time = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Switch::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca stan urządzenia
	const bool Switch::getState() const
	{
		return m_state;
	}

	//Metoda ustawia stan urządzenia
	void Switch::setState(bool state)
	{
		m_state = state;
	}

	//Metoda zwraca czas do uruchomienia urządzenia
	const float Switch::getTimeToRun() const
	{
		return m_time_to_run;
	}

	//Metoda ustawia czas do uruchomienia urządzenia
	void Switch::setTimeToRun(float time_to_run)
	{
		m_time_to_run = time_to_run;
	}

	//Metoda zwraca stałą referencję na opakowanie przechowujące zakres do losowania czasu procesu
	const std::pair<float, float> & Switch::getTimeToRunRange() const
	{
		return m_time_to_run_range;
	}

	//Metoda ustawia referencję na opakowanie przechowujące zakres do losowania czasu procesu
	void  Switch::setTimeToRunRange(const std::pair<float, float> & range)
	{
		m_time_to_run_range = range;
	}

	//Metoda ustawia referencję na opakowanie przechowujące zakres do losowania czasu procesu
	void  Switch::setTimeToRunRange(float begin, float end)
	{
		m_time_to_run_range.first = begin;
		m_time_to_run_range.second = end;
	}

	//Metoda aktywuje włącznik
	void Switch::updateToRun(float dt)
	{
		//aktywny - nie ma potrzeby uruchamiania procesu
		if (m_state) return;

		//przełącznik jest wyłączony - nieaktywny
		if (!m_state)
		{
			m_elapsed_time += dt;					//zliczam czas do aktywowania
			if (m_elapsed_time >= m_time_to_run)	//po jego upływie
			{
				m_state = true;						//aktywacja
				m_elapsed_time = 0.0f;				//zerowanie czasu
			}
		}
	}
}//namespace equipment

 //Nadanie wartości stałym składowym statycznym
float equipment::Switch::m_time_to_run_first	= 0.5f;	//statyczne dane dla zakresu - losowanie
float equipment::Switch::m_time_to_run_second	= 1.5f;	//statyczne dane dla zakresu - losowanie
