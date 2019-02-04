/*
 ____________________________________
| CGalaxy.cpp - implementacja klasy. |
| Jack Flower - May 2014.            |
|____________________________________|

*/

#include "CGalaxy.h"

namespace universe
{
	namespace galaxy
	{
		RTTI_IMPL_NOPARENT(CGalaxy);

		//Konstruktor
		CGalaxy::CGalaxy(void)
		:
			m_galaxy_name			(),
			m_galaxy_type			(),
			m_galaxy_temperature	()
		{
		}

		//Konstruktor kopiuj¹cy
		CGalaxy::CGalaxy(const CGalaxy & CGalaxyCopy)
		:
			m_galaxy_name			(CGalaxyCopy.m_galaxy_name),
			m_galaxy_type			(CGalaxyCopy.m_galaxy_type),
			m_galaxy_temperature	(CGalaxyCopy.m_galaxy_temperature)
		{
		}

		//Destruktor
		CGalaxy::~CGalaxy(void)
		{
			m_galaxy_name			= "";
			m_galaxy_type			= "";
			//m_galaxy_temperature	not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CGalaxy::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca nazwê galaktyki
		const std::string CGalaxy::getName() const
		{
			return m_galaxy_name;
		}

		//Metoda ustawia nazwê galaktyki
		void CGalaxy::setName(const std::string & galaxy_name)
		{
			m_galaxy_name = galaxy_name;
		}

		//Metoda zwraca typ galaktyki
		const std::string CGalaxy::getGalaxyType() const
		{
			return m_galaxy_type;
		}

		//Metoda ustawia typ galaktyki
		void CGalaxy::setGalaxyType(const std::string & galaxy_type)
		{
			m_galaxy_type = galaxy_type;
		}

		//Metoda zwraca temperaturê galaktyki
		const float CGalaxy::getGalaxyTemperature() const
		{
			return m_galaxy_temperature.getEntityTemperature();
		}

		//Metoda ustawia temperaturê galaktyki
		void CGalaxy::setGalaxyTemperature(float galaxy_temperature)
		{
			m_galaxy_temperature.setEntityTemperature(galaxy_temperature);
		}



	}//namespace galaxy
}//namespace universe