////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "EnemyGenerator.h"

//Konstruktor domyślny
EnemyGenerator::EnemyGenerator()
{
}

//Destruktor wirtualny
EnemyGenerator::~EnemyGenerator()
{
}

//Metoda zwraca wartość pseudolosową typu float z podanego zakresu
const float EnemyGenerator::getRandomFloat(float min, float max) const
{
	std::random_device m_random_device;
	std::default_random_engine generator{ m_random_device() };
	return std::uniform_real_distribution<float>{min, max}(generator);
}
