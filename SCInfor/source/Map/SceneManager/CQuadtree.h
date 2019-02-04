//  ______________________________________
// | CQuadtree.h - class definition       |
// | Jack April - July 2016               |
// |______________________________________|
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
class CObject;

namespace mapengine
{
	class CQuadtree
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor parametryczny
		///
		CQuadtree(float x, float y, float width, float height, int level, int maxLevel);

		//ctor, ctor_copy, dtor

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		void					AddObject(CObject *object);
		vector<CObject*>			GetObjectsAt(float x, float y);
		void					Clear();

		void					SetFont(const sf::Font &font);
		void					Draw(sf::RenderTarget &canvas);

	private:
		float					x;
		float					y;
		float					width;
		float					height;
		int						level;
		int						maxLevel;
		vector<CObject*>			objects;

		CQuadtree *				parent;
		CQuadtree *				NW;
		CQuadtree *				NE;
		CQuadtree *				SW;
		CQuadtree *				SE;

		sf::RectangleShape		shape;
		sf::Text				text;

		bool					Contains(CQuadtree *child, CObject *object);
	};
}//namespace mapengine
#endif//H_QUADTREE_JACK
