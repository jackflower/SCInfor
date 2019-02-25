//  _________________________________________
// | CollisionMap.cpp - class implementation |
// | Jack Flower July 2013                   |
// |_________________________________________|
//


#include "DynamicRegionsGenerator.h"
#include "DynamicRegion.h"
#include <algorithm>

namespace mapengine
{
	RTTI_IMPL_NOPARENT(DynamicRegionsGenerator);

	int DynamicRegionsGenerator::mLastRegionID = 0;

	//Kostruktor
	DynamicRegionsGenerator::DynamicRegionsGenerator(const sf::Vector2i & map_size, const sf::Vector2i & region_size)
	:
		m_map_size(map_size),
		m_region_size(region_size),
		m_last_point_checked(0, 0),
		m_open_List(),
		m_link_list(),
		p_cell_list(NULL),
		p_region_list(NULL)
	{
	}

	//Destruktor
	DynamicRegionsGenerator::~DynamicRegionsGenerator()
	{
		m_map_size.x = 0;
		m_map_size.y = 0;
		m_region_size.x = 0;
		m_region_size.y = 0;
		m_last_point_checked.x = 0;
		m_last_point_checked.y = 0;
		//m_open_List
		//m_link_list
		//p_cell_list
		//p_region_list
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string DynamicRegionsGenerator::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda generuje regiony
	void DynamicRegionsGenerator::GenerateRegions(std::vector<Cell> & cellList, std::vector<DynamicRegion*> & regionList)
	{   
		p_cell_list = &cellList;
		p_region_list = &regionList;
		m_last_point_checked = sf::Vector2i(0, 0);
		m_open_List.clear();
	    
		m_last_point_checked = findNextStartingPoint();
		while (m_last_point_checked != sf::Vector2i(-1, -1))
		{
			fillRegion(m_last_point_checked);
			m_last_point_checked = findNextStartingPoint();
		}
	    
		//     FILE * reg = fopen("regions.raw", "wb");
		//     FILE * col = fopen("collisions.raw", "wb");
		//     for (int y = 0; y < m_map_size.y; ++y)
		//     {
		//         for (int x = 0; x < m_map_size.x; ++x)
		//         {
		//             char a = 1, b = 0;
		//             fwrite(&(p_cell_list->at(y * m_map_size.x + x).regionId), sizeof(char), 1, reg);
		//             fwrite((p_cell_list->at(y * m_map_size.x + x).collision ? &a : &b), sizeof(char), 1, col);
		//         }
		//     }
		//     fclose(reg);
		//     fclose(col);
		//     
		//     std::ofstream out("links.txt");
		//     for (unsigned int i = 0; i < p_region_list->size(); ++i)
		//     {
		//         out << (*p_region_list->at(i)) << std::endl;
		//     }    
	    
		p_cell_list = NULL;
		p_region_list = NULL;
	}

	//Metoda zjaduje następny punkt startowy
	const sf::Vector2i DynamicRegionsGenerator::findNextStartingPoint() const
	{
		for (int y = m_last_point_checked.y; y < m_map_size.y; ++y)
		{
			for (int x = m_last_point_checked.x; x < m_map_size.x; ++x)
			{
				int offset = y * m_map_size.x + x;
				if (p_cell_list->at(offset).getCollision() == false && //jeśli nie ma kolizji
					p_cell_list->at(offset).getRegionId() == 0)		//i identyfikator jest wstępnie wyzerowny
				{
					return sf::Vector2i(x, y);//zwracamy wektor współrzędnych
				}
			}
		}
		return sf::Vector2i(-1, -1);
	}

	//Metoda tworzy połączenie pomiędzy regionami
	void DynamicRegionsGenerator::generateLinks(int region, DynamicRegion* newRegion)
	{
		std::pair< LinkList::iterator, LinkList::iterator > range = m_link_list.equal_range(region);
		for (LinkList::iterator it = range.first; it != range.second; ++it)
		{
			newRegion->addNeighbour(findRegion((*it).second));
		}
	}

	//Metoda dokonuje konwersji pozycji na region
	int DynamicRegionsGenerator::positionToRegion(const sf::Vector2i& position) const
	{
		return (position.y / m_region_size.y) * ((m_map_size.x / m_region_size.x) + 1) + 
			   (position.x / m_region_size.x);
	}

	//Metoda tworzy obiekt klasy DynamicRegion - węzeł grafu
	void DynamicRegionsGenerator::createRegion(int region, int regionID)
	{
		DynamicRegion * newRegion = findRegion(regionID);
		if (newRegion == NULL)
		{
			newRegion = new DynamicRegion(regionID);
			p_region_list->push_back(newRegion);
		}

		generateLinks(region, newRegion);
	}

	//Metoda sprawdza, czy dany węzeł powinien być odwiedzany
	bool DynamicRegionsGenerator::shouldBeVisited(const sf::Vector2i& position) const
	{
		//jeśli znajdujemy się na mapie
		if (position.x >= 0 && position.x < m_map_size.x &&
			position.y >= 0 && position.y < m_map_size.y)
		{
			//wyliczamy indeks, pod którym zapiszemy informację o identyfikatorze i kolizji
			int cellIndex = position.y * m_map_size.x + position.x;
			return (p_cell_list->at(cellIndex).getRegionId() == 0 &&
				p_cell_list->at(cellIndex).getCollision() == false);
		}
		return false;
	}

	//Metoda wypełnia graf węzłami począwszy od zadanego punktu
	void DynamicRegionsGenerator::fillRegion(const sf::Vector2i & starting_point)
	{    
		m_open_List[positionToRegion(starting_point)].push_back(starting_point);

		while (!m_open_List.empty())
		{
			int currentRegion = m_open_List.begin()->first;
			createRegion(currentRegion, ++mLastRegionID);
	        
			//czy dany region ma jeszcze jakieś punkty na "open" liście?
			while (m_open_List[currentRegion].empty() == false)
			{
				//pobierz pierwszy punkt i usun go z listy
				sf::Vector2i currentCell = m_open_List[currentRegion].front();
				m_open_List[currentRegion].erase(m_open_List[currentRegion].begin());

				if (shouldBeVisited(currentCell) == true)
				{
					findRegion(mLastRegionID)->addCell(currentCell);
					p_cell_list->at(currentCell.y * m_map_size.x + currentCell.x).setRegionId(mLastRegionID);

					processPoint(currentCell, sf::Vector2i(-1, 0));
					processPoint(currentCell, sf::Vector2i(-1,-1));
					processPoint(currentCell, sf::Vector2i( 0,-1));
					processPoint(currentCell, sf::Vector2i( 1,-1));
					processPoint(currentCell, sf::Vector2i( 1, 0));
					processPoint(currentCell, sf::Vector2i( 1, 1));
					processPoint(currentCell, sf::Vector2i( 0, 1));
					processPoint(currentCell, sf::Vector2i(-1, 1));
				}
			}
			m_open_List.erase(m_open_List.find(currentRegion));
		}
	}

	//Metoda zwraca wskaźnik na węzeł grafu na podstawie podanego identyfikatora
	DynamicRegion *DynamicRegionsGenerator::findRegion(int regionID)
	{
		for (std::vector<DynamicRegion*>::const_iterator it = p_region_list->begin(); it != p_region_list->end(); ++it)
		{
			if ((*it)->getRegionID() == regionID)
				return *it;
		}
		return NULL;
	}

	//Metoda przetwarza punkty wokół danego węzła
	void DynamicRegionsGenerator::processPoint(const sf::Vector2i & source, const sf::Vector2i & offset)
	{
		sf::Vector2i point = source + offset;
		if (shouldBeVisited(point) == true)
		{
			int sourceRegion = positionToRegion(source);
			int targetRegion = positionToRegion(point);
	        
			m_open_List[targetRegion].push_back(point);
			if (sourceRegion != targetRegion)
				m_link_list.insert(std::make_pair(targetRegion, mLastRegionID));
		}
	}
}//namespace mapengine
