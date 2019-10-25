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

#ifndef H_ENEMY_GENERATOR_ACODEMIA
#define H_ENEMY_GENERATOR_ACODEMIA

#include "../utilities/Singleton.h"
#include <random>

#define gEnemyGenerator EnemyGenerator::getSingleton()

///
///Klasa reprezentuje fabrykę produkującą wrogów,
///dziedziczy po szablonie, który jest wzorcem singletona
///
class EnemyGenerator : public Singleton<EnemyGenerator>
{
public:

	///
	///Konstruktor domyślny
	///
	EnemyGenerator();

	///
	///Destruktor wirtualny
	///
	virtual ~EnemyGenerator();

	///
	///Metoda zwraca wartość pseudolosową typu float z podanego zakresu
	///
	///@param min - wartość minimalna przedziału
	///
	///@param max - wartość maksymalna przedziału
	///
	const float getRandomFloat(float min, float max) const;

private:

};

#endif//H_ENEMY_GENERATOR_ACODEMIA


////random generator...
//// Seed with a real random value, if available
//std::random_device r;
//std::default_random_engine generator(r());
//std::uniform_int_distribution<int> distribution(1, 6);
//std::uniform_real_distribution<float> dfloat(0.25f, 1.125f);
//int dice_roll = distribution(generator);  // generates number in the range 1..6 
//float zenek = dfloat(generator);
//std::cout << "Randomly-chosen mean: " << dice_roll << '\n';
//std::cout << "Randomly-chosen mean float: " << zenek << '\n';
