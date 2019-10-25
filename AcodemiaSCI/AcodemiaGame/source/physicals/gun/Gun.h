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

#ifndef H_GUN_ACODEMIA
#define H_GUN_ACODEMIA

#include "../physical/Physical.h"
#include "../../rendering/Texture.h"

using namespace acodemia::rendering;

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje obiekt strzelający
		///
		class Gun : public Physical
		{
		public:

			///
			///Konstruktor domyślny
			///
			Gun();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Gun
			///
			Gun(const Gun & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Gun(Gun && other);

			///
			///Destruktor
			///
			~Gun();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Gun
			///
			Gun & operator=(const Gun & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Gun & operator=(Gun && other);

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
			///Metoda generuje strzał
			///
			///@param owner - stała referencja na obiekt będący właścicielem działa
			///
			void shoot(const Physical & owner);

			///
			///Metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			void update(float dt);

		private:

			Texture * p_bullet_texture;//wskaźnik na teksturę pociski
			float m_shoot_timer;//timer strzelanie - działo generuje pocisk co jakiś czas
			float m_elapsed_time;//upływający czas
			bool m_shoot_enabled;//flaga, czy można oddać strzał
			float m_bullet_speed;//prędkość pocisku
			sf::Vector2f m_bullet_start_position;//wyliczana pozycja startowa pocisku
			sf::Vector2f m_bullet_motion;//wektor kierunku pocisku
			float m_bullet_caliber;//kaliber pocisku - decyduje o obrażeniach
			float m_bullet_life_time;//czas życia pocisku
			Texture * p_explosion_texture;//wskaźnik na teksturę eksplozji
			unsigned m_explosion_width;//szerokość klatki animacji eksplozji - wyciętej z atlasu
			unsigned m_explosion_height;//wysokość klatki animacji eksplozji - wyciętej z atlasu
			float m_explosiom_speed;//prędkość odtwarzania animacji eksplozji

		};
	}//namespace physical
}// namespace acodemia
#endif//H_GUN_ACODEMIA
