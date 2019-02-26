//  _____________________________________
// | Satelite.cpp - class implementation |
// | Jack Flower - May 2014              |
// |_____________________________________|
//

#include "Satelite.h"

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
					RTTI_IMPL_NOPARENT(Satelite);

					//Knstruktor
					Satelite::Satelite(void)
					:
						m_satelite_temperature{}
					{
					}

					//Konstruktor kopiuj¹cy
					Satelite::Satelite(const Satelite & copy)
					:
						m_satelite_temperature{ copy.m_satelite_temperature }
					{
					}

					//Konstruktor przenosz¹cy
					Satelite::Satelite(Satelite && other)
						:
						m_satelite_temperature{ other.m_satelite_temperature }, //konstruktor przenosz¹cy klasy bazowej
						m_satelite_gravity{ other.m_satelite_gravity }
					{
						//zerujemy sk³adowe obiektu Ÿród³owego...
						other.m_satelite_temperature;
						other.m_satelite_gravity;
					}

					//Destruktor
					Satelite::~Satelite()
					{
						m_satelite_temperature;
						m_satelite_gravity;
					}

					//Przeci¹¿ony operator przypisania kopiowania
					Satelite & Satelite::operator=(const Satelite & copy)
					{
						if (this != &copy)
						{
							m_satelite_temperature = copy.m_satelite_temperature;
							m_satelite_gravity = copy.m_satelite_gravity;
						}
						return *this;
					}

					//Przeci¹¿ony operator przypisania przenoszenia
					Satelite & Satelite::operator=(Satelite && other)
					{
						if (this != &other)
						{
							m_satelite_temperature = other.m_satelite_temperature;
							m_satelite_gravity = other.m_satelite_gravity;

							//zerowanie obiektu Ÿród³owego
							other.m_satelite_temperature;
							other.m_satelite_gravity;
						}
						return *this;
					}

					//Metoda zwraca typ obiektu /RTTI/
					const std::string Satelite::getType() const
					{
						return rtti.getNameClass();
					}

					///Metoda zwraca temperaturê satelity
					const float Satelite::getSateliteTemperature() const
					{
						return m_satelite_temperature.getEntityTemperature();
					}

					//Metoda ustawia temperaturê satelity
					void Satelite::setSateliteTemperature(float satelite_temperature)
					{
						m_satelite_temperature.setEntityTemperature(satelite_temperature);
					}

					//Metoda zwraca grawitacjê satelity
					const float Satelite::getSateliteGravity() const
					{
						return m_satelite_gravity.getGravityForce();
					}

					//Metoda ustawia grawitacjê satelity
					void Satelite::setSateliteGravity(float satelite_gravity)
					{
						m_satelite_gravity.setGravityForce(satelite_gravity);
					}

				}//namespace satelite
			}//namespace planet
		}//namespace star
	}//namespace gakaxy
}//namespace universe
