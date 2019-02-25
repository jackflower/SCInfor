//  ____________________________________
// | Receiver.h - class definition      |
// | Jack Flower - July 2015            |
// |____________________________________|
//

#ifndef H_RECIVER_JACK
#define H_RECIVER_JACK


#include "Communication.h"
#include "../Actor/Actor.h"
#include "../../Equipment/Switch.h"

namespace logic
{
	namespace communication
	{
		///
		///Klasa bazowa reprezentująca odbiornik
		///
		class Receiver : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt Receiver, należy wywołać PhysicalManager::CreateReceiver();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring
			///
			Receiver(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param ReceiverCopy - obiekt klasy Receiver
			///
			Receiver(const Receiver & ReceiverCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			virtual ~Receiver();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca flagę, czy obiekt posiada moduł komunikacji
			///
			const bool getUseCommunication() const;

			///
			///Metoda ustawia flagę, czy obiekt posiada moduł komunikacji
			///
			///@param use_communication - flaga, czy obiekt posiada moduł komunikacji
			///
			void setUseCommunication(const bool use_communication);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string m_receiver_name; //nazwa modułu
			Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka
			bool m_use_communication; //flaga, czy obiekt posiada moduł komunikacji
			Communication *p_communication; //wskaźnik na obiekt klasy Communication (posiada moduł komunikacyjny)

			//to do...analiza pól etc...

		};
	}//namespace communication
}//namespace logic
#endif//H_RECIVER_JACK
