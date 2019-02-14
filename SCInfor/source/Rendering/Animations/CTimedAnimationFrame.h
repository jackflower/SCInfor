//  _________________________________________________
// | CTimedAnimationFrame.h - class definition       |
// | Jack Flower - March 2012                        |
// |_________________________________________________|
//

#ifndef H_TIMED_ANIMATION_FRAME_JACK
#define H_TIMED_ANIMATION_FRAME_JACK

#include "AnimationFrame.h"

namespace rendering
{
	namespace animation
	{
		///
		///Klasa reprezentuje klatkê animacji wraz z czasem jej ekspozycji
		///
		class CTimedAnimationFrame
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domyœlny
			///
			CTimedAnimationFrame(void);

			///
			///Konstruktor kopiuj¹cy
			///
			///@param CTimedAnimationFrameCopy - parametr - obiekt klasy CTimedAnimationFrame
			///
			CTimedAnimationFrame(const CTimedAnimationFrame& CTimedAnimationFrameCopy);

			///
			///Konstruktor paramatryczny
			///
			///@param time - czas
			///
			///@param &frame - sta³a referencja na obiekt klasy AnimationFrame
			///
			CTimedAnimationFrame(float time, const AnimationFrame& frame);

			///
			///Destruktor
			///
			~CTimedAnimationFrame(void);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca czas odtwarzania klatki animacji
			///
			float GetFrameTime();

			///
			///Metoda zwraca referencjê klatki animacji - referencja do obiektu klasy AnimationFrame
			///
			AnimationFrame &GetAnimationFrame();

		private:

			AnimationFrame m_frame;		//klatka animacji - obiekt klasy AnimationFrame
			float			m_time;			//czas ekspozycji klatki animacji
		};
	}//namespace animation
}//namespace rendering
#endif//H_TIMED_ANIMATION_FRAME_JACK
