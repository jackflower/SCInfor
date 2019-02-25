/*
 ____________________________________________
| CWaypointRegion.cpp - implementacja klasy. |
| SCI - by Jack Flower February 2012.        |
|____________________________________________|

*/

#include "CWaypointRegion.h"
//#include "../CDynamicRegion.h"

//Konstruktor (wyra�ny - explicit)
CWaypointRegion::CWaypointRegion(CDynamicRegion * region)
:
	CWaypoint	(),
	m_region	(region)
{
}

//Konstruktor kopiuj�cy
CWaypointRegion::CWaypointRegion(const CWaypointRegion & other)
:
	CWaypoint	(other),//Konstruktor kopiuj�cy klasy bazowej
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

//Wirtualna metoda zwraca z wektora waypoint (node) s�siaduj�cy
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

//Wirtualna metoda zwraca z wektora wska�nik clon waypointa (node)
CWaypoint * CWaypointRegion::Clone() const
{
	return new CWaypointRegion(*this);
}
