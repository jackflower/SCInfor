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

#include "Player.h"
#include <iostream>
#include "../../manager/PhysicalManager.h"
#include "../bullet/Bullet.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Player::Player()
		:
			Actor()//konstruktor klasy bazowej
		{
		}

		//Konstruktor kopiujący
		Player::Player(const Player & copy)
		:
			Actor(copy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Konstruktor przenoszący
		Player::Player(Player && other)
		:
			Actor(other)//konstruktor przenoszący klasy bazowej
		{
		}

		//Destruktor
		Player::~Player()
		{
		}

		//Przeciążony operator przypisania kopiowania
		Player & Player::operator=(const Player & copy)
		{
			if (this != &copy)
			{
				Actor::operator=(copy);
				//members...
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Player & Player::operator=(Player && other)
		{
			if (this != &other)
			{
				Actor::operator=(other);
				//members...
			}
			return *this;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Player::update(float dt)
		{
			Actor::update(dt);
			controlPlayer(dt);
			correctPlayerPosition(m_position);
		}

		void Player::controlPlayer(float time)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				setMotion(1, 0);
				Physical::update(time);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				setMotion(-1, 0);
				Physical::update(time);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				setMotion(0, -1);
				Physical::update(time);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				setMotion(0, 1);
				Physical::update(time);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				Actor::shoot();
		}

		void Player::correctPlayerPosition(sf::Vector2f & position)
		{
			//w poziomie
			if (position.x <= 0)
				position.x = 0;
			if (position.x >= gPhysicalManager.width)
				position.x = gPhysicalManager.width;

			//w pionie
			if (position.y <= 0)
				position.y = 0;
			if (position.y >= gPhysicalManager.height)
				position.y = gPhysicalManager.height;
		}

	}//namespace physical
}//namespace acodemia
