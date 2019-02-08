/*
 ____________________________________
| CBullet.cpp - implementacja klasy. |
| Jack Flower - March 2013.          |
|____________________________________|

*/

#include "CBullet.h"
#include "../CPhysicalManager.h"

namespace logic
{
	RTTI_IMPL(CBullet, CActor);

	//Chroniony konstruktor domyœlny
	CBullet::CBullet(const std::wstring &uniqueId)
	:
		CActor				(uniqueId),//konstruktor klasy bazowej
		m_speed					(0.0f),
		m_distance				(0.0f),
		m_half_distance			(0.0f),
		m_bullet_emiter			(0.0f, 0.0f),
		m_vector_move			(0.0f, 0.0f),
		m_destruction_time		(0.0f),
		m_bullet_force			(0.0f),
		m_road					(0.0f)
	{
	}

	//Chroniony konstruktor kopiuj¹cy
	CBullet::CBullet(const CBullet &CBulletCopy)
	:
		CActor(CBulletCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_speed					(CBulletCopy.m_speed),
		m_distance				(CBulletCopy.m_distance),
		m_half_distance			(CBulletCopy.m_half_distance),
		m_bullet_emiter			(CBulletCopy.m_bullet_emiter),
		m_vector_move			(CBulletCopy.m_vector_move),
		m_destruction_time		(CBulletCopy.m_destruction_time),
		m_bullet_force			(CBulletCopy.m_bullet_force),
		m_road					(CBulletCopy.m_road)
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
	CBullet::~CBullet()
	{
		m_speed					= 0.0f;
		m_distance				= 0.0f;
		m_half_distance			 =0.0f;
		m_bullet_emiter.x		= 0.0f;
		m_bullet_emiter.y		= 0.0f;
		m_vector_move.x			= 0.0f;
		m_vector_move.y			= 0.0f;
		m_destruction_time		= 0.0f;
		m_bullet_force			= 0.0f;
		m_road					= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CBullet::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca prêdkoœæ pocisku
	const float CBullet::GetSpeed() const
	{
		return m_speed;
	}

	//Metoda ustawia prêdkoœæ pocisku
	void CBullet::SetSpeed(float speed)
	{
		if (speed < 0) return;
		m_speed = speed;
	}

	//Metoda zwraca dystans do pokonania przez pocisk
	const float CBullet::GetDistance() const
	{
		return m_distance;
	}

	//Metoda ustawia dystans do pokonania przez pocisk
	void CBullet::SetDistance(float distance)
	{
		if(distance < 0) return;
		m_distance = distance;
	}

	//Metoda zwraca po³o¿enia emitera pocisku wzglêdem w³aœciciela
	const sf::Vector2f& CBullet::GetBulletEmiter() const
	{
		return m_bullet_emiter;
	}

	//Metoda ustawia po³o¿enia emitera pocisku wzglêdem w³aœciciela
	void CBullet::SetBulletEmiter(float bullet_emiter_x, float bullet_emiter_y)
	{
		m_bullet_emiter.x = bullet_emiter_x;
		m_bullet_emiter.y = bullet_emiter_y;
	}

	//Metoda ustawia po³o¿enia emitera pocisku wzglêdem w³aœciciela
	void CBullet::SetBulletEmiter(sf::Vector2f bullet_emiter)
	{
		m_bullet_emiter = bullet_emiter;
	}

	//Metoda zwraca wektor kierunku
	const sf::Vector2f& CBullet::GetVectorMove() const
	{
		return m_vector_move;
	}

	//Metoda ustawia wektor kierunku - wspó³rzêdne
	void CBullet::SetVectorMove(float vector_move_x, float vector_move_y)
	{
		m_vector_move.x = vector_move_x;
		m_vector_move.y = vector_move_y;
	}

	//Metoda ustawia wektor kierunku - wektor
	void CBullet::SetVectorMove(sf::Vector2f vector_move)
	{
		m_vector_move = vector_move;
	}

	//Metoda zwraca czas destrukcji pocisku
	const float CBullet::GetDestructionTime() const
	{
		return m_destruction_time;
	}

	//Metoda ustawia czas destrukcji pocisku
	void CBullet::SetDestructionTime(float destruction_time)
	{
		m_destruction_time = destruction_time;
	}

	//Metoda zwraca funkcjonalnoœæ ataku pocisku
	const float CBullet::GetBulletForce() const
	{
		return m_bullet_force;
	}

	//Metoda ustawia funkcjonalnoœæ ataku pocisku
	void CBullet::SetBulletForce(float bullet_force)
	{
		m_bullet_force = bullet_force;
	}

	//Metoda zwraca po³o¿enie celu - wektor, do którego pod¹¿a pocisk
	const sf::Vector2f &CBullet::GetTarget() const
	{
		return m_target;
	} 

	//Metoda ustawia po³o¿enie celu - wektor, do którego pod¹¿a pocisk
	void CBullet::SetTarget(sf::Vector2f& target)
	{
		m_target = target;
	}

	//Metoda ustawia po³o¿enie celu - wspó³rzêdne X, Y, do którego pod¹¿a pocisk
	void CBullet::SetTarget(float target_x, float target_y)
	{
		m_target.x = target_x;
		m_target.y = target_y;
	}

	//Metoda zwraca drogê pokonan¹ przez pocisk
	float CBullet::GetRoad(float _road)
	{
		return m_road;
	}

	//Metoda ustawia drogê pokonan¹ przez pocisk
	void CBullet::SetRoad(float road)
	{
		m_road = road;
	}

	//Metoda zwraca prêdkoœæ pocisku wystrzelonego z dzia³a
	const float CBullet::GetBulletSpeed() const
	{
		return m_bullet_speed;
	}

	//Metoda ustawia prêdkoœæ pocisku wystrzelonego z dzia³a
	void CBullet::SetBulletSpeed(float bullet_speed)
	{
		m_bullet_speed = bullet_speed;
	}

	//Metoda tworzy eksplozjê - wymaga implementacji
	void CBullet::Explode()
	{
		// to do
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CBullet::update(float dt)
	{
		CPhysical::update(dt);
		//this->Kill();
		//this->MarkForDelete();
		//potrzebujê klasy CDetector...
	}

	//Metoda testowa
	void CBullet::Test()
	{
		//testy, czy mam wszystkie pola...(potrzebne)
		//this->
	}

}//namespace logic



/*
	//Wirtualna metoda aktualizuj¹ca obiekt
	void CBullet::update(float _elapsedtime)
	{
		CPhysical::update(_elapsedtime);//aktualizcja

		//obliczam drogê przebyt¹ przez pocisk
		m_road = sqrtf( ((GetPosition().x - GetInitial().x)*(GetPosition().x - GetInitial().x)) + 
						((GetPosition().y - GetInitial().y)*(GetPosition().y - GetInitial().y)) );

		//sprawdzam kolizjê pocisku
		if(m_bullet_check_collision)
		{
			if (gAICombatUnitManager.CheckBulletCollision(this))
			{
				//aktualizacja po³o¿enia pocisku - po kolizji
				SetPosition(GetPosition().x, GetPosition().y);
				//pu³ap jest zerowy - spad³ na powierzchniê
				SetAltitude(0);
				//osiagn¹³ dystans w wyniku kolizji
				SetBulletIsDistance(true);
				//obliczam czas autodestrukcji
				SetDestructionTime(GetFrameTime() * GetAnimSize()); 
				//podmiana animacji na animacjê destrukcji pocisu
				SetAnim(gAnim.AnimFromManager(GetPrepareToDeathAnimName()),true);//Czerwona eksplozja - zmiana grafiki na "Ash"
				//sprawdzam, które obiekty znalaz³y siê w zasiêgu ra¿enia pocisku...
				gAICombatUnitManager.CheckBulletDamage(this);
				//autodestrukcja jest niedostêpna
				m_destruction_enabled = false;
				//pocisk mo¿e eksplodowaæ
				m_explosion_enabled = true;
				//test kolizji jest niedostêpny
				m_bullet_check_collision = false;
			}
		}

		if (!GetBulletIsDistance())//pocisk siê porusza - nie przeby³ wyliczonej drogi - zasiêgu
		{
			if (m_road <= m_distance)//jeœli nie osi¹ga zakresu lotu...
			{
				SetPosition(GetPosition().x + (GetVectorMove().x * GetSpeed() * _elapsedtime), GetPosition().y + (GetVectorMove().y * GetSpeed() * _elapsedtime));
				if (m_road >= m_half_distance)//od po³owy dystansu do pokonania obni¿am pu³ap
				{
					//dynamicznie wyliczam altitude - cieñ symuluje balistyczny tor lotu pocisku
					//funkcja liniowa
					//mo¿na rozwa¿yæ funkcjê cosinus - opadanie po cosinusie
					SetAltitude((m_half_distance -(m_road - m_half_distance))*(m_target_altitude/m_half_distance));
				}
			}
			else//dolecia³ do celu, ale w nic nie trafi³
			{
				//aktualizacja po³o¿enia pocisku - tam gdzie siê znajduje po pokonaniu drogi
				SetPosition(GetPosition().x, GetPosition().y);
				//pu³ap jest zerowy - spad³ na powierzchniê [ po walidacji 1 ]
				SetAltitude(0);
				//osiagn¹³ dystans bez kolizji
				SetBulletIsDistance(true);
				//obliczam czas autodestrukcji
				SetDestructionTime(GetFrameTime() * GetAnimSize()); 
				//podmiana animacji na animacjê destrukcji pocisu
				SetAnim(gAnim.AnimFromManager(GetPrepareToDeathAnimName()),true);//Czerwona eksplozja - zmiana grafiki na "Ash"
				//sprawdzam, które obiekty znalaz³y siê w zasiêgu ra¿enia pocisku (pocisk bezkolizyjnie dotar³ do celu)
				gAICombatUnitManager.CheckBulletDamage(this);
				m_destruction_enabled = true;
				m_destruction_clock.Reset();
			}
		}

		if (m_destruction_enabled)//jeœli bezkolizyjnie dotar³ do celu eksploduje
		{
			//autodestrukcja pocisku
			if (m_destruction_clock.GetElapsedTime() >= GetDestructionTime())
			{
				m_destruction_enabled = false;
				//podmiana animacji pocisku na eksplozjê
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