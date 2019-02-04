//  ____________________________________
// | CEnergy.cpp - class implementation |
// | Jack Flower May 2014               |
// |____________________________________|
//

#include "CSolarBattery.h"

namespace equipment
{
	namespace battery
	{
		RTTI_IMPL(CSolarBattery, CBattery);

		//Konstruktor domy�lny chroniony
		CSolarBattery::CSolarBattery(const std::wstring& uniqueId)
		:
			CBattery		(uniqueId),//konstruktor klasy bazowej
			m_decline		(0.0f)
		{
		}

		//Konstruktor kopiuj�cy chroniony
		CSolarBattery::CSolarBattery(const CSolarBattery& CSolarBatteryCopy)
		:
			CBattery		(CSolarBatteryCopy),//konstruktor kopiuj�cy klasy bazowej
			m_decline		(CSolarBatteryCopy.m_decline)
		{
		}

		//Destruktor chroniony
		CSolarBattery::~CSolarBattery(void)
		{
			//CBattery		not edit
			m_decline		= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CSolarBattery::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca warto�� spadku pojemno�ci baterii
		const float CSolarBattery::getDecline() const
		{
			return m_decline;
		}

		//Metoda ustawia warto�� spadku pojemno�ci baterii
		void CSolarBattery::setDecline(float decline)
		{
			m_decline = decline;
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CSolarBattery::Update(float dt)
		{
			CBattery::Update(dt);
			//je�li jest energia s�oneczna (factor dodatni)
			//nast�puje �adowanie ogniw baterii s�onecznej
			//ka�dy cykl od roz�adowania do �adowania
			//zmniejsza jej pojemno�� (sprawno��)
		}

	}//namespace battery
}//namespace equipment