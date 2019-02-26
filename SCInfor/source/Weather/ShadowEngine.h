//  _________________________________________
// | ShadowEngine.h - class definition       |
// | Jack Flower - April 2014                |
// |_________________________________________|
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
		///Klasa reprezentuje mechanizm pozornego obiegu źródła światła wokół sceny i generowanie cienia
		///
		class ShadowEngine
		{
			RTTI_DECL;

		public:
			
			///
			///Konstruktor
			///
			ShadowEngine();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy ShadowEngine
			///
			ShadowEngine(const ShadowEngine & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other - referencja do r-wartości
			///
			ShadowEngine(ShadowEngine && other);

			///
			///Destruktor
			///
			~ShadowEngine();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy ShadowEngine
			///
			ShadowEngine & operator=(const ShadowEngine & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			ShadowEngine & operator=(ShadowEngine && other);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca kąt padania promieni słonecznych - pozorny obieg źródła światła wokół sceny
			///
			const float getAngleSun() const;

			///
			///Metoda ustawia kąt padania promieni słonecznych - pozorny obieg źródła światła wokół sceny
			///
			///@param angle_sun - kąt padania promieni słonecznych
			///
			void setAngleSun(float angle_sun);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color & getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param color_shadow - kolor cienia
			///
			void setColor(const sf::Color & color_shadow);

			///
			///Metoda zwraca składową koloru - kanał alpha - wartość bazowa
			///
			const float getAlphaBase() const;

			///
			///Metoda ustawia składową koloru - kanał alpha - wartość bazowa
			///
			///@param alpha_base - składowa koloru - kanał alpha - wartość bazowa
			///
			void setAlphaBase(float alpha_base);

			///
			///Metoda zwraca składową koloru - kanał alpha - wartość dodana
			///
			const float getAlphaExtra() const;

			///
			///Metoda ustawia składową koloru - kanał alpha - wartość dodana
			///
			///@param alpha_extra - składowa koloru - kanał alpha - wartość dodana
			///
			void setAlphaExtra(float alpha_extra);

			///
			///Metoda zwraca przyrost kąta obiegu światła
			///
			const float getAngleSunIncrement() const;

			///
			///Metoda ustawia przyrost kąta obiegu światła
			///
			///@param angle_sun_increment - przyrost kąta obiegu światła
			///
			void setAngleSunIncrement(float angle_sun_increment);

			///
			///Metoda aktualizuje obiekt
			///
			///@param dt - czas
			///
			void update(float dt);

			///
			///Metoda zwraca współczynnik energii słonecznej zależny od wysokości słońca
			///
			inline const float & getSolarEnergyFactor() const { return m_solar_energy_factor; }

		private:
		
			sf::Transformable m_angle_sun; //wyliczany kąt padania promieni słonecznych - wirtualny obieg obiektu
			sf::Color m_color_shadow; //kolor cienia (może np. zależeć od pory dnia)
			float m_alpha_base; //wartość składowej koloru - kanał alpha - wartość bazowa
			float m_alpha_extra; //wartość składowej koloru - kanał alpha - wartość dodana - zawsze jest jakiś cień...
			float m_alpha; //wartość składowej koloru - wartość wyliczana względem pozycji słońca
			float m_angle_sun_increment; //przyrost kąta obiegu światła
			float m_solar_energy_factor; //współczynnik energii słonecznej

			//metody pomocnicze
			void inline checkAlpha(float & alpha);
		};
	}//namespace shadowengine
}//namespace weather
#endif//H_SHADOW_ENGINE_JACK
