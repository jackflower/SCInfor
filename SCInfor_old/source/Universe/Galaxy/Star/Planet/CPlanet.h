/*
 ____________________________________
| CPlanet.h - definicja klasy.       |
| Jack Flower - May 2014.            |
|____________________________________|

*/

#ifndef H_PLANET_JACK
#define H_PLANET_JACK

#include <map>
#include <string>
#include "../../../../RTTI/RTTI.h"
#include "Satelite/CSatelite.h"
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
				///Klasa reprezentuje planet�
				///
				class CPlanet
				{
					RTTI_DECL;

				public:

					///
					///Knstruktor
					///
					CPlanet(void);

					///
					///Konstruktor kopiuj�cy
					///
					///@param CPlanetCopy - sta�a referecja na obiekt klasy CPlanet
					///
					CPlanet(const CPlanet & CPlanetCopy);

					///
					///Destruktor
					///
					~CPlanet(void);

					///
					///Metoda zwraca typ obiektu /RTTI/
					///
					const std::string GetType() const;

					///
					///Metoda zwraca temperatur� planety
					///
					const float getPlanetTemperature() const;

					///
					///Metoda ustawia temperatur� planety
					///
					///@param planet_temperature - temperatura planety
					///
					void setPlanetTemperature(float planet_temperature);

					///
					///Metoda zwraca grawitacj� planety
					///
					const float getPlanetGravity() const;

					///
					///Metoda ustawia grawitacj� planety
					///
					///@param planet_gravity - grawitacj� planety
					///
					void setPlanetGravity(float planet_gravity);

				private:
				
					typedef std::map<std::string, CSatelite*>	SateliteMap;	//definicja typu - kontener (mapa) na satelity
					SateliteMap									m_satelite;		//kontener (mapa) na satelity
					
					CEntityTemperature							m_planet_temperature;	//temperatura planety
					CGravity									m_planet_gravity;		//grawitacja
					//masa
					//wielko��
					//inne ...

				};
			}//namespace planet
		}//namespace star
	}//namespace galaxy
}//namespace universe
#endif//H_PLANET_JACK