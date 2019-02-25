//  __________________________________
// | Unit.h - class definition        |
// | Jack Flower - May 2016           |
// |__________________________________|
//

#ifndef H_UNIT_JACK
#define H_UNIT_JACK

#include "../Actor/Actor.h"
#include "StrategyController.h"

namespace logic
{
	namespace unit
	{
		///
		///Klasa reprezetuje obiekt gry
		///
		class Unit : public Actor
		{
			RTTI_DECL;
		
			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt Unit, należy wywołać PhysicalManager::CreateUnit();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring - identyfikator
			///
			Unit(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param UnitCopy - obiekt klasy Unit
			///
			Unit(const Unit & UnitCopy);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			virtual ~Unit();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

		protected:

			StrategyController m_strategy_controller; //kontroler strategii
		
		private:

		};
	}//namespace unit
}//namespace logic
#endif//H_UNIT_JACK
