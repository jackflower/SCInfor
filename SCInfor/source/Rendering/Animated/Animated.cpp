//  _____________________________________
// | Animated.cpp - class implementation |
// | Jack Flower - March 2009            |
// |_____________________________________|
//

#include "Animated.h"

namespace animated
{
	RTTI_IMPL(Animated, Sprite);

	// Konstruktor domyślny
	Animated::Animated()
	:
		Sprite{},
		m_time{ m_default_time },
		m_elapsedtime{ 0 },
		m_paused{ false },
		m_loop{ true },
		p_animation{ nullptr },
		m_currentframe{ 0 },
		m_lastanimframe{ 0 },
		m_default_anim_mode{ true },
		m_animation_spped{ 1.f }
	{
		setFrame(0);
		setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
	}

	//Konstruktor kopiujący
	Animated::Animated(const Animated & copy)
	:
		Sprite{ copy }, //konstruktor kopiujący klasy bazowej
		m_time{ copy.m_time },
		m_elapsedtime{ copy.m_elapsedtime },
		m_paused{ copy.m_paused },
		m_loop{ copy.m_loop },
		p_animation{ copy.p_animation },
		m_currentframe{ copy.m_currentframe },
		m_lastanimframe{ copy.m_lastanimframe },
		m_default_anim_mode{ copy.m_default_anim_mode },
		m_animation_spped{ copy.m_animation_spped }
	{
	}

	//Konstruktor przenoszący
	Animated::Animated(Animated && other)
	:
		Sprite{ other }, //konstruktor przenoszący klasy bazowej
		m_time{ other.m_time },
		m_elapsedtime{ other.m_elapsedtime },
		m_paused{ other.m_paused },
		m_loop{ other.m_loop },
		//kopiujemy pod wskaźnik dane obiektu źródłowego
		p_animation{ other.p_animation },
		m_currentframe{ other.m_currentframe },
		m_lastanimframe{ other.m_lastanimframe },
		m_animation_spped{ other.m_animation_spped }

	{
		//zerujemy składowe obiektu źródłowego...
		other.m_time = 0.f;
		other.m_elapsedtime = 0.f;
		other.m_paused = 0.f;
		other.m_loop = false;
		//zwalniamy wskaźnik na dane obiektu źródłowego tak,
		//aby destruktor nie zwalniał pamięci wielokrotnie
		other.p_animation = nullptr;
		other.m_currentframe = 0;
		other.m_lastanimframe = 0;
		other.m_animation_spped = 0;
	}

	// Konstruktor parametryczny
	Animated::Animated(AnimatedAnimation* p_animation, bool play, bool loop, float time)
	:
		Sprite{}, //konstruktor klasy bazowej
		m_time{ time },
		m_elapsedtime{ time },
		m_paused{ !play },
		m_loop{ loop },
		p_animation{ p_animation },
		m_currentframe{ 0 },
		m_lastanimframe{ 0 },
		m_default_anim_mode{ true },
		m_animation_spped{ 1.f }
	{
		setFrame(0);
		setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
	}


	//Destruktor wirtualny
	Animated::~Animated()
	{
		//~Sprite()
		m_time = 0.f;
		m_elapsedtime = 0.f;
		m_paused = false;
		m_loop = false;
		p_animation = nullptr;
		m_currentframe = 0;
		m_lastanimframe = 0;
		m_default_anim_mode = false;
		m_animation_spped = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Animated::getType() const
	{
		return rtti.getNameClass();
	}

	//Przeciążony operator przypisania kopiowania
	Animated & Animated::operator=(const Animated & copy)
	{
		if (this != &copy)
		{
			m_time = copy.m_time;
			m_elapsedtime = copy.m_elapsedtime;
			m_paused = copy.m_paused;
			m_loop = copy.m_loop;

			//zwalaniamy dane pod wskaźnikiem
			delete p_animation;
			//tworzymy nowy obiekt na podstawie obiektu źródłowego
			p_animation = new AnimatedAnimation(*copy.p_animation);

			m_currentframe = copy.m_currentframe;
			m_lastanimframe = copy.m_lastanimframe;
			m_animation_spped = copy.m_animation_spped;
		}
		return *this;
	}

	//Przeciążony operator przypisania przenoszenia
	Animated & Animated::operator=(Animated && other)
	{
		if (this != & other)
		{
			m_time = other.m_time;
			m_elapsedtime = other.m_elapsedtime;
			m_paused = other.m_paused;
			m_loop = other.m_loop;

			//zwalaniamy dane pod wskaźnikiem
			delete p_animation;
			//przenosimy pod wskaźnik dane z obiektu źródłowego
			p_animation = other.p_animation;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie

			other.p_animation = nullptr;
			m_currentframe = other.m_currentframe;
			m_lastanimframe = other.m_lastanimframe;
			m_animation_spped = other.m_animation_spped;

			//zerowanie obiektu źródłowego
			other.m_time = 0.f;
			other.m_elapsedtime = 0.f;
			other.m_paused = false;
			other.m_loop = false;
			other.m_currentframe = 0;
			other.m_lastanimframe = 0;
			other.m_animation_spped = 0.f;
		}
		return *this;
	}

	//Metoda zwraca wskaźnik na obiekt klasy AnimatedAnimation
	AnimatedAnimation *Animated::getAnimation() const
	{
		return p_animation;
	}

	//Metoda ustawia wskaźnik na obiekt klasy AnimatedAnimation
	const void Animated::setAnimation(AnimatedAnimation *animated, bool playmode)
	{
		p_animation = animated;
		stop();

		if (!playmode)
			play();
		setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
	}

	//Metoda wyrejestrowuje animację - obiekt klasy Animation
	void Animated::unsetAnim()
	{
		p_animation = nullptr;
		stop();
	}

	//Metoda zwraca numer aktualnej klatki animacji obiektu klasy Animation
	const int Animated::getCurrentFrame() const
	{
		return m_currentframe;
	}

	//Metoda ustawia numer klatki animacji obiektu klasy Animation
	const void Animated::setFrame(int frame)
	{
		if (p_animation != nullptr)
		{
			if (p_animation->size() > 0)
			{
				if ((*p_animation)[frame].getFrameImage() != nullptr)
					setTexture(*((*p_animation)[frame].getFrameImage()));
				setTextureRect((*p_animation)[frame].getFrameRectangle());
				m_currentframe = frame;
			}
		}
	}

	//Metoda zwraca czas ekspozycji klatki animacji obiektu klasy Animation
	const float Animated::getFrameTime() const
	{
		return m_time;
	}

	//Metoda ustawia czas ekspozycji klatki animacji obiektu klasy Animation
	const void Animated::setFrameTime(float time)
	{
		m_time = time;
	}

	//Metoda zwraca tryb pause animacji
	const bool Animated::getPaused() const
	{
		return m_paused;
	}

	//Metoda ustwia tryb pause animacji
	const void Animated::setPaused(bool paused)
	{
		m_paused = paused;
	}

	//Metoda sprawdza czy ustawiony jest tryb Loop
	const bool Animated::isLoop() const
	{
		return m_loop;
	}

	//Metoda ustawiająca tryb Loop animacji
	const void Animated::setLoop(bool loop)
	{
		m_loop = loop;
	}

	//Metoda zatrzymuje odtwarzanie animacji
	void Animated::pause()
	{
		m_paused = true;
	}

	//Metoda uruchamia animację
	void Animated::play()
	{
		m_paused = false;
	}

	//Metoda zatrzymuje animację
	void Animated::stop()
	{
		setFrame(0);
		m_elapsedtime = m_time;
		m_paused = true;
	}

	//Metoda sprawdza, czy animacja jest w trybie Pause
	const bool Animated::isPaused() const
	{
		return m_paused;
	}

	//Metoda sprawdza, czy animacja jest zatrzymana
	const bool Animated::isStoped() const
	{
		return (m_paused && (m_currentframe == 0) && (m_elapsedtime == m_time));
	}

	//Metoda uruchamia animację
	void Animated::update(float elapsed_time)
	{
		if (!m_paused && p_animation != nullptr)
		{
			m_elapsedtime -= elapsed_time * m_animation_spped;

			if (m_elapsedtime <= 0.f)
			{
				m_elapsedtime = m_time;
				if (m_currentframe + 1 < (int)p_animation->size())
					m_currentframe++;
				else
				{
					if (m_loop)
						m_currentframe = 0;
					else
					{
						stop();
					}
				}
				setFrame(m_currentframe);
			}
		}
	}

	//Metoda zwraca numer ostatnio wyświetlanej klatki animacji
	const int Animated::getLastAnimFrame() const
	{
		return m_lastanimframe;
	}

	//Metoda zwraca ilość klatek animacji
	const int Animated::getAnimSize() const
	{
		return p_animation->size();
	}

	//Metoda zwraca flagę standardowej konfiguracji animacji
	const bool Animated::getAnimMode() const
	{
		return m_default_anim_mode;
	}

	//Metoda zwraca stałą, zdefiniowaną statycznie wartość ekspozycji klatki animacji
	const float Animated::getDefaultFrameTime() const
	{
		return m_default_time;
	}

	//Metoda renderująca obiekt klasy Animated
	void Animated::draw(sf::RenderWindow *render)
	{
		render->draw(*this);
	}
}//namespace animated

//Nadanie wartości stałej składowej statycznej
const float animated::Animated::m_default_time = 0.06250f;
