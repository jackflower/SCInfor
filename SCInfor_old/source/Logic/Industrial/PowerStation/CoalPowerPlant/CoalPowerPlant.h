//  ___________________________________________
// | CoalPowerPlant.h - class definition       |
// | Jack Flower - July 2014                   |
// |___________________________________________|
//

#ifndef H_COAL_POWER_PLANT_JACK
#define H_COAL_POWER_PLANT_JACK

#include "../PowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalność elektrowni węglowej
		///
		class CoalPowerPlant : public PowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;
			
			//Aby uzyskać obiekt CoalPowerPlant, należy wywołać PhysicalManager::CreateCoalPowerPlant();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			CoalPowerPlant(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param CoalPowerPlantCopy - stała referencja na obiekt klasy CoalPowerPlant
			///
			CoalPowerPlant(const CoalPowerPlant & CoalPowerPlantCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			~CoalPowerPlant();

		public:
			
			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

		private:
			
			//

		};
	}//namespace powerstation
}//namespace logic
#endif//H_COAL_POWER_PLANT_JACK
