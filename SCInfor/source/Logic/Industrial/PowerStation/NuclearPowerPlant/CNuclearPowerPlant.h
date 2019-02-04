/*
 ______________________________________________
| CNuclearPowerPlant.h - definicja klasy.       |
| Jack Flower - July 2014.                     |
|______________________________________________|

*/

#ifndef H_NUCLEAR_POWER_PLANT_JACK
#define H_NUCLEAR_POWER_PLANT_JACK

#include "../CPowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalnoœæ elektrowni atomowej
		///
		class CNuclearPowerPlant : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskaæ obiekt CNuclearPowerPlant, nale¿y wywo³aæ CPhysicalManager::CreateNuclearPowerPlant();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			CNuclearPowerPlant(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CNuclearPowerPlantCopy - obiekt klasy CNuclearPowerPlant
			///
			CNuclearPowerPlant(const CNuclearPowerPlant &CNuclearPowerPlantCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			~CNuclearPowerPlant(void);

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

#endif//H_NUCLEAR_POWER_PLANT_JACK