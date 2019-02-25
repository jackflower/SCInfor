/*
 __________________________________
| CStar.cpp - implementacja klasy. |
| Jack Flower - May 2014.          |
|__________________________________|

*/

#include "CStar.h"

namespace universe
{
	namespace galaxy
	{
		namespace star
		{

			RTTI_IMPL_NOPARENT(CStar);

			//Knstruktor
			CStar::CStar(void)
			:
				m_planet				(),
				m_star_temperature		()
			{
			}

			//Konstruktor kopiuj¹cy
			CStar::CStar(const CStar & CStarCopy)
			:
				m_planet				(CStarCopy.m_planet),
				m_star_temperature		(CStarCopy.m_star_temperature)
			{
			}

			//Destruktor
			CStar::~CStar(void)
			{
				//m_planet				not edit
				//m_star_temperature	not edit
			}

			//Metoda zwraca typ obiektu /RTTI/
			const std::string CStar::GetType() const
			{
				return rtti.GetNameClass();
			}

			//Metoda zwraca temperaturê gwiazdy
			const float CStar::getStarTemperature() const
			{
				return m_star_temperature.getEntityTemperature();
			}

			//Metoda ustawia temperaturê gwiazdy
			void CStar::setStarTemperature(float star_temperature)
			{
				m_star_temperature.setEntityTemperature(star_temperature);
			}

		}//namespace star
	}//namespace gakaxy
}//namespace universe