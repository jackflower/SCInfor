//  _____________________________________________
// | NuclearPowerPlant.h - definicja klasy       |
// | Jack Flower - July 2014                     |
// |_____________________________________________|


#ifndef H_NUCLEAR_POWER_PLANT_JACK
#define H_NUCLEAR_POWER_PLANT_JACK

#include "../PowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalność elektrowni atomowej
		///
		class NuclearPowerPlant : public PowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskać obiekt NuclearPowerPlant, należy wywołać CPhysicalManager::CreateNuclearPowerPlant();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			NuclearPowerPlant(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param NuclearPowerPlantCopy - stała referencja na obiekt klasy NuclearPowerPlant
			///
			NuclearPowerPlant(const NuclearPowerPlant & NuclearPowerPlantCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
			///
			~NuclearPowerPlant();

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
#endif//H_NUCLEAR_POWER_PLANT_JACK
