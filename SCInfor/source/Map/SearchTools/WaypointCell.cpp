//  _________________________________________
// | WaypointCell.cpp - class implementation |
// | Jack Flower February 2012               |
// |_________________________________________|
//

#include "WaypointCell.h"
#include "../CMapManager.h"
#include "../CCollisionMap.h"

WaypointCell::WaypointCell(const sf::Vector2i & cell)
:
    Waypoint(),
	m_cell(cell)
{
}

WaypointCell::WaypointCell(const WaypointCell & other)
:
    Waypoint(other),
	m_cell(other.getCell())
{
}

WaypointCell::~WaypointCell()
{}

int WaypointCell::getHash() const
{
    return m_cell.y * 1024 + m_cell.x;    // TODO uzaleznic to od rozmiarow mapy
}

std::vector< Waypoint * > WaypointCell::getNeighbours() const
{
    std::vector< Waypoint * > result;  // TODO uwzglednic wielkosc potwora

    checkNeighbour(result, m_cell - sf::Vector2i( 1,  1));
    checkNeighbour(result, m_cell - sf::Vector2i( 1,  0));
    checkNeighbour(result, m_cell - sf::Vector2i( 1, -1));
    checkNeighbour(result, m_cell - sf::Vector2i( 0, -1));
    checkNeighbour(result, m_cell - sf::Vector2i(-1, -1));
    checkNeighbour(result, m_cell - sf::Vector2i(-1,  0));
    checkNeighbour(result, m_cell - sf::Vector2i(-1,  1));
    checkNeighbour(result, m_cell - sf::Vector2i( 0,  1));

    return result;
}

Waypoint * WaypointCell::clone() const
{
    return new WaypointCell(*this);
}

void WaypointCell::checkNeighbour(std::vector< Waypoint * > & neighbours, const sf::Vector2i neighbour) const
{
    if (gMapManager.GetCollisionMap()->GetCollisionByCell(neighbour) == false)
    {
        neighbours.push_back(new WaypointCell(neighbour));
    }
}
