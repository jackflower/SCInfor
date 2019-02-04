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
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CCombatUnit, nale¿y wywo³aæ CPhysicalManager::CreateCombatUnit();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			///@param & uniqueId - sta³a referencja na obiekt klasy std::wstring - identyfikator
			///
			CCombatUnit(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CCombatUnitCopy - obiekt klasy CCombatUnit
			///
			CCombatUnit(const CCombatUnit & CCombatUnitCopy);

			/////
			/////Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
			/////
			/////@param dt - czas
			/////
			//virtual void updateAnimations(float dt);

			/////
			/////Wirtualan metoda zabija obiekt klasy CActor i wywo³uje odpowiednie czynnoœci z tym zwi¹zane
			/////
			//virtual void Kill();

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			virtual ~CCombatUnit();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

		private:

			//logika ally
			//obiekty walcz¹ce, bojowe, ale nie krocz¹ce...
			//np. czo³gi, pojady bojowe, g¹sienicowe,
			//bojowe wozy piechoty, transportery, haubice,
			//dzia³a samobi¿ene....etc...

		};
	}//namespace unit
}//namespace logic
#endif//H_COMBAT_UNIT_JACK
