//  _________________________________________
// | Waypoint.h - class definition           |
// | Jack Flower February 2012               |
// |_________________________________________|
//

#ifndef H_WAYPOINT_CELL_JACK
#define H_WAYPOINT_CELL_JACK

#include "Waypoint.h"
#include <SFML/System/Vector2.hpp>

class WaypointCell : public Waypoint
{
public:

    explicit WaypointCell(const sf::Vector2i & cell);
    WaypointCell(const WaypointCell & other);
    virtual ~WaypointCell();

    virtual int getHash() const;
    virtual std::vector<Waypoint*> getNeighbours() const;
    const sf::Vector2i & getCell() const    { return m_cell; }
    virtual Waypoint * clone() const;

private:

    void checkNeighbour(std::vector<Waypoint*> & neighbours, const sf::Vector2i neighbour) const;

    sf::Vector2i m_cell;

};
#endif //H_WAYPOINT_CELL_JACK
