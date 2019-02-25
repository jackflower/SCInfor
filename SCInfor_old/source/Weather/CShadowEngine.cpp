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

		//Konstruktor kopiuj¹cy
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

		//Metoda zwraca k¹t padania promieni s³onecznych - pozorny obieg Ÿród³a œwiat³a wokó³ sceny
		const float CShadowEngine::getAngleSun() const
		{
			return m_angle_sun.getRotation();
		}

		//Metoda ustawia k¹t padania promieni s³onecznych - pozorny obieg Ÿród³a œwiat³a wokó³ sceny
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

		//Metoda zwraca sk³adow¹ koloru - kana³ alpha - wartoœæ bazowa
		const float CShadowEngine::getAlphaBase() const
		{
			return m_alpha_base;
		}

		//Metoda ustawia sk³adow¹ koloru - kana³ alpha - wartoœæ bazowa
		void CShadowEngine::setAlphaBase(float alpha_base)
		{
			m_alpha_base = alpha_base;
		}

		//Metoda zwraca sk³adow¹ koloru - kana³ alpha - wartoœæ dodana
		const float CShadowEngine::getAlphaExtra() const
		{
			return m_alpha_extra;
		}

		//Metoda ustawia sk³adow¹ koloru - kana³ alpha - wartoœæ dodana
		void CShadowEngine::setAlphaExtra(float alpha_extra)
		{
			m_alpha_extra = alpha_extra;
		}

		//Metoda zwraca przyrost k¹ta obiegu œwiat³a
		const float CShadowEngine::getAngleSunIncrement() const
		{
			return m_angle_sun_increment;
		}

		//Metoda ustawia przyrost k¹ta obiegu œwiat³a
		void CShadowEngine::setAngleSunIncrement(float angle_sun_increment)
		{
			m_angle_sun_increment = angle_sun_increment;
		}

		//Metoda aktualizuje obiekt
		void CShadowEngine::update(float dt)
		{
			//wyliczam wspó³czynnik energii s³onecznej (dodatni b¹dŸ ujemny: dzieñ-noc)
			m_solar_energy_factor = sin(m_angle_sun.getRotation()* (float)RADIANS_PER_DEGREE);

			//aktualizacja pozycji s³oñca
			//obliczanie przesuniêcia cienia w czasie rzeczywistym i jego nasycenia,
			//kana³ alpha koloru cienia (wszystko zale¿y od pozycji s³oñca)
			m_angle_sun.rotate(m_angle_sun_increment);

			//aktualizacja nasycenia cienia - w czasie rzeczywistym
			if(m_solar_energy_factor >= 0)//pozycja s³oñca - dzieñ
			{
				checkAlpha(m_alpha_base);
				checkAlpha(m_alpha_extra);
				//wyliczam wspó³czynnik dla kana³u alpha
				m_alpha = (m_alpha_base * m_solar_energy_factor) + m_alpha_extra;
				checkAlpha(m_alpha);
				//ustawiam kana³ alpha na obliczony wspó³czynnik
				m_color_shadow.a = (sf::Uint8)m_alpha;
			}
			else
			{
				//wartoœæ sk³adowej koloru - kana³ alpha - wartoœæ dodana - zawsze jest jakiœ cieñ...bia³e noce
				checkAlpha(m_alpha_extra);
				m_color_shadow.a = (sf::Uint8)m_alpha_extra;
			}

			//m_color_shadow.a = 255;//gdyby zasz³a potrzeba przetestowaæ cieñ...
		}


		//implementacja metod private:
		
		void CShadowEngine::checkAlpha(float & alpha)
		{
			//sprawdzamy, czy parametr jest prawid³owy lub go zerujemy
			if (alpha < 0)
			{
				alpha = 0;
				return;
			}
			//sprawdzamy, czy parametr jest prawid³owy lub ustawiamy wartoœæ maksymaln¹
			if (alpha > 255)
			{
				alpha = 255;
				return;
			}
		}
	}//namespace shadowengine
}//namespace weather