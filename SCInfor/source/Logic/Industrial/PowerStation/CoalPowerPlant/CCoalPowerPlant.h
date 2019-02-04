/*
 ____________________________________________
| CCoalPowerPlant.h - definicja klasy.       |
| Jack Flower - July 2014.                   |
|____________________________________________|

*/

#ifndef H_COAL_POWER_PLANT_JACK
#define H_COAL_POWER_PLANT_JACK

#include "../CPowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalnoœæ elektrowni wêglowej
		///
		class CCoalPowerPlant : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskaæ obiekt CCoalPowerPlant, nale¿y wywo³aæ CPhysicalManager::CreateCoalPowerPlant();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			CCoalPowerPlant(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CCoalPowerPlantCopy - obiekt klasy CCoalPowerPlant
			///
			CCoalPowerPlant(const CCoalPowerPlant &CCoalPowerPlantCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			~CCoalPowerPlant(void);

		public:
			
			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

		private:
			
			//

		};
	}//namespace powerstation
}//namespace logic

#endif//H_COAL_POWER_PLANT_JACK