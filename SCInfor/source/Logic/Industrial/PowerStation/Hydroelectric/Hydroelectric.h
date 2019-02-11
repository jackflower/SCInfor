//  __________________________________________
// | Hydroelectric.h - class definition       |
// | Jack Flower - July 2014                  |
// |__________________________________________|
//

#ifndef H_HYDRO_ELECTRIC_JACK
#define H_HYDRO_ELECTRIC_JACK

#include "../PowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalność elektrowni wodnej
		///
		class Hydroelectric : public PowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskać obiekt Hydroelectric, należy wywołać CPhysicalManager::CreateHydroelectric();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			Hydroelectric(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param HydroelectricCopy - stała referencja na obiekt klasy Hydroelectric
			///
			Hydroelectric(const Hydroelectric & HydroelectricCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
			///
			~Hydroelectric();

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
#endif//H_HYDRO_ELECTRIC_JACK
