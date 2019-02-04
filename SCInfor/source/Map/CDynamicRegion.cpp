//  _________________________________
// | CMap.cpp - class implementation |
// | Jack Flower June 2013           |
// |_________________________________|
//

#include "CDynamicRegion.h"
#include <algorithm>

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CDynamicRegion);

	//Konstruktor
	CDynamicRegion::CDynamicRegion(int region_id)
	:
		m_region_id		(region_id),
		m_neighbours	(),
		m_cells			(),
		m_center		(0, 0)
	{
	}

	//Destruktor
	CDynamicRegion::~CDynamicRegion()
	{
		m_region_id		= 0;
		//m_neighbours	not edit
		//m_cells		not edit
		//m_center		not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CDynamicRegion::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca identyfikator regionu
	int CDynamicRegion::GetRegionID() const
	{
		return m_region_id;
	}

	//Metoda dodaje do aktualnego wez³a wêze³ s¹siada
	void CDynamicRegion::AddNeighbour(CDynamicRegion* p_region)
	{
		if (std::find(m_neighbours.begin(), m_neighbours.end(), p_region) == m_neighbours.end())
		{
			m_neighbours.push_back(p_region);
			p_region->AddNeighbour(this);
		}
	}

	//Metoda dodaje wektor pozycji do wektora pozycji obiektu
	void CDynamicRegion::AddCell(const sf::Vector2i& cell)
	{
		bool add_cell = true;			//flaga, czy do wektora dodano now¹ pozycjê
		m_center = sf::Vector2i(0, 0);	//zerujemy wspó³rzêdne

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

	//Metoda zwraca wspó³rzêdne œrodka geometrycznego obiektu
	const sf::Vector2i& CDynamicRegion::GetCenter() const
	{
		return m_center;
	}

	//Metoda zwraca wektor przechowuj¹cy wêz³y przyleg³e do tego obiektu
	const DynamicRegionList& CDynamicRegion::GetNeighbours() const
	{
		return m_neighbours;
	}

	//ZaprzyjaŸniony operator
	std::ostream& operator<<(std::ostream & out, const CDynamicRegion& region)
	{
		out << region.GetRegionID() << ": ";
		for (unsigned int i = 0; i < region.m_neighbours.size(); ++i)
			out << region.m_neighbours.at(i)->GetRegionID() << " ";
		return out;
	}
}//namespace mapengine