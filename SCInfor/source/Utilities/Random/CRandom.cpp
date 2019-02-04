/*
 ____________________________________
| CRandom.cpp - implementacja klasy. |
| Jack Flower April 2013.            |
|____________________________________|

*/

#include "CRandom.h"
#include "../MathFunctions/MathFunctions.h"
using namespace maths;

template<> CRandom * CSingleton<CRandom>::m_singleton = 0;

//Konstruktor
CRandom::CRandom()
:
	m_seed(1)
{
	srand(m_seed);
}

//Destruktor
CRandom::~CRandom()
{
	m_seed = 0;
}

//Metoda inicjuje ziarno dla generatora liczb pseudolosowych
void CRandom::Seed(unsigned seed)
{
	srand(m_seed = (unsigned) seed);
}

//Metoda zwraca wartoœæ pseudolosow¹ z zakresu od -1 do 1
float CRandom::Rndnf()
{
	return rand() / static_cast<float>((RAND_MAX / 2)) - 1.f;
}

//Metoda zwraca wartoœæ pseudolosow¹ z zakresu od 0 do 1
float CRandom::Rndf()
{
	return rand() / static_cast<float> (RAND_MAX);
}

//Metoda zwraca wartoœæ pseudolosow¹ z zakresu od 0 do 1, zbli¿on¹ do parametru 
float CRandom::Rndf(float most_probabled)
{
	float m = Clamp(most_probabled, 0.00001f, 0.99999f);
	float rnd = Rndf();
	float dest;
	float destFactor;

	if (rnd < m)
	{
		dest = 0.00001f;
		destFactor = Clamp(0.1f / ((m-rnd) / m + 0.1f) - 0.1f);
	}
	else
	{
		dest = 0.99999f;
		destFactor = Clamp(0.1f / ((rnd-m) / (1.0f-m) + 0.1f) - 0.1f);
	}
	return Lerp(m, dest, destFactor);
}

//Metoda zwraca wartoœæ pseudolosow¹ z zakresu podanego w parametrach
float CRandom::Rndf(float begin, float end)
{
	return Rndf() * (end - begin) + begin;
}

//Metoda zwraca wartoœæ pseudolosow¹ z zakresu od 0 do RAND_MAX
int CRandom::Rnd()
{
	return rand();
}

//Metoda zwraca wartoœæ pseudolosow¹ z zakresu od min do max
int CRandom::Rnd(unsigned min, unsigned max)
{
	return min != max? (Rnd()%(max - min) + min) : max;
}
