//  _________________________________
// | Star.h - class definition       |
// | Jack Flower - May 2014          |
// |_________________________________|
//

#ifndef H_STAR_JACK
#define H_STAR_JACK

#include <map>
#include <string>
#include "../../../RTTI/RTTI.h"
#include "Planet/Planet.h"
#include "../../Interaction/EntityTemperature.h"

using namespace universe::galaxy::star::planet;

namespace universe
{
	namespace galaxy
	{
		namespace star
		{

			///
			///Klasa reprezentuje gwiazdę
			///
			class Star
			{
				RTTI_DECL;

			public:

				///
				///Knstruktor
				///
				Star();

				///
				///Konstruktor kopiujący
				///
				///@param copy - stała referecja na obiekt klasy Star
				///
				Star(const Star & copy);

				///
				///Destruktor
				///
				~Star();

				///
				///Metoda zwraca typ obiektu /RTTI/
				///
				const std::string getType() const;

				///
				///Metoda zwraca temperaturę gwiazdy
				///
				const float getStarTemperature() const;

				///
				///Metoda ustawia temperaturę gwiazdy
				///
				///@param star_temperature - temepratura gwiazdy
				///
				void setStarTemperature(float star_temperature);

			private:
				
				//definicja typu - kontener (mapa) na planety
				typedef std::map<std::string, Planet*> PlanetMap;
				PlanetMap m_planet; //kontener (mapa) na planety
				EntityTemperature m_star_temperature; //temperatura gwiazdy

			};
		}//namespace star
	}//namespace galaxy
}//namespace universe
#endif//H_STAR_JACK
