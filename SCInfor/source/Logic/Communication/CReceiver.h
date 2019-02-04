//  _____________________________________
// | CReceiver.h - class definition      |
// | Jack Flower - July 2015             |
// |_____________________________________|
//

#ifndef H_RECIVER_JACK
#define H_RECIVER_JACK

#include "../Actor/CActor.h"
#include "../../Equipment/Switch.h"
#include "CCommunication.h"

namespace logic
{
	namespace communication
	{
		///
		///Klasa bazowa reprezentuj�ca odbiornik
		///
		class CReceiver : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CReceiver, nale�y wywo�a� CPhysicalManager::CreateReceiver();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			///@param &uniqueId - sta�a referencja na obiekt klasy std::wstring
			///
			CReceiver(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CReceiverCopy - obiekt klasy CReceiver
			///
			CReceiver(const CReceiver &CReceiverCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			virtual ~CReceiver();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca flag�, czy obiekt posiada modu� komunikacji
			///
			const bool getUseCommunication() const;

			///
			///Metoda ustawia flag�, czy obiekt posiada modu� komunikacji
			///
			///@param use_communication - flaga, czy obiekt posiada modu� komunikacji
			///
			void setUseCommunication(const bool use_communication);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string			m_receiver_name;		//nazwa modu�u
			Switch				m_unit_controller;		//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka
			bool				m_use_communication;	//flaga, czy obiekt posiada modu� komunikacji
			CCommunication*		p_communication;		//wska�nik na obiekt klasy CCommunication (posiada modu� komunikacyjny)

			//to do...analiza p�l etc...

		};
	}//namespace communication
}//namespace logic
#endif//H_RECIVER_JACK
