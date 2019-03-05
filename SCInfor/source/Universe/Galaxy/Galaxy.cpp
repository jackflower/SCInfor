//  ___________________________________
// | Galaxy.cpp - class implementation |
// | Jack Flower - May 2014            |
// |___________________________________|
//

#include "Galaxy.h"

namespace universe
{
	namespace galaxy
	{
		RTTI_IMPL_NOPARENT(Galaxy);

		//Konstruktor
		Galaxy::Galaxy()
		:
			m_galaxy_name{},
			m_galaxy_type{},
			m_galaxy_temperature{}
		{
		}

		//Konstruktor kopiujący
		Galaxy::Galaxy(const Galaxy & copy)
		:
			m_galaxy_name{ copy.m_galaxy_name },
			m_galaxy_type{ copy.m_galaxy_type },
			m_galaxy_temperature{ copy.m_galaxy_temperature }
		{
		}

		//Destruktor
		Galaxy::~Galaxy(void)
		{
			m_galaxy_name = "";
			m_galaxy_type = "";
			m_galaxy_temperature;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Galaxy::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca nazwę galaktyki
		const std::string Galaxy::getName() const
		{
			return m_galaxy_name;
		}

		//Metoda ustawia nazwę galaktyki
		void Galaxy::setName(const std::string & galaxy_name)
		{
			m_galaxy_name = galaxy_name;
		}

		//Metoda zwraca typ galaktyki
		const std::string Galaxy::getGalaxyType() const
		{
			return m_galaxy_type;
		}

		//Metoda ustawia typ galaktyki
		void Galaxy::setGalaxyType(const std::string & galaxy_type)
		{
			m_galaxy_type = galaxy_type;
		}

		//Metoda zwraca temperaturę galaktyki
		const float Galaxy::getGalaxyTemperature() const
		{
			return m_galaxy_temperature.getEntityTemperature();
		}

		//Metoda ustawia temperaturę galaktyki
		void Galaxy::setGalaxyTemperature(float galaxy_temperature)
		{
			m_galaxy_temperature.setEntityTemperature(galaxy_temperature);
		}

	}//namespace galaxy
}//namespace universe
