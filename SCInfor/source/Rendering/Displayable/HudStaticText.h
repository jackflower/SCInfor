//  __________________________________________
// | HudStaticText.h - class definition       |
// | Jack Flower October 2012                 |
// |__________________________________________|
//


#ifndef H_HUD_STATIC_TEXT_JACK
#define H_HUD_STATIC_TEXT_JACK

#include "../../RTTI/RTTI.h"
#include "../../ResourceManager/CResourceManager.h"
#include "../../ResourceManager/CFont.h"
#include "../Drawable/Drawable.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>

///
///Forward declaration
///
namespace sf
{
    class Text;
    class RenderWindow;
}

using namespace rendering::drawable;
using namespace resource;

namespace rendering
{
	namespace displayable
	{

		///
		///Klasa reprezentujaca tekst rysowany na HUD - przyklejony do kamery (ang. Head-Up Display)
		///
		class HudStaticText : public rendering::drawable::Drawable
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			HudStaticText();

			///
			///Destruktor wirtualny
			///
			virtual ~HudStaticText();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca wskaźnik na obiekt klasy sf::Text
			///
			const sf::Text *getText() const;

			///
			///Metoda zwraca kolor
			///
			const sf::Color & getColor() const;

			///
			///Metoda ustawia kolor
			///
			///@param color - kolor - referencja na obiekt klasy sf::Color
			///
			void setColor(const sf::Color & color);

			///
			///Metoda ustawia kolor
			///
			/// @param red   komponent Red (zakres [0, 255])
			///
			/// @param green komponent Green (zakres [0, 255])
			//
			/// @param blue  komponent Blue (zakres [0, 255])
			///
			/// @param alpha komponent Alpha (zakres [0, 255]) - opcjonalenie
			///
			void setColor(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha = 255);

			///
			///Metoda ustawia czcionkę graficzną tekstu dla obiektu klasy sf::String
			///
			///@param font - stała referencja na obiekt klasy std::string
			///
			void setFont(const std::string & font);

			///
			///Metoda ustawia czcionkę graficzną tekstu dla obiektu klasy sf::String
			///
			///@param font - stała referencja na obiekt klasy std::string
			///
			///@param size - romiar czcionki
			///
			void setFont(const std::string & font, unsigned size);
			
			///
			///Metoda ustawia rozmiar czcionki graficznej tekstu
			///
			///@param size - rozmiar czcionki graficznej
			///
			void setFontSize(unsigned size);

			///
			///Metoda ustawia łańcuch znaków
			///
			///@param string - stała referencja na obiekt klasy std::string
			///
			void setString(const sf::String & string);

			///
			///Metoda zwraca pozycję obiektu
			///
			const sf::Vector2f & getPosition() const;
		
			///
			///Metoda ustawia pozycję obiektu
			///
			///@param positon - stała referecnaj na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & position);

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param x - współrzędna X
			///
			///@param y - współrzędna Y
			///
			void setPosition(float x, float y);

			///
			///Metoda zwraca obrót obiektu
			///
			float getRotation() const;

			///
			///Metoda ustawia obrót obiektu
			///
			///@param angle - kąt obrotu
			///
			void setRotation(float angle);

			///
			///Metoda obraca obiekt zadany kąt
			///
			///@param angle - kąt obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca wektor skali obiektu
			///
			const sf::Vector2f & getScale() const;

			///
			///Metoda ustawia skalę obiektu
			///
			///@param factors - wektor współczynika skali - stała referncja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f & factors);

			///
			///Metoda ustawia skalę obiektu
			///
			///@param factorXt - współczynnik X
			///
			///@param factorY - współczynnik Y
			///
			void setScale(float factorX, float factorY);
		
			///
			///Metoda skaluje obiekt
			///
			///@param factor - współczynnik skali
			///
			void scale(const sf::Vector2f & factor);

			///
			///Metoda skaluje obiekt
			///
			///@param factorX - współczynnik X
			///
			///@param factorY - współczynnik Y
			///
			void scale(float factorX, float factorY);

			///
			///Metoda zwraca origin obiektu
			///
			const sf::Vector2f & getOrigin() const;

			///
			///Metoda ustawia origin obiektu
			///
			///@param origin - stała referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f & origin);

			///
			///Metoda ustawia origin obiektu
			///
			///@param x - współrzędna X
			///
			///@param y - współrzędna Y
			///
			void setOrigin(float x, float y);

			///
			///Wirtualna metoda renderująca obiekt klasy HudStaticText
			///
			///@render render_window - parametr drawable
			///
			virtual void draw( sf::RenderWindow *render_window );

		private:
			
			sf::Text *p_text; //wskaźnik na obiekt klasy sf::Text (obiekt renderowalny)
			sf::Color m_color; //kolor
			CFont *p_font; //wskaźnik na czcionkę
			unsigned m_font_size; //rozmiar czcionki
			sf::String m_string; //łańcych znaków
			sf::Transformable m_tranformable; //opakowanie danych transformacji geometrycznej
		};
	} //namespace displayable
}//namespace rendering
#endif //H_HUD_STATIC_TEXT_JACK
