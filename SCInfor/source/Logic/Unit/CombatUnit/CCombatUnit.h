//  ___________________________________
// | CombatUnit.h - class definition        |
// | Jack Flower - May 2016            |
// |___________________________________|
//

#ifndef H_COMBAT_UNIT_JACK
#define H_COMBAT_UNIT_JACK

#include "../CUnit.h"


namespace logic
{
	namespace unit
	{
		///
		///Klasa reprezetuje obiekt gry
		///
		class CCombatUnit : public CUnit
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CCombatUnit, nale�y wywo�a� CPhysicalManager::CreateCombatUnit();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			///@param & uniqueId - sta�a referencja na obiekt klasy std::wstring - identyfikator
			///
			CCombatUnit(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CCombatUnitCopy - obiekt klasy CCombatUnit
			///
			CCombatUnit(const CCombatUnit & CCombatUnitCopy);

			/////
			/////Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
			/////
			/////@param dt - czas
			/////
			//virtual void updateAnimations(float dt);

			/////
			/////Wirtualan metoda zabija obiekt klasy CActor i wywo�uje odpowiednie czynno�ci z tym zwi�zane
			/////
			//virtual void Kill();

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			virtual ~CCombatUnit();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

		private:

			//logika ally
			//obiekty walcz�ce, bojowe, ale nie krocz�ce...
			//np. czo�gi, pojady bojowe, g�sienicowe,
			//bojowe wozy piechoty, transportery, haubice,
			//dzia�a samobi�ene....etc...

		};
	}//namespace unit
}//namespace logic
#endif//H_COMBAT_UNIT_JACK
