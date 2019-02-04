/*
 _________________________________________________
| CSuppliedDieselPower.h - definicja klasy.       |
| Jack Flower - August 2014.                      |
|_________________________________________________|

*/

#ifndef H_SUPPLIED_DIESEL_POWER_JACK
#define H_SUPPLIED_DIESEL_POWER_JACK

#include "../CPowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalnoœæ elektrowni wêglowej
		///
		class CSuppliedDieselPower : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskaæ obiekt CSuppliedDieselPower, nale¿y wywo³aæ CPhysicalManager::CreateSuppliedDieselPower();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			CSuppliedDieselPower(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CSuppliedDieselPowerCopy - obiekt klasy CSuppliedDieselPower
			///
			CSuppliedDieselPower(const CSuppliedDieselPower &CSuppliedDieselPowerCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			~CSuppliedDieselPower(void);

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

#endif//H_SUPPLIED_DIESEL_POWER_JACK
