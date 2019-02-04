/*
 ______________________________________
| CWaypoint.h - definicja klasy.       |
| SCI - by Jack Flower February 2012.  |
|______________________________________|

*/

#ifndef _H_WAYPOINT_JACK
#define _H_WAYPOINT_JACK

#include <SFML/System/Vector2.hpp>
#include <vector>

///
///Klasa reprezentuje abstrakcyjny w�ze� �wiata
///
class CWaypoint
{
public:
	///
	///Destruktor wirtualny
	///
    virtual ~CWaypoint();
    
	///
	///Metoda zwraca koszt doj�cia do tego waypointa (node)
	///
	int GetCostFromStart() const { return m_cost_from_start; }
	
	///
	///Metoda ustawia koszt doj�cia do tego waypointa (node)
	///
	///@param cost_from_start - doj�cia do tego waypointa (node)
	///
	void SetCostFromStart(int cost_from_start);

	///
	///Metoda zwraca szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	int GetTotalCost() const { return m_cost_from_start + m_cost_to_goal; }

	///
	///Metoda ustawia szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param cost_from_start - koszt doj�cia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	void SetTotalCost(int cost_from_start, int cost_to_goal);

	///
	///Metoda zwraca wska�nik na w�ze� rodzica
	///
	const CWaypoint *GetParent() const{ return m_parent; }

	///
	///Metoda ustawia wska�nik na w�ze� rodzica
	///
	///@param *parent - wska�nik na w�ze� rodzica
	///
	void SetParent(CWaypoint *parent);

	///
	///Metoda zwraca flag�, czy lista jest otwarta
	///
	bool IsOnOpen() const { return m_is_on_open; }

	///
	///Metoda ustawia flag�, czy lista jest otwarta
	///
	///@param is_on_open - flag�, czy lista ma by� otwarta
	///
	void SetOnOpen(bool is_on_open);

	///
	///Metoda zwraca flag�, czy lista jest zamkni�ta
	///
	bool IsOnClosed() const { return m_is_on_closed; }

	///
	///Metoda ustawia flag�, czy lista jest zamkni�ta
	///
	///@param is_on_closed - flag�, czy lista ma by� zamkni�ta
	///
	void SetOnClosed(bool is_on_closed);
	
	///
	///Metoda aktualizuje obiekt (node)
	///
	///@param cost_from_start - koszt doj�cia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param parent - w�ze� rodzicielski
	///
    void Update(int cost_from_start, int cost_to_goal, CWaypoint * parent);

	///
	///Metoda zwraca flag�, czy dany waypoint (node) jest u�yty podczas danego szukania
	///
	bool IsInUse() const { return m_is_in_use; }

	///
	///Metoda ustawia flaga - dany waypoint (node) nie jest u�ywany podczas danego szukania
	///
    void Clear() { m_is_in_use = false; }
    
	///
	///Operator por�wnania z innym waypoint'em (node)
	///
	///@param &other - referencja na obiekt klasy CWaypoint
	///
    bool operator==(const CWaypoint & other);

	///
	///Wirtualna metoda zwraca unikalny identyfikator tego waypointa (node)
	///
    virtual int GetHash() const = 0;

	///
	///Wirtualna metoda zwraca z wektora waypoint (node) s�siaduj�cy
	///
    virtual std::vector< CWaypoint * > GetNeighbours() const = 0;
    
	///
	///Wirtualna metoda zwraca z wektora wska�nik clon waypointa (node)
	///
    virtual CWaypoint * Clone() const = 0;
    
protected:
	
	///
	///Konstruktor domy�lny (protected)
	///
    CWaypoint();

	///
	///Konstruktor parametryczny (protected)
	///
	///@param cost_from_start - koszt doj�cia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param parent - w�ze� rodzicielski
	///
    CWaypoint(int cost_from_start, int cost_to_goal, CWaypoint * parent);

private:

	int			m_cost_from_start;	//Koszt doj�cia do tego waypointa (node)
    int			m_cost_to_goal;		//Szacowany koszt do celu (koszt + heurystyczna ocena)
    CWaypoint	*m_parent;			//Waypoint (node) - rodzicielski w�ze�, z kt�rego tu przyszli�my
    bool		m_is_on_open;		//Flaga, czy waypoint (node) jest na li�cie open
    bool		m_is_on_closed;		//Flaga, czy waypoint (node) jest na li�cie closed
    bool		m_is_in_use;		//Flaga, czy dany waypoint (node) jest u�yty podczas danego szukania
									//Po�o�enie w�z�a (pewna reprezentacja po�o�enia)

};

//Szablon klasy pomocniczej
//not to use...
//template < class T >
//class CFindWaypointByIndex
//{
//public:
//
//	CFindWaypointByIndex(const T & index)
//	:
//		m_index(index)
//		{
//		}
//	bool operator()(const CWaypoint * waypoint) const { return m_index == waypoint->GetIndex(); }
//
//private:
//	T m_index;
//};

#endif // _H_WAYPOINT_JACK
