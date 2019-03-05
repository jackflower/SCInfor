//  ____________________________________
// | Planet.h - class definition        |
// | Jack Flower - May 2014             |
// |____________________________________|


#ifndef H_PLANET_JACK
#define H_PLANET_JACK

#include <map>
#include <string>
#include "../../../../RTTI/RTTI.h"
#include "Satelite/Satelite.h"
#include "../../../Interaction/CGravity.h"
#include "../../../Interaction/CEntityTemperature.h"

using namespace universe::galaxy::star::planet::satelite;
using namespace interaction;

namespace universe
{
	namespace galaxy
	{
		namespace star
		{
			namespace planet
			{
			
				///
				///Klasa reprezentuje planetę
				///
				class Planet
				{
					RTTI_DECL;

				public:

					///
					///Knstruktor
					///
					Planet();

					///
					///Konstruktor kopiujący
					///
					///@param copy - stała referecja na obiekt klasy Planet
					///
					Planet(const Planet & copy);

					///
					///Destruktor
					///
					~Planet();

					///
					///Metoda zwraca typ obiektu /RTTI/
					///
					const std::string getType() const;

					///
					///Metoda zwraca temperaturę planety
					///
					const float getPlanetTemperature() const;

					///
					///Metoda ustawia temperaturę planety
					///
					///@param planet_temperature - temperatura planety
					///
					void setPlanetTemperature(float planet_temperature);

					///
					///Metoda zwraca grawitację planety
					///
					const float getPlanetGravity() const;

					///
					///Metoda ustawia grawitację planety
					///
					///@param planet_gravity - grawitację planety
					///
					void setPlanetGravity(float planet_gravity);

				private:
				
					//definicja typu - kontener (mapa) na satelity
					typedef std::map<std::string, Satelite*> SateliteMap;
					SateliteMap m_satelite; //kontener (mapa) na satelity
					CEntityTemperature m_planet_temperature; //temperatura planety
					CGravity m_planet_gravity; //grawitacja
					//masa, wielkośc, inne...
				};
			}//namespace planet
		}//namespace star
	}//namespace galaxy
}//namespace universe
#endif//H_PLANET_JACK
