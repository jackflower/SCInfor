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

#include "Displayable.h"

namespace acodemia
{
	namespace rendering
	{
		//Konstruktor domyślny
		Displayable::Displayable()
		:
			p_sprite(new Sprite())
		{
		}

		//Konstruktor kopiujący
		Displayable::Displayable(const Displayable & copy)
		:
			p_sprite(new Sprite(*copy.p_sprite))
		{
		}

		//Konstruktor przenoszący
		Displayable::Displayable(Displayable && other)
		:
			//kopiujemy pod wskaźnik dane obiektu źródłowego
			p_sprite(std::move(other.p_sprite))
		{
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie
			other.p_sprite = nullptr;
		}

		//Destruktor
		Displayable::~Displayable() 
		{
			if(p_sprite != nullptr)
				delete p_sprite;
			p_sprite = nullptr;
		}

		//Przeciążony operator przypisania kopiowania
		Displayable & Displayable::operator=(const Displayable & copy)
		{
			if (this != &copy)
			{
				//zwalaniamy dane pod wskaźnikiem
				delete p_sprite;
				//tworzymy nowy obiekt na podstawie obiektu źródłowego
				p_sprite = new Sprite(*copy.p_sprite);
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Displayable & Displayable::operator=(Displayable && other)
		{
			if (this != & other)
			{
				//zwalaniamy dane pod wskaźnikiem
				delete p_sprite;
				//przenosimy pod wskaźnik dane z obiektu źródłowego
				p_sprite = other.p_sprite;
				//zwalniamy wskaźnik na dane obiektu źródłowego tak,
				//aby destruktor nie zwalniał pamięci wielokrotnie
				other.p_sprite = nullptr;
			}
				return *this;
		}

		//Metoda zwraca stałą referencję pozycji obiektu
		const sf::Vector2f & Displayable::getPosition() const
		{
			return p_sprite->getPosition();
		}

		//Metoda ustawia pozycję obiektu
		void Displayable::setPosition(float x, float y)
		{
			if(p_sprite)
				p_sprite->setPosition(x, y);
		}

		//Metoda ustawia pozycję obiektu
		void Displayable::setPosition(const sf::Vector2f & vector)
		{
			setPosition(vector.x, vector.y);
		}

		//Metoda zwraca wartość obrotu
		float Displayable::getRotation() const
		{ 
			return p_sprite->getRotation();
		}

		//Metoda ustawia wartość obrotu
		void Displayable::setRotation(float rotation_value)
		{
			if (p_sprite)
				p_sprite->setRotation(rotation_value);
		}

		//Metoda obraca wartość obrotu
		void Displayable::rotate(float angle)
		{
			if (p_sprite)
				p_sprite->rotate(angle);
		}

		//Metoda zwraca skalę
		const sf::Vector2f & Displayable::getScale() const
		{
			return p_sprite->getScale();
		}

		//Metoda ustawia skalę
		void Displayable::setScale(float x, float y)
		{
			if (p_sprite)
				p_sprite->setScale(x, y);
		}

		//Metoda ustawia skalę
		void Displayable::setScale(const sf::Vector2f & new_scale_value)
		{
			p_sprite->setScale(new_scale_value);
		}

		//Metoda ustawia skalę
		void Displayable::setScale(float factors)
		{
			if (p_sprite)
				setScale(factors, factors);
		}

		//Metoda ustawia skalę w stosunku do obecnej skali
		void Displayable::scale(float factorX, float factorY)
		{
			p_sprite->scale(factorX, factorY);
		}

		//Metoda ustawia skalę w stosunku do obecnej skali
		void Displayable::scale(const sf::Vector2f & factor)
		{
			if (p_sprite)
				p_sprite->scale(factor);
		}

		//Metoda zwraca współrzędne punktu uchwytu obiektu
		const sf::Vector2f & Displayable::getOrigin() const
		{
			return p_sprite->getOrigin();
		}

		//Metoda ustawia współrzędne punktu uchwytu obiektu
		void Displayable::setOrigin(float x, float y)
		{
			if (p_sprite)
				p_sprite->setOrigin(x, y);
		}

		//Metoda ustawia współrzędne punktu uchwytu obiektu
		void Displayable::setOrigin(const sf::Vector2f & origin)
		{
			if (p_sprite)
				p_sprite->setOrigin(origin);
		}

		//Metoda zwraca obszar prostokątny zajmowany przez teksturę
		const sf::IntRect & Displayable::getTextureRect() const
		{
			return p_sprite->getTextureRect();
		}

		//Metoda ustawia obszar prostokątny zajmowany przez teksturę
		void Displayable::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight)
		{
			setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
		}

		//Metoda ustawia obszar prostokątny zajmowany przez teksturę
		void Displayable::setTextureRect (const sf::IntRect& rectangle)
		{
			if (p_sprite)
				p_sprite->setTextureRect(rectangle);
		}

		//Metoda zwraca granice obiektu w lokalnym w układzie współrzędnych
		sf::FloatRect Displayable::getLocalBounds() const
		{
			return p_sprite->getLocalBounds();
		}

		//Metoda zwraca granice obiektu w globalnym w układzie współrzędnych
		sf::FloatRect Displayable::getGlobalBounds() const
		{
			return p_sprite->getGlobalBounds();
		}

		//Metoda przemieszcza obiekt o wartość podaną w parametrach względem aktualnej pozycji
		void Displayable::move(float offsetX, float offsetY)
		{
			if (p_sprite)
				p_sprite->move(offsetX, offsetY);
		}

		//Metoda przemieszcza obiekt o wartość wektora przesunięcia
		void Displayable::move(const sf::Vector2f & offset)
		{
			if (p_sprite)
				p_sprite->move(offset);
		}

		//Metoda zwraca kolor obiektu
		const sf::Color&  Displayable::getColor() const
		{
			return p_sprite->getColor();
		}

		//Metoda ustawia kolor obiektu
		void Displayable::setColor(const sf::Color & color)
		{
			if (p_sprite)
				p_sprite->setColor(color);
		}

		//Metoda ustawia teksturę dla sprite
		void Displayable::setTexture(const Texture & texture)
		{
			if(p_sprite)
				p_sprite->setTexture(texture);
		}

		//Wirtualna metoda renderująca obiekt
		void Displayable::draw(sf::RenderWindow & render) const
		{
			if (p_sprite)//na wszelki wypadek, gdyby wskaźnik stracił adres...
				render.draw(*p_sprite);	//rysujemy obiekt
		}
	}//namespace rendering
}//namespace acodemia
