/*
 __________________________________
| CStar.h - definicja klasy.       |
| Jack Flower - May 2014.          |
|__________________________________|

*/

#ifndef H_STAR_JACK
#define H_STAR_JACK

#include <map>
#include <string>
#include "../../../RTTI/RTTI.h"
#include "Planet/CPlanet.h"
#include "../../Interaction/CEntityTemperature.h"

using namespace universe::galaxy::star::planet;

namespace universe
{
	namespace galaxy
	{
		namespace star
		{

			///
			///Klasa reprezentuje gwiazdê
			///
			class CStar
			{
				RTTI_DECL;

			public:

				///
				///Knstruktor
				///
				CStar(void);

				///
				///Konstruktor kopiuj¹cy
				///
				///@param CStarCopy - sta³a referecja na obiekt klasy CStar
				///
				CStar(const CStar & CStarCopy);

				///
				///Destruktor
				///
				~CStar(void);

				///
				///Metoda zwraca typ obiektu /RTTI/
				///
				const std::string GetType() const;

				///
				///Metoda zwraca temperaturê gwiazdy
				///
				const float getStarTemperature() const;

				///
				///Metoda ustawia temperaturê gwiazdy
				///
				///@param star_temperature - temepratura gwiazdy
				///
				void setStarTemperature(float star_temperature);

			private:
				
				typedef std::map<std::string, CPlanet*>	PlanetMap;			//definicja typu - kontener (mapa) na planety
				PlanetMap								m_planet;			//kontener (mapa) na planety
				CEntityTemperature						m_star_temperature;	//temperatura gwiazdy

			};
		}//namespace star
	}//namespace galaxy
}//namespace universe
#endif//H_STAR_JACK