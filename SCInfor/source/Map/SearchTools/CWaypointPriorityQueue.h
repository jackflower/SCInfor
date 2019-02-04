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
///Klasa reprezentuje kolejkê priorytetow¹ opart¹ na strukturze kopca do kolejkowania waypoint'ow
///Waypoint'y ustawiane s¹ w kolejnoœci rosn¹cej wzglêdem ³¹cznego kosztu dotarcia do celu
///
class CWaypointPriorityQueue
{
public:

	///
	///Metoda zwraca wskaŸnik na CWaypoint o najni¿szym ³¹cznym koszcie dotarcia do celu (pamiêtaæ o zniszczeniu tego obiektu)
	///
    CWaypoint *Pop();
    
	///
	///Metoda dodaje wskaŸnik na obiekt CWaypoint i wstawia go na odpowiednie miejsce kolejki
	///
	///@param *waypoint - wskaŸnik na obiekt CWaypoint
	///
    void Push(CWaypoint *waypoint);

	///
	///Metoda aktualizuje dany waypoint przesuwaj¹c go w kolejce je¿eli potrzeba
	///
	///@param *waypoint - wskaŸnik na waypoint, który chcemy uaktualniæ
	///
    void update(CWaypoint * waypoint);
    
	///
    ///Metoda sprawdza, czy kolejka jest pusta
    ///
    bool IsEmpty() const { return m_heap.empty(); }
    
    ///
	///Metoda czyœci kolejkê - waypoint'y (node) nie s¹ niszczone
	///
	void Clear() { m_heap.clear(); }  

	///
	///Metoda zwalnia obiekty z wektora i zajmowan¹ przez nie pamiêæ
	///
	void ReleaseQueue();

	///
	///Destruktor wirtualny
	///
	virtual ~CWaypointPriorityQueue();

private:
	class CTotalCostGreater;									//klasa do porownywania ³¹cznego kosztu do celu dwóch waypointow
	typedef std::vector< CWaypoint * > Heap;					//definicja typu - wektor na wskaŸniki na obiekt CWaypoint
	Heap m_heap;												//wektor - optylizacja do funkcjonalnoœci kolejki piorytetowej opartej na kopcu
};

class CWaypointPriorityQueue::CTotalCostGreater
{
public:
	///
	///Operator sprawdza, który waypoint (node) ma wiêkszy koszt dotarcia do celu
	///zwraca (return true) je¿eli koszt dotarcia do celu first jest wiêekszy ni¿ second
	///Jest to wymagane przez STL do sortowania kolejki priorytetowej
	///(jest to wpisywane jako argument w funkcji kopca STL)
	bool operator()(CWaypoint * first, CWaypoint * second)
        { return first->GetTotalCost() > second->GetTotalCost(); }
};
#endif // _H_WAYPOINT_PRIORYTY_QUEUE_JACK
