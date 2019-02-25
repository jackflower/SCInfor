//  __________________________________________
// | CShadowEngine.h - class definition       |
// | Jack Flower - April 2014                 |
// |__________________________________________|
//

#ifndef H_SHADOW_ENGINE_JACK
#define H_SHADOW_ENGINE_JACK

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Color.hpp>
#include "../RTTI/RTTI.h"

namespace weather
{
	namespace shadowengine
	{
		///
		///Klasa reprezentuje mechanizm pozornego obiegu Ÿród³a œwiat³a wokó³ sceny i generowanie cienia
		///
		class CShadowEngine
		{
			RTTI_DECL;

		public:
			
			///
			///Konstruktor
			///
			CShadowEngine();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param &CShadowEngineCopy - sta³a referencja na obiekt klasy CShadowEngine
			///
			CShadowEngine(const CShadowEngine& CShadowEngineCopy);

			///
			///Destruktor
			///
			~CShadowEngine();

			///
			///Metoda zwraca k¹t padania promieni s³onecznych - pozorny obieg Ÿród³a œwiat³a wokó³ sceny
			///
			const float getAngleSun() const;

			///
			///Metoda ustawia k¹t padania promieni s³onecznych - pozorny obieg Ÿród³a œwiat³a wokó³ sceny
			///
			///@param angle_sun - k¹t padania promieni s³onecznych
			///
			void setAngleSun(float angle_sun);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color& getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param color_shadow - kolor cienia
			///
			void setColor(const sf::Color& color_shadow);

			///
			///Metoda zwraca sk³adow¹ koloru - kana³ alpha - wartoœæ bazowa
			///
			const float getAlphaBase() const;

			///
			///Metoda ustawia sk³adow¹ koloru - kana³ alpha - wartoœæ bazowa
			///
			///@param alpha_base - sk³adowa koloru - kana³ alpha - wartoœæ bazowa
			///
			void setAlphaBase(float alpha_base);

			///
			///Metoda zwraca sk³adow¹ koloru - kana³ alpha - wartoœæ dodana
			///
			const float getAlphaExtra() const;

			///
			///Metoda ustawia sk³adow¹ koloru - kana³ alpha - wartoœæ dodana
			///
			///@param alpha_extra - sk³adowa koloru - kana³ alpha - wartoœæ dodana
			///
			void setAlphaExtra(float alpha_extra);

			///
			///Metoda zwraca przyrost k¹ta obiegu œwiat³a
			///
			const float getAngleSunIncrement() const;

			///
			///Metoda ustawia przyrost k¹ta obiegu œwiat³a
			///
			///@param angle_sun_increment - przyrost k¹ta obiegu œwiat³a
			///
			void setAngleSunIncrement(float angle_sun_increment);

			///
			///Metoda aktualizuje obiekt
			///
			///@param dt - czas
			///
			void update(float dt);

			///
			///Metoda zwraca wspó³czynnik energii s³onecznej zale¿ny od wysokoœci s³oñca
			///
			inline const float & getSolarEnergyFactor() const { return m_solar_energy_factor; }

		private:
		
			sf::Transformable	m_angle_sun;			//wyliczany k¹t padania promieni s³onecznych - wirtualny obieg obiektu
			sf::Color			m_color_shadow;			//kolor cienia (mo¿e np. zale¿eæ od pory dnia)
			float				m_alpha_base;			//wartoœæ sk³adowej koloru - kana³ alpha - wartoœæ bazowa
			float				m_alpha_extra;			//wartoœæ sk³adowej koloru - kana³ alpha - wartoœæ dodana - zawsze jest jakiœ cieñ...
			float				m_alpha;				//wartoœæ sk³adowej koloru - wartoœæ wyliczana wzglêdem pozycji s³oñca
			float				m_angle_sun_increment;	//przyrost k¹ta obiegu œwiat³a
			float				m_solar_energy_factor;	//wspó³czynnik energii s³onecznej

			//metody pomocnicze
			void inline checkAlpha(float & alpha);
		};
	}//namespace shadowengine
}//namespace weather
#endif//H_SHADOW_ENGINE_JACK