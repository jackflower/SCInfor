//  ______________________________________
// | SlotsRate.h - class definition       |
// | Jack Flower - January 2016           |
// |______________________________________|
//

#ifndef H_SLOTS_RATE_JACK
#define H_SLOTS_RATE_JACK

#include "../../Actor/Actor.h"

namespace logic
{
	namespace energetics
	{
		///
		///Klasa reprezentuje wskaźnik przekaźnika
		///
		class SlotsRate : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt SlotsRate, należy wywołać PhysicalManager::CreateSlotsRate();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring
			///
			SlotsRate(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param SlotsRateCopy - obiekt klasy SlotsRate
			///
			SlotsRate(const SlotsRate & SlotsRateCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			virtual ~SlotsRate();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca ilość zajętych slotów
			///
			const int getSlotCounter() const;

			///
			///Metoda ustawia ilość zajętych slotów
			///
			///@param slot_counter - ilość zajętych slotów
			///
			void setSlotCounter(const int slot_counter);

			///
			///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			int m_slot_counter;	//ilość zajętych slotów - sterowana przez
								//class PowerRelayStation - aktualizacja animacji
		};

	}//namespace energetics
}//namespace logic
#endif//H_SLOTS_RATE_JACK
