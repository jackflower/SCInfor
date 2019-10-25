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

#include "Explosion.h"

namespace acodemia
{
	namespace animation
	{
		//Konstruktor domyślny
		Explosion::Explosion()
		:
			explosion_animation{},
			explosion{},
			m_destruction{ false }
		{
		}

		//Konstruktor kopiujący
		Explosion::Explosion(const Explosion & copy)
		:
			explosion_animation{ copy.explosion_animation },
			explosion{ copy.explosion },
			m_destruction{ copy.m_destruction }
		{
		}

		//Konstruktor przenoszący
		Explosion::Explosion(Explosion && other)
		:
			explosion_animation{ other.explosion_animation },
			explosion{ other.explosion },
			m_destruction{ other.m_destruction }
		{
		}

		//Destruktor
		Explosion::~Explosion()
		{
			explosion_animation;
			explosion;
			m_destruction = false;
		}

		//Przeciążony operator przypisania kopiowania
		Explosion & Explosion::operator=(const Explosion & copy)
		{
			if (this != &copy)
			{
				explosion_animation = copy.explosion_animation;
				explosion = copy.explosion;
				m_destruction = copy.m_destruction;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Explosion & Explosion::operator=(Explosion && other)
		{
			if (this != &other)
			{
				explosion_animation = other.explosion_animation;
				explosion = other.explosion;
				m_destruction = other.m_destruction;
			}
			return *this;
		}

		//Metoda zwraca stałą referencję pozycji obiektu
		const sf::Vector2f & Explosion::getPosition() const
		{
			return explosion.getPosition();
		}

		//Metoda ustawia pozycję obiektu
		void Explosion::setPosition(float x, float y)
		{
			explosion.setPosition(x, y);
		}

		//Metoda ustawia pozycję obiektu
		void Explosion::setPosition(const sf::Vector2f & vector)
		{
			explosion.setPosition(vector);
		}

		//Metoda ustawia skalę
		void Explosion::setScale(float x, float y)
		{
			explosion.setScale(x, y);
		}

		//Metoda ustawia skalę
		void Explosion::setScale(const sf::Vector2f & new_scale_value)
		{
			explosion.setScale(new_scale_value);
		}

		//Metoda ustawia skalę
		void Explosion::setScale(float factors)
		{
			explosion.setScale(factors, factors);
		}

		//Metoda zwraca prędkość odtwarzania animacji
		const float Explosion::getAnimationSpeed() const
		{
			return explosion.getAnimationSpeed();
		}

		//Metoda ustawia prędkość odtwarzania animacji
		void Explosion::setAnimationSpeed(float speed)
		{
			explosion.setAnimationSpeed(speed);
		}

		//Metoda ustawia teksturę eksplozji
		void Explosion::setExplosionTexture(const acodemia::rendering::Texture & texture, int explosion_frame_width, int explosion_frame_height)
		{
			explosion_animation.setAnimationFramesFromAtlasTexture(texture, explosion_frame_width, explosion_frame_height);
			explosion.setAnimation(&explosion_animation);
		}

		//Metoda zwraca informację, czy eksplozja ma być zniszczona
		const bool Explosion::getDestruction() const
		{
			return m_destruction;
		}

		//Metoda aktualizuje eksplozję
		void Explosion::update(float elapsed_time)
		{
			explosion.update(elapsed_time);

			int current_frame = explosion.getCurrentFrame();
			int anim_size = explosion.getAnimSize();

			if(explosion.getCurrentFrame() >= explosion.getAnimSize()-1)
				m_destruction = true;
		}

		//Metoda renderująca obiekt klasy Animated
		void Explosion::draw(sf::RenderWindow & render) const
		{
			render.draw(explosion);
		}

	}//animation
}//acodemia
