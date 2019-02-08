//  _____________________________________
// | CReceiver.cpp - class implementaion |
// | Jack Flower - July 2015             |
// |_____________________________________|
//

#include "CReceiver.h"

namespace logic
{
	namespace communication
	{
		RTTI_IMPL(CReceiver, Actor);

		//Chroniony konstruktor domy�lny
		CReceiver::CReceiver(const std::wstring& uniqueId)
		:
			Actor(uniqueId)//konstruktor klasy bazowej
		{
		}
			
		//Chroniony konstruktor kopiuj�cy
		CReceiver::CReceiver(const CReceiver &CReceiverCopy)
		:
			Actor (CReceiverCopy)//konstruktor kopiujacy klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CReceiver::~CReceiver()
		{
			//Actor				not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CReceiver::GetType() const
		{
			return rtti.GetNameClass();
		}
		
		//Metoda zwraca flag�, czy obiekt posiada modu� komunikacji
		const bool CReceiver::getUseCommunication() const
		{
			return m_use_communication;
		}

		//Metoda ustawia flag�, czy obiekt posiada modu� komunikacji
		void CReceiver::setUseCommunication(const bool use_communication)
		{
			m_use_communication = use_communication;
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CReceiver::update(float dt)
		{
		}
	}//namespace communication
}//namespace logic
