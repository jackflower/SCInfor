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
		///Klasa reprezentuje funkcjonalno�� elektrowni w�glowej
		///
		class CSuppliedDieselPower : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;
			
			//Aby uzyska� obiekt CSuppliedDieselPower, nale�y wywo�a� CPhysicalManager::CreateSuppliedDieselPower();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			CSuppliedDieselPower(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CSuppliedDieselPowerCopy - obiekt klasy CSuppliedDieselPower
			///
			CSuppliedDieselPower(const CSuppliedDieselPower &CSuppliedDieselPowerCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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
