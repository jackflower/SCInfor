//  _________________________________
// | Star.cpp - class implementation |
// | Jack Flower - May 2014          |
// |_________________________________|
//

#include "Star.h"

namespace universe
{
	namespace galaxy
	{
		namespace star
		{

			RTTI_IMPL_NOPARENT(Star);

			//Knstruktor
			Star::Star(void)
			:
				m_planet{},
				m_star_temperature{}
			{
			}

			//Konstruktor kopiujący
			Star::Star(const Star & copy)
			:
				m_planet{ copy.m_planet },
				m_star_temperature{ copy.m_star_temperature }
			{
			}

			//Destruktor
			Star::~Star()
			{
				m_planet;
				m_star_temperature;
			}

			//Metoda zwraca typ obiektu /RTTI/
			const std::string Star::getType() const
			{
				return rtti.getNameClass();
			}

			//Metoda zwraca temperaturę gwiazdy
			const float Star::getStarTemperature() const
			{
				return m_star_temperature.getEntityTemperature();
			}

			//Metoda ustawia temperaturę gwiazdy
			void Star::setStarTemperature(float star_temperature)
			{
				m_star_temperature.setEntityTemperature(star_temperature);
			}

		}//namespace star
	}//namespace gakaxy
}//namespace universe
