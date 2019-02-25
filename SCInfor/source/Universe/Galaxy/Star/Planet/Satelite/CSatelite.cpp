/*
 ______________________________________
| CSatelite.cpp - implementacja klasy. |
| Jack Flower - May 2014.              |
|______________________________________|

*/

#include "CSatelite.h"

namespace universe
{
	namespace galaxy
	{
		namespace star
		{
			namespace planet
			{
				namespace satelite
				{
					RTTI_IMPL_NOPARENT(CSatelite);

					//Knstruktor
					CSatelite::CSatelite(void)
					:
						m_satelite_temperature	()
					{
					}

					//Konstruktor kopiujący
					CSatelite::CSatelite(const CSatelite & CSateliteCopy)
					:
						m_satelite_temperature	(CSateliteCopy.m_satelite_temperature)
					{
					}

					//Destruktor
					CSatelite::~CSatelite(void)
					{
						//m_satelite_temperature not edit
					}

					//Metoda zwraca typ obiektu /RTTI/
					const std::string CSatelite::GetType() const
					{
						return rtti.getNameClass();
					}

					///Metoda zwraca temperaturę satelity
					const float CSatelite::getSateliteTemperature() const
					{
						return m_satelite_temperature.getEntityTemperature();
					}

					//Metoda ustawia temperaturę satelity
					void CSatelite::setSateliteTemperature(float satelite_temperature)
					{
						m_satelite_temperature.setEntityTemperature(satelite_temperature);
					}

					//Metoda zwraca grawitację satelity
					const float CSatelite::getSateliteGravity() const
					{
						return m_satelite_gravity.getGravityForce();
					}

					//Metoda ustawia grawitację satelity
					void CSatelite::setSateliteGravity(float satelite_gravity)
					{
						m_satelite_gravity.setGravityForce(satelite_gravity);
					}

				}//namespace satelite
			}//namespace planet
		}//namespace star
	}//namespace gakaxy
}//namespace universe