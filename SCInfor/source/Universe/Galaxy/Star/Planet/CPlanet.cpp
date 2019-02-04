/*
 ____________________________________
| CPlanet.cpp - implementacja klasy. |
| Jack Flower - May 2014.            |
|____________________________________|

*/

#include "CPlanet.h"

namespace universe
{
	namespace galaxy
	{
		namespace star
		{
			namespace planet
			{
				RTTI_IMPL_NOPARENT(CPlanet);

				//Knstruktor
				CPlanet::CPlanet(void)
				:
					m_satelite				(),
					m_planet_temperature	(),
					m_planet_gravity				()
				{
				}
	
				//Konstruktor kopiuj¹cy
				CPlanet::CPlanet(const CPlanet & CPlanetCopy)
				:
					m_satelite				(CPlanetCopy.m_satelite),
					m_planet_gravity				(CPlanetCopy.m_planet_gravity),
					m_planet_temperature	(CPlanetCopy.m_planet_temperature)
				{
				}

				//Destruktor
				CPlanet::~CPlanet(void)
				{
					//m_satelite			not edit
					//m_planet_gravity				not edit
					//m_planet_temperature	not edit
				}

				//Metoda zwraca typ obiektu /RTTI/
				const std::string CPlanet::GetType() const
				{
					return rtti.GetNameClass();
				}

				//Metoda zwraca temperaturê planety
				const float CPlanet::getPlanetTemperature() const
				{
					return m_planet_temperature.getEntityTemperature();
				}

				//Metoda ustawia temperaturê planety
				void CPlanet::setPlanetTemperature(float planet_temperature)
				{
					m_planet_temperature.setEntityTemperature(planet_temperature);
				}

				//Metoda zwraca grawitacjê planety
				const float CPlanet::getPlanetGravity() const
				{
					return m_planet_gravity.getGravityForce();
				}

				//Metoda ustawia grawitacjê planety
				void CPlanet::setPlanetGravity(float planet_gravity)
				{
					m_planet_gravity.setGravityForce(planet_gravity);
				}

			}//namespace planet
		}//namespace star
	}//namespace gakaxy
}//namespace universe