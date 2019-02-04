//  _______________________________________
// | CRectangle.cpp - class implementation |
// | Jack Flower - April 2014              |
// |_______________________________________|
//

#include "CRectangle.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace rendering
{
	namespace primitives
	{
		RTTI_IMPL(CRectangle, IDrawable);

		//Konstruktor
		CRectangle::CRectangle()
		:
			IDrawable	(),			//konstruktor klasy bazowej
			p_rectangle	()
		{
			//tworzymy obiekt klasy sf::RectangleShape
			p_rectangle = new sf::RectangleShape();
		}

		//Destruktor
		CRectangle::~CRectangle()
		{
			delete p_rectangle;//usuwamy obiekt (mamy pewno��, �e istnieje, bo konstruktor go stworzy�)
			p_rectangle	= NULL;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CRectangle::GetType() const
		{
			return rtti.GetNameClass();
		}
	
		//Metoda zwraca wska�nik na obiekt sf::RectangleShape
		sf::RectangleShape *CRectangle::getRectangleShape()
		{
			return p_rectangle;
		}

		//Metoda zwraca pozycj� obiektu
		const sf::Vector2f& CRectangle::getPosition() const
		{
			return p_rectangle->getPosition();
		}

		//Metoda ustawia pozycj� obiektu
		void CRectangle::setPosition(float x, float y)
		{
			p_rectangle->setPosition(x, y);
		}

		//Metoda ustawia pozycj� obiektu
		void CRectangle::setPosition(const sf::Vector2f& vector)
		{
			setPosition(vector.x, vector.y);
		}

		//Wirtualna metoda renderuj�ca obiekt
		void CRectangle::Draw(sf::RenderWindow* render)
		{
			//je�li flaga nie pozwala - nie rysujemy obiektu - return
			if(m_can_draw == false)	return;
			if (p_rectangle)				//na wszelki wypadek, gdyby wska�nik straci� adres...
				render->draw(*p_rectangle);	//rysujemy obiekt
		}
	}//namespace primitives
}//namespace rendering
