/*
 ___________________________________________________
| CWaypointPriorityQueue.cpp - implementacja klasy. |
| SCI - by Jack Flower February 2012.               |
|___________________________________________________|

*/

#include "CWaypointPriorityQueue.h"

//Metoda zwraca wska�nik na CWaypoint o najni�szym ��cznym koszcie dotarcia do celu (pami�ta� o zniszczeniu tego obiektu)
CWaypoint * CWaypointPriorityQueue::Pop()
{
	//Pobieramy w�ze� z pocz�tku kopca - (potencjalnie) ma najni�szy ��czny koszt
    CWaypoint * waypoint = m_heap.front();
	
	//Przenosimy teraz ten w�ze� z pocz�tku kopca do po�o�enia N (na "koniec") w kopcu
	//i sortujemy kopiec, aby <vector> znowy posiada� swoje w�a�ciwo�ci (kopca)
	//(STL nie przyjmuje za�o�e� co do danych i nie chce z racji tego, �e jest to <vector>
	//zmienia� swojego rozmiaru jako kontenera)
    std::pop_heap(m_heap.begin(), m_heap.end(), CWaypointPriorityQueue::CTotalCostGreater());
	
	//Zdejmujemy z ko�ca ten w�ze�, na kt�rym nam zale�a�o - (potencjalnie) ma najni�szy ��czny koszt
	//W rzeczywsto�ci zostanie usuni�ty ostatni element kopca
	//(teraz kopiec jest posortowany dla pozycji od 1 do N)
    m_heap.pop_back();

	//Zwracamy zatem wska�nik na obiekt waypoint z wektora
    return waypoint;
}

//Metoda dodaje wska�nik na obiekt CWaypoint i wstawia go na odpowiednie miejsce kolejki
void CWaypointPriorityQueue::Push(CWaypoint * waypoint)
{
	//��czny czas  = 0(log n)
	//Umieszczamy w�ze� na ko�cu wektora (kopiec jest teraz nieposortowany)
	//Zale�y nam na tym, aby dodaj�c do kolejki priorytetowej (kopca) w�ze�,
	//zosta� on ju� na tym etapie umieszczony na swoim miejscu (posortowana struktura kopca)
    m_heap.push_back(waypoint);

	//Sortujemy nowy element w kopcu, aby <vector> znowy posiada� swoje w�a�ciwo�ci (kopca)
	//(STL nie przyjmuje za�o�e� co do danych i nie chce z racji tego, �e jest to <vector>
	//zmienia� swojego rozmiaru jako kontenera)
    std::push_heap(m_heap.begin(), m_heap.end(), CWaypointPriorityQueue::CTotalCostGreater());
}

//Metoda aktualizuje dany waypoint przesuwaj�c go w kolejce je�eli potrzeba
void CWaypointPriorityQueue::update(CWaypoint * waypoint)
{
	//Przechodzimy przez kopiec i znajdujemy w�ze� wymagaj�cy uaktualnienia
    for (Heap::iterator it = m_heap.begin(); it != m_heap.end(); ++it)
    {
        if ((*it)->GetHash() == waypoint->GetHash())
        {
			//Je�li znaleziono w�ze�, nast�puje ponowne posortowanie kopca od tego miejsca
			//(poniewa� ��czna warto�� zosta�a zmieniona)
            std::push_heap(m_heap.begin(), it + 1, CWaypointPriorityQueue::CTotalCostGreater());
            return;
        }
    }
}

//Metoda zwalnia obiekty z wektora i zajmowan� przez nie pami��
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
