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

#include "Bullet.h"
#include "../../manager/PhysicalManager.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Bullet::Bullet()
		:
			Actor{},
			m_caliber{ 0.f },
			m_lifetime{ 0.f },
			m_elapsedtime{ 0.f },
			p_texture_explosion{nullptr},
			p_explosion{nullptr},
			m_explosion_frame_width{ 0 },
			m_explosion_frame_height{ 0 },
			m_explosiom_speed{0.0f}

		//unsigned ;//szerokość klatki animacji eksplozji - wyciętej z atlasu
		//unsigned ;//wysokość klatki animacji eksplozji - wyciętej z atlasu
		//float m_explosiom_speed;//prędkość odtwarzania animacji eksplozji

		{
		}

		//Konstruktor kopiujący
		Bullet::Bullet(const Bullet & copy)
		:
			Actor{ copy },//konstruktor kopiujący klasy bazowej
			m_caliber{ copy.m_caliber },
			m_lifetime{copy.m_lifetime},
			m_elapsedtime{copy.m_elapsedtime},
			p_texture_explosion{ copy.p_texture_explosion },
			p_explosion{ copy.p_explosion },
			m_explosion_frame_width{ copy.m_explosion_frame_width },
			m_explosion_frame_height{ copy.m_explosion_frame_height },
			m_explosiom_speed{ copy.m_explosiom_speed }
		{
		}

		//Konstruktor przenoszący
		Bullet::Bullet(Bullet && other)
		:
			Actor{ other },//konstruktor przenoszący klasy bazowej
			m_caliber{ other.m_caliber },
			m_lifetime{ other.m_lifetime },
			m_elapsedtime{ other.m_elapsedtime },
			p_texture_explosion{ other.p_texture_explosion },
			p_explosion{ other.p_explosion },
			m_explosion_frame_width{ other.m_explosion_frame_width },
			m_explosion_frame_height{ other.m_explosion_frame_height },
			m_explosiom_speed{ other.m_explosiom_speed }
		{
		}

		//Destruktor wirtualny
		Bullet::~Bullet()
		{
			m_caliber = 0.f;
			m_lifetime = 0.f;
			m_elapsedtime = 0.f;
			p_texture_explosion = nullptr;
			p_explosion = nullptr;
			m_explosion_frame_width = 0;
			m_explosion_frame_height = 0;
			m_explosiom_speed = 0.0f;
		}

		//Przeciążony operator przypisania kopiowania
		Bullet & Bullet::operator=(const Bullet & copy)
		{
			if (this != &copy)
			{
				Actor::operator=(copy);
				m_caliber = copy.m_caliber;
				m_lifetime = copy.m_lifetime;
				m_elapsedtime = copy.m_elapsedtime;
				p_texture_explosion = copy.p_texture_explosion;
				p_explosion = copy.p_explosion;
				m_explosion_frame_width = copy.m_explosion_frame_width;
				m_explosion_frame_height = copy.m_explosion_frame_height;
				m_explosiom_speed = copy.m_explosiom_speed;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Bullet & Bullet::operator =(Bullet && other)
		{
			if (this != &other)
			{
				Actor::operator=(other);
				m_caliber = other.m_caliber;
				m_lifetime = other.m_lifetime;
				m_elapsedtime = other.m_elapsedtime;
				p_texture_explosion = other.p_texture_explosion;
				p_explosion = other.p_explosion;
				m_explosion_frame_width = other.m_explosion_frame_width;
				m_explosion_frame_height = other.m_explosion_frame_height;
				m_explosiom_speed = other.m_explosiom_speed;
			}
			return *this;
		}
		
		//Metoda zwraca kaliber pocisku
		const float Bullet::getCaliber() const
		{
			return m_caliber;
		}

		//Metoda ustawia kaliber pocisku
		void Bullet::setCaliber(float caliber)
		{
			m_caliber = caliber;
		}

		//Metoda zwraca czas życia pocisku
		const float Bullet::getLifeTime() const
		{
			return m_lifetime;
		}

		//Metoda ustawia czas życia pocisku
		void Bullet::setLifeTime(float lifetime)
		{
			m_lifetime = lifetime;
		}
		
		//Metoda ustawia teksturę eksplozji
		void Bullet::setExplosionTexture(Texture * texture_explosion)
		{
			p_texture_explosion = texture_explosion;
		}

		//Metoda zwraca wskaźnik na eksplozję
		const Explosion *Bullet::getExplosion() const
		{
			return p_explosion;
		}

		//Metoda ustawia rozmiar klatki animacji eksplozji - podział z atlasu tekstur
		void Bullet::setExplosionFrameSize(unsigned frame_width, unsigned frame_height)
		{
			m_explosion_frame_width = frame_width;
			m_explosion_frame_height = frame_height;
		}

		//Metoda ustawia prędkość odtwarzania animacji eksplozji
		void Bullet::setExplosionSpeed(float explosion_speed)
		{
			m_explosiom_speed = explosion_speed;
		}

		//Eksplozja pocisku
		void Bullet::explode()
		{
			if (p_texture_explosion)
			{
				p_explosion = gPhysicalManager.CreateExplosion();
				p_explosion->setExplosionTexture(*p_texture_explosion, m_explosion_frame_width, m_explosion_frame_width);
 				p_explosion->setPosition(getPosition());
				p_explosion->setScale(getScale());
				p_explosion->setAnimationSpeed(m_explosiom_speed);
			}
		}

		//Wirtualna metoda aktualizująca obiekt
		void Bullet::update(float dt)
		{
			//aktualizacja pozycji
			Physical::update(dt);

			//zliczamy czas życia pocisku
			m_elapsedtime += dt;
			//po upływie określonego czasu
			if (m_elapsedtime > m_lifetime)
				destroy();//niszczymy pocisk
		}

	}//namespace physical
}//namespace acodemia
