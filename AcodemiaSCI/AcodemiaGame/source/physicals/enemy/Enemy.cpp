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

#include "Enemy.h"
#include <iostream>
#include "../../manager/PhysicalManager.h"
#include "../bullet/Bullet.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Enemy::Enemy()
		:
			Actor(),//konstruktor klasy bazowej
			m_enemy_token(false)
		{
		}

		//Konstruktor kopiujący
		Enemy::Enemy(const Enemy & copy)
		:
			Actor(copy),//konstruktor kopiujący klasy bazowej
			m_enemy_token(copy.m_enemy_token)
		{
		}

		//Konstruktor przenoszący
		Enemy::Enemy(Enemy && other)
		:
			Actor(other),//konstruktor przenoszący klasy bazowej
			m_enemy_token(other.m_enemy_token)
		{
		}

		//Destruktor
		Enemy::~Enemy()
		{
			m_enemy_token = false;
		}

		//Przeciążony operator przypisania kopiowania
		Enemy & Enemy::operator=(const Enemy & copy)
		{
			if (this != &copy)
			{
				Actor::operator=(copy);
				m_enemy_token = copy.m_enemy_token;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Enemy & Enemy::operator=(Enemy && other)
		{
			if (this != &other)
			{
				Actor::operator=(other);
				m_enemy_token = other.m_enemy_token;
			}
			return *this;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Enemy::update(float dt)
		{
			setMotion(0, 1);
			Physical::update(dt);
			Actor::update(dt);
			controlEnemy(dt);

			//algorithm AI
			//1. token nieaktywny (false)
			//2. obiekt wchodzi w obszar kamery - token się uaktywuje (true)
			//3. jeśli token jest aktywny (true) oraz obiekt opuścił obszar kamery - ginie

			//aktywacja m_enemy_token, gdy obiekt wchodzi w obszar kamery
			if (!m_enemy_token and inCamera())
				m_enemy_token = true;

			//m_enemy_token jest aktywny i obiekt opuszcza obszar kamery - ginie
			if (m_enemy_token and not inCamera())
				m_destruction = true;
		}

		//prywatna metoda steruje wrogiem...
		void Enemy::controlEnemy(float time)
		{
			Actor::shoot();
		}

		//prywatna metoda sprawdza, czy obiekt jest w obszarze kamery
		bool Enemy::inCamera()
		{
			//uwaga: poprawimy tutaj stałe napisowe (800, 600)
			//odpowiadające za obszar kamery (okna)...
			return (m_position.x > 0 and m_position.x < 800 and m_position.y > 0 and m_position.y < 600);
		}
	}//namespace physical
}//namespace acodemia
