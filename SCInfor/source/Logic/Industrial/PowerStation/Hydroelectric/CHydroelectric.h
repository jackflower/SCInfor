/*
 ___________________________________________
| CHydroelectric.h - definicja klasy.       |
| Jack Flower - July 2014.                  |
|___________________________________________|

*/

#ifndef H_HYDRO_ELECTRIC_JACK
#define H_HYDRO_ELECTRIC_JACK

#include "../CPowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalno�� elektrowni wodnej
		///
		class CHydroelectric : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;
			
			//Aby uzyska� obiekt CHydroelectric, nale�y wywo�a� CPhysicalManager::CreateHydroelectric();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			CHydroelectric(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CHydroelectricCopy - obiekt klasy CHydroelectric
			///
			CHydroelectric(const CHydroelectric &CHydroelectricCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			~CHydroelectric(void);

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

#endif//H_HYDRO_ELECTRIC_JACK