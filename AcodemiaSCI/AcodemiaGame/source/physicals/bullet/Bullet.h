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

#ifndef H_BULLET_ACODEMIA
#define H_BULLET_ACODEMIA

#include "SFML/Graphics.hpp"
#include "../actor/Actor.h"
#include "../../explosion/Explosion.h"

using namespace acodemia::animation;

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentje pocisk
		///
		class Bullet : public Actor
		{
		public:

			///
			///Konstruktor domyślny
			///
			Bullet();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Bullet
			///
			Bullet(const Bullet & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Bullet(Bullet && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Bullet();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Bullet
			///
			Bullet & operator=(const Bullet & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Bullet & operator=(Bullet && other);

			///
			///Metoda zwraca kaliber pocisku
			///
			const float getCaliber() const;

			///
			///Metoda ustawia kaliber pocisku
			///
			///@param caliber - kaliber pocisku
			///
			void setCaliber(float caliber);

			///
			///Metoda zwraca czas życia pocisku
			///
			const float getLifeTime() const;

			///
			///Metoda ustawia czas życia pocisku
			///
			///@param lifetime - czas życia pocisku
			///
			void setLifeTime(float lifetime);

			///
			///Metoda ustawia teksturę eksplozji
			///
			///@param *texture_explosion - wskaźnik na teksturę
			///
			void setExplosionTexture(Texture * texture_explosion);

			///
			///Metoda zwraca wskaźnik na eksplozję
			///
			const Explosion *getExplosion() const;

			///
			///Metoda ustawia rozmiar klatki animacji eksplozji - podział z atlasu tekstur
			///
			///@param frame_width - szerokość klatki
			///
			///@param frame_height - wysokość klatki
			///
			void setExplosionFrameSize(unsigned frame_width, unsigned frame_height);

			///
			///Metoda ustawia prędkość odtwarzania animacji eksplozji
			///
			///@param explosion_speed - prędkość odtwarzania animacji
			///
			void setExplosionSpeed(float explosion_speed);

			///
			///Eksplozja pocisku
			///
			void explode();

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			float m_caliber; //kaliber - siła rażenia
			float m_lifetime; //czas życia pocisku
			float m_elapsedtime; //upływający czas
			Texture * p_texture_explosion;//wskaźnik na teksturę eksplozji
			Explosion * p_explosion;//wskaźnik na eksplozję
			unsigned m_explosion_frame_width;//szerokość klatki animacji eksplozji - wyciętej z atlasu
			unsigned m_explosion_frame_height;//wysokość klatki animacji eksplozji - wyciętej z atlasu
			float m_explosiom_speed;//prędkość odtwarzania animacji eksplozji
		};

	}//namespace physical
}//namespace acodemia
#endif//H_BULLET_ACODEMIA
