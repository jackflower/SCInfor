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

#ifndef H_SPRITE_ACODEMIA
#define H_SPRITE_ACODEMIA

#include "SFML/Graphics/Sprite.hpp"

namespace acodemia
{
	namespace rendering
	{
		///
		///Klasa reprezentuje opakowanie bibliotecznej klasy sf::Sprite
		///
		class Sprite : public sf::Sprite
		{
		public:

			///
			///Konstruktor
			///
			Sprite();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Sprite
			///
			Sprite(const Sprite & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other - referencja do r-wartości
			///
			Sprite(Sprite && other);

			///
			///Destrukror
			///
			~Sprite();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Sprite
			///
			Sprite & operator=(const Sprite & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Sprite & operator=(Sprite && other);

		};
	}//namespace rendering
}//namespace acodemia

#endif//H_SPRITE_ACODEMIA
