//  __________________________________________________
// | WaypointPriorityQueue.h - class definition       |
// | SCI - by Jack Flower February 2012               |
// |__________________________________________________|
//

#ifndef _H_WAYPOINT_PRIORYTY_QUEUE_JACK
#define _H_WAYPOINT_PRIORYTY_QUEUE_JACK

#include "Waypoint.h"
#include <vector>
#include <algorithm>

///
///Klasa reprezentuje kolejkę priorytetową opartą na strukturze kopca do kolejkowania waypoint'ow
///Waypoint'y ustawiane są w kolejności rosnącej względem łącznego kosztu dotarcia do celu
///
class WaypointPriorityQueue
{
public:

	///
	///Destruktor wirtualny
	///
	virtual ~WaypointPriorityQueue();

	///
	///Metoda zwraca wskaźnik na Waypoint o najniższym łącznym koszcie dotarcia do celu (pamiętać o zniszczeniu tego obiektu)
	///
    Waypoint *pop();
    
	///
	///Metoda dodaje wskaźnik na obiekt Waypoint i wstawia go na odpowiednie miejsce kolejki
	///
	///@param *waypoint - wskaźnik na obiekt Waypoint
	///
    void push(Waypoint *waypoint);

	///
	///Metoda aktualizuje dany waypoint przesuwając go w kolejce jeżeli potrzeba
	///
	///@param *waypoint - wskaźnik na waypoint, który chcemy uaktualnić
	///
    void update(Waypoint *waypoint);
    
	///
    ///Metoda sprawdza, czy kolejka jest pusta
    ///
    bool isEmpty() const { return m_heap.empty(); }
    
    ///
	///Metoda czyści kolejkę - waypoint'y (node) nie są niszczone
	///
	void clear() { m_heap.clear(); }  

	///
	///Metoda zwalnia obiekty z wektora i zajmowaną przez nie pamięć
	///
	void releaseQueue();


private:
	class CTotalCostGreater; //klasa do porownywania łącznego kosztu do celu dwóch waypointow
	typedef std::vector<Waypoint*> Heap; //definicja typu - wektor na wskaźniki na obiekt Waypoint
	Heap m_heap; //wektor - optylizacja do funkcjonalności kolejki piorytetowej opartej na kopcu
};

class WaypointPriorityQueue::CTotalCostGreater
{
public:
	///
	///Operator sprawdza, który waypoint (node) ma większy koszt dotarcia do celu
	///zwraca (return true) jeżeli koszt dotarcia do celu first jest więekszy niż second
	///Jest to wymagane przez STL do sortowania kolejki priorytetowej
	///(jest to wpisywane jako argument w funkcji kopca STL)
	bool operator()(Waypoint * first, Waypoint * second)
        { return first->getTotalCost() > second->getTotalCost(); }
};
#endif // _H_WAYPOINT_PRIORYTY_QUEUE_JACK
