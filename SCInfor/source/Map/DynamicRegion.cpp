//  __________________________________________
// | DynamicRegion.cpp - class implementation |
// | Jack Flower June 2013                    |
// |__________________________________________|
//

#include "DynamicRegion.h"
#include <algorithm>

namespace mapengine
{
	RTTI_IMPL_NOPARENT(DynamicRegion);

	//Konstruktor
	DynamicRegion::DynamicRegion(int region_id)
	:
		m_region_id	(region_id),
		m_neighbours(),
		m_cells(),
		m_center(0, 0)
	{
	}

	//Destruktor
	DynamicRegion::~DynamicRegion()
	{
		m_region_id = 0;
		//m_neighbours
		//m_cells
		//m_center
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string DynamicRegion::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca identyfikator regionu
	int DynamicRegion::getRegionID() const
	{
		return m_region_id;
	}

	//Metoda dodaje do aktualnego wezła węzeł sąsiada
	void DynamicRegion::addNeighbour(DynamicRegion *p_region)
	{
		if (std::find(m_neighbours.begin(), m_neighbours.end(), p_region) == m_neighbours.end())
		{
			m_neighbours.push_back(p_region);
			p_region->addNeighbour(this);
		}
	}

	//Metoda dodaje wektor pozycji do wektora pozycji obiektu
	void DynamicRegion::addCell(const sf::Vector2i & cell)
	{
		bool add_cell = true;			//flaga, czy do wektora dodano nową pozycję
		m_center = sf::Vector2i(0, 0);	//zerujemy współrzędne

		for (std::vector<sf::Vector2i>::const_iterator it = m_cells.begin(); it != m_cells.end(); ++it)
		{
			m_center += *it;
			add_cell &= (*it != cell);
		}

		if (add_cell)
		{
			m_cells.push_back(cell);
			m_center += cell;
		}

		m_center /= static_cast< int >(m_cells.size());
	}

	//Metoda zwraca współrzędne środka geometrycznego obiektu
	const sf::Vector2i & DynamicRegion::getCenter() const
	{
		return m_center;
	}

	//Metoda zwraca wektor przechowujący węzły przyległe do tego obiektu
	const DynamicRegionList & DynamicRegion::getNeighbours() const
	{
		return m_neighbours;
	}

	//Zaprzyjaźniony operator
	std::ostream & operator<<(std::ostream & out, const DynamicRegion & region)
	{
		out << region.getRegionID() << ": ";
		for (unsigned int i = 0; i < region.m_neighbours.size(); ++i)
			out << region.m_neighbours.at(i)->getRegionID() << " ";
		return out;
	}
}//namespace mapengine
