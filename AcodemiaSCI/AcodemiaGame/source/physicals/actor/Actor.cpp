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

#include "Actor.h"
#include <iostream>

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Actor::Actor()
		:
			Physical(),//konstrutor klasy bazowej
			gun()
		{
		}

		//Konstruktor kopiujący
		Actor::Actor(const Actor & copy)
		:
			Physical(copy),//konstrutor kopiujący klasy bazowej
			gun(copy.gun)
		{
		}

		//Konstruktor przenoszący
		Actor::Actor(Actor && other)
		:
			Physical(other),//konstruktor przenoszący klasy bazowej
			gun(other.gun)
		{
		}

		//Destruktor
		Actor::~Actor()
		{
			gun;
		}

		//Przeciążony operator przypisania kopiowania
		Actor & Actor::operator=(const Actor & copy)
		{
			if (this != &copy)
			{
				Actor::operator=(copy);
				gun = copy.gun;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Actor & Actor::operator=(Actor && other)
		{
			if (this != &other)
			{
				Actor::operator=(other);
				gun = other.gun;
			}
			return *this;
		}

		//Metoda ustawia teksturę dla kontekstu graficznego pocisku
		void Actor::setBulletTexture(Texture * texture)
		{
			gun.setBulletTexture(texture);
		}

		//Metoda zwraca prędkość pocisku
		const float Actor::getBulletSpeed() const
		{
			return gun.getBulletSpeed();
		}

		//Metoda ustawia prędkość pocisku
		void Actor::setBulletSpeed(float bullet_speed)
		{
			gun.setBulletSpeed(bullet_speed);
		}

		//Metoda zwraca stałą referencję na wektor kierunku pocisku
		const sf::Vector2f & Actor::getBulletMotion() const
		{
			return gun.getBulletMotion();
		}

		//Metoda ustawia wektor kierunku pocisku
		void Actor::setBulletMotion(const sf::Vector2f & bullet_motion)
		{
			gun.setBulletMotion(bullet_motion);
		}

		//Metoda zwraca kaliber pocisku
		const float Actor::getBulletCaliber() const
		{
			return gun.getBulletCaliber();
		}

		//Metoda ustawia kaliber pocisku
		void Actor::setBulletCaliber(float caliber)
		{
			gun.setBulletCaliber(caliber);
		}

		//Metoda zwraca czas życia pocisku
		const float Actor::getBulletLifeTime() const
		{
			return gun.getBulletLifeTime();
		}

		//Metoda ustawia czas życia pocisku
		void Actor::setBulletLifeTime(float bullet_life_time)
		{
			gun.setBulletLifeTime(bullet_life_time);
		}

		//Metoda zwraca ilość pocisków oddawanych na sekundę - szybkostrzelność
		const float Actor::getGunRate() const
		{
			return gun.getGunRate();
		}

		//Metoda ustawiam ilość pocisków oddawanych na sekundę - szybkostrzelność
		void Actor::setGunRate(float gun_rate)
		{
			gun.setGunRate(gun_rate);
		}

		//Metoda ustawia wskaźnik na teksturę dla kontekstu graficznego eksplozji
		void Actor::setExplosionTexture(Texture * texture)
		{
			gun.setExplosionTexture(texture);
		}

		//Metoda ustawia rozmiar klatki animacji eksplozji - podział z atlasu tekstur
		void Actor::setExplosionFrameSize(unsigned frame_width, unsigned frame_height)
		{
			gun.setExplosionFrameSize(frame_width, frame_height);
		}

		//Metoda ustawia prędkość odtwarzania animacji eksplozji
		void Actor::setExplosionSpeed(float explosion_speed)
		{
			gun.setExplosionSpeed(explosion_speed);
		}

		//Wirtualna metoda aktualizująca obiekt
		void Actor::update(float dt)
		{
			gun.update(dt);

			if (m_health <= 0)
				m_destruction = true;
		}

		//Chroniona wirtualna metoda - strzał
		void Actor::shoot()
		{
			gun.shoot(*this);
		}

	}//namespace physical
}//namespace acodemia
