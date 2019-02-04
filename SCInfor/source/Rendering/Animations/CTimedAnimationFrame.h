//  _________________________________________________
// | CTimedAnimationFrame.h - class definition       |
// | Jack Flower - March 2012                        |
// |_________________________________________________|
//

#ifndef H_TIMED_ANIMATION_FRAME_JACK
#define H_TIMED_ANIMATION_FRAME_JACK

#include "CAnimationFrame.h"

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
			///@param &frame - sta³a referencja na obiekt klasy CAnimationFrame
			///
			CTimedAnimationFrame(float time, const CAnimationFrame& frame);

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
			///Metoda zwraca referencjê klatki animacji - referencja do obiektu klasy CAnimationFrame
			///
			CAnimationFrame &GetAnimationFrame();

		private:

			CAnimationFrame m_frame;		//klatka animacji - obiekt klasy CAnimationFrame
			float			m_time;			//czas ekspozycji klatki animacji
		};
	}//namespace animation
}//namespace rendering
#endif//H_TIMED_ANIMATION_FRAME_JACK
