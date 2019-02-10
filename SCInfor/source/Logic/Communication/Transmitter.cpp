//  _________________________________________
// | Transmitter.cpp - class implementation |
// | Jack Flower - July 2015                 |
// |_________________________________________|
//

#include "Transmitter.h"

namespace logic
{
	namespace communication
	{
		RTTI_IMPL(Transmitter, Actor);

		//Chroniony konstruktor domyślny
		Transmitter::Transmitter(const std::wstring & uniqueId)
		:
			Actor(uniqueId),//konstruktor klasy bazowej
			m_transmitter_name(""),
			m_unit_controller(false),//urządzenie wyłączone
			m_use_communication(false),
			p_communication(NULL)
		{
		}
			
		//Chroniony konstruktor kopiujący
		Transmitter::Transmitter(const Transmitter & TransmitterCopy)
		:
			Actor (TransmitterCopy),//konstruktor kopiujacy klasy bazowej
			m_transmitter_name(TransmitterCopy.m_transmitter_name),
			m_unit_controller(TransmitterCopy.m_unit_controller),//urządzenie wyłączone
			m_use_communication(TransmitterCopy.m_use_communication),
			p_communication(TransmitterCopy.p_communication)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		Transmitter::~Transmitter()
		{
			//~Actor()
			m_transmitter_name = "";
			//m_unit_controller
			m_use_communication = false;
			p_communication = NULL;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Transmitter::getType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizująca obiekt
		void Transmitter::update(float dt)
		{
		}
	}//namespace communication
}//namespace logic
