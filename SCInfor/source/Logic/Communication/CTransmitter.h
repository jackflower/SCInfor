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
		///Klasa bazowa reprezentuj¹ca nadajnik
		///
		class CTransmitter : public Actor
		{

			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CTransmitter, nale¿y wywo³aæ CPhysicalManager::CreateTransmitter();
		
		protected:
		
			///
			///Chroniony konstruktor domyœlny
			///
			///@param &uniqueId - sta³a referencja na obiekt klasy std::wstring
			///
			CTransmitter(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CTransmitterCopy - obiekt klasy CTransmitter
			///
			CTransmitter(const CTransmitter &CTransmitterCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			virtual ~CTransmitter();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string			m_transmitter_name;		//nazwa modu³u
			Switch				m_unit_controller;		//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka
			bool				m_use_communication;	//flaga, czy obiekt posiada modu³ komunikacji
			CCommunication*		p_communication;		//wskaŸnik na obiekt klasy CCommunication (posiada modu³ komunikacyjny)

			//to do...analiza pól etc...

		};
	}//namespace communication
}//namespace logic
#endif//H_TRANSMITTER_JACK
