/*
 ____________________________________
| CGalaxy.h - definicja klasy.       |
| Jack Flower - May 2014.            |
|____________________________________|

*/

#ifndef H_GALAXY_JACK
#define H_GALAXY_JACK

#include <map>
#include <string>
#include "../../RTTI/RTTI.h"
#include "Star/CStar.h"
#include "../Interaction/CEntityTemperature.h"

using namespace universe::galaxy::star;

namespace universe
{
	namespace galaxy
	{
		///
		///Klasa reprezentuje galaktykê
		///
		class CGalaxy
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			CGalaxy(void);

			///
			///Konstruktor kopiuj¹cy
			///
			///@param &CGalaxyCopy - sta³a referencja na obiekt klasy CGalaxy
			///
			CGalaxy(const CGalaxy & CGalaxyCopy);

			///
			///Destruktor
			///
			~CGalaxy(void);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;
		
			///
			///Metoda zwraca nazwê galaktyki
			///
			const std::string getName() const;

			///
			///Metoda ustawia nazwê galaktyki
			///
			///@param &galaxy_name - nazwa galaktyki
			///
			void setName(const std::string & galaxy_name);

			///
			///Metoda zwraca typ galaktyki
			///
			const std::string getGalaxyType() const;

			///
			///Metoda ustawia typ galaktyki
			///
			///@param &galaxy_type - typ galaktyki
			///
			void setGalaxyType(const std::string & galaxy_type);

			///
			///Metoda zwraca temperaturê galaktyki
			///
			const float getGalaxyTemperature() const;

			///
			///Metoda ustawia temperaturê galaktyki
			///
			///@param galaxy_temperature - temepratura galaktyki
			///
			void setGalaxyTemperature(float galaxy_temperature);

		private:

		std::string			m_galaxy_name;			//nazwa galaktyki
		std::string			m_galaxy_type;			//typ galaktyki
		CEntityTemperature	m_galaxy_temperature;	//temperatura galaktyki
		
		
		typedef std::map<std::string, CStar*>	StarsMap;	//definicja typu - kontener (mapa) na gwiazdy
		StarsMap								m_stars;	//kontener (mapa) na gwiazdy

		};
	}//namespace galaxy
}//namespace universe
#endif//H_GALAXY_JACK