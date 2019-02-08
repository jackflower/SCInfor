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
		///Klasa reprezentuje wskaŸnik przekaŸnika
		///
		class CSlotsRate : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CSlotsRate, nale¿y wywo³aæ CPhysicalManager::CreateSlotsRate();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			///@param &uniqueId - sta³a referencja na obiekt klasy std::wstring
			///
			CSlotsRate(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param & CSlotsRateCopy - obiekt klasy CSlotsRate
			///
			CSlotsRate(const CSlotsRate &CSlotsRateCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			virtual ~CSlotsRate();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca iloœæ zajêtych slotów
			///
			const int getSlotCounter() const;

			///
			///Metoda ustawia iloœæ zajêtych slotów
			///
			///@param slot_counter - iloœæ zajêtych slotów
			///
			void setSlotCounter(const int slot_counter);

			///
			///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			int				m_slot_counter;	//iloœæ zajêtych slotów - sterowana przez
											//class CPowerRelayStation - aktualizacja animacji
		};

	}//namespace energetics
}//namespace logic
#endif//H_SLOTS_RATE_JACK
