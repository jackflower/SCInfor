//  ________________________________________________
// | TimedAnimationFrame.h - class definition       |
// | Jack Flower - March 2012                       |
// |________________________________________________|
//

#ifndef H_TIMED_ANIMATION_FRAME_JACK
#define H_TIMED_ANIMATION_FRAME_JACK

#include "AnimationFrame.h"

namespace rendering
{
	namespace animation
	{
		///
		///Klasa reprezentuje klatkę animacji wraz z czasem jej ekspozycji
		///
		class TimedAnimationFrame
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domyślny
			///
			TimedAnimationFrame();

			///
			///Konstruktor kopiujący
			///
			///@param TimedAnimationFrameCopy - parametr - obiekt klasy TimedAnimationFrame
			///
			TimedAnimationFrame(const TimedAnimationFrame & TimedAnimationFrameCopy);

			///
			///Konstruktor paramatryczny
			///
			///@param time - czas
			///
			///@param frame - stała referencja na obiekt klasy AnimationFrame
			///
			TimedAnimationFrame(float time, const AnimationFrame & frame);

			///
			///Destruktor
			///
			~TimedAnimationFrame();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca czas odtwarzania klatki animacji
			///
			float getFrameTime();

			///
			///Metoda zwraca referencję klatki animacji - referencja do obiektu klasy AnimationFrame
			///
			AnimationFrame & getAnimationFrame();

		private:

			AnimationFrame m_frame; //klatka animacji - obiekt klasy AnimationFrame
			float m_time; //czas ekspozycji klatki animacji
		};
	}//namespace animation
}//namespace rendering
#endif//H_TIMED_ANIMATION_FRAME_JACK
