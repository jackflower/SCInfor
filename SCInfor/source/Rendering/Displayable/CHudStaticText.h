//  ___________________________________________
// | CHudStaticText.h - class definition       |
// | Jack Flower October 2012                  |
// |___________________________________________|
//


#ifndef H_HUD_STATIC_TEXT_JACK
#define H_HUD_STATIC_TEXT_JACK

#include "../../RTTI/RTTI.h"
#include "../../ResourceManager/CResourceManager.h"
#include "../../ResourceManager/CFont.h"
#include "../Drawable/IDrawable.h"
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
		class CHudStaticText : public IDrawable
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			CHudStaticText();

			///
			///Destruktor wirtualny
			///
			virtual ~CHudStaticText();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca wskaŸnik na obiekt klasy sf::Text
			///
			const sf::Text* getText() const;

			///
			///Metoda zwraca kolor
			///
			const sf::Color& getColor() const;

			///
			///Metoda ustawia kolor
			///
			///@param &color - kolor - referencja na obiekt klasy sf::Color
			///
			void setColor(const sf::Color& color);

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
			///Metoda ustawia czcionkê graficzn¹ tekstu dla obiektu klasy sf::String
			///
			///@param &font - sta³a referencja na obiekt klasy std::string
			///
			void SetFont(const std::string& font);

			///
			///Metoda ustawia czcionkê graficzn¹ tekstu dla obiektu klasy sf::String
			///
			///@param &font - sta³a referencja na obiekt klasy std::string
			///
			///@param size - romiar czcionki
			///
			void SetFont(const std::string& font, unsigned size);
			
			///
			///Metoda ustawia rozmiar czcionki graficznej tekstu
			///
			///@param size - rozmiar czcionki graficznej
			///
			void SetFontSize(unsigned size);

			///
			///Metoda ustawia ³añcuch znaków
			///
			///@param & string - sta³a referencja na obiekt klasy std::string
			///
			void SetString(const sf::String & string);

			///
			///Metoda zwraca pozycjê obiektu
			///
			const sf::Vector2f & getPosition() const;
		
			///
			///Metoda ustawia pozycjê obiektu
			///
			///@param & positon - sta³a referecnaj na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f &position);

			///
			///Metoda ustawia pozycjê obiektu
			///
			///@param x - wspó³rzêdna X
			///
			///@param y - wspó³rzêdna Y
			///
			void setPosition(float x, float y);

			///
			///Metoda zwraca obrót obiektu
			///
			float getRotation() const;

			///
			///Metoda ustawia obrót obiektu
			///
			///@param angle - k¹t obrotu
			///
			void setRotation(float angle);

			///
			///Metoda obraca obiekt zadany k¹t
			///
			///@param angle - k¹t obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca wektor skali obiektu
			///
			const sf::Vector2f& getScale() const;

			///
			///Metoda ustawia skalê obiektu
			///
			///@param &factors - wektor wspó³czynika skali - sta³a referncja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f& factors);

			///
			///Metoda ustawia skalê obiektu
			///
			///@param factorXt - wspó³czynnik X
			///
			///@param factorY - wspó³czynnik Y
			///
			void setScale(float factorX, float factorY);
		
			///
			///Metoda skaluje obiekt
			///
			///@param &factor - wspó³czynnik skali
			///
			void scale(const sf::Vector2f& factor);

			///
			///Metoda skaluje obiekt
			///
			///@param factorX - wspó³czynnik X
			///
			///@param factorY - wspó³czynnik Y
			///
			void scale(float factorX, float factorY);

			///
			///Metoda zwraca origin obiektu
			///
			const sf::Vector2f& getOrigin() const;

			///
			///Metoda ustawia origin obiektu
			///
			///@param &origin - sta³a referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f& origin);

			///
			///Metoda ustawia origin obiektu
			///
			///@param x - wspó³rzêdna X
			///
			///@param y - wspó³rzêdna Y
			///
			void setOrigin(float x, float y);

			///
			///Wirtualna metoda renderuj¹ca obiekt klasy CHudStaticText
			///
			///@render render_window - parametr drawable
			///
			virtual void Draw( sf::RenderWindow* render_window );

		private:
			
			sf::Text*			p_text;			//wskaŸnik na obiekt klasy sf::Text (obiekt renderowalny)
			sf::Color			m_color;		//kolor
			CFont*				p_font;			//wskaŸnik na czcionkê
			unsigned			m_font_size;	//rozmiar czcionki
			sf::String			m_string;		//³añcych znaków
			sf::Transformable	m_tranformable;	//opakowanie danych transformacji geometrycznej
		};
	} //namespace displayable
}//namespace rendering
#endif //H_HUD_STATIC_TEXT_JACK
