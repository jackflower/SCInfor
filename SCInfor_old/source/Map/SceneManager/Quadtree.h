//  _____________________________________
// | Quadtree.h - class definition       |
// | Jack April - July 2016              |
// |_____________________________________|
//

#ifndef H_QUADTREE_JACK
#define H_QUADTREE_JACK

#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../../RTTI/RTTI.h"

using namespace std;

///
///Forward declaration
///
class CQuadtree;
class Object;

namespace mapengine
{
	class Quadtree
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor parametryczny
		///
		Quadtree(float x, float y, float width, float height, int level, int maxLevel);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		void addObject(Object *object);
		vector<Object*> getObjectsAt(float x, float y);
		void clear();

		void setFont(const sf::Font & font);
		void draw(sf::RenderTarget & canvas);

	private:
		float m_x;
		float m_y;
		float m_width;
		float m_height;
		int m_level;
		int m_maxLevel;
		vector<Object*> objects;

		Quadtree *parent;
		Quadtree *NW;
		Quadtree *NE;
		Quadtree *SW;
		Quadtree *SE;

		sf::RectangleShape shape;
		sf::Text text;

		bool Contains(Quadtree *child, Object *object);
	};
}//namespace mapengine
#endif//H_QUADTREE_JACK
