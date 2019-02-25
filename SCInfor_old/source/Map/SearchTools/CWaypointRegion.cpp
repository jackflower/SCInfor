/*
 ____________________________________________
| CWaypointRegion.cpp - implementacja klasy. |
| SCI - by Jack Flower February 2012.        |
|____________________________________________|

*/

#include "CWaypointRegion.h"
//#include "../CDynamicRegion.h"

//Konstruktor (wyraüny - explicit)
CWaypointRegion::CWaypointRegion(CDynamicRegion * region)
:
	CWaypoint	(),
	m_region	(region)
{
}

//Konstruktor kopiujπcy
CWaypointRegion::CWaypointRegion(const CWaypointRegion & other)
:
	CWaypoint	(other),//Konstruktor kopiujπcy klasy bazowej
	m_region	(other.GetRegion())
{
}

//Destruktor wirtualny 
CWaypointRegion::~CWaypointRegion()
{
}

//Wirtualna metoda zwraca unikalny identyfikator tego waypointa (node)
int CWaypointRegion::GetHash() const
{
	return m_region->GetRegionID();
}

//Wirtualna metoda zwraca z wektora waypoint (node) sπsiadujπcy
std::vector< CWaypoint * > CWaypointRegion::GetNeighbours() const
{
	std::vector< CWaypoint * > result;

	typedef std::vector <CDynamicRegion*> DynamicRegionList;

	const DynamicRegionList neighbours = m_region->GetNeighbours();
	for (DynamicRegionList::const_iterator it = neighbours.begin(); it != neighbours.end(); ++it)
	{
		result.push_back(new CWaypointRegion(*it));
	}

	return result;
}

//Wirtualna metoda zwraca z wektora wskaünik clon waypointa (node)
CWaypoint * CWaypointRegion::Clone() const
{
	return new CWaypointRegion(*this);
}
