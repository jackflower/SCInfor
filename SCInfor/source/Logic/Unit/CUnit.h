//  ___________________________________
// | CUnit.h - class definition        |
// | Jack Flower - May 2016            |
// |___________________________________|
//

#ifndef H_UNIT_JACK
#define H_UNIT_JACK

#include "../Actor/CActor.h"
#include "CStrategyController.h"

namespace logic
{
	namespace unit
	{
		///
		///Klasa reprezetuje obiekt gry
		///
		class CUnit : public CActor
		{
			RTTI_DECL;
		
			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CUnit, nale¿y wywo³aæ CPhysicalManager::CreateUnit();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			///@param & uniqueId - sta³a referencja na obiekt klasy std::wstring - identyfikator
			///
			CUnit(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CUnitCopy - obiekt klasy CUnit
			///
			CUnit(const CUnit & CUnitCopy);

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			virtual ~CUnit();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

		protected:

			CStrategyController	m_strategy_controller;	//kontroler strategii
		
		private:

		};
	}//namespace unit
}//namespace logic
#endif//H_UNIT_JACK
