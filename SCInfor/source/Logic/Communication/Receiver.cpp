//  ____________________________________
// | Receiver.cpp - class implementaion |
// | Jack Flower - July 2015            |
// |____________________________________|
//

#include "Receiver.h"

namespace logic
{
	namespace communication
	{
		RTTI_IMPL(Receiver, Actor);

		//Chroniony konstruktor domyślny
		Receiver::Receiver(const std::wstring & uniqueId)
		:
			Actor(uniqueId),//konstruktor klasy bazowej
			m_receiver_name(""),
			m_unit_controller(false),//urządzenie wyłączone
			m_use_communication(false),
			p_communication(NULL)
		{
		}
			
		//Chroniony konstruktor kopiujący
		Receiver::Receiver(const Receiver & ReceiverCopy)
		:
			Actor (ReceiverCopy),//konstruktor kopiujacy klasy bazowej
			m_receiver_name(ReceiverCopy.m_receiver_name),
			m_unit_controller(ReceiverCopy.m_unit_controller),//urządzenie wyłączone
			m_use_communication(ReceiverCopy.m_use_communication),
			p_communication(ReceiverCopy.p_communication)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		Receiver::~Receiver()
		{
			//~Actor()
			m_receiver_name = "";
			//m_unit_controller
			m_use_communication = false;
			p_communication = NULL;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Receiver::getType() const
		{
			return rtti.GetNameClass();
		}
		
		//Metoda zwraca flagę, czy obiekt posiada moduł komunikacji
		const bool Receiver::getUseCommunication() const
		{
			return m_use_communication;
		}

		//Metoda ustawia flagę, czy obiekt posiada moduł komunikacji
		void Receiver::setUseCommunication(const bool use_communication)
		{
			m_use_communication = use_communication;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Receiver::update(float dt)
		{
		}
	}//namespace communication
}//namespace logic
