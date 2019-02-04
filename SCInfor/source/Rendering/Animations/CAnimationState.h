//  ____________________________________________
// | CAnimationState.h - class definition       |
// | Jack Flower - March 2012                   |
// |____________________________________________|
// 

#ifndef H_ANIMATION_STATE_JACK
#define H_ANIMATION_STATE_JACK

#include "CAnimationFrame.h"

namespace rendering
{
	namespace animation
	{
		///
		///Forward declaration
		///
		class CAnimation;

		///
		///Klasa reprezentuje funkcjonalny obiekt animowany
		///
		class CAnimationState
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domyœlny
			///
			CAnimationState(void);

			///
			///Konstruktor kopiuj¹cy
			///
			///@param &CAnimationStateCopy - parametr - obiekt klasy CAnimationState
			///
			CAnimationState(const CAnimationState& CAnimationStateCopy);

			///
			///Konstruktor parametryczny
			///
			///@param *animation - wskaŸnik na obiekt klasy CAnimation
			///
			CAnimationState(CAnimation* animation);

			///
			///Destruktor
			///
			~CAnimationState(void);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca czas, który up³yn¹³
			///
			const float GetCurrentTime() const;

			///
			///Metoda ustawia up³ywaj¹cy czas (up³yw czasu)
			///
			///@param current_time - up³ywaj¹cy
			///
			void SetCurrentTime (float current_time);

			///
			///Metoda zwraca wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed
			///
			const float GetAnimSpeed() const;

			///
			///Metoda ustawia wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed
			///
			///@param anim_speed - wspó³czynnik prêdkoœci odtwarzania animacji
			///
			void SetAnimSpeed(float anim_speed);

			///
			///Motoda zwraca flagê, czy animacji jest w trybie zapêtlenia (loop)
			///
			const bool GetLooped() const;

			///
			///Motoda ustawia flagê, animacji - tryb zapêtlenia (loop)
			///
			///@param is_looped - tryb zapêtlenia (loop)
			///
			void SetLooped(bool is_looped);

			///
			///Motoda zwraca flagê, animacji - stan pause
			///
			const bool GetPaused() const;

			///
			///Motoda ustawia flagê, animacji - stan pause
			///
			///@param is_paused - flaga animacji - stan pause
			///
			void SetPaused (bool is_paused);

			///
			///Metoda zwraca wskaŸnik na obiekt klasy CAnimation
			///
			CAnimation* GetAnimation();

			///
			///Metoda ustawia wskaŸnik na animacjê - obiekt klasy CAnimation
			///
			///@param *animation - wskaŸnik na obiekt klasy CAnimation (pojemnik na klatki animacji)
			///
			void SetAnimation(CAnimation* animation);

			///
			///Metoda dodaje czas do odtwarzania animacji
			///
			///@param - time - czas
			///
			void AddTime(float time);

			///
			///Metoda zwraca sta³¹ referencjê na kolejn¹ (nastêpn¹) klatkê animacji
			///
			const CAnimationFrame& GetCurrentFrame();
			
			///
			///Metoda uruchamia animacjê
			///
			void Play();

			///
			///Metoda zatrzymuje animacjê
			///
			void Stop();

			///
			///Metoda przewija sekwencjê animacji do zadanej pozycji (czasu)
			///
			///@param - position - pozycja klatki animacji (0.0 - poczatek animacji, 1.0 - koniec)
			///
			void RewindTo(float position);

			///
			///Metoda zwraca aktualny numer klatki animacji
			///
			inline const unsigned getFrameNumber() const { return m_frame_number; }
			

		private:

			float		m_current_time;	//up³ywaj¹cy czas
			float		m_anim_speed;	//wspó³czynnik prêdkoœci odtwarzania animacji 1.0f - normal speed
			bool		m_is_looped;	//flaga, czy animacja ma byæ odtwarzana jako zapêtlona (loop)
			bool		m_is_paused;	//flaga, czy animacja jest wstrzymana
			CAnimation* p_animation;	//wskaŸnik na obiekt klasy CAnimation (pojemnik z klatkami)
			unsigned	m_frame_number;	//numer klatki animacji aktualnie wyœwietlanej
		};
	}//namespace animation
}//namespace rendering
#endif //H_ANIMATION_STATE_JACK