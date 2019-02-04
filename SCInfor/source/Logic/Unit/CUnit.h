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
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CUnit, nale�y wywo�a� CPhysicalManager::CreateUnit();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			///@param & uniqueId - sta�a referencja na obiekt klasy std::wstring - identyfikator
			///
			CUnit(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CUnitCopy - obiekt klasy CUnit
			///
			CUnit(const CUnit & CUnitCopy);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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
