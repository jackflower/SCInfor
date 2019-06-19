//  _____________________________________
// | Waypoint.cpp - class implementation |
// | Jack Flower February 2012           |
// |_____________________________________|
//

#include "Waypoint.h"

//Konstruktor domyślny (protected)
Waypoint::Waypoint()
:
	m_cost_from_start{ 0 },
	m_cost_to_goal{ 0 },
	m_parent{ nullptr },
	m_is_on_open{ false },
	m_is_on_closed{ false },
	m_is_in_use{ false }
{
}

//Konstruktor parametryczny (protected)
Waypoint::Waypoint(int cost_from_start, int cost_to_goal, Waypoint *parent) 
:
	m_cost_from_start{ cost_from_start },
	m_cost_to_goal{ cost_to_goal },
	m_parent{ parent },
	m_is_on_open{ true },
	m_is_on_closed{ false },
	m_is_in_use{ false }
{
}

//Destruktor wirtualny
Waypoint::~Waypoint()
{
	m_cost_from_start = 0;
	m_cost_to_goal = 0;
	m_parent = nullptr;
	m_is_on_open = false;
	m_is_on_closed = false;
	m_is_in_use = false;
}

//Metoda zwraca koszt dojścia do tego waypointa (node)
int Waypoint::getCostFromStart() const
{
	return m_cost_from_start;
}

//Metoda ustawia koszt dojścia do tego waypointa (node)
void Waypoint::setCostFromStart(int cost_from_start)
{
	m_cost_from_start = cost_from_start;
}

//Metoda zwraca szacowany koszt do celu (koszt + heurystyczna ocena)
int Waypoint::getTotalCost() const
{
	return m_cost_from_start + m_cost_to_goal;
}

//Metoda ustawia szacowany koszt do celu (koszt + heurystyczna ocena)
void Waypoint::setTotalCost(int cost_from_start, int cost_to_goal)
{
	m_cost_from_start = cost_from_start;
	m_cost_to_goal = cost_to_goal;
}

//Metoda zwraca wskaźnik na węzeł rodzica
const Waypoint *Waypoint::getParent() const
{
	return m_parent;
}

//Metoda ustawia wskaźnik na węzeł rodzica
void Waypoint::setParent(Waypoint *parent)
{
	m_parent = parent;
}

//Metoda zwraca flagę, czy lista jest otwarta
bool Waypoint::isOnOpen() const
{ 
	return m_is_on_open;
}

//Metoda ustawia flagę, czy lista jest otwarta
void Waypoint::setOnOpen(bool is_on_open)
{
	m_is_on_open = is_on_open;
}

//Metoda zwraca flagę, czy lista jest zamknięta
bool Waypoint::isOnClosed() const
{
	return m_is_on_closed;
}

//Metoda ustawia flagę, czy lista jest zamknięta
void Waypoint::setOnClosed(bool is_on_closed)
{
	m_is_on_closed = is_on_closed;
}

//Metoda aktualizuje obiekt (node)
void Waypoint::update(int cost_from_start, int cost_to_goal, Waypoint * parent)
{
	m_cost_from_start = cost_from_start;
	m_cost_to_goal = cost_to_goal;
	m_parent = parent;
	m_is_on_open = true;
	m_is_on_closed = false;
	m_is_in_use = true;
}

//Metoda zwraca flagę, czy dany waypoint (node) jest użyty podczas danego szukania
bool Waypoint::isInUse() const
{
	return m_is_in_use;
}

//Metoda ustawia flaga - dany waypoint (node) nie jest używany podczas danego szukania
void Waypoint::clear()
{
	m_is_in_use = false;
}

//Operator porównania z innym waypoint'em (node)
bool Waypoint::operator==(const Waypoint & other)
{
	return getHash() == other.getHash();
}

//Szablon klasy pomocniczej
//not to use...
//Waypoint::CFindWaypointByIndex::CFindWaypointByIndex(const sf::Vector2i & index)
//:
//	mIndex(index)
//{
//}
//template < class T >
//bool Waypoint::CFindWaypointByIndex::operator()(const Waypoint * waypoint) const
//{
//	return m_index == waypoint->GetIndex();
//}
