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
///Klasa reprezentuje abstrakcyjny wêze³ œwiata
///
class CWaypoint
{
public:
	///
	///Destruktor wirtualny
	///
    virtual ~CWaypoint();
    
	///
	///Metoda zwraca koszt dojœcia do tego waypointa (node)
	///
	int GetCostFromStart() const { return m_cost_from_start; }
	
	///
	///Metoda ustawia koszt dojœcia do tego waypointa (node)
	///
	///@param cost_from_start - dojœcia do tego waypointa (node)
	///
	void SetCostFromStart(int cost_from_start);

	///
	///Metoda zwraca szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	int GetTotalCost() const { return m_cost_from_start + m_cost_to_goal; }

	///
	///Metoda ustawia szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param cost_from_start - koszt dojœcia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	void SetTotalCost(int cost_from_start, int cost_to_goal);

	///
	///Metoda zwraca wskaŸnik na wêze³ rodzica
	///
	const CWaypoint *GetParent() const{ return m_parent; }

	///
	///Metoda ustawia wskaŸnik na wêze³ rodzica
	///
	///@param *parent - wskaŸnik na wêze³ rodzica
	///
	void SetParent(CWaypoint *parent);

	///
	///Metoda zwraca flagê, czy lista jest otwarta
	///
	bool IsOnOpen() const { return m_is_on_open; }

	///
	///Metoda ustawia flagê, czy lista jest otwarta
	///
	///@param is_on_open - flagê, czy lista ma byæ otwarta
	///
	void SetOnOpen(bool is_on_open);

	///
	///Metoda zwraca flagê, czy lista jest zamkniêta
	///
	bool IsOnClosed() const { return m_is_on_closed; }

	///
	///Metoda ustawia flagê, czy lista jest zamkniêta
	///
	///@param is_on_closed - flagê, czy lista ma byæ zamkniêta
	///
	void SetOnClosed(bool is_on_closed);
	
	///
	///Metoda aktualizuje obiekt (node)
	///
	///@param cost_from_start - koszt dojœcia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param parent - wêze³ rodzicielski
	///
    void Update(int cost_from_start, int cost_to_goal, CWaypoint * parent);

	///
	///Metoda zwraca flagê, czy dany waypoint (node) jest u¿yty podczas danego szukania
	///
	bool IsInUse() const { return m_is_in_use; }

	///
	///Metoda ustawia flaga - dany waypoint (node) nie jest u¿ywany podczas danego szukania
	///
    void Clear() { m_is_in_use = false; }
    
	///
	///Operator porównania z innym waypoint'em (node)
	///
	///@param &other - referencja na obiekt klasy CWaypoint
	///
    bool operator==(const CWaypoint & other);

	///
	///Wirtualna metoda zwraca unikalny identyfikator tego waypointa (node)
	///
    virtual int GetHash() const = 0;

	///
	///Wirtualna metoda zwraca z wektora waypoint (node) s¹siaduj¹cy
	///
    virtual std::vector< CWaypoint * > GetNeighbours() const = 0;
    
	///
	///Wirtualna metoda zwraca z wektora wskaŸnik clon waypointa (node)
	///
    virtual CWaypoint * Clone() const = 0;
    
protected:
	
	///
	///Konstruktor domyœlny (protected)
	///
    CWaypoint();

	///
	///Konstruktor parametryczny (protected)
	///
	///@param cost_from_start - koszt dojœcia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param parent - wêze³ rodzicielski
	///
    CWaypoint(int cost_from_start, int cost_to_goal, CWaypoint * parent);

private:

	int			m_cost_from_start;	//Koszt dojœcia do tego waypointa (node)
    int			m_cost_to_goal;		//Szacowany koszt do celu (koszt + heurystyczna ocena)
    CWaypoint	*m_parent;			//Waypoint (node) - rodzicielski wêze³, z którego tu przyszliœmy
    bool		m_is_on_open;		//Flaga, czy waypoint (node) jest na liœcie open
    bool		m_is_on_closed;		//Flaga, czy waypoint (node) jest na liœcie closed
    bool		m_is_in_use;		//Flaga, czy dany waypoint (node) jest u¿yty podczas danego szukania
									//Po³o¿enie wêz³a (pewna reprezentacja po³o¿enia)

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
