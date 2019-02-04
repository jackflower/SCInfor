//  __________________________________________
// | CShadowEngine.cpp - class implementation |
// |  Jack Flower - April 2014                |
// |__________________________________________|
//

#include "CShadowEngine.h"
#include <math.h>
#include "../Utilities/Utilities/Utilities.h"

namespace weather
{
	namespace shadowengine
	{
		RTTI_IMPL_NOPARENT(CShadowEngine);

		//Konstruktor
		CShadowEngine::CShadowEngine(void)
		:
			m_angle_sun				(),
			m_color_shadow			(),
			m_alpha_base			(0.0f),
			m_alpha_extra			(0.0f),
			m_alpha					(0.0f),
			m_angle_sun_increment	(0.0f),
			m_solar_energy_factor	(0.0f)
		{
		}

		//Konstruktor kopiuj�cy
		CShadowEngine::CShadowEngine(const CShadowEngine& CShadowEngineCopy)
		:
			m_angle_sun				(CShadowEngineCopy.m_angle_sun),
			m_color_shadow			(CShadowEngineCopy.m_color_shadow),
			m_alpha_base			(CShadowEngineCopy.m_alpha_base),
			m_alpha_extra			(CShadowEngineCopy.m_alpha_extra),
			m_alpha					(CShadowEngineCopy.m_alpha),
			m_angle_sun_increment	(CShadowEngineCopy.m_angle_sun_increment),
			m_solar_energy_factor	(CShadowEngineCopy.m_solar_energy_factor)
		{
		}

		//Destruktor
		CShadowEngine::~CShadowEngine(void)
		{
			//m_angle_sun			not edit
			//m_color_shadow		not edit
			m_alpha_base			= 0.0f;
			m_alpha_extra			= 0.0f;
			m_alpha					= 0.0f;
			m_angle_sun_increment	= 0.0f;
			m_solar_energy_factor	= 0.0f;
		}

		//Metoda zwraca k�t padania promieni s�onecznych - pozorny obieg �r�d�a �wiat�a wok� sceny
		const float CShadowEngine::getAngleSun() const
		{
			return m_angle_sun.getRotation();
		}

		//Metoda ustawia k�t padania promieni s�onecznych - pozorny obieg �r�d�a �wiat�a wok� sceny
		void CShadowEngine::setAngleSun(float angle_sun)
		{
			m_angle_sun.setRotation(angle_sun);
		}

		//Metoda zwraca kolor obiektu
		const sf::Color& CShadowEngine::getColor() const
		{
			return m_color_shadow;
		}

		//Metoda ustawia kolor obiektu
		void CShadowEngine::setColor(const sf::Color& color_shadow)
		{
			m_color_shadow = color_shadow;
		}

		//Metoda zwraca sk�adow� koloru - kana� alpha - warto�� bazowa
		const float CShadowEngine::getAlphaBase() const
		{
			return m_alpha_base;
		}

		//Metoda ustawia sk�adow� koloru - kana� alpha - warto�� bazowa
		void CShadowEngine::setAlphaBase(float alpha_base)
		{
			m_alpha_base = alpha_base;
		}

		//Metoda zwraca sk�adow� koloru - kana� alpha - warto�� dodana
		const float CShadowEngine::getAlphaExtra() const
		{
			return m_alpha_extra;
		}

		//Metoda ustawia sk�adow� koloru - kana� alpha - warto�� dodana
		void CShadowEngine::setAlphaExtra(float alpha_extra)
		{
			m_alpha_extra = alpha_extra;
		}

		//Metoda zwraca przyrost k�ta obiegu �wiat�a
		const float CShadowEngine::getAngleSunIncrement() const
		{
			return m_angle_sun_increment;
		}

		//Metoda ustawia przyrost k�ta obiegu �wiat�a
		void CShadowEngine::setAngleSunIncrement(float angle_sun_increment)
		{
			m_angle_sun_increment = angle_sun_increment;
		}

		//Metoda aktualizuje obiekt
		void CShadowEngine::update(float dt)
		{
			//wyliczam wsp�czynnik energii s�onecznej (dodatni b�d� ujemny: dzie�-noc)
			m_solar_energy_factor = sin(m_angle_sun.getRotation()* (float)RADIANS_PER_DEGREE);

			//aktualizacja pozycji s�o�ca
			//obliczanie przesuni�cia cienia w czasie rzeczywistym i jego nasycenia,
			//kana� alpha koloru cienia (wszystko zale�y od pozycji s�o�ca)
			m_angle_sun.rotate(m_angle_sun_increment);

			//aktualizacja nasycenia cienia - w czasie rzeczywistym
			if(m_solar_energy_factor >= 0)//pozycja s�o�ca - dzie�
			{
				checkAlpha(m_alpha_base);
				checkAlpha(m_alpha_extra);
				//wyliczam wsp�czynnik dla kana�u alpha
				m_alpha = (m_alpha_base * m_solar_energy_factor) + m_alpha_extra;
				checkAlpha(m_alpha);
				//ustawiam kana� alpha na obliczony wsp�czynnik
				m_color_shadow.a = (sf::Uint8)m_alpha;
			}
			else
			{
				//warto�� sk�adowej koloru - kana� alpha - warto�� dodana - zawsze jest jaki� cie�...bia�e noce
				checkAlpha(m_alpha_extra);
				m_color_shadow.a = (sf::Uint8)m_alpha_extra;
			}

			//m_color_shadow.a = 255;//gdyby zasz�a potrzeba przetestowa� cie�...
		}


		//implementacja metod private:
		
		void CShadowEngine::checkAlpha(float & alpha)
		{
			//sprawdzamy, czy parametr jest prawid�owy lub go zerujemy
			if (alpha < 0)
			{
				alpha = 0;
				return;
			}
			//sprawdzamy, czy parametr jest prawid�owy lub ustawiamy warto�� maksymaln�
			if (alpha > 255)
			{
				alpha = 255;
				return;
			}
		}
	}//namespace shadowengine
}//namespace weather