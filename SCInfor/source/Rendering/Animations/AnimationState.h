//  ___________________________________________
// | AnimationState.h - class definition       |
// | Jack Flower - March 2012                  |
// |___________________________________________|
// 

#ifndef H_ANIMATION_STATE_JACK
#define H_ANIMATION_STATE_JACK

#include "AnimationFrame.h"

namespace rendering
{
	namespace animation
	{
		///
		///Forward declaration
		///
		class Animation;

		///
		///Klasa reprezentuje funkcjonalny obiekt animowany
		///
		class AnimationState
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domyślny
			///
			AnimationState();

			///
			///Konstruktor kopiujący
			///
			///@param AnimationStateCopy - parametr - obiekt klasy AnimationState
			///
			AnimationState(const AnimationState & AnimationStateCopy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			AnimationState(AnimationState && other);

			///
			///Konstruktor parametryczny
			///
			///@param *animation - wskaźnik na obiekt klasy Animation
			///
			AnimationState(Animation *animation);

			///
			///Destruktor
			///
			~AnimationState();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy AnimationState
			///
			AnimationState & operator=(const AnimationState & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			AnimationState & operator=(AnimationState && other);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca czas, który upłynął
			///
			const float getCurrentTime() const;

			///
			///Metoda ustawia upływający czas (upływ czasu)
			///
			///@param current_time - upływający
			///
			void setCurrentTime (float current_time);

			///
			///Metoda zwraca współczynnik prędkości odtwarzania animacji 1.0f - normal speed
			///
			const float getAnimSpeed() const;

			///
			///Metoda ustawia współczynnik prędkości odtwarzania animacji 1.0f - normal speed
			///
			///@param anim_speed - współczynnik prędkości odtwarzania animacji
			///
			void setAnimSpeed(float anim_speed);

			///
			///Motoda zwraca flagę, czy animacji jest w trybie zapętlenia (loop)
			///
			const bool getLooped() const;

			///
			///Motoda ustawia flagę, animacji - tryb zapętlenia (loop)
			///
			///@param is_looped - tryb zapętlenia (loop)
			///
			void setLooped(bool is_looped);

			///
			///Motoda zwraca flagę, animacji - stan pause
			///
			const bool getPaused() const;

			///
			///Motoda ustawia flagę, animacji - stan pause
			///
			///@param is_paused - flaga animacji - stan pause
			///
			void setPaused (bool is_paused);

			///
			///Metoda zwraca wskaźnik na obiekt klasy Animation
			///
			Animation *getAnimation();

			///
			///Metoda ustawia wskaźnik na animację - obiekt klasy Animation
			///
			///@param *animation - wskaźnik na obiekt klasy Animation (pojemnik na klatki animacji)
			///
			void setAnimation(Animation *animation);

			///
			///Metoda dodaje czas do odtwarzania animacji
			///
			///@param - time - czas
			///
			void addTime(float time);

			///
			///Metoda zwraca stałą referencję na kolejną (następną) klatkę animacji
			///
			const AnimationFrame & getCurrentFrame();
			
			///
			///Metoda uruchamia animację
			///
			void play();

			///
			///Metoda zatrzymuje animację
			///
			void stop();

			///
			///Metoda przewija sekwencję animacji do zadanej pozycji (czasu)
			///
			///@param - position - pozycja klatki animacji (0.0 - poczatek animacji, 1.0 - koniec)
			///
			void rewindTo(float position);

			///
			///Metoda zwraca aktualny numer klatki animacji
			///
			inline const unsigned getFrameNumber() const { return m_frame_number; }
			

		private:

			float m_current_time; //upływający czas
			float m_anim_speed;	//współczynnik prędkości odtwarzania animacji 1.0f - normal speed
			bool m_is_looped; //flaga, czy animacja ma być odtwarzana jako zapętlona (loop)
			bool m_is_paused; //flaga, czy animacja jest wstrzymana
			Animation *p_animation;	//wskaźnik na obiekt klasy Animation (pojemnik z klatkami)
			unsigned m_frame_number; //numer klatki animacji aktualnie wyświetlanej
		};
	}//namespace animation
}//namespace rendering
#endif //H_ANIMATION_STATE_JACK
