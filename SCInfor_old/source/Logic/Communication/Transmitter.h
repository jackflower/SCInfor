//  ________________________________________
// | Transmitter.h - class definition       |
// | Jack Flower - July 2015                |
// |________________________________________|
//

#ifndef H_TRANSMITTER_JACK
#define H_TRANSMITTER_JACK


#include "Communication.h"
#include "../Actor/Actor.h"
#include "../../Equipment/Switch.h"

namespace logic
{
	namespace communication
	{
		///
		///Klasa bazowa reprezentująca nadajnik
		///
		class Transmitter : public Actor
		{

			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt Transmitter, należy wywołać PhysicalManager::CreateTransmitter();
		
		protected:
		
			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring
			///
			Transmitter(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param TransmitterCopy - obiekt klasy Transmitter
			///
			Transmitter(const Transmitter & TransmitterCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			virtual ~Transmitter();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string m_transmitter_name; //nazwa modułu
			Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka
			bool m_use_communication; //flaga, czy obiekt posiada moduł komunikacji
			Communication *p_communication; //wskaźnik na obiekt klasy Communication (posiada moduł komunikacyjny)

			//to do...analiza pól etc...

		};
	}//namespace communication
}//namespace logic
#endif//H_TRANSMITTER_JACK
