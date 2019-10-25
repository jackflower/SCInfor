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

#include "Gun.h"
#include "../bullet/Bullet.h"
#include "../../manager/PhysicalManager.h"

using namespace acodemia::physical;

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Gun::Gun()
			:
			Physical{},//konstruktor klasy bazowej
			p_bullet_texture{ nullptr },
			m_elapsed_time{ 0.0f },
			m_shoot_timer{ 0.0f },
			m_shoot_enabled{ false },
			m_bullet_speed{ 0.0f },
			m_bullet_start_position{},
			m_bullet_motion{ 0.0f, 0.0f },
			m_bullet_caliber{ 0.0f },
			m_bullet_life_time{ 0.0f },
			p_explosion_texture{ nullptr },
			m_explosion_width{ 0 },
			m_explosion_height{ 0 },
			m_explosiom_speed{ 0.0f }
		{
		}

		//Konstruktor kopiujący
		Gun::Gun(const Gun & copy)
		:
			Physical{ copy },//konstruktor kopiujący klasy bazowej
			//kopiujemy dane obiektu źródłowego
			p_bullet_texture{ copy.p_bullet_texture },
			m_elapsed_time{ copy.m_elapsed_time },
			m_shoot_timer{ copy.m_shoot_timer },
			m_shoot_enabled{ copy.m_shoot_enabled },
			m_bullet_speed{ copy.m_bullet_speed },
			m_bullet_start_position{ copy.m_bullet_start_position },
			m_bullet_motion{ copy.m_bullet_motion },
			m_bullet_caliber{ copy.m_bullet_caliber },
			m_bullet_life_time{ copy.m_bullet_life_time },
			p_explosion_texture{ copy.p_explosion_texture },
			m_explosion_width{ copy.m_explosion_width },
			m_explosion_height{ copy.m_explosion_height },
			m_explosiom_speed{ copy.m_explosiom_speed }
		{
		}

		//Konstruktor przenoszący
		Gun::Gun(Gun && other)
		:
			Physical{ other },//konstruktor przenoszący klasy bazowej
			//przenosimy dane obiektu źródłowego
			p_bullet_texture{ other.p_bullet_texture },
			m_elapsed_time{ other.m_elapsed_time },
			m_shoot_timer{ other.m_shoot_timer },
			m_shoot_enabled{ other.m_shoot_enabled },
			m_bullet_speed{ other.m_bullet_speed },
			m_bullet_start_position{ other.m_bullet_start_position },
			m_bullet_motion{ other.m_bullet_motion },
			m_bullet_caliber{ other.m_bullet_caliber },
			m_bullet_life_time{ other.m_bullet_life_time },
			p_explosion_texture{ other.p_explosion_texture },
			m_explosion_width{ other.m_explosion_width },
			m_explosion_height{ other.m_explosion_height },
			m_explosiom_speed{ other.m_explosiom_speed }
		{
		}

		//Destruktor
		Gun::~Gun()
		{
			p_bullet_texture = nullptr;
			m_shoot_timer = 0.0f;
			m_elapsed_time = 0.0f;
			m_shoot_enabled = false;
			m_bullet_speed = 0.0f;
			m_bullet_start_position.x = 0.0f;
			m_bullet_start_position.y = 0.0f;
			m_bullet_motion.x = 0.0f;
			m_bullet_motion.y = 0.0f;
			m_bullet_caliber = 0.0f;
			m_bullet_life_time = 0.0f;
			p_explosion_texture = nullptr;
			m_explosion_width = 0;
			m_explosion_height = 0;
			m_explosiom_speed = 0.0f;
		}

		//Przeciążony operator przypisania kopiowania
		Gun & Gun::operator=(const Gun & copy)
		{
			if (this != &copy)
			{
				Physical::operator=(copy);
				p_bullet_texture = copy.p_bullet_texture;
				m_shoot_timer = copy.m_shoot_timer;
				m_elapsed_time = copy.m_elapsed_time;
				m_shoot_enabled = copy.m_shoot_enabled;
				m_bullet_speed = copy.m_bullet_speed;
				m_bullet_start_position = copy.m_bullet_start_position;
				m_bullet_motion = copy.m_bullet_motion;
				m_bullet_caliber = copy.m_bullet_caliber;
				m_bullet_life_time = copy.m_bullet_life_time;
				p_explosion_texture = copy.p_explosion_texture;
				m_explosion_width = copy.m_explosion_width;
				m_explosion_height = copy.m_explosion_height;
				m_explosiom_speed = copy.m_explosiom_speed;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Gun & Gun::operator=(Gun && other)
		{
			if (this != &other)
			{
				Physical::operator=(other);
				p_bullet_texture = other.p_bullet_texture;
				m_shoot_timer = other.m_shoot_timer;
				m_elapsed_time = other.m_elapsed_time;
				m_shoot_enabled = other.m_shoot_enabled;
				m_bullet_speed = other.m_bullet_speed;
				m_bullet_start_position = other.m_bullet_start_position;
				m_bullet_motion = other.m_bullet_motion;
				m_bullet_caliber = other.m_bullet_caliber;
				m_bullet_life_time = other.m_bullet_life_time;
				p_explosion_texture = other.p_explosion_texture;
				m_explosion_width = other.m_explosion_width;
				m_explosion_height = other.m_explosion_height;
				m_explosiom_speed = other.m_explosiom_speed;
			}
			return *this;
		}

		//Metoda ustawia wskaźnik na teksturę dla kontekstu graficznego pocisku
		void Gun::setBulletTexture(Texture * texture)
		{
			p_bullet_texture = texture;
		}

		//Metoda zwraca prędkość pocisku
		const float Gun::getBulletSpeed() const
		{
			return m_bullet_speed;
		}

		//Metoda ustawia prędkość pocisku
		void Gun::setBulletSpeed(float bullet_speed)
		{
			m_bullet_speed = bullet_speed;
		}

		//Metoda zwraca stałą referencję na wektor kierunku pocisku
		const sf::Vector2f & Gun::getBulletMotion() const
		{
			return m_bullet_motion;
		}

		//Metoda ustawia wektor kierunku pocisku
		void Gun::setBulletMotion(const sf::Vector2f & bullet_motion)
		{
			m_bullet_motion = bullet_motion;
		}

		//Metoda zwraca kaliber pocisku
		const float Gun::getBulletCaliber() const
		{
			return m_bullet_caliber;
		}

		//Metoda ustawia kaliber pocisku
		void Gun::setBulletCaliber(float caliber)
		{
			m_bullet_caliber = caliber;
		}

		//Metoda zwraca czas życia pocisku
		const float Gun::getBulletLifeTime() const
		{
			return m_bullet_life_time;
		}

		//Metoda ustawia czas życia pocisku
		void Gun::setBulletLifeTime(float bullet_life_time)
		{
			m_bullet_life_time = bullet_life_time;
		}

		//Metoda zwraca ilość pocisków oddawanych na sekundę - szybkostrzelność
		const float Gun::getGunRate() const
		{
			return m_shoot_timer;
		}

		//Metoda ustawiam ilość pocisków oddawanych na sekundę - szybkostrzelność
		void Gun::setGunRate(float gun_rate)
		{
			m_shoot_timer = gun_rate;
		}

		//Metoda ustawia wskaźnik na teksturę dla kontekstu graficznego eksplozji
		void Gun::setExplosionTexture(Texture * texture)
		{
			p_explosion_texture = texture;
		}

		//Metoda ustawia rozmiar klatki animacji eksplozji - podział z atlasu tekstur
		void Gun::setExplosionFrameSize(unsigned frame_width, unsigned frame_height)
		{
			m_explosion_width = frame_width;
			m_explosion_height = frame_height;
		}

		//Metoda ustawia prędkość odtwarzania animacji eksplozji
		void Gun::setExplosionSpeed(float explosion_speed)
		{
			m_explosiom_speed = explosion_speed;
		}

		//Metoda generuje strzał
		void Gun::shoot(const Physical & owner)
		{
			if (m_shoot_enabled)
			{
				if (p_bullet_texture)
				{
					//tworzymy pocisk, konfigurujemy go, strzelamy
					Bullet *bullet = gPhysicalManager.CreateBullet();
					bullet->setTexture(*p_bullet_texture);
					bullet->setUseDisplayable(true);
					//skala, etc...
					bullet->setScale(owner.getScale());
					bullet->setOrigin(bullet->getLocalBounds().width * 0.5f, bullet->getLocalBounds().height * 0.5f);
					bullet->setMotion(m_bullet_motion.x, m_bullet_motion.y);

					//korekta...pozycja startowa pocisku - pocisk nie może kolidować z lufą
					if(owner.getUpsideDown())
					{
						m_bullet_start_position.x = owner.getPosition().x + 0.0f;
						m_bullet_start_position.y = owner.getPosition().y + owner.getGlobalBounds().height * 0.5f;
						//porawka na wielkość pocisku
						m_bullet_start_position.x = owner.getPosition().x + 0.0f;
						m_bullet_start_position.y = m_bullet_start_position.y + bullet->getGlobalBounds().height * 0.5f;
					}
					else
					{
						m_bullet_start_position.x = owner.getPosition().x + 0.0f;
						m_bullet_start_position.y = owner.getPosition().y - owner.getGlobalBounds().height * 0.5f;
						//porawka na wielkość pocisku
						m_bullet_start_position.x = owner.getPosition().x + 0.0f;
						m_bullet_start_position.y = m_bullet_start_position.y - bullet->getGlobalBounds().height * 0.5f;
					}

					bullet->setPosition(m_bullet_start_position);
					bullet->setSpeed(m_bullet_speed);
					bullet->setCaliber(m_bullet_caliber);
					bullet->setLifeTime(m_bullet_life_time);
					bullet->setExplosionTexture(p_explosion_texture);
					bullet->setExplosionFrameSize(m_explosion_width, m_explosion_height);
					bullet->setExplosionSpeed(m_explosiom_speed);
					m_shoot_enabled = false;
				}
			}
		}

		//Metoda aktualizująca obiekt
		void Gun::update(float dt)
		{
			m_elapsed_time = m_elapsed_time + dt;

			if (m_elapsed_time >= m_shoot_timer)
			{
				m_elapsed_time = 0.0f;
				m_shoot_enabled = true;
			}
		}

	}//namespace physical
}// namespace acodemia
