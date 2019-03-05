//  ____________________________________
// |  Planet.cpp - class implementation |
// | Jack Flower - May 2014             |
// |____________________________________|
//

#include "Planet.h"

namespace universe
{
	namespace galaxy
	{
		namespace star
		{
			namespace planet
			{
				RTTI_IMPL_NOPARENT(Planet);

				//Knstruktor
				Planet::Planet()
				:
					m_satelite{},
					m_planet_temperature{},
					m_planet_gravity{}
				{
				}
	
				//Konstruktor kopiujący
				Planet::Planet(const Planet & copy)
				:
					m_satelite{ copy.m_satelite },
					m_planet_gravity{ copy.m_planet_gravity },
					m_planet_temperature{ copy.m_planet_temperature }
				{
				}

				//Destruktor
				Planet::~Planet()
				{
					m_satelite;
					m_planet_gravity;
					m_planet_temperature;
				}

				//Metoda zwraca typ obiektu /RTTI/
				const std::string Planet::getType() const
				{
					return rtti.getNameClass();
				}

				//Metoda zwraca temperaturę planety
				const float Planet::getPlanetTemperature() const
				{
					return m_planet_temperature.getEntityTemperature();
				}

				//Metoda ustawia temperaturę planety
				void Planet::setPlanetTemperature(float planet_temperature)
				{
					m_planet_temperature.setEntityTemperature(planet_temperature);
				}

				//Metoda zwraca grawitację planety
				const float Planet::getPlanetGravity() const
				{
					return m_planet_gravity.getGravityForce();
				}

				//Metoda ustawia grawitację planety
				void Planet::setPlanetGravity(float planet_gravity)
				{
					m_planet_gravity.setGravityForce(planet_gravity);
				}

			}//namespace planet
		}//namespace star
	}//namespace gakaxy
}//namespace universe
