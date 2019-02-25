//  _______________________________________
// | CollisionMap.h - class implementation |
// | Jack Flower July 2013                 |
// |_______________________________________|
//

#include "CollisionMap.h"
//#include "DynamicRegionsGenerator.h"//to pozostanie, ale zanim - includuję DynamicRegion
#include "DynamicRegion.h"
#include "Map.h"
#include "MapManager.h"
//#include "SearchTools/CPath.h"
//#include "SearchTools/CPathFinder.h"
#include "../Logic/PhysicalManager.h"
#include "../Logic/Physical/Physical.h"
#include "../Utilities/MathFunctions/MathFunctions.h"
#include <climits>
#include <iostream>

const int kUnaccessableTile = INT_MAX;	//limit ilości kafli - niedostępne
const int kRegionSize = 10;				//kazdy region zajmuje x komórek

using namespace mapengine;

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CollisionMap);

	//Konstruktor
	CollisionMap::CollisionMap()
	:
		m_size(0, 0),
		m_cell_per_tile(0.0f, 0.0f),
		m_single_cell_size(0.0f, 0.0f),
		m_cell_list(),
		m_region_list(),
		m_enemy_density(5)
	{
		m_cell_list.clear();
		m_region_list.clear();
	}

	//Destruktor
	CollisionMap::~CollisionMap()
	{
		m_cell_list.clear();
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CollisionMap::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda inicjuje mapę kolizji
	void CollisionMap::initialize(sf::Vector2i size)
	{
		m_size = size;//tutaj ustawiam rozmiar mapy kolizji
		//wywołane raz w MapManager...
		
		if (gMapManager.getCurrent())
		{
			m_cell_per_tile.x = (float)size.x/(float)gMapManager.getCurrent()->getSize().x;
			m_cell_per_tile.y = (float)size.y/(float)gMapManager.getCurrent()->getSize().y;
		}
		else
			m_cell_per_tile = sf::Vector2f(0.0f, 0.0f);
		
		m_single_cell_size.x = (m_cell_per_tile.x != 0.0f ? 1.0f/m_cell_per_tile.x : 0.0f);
		m_single_cell_size.y = (m_cell_per_tile.y != 0.0f ? 1.0f/m_cell_per_tile.y : 0.0f);
		
		m_cell_list.clear();
		m_cell_list.resize(m_size.x * m_size.y);
		
		for (unsigned i = 0; i < m_cell_list.size(); i++)
		{
			m_cell_list[i].setCollision(false);
		}

		updatePhysicals(PHYSICAL_PATHBLOCKER);
		updateRegions();
		updatePhysicals(PHYSICAL_ACTORS);
	}

	//Metoda aktualizuje wszystkie obiekty znajdujące się na mapie kolizji
	void CollisionMap::updateAllPhysicals()
	{
		const std::vector<Physical*> & physicals = gPhysicalManager.getPhysicals();
		for (unsigned i = 0; i < physicals.size(); i++)
		{
			updatePhysical(physicals[i], true);
		}
	}

	//Metoda aktualizuje obiekty znajdujące się na mapie kolizji w zależności od kategorii
	void CollisionMap::updatePhysicals(int category)
	{
		const std::vector<Physical*> & physicals = gPhysicalManager.getPhysicals();
		for (unsigned i = 0; i < physicals.size(); i++)
		{
			if (physicals[i]->getCategory() & category)
				updatePhysical(physicals[i], true);
		}
	}

	//Metoda aktualizuje wskazany obiekt klasy Physical
	void CollisionMap::updatePhysical(Physical *physical, bool collision)
	{
		if (!(physical->getCategory() & PHYSICAL_PATHBLOCKER))
			return;
		if (!gMapManager.getCurrent())
			return;

		//pobieramy rozmiar mapy w kaflach, aby poprawnie zeskalować współrzędne
		sf::Vector2i mapSize = gMapManager.getCurrent()->getSize();

		//rzutowanie physicala na mapę kolizji o danym rozmiarze
		sf::IntRect rect
		(
			int ((physical->getPosition().x - physical->getRectSize().x * 0.49f) * (float) m_size.x / (float) mapSize.x),
			int ((physical->getPosition().y - physical->getRectSize().y * 0.49f) * (float) m_size.y / (float) mapSize.y),
			int ((physical->getPosition().x + physical->getRectSize().x * 0.49f) * (float) m_size.x / (float) mapSize.x),
			int ((physical->getPosition().y + physical->getRectSize().y * 0.49f) * (float) m_size.y / (float) mapSize.y)
		);

		//TUTAJ utknąłem, bo wymaga to policzenia...
		//kogut - co jest grane???

		//zabezpieczenie przed wyjściem poza tablice

		//if ( rect.Left < 0 )				rect.Left = 0;
		//if ( rect.Left >= m_size.x )		rect.Left = m_size.x - 1;
		//if ( rect.Right < 0 )				rect.Right = 0;
		//if ( rect.Right >= m_size.x )		rect.Right = m_size.x - 1;

		//if ( rect.Top < 0 )				rect.Top = 0;
		//if ( rect.Top >= m_size.y )		rect.Top = m_size.y - 1;
		//if ( rect.Bottom < 0 )			rect.Bottom = 0;
		//if ( rect.Bottom >= m_size.y )	rect.Bottom = m_size.y - 1;
		
		//zagadka???
		//if ( rect.left < 0 )				rect.left = 0;
		//if ( rect.left >= m_size.x )		rect.left = m_size.x - 1;//1?? jeden?  dlaczego?
		//if ( (rect.left + rect.width) < 0 )	rect.Right = 0;
		//if ( rect.Right >= m_size.x )		rect.Right = m_size.x - 1;



		// no i nareszcie...

		//ponbiżej (nie ruszać, ma być comment, patrz source WG
		//UWAGA - ODBLOKOWANIE!!!!
	//	for ( unsigned y = rect.Top; y <= (unsigned) rect.Bottom; y++ )
	//		for ( unsigned x = rect.Left; x <= (unsigned) rect.Right; x++ )
	//			m_cell_list[ y * m_size.x + x ].collision = collision;	

		//po analizie domniemuję... - co jest grane???
		//w tej pętli określam, czy dany obszar mapy jest zajęty...
		//czyli czy jest w tym obszarze kolizja?
	}

	//Metoda zwraca flagę, czy nastąpiła kolizja z jakimkolwiek obiektem z kontenera przechowującego obiekty klasy Cell
	bool CollisionMap::getCollisionByCell(const sf::Vector2i& collision) const
	{
		if (collision.x < 0 || collision.y < 0 || collision.x >= m_size.x || collision.y >= m_size.y)
			return true;
		return m_cell_list[cellToIndex(collision)].getCollision();
	}

	//Metoda zwraca flagę, czy nastąpiła kolizja z obiektem opisanym współrzędnymi skrajnych wierzchołków
	bool CollisionMap::getCollisionByRect(const sf::Vector2i &leftUp, const sf::Vector2i &rightDown) const
	{
		for (int y = leftUp.y; y <= rightDown.y; y++)
			for (int x = leftUp.x; x <= rightDown.x; x++)
				if (m_cell_list[y * m_size.x + x ].getCollision())
					return true;
		return false;
	}

	//Metoda zwraca gęstość obiektów w obszarze klasy Cell
	int CollisionMap::getDensityByCell(const sf::Vector2i& cell)
	{
		int index = cellToIndex(cell);
		return (m_cell_list[index].getCollision() == true ? kUnaccessableTile : m_cell_list[index].getDensity());
	}

	//Metoda zwraca gęstość obiektów opisanych współrzędnymi skrajnych wierzchołków
	int CollisionMap::getDensityByRect(const sf::Vector2i& leftUp, const sf::Vector2i& rightDown)
	{
		if (getCollisionByRect(leftUp, rightDown) == true)
		{
			return kUnaccessableTile;
		}

		int totalDensity = 0;

		for (int y = leftUp.y; y <= rightDown.y; ++y)
		{
			for (int x = leftUp.x; x <= rightDown.x; ++x)
			{
				totalDensity += m_cell_list[y * m_size.x + x].getDensity();
			}
		}
		
		return totalDensity;
	}

	//Metoda dodaje do kontenera węzeł ścieżki
	void CollisionMap::addPath(const CPath * path)
	{
		modifyPath(path, m_enemy_density);
	}

	//Metoda usuwa z kontenera węzeł ścieżki
	void CollisionMap::removePath(const CPath * path)
	{
		modifyPath(path, -m_enemy_density);
	}

	//Metoda modyfikuje ściżkę
	void CollisionMap::modifyPath(const CPath* path, int delta)
	{
		/*
		sf::Vector2i size = path->GetSize();
		for (unsigned int i = 0; i < path->Length(); ++i)
		{
			sf::Vector2i index = path->GetWaypoint(i);
			for (int y = 0; y < size.y; ++y)
			{
				for (int x = 0; x < size.x; ++x)
				{
					m_cell_list[(index.y + y) * m_size.x + (index.x + x)].m_density += delta;
				}
			}        
		}
		*/
	}

	//Metoda znajduje ścieżkę
	bool CollisionMap::findPath(
		const sf::Vector2f & start,
		const sf::Vector2f & goal,
		const sf::Vector2f & physicalSize,
		CPath ** path)
	{
		//return CPathFinder().FindPath(start, goal, physicalSize, path);
		return false; ///atrapa...
	}

	//Metoda zwraca pozycję kafla dla danych współrzędnych globalnych
	sf::Vector2i CollisionMap::getCellByCoords(const sf::Vector2f& point) 
	{ 
		return sf::Vector2i
			( 
				maths::ClampInt((int)(point.x * m_cell_per_tile.x ), 0, m_size.x-1),
				maths::ClampInt((int)(point.y * m_cell_per_tile.y ), 0, m_size.y-1) 
			);
	}

	//Metoda zwraca współrzędne globalne dla danego kafla
	sf::Vector2f CollisionMap::getCoordsByCell( const sf::Vector2i& cell )
	{
		return sf::Vector2f
			( 
				(float)cell.x * m_single_cell_size.x, 
				(float)cell.y * m_single_cell_size.y
			);
	}

	//Metoda zamienia rozmiar w ilość zajmowanych pol
	sf::Vector2i CollisionMap::convertSizeToCells(const sf::Vector2f & size)
	{
		return sf::Vector2i
			(
				static_cast<int>(size.x / m_single_cell_size.x),
				static_cast<int>(size.y / m_single_cell_size.y)
			);
	}

	//Metoda dynamicznie aktalizuje regiony mapy
	void CollisionMap::updateRegions()
	{
	    //DynamicRegionsGenerator regionsGenerator(m_size, sf::Vector2i(kRegionSize, kRegionSize));
	    //regionsGenerator.GenerateRegions(m_cell_list, m_region_list);
	}

	//Metoda zwraca wskaźnik na obiekt klasy DynamicRegion
	DynamicRegion *CollisionMap::getRegionByCell(const sf::Vector2i &cell)
	{
		int regionId = m_cell_list.at(cellToIndex((cell))).getRegionId();

		for (std::vector<DynamicRegion*>::const_iterator it = m_region_list.begin(); it != m_region_list.end(); ++it)
		{
			if ((*it)->getRegionID() == regionId)
		        return *it;
		}
		return NULL;
	}
}//namespace mapengine
