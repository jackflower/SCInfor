//  ___________________________________________
// | AnimationState.cpp - class implementation |
// | Jack Flower - March 2012                  |
// |___________________________________________|
//

#include "AnimationState.h"
#include "Animation.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(AnimationState);

		//Pusta klatka animacji i nadanie jej nazwy
		AnimationFrame gNullFrame = AnimationFrame("NULL_ANIMATION");

		//Konstruktor domyślny
		AnimationState::AnimationState()
		:
			m_current_time{ 0 },
			m_anim_speed{ 1.0f },
			m_is_looped{ true },
			m_is_paused{ false },
			p_animation{ nullptr },
			m_frame_number{ 0 }
		{
		}

		//Konstruktor kopiujący
		AnimationState::AnimationState(const AnimationState & AnimationStateCopy)
		:
			m_current_time{ AnimationStateCopy.m_current_time },
			m_anim_speed{ AnimationStateCopy.m_anim_speed },
			m_is_looped{ AnimationStateCopy.m_is_looped },
			m_is_paused{ AnimationStateCopy.m_is_paused },
			p_animation{ AnimationStateCopy.p_animation },
			m_frame_number{ AnimationStateCopy.m_frame_number }
		{
		}
	
		//Konstruktor przenoszący
		AnimationState::AnimationState(AnimationState && other)
		:
			m_current_time{ other.m_current_time },
			m_anim_speed{ other.m_anim_speed },
			m_is_looped{ other.m_is_looped },
			m_is_paused{ other.m_is_paused },
			p_animation{ other.p_animation },
			m_frame_number{ other.m_frame_number }
		{
			//zerujemy składowe obiektu źródłowego...
			other.m_current_time = 0.f;
			other.m_anim_speed = 0.f;
			other.m_is_looped = false;
			other.m_is_paused = false;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie
			other.p_animation = nullptr;
			other.m_frame_number = 0;
		}

		//Konstruktor parametryczny
		AnimationState::AnimationState(Animation *animation)
		:
			m_current_time{ 0 },
			m_anim_speed{ 1.0f },
			m_is_looped{ true },
			m_is_paused{ false },
			p_animation{ animation },
			m_frame_number{ 0 }
		{
		}

		//Destruktor
		AnimationState::~AnimationState()
		{
			m_current_time = 0;
			m_anim_speed = 0.0f;
			m_is_looped = true;
			m_is_paused = false;
			p_animation = nullptr;
			m_frame_number = 0;
		}

		//Przeciążony operator przypisania kopiowania
		AnimationState & AnimationState::operator=(const AnimationState & copy)
		{
			if (this != &copy)
			{
				m_current_time = copy.m_current_time;
				m_anim_speed = copy.m_anim_speed;
				m_is_looped = copy.m_is_looped;
				m_is_paused = copy.m_is_paused;

				//zwalaniamy dane pod wskaźnikiem
				delete p_animation;
				//tworzymy nowy obiekt na podstawie obiektu źródłowego
				p_animation = new Animation(*copy.p_animation);
				m_frame_number = copy.m_frame_number;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		AnimationState & AnimationState::operator=(AnimationState && other)
		{
			if (this != &other)
			{
				m_current_time = other.m_current_time;
				m_anim_speed = other.m_anim_speed;
				m_is_looped = other.m_is_looped;
				m_is_paused = other.m_is_paused;

				//zwalaniamy dane pod wskaźnikiem
				delete p_animation;
				//przenosimy pod wskaźnik dane z obiektu źródłowego
				p_animation = other.p_animation;
				//zwalniamy wskaźnik na dane obiektu źródłowego tak,
				//aby destruktor nie zwalniał pamięci wielokrotnie
				other.p_animation = nullptr;
				m_frame_number = other.m_frame_number;

				//zerowanie obiektu źródłowego
				other.m_current_time = 0.f;
				other.m_anim_speed = 0.f;
				other.m_is_looped = false;
				other.m_is_paused = false;
				//p_animation...
				other.m_frame_number = 0;
			}
			return *this;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string AnimationState::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca czas, który upłynął
		const float AnimationState::getCurrentTime() const
		{
			return m_current_time;
		}

		//Metoda ustawia upływający czas (upływ czasu)
		void AnimationState::setCurrentTime (float current_time)
		{
			m_current_time = current_time;
		}

		//Metoda zwraca współczynnik prędkości odtwarzania animacji 1.0f - normal speed
		const float AnimationState::getAnimSpeed() const
		{
			return m_anim_speed;
		}

		//Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed
		void AnimationState::setAnimSpeed(float anim_speed)
		{
			m_anim_speed = anim_speed;
		}

		//Motoda zwraca flagę, czy animacji jest w trybie zapętlenia (loop)
		const bool AnimationState::getLooped() const
		{
			return m_is_looped;
		}

		//Motoda ustawia flagę, animacji - tryb zapętlenia (loop)
		void AnimationState::setLooped(bool is_looped)
		{
			m_is_looped = is_looped;
		}

		//Motoda zwraca flagę, animacji - stan pause
		const bool AnimationState::getPaused() const
		{
			return m_is_paused;
		}

		//Motoda ustawia flagę, animacji - stan pause
		void AnimationState::setPaused (bool is_paused)
		{
			m_is_paused = is_paused;
		}

		//Metoda zwraca wskaźnik na obiekt klasy Animation
		Animation *AnimationState::getAnimation()
		{
			return p_animation;
		}

		//Metoda ustawia wskaźnik na animację - obiekt klasy Animation
		void AnimationState::setAnimation(Animation *animation)
		{
			p_animation = animation;
		}

		//Metoda dodaje czas do odtwarzania animacji
		void AnimationState::addTime(float time)
		{
			//kumulujemy upływający czas
			//główna idea - "oszczędzamy" czas
			m_current_time += time * m_anim_speed;

			//długość animacji to czas równy
			//całkowitej sumie czasów trwania wszystkich
			//jej klatek animacji - suma poszczególnych czasów każdej klatki
			float animationLength = p_animation->totalLength();	

			if (m_is_looped) //jeśli animacja pracuje w trybie zapętlenia (loop)
			{
				if (animationLength > 0.0f) //jeśli czas trwania animacji jest dodatni
				{
					//jeśli skumulowany czas jest większy niż całkowity czas trwania animacji
					//wchodzimy w pętlę...

					//dopóki upływający czas jest większy
					//od czasu długości trwania całej animacji
					//zmniejszam czas trwania animacji
					while (m_current_time > animationLength)
						m_current_time -= animationLength;		
						//rekumulacja...
				}
				else //w przeciwnym wypadku, zerujemy upływający czas												
					m_current_time = 0.0f;
			}
			else //animacja pracuje w trybie bez zapętlenia
			{
				//jeśli czas, który upłynął jest większy
				//od czasu trwania animacji - to czas, który upłynął
				if (m_current_time > animationLength)
					m_current_time = animationLength;//jest równy czasowi trwania animacji (reset)
			}
		}
		
		//Metoda zwraca stałą referencję na kolejną (następną) klatkę animacji
		const AnimationFrame& AnimationState::getCurrentFrame()
		{
			if (p_animation->m_frames.empty()) //jeśli w kontenerze nie ma klatek animacji
					return gNullFrame; //zwracamy pustą animację

			size_t candidate = 0; //kolejna klatka animacji do odtwarzania
			for (size_t i = p_animation->m_frames.size()-1; i>0; i--) //przeszukujemy kontener z klatkami animacji
			{
				//jeśli czas  odtwarzania klatki z kontenera
				//jest mniejszy niż bieżący czas
				//(skończył się czas jej ekspozycji)
				if (p_animation->m_frames[i-1].getFrameTime() < m_current_time)
				{
					candidate = i; //to następną klatką do ekspozycji
					break; //jest kolejna klatka - przerywamy iterowanie
				}
			}
			m_frame_number = candidate;
			return p_animation->m_frames[candidate].getAnimationFrame();	//zwracamy ją, jako kolejną do odtwarzania
		}

		//Metoda uruchamia animację
		void AnimationState::play()
		{
			m_is_paused = false;
		}

		//Metoda zatrzymuje animację
		void AnimationState::stop()
		{
			 m_is_paused = true;
		}
		
		//Metoda przewija sekwencję animacji do zadanej pozycji (czasu)
		void AnimationState::rewindTo(float position) // 0.0 - poczatek animacji, 1.0 - koniec
		{
			if (position < 0.0f) position = 0.0f;
			if (position > 1.0f) position = 1.0f;

			float animationLength = p_animation->totalLength();
			m_current_time = animationLength * position;
		}
	}//namespace animation
}//namespace rendering
