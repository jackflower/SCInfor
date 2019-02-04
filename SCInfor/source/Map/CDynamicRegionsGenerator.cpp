//  __________________________________________
// | CCollisionMap.cpp - class implementation |
// | Jack Flower July 2013                    |
// |__________________________________________|
//


#include "CDynamicRegionsGenerator.h"
#include "CDynamicRegion.h"
#include <algorithm>
//#include <cstdio>
//#include <fstream>

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CDynamicRegionsGenerator);

	int CDynamicRegionsGenerator::mLastRegionID = 0;

	//Kostruktor
	CDynamicRegionsGenerator::CDynamicRegionsGenerator(const sf::Vector2i & map_size, const sf::Vector2i & region_size)
	:
		m_map_size				(map_size),
		m_region_size			(region_size),
		m_last_point_checked	(0, 0),
		m_open_List				(),
		m_link_list				(),
		p_cell_list				(NULL),
		p_region_list			(NULL)
	{
	}

	//Destruktor
	CDynamicRegionsGenerator::~CDynamicRegionsGenerator()
	{
		m_map_size.x 			= 0;
		m_map_size.y 			= 0;
		m_region_size.x			= 0;
		m_region_size.y			= 0;
		m_last_point_checked.x	= 0;
		m_last_point_checked.y	= 0;
		//m_open_List			not edit
		//m_link_list			not edit
		//p_cell_list			not edit
		//p_region_list			not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CDynamicRegionsGenerator::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda generuje regiony
	void CDynamicRegionsGenerator::GenerateRegions(std::vector<CCell>& cellList, std::vector<CDynamicRegion*> & regionList)
	{   
		p_cell_list = &cellList;
		p_region_list = &regionList;
		m_last_point_checked = sf::Vector2i(0, 0);
		m_open_List.clear();
	    
		m_last_point_checked = FindNextStartingPoint();
		while (m_last_point_checked != sf::Vector2i(-1, -1))
		{
			FillRegion(m_last_point_checked);
			m_last_point_checked = FindNextStartingPoint();
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

	//Metoda zjaduje nastêpny punkt startowy
	const sf::Vector2i CDynamicRegionsGenerator::FindNextStartingPoint() const
	{
		for (int y = m_last_point_checked.y; y < m_map_size.y; ++y)
		{
			for (int x = m_last_point_checked.x; x < m_map_size.x; ++x)
			{
				int offset = y * m_map_size.x + x;
				if (p_cell_list->at(offset).getCollision() == false && //jeœli nie ma kolizji
					p_cell_list->at(offset).getRegionId() == 0)		//i identyfikator jest wstêpnie wyzerowny
				{
					return sf::Vector2i(x, y);//zwracamy wektor wspó³rzêdnych
				}
			}
		}
		return sf::Vector2i(-1, -1);
	}

	//Metoda tworzy po³¹czenie pomiêdzy regionami
	void CDynamicRegionsGenerator::GenerateLinks(int region, CDynamicRegion* newRegion)
	{
		std::pair< LinkList::iterator, LinkList::iterator > range = m_link_list.equal_range(region);
		for (LinkList::iterator it = range.first; it != range.second; ++it)
		{
			newRegion->AddNeighbour(FindRegion((*it).second));
		}
	}

	//Metoda dokonuje konwersji pozycji na region
	int CDynamicRegionsGenerator::PositionToRegion(const sf::Vector2i& position) const
	{
		return (position.y / m_region_size.y) * ((m_map_size.x / m_region_size.x) + 1) + 
			   (position.x / m_region_size.x);
	}

	//Metoda tworzy obiekt klasy CDynamicRegion - wêze³ grafu
	void CDynamicRegionsGenerator::CreateRegion(int region, int regionID)
	{
		CDynamicRegion * newRegion = FindRegion(regionID);
		if (newRegion == NULL)
		{
			newRegion = new CDynamicRegion(regionID);
			p_region_list->push_back(newRegion);
		}

		GenerateLinks(region, newRegion);
	}

	//Metoda sprawdza, czy dany wêze³ powinien byæ odwiedzany
	bool CDynamicRegionsGenerator::ShouldBeVisited(const sf::Vector2i& position) const
	{
		//jeœli znajdujemy siê na mapie
		if (position.x >= 0 && position.x < m_map_size.x &&
			position.y >= 0 && position.y < m_map_size.y)
		{
			//wyliczamy indeks, pod którym zapiszemy informacjê o identyfikatorze i kolizji
			int cellIndex = position.y * m_map_size.x + position.x;
			return (p_cell_list->at(cellIndex).getRegionId() == 0 &&
				p_cell_list->at(cellIndex).getCollision() == false);
		}
		return false;
	}

	//Metoda wype³nia graf wêz³ami pocz¹wszy od zadanego punktu
	void CDynamicRegionsGenerator::FillRegion(const sf::Vector2i & starting_point)
	{    
		m_open_List[PositionToRegion(starting_point)].push_back(starting_point);

		while (!m_open_List.empty())
		{
			int currentRegion = m_open_List.begin()->first;
			CreateRegion(currentRegion, ++mLastRegionID);
	        
			//czy dany region ma jeszcze jakieœ punkty na "open" liœcie?
			while (m_open_List[currentRegion].empty() == false)
			{
				//pobierz pierwszy punkt i usun go z listy
				sf::Vector2i currentCell = m_open_List[currentRegion].front();
				m_open_List[currentRegion].erase(m_open_List[currentRegion].begin());

				if (ShouldBeVisited(currentCell) == true)
				{
					FindRegion(mLastRegionID)->AddCell(currentCell);
					p_cell_list->at(currentCell.y * m_map_size.x + currentCell.x).setRegionId(mLastRegionID);

					ProcessPoint(currentCell, sf::Vector2i(-1, 0));
					ProcessPoint(currentCell, sf::Vector2i(-1,-1));
					ProcessPoint(currentCell, sf::Vector2i( 0,-1));
					ProcessPoint(currentCell, sf::Vector2i( 1,-1));
					ProcessPoint(currentCell, sf::Vector2i( 1, 0));
					ProcessPoint(currentCell, sf::Vector2i( 1, 1));
					ProcessPoint(currentCell, sf::Vector2i( 0, 1));
					ProcessPoint(currentCell, sf::Vector2i(-1, 1));
				}
			}
			m_open_List.erase(m_open_List.find(currentRegion));
		}
	}

	//Metoda zwraca wskaŸnik na wêze³ grafu na podstawie podanego identyfikatora
	CDynamicRegion * CDynamicRegionsGenerator::FindRegion(int regionID)
	{
		for (std::vector<CDynamicRegion*>::const_iterator it = p_region_list->begin(); it != p_region_list->end(); ++it)
		{
			if ((*it)->GetRegionID() == regionID)
				return *it;
		}
		return NULL;
	}

	//Metoda przetwarza punkty wokó³ danego wêz³a
	void CDynamicRegionsGenerator::ProcessPoint(const sf::Vector2i & source, const sf::Vector2i & offset)
	{
		sf::Vector2i point = source + offset;
		if (ShouldBeVisited(point) == true)
		{
			int sourceRegion = PositionToRegion(source);
			int targetRegion = PositionToRegion(point);
	        
			m_open_List[targetRegion].push_back(point);
			if (sourceRegion != targetRegion)
				m_link_list.insert(std::make_pair(targetRegion, mLastRegionID));
		}
	}
}//namespace mapengine
