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
// z tego oprogramowania.Zastrzega
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

#include "Sprite.h"

namespace acodemia
{
	namespace rendering
	{
		//Konstruktor
		Sprite::Sprite()
		:
			sf::Sprite()//konstruktor klasy bazowej
		{
		}

		//Konstruktor kopiujący
		Sprite::Sprite(const Sprite & copy)
		:
			sf::Sprite(copy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Konstruktor przenoszący
		Sprite::Sprite(Sprite && other)
		:
			sf::Sprite(other)
		{
		}

		//Destrukror
		Sprite::~Sprite()
		{
		}

		//Przeciążony operator przypisania kopiowania
		Sprite & Sprite::operator=(const Sprite & copy)
		{
			if (this != &copy)
				sf::Sprite::operator=(copy);
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Sprite & Sprite::operator=(Sprite && other)
		{
			if (this != &other)
				sf::Sprite::operator=(other);
			return *this;
		}

	}//namespace rendering
}//namespace acodemia
