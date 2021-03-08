/*
 ____________________________________
| CRand.h - definicja klasy.         |
| Jack Flower April 2013.            |
|____________________________________|

*/

/// Algorytm pseudolosowy opracowany przez demoscenowa grupe RGBA
/// Szybki i bardzo dobry (23 losowe bity), 4x szybszy od rand()/MAX_RAND itp.
/// http://rgba.scenesp.org/iq/computer/articles/sfrand/sfrand.htm


#ifndef H_RAND_JACK
#define H_RAND_JACK

#include "../Singleton/Singleton.h"
#include <cstdlib>

#define gRandom CRandom::GetSingleton()

///
///Klasa reprezentuj�ca generator liczb pseudolosowych
///
class CRandom : public Singleton<CRandom>
{
public:

	///
	///Konstruktor
	///
	CRandom();

	///
	///Destruktor
	///
	~CRandom();

	///
	///Metoda inicjuje ziarno dla generatora liczb pseudolosowych
	///
	///@param seed - ziarno dla generatora liczb pseudolosowych
	///
    void Seed(unsigned seed);

	///
	///Metoda zwraca warto�� pseudolosow� z zakresu od -1 do 1
	///
    float Rndnf();
    
	///
	///Metoda zwraca warto�� pseudolosow� z zakresu od 0 do 1
	///
    float Rndf();

	///
	///Metoda zwraca warto�� pseudolosow� z zakresu od 0 do 1, zbli�on� do parametru 
	///
	float Rndf(float most_probabled);
    
	///
	///Metoda zwraca warto�� pseudolosow� z zakresu podanego w parametrach
	///
	///@param begin - warto�� pocz�tkowa zakresu
	///
	///@param end - warto�� ko�cowa zakresu
	///
    float Rndf(float begin, float end);

	///
    ///Metoda zwraca warto�� pseudolosow� z zakresu od 0 do RAND_MAX
	///
    int Rnd();

	///
	///Metoda zwraca warto�� pseudolosow� z zakresu od min do max
	///
	///@param min - warto�� minimalna zakresu
	///
	///@param max - warto�� maksymalna zakresu
	///
    int Rnd(unsigned min, unsigned max);

private:

	unsigned m_seed;	//ziarno losowania

};

#endif //H_RAND_JACK
