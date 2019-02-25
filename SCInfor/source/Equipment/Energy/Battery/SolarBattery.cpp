//  _________________________________________
// | SolarBattery.cpp - class implementation |
// | Jack Flower May 2014                    |
// |_________________________________________|
//

#include "SolarBattery.h"

namespace equipment
{
	namespace battery
	{
		RTTI_IMPL(SolarBattery, Battery);

		//Konstruktor domyślny chroniony
		SolarBattery::SolarBattery(const std::wstring & uniqueId)
		:
			Battery(uniqueId),//konstruktor klasy bazowej
			m_decline(0.0f)
		{
		}

		//Konstruktor kopiujący chroniony
		SolarBattery::SolarBattery(const SolarBattery & SolarBatteryCopy)
		:
			Battery(SolarBatteryCopy),//konstruktor kopiujący klasy bazowej
			m_decline(SolarBatteryCopy.m_decline)
		{
		}

		//Destruktor chroniony
		SolarBattery::~SolarBattery(void)
		{
			//Battery
			m_decline = 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string SolarBattery::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca wartość spadku pojemności baterii
		const float SolarBattery::getDecline() const
		{
			return m_decline;
		}

		//Metoda ustawia wartość spadku pojemności baterii
		void SolarBattery::setDecline(float decline)
		{
			m_decline = decline;
		}

		//Wirtualna metoda aktualizująca obiekt
		void SolarBattery::update(float dt)
		{
			Battery::update(dt);
			//jeśli jest energia słoneczna (factor dodatni)
			//następuje ładowanie ogniw baterii słonecznej
			//każdy cykl od rozładowania do ładowania
			//zmniejsza jej pojemność (sprawność)

			//po testach klasy bazowej Battery
			//tutaj wymagana jest impelmentacja "starzenie" baterii...
		}

	}//namespace battery
}//namespace equipment