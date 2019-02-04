//  ______________________________________
// | CQuadtree.cpp - class implementation |
// | Jack April - July 2016               |
// |______________________________________|
//

#include "CQuadtree.h"
//#include "Object.h"	//atrapa - dodaæ nag³ówek klasy CPhysical
#include <iostream>
#include <sstream>

using namespace std;

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CQuadtree);

	CQuadtree::CQuadtree(float _x, float _y, float _width, float _height, int _level, int _maxLevel)
		:
		x(_x),
		y(_y),
		width(_width),
		height(_height),
		level(_level),
		maxLevel(_maxLevel)
	{
		shape.setPosition(x, y);
		shape.setSize(sf::Vector2f(width, height));
		shape.setFillColor(sf::Color(0, 0, 0, 0));
		shape.setOutlineThickness(1.0f);
		shape.setOutlineColor(sf::Color(64, 128, 255));
		text.setPosition(x, y + level * 16);
		text.setCharacterSize(12);

		if (level == maxLevel)
		{
			return;
		}
		//poni¿sze do prywatnej metody Build...
		NW = new CQuadtree(x, y, width / 2.0f, height / 2.0f, level + 1, maxLevel);
		NE = new CQuadtree(x + width / 2.0f, y, width / 2.0f, height / 2.0f, level + 1, maxLevel);
		SW = new CQuadtree(x, y + height / 2.0f, width / 2.0f, height / 2.0f, level + 1, maxLevel);
		SE = new CQuadtree(x + width / 2.0f, y + height / 2.0f, width / 2.0f, height / 2.0f, level + 1, maxLevel);
	}

	//ctor, ctor_copy, dtor

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CQuadtree::GetType() const
	{
		return rtti.GetNameClass();
	}

	void CQuadtree::AddObject(CObject *object)
	{
		if (level == maxLevel)
		{
			objects.push_back(object);
			return;
		}
		if (Contains(NW, object))
		{
			NW->AddObject(object); return;
		}
		else if (Contains(NE, object))
		{
			NE->AddObject(object); return;
		}
		else if (Contains(SW, object)) {
			SW->AddObject(object); return;
		}
		else if (Contains(SE, object))
		{
			SE->AddObject(object); return;
		}
		if (Contains(this, object))
		{
			objects.push_back(object);
		}
	}

	vector<CObject*> CQuadtree::GetObjectsAt(float _x, float _y)
	{
		if (level == maxLevel)
		{
			return objects;
		}

		vector<CObject*> returnObjects, childReturnObjects;
		if (!objects.empty())
		{
			returnObjects = objects;
		}
		if (_x > x + width / 2.0f && _x < x + width)
		{
			if (_y > y + height / 2.0f && _y < y + height)
			{
				childReturnObjects = SE->GetObjectsAt(_x, _y);
				returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
				return returnObjects;
			}
			else if (_y > y && _y <= y + height / 2.0f)
			{
				childReturnObjects = NE->GetObjectsAt(_x, _y);
				returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
				return returnObjects;
			}
		}
		else if (_x > x && _x <= x + width / 2.0f)
		{
			if (_y > y + height / 2.0f && _y < y + height)
			{
				childReturnObjects = SW->GetObjectsAt(_x, _y);
				returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
				return returnObjects;
			}
			else if (_y > y && _y <= y + height / 2.0f)
			{
				childReturnObjects = NW->GetObjectsAt(_x, _y);
				returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
				return returnObjects;
			}
		}
		return returnObjects;
	}

	void CQuadtree::Clear()
	{
		if (level == maxLevel)
		{
			objects.clear();
			return;
		}
		else
		{
			NW->Clear();
			NE->Clear();
			SW->Clear();
			SE->Clear();
		}
		if (!objects.empty())
		{
			objects.clear();
		}
	}

	void CQuadtree::SetFont(const sf::Font &font)
	{
		text.setFont(font);
		if (level != maxLevel)
		{
			NW->SetFont(font);
			NE->SetFont(font);
			SW->SetFont(font);
			SE->SetFont(font);
		}
	}

	void CQuadtree::Draw(sf::RenderTarget &canvas)
	{
		stringstream ss;
		ss << objects.size();
		string numObjectsStr = ss.str();
		text.setString(numObjectsStr);
		canvas.draw(shape);
		canvas.draw(text);

		if (level != maxLevel)
		{
			NW->Draw(canvas);
			NE->Draw(canvas);
			SW->Draw(canvas);
			SE->Draw(canvas);
		}
	}

	bool CQuadtree::Contains(CQuadtree *child, CObject *object)
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