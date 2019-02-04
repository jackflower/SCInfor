//  ______________________________________
// | CAnimated.cpp - class implementation |
// | Jack Flower - March 2009             |
// | update May 2017                      |
// |______________________________________|
//

#include "CAnimated.h"

namespace animated
{

	// Konstruktor domyœlny
	CAnimated::CAnimated()
		:
		sf::Sprite(), //konstruktor klasy bazowej
		m_time(m_default_time),
		m_elapsedtime(0),
		m_paused(false),
		m_loop(true),
		p_animation(NULL),
		m_currentframe(0),
		m_lastanimframe(0),
		m_default_anim_mode(true)
	{
		SetFrame(0);
		setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
	}

	// Konstruktor parametryczny
	CAnimated::CAnimated(CAnimatedAnimation* p_animation, bool play, bool loop, float time)
		:
		sf::Sprite(), //konstruktor klasy bazowej
		m_time(time),
		m_elapsedtime(time),
		m_paused(!play),
		m_loop(loop),
		p_animation(p_animation),
		m_currentframe(0),
		m_lastanimframe(0),
		m_default_anim_mode(true)
	{
		SetFrame(0);
		setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
	}

	//Konstruktor kopiuj¹cy
	CAnimated::CAnimated(const CAnimated & copy)
		:
		sf::Sprite(copy), //konstruktor kopiuj¹cy klasy bazowej
		m_time(copy.m_time),
		m_elapsedtime(copy.m_elapsedtime),
		m_paused(copy.m_paused),
		m_loop(copy.m_loop),
		p_animation(copy.p_animation),
		m_currentframe(copy.m_currentframe),
		m_lastanimframe(copy.m_lastanimframe),
		m_default_anim_mode(copy.m_default_anim_mode)
	{
	}

	//Destruktor wirtualny
	CAnimated::~CAnimated()
	{
		m_time = 0.f;
		m_elapsedtime = 0.f;
		m_paused = false;
		m_loop = false;
		p_animation = NULL;
		m_currentframe = 0;
		m_lastanimframe = 0;
		m_default_anim_mode = false;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CAnimatedAnimation
	CAnimatedAnimation* CAnimated::GetAnimation() const
	{
		return p_animation;
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CAnimatedAnimation
	const void CAnimated::SetAnimation(CAnimatedAnimation* animated, bool play)
	{
		p_animation = animated;
		Stop();

		if (!play)
			Play();
		setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
	}

	//Metoda wyrejestrowuje animacjê - obiekt klasy CAnimation
	void CAnimated::UnsetAnim()
	{
		p_animation = 0;
		Stop();
	}

	//Metoda zwraca numer aktualnej klatki animacji obiektu klasy CAnimation
	const int CAnimated::GetCurrentFrame() const
	{
		return m_currentframe;
	}

	//Metoda ustawia numer klatki animacji obiektu klasy CAnimation
	const void CAnimated::SetFrame(int frame)
	{
		if (p_animation != NULL)
		{
			if (p_animation->Size() > 0)
			{
				if ((*p_animation)[frame].GetFrameImage() != NULL)
					setTexture(*((*p_animation)[frame].GetFrameImage()));
				setTextureRect((*p_animation)[frame].GetFrameRectangle());
				m_currentframe = frame;
			}
		}
	}

	//Metoda zwraca czas ekspozycji klatki animacji obiektu klasy CAnimation
	const float CAnimated::GetFrameTime() const
	{
		return m_time;
	}

	//Metoda ustawia czas ekspozycji klatki animacji obiektu klasy CAnimation
	const void CAnimated::SetFrameTime(float time)
	{
		m_time = time;
	}

	//Metoda zwraca tryb pause animacji
	const bool CAnimated::GetPaused() const
	{
		return m_paused;
	}

	//Metoda ustwia tryb pause animacji
	const void CAnimated::SetPaused(bool paused)
	{
		m_paused = paused;
	}

	//Metoda sprawdza czy ustawiony jest tryb Loop
	const bool CAnimated::IsLoop() const
	{
		return m_loop;
	}

	//Metoda ustawiaj¹ca tryb Loop animacji
	const void CAnimated::SetLoop(bool loop)
	{
		m_loop = loop;
	}

	//Metoda zatrzymuje odtwarzanie animacji
	void CAnimated::Pause()
	{
		m_paused = true;
	}

	//Metoda uruchamia animacjê
	void CAnimated::Play()
	{
		m_paused = false;
	}

	//Metoda zatrzymuje animacjê
	void CAnimated::Stop()
	{
		SetFrame(0);
		m_elapsedtime = m_time;
		m_paused = true;
	}

	//Metoda sprawdza, czy animacja jest w trybie Pause
	const bool CAnimated::IsPaused() const
	{
		return m_paused;
	}

	//Metoda sprawdza, czy animacja jest zatrzymana
	const bool CAnimated::IsStoped() const
	{
		return (m_paused && (m_currentframe == 0) && (m_elapsedtime == m_time));
	}

	//Metoda uruchamia animacjê
	void CAnimated::update(float elapsed_time)
	{
		if (!m_paused && p_animation != NULL)
		{
			m_elapsedtime -= elapsed_time;
			if (m_elapsedtime <= 0.f)
			{
				m_elapsedtime = m_time;
				if (m_currentframe + 1 < (int)p_animation->Size())
					m_currentframe++;
				else
				{
					if (m_loop)
						m_currentframe = 0;
					else
					{
						Stop();
					}
				}
				SetFrame(m_currentframe);
			}
		}
	}

	//Metoda zwraca numer ostatnio wyœwietlanej klatki animacji
	const int CAnimated::GetLastAnimFrame() const
	{
		return m_lastanimframe;
	}

	//Metoda zwraca iloœæ klatek animacji
	const int CAnimated::GetAnimSize() const
	{
		return p_animation->Size();
	}

	//Metoda zwraca flagê standardowej konfiguracji animacji
	const bool CAnimated::GetAnimMode() const
	{
		return m_default_anim_mode;
	}

	//Metoda zwraca sta³¹, zdefiniowan¹ statycznie wartoœæ ekspozycji klatki animacji
	const float CAnimated::GetDefaultFrameTime() const
	{
		return m_default_time;
	}

	//Metoda renderuj¹ca obiekt klasy CAnimated
	void CAnimated::draw(sf::RenderWindow* render)
	{
		render->draw(*this);
	}
}//namespace animated

//Nadanie wartoœci sta³ej sk³adowej statycznej
const float animated::CAnimated::m_default_time = 0.06250f;
