//  ________________________________________________
// | SuppliedDieselPower.h - definicja klasy        |
// | Jack Flower - August 2014.                     |
// |________________________________________________|
//

#ifndef H_SUPPLIED_DIESEL_POWER_JACK
#define H_SUPPLIED_DIESEL_POWER_JACK

#include "../PowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalność elektrowni węglowej
		///
		class SuppliedDieselPower : public PowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;
			
			//Aby uzyskać obiekt SuppliedDieselPower, należy wywołać PhysicalManager::CreateSuppliedDieselPower();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			SuppliedDieselPower(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param SuppliedDieselPowerCopy - stała referencja na obiekt klasy SuppliedDieselPower
			///
			SuppliedDieselPower(const SuppliedDieselPower & SuppliedDieselPowerCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			~SuppliedDieselPower();

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
#endif//H_SUPPLIED_DIESEL_POWER_JACK
