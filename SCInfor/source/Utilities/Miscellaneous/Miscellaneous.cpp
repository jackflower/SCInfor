//  _____________________________________________
// | Miscellaneous.cpp - function implementation |
// | Jack Flower Juni 2015                       |
// |_____________________________________________|
//

#include "Miscellaneous.h"

namespace jackflower
{
	//Funkcja zwraca ilo�� cyfr podanej liczby
	short ile_cyfr(int liczba)
	{
		short i = 0;
		while(liczba != 0)
		{
			i++;
			liczba/=10;//bo zmiana pozycji cyfry wynika z tego, �e jest to system dziesi�tny
			int cc = 0;
		}
		return i;
	}
}//namespace jackflower