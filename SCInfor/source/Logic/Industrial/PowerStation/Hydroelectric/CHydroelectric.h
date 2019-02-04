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
		///Klasa reprezentuje funkcjonalnoœæ elektrowni wodnej
		///
		class CHydroelectric : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskaæ obiekt CHydroelectric, nale¿y wywo³aæ CPhysicalManager::CreateHydroelectric();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			CHydroelectric(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CHydroelectricCopy - obiekt klasy CHydroelectric
			///
			CHydroelectric(const CHydroelectric &CHydroelectricCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
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