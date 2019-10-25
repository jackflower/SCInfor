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


#ifndef H_ACTOR_ACODEMIA
#define H_ACTOR_ACODEMIA

#include "../physical/Physical.h"
#include "../gun/Gun.h"

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje aktora
		///
		class Actor : public Physical
		{
		public:

			///
			///Konstruktor domyślny
			///
			Actor();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Actor
			///
			Actor(const Actor & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Actor(Actor && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Actor();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Actor
			///
			Actor & operator=(const Actor & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Actor & operator=(Actor && other);

			///
			///Metoda ustawia wskaźnik na teksturę dla kontekstu graficznego pocisku
			///
			///@param *texture - wskaźnik na obiekt klasy Texture
			///
			void setBulletTexture(Texture * texture);

			///
			///Metoda zwraca prędkość pocisku
			///
			const float getBulletSpeed() const;

			///
			///Metoda ustawia prędkość pocisku
			///
			///@param bullet_speed - prędkość pocisku
			///
			void setBulletSpeed(float bullet_speed);

			///
			///Metoda zwraca stałą referencję na wektor kierunku pocisku
			///
			const sf::Vector2f & getBulletMotion() const;

			///
			///Metoda ustawia wektor kierunku pocisku
			///
			///@param bullet_motion - stała referencja na obiekt klasy sf::Vector2f
			///
			void setBulletMotion(const sf::Vector2f & bullet_motion);

			///
			///Metoda zwraca kaliber pocisku
			///
			const float getBulletCaliber() const;

			///
			///Metoda ustawia kaliber pocisku
			///
			///@param caliber - kaliber pocisku
			///
			void setBulletCaliber(float caliber);

			///
			///Metoda zwraca czas życia pocisku
			///
			const float getBulletLifeTime() const;

			///
			///Metoda ustawia czas życia pocisku
			///
			///@param bullet_life_time - czas życia pocisku
			///
			void setBulletLifeTime(float bullet_life_time);

			///
			///Metoda zwraca ilość pocisków oddawanych na sekundę - szybkostrzelność
			///
			const float getGunRate() const;

			///
			///Metoda ustawiam ilość pocisków oddawanych na sekundę - szybkostrzelność
			///
			///@param gun_rate - szybkostrzelność
			///
			void setGunRate(float gun_rate);

			///
			///Metoda ustawia wskaźnik na teksturę dla kontekstu graficznego eksplozji
			///
			///@param *texture - wskaźnik na obiekt klasy Texture
			///
			void setExplosionTexture(Texture * texture);
			
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
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			//Chroniona wirtualna metoda - strzał
			virtual void shoot();
		
		private:
			Gun gun;//działo...

		};
	}//namespace physical
}//namespace acodemia

#endif//H_ACTOR_ACODEMIA
