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


#ifndef H_PLAYER_ACODEMIA
#define H_PLAYER_ACODEMIA

#include "../actor/Actor.h"
#include "../gun/Gun.h"

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje gracza
		///
		class Player : public Actor
		{
		public:

			///
			///Konstruktor domyślny
			///
			Player();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Player
			///
			Player(const Player & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Player(Player && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Player();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Player
			///
			Player & operator=(const Player & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Player & operator=(Player && other);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:
		private:
			
			//prywatna metoda - sterowanie graczem graczem
			void controlPlayer(float time);
			//prywatna metoda - ograniczenie pozycji gracza do obszaru okna gry
			//gracz o polu widzenia kamery
			void correctPlayerPosition(sf::Vector2f & position);

		};
	}//namespace physical
}//namespace acodemia

#endif//H_PLAYER_ACODEMIA
