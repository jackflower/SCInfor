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

		//Konstruktor domyœlny chroniony
		CSolarBattery::CSolarBattery(const std::wstring& uniqueId)
		:
			CBattery		(uniqueId),//konstruktor klasy bazowej
			m_decline		(0.0f)
		{
		}

		//Konstruktor kopiuj¹cy chroniony
		CSolarBattery::CSolarBattery(const CSolarBattery& CSolarBatteryCopy)
		:
			CBattery		(CSolarBatteryCopy),//konstruktor kopiuj¹cy klasy bazowej
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

		//Metoda zwraca wartoœæ spadku pojemnoœci baterii
		const float CSolarBattery::getDecline() const
		{
			return m_decline;
		}

		//Metoda ustawia wartoœæ spadku pojemnoœci baterii
		void CSolarBattery::setDecline(float decline)
		{
			m_decline = decline;
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CSolarBattery::Update(float dt)
		{
			CBattery::Update(dt);
			//jeœli jest energia s³oneczna (factor dodatni)
			//nastêpuje ³adowanie ogniw baterii s³onecznej
			//ka¿dy cykl od roz³adowania do ³adowania
			//zmniejsza jej pojemnoœæ (sprawnoœæ)
		}

	}//namespace battery
}//namespace equipment