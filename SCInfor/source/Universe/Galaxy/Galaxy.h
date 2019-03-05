//  ___________________________________
// | Galaxy.h - classs definition      |
// | Jack Flower - May 2014            |
// |___________________________________|
//

#ifndef H_GALAXY_JACK
#define H_GALAXY_JACK

#include <map>
#include <string>
#include "../../RTTI/RTTI.h"
#include "Star/Star.h"
#include "../Interaction/CEntityTemperature.h"

using namespace universe::galaxy::star;

namespace universe
{
	namespace galaxy
	{
		///
		///Klasa reprezentuje galaktykę
		///
		class Galaxy
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			Galaxy();

			///
			///Konstruktor kopiujący
			///
			///@param copyy - stała referencja na obiekt klasy Galaxy
			///
			Galaxy(const Galaxy & copy);

			///
			///Destruktor
			///
			~Galaxy();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;
		
			///
			///Metoda zwraca nazwę galaktyki
			///
			const std::string getName() const;

			///
			///Metoda ustawia nazwę galaktyki
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
			///@param galaxy_type - typ galaktyki
			///
			void setGalaxyType(const std::string & galaxy_type);

			///
			///Metoda zwraca temperaturę galaktyki
			///
			const float getGalaxyTemperature() const;

			///
			///Metoda ustawia temperaturę galaktyki
			///
			///@param galaxy_temperature - temepratura galaktyki
			///
			void setGalaxyTemperature(float galaxy_temperature);

		private:

		std::string m_galaxy_name; //nazwa galaktyki
		std::string m_galaxy_type; //typ galaktyki
		CEntityTemperature m_galaxy_temperature; //temperatura galaktyki
		
		//definicja typu - kontener (mapa) na gwiazdy
		typedef std::map<std::string, Star*> StarsMap;
		StarsMap m_stars; //kontener (mapa) na gwiazdy

		};
	}//namespace galaxy
}//namespace universe
#endif//H_GALAXY_JACK
