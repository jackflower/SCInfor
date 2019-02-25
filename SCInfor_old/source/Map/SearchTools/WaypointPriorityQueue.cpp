//  __________________________________________________
// | WaypointPriorityQueue.cpp - class implementation |
// | SCI - by Jack Flower February 2012               |
// |__________________________________________________|
//

#include "WaypointPriorityQueue.h"


//Destruktor wirtualny
WaypointPriorityQueue::~WaypointPriorityQueue()
{
	releaseQueue();
}

//Metoda zwraca wskaźnik na Waypoint o najniższym łącznym koszcie dotarcia do celu (pamiętać o zniszczeniu tego obiektu)
Waypoint * WaypointPriorityQueue::pop()
{
	//Pobieramy węzeł z początku kopca - (potencjalnie) ma najniższy łączny koszt
    Waypoint * waypoint = m_heap.front();
	
	//Przenosimy teraz ten węzeł z początku kopca do położenia N (na "koniec") w kopcu
	//i sortujemy kopiec, aby <vector> znowy posiadał swoje właściwości (kopca)
	//(STL nie przyjmuje założeń co do danych i nie chce z racji tego, że jest to <vector>
	//zmieniać swojego rozmiaru jako kontenera)
    std::pop_heap(m_heap.begin(), m_heap.end(), WaypointPriorityQueue::CTotalCostGreater());
	
	//Zdejmujemy z końca ten węzeł, na którym nam zależało - (potencjalnie) ma najniższy łączny koszt
	//W rzeczywstości zostanie usunięty ostatni element kopca
	//(teraz kopiec jest posortowany dla pozycji od 1 do N)
    m_heap.pop_back();

	//Zwracamy zatem wskaźnik na obiekt waypoint z wektora
    return waypoint;
}

//Metoda dodaje wskaźnik na obiekt Waypoint i wstawia go na odpowiednie miejsce kolejki
void WaypointPriorityQueue::push(Waypoint *waypoint)
{
	//Łączny czas  = 0(log n)
	//Umieszczamy węzeł na końcu wektora (kopiec jest teraz nieposortowany)
	//Zależy nam na tym, aby dodając do kolejki priorytetowej (kopca) węzeł,
	//został on już na tym etapie umieszczony na swoim miejscu (posortowana struktura kopca)
    m_heap.push_back(waypoint);

	//Sortujemy nowy element w kopcu, aby <vector> znowy posiadał swoje właściwości (kopca)
	//(STL nie przyjmuje założeń co do danych i nie chce z racji tego, że jest to <vector>
	//zmieniać swojego rozmiaru jako kontenera)
    std::push_heap(m_heap.begin(), m_heap.end(), WaypointPriorityQueue::CTotalCostGreater());
}

//Metoda aktualizuje dany waypoint przesuwając go w kolejce jeżeli potrzeba
void WaypointPriorityQueue::update(Waypoint * waypoint)
{
	//Przechodzimy przez kopiec i znajdujemy węzeł wymagający uaktualnienia
    for (Heap::iterator it = m_heap.begin(); it != m_heap.end(); ++it)
    {
        if ((*it)->getHash() == waypoint->getHash())
        {
			//Jeśli znaleziono węzeł, następuje ponowne posortowanie kopca od tego miejsca
			//(ponieważ łączna wartość została zmieniona)
            std::push_heap(m_heap.begin(), it + 1, WaypointPriorityQueue::CTotalCostGreater());
            return;
        }
    }
}

//Metoda zwalnia obiekty z wektora i zajmowaną przez nie pamięć
void WaypointPriorityQueue::releaseQueue()
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
