//  ________________________________________
// | CCollisionMap.h - class implementation |
// | Jack Flower July 2013                  |
// |________________________________________|
//

#include "CCollisionMap.h"
//#include "CDynamicRegionsGenerator.h"//to pozostanie, ale zanim - includujê CDynamicRegion
#include "CDynamicRegion.h"
#include "CMap.h"
#include "CMapManager.h"
//#include "SearchTools/CPath.h"
//#include "SearchTools/CPathFinder.h"
#include "../Logic/CPhysicalManager.h"
#include "../Logic/Physical/Physical.h"
#include "../Utilities/MathFunctions/MathFunctions.h"
#include <climits>
#include <iostream>

const int kUnaccessableTile = INT_MAX;	//limit iloœci kafli - niedostêpne
const int kRegionSize = 10;				//kazdy region zajmuje x komórek

using namespace mapengine;

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CCollisionMap);

	//Konstruktor
	CCollisionMap::CCollisionMap()
	:
		m_size				(0, 0),
		m_cell_per_tile		(0.0f, 0.0f),
		m_single_cell_size	(0.0f, 0.0f),
		m_cell_list			(),
		m_region_list		(),
		m_enemy_density		(5)
	{
		m_cell_list.clear();
		m_region_list.clear();
	}

	//Destruktor
	CCollisionMap::~CCollisionMap()
	{
		m_cell_list.clear();
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CCollisionMap::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda inicjuje mapê kolizji
	void CCollisionMap::Initialize(sf::Vector2i size)
	{
		m_size = size;//tutaj ustawiam rozmiar mapy kolizji
		//wywo³ane raz w CMapManager...
		
		if (gMapManager.GetCurrent())
		{
			m_cell_per_tile.x = (float)size.x/(float)gMapManager.GetCurrent()->getSize().x;
			m_cell_per_tile.y = (float)size.y/(float)gMapManager.GetCurrent()->getSize().y;
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

		UpdatePhysicals(PHYSICAL_PATHBLOCKER);
		UpdateRegions();
		UpdatePhysicals(PHYSICAL_ACTORS);
	}

	//Metoda aktualizuje wszystkie obiekty znajduj¹ce siê na mapie kolizji
	void CCollisionMap::UpdateAllPhysicals()
	{
		const std::vector<Physical*> &physicals = gPhysicalManager.GetPhysicals();
		for (unsigned i = 0; i < physicals.size(); i++)
		{
			UpdatePhysical(physicals[i], true);
		}
	}

	//Metoda aktualizuje obiekty znajduj¹ce siê na mapie kolizji w zale¿noœci od kategorii
	void CCollisionMap::UpdatePhysicals(int category)
	{
		const std::vector<Physical*> &physicals = gPhysicalManager.GetPhysicals();
		for (unsigned i = 0; i < physicals.size(); i++)
		{
			if (physicals[i]->getCategory() & category)
				UpdatePhysical(physicals[i], true);
		}
	}

	//Metoda aktualizuje wskazany obiekt klasy Physical
	void CCollisionMap::UpdatePhysical(Physical *physical, bool collision)
	{
		if (!(physical->getCategory() & PHYSICAL_PATHBLOCKER))	return;
		if (!gMapManager.GetCurrent())							return;

		//pobieramy rozmiar mapy w kaflach, aby poprawnie zeskalowaæ wspó³rzêdne
		sf::Vector2i mapSize = gMapManager.GetCurrent()->getSize();

		//rzutowanie physicala na mapê kolizji o danym rozmiarze
		sf::IntRect rect
		(
			int ((physical->getPosition().x - physical->getRectSize().x * 0.49f) * (float) m_size.x / (float) mapSize.x),
			int ((physical->getPosition().y - physical->getRectSize().y * 0.49f) * (float) m_size.y / (float) mapSize.y),
			int ((physical->getPosition().x + physical->getRectSize().x * 0.49f) * (float) m_size.x / (float) mapSize.x),
			int ((physical->getPosition().y + physical->getRectSize().y * 0.49f) * (float) m_size.y / (float) mapSize.y)
		);

		//TUTAJ utkn¹³em, bo wymaga to policzenia...
		//kogut - co jest grane???

		//zabezpieczenie przed wyjœciem poza tablice

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

		//ponbi¿ej (nie ruszaæ, ma byæ comment, patrz source WG
		//UWAGA - ODBLOKOWANIE!!!!
	//	for ( unsigned y = rect.Top; y <= (unsigned) rect.Bottom; y++ )
	//		for ( unsigned x = rect.Left; x <= (unsigned) rect.Right; x++ )
	//			m_cell_list[ y * m_size.x + x ].collision = collision;	

		//po analizie domniemujê... - co jest grane???
		//w tej pêtli okreœlam, czy dany obszar mapy jest zajêty...
		//czyli czy jest w tym obszarze kolizja?
	}

	//Metoda zwraca flagê, czy nast¹pi³a kolizja z jakimkolwiek obiektem z kontenera przechowuj¹cego obiekty klasy CCell
	bool CCollisionMap::GetCollisionByCell(const sf::Vector2i& collision) const
	{
		if (collision.x < 0 || collision.y < 0 || collision.x >= m_size.x || collision.y >= m_size.y)
			return true;
		return m_cell_list[CellToIndex(collision)].getCollision();
	}

	//Metoda zwraca flagê, czy nast¹pi³a kolizja z obiektem opisanym wspó³rzêdnymi skrajnych wierzcho³ków
	bool CCollisionMap::GetCollisionByRect(const sf::Vector2i &leftUp, const sf::Vector2i &rightDown) const
	{
		for (int y = leftUp.y; y <= rightDown.y; y++)
			for (int x = leftUp.x; x <= rightDown.x; x++)
				if (m_cell_list[y * m_size.x + x ].getCollision())
					return true;
		return false;
	}

	//Metoda zwraca gêstoœæ obiektów w obszarze klasy CCell
	int CCollisionMap::GetDensityByCell(const sf::Vector2i& cell)
	{
		int index = CellToIndex(cell);
		return (m_cell_list[index].getCollision() == true ? kUnaccessableTile : m_cell_list[index].getDensity());
	}

	//Metoda zwraca gêstoœæ obiektów opisanych wspó³rzêdnymi skrajnych wierzcho³ków
	int CCollisionMap::GetDensityByRect(const sf::Vector2i& leftUp, const sf::Vector2i& rightDown)
	{
		if (GetCollisionByRect(leftUp, rightDown) == true)
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

	//Metoda dodaje do kontenera wêze³ œcie¿ki
	void CCollisionMap::AddPath(const CPath * path)
	{
		ModifyPath(path, m_enemy_density);
	}

	//Metoda usuwa z kontenera wêze³ œcie¿ki
	void CCollisionMap::RemovePath(const CPath * path)
	{
		ModifyPath(path, -m_enemy_density);
	}

	//Metoda modyfikuje œci¿kê
	void CCollisionMap::ModifyPath(const CPath* path, int delta)
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

	//Metoda znajduje œcie¿kê
	bool CCollisionMap::FindPath(
		const sf::Vector2f & start,
		const sf::Vector2f & goal,
		const sf::Vector2f & physicalSize,
		CPath ** path)
	{
		//return CPathFinder().FindPath(start, goal, physicalSize, path);
		return false; ///atrapa...
	}

	//Metoda zwraca pozycjê kafla dla danych wspó³rzêdnych globalnych
	sf::Vector2i CCollisionMap::GetCellByCoords(const sf::Vector2f& point) 
	{ 
		return sf::Vector2i
			( 
				maths::ClampInt((int)(point.x * m_cell_per_tile.x ), 0, m_size.x-1),
				maths::ClampInt((int)(point.y * m_cell_per_tile.y ), 0, m_size.y-1) 
			);
	}

	//Metoda zwraca wspó³rzêdne globalne dla danego kafla
	sf::Vector2f CCollisionMap::GetCoordsByCell( const sf::Vector2i& cell )
	{
		return sf::Vector2f
			( 
				(float)cell.x * m_single_cell_size.x, 
				(float)cell.y * m_single_cell_size.y
			);
	}

	//Metoda zamienia rozmiar w iloœæ zajmowanych pol
	sf::Vector2i CCollisionMap::ConvertSizeToCells(const sf::Vector2f & size)
	{
		return sf::Vector2i
			(
				static_cast<int>(size.x / m_single_cell_size.x),
				static_cast<int>(size.y / m_single_cell_size.y)
			);
	}

	//Metoda dynamicznie aktalizuje regiony mapy
	void CCollisionMap::UpdateRegions()
	{
	    //CDynamicRegionsGenerator regionsGenerator(m_size, sf::Vector2i(kRegionSize, kRegionSize));
	    //regionsGenerator.GenerateRegions(m_cell_list, m_region_list);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDynamicRegion
	CDynamicRegion *CCollisionMap::GetRegionByCell(const sf::Vector2i &cell)
	{
		int regionId = m_cell_list.at(CellToIndex((cell))).getRegionId();

		for (std::vector<CDynamicRegion*>::const_iterator it = m_region_list.begin(); it != m_region_list.end(); ++it)
		{
			if ((*it)->GetRegionID() == regionId)
		        return *it;
		}
		return NULL;
	}
}//namespace mapengine
