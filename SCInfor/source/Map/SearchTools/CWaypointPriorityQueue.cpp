/*
 ___________________________________________________
| CWaypointPriorityQueue.cpp - implementacja klasy. |
| SCI - by Jack Flower February 2012.               |
|___________________________________________________|

*/

#include "CWaypointPriorityQueue.h"

//Metoda zwraca wskaŸnik na CWaypoint o najni¿szym ³¹cznym koszcie dotarcia do celu (pamiêtaæ o zniszczeniu tego obiektu)
CWaypoint * CWaypointPriorityQueue::Pop()
{
	//Pobieramy wêze³ z pocz¹tku kopca - (potencjalnie) ma najni¿szy ³¹czny koszt
    CWaypoint * waypoint = m_heap.front();
	
	//Przenosimy teraz ten wêze³ z pocz¹tku kopca do po³o¿enia N (na "koniec") w kopcu
	//i sortujemy kopiec, aby <vector> znowy posiada³ swoje w³aœciwoœci (kopca)
	//(STL nie przyjmuje za³o¿eñ co do danych i nie chce z racji tego, ¿e jest to <vector>
	//zmieniaæ swojego rozmiaru jako kontenera)
    std::pop_heap(m_heap.begin(), m_heap.end(), CWaypointPriorityQueue::CTotalCostGreater());
	
	//Zdejmujemy z koñca ten wêze³, na którym nam zale¿a³o - (potencjalnie) ma najni¿szy ³¹czny koszt
	//W rzeczywstoœci zostanie usuniêty ostatni element kopca
	//(teraz kopiec jest posortowany dla pozycji od 1 do N)
    m_heap.pop_back();

	//Zwracamy zatem wskaŸnik na obiekt waypoint z wektora
    return waypoint;
}

//Metoda dodaje wskaŸnik na obiekt CWaypoint i wstawia go na odpowiednie miejsce kolejki
void CWaypointPriorityQueue::Push(CWaypoint * waypoint)
{
	//£¹czny czas  = 0(log n)
	//Umieszczamy wêze³ na koñcu wektora (kopiec jest teraz nieposortowany)
	//Zale¿y nam na tym, aby dodaj¹c do kolejki priorytetowej (kopca) wêze³,
	//zosta³ on ju¿ na tym etapie umieszczony na swoim miejscu (posortowana struktura kopca)
    m_heap.push_back(waypoint);

	//Sortujemy nowy element w kopcu, aby <vector> znowy posiada³ swoje w³aœciwoœci (kopca)
	//(STL nie przyjmuje za³o¿eñ co do danych i nie chce z racji tego, ¿e jest to <vector>
	//zmieniaæ swojego rozmiaru jako kontenera)
    std::push_heap(m_heap.begin(), m_heap.end(), CWaypointPriorityQueue::CTotalCostGreater());
}

//Metoda aktualizuje dany waypoint przesuwaj¹c go w kolejce je¿eli potrzeba
void CWaypointPriorityQueue::update(CWaypoint * waypoint)
{
	//Przechodzimy przez kopiec i znajdujemy wêze³ wymagaj¹cy uaktualnienia
    for (Heap::iterator it = m_heap.begin(); it != m_heap.end(); ++it)
    {
        if ((*it)->GetHash() == waypoint->GetHash())
        {
			//Jeœli znaleziono wêze³, nastêpuje ponowne posortowanie kopca od tego miejsca
			//(poniewa¿ ³¹czna wartoœæ zosta³a zmieniona)
            std::push_heap(m_heap.begin(), it + 1, CWaypointPriorityQueue::CTotalCostGreater());
            return;
        }
    }
}

//Metoda zwalnia obiekty z wektora i zajmowan¹ przez nie pamiêæ
void CWaypointPriorityQueue::ReleaseQueue()
{
	if(!m_heap.empty())//kontener nie jest pusty
	{
		for (Heap::iterator it = m_heap.begin(); it != m_heap.end(); it++)
		{
			(*it) = NULL;
				delete (*it);
		}
	}
		m_heap.clear(); 
}

//Destruktor wirtualny
CWaypointPriorityQueue::~CWaypointPriorityQueue()
{
	ReleaseQueue();
}
