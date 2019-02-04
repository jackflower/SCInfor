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
		///Klasa reprezentuje funkcjonalno�� elektrowni w�glowej
		///
		class CCoalPowerPlant : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;
			
			//Aby uzyska� obiekt CCoalPowerPlant, nale�y wywo�a� CPhysicalManager::CreateCoalPowerPlant();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			CCoalPowerPlant(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CCoalPowerPlantCopy - obiekt klasy CCoalPowerPlant
			///
			CCoalPowerPlant(const CCoalPowerPlant &CCoalPowerPlantCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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