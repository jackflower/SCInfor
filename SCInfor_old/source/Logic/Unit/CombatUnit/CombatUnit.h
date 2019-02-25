//  ________________________________________
// | CombatUnit.h - class definition        |
// | Jack Flower - May 2016                 |
// |________________________________________|
//

#ifndef H_COMBAT_UNIT_JACK
#define H_COMBAT_UNIT_JACK

#include "../Unit.h"


namespace logic
{
	namespace unit
	{
		///
		///Klasa reprezetuje obiekt gry
		///
		class CombatUnit : public Unit
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt CombatUnit, należy wywołać PhysicalManager::CreateCombatUnit();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring - identyfikator
			///
			CombatUnit(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param CombatUnitCopy - obiekt klasy CombatUnit
			///
			CombatUnit(const CombatUnit & CombatUnitCopy);

			///
			///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualan metoda zabija obiekt klasy Actor i wywołuje odpowiednie czynności z tym związane
			///
			virtual void kill();

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			virtual ~CombatUnit();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

		private:

			//logika ally
			//obiekty walczące, bojowe, ale nie kroczące...
			//np. czołgi, pojady bojowe, gąsienicowe,
			//bojowe wozy piechoty, transportery, haubice,
			//działa samobiżene....etc...

		};
	}//namespace unit
}//namespace logic
#endif//H_COMBAT_UNIT_JACK
