//  _________________________________________
// | ShadowEngine.cpp - class implementation |
// |  Jack Flower - April 2014               |
// |_________________________________________|
//

#include "ShadowEngine.h"
#include <math.h>
#include "../Utilities/Utilities/Utilities.h"

namespace weather
{
	namespace shadowengine
	{
		RTTI_IMPL_NOPARENT(ShadowEngine);

		//Konstruktor
		ShadowEngine::ShadowEngine(void)
		:
			m_angle_sun{},
			m_color_shadow{},
			m_alpha_base{ 0.0f },
			m_alpha_extra{ 0.0f },
			m_alpha{ 0.0f },
			m_angle_sun_increment{ 0.0f },
			m_solar_energy_factor{ 0.0f }
		{
		}

		//Konstruktor kopiujący
		ShadowEngine::ShadowEngine(const ShadowEngine & copy)
		:
			m_angle_sun{ copy.m_angle_sun },
			m_color_shadow{ copy.m_color_shadow },
			m_alpha_base{ copy.m_alpha_base },
			m_alpha_extra{ copy.m_alpha_extra },
			m_alpha{ copy.m_alpha },
			m_angle_sun_increment{ copy.m_angle_sun_increment },
			m_solar_energy_factor{ copy.m_solar_energy_factor }
		{
		}

		//Konstruktor przenoszący
		ShadowEngine::ShadowEngine(ShadowEngine && other)
		:
			m_angle_sun{ other.m_angle_sun },
			m_color_shadow{ other.m_color_shadow },
			m_alpha_base{ other.m_alpha_base },
			m_alpha_extra{ other.m_alpha_extra },
			m_alpha{ other.m_alpha },
			m_angle_sun_increment{ other.m_angle_sun_increment },
			m_solar_energy_factor{ other.m_solar_energy_factor }
		{
			//zerujemy składowe obiektu źródłowego...
			other.m_angle_sun;
			other.m_color_shadow;
			other.m_alpha_base = 0.0f;
			other.m_alpha_extra = 0.0f;
			other.m_alpha = 0.0f;
			other.m_angle_sun_increment = 0.0f;
			other.m_solar_energy_factor = 0.0f;
		}

		//Destruktor
		ShadowEngine::~ShadowEngine(void)
		{
			m_angle_sun;
			m_color_shadow;
			m_alpha_base = 0.0f;
			m_alpha_extra = 0.0f;
			m_alpha = 0.0f;
			m_angle_sun_increment = 0.0f;
			m_solar_energy_factor = 0.0f;
		}

		//Przeciążony operator przypisania kopiowania
		ShadowEngine & ShadowEngine::operator=(const ShadowEngine & copy)
		{
			if (this != &copy)
			{
				m_angle_sun = copy.m_angle_sun;
				m_color_shadow = copy.m_color_shadow;
				m_alpha_base = copy.m_alpha_base;
				m_alpha_extra = copy.m_alpha_extra;
				m_alpha = copy.m_alpha;
				m_angle_sun_increment = copy.m_angle_sun_increment;
				m_solar_energy_factor = copy.m_solar_energy_factor;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		ShadowEngine & ShadowEngine::operator=(ShadowEngine && other)
		{
			if (this != &other)
			{
				m_angle_sun = other.m_angle_sun;
				m_color_shadow = other.m_color_shadow;
				m_alpha_base = other.m_alpha_base;
				m_alpha_extra = other.m_alpha_extra;
				m_alpha = other.m_alpha;
				m_angle_sun_increment = other.m_angle_sun_increment;
				m_solar_energy_factor = other.m_solar_energy_factor;
				//zerowanie obiektu źródłowego
				other.m_angle_sun;
				other.m_color_shadow;
				other.m_alpha_base = 0.0f;
				other.m_alpha_extra = 0.0f;
				other.m_alpha = 0.0f;
				other.m_angle_sun_increment = 0.0f;
				other.m_solar_energy_factor = 0.0f;
			}
			return *this;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string ShadowEngine::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca kąt padania promieni słonecznych - pozorny obieg źródła światła wokół sceny
		const float ShadowEngine::getAngleSun() const
		{
			return m_angle_sun.getRotation();
		}

		//Metoda ustawia kąt padania promieni słonecznych - pozorny obieg źródła światła wokół sceny
		void ShadowEngine::setAngleSun(float angle_sun)
		{
			m_angle_sun.setRotation(angle_sun);
		}

		//Metoda zwraca kolor obiektu
		const sf::Color & ShadowEngine::getColor() const
		{
			return m_color_shadow;
		}

		//Metoda ustawia kolor obiektu
		void ShadowEngine::setColor(const sf::Color & color_shadow)
		{
			m_color_shadow = color_shadow;
		}

		//Metoda zwraca składową koloru - kanał alpha - wartość bazowa
		const float ShadowEngine::getAlphaBase() const
		{
			return m_alpha_base;
		}

		//Metoda ustawia składową koloru - kanał alpha - wartość bazowa
		void ShadowEngine::setAlphaBase(float alpha_base)
		{
			m_alpha_base = alpha_base;
		}

		//Metoda zwraca składową koloru - kanał alpha - wartość dodana
		const float ShadowEngine::getAlphaExtra() const
		{
			return m_alpha_extra;
		}

		//Metoda ustawia składową koloru - kanał alpha - wartość dodana
		void ShadowEngine::setAlphaExtra(float alpha_extra)
		{
			m_alpha_extra = alpha_extra;
		}

		//Metoda zwraca przyrost kąta obiegu światła
		const float ShadowEngine::getAngleSunIncrement() const
		{
			return m_angle_sun_increment;
		}

		//Metoda ustawia przyrost kąta obiegu światła
		void ShadowEngine::setAngleSunIncrement(float angle_sun_increment)
		{
			m_angle_sun_increment = angle_sun_increment;
		}

		//Metoda aktualizuje obiekt
		void ShadowEngine::update(float dt)
		{
			//wyliczam współczynnik energii słonecznej (dodatni bądź ujemny: dzień-noc)
			m_solar_energy_factor = sin(m_angle_sun.getRotation() * (float)RADIANS_PER_DEGREE);

			//aktualizacja pozycji słońca
			//obliczanie przesunięcia cienia w czasie rzeczywistym i jego nasycenie,
			//kanał alpha koloru cienia (wszystko zależy od pozycji słońca)
			m_angle_sun.rotate(m_angle_sun_increment);

			//aktualizacja nasycenia cienia - w czasie rzeczywistym
			if(m_solar_energy_factor >= 0)//pozycja słońca - dzień
			{
				checkAlpha(m_alpha_base);
				checkAlpha(m_alpha_extra);
				//wyliczam współczynnik dla kanału alpha
				m_alpha = (m_alpha_base * m_solar_energy_factor) + m_alpha_extra;
				checkAlpha(m_alpha);
				//ustawiam kanał alpha na obliczony współczynnik
				m_color_shadow.a = (sf::Uint8)m_alpha;
			}
			else
			{
				//wartość składowej koloru - kanał alpha - wartość dodana - zawsze jest jakiś cień...białe noce
				checkAlpha(m_alpha_extra);
				m_color_shadow.a = (sf::Uint8)m_alpha_extra;
			}

			//m_color_shadow.a = 255;//gdyby zaszła potrzeba przetestować cień...
		}


		//implementacja metod private:
		
		void ShadowEngine::checkAlpha(float & alpha)
		{
			//sprawdzamy, czy parametr jest prawidłowy lub go zerujemy
			if (alpha < 0)
			{
				alpha = 0;
				return;
			}
			//sprawdzamy, czy parametr jest prawidłowy lub ustawiamy wartość maksymalną
			if (alpha > 255)
			{
				alpha = 255;
				return;
			}
		}
	}//namespace shadowengine
}//namespace weather
