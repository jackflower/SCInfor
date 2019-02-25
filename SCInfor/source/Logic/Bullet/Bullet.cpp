//  ___________________________________
// | Bullet.cpp - class implementation |
// | Jack Flower - March 2013          |
// |___________________________________|
//


#include "Bullet.h"
#include "../PhysicalManager.h"

namespace logic
{
	RTTI_IMPL(Bullet, Actor);

	//Chroniony konstruktor domyślny
	Bullet::Bullet(const std::wstring & uniqueId)
	:
		Actor(uniqueId),//konstruktor klasy bazowej
		m_speed(0.0f),
		m_distance(0.0f),
		m_half_distance(0.0f),
		m_bullet_emiter(0.0f, 0.0f),
		m_vector_move(0.0f, 0.0f),
		m_destruction_time(0.0f),
		m_bullet_force(0.0f),
		m_road(0.0f)
	{
	}

	//Chroniony konstruktor kopiujący
	Bullet::Bullet(const Bullet & BulletCopy)
	:
		Actor(BulletCopy),//konstruktor kopiujący klasy bazowej
		m_speed(BulletCopy.m_speed),
		m_distance(BulletCopy.m_distance),
		m_half_distance(BulletCopy.m_half_distance),
		m_bullet_emiter(BulletCopy.m_bullet_emiter),
		m_vector_move(BulletCopy.m_vector_move),
		m_destruction_time(BulletCopy.m_destruction_time),
		m_bullet_force(BulletCopy.m_bullet_force),
		m_road(BulletCopy.m_road)
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
	Bullet::~Bullet()
	{
		m_speed = 0.0f;
		m_distance = 0.0f;
		m_half_distance = 0.0f;
		m_bullet_emiter.x = 0.0f;
		m_bullet_emiter.y = 0.0f;
		m_vector_move.x = 0.0f;
		m_vector_move.y = 0.0f;
		m_destruction_time = 0.0f;
		m_bullet_force = 0.0f;
		m_road = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Bullet::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca prędkość pocisku
	const float Bullet::getSpeed() const
	{
		return m_speed;
	}

	//Metoda ustawia prędkość pocisku
	void Bullet::setSpeed(float speed)
	{
		if (speed < 0) return;
		m_speed = speed;
		//2019-02-10 - sprawdzić, czy odwołać się do składowych
		//m_velocity...
	}

	//Metoda zwraca dystans do pokonania przez pocisk
	const float Bullet::getDistance() const
	{
		return m_distance;
	}

	//Metoda ustawia dystans do pokonania przez pocisk
	void Bullet::setDistance(float distance)
	{
		if(distance < 0) return;
		m_distance = distance;
	}

	//Metoda zwraca położenia emitera pocisku względem właściciela
	const sf::Vector2f & Bullet::getBulletEmiter() const
	{
		return m_bullet_emiter;
	}

	//Metoda ustawia położenia emitera pocisku względem właściciela
	void Bullet::setBulletEmiter(float bullet_emiter_x, float bullet_emiter_y)
	{
		m_bullet_emiter.x = bullet_emiter_x;
		m_bullet_emiter.y = bullet_emiter_y;
	}

	//Metoda ustawia położenia emitera pocisku względem właściciela
	void Bullet::setBulletEmiter(sf::Vector2f & bullet_emiter)
	{
		m_bullet_emiter = bullet_emiter;
	}

	//Metoda zwraca wektor kierunku
	const sf::Vector2f& Bullet::getVectorMove() const
	{
		return m_vector_move;
	}

	//Metoda ustawia wektor kierunku - współrzędne
	void Bullet::setVectorMove(float vector_move_x, float vector_move_y)
	{
		m_vector_move.x = vector_move_x;
		m_vector_move.y = vector_move_y;
	}

	//Metoda ustawia wektor kierunku - wektor
	void Bullet::setVectorMove(sf::Vector2f & vector_move)
	{
		m_vector_move = vector_move;
	}

	//Metoda zwraca czas destrukcji pocisku
	const float Bullet::getDestructionTime() const
	{
		return m_destruction_time;
	}

	//Metoda ustawia czas destrukcji pocisku
	void Bullet::setDestructionTime(float destruction_time)
	{
		m_destruction_time = destruction_time;
	}

	//Metoda zwraca funkcjonalność ataku pocisku
	const float Bullet::getBulletForce() const
	{
		return m_bullet_force;
	}

	//Metoda ustawia funkcjonalność ataku pocisku
	void Bullet::setBulletForce(float bullet_force)
	{
		m_bullet_force = bullet_force;
	}

	//Metoda zwraca położenie celu - wektor, do którego podąża pocisk
	const sf::Vector2f & Bullet::getTarget() const
	{
		return m_target;
	} 

	//Metoda ustawia położenie celu - wektor, do którego podąża pocisk
	void Bullet::setTarget(sf::Vector2f & target)
	{
		m_target = target;
	}

	//Metoda ustawia położenie celu - współrzędne X, Y, do którego podąża pocisk
	void Bullet::setTarget(float target_x, float target_y)
	{
		m_target.x = target_x;
		m_target.y = target_y;
	}

	//Metoda zwraca drogę pokonaną przez pocisk
	const float Bullet::getRoad()
	{
		return m_road;
	}

	//Metoda ustawia drogę pokonaną przez pocisk
	void Bullet::setRoad(float road)
	{
		m_road = road;
	}

	//Metoda zwraca prędkość pocisku wystrzelonego z działa
	const float Bullet::getBulletSpeed() const
	{
		return m_bullet_speed;
	}

	//Metoda ustawia prędkość pocisku wystrzelonego z działa
	void Bullet::setBulletSpeed(float bullet_speed)
	{
		m_bullet_speed = bullet_speed;
	}

	//Metoda tworzy eksplozję - wymaga implementacji
	void Bullet::explode()
	{
		// to do
	}


	//Wirtualna metoda aktualizująca obiekt
	void Bullet::update(float dt)
	{
		Physical::update(dt);
		//this->kill();
		//this->MarkForDelete();
		//potrzebuję klasy CDetector...
	}

	//Metoda testowa
	void Bullet::Test()
	{
		//testy, czy mam wszystkie pola...(potrzebne)
		//this->
	}

}//namespace logic


/*
	//Wirtualna metoda aktualizująca obiekt
	void Bullet::update(float _elapsedtime)
	{
		Physical::update(_elapsedtime);//aktualizcja

		//obliczam drogę przebytą przez pocisk
		m_road = sqrtf( ((GetPosition().x - GetInitial().x)*(GetPosition().x - GetInitial().x)) + 
						((GetPosition().y - GetInitial().y)*(GetPosition().y - GetInitial().y)) );

		//sprawdzam kolizję pocisku
		if(m_bullet_check_collision)
		{
			if (gAICombatUnitManager.CheckBulletCollision(this))
			{
				//aktualizacja położenia pocisku - po kolizji
				SetPosition(GetPosition().x, GetPosition().y);
				//pułap jest zerowy - spadł na powierzchnię
				SetAltitude(0);
				//osiagnął dystans w wyniku kolizji
				SetBulletIsDistance(true);
				//obliczam czas autodestrukcji
				SetDestructionTime(GetFrameTime() * GetAnimSize()); 
				//podmiana animacji na animację destrukcji pocisu
				SetAnim(gAnim.AnimFromManager(GetPrepareToDeathAnimName()),true);//Czerwona eksplozja - zmiana grafiki na "Ash"
				//sprawdzam, które obiekty znalazły się w zasięgu rażenia pocisku...
				gAICombatUnitManager.CheckBulletDamage(this);
				//autodestrukcja jest niedostępna
				m_destruction_enabled = false;
				//pocisk może eksplodować
				m_explosion_enabled = true;
				//test kolizji jest niedostępny
				m_bullet_check_collision = false;
			}
		}

		if (!GetBulletIsDistance())//pocisk się porusza - nie przebył wyliczonej drogi - zasięgu
		{
			if (m_road <= m_distance)//jeśli nie osiąga zakresu lotu...
			{
				SetPosition(GetPosition().x + (GetVectorMove().x * GetSpeed() * _elapsedtime), GetPosition().y + (GetVectorMove().y * GetSpeed() * _elapsedtime));
				if (m_road >= m_half_distance)//od połowy dystansu do pokonania obniżam pułap
				{
					//dynamicznie wyliczam altitude - cień symuluje balistyczny tor lotu pocisku
					//funkcja liniowa
					//można rozważyć funkcję cosinus - opadanie po cosinusie
					SetAltitude((m_half_distance -(m_road - m_half_distance))*(m_target_altitude/m_half_distance));
				}
			}
			else//doleciał do celu, ale w nic nie trafił
			{
				//aktualizacja położenia pocisku - tam gdzie się znajduje po pokonaniu drogi
				SetPosition(GetPosition().x, GetPosition().y);
				//pułap jest zerowy - spadł na powierzchnię [ po walidacji 1 ]
				SetAltitude(0);
				//osiagnął dystans bez kolizji
				SetBulletIsDistance(true);
				//obliczam czas autodestrukcji
				SetDestructionTime(GetFrameTime() * GetAnimSize()); 
				//podmiana animacji na animację destrukcji pocisu
				SetAnim(gAnim.AnimFromManager(GetPrepareToDeathAnimName()),true);//Czerwona eksplozja - zmiana grafiki na "Ash"
				//sprawdzam, które obiekty znalazły się w zasięgu rażenia pocisku (pocisk bezkolizyjnie dotarł do celu)
				gAICombatUnitManager.CheckBulletDamage(this);
				m_destruction_enabled = true;
				m_destruction_clock.Reset();
			}
		}

		if (m_destruction_enabled)//jeśli bezkolizyjnie dotarł do celu eksploduje
		{
			//autodestrukcja pocisku
			if (m_destruction_clock.GetElapsedTime() >= GetDestructionTime())
			{
				m_destruction_enabled = false;
				//podmiana animacji pocisku na eksplozję
				SetAnim(gAnim.AnimFromManager(GetDestroyAnimName()),true);//Niebieska animacja - eksplozja po bezkolizyjnym upadku u celu
				//obliczam czas eksplozji pocisku u celu
				SetDestructionTime(GetFrameTime() * GetAnimSize()); 
				m_explosion_enabled = true;
				m_destruction_clock.Reset();
			}
		}

		//zniszczenie pocisku po odegraniu animacji destrukcji
		if (m_explosion_enabled)
		{
			if (m_destruction_clock.GetElapsedTime() >= GetDestructionTime())
			{
				m_explosion_enabled = false;
				m_destruction_enabled = false;
				SetDeath(true);
				m_destruction_clock.Reset();
			}
		}

		//	R	e	s	z	t	a	 AI

*/