//  _______________________________________
// | CSlotsRate.h - class definition       |
// | Jack Flower - January 2016            |
// |_______________________________________|
//

#ifndef H_SLOTS_RATE_JACK
#define H_SLOTS_RATE_JACK

#include "../../Actor/Actor.h"

namespace logic
{
	namespace energetics
	{
		///
		///Klasa reprezentuje wska�nik przeka�nika
		///
		class CSlotsRate : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CSlotsRate, nale�y wywo�a� CPhysicalManager::CreateSlotsRate();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			///@param &uniqueId - sta�a referencja na obiekt klasy std::wstring
			///
			CSlotsRate(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param & CSlotsRateCopy - obiekt klasy CSlotsRate
			///
			CSlotsRate(const CSlotsRate &CSlotsRateCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			virtual ~CSlotsRate();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca ilo�� zaj�tych slot�w
			///
			const int getSlotCounter() const;

			///
			///Metoda ustawia ilo�� zaj�tych slot�w
			///
			///@param slot_counter - ilo�� zaj�tych slot�w
			///
			void setSlotCounter(const int slot_counter);

			///
			///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			int				m_slot_counter;	//ilo�� zaj�tych slot�w - sterowana przez
											//class CPowerRelayStation - aktualizacja animacji
		};

	}//namespace energetics
}//namespace logic
#endif//H_SLOTS_RATE_JACK
