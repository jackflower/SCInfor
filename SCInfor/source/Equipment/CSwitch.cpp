//  ____________________________________
// | CSwitch.cpp - class implementation |
// | Jack Flower June 2014              |
// |____________________________________|
//

#include "CSwitch.h"
#include "../Utilities/Random/CRandom.h"

namespace equipment
{
	RTTI_IMPL_NOPARENT(CSwitch);

	//Konstruktor
	CSwitch::CSwitch()
	:
		m_state						(false),
		m_time_to_run_range			(m_time_to_run_first, m_time_to_run_second),
		m_time_to_run				(gRandom.Rndf(m_time_to_run_range.first, m_time_to_run_range.second)),
		m_elapsed_time				(0.0f)
	{
	}

	//Konstruktor
	CSwitch::CSwitch(bool state)
	:
		m_state						(state),
		m_time_to_run_range			(m_time_to_run_first, m_time_to_run_second),
		m_time_to_run				(gRandom.Rndf(m_time_to_run_range.first, m_time_to_run_range.second)),
		m_elapsed_time				(0.0f)
	{
	}

	//Konstruktor kopiuj¹cy
	CSwitch::CSwitch(const CSwitch & CSwitchCopy)
	:
		m_state						(CSwitchCopy.m_state),
		m_time_to_run_range			(CSwitchCopy.m_time_to_run_range),
		m_time_to_run				(CSwitchCopy.m_time_to_run),
		m_elapsed_time				(CSwitchCopy.m_elapsed_time)
	{
	}

	//Destruktor
	CSwitch::~CSwitch()
	{
		m_state						= false;
		m_time_to_run_range.first	= 0.0f;
		m_time_to_run_range.second	= 0.0f;
		m_time_to_run				= 0.0f;
		m_elapsed_time				= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CSwitch::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca stan urz¹dzenia
	const bool CSwitch::getState() const
	{
		return m_state;
	}

	//Metoda ustawia stan urz¹dzenia
	void CSwitch::setState(bool state)
	{
		m_state = state;
	}

	//Metoda zwraca czas do uruchomienia urz¹dzenia
	const float CSwitch::getTimeToRun() const
	{
		return m_time_to_run;
	}

	//Metoda ustawia czas do uruchomienia urz¹dzenia
	void CSwitch::setTimeToRun(float time_to_run)
	{
		m_time_to_run = time_to_run;
	}

	//Metoda zwraca sta³¹ referencjê na opakowanie przechowuj¹ce zakres do losowania czasu procesu
	const std::pair<float, float> & CSwitch::getTimeToRunRange() const
	{
		return m_time_to_run_range;
	}

	//Metoda ustawia referencjê na opakowanie przechowuj¹ce zakres do losowania czasu procesu
	void  CSwitch::setTimeToRunRange(const std::pair<float, float> & range)
	{
		m_time_to_run_range = range;
	}

	//Metoda ustawia referencjê na opakowanie przechowuj¹ce zakres do losowania czasu procesu
	void  CSwitch::setTimeToRunRange(float begin, float end)
	{
		m_time_to_run_range.first = begin;
		m_time_to_run_range.second = end;
	}

	//Metoda aktywuje w³¹cznik
	void CSwitch::updateToRun(float dt)
	{
		//aktywny - nie ma potrzeby uruchamiania procesu
		if (m_state) return;

		//prze³¹cznik jest wy³¹czony - nieaktywny
		if (!m_state)
		{
			m_elapsed_time += dt;					//zliczam czas do aktywowania
			if (m_elapsed_time >= m_time_to_run)	//po jego up³ywie
			{
				m_state = true;						//aktywacja
				m_elapsed_time = 0.0f;				//zerowanie czasu
			}
		}
	}
}//namespace equipment

 //Nadanie wartoœci sta³ym sk³adowym statycznym
float equipment::CSwitch::m_time_to_run_first	= 0.5f;	//statyczne dane dla zakresu - losowanie
float equipment::CSwitch::m_time_to_run_second	= 1.5f;	//statyczne dane dla zakresu - losowanie
