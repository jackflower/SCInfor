/*
 _____________________________________________
| CWaypointPriorityQueue.h - definicja klasy. |
| SCI - by Jack Flower February 2012.         |
|_____________________________________________|

*/

#ifndef _H_WAYPOINT_PRIORYTY_QUEUE_JACK
#define _H_WAYPOINT_PRIORYTY_QUEUE_JACK

#include "CWaypoint.h"
#include <vector>
#include <algorithm>

///
///Klasa reprezentuje kolejk� priorytetow� opart� na strukturze kopca do kolejkowania waypoint'ow
///Waypoint'y ustawiane s� w kolejno�ci rosn�cej wzgl�dem ��cznego kosztu dotarcia do celu
///
class CWaypointPriorityQueue
{
public:

	///
	///Metoda zwraca wska�nik na CWaypoint o najni�szym ��cznym koszcie dotarcia do celu (pami�ta� o zniszczeniu tego obiektu)
	///
    CWaypoint *Pop();
    
	///
	///Metoda dodaje wska�nik na obiekt CWaypoint i wstawia go na odpowiednie miejsce kolejki
	///
	///@param *waypoint - wska�nik na obiekt CWaypoint
	///
    void Push(CWaypoint *waypoint);

	///
	///Metoda aktualizuje dany waypoint przesuwaj�c go w kolejce je�eli potrzeba
	///
	///@param *waypoint - wska�nik na waypoint, kt�ry chcemy uaktualni�
	///
    void update(CWaypoint * waypoint);
    
	///
    ///Metoda sprawdza, czy kolejka jest pusta
    ///
    bool IsEmpty() const { return m_heap.empty(); }
    
    ///
	///Metoda czy�ci kolejk� - waypoint'y (node) nie s� niszczone
	///
	void Clear() { m_heap.clear(); }  

	///
	///Metoda zwalnia obiekty z wektora i zajmowan� przez nie pami��
	///
	void ReleaseQueue();

	///
	///Destruktor wirtualny
	///
	virtual ~CWaypointPriorityQueue();

private:
	class CTotalCostGreater;									//klasa do porownywania ��cznego kosztu do celu dw�ch waypointow
	typedef std::vector< CWaypoint * > Heap;					//definicja typu - wektor na wska�niki na obiekt CWaypoint
	Heap m_heap;												//wektor - optylizacja do funkcjonalno�ci kolejki piorytetowej opartej na kopcu
};

class CWaypointPriorityQueue::CTotalCostGreater
{
public:
	///
	///Operator sprawdza, kt�ry waypoint (node) ma wi�kszy koszt dotarcia do celu
	///zwraca (return true) je�eli koszt dotarcia do celu first jest wi�ekszy ni� second
	///Jest to wymagane przez STL do sortowania kolejki priorytetowej
	///(jest to wpisywane jako argument w funkcji kopca STL)
	bool operator()(CWaypoint * first, CWaypoint * second)
        { return first->GetTotalCost() > second->GetTotalCost(); }
};
#endif // _H_WAYPOINT_PRIORYTY_QUEUE_JACK
