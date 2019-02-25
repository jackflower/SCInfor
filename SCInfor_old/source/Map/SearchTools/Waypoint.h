//  _____________________________________
// | Waypoint.h - class definition       |
// | Jack Flower February 2012           |
// |_____________________________________|
//

#ifndef H_WAYPOINT_JACK
#define H_WAYPOINT_JACK

#include <SFML/System/Vector2.hpp>
#include <vector>

///
///Klasa reprezentuje abstrakcyjny węzeł świata
///
class Waypoint
{

protected:

	///
	///Konstruktor domyślny (protected)
	///
	Waypoint();

	///
	///Konstruktor parametryczny (protected)
	///
	///@param cost_from_start - koszt dojścia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param parent - wskaźniak na węzeł rodzicielski
	///
	Waypoint(int cost_from_start, int cost_to_goal, Waypoint* parent);

public:

	///
	///Destruktor wirtualny
	///
    virtual ~Waypoint();
    
	///
	///Metoda zwraca koszt dojścia do tego waypointa (node)
	///
	int getCostFromStart() const;
	
	///
	///Metoda ustawia koszt dojścia do tego waypointa (node)
	///
	///@param cost_from_start - dojścia do tego waypointa (node)
	///
	void setCostFromStart(int cost_from_start);

	///
	///Metoda zwraca szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	int getTotalCost() const;

	///
	///Metoda ustawia szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param cost_from_start - koszt dojścia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	void setTotalCost(int cost_from_start, int cost_to_goal);

	///
	///Metoda zwraca wskaźnik na węzeł rodzica
	///
	const Waypoint *getParent() const;

	///
	///Metoda ustawia wskaźnik na węzeł rodzica
	///
	///@param *parent - wskaźnik na węzeł rodzica
	///
	void setParent(Waypoint *parent);

	///
	///Metoda zwraca flagę, czy lista jest otwarta
	///
	bool isOnOpen() const;

	///
	///Metoda ustawia flagę, czy lista jest otwarta
	///
	///@param is_on_open - flagę, czy lista ma być otwarta
	///
	void setOnOpen(bool is_on_open);

	///
	///Metoda zwraca flagę, czy lista jest zamknięta
	///
	bool isOnClosed() const;

	///
	///Metoda ustawia flagę, czy lista jest zamknięta
	///
	///@param is_on_closed - flagę, czy lista ma być zamknięta
	///
	void setOnClosed(bool is_on_closed);
	
	///
	///Metoda aktualizuje obiekt (node)
	///
	///@param cost_from_start - koszt dojścia do tego waypointa (node)
	///
	///@param cost_to_goal - szacowany koszt do celu (koszt + heurystyczna ocena)
	///
	///@param parent - węzeł rodzicielski
	///
    void update(int cost_from_start, int cost_to_goal, Waypoint *parent);

	///
	///Metoda zwraca flagę, czy dany waypoint (node) jest użyty podczas danego szukania
	///
	bool isInUse() const;

	///
	///Metoda ustawia flaga - dany waypoint (node) nie jest używany podczas danego szukania
	///
	void clear();
    
	///
	///Operator porównania z innym waypoint'em (node)
	///
	///@param other - stała referencja na obiekt klasy Waypoint
	///
    bool operator==(const Waypoint & other);

	///
	///Wirtualna metoda zwraca unikalny identyfikator tego waypointa (node)
	///
    virtual int getHash() const = 0;

	///
	///Wirtualna abstrakcyjna metoda zwraca z wektora waypoint (node) sąsiadujący
	///
    virtual std::vector< Waypoint * > getNeighbours() const = 0;
    
	///
	///Wirtualna abstrakcyjna metoda zwraca z wektora wskaźnik clon waypointa (node)
	///
    virtual Waypoint *clone() const = 0;


private:

	int m_cost_from_start; //Koszt dojścia do tego waypointa (node)
    int m_cost_to_goal; //Szacowany koszt do celu (koszt + heurystyczna ocena)
    Waypoint *m_parent; //Waypoint (node) - rodzicielski węzeł, z którego tu przyszliśmy
    bool m_is_on_open; //Flaga, czy waypoint (node) jest na liście open
    bool m_is_on_closed; //Flaga, czy waypoint (node) jest na liście closed
    bool m_is_in_use; //Flaga, czy dany waypoint (node) jest użyty podczas danego szukania
					  //Położenie węzła (pewna reprezentacja położenia)

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
//	bool operator()(const Waypoint * waypoint) const { return m_index == waypoint->GetIndex(); }
//
//private:
//	T m_index;
//};

#endif //H_WAYPOINT_JACK
