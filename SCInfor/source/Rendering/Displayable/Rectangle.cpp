//  ______________________________________
// | Rectangle.cpp - class implementation |
// | Jack Flower - April 2014             |
// |______________________________________|
//

#include "Rectangle.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace rendering
{
	namespace primitives
	{
		RTTI_IMPL(Rectangle, Drawable);

		//Konstruktor
		Rectangle::Rectangle()
		:
			Drawable(), //konstruktor klasy bazowej
			p_rectangle()
		{
			//tworzymy obiekt klasy sf::RectangleShape
			p_rectangle = new sf::RectangleShape();
		}

		//Destruktor
		Rectangle::~Rectangle()
		{
			delete p_rectangle;//usuwamy obiekt (mamy pewność, że istnieje, bo konstruktor go stworzył)
			p_rectangle	= NULL;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Rectangle::getType() const
		{
			return rtti.getNameClass();
		}
	
		//Metoda zwraca wskaźnik na obiekt sf::RectangleShape
		sf::RectangleShape *Rectangle::getRectangleShape()
		{
			return p_rectangle;
		}

		//Metoda zwraca pozycję obiektu
		const sf::Vector2f & Rectangle::getPosition() const
		{
			return p_rectangle->getPosition();
		}

		//Metoda ustawia pozycję obiektu
		void Rectangle::setPosition(float x, float y)
		{
			p_rectangle->setPosition(x, y);
		}

		//Metoda ustawia pozycję obiektu
		void Rectangle::setPosition(const sf::Vector2f & vector)
		{
			setPosition(vector.x, vector.y);
		}

		//Wirtualna metoda renderująca obiekt
		void Rectangle::draw(sf::RenderWindow *render)
		{
			//jeśli flaga nie pozwala - nie rysujemy obiektu - return
			if(m_can_draw == false)	return;
			if (p_rectangle)				//na wszelki wypadek, gdyby wskaźnik stracił adres...
				render->draw(*p_rectangle);	//rysujemy obiekt
		}
	}//namespace primitives
}//namespace rendering
