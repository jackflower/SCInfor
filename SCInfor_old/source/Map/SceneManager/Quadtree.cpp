//  _____________________________________
// | Quadtree.cpp - class implementation |
// | Jack April - July 2016              |
// |_____________________________________|
//

#include "Quadtree.h"
//#include "Object.h"	//atrapa - dodać nagłówek klasy Physical
#include <iostream>
#include <sstream>

using namespace std;

namespace mapengine
{
	RTTI_IMPL_NOPARENT(Quadtree);

	Quadtree::Quadtree(float x, float y, float width, float height, int level, int maxLevel)
	:
		m_x(x),
		m_y(y),
		m_width(width),
		m_height(height),
		m_level(level),
		m_maxLevel(maxLevel)
	{
		shape.setPosition(m_x, m_y);
		shape.setSize(sf::Vector2f(m_width, m_height));
		shape.setFillColor(sf::Color(0, 0, 0, 0));
		shape.setOutlineThickness(1.0f);
		shape.setOutlineColor(sf::Color(64, 128, 255));
		text.setPosition(m_x, m_y + m_level * 16);
		text.setCharacterSize(12);

		if (m_level == m_maxLevel)
		{
			return;
		}
		//poniższe do prywatnej metody Build...
		NW = new Quadtree(m_x, m_y, m_width / 2.0f, m_height / 2.0f, m_level + 1, m_maxLevel);
		NE = new Quadtree(m_x + m_width / 2.0f, m_y, m_width / 2.0f, m_height / 2.0f, m_level + 1, m_maxLevel);
		SW = new Quadtree(m_x, m_y + m_height / 2.0f, m_width / 2.0f, m_height / 2.0f, m_level + 1, m_maxLevel);
		SE = new Quadtree(m_x + m_width / 2.0f, m_y + m_height / 2.0f, m_width / 2.0f, m_height / 2.0f, m_level + 1, m_maxLevel);
	}

	//ctor, ctor_copy, dtor

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Quadtree::getType() const
	{
		return rtti.GetNameClass();
	}

	void Quadtree::addObject(Object *object)
	{
		if (m_level == m_maxLevel)
		{
			objects.push_back(object);
			return;
		}
		if (Contains(NW, object))
		{
			NW->addObject(object); return;
		}
		else if (Contains(NE, object))
		{
			NE->addObject(object); return;
		}
		else if (Contains(SW, object)) {
			SW->addObject(object); return;
		}
		else if (Contains(SE, object))
		{
			SE->addObject(object); return;
		}
		if (Contains(this, object))
		{
			objects.push_back(object);
		}
	}

	vector<Object*> Quadtree::getObjectsAt(float x, float y)
	{
		if (m_level == m_maxLevel)
		{
			return objects;
		}

		vector<Object*> returnObjects, childReturnObjects;
		if (!objects.empty())
		{
			returnObjects = objects;
		}
		if (x > m_x + m_width / 2.0f && x < m_x + m_width)
		{
			if (y > m_y + m_height / 2.0f && y < m_y + m_height)
			{
				childReturnObjects = SE->getObjectsAt(x, y);
				returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
				return returnObjects;
			}
			else if (y > m_y && y <= m_y + m_height / 2.0f)
			{
				childReturnObjects = NE->getObjectsAt(x, y);
				returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
				return returnObjects;
			}
		}
		else if (x > m_x && x <= m_x + m_width / 2.0f)
		{
			if (y > m_y + m_height / 2.0f && y < m_y + m_height)
			{
				childReturnObjects = SW->getObjectsAt(x, y);
				returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
				return returnObjects;
			}
			else if (y > m_y && y <= m_y + m_height / 2.0f)
			{
				childReturnObjects = NW->getObjectsAt(x, y);
				returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
				return returnObjects;
			}
		}
		return returnObjects;
	}

	void Quadtree::clear()
	{
		if (m_level == m_maxLevel)
		{
			objects.clear();
			return;
		}
		else
		{
			NW->clear();
			NE->clear();
			SW->clear();
			SE->clear();
		}
		if (!objects.empty())
		{
			objects.clear();
		}
	}

	void Quadtree::setFont(const sf::Font & font)
	{
		text.setFont(font);
		if (m_level != m_maxLevel)
		{
			NW->setFont(font);
			NE->setFont(font);
			SW->setFont(font);
			SE->setFont(font);
		}
	}

	void Quadtree::draw(sf::RenderTarget & canvas)
	{
		stringstream ss;
		ss << objects.size();
		string numObjectsStr = ss.str();
		text.setString(numObjectsStr);
		canvas.draw(shape);
		canvas.draw(text);

		if (m_level != m_maxLevel)
		{
			NW->draw(canvas);
			NE->draw(canvas);
			SW->draw(canvas);
			SE->draw(canvas);
		}
	}

	bool Quadtree::Contains(Quadtree *child, Object *object)
	{
		//return	 !(object->x < child->x ||
		//	object->y < child->y ||
		//	object->x > child->x + child->width ||
		//	object->y > child->y + child->height ||
		//	object->x + object->width < child->x ||
		//	object->y + object->height < child->y ||
		//	object->x + object->width > child->x + child->width ||
		//	object->y + object->height > child->y + child->height);

		return false; //atrapa
	}
}//namespace mapengine