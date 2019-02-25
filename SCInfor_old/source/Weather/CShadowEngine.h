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
		///Klasa reprezentuje mechanizm pozornego obiegu �r�d�a �wiat�a wok� sceny i generowanie cienia
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
			///Konstruktor kopiuj�cy
			///
			///@param &CShadowEngineCopy - sta�a referencja na obiekt klasy CShadowEngine
			///
			CShadowEngine(const CShadowEngine& CShadowEngineCopy);

			///
			///Destruktor
			///
			~CShadowEngine();

			///
			///Metoda zwraca k�t padania promieni s�onecznych - pozorny obieg �r�d�a �wiat�a wok� sceny
			///
			const float getAngleSun() const;

			///
			///Metoda ustawia k�t padania promieni s�onecznych - pozorny obieg �r�d�a �wiat�a wok� sceny
			///
			///@param angle_sun - k�t padania promieni s�onecznych
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
			///Metoda zwraca sk�adow� koloru - kana� alpha - warto�� bazowa
			///
			const float getAlphaBase() const;

			///
			///Metoda ustawia sk�adow� koloru - kana� alpha - warto�� bazowa
			///
			///@param alpha_base - sk�adowa koloru - kana� alpha - warto�� bazowa
			///
			void setAlphaBase(float alpha_base);

			///
			///Metoda zwraca sk�adow� koloru - kana� alpha - warto�� dodana
			///
			const float getAlphaExtra() const;

			///
			///Metoda ustawia sk�adow� koloru - kana� alpha - warto�� dodana
			///
			///@param alpha_extra - sk�adowa koloru - kana� alpha - warto�� dodana
			///
			void setAlphaExtra(float alpha_extra);

			///
			///Metoda zwraca przyrost k�ta obiegu �wiat�a
			///
			const float getAngleSunIncrement() const;

			///
			///Metoda ustawia przyrost k�ta obiegu �wiat�a
			///
			///@param angle_sun_increment - przyrost k�ta obiegu �wiat�a
			///
			void setAngleSunIncrement(float angle_sun_increment);

			///
			///Metoda aktualizuje obiekt
			///
			///@param dt - czas
			///
			void update(float dt);

			///
			///Metoda zwraca wsp�czynnik energii s�onecznej zale�ny od wysoko�ci s�o�ca
			///
			inline const float & getSolarEnergyFactor() const { return m_solar_energy_factor; }

		private:
		
			sf::Transformable	m_angle_sun;			//wyliczany k�t padania promieni s�onecznych - wirtualny obieg obiektu
			sf::Color			m_color_shadow;			//kolor cienia (mo�e np. zale�e� od pory dnia)
			float				m_alpha_base;			//warto�� sk�adowej koloru - kana� alpha - warto�� bazowa
			float				m_alpha_extra;			//warto�� sk�adowej koloru - kana� alpha - warto�� dodana - zawsze jest jaki� cie�...
			float				m_alpha;				//warto�� sk�adowej koloru - warto�� wyliczana wzgl�dem pozycji s�o�ca
			float				m_angle_sun_increment;	//przyrost k�ta obiegu �wiat�a
			float				m_solar_energy_factor;	//wsp�czynnik energii s�onecznej

			//metody pomocnicze
			void inline checkAlpha(float & alpha);
		};
	}//namespace shadowengine
}//namespace weather
#endif//H_SHADOW_ENGINE_JACK