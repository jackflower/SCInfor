//  _________________________________________
// | CTransmitter.h - class definition       |
// | Jack Flower - July 2015                 |
// |_________________________________________|
//

#ifndef H_TRANSMITTER_JACK
#define H_TRANSMITTER_JACK

#include "../Actor/Actor.h"
#include "../../Equipment/Switch.h"
#include "CCommunication.h"

namespace logic
{
	namespace communication
	{
		///
		///Klasa bazowa reprezentuj�ca nadajnik
		///
		class CTransmitter : public Actor
		{

			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CTransmitter, nale�y wywo�a� CPhysicalManager::CreateTransmitter();
		
		protected:
		
			///
			///Chroniony konstruktor domy�lny
			///
			///@param &uniqueId - sta�a referencja na obiekt klasy std::wstring
			///
			CTransmitter(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CTransmitterCopy - obiekt klasy CTransmitter
			///
			CTransmitter(const CTransmitter &CTransmitterCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			virtual ~CTransmitter();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string			m_transmitter_name;		//nazwa modu�u
			Switch				m_unit_controller;		//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka
			bool				m_use_communication;	//flaga, czy obiekt posiada modu� komunikacji
			CCommunication*		p_communication;		//wska�nik na obiekt klasy CCommunication (posiada modu� komunikacyjny)

			//to do...analiza p�l etc...

		};
	}//namespace communication
}//namespace logic
#endif//H_TRANSMITTER_JACK
