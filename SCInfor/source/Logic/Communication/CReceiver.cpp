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
		RTTI_IMPL(CReceiver, CActor);

		//Chroniony konstruktor domyœlny
		CReceiver::CReceiver(const std::wstring& uniqueId)
		:
			CActor(uniqueId)//konstruktor klasy bazowej
		{
		}
			
		//Chroniony konstruktor kopiuj¹cy
		CReceiver::CReceiver(const CReceiver &CReceiverCopy)
		:
			CActor (CReceiverCopy)//konstruktor kopiujacy klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CReceiver::~CReceiver()
		{
			//CActor				not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CReceiver::GetType() const
		{
			return rtti.GetNameClass();
		}
		
		//Metoda zwraca flagê, czy obiekt posiada modu³ komunikacji
		const bool CReceiver::getUseCommunication() const
		{
			return m_use_communication;
		}

		//Metoda ustawia flagê, czy obiekt posiada modu³ komunikacji
		void CReceiver::setUseCommunication(const bool use_communication)
		{
			m_use_communication = use_communication;
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CReceiver::Update(float dt)
		{
		}
	}//namespace communication
}//namespace logic
