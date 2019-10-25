////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#ifndef H_DISPLAYABLE_ACODEMIA
#define H_DISPLAYABLE_ACODEMIA

#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Texture.h"

namespace acodemia
{
	namespace rendering
	{
		///
		///Klasa reprezentuje obiekt, który może być renderowany
		///
		class Displayable
		{
		
		public:

			///
			///Konstruktor domyślny
			///
			Displayable();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Displayable
			///
			Displayable(const Displayable & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Displayable(Displayable && other);

			///
			///Destruktor
			///
			~Displayable();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Displayable
			///
			Displayable & operator=(const Displayable & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Displayable & operator=(Displayable && other);

			///
			///Metoda zwraca stałą referencję pozycji obiektu
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param x - współrzędna x obiektu
			///
			///@param y - współrzędna y obiektu
			///
			void setPosition(float x, float y);

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param vector - stała referenacja na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & vector);

			///
			///Metoda zwraca wartość obrotu
			///
			float getRotation() const;
		
			///
			///Metoda ustawia wartość obrotu
			///
			///@param rotation_value - wartość obrotu
			///
			void setRotation(float rotation_value);

			///
			///Metoda obraca wartość obrotu
			///
			///@param angle - wartość obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca skalę
			///
			const sf::Vector2f & getScale() const;
		
			///
			///Metoda ustawia skalę
			///
			///@param x - współrzędna x wektora
			///
			///@param y - współrzędna y wektora
			///
			void setScale(float x, float y);

			///
			///Metoda ustawia skalę
			///
			///@param new_scale_value - stała referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f & new_scale_value);

			///
			///Metoda ustawia skalę
			///
			///@param factors - jednolita wartość skalująca w osi x i y
			///
			void setScale(float factors);

			///
			///Metoda ustawia skalę w stosunku do obecnej skali
			///
			///@param factorX - współczynnik w osi x
			///
			///@param factorY - spółczynnik w osi y
			///
			void scale(float factorX, float factorY);
			
			///
			///Metoda ustawia skalę w stosunku do obecnej skali
			///
			///@param factor - stała referencja na obiekt klasy sf::Vector2f
			///
			void scale(const sf::Vector2f & factor);

			///
			///Metoda zwraca współrzędne punktu uchwytu obiektu
			///
			const sf::Vector2f & getOrigin() const;

			///
			///Metoda ustawia współrzędne punktu uchwytu obiektu
			///
			///@param x - współrzędna x
			///
			///@param y - współrzędna y
			///
			void setOrigin(float x, float y);

			///
			///Metoda ustawia współrzędne punktu uchwytu obiektu
			///
			///@param origin - stała referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f & origin);

			///
			///Metoda zwraca obszar prostokątny zajmowany przez teksturę
			///
			const sf::IntRect & getTextureRect() const;

			///
			///Metoda ustawia obszar prostokątny zajmowany przez teksturę
			///
			///@param rectLeft - lewy róg prostokątnego obszaru
			///
			///@param rectTop - górny róg prostokątnego obszaru
			///
			///@param rectWidth - szerokość prostokątnego obszaru
			///
			///@param rectHeight - wysokość prostokątnego obszaru
			///
			void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);

			///
			///Metoda ustawia obszar prostokątny zajmowany przez teksturę
			///
			///@param rectangle - stała referencja na obiekt klasy sf::IntRect
			///
			void setTextureRect (const sf::IntRect & rectangle);

			///
			///Metoda zwraca granice obiektu w lokalnym w układzie współrzędnych
			///
			sf::FloatRect getLocalBounds() const;

			///
			///Metoda zwraca granice obiektu w globalnym w układzie współrzędnych
			///
			sf::FloatRect getGlobalBounds() const;
			
			///
			///Metoda przemieszcza obiekt o wartość podaną w parametrach względem aktualnej pozycji
			///
			///@param offsetX - wartość przesunięcia w osi x
			///
			///@param offsetY - wartość przesunięcia w osi x
			///
			void move(float offsetX, float offsetY);

			///
			///Metoda przemieszcza obiekt o wartość wektora przesunięcia
			///
			///@param offset - stała referencja na obiekt klasy sf::Vector2f - wektora przesunięcia
			///
			void move(const sf::Vector2f & offset);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color & getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param color - stała referencja na obiekt klasy sf::Color
			///
			void setColor(const sf::Color & color);

			///
			///Metoda ustawia teksturę dla sprite
			///
			///@param &texture - stała referencja na obiekt klasy Texture
			///
			void setTexture(const Texture & texture);

			///
			///Wirtualna metoda renderująca obiekt
			///
			///@param render - referencja na kontekst graficzny
			///
			virtual void draw(sf::RenderWindow & render) const;
		
		private:
		
			Sprite *p_sprite;
			
		};
	} //namespace rendering
}//namespace acodemia
#endif //H_DISPLAYABLE_ACODEMIA
