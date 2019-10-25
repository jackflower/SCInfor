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


#ifndef H_ENEMY_ACODEMIA
#define H_ENEMY_ACODEMIA

#include "../actor/Actor.h"
#include "../gun/Gun.h"

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje gracza
		///
		class Enemy : public Actor
		{
		public:

			///
			///Konstruktor domyślny
			///
			Enemy();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Enemy
			///
			Enemy(const Enemy & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Enemy(Enemy && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Enemy();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Enemy
			///
			Enemy & operator=(const Enemy & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other - referencja do r-wartości
			///
			Enemy & operator=(Enemy && other);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:
		private:
			
			void controlEnemy(float time); //prywatna metoda steruje wrogiem
			bool inCamera(); //prywatna metoda sprawdza, czy obiekt jest w obszarze kamery
			bool m_enemy_token; //flaga, czy enemy ulega destrukcji poza kamerą
			
		};
	}//namespace physical
}//namespace acodemia

#endif//H_ENEMY_ACODEMIA
