/*
 ______________________________________
| CWaypoint.cpp - implementacja klasy. |
| SCI - by Jack Flower February 2012.  |
|______________________________________|

*/

#include "CWaypoint.h"

//Konstruktor domyœlny (protected)
CWaypoint::CWaypoint()
:
	m_cost_from_start	(0),
	m_cost_to_goal		(0),
	m_parent			(NULL),
	m_is_on_open		(false),
	m_is_on_closed		(false),
	m_is_in_use			(false)
{
}

//Konstruktor parametryczny (protected)
CWaypoint::CWaypoint(int cost_from_start, int cost_to_goal, CWaypoint * parent) 
:
	m_cost_from_start	(cost_from_start),
	m_cost_to_goal		(cost_to_goal),
    m_parent			(parent),
	m_is_on_open		(true),
	m_is_on_closed		(false),
	m_is_in_use			(false)
{
}

//Destruktor wirtualny
CWaypoint::~CWaypoint()
{
	m_cost_from_start	= 0;
	m_cost_to_goal		= 0;
	m_parent			= NULL;
	m_is_on_open		= false;
	m_is_on_closed		= false;
	m_is_in_use			= false;
}

//Metoda ustawia koszt dojœcia do tego waypointa (node)
void CWaypoint::SetCostFromStart(int cost_from_start)
{
	m_cost_from_start = cost_from_start;
}

//Metoda ustawia szacowany koszt do celu (koszt + heurystyczna ocena)
void CWaypoint::SetTotalCost(int cost_from_start, int cost_to_goal)
{
	m_cost_from_start = cost_from_start;
	m_cost_to_goal = cost_to_goal;
}

//Metoda ustawia wskaŸnik na wêze³ rodzica
void CWaypoint::SetParent(CWaypoint *parent)
{
	m_parent = parent;
}

//Metoda ustawia flagê, czy lista jest otwarta
void CWaypoint::SetOnOpen(bool is_on_open)
{
	m_is_on_open = is_on_open;
}

//Metoda ustawia flagê, czy lista jest zamkniêta
void CWaypoint::SetOnClosed(bool is_on_closed)
{
	m_is_on_closed = is_on_closed;
}

//Metoda aktualizuje obiekt (node)
void CWaypoint::update(int cost_from_start, int cost_to_goal, CWaypoint * parent)
{
	m_cost_from_start	= cost_from_start;
	m_cost_to_goal		= cost_to_goal;
	m_parent			= parent;
	m_is_on_open		= true;
	m_is_on_closed		= false;
	m_is_in_use			= true;
}

//Operator porównania z innym waypoint'em (node)
bool CWaypoint::operator==(const CWaypoint & other)
{
	return GetHash() == other.GetHash();
}

//Szablon klasy pomocniczej
//not to use...
//CWaypoint::CFindWaypointByIndex::CFindWaypointByIndex(const sf::Vector2i & index)
//:
//	mIndex(index)
//{
//}
//template < class T >
//bool CWaypoint::CFindWaypointByIndex::operator()(const CWaypoint * waypoint) const
//{
//	return m_index == waypoint->GetIndex();
//}
