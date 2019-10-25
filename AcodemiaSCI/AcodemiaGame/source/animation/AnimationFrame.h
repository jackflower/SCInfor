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

#ifndef H_ANIMATION_FRAME_ACODEMIA
#define H_ANIMATION_FRAME_ACODEMIA

#include "../rendering/Texture.h"

namespace acodemia
{
	namespace animation
	{
		///
		///Klasa reprezentuje klatkę animacji
		///
		class AnimationFrame
		{
		public:

			///
			///Konstruktor domyślny
			///
			AnimationFrame();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame(const AnimationFrame & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			AnimationFrame(AnimationFrame && other);

			///
			///Konstruktor parametryczny
			///
			///@param texture - stała referencja na teksturę
			///
			///@param rectangle - stała referencja na obszar prostokątny tekstury
			///
			AnimationFrame(const acodemia::rendering::Texture & texture, const sf::IntRect & rectangle);

			///
			///Konstruktor parametryczny
			///
			///@param texture - stała referencja na teksturę
			///
			AnimationFrame(const acodemia::rendering::Texture & texture);
			
			///
			///Destruktor
			///
			~AnimationFrame();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame & operator=(const AnimationFrame & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			AnimationFrame & operator=(AnimationFrame && other);

			///
			///Metoda zwraca stały wskaźnik na teksturę klatki animacji z wektora
			///
			const sf::Texture *getFrameImage() const;

			///
			///Metoda zwraca koordynaty klatki animacji z wektora
			///
			const sf::IntRect getFrameRectangle() const;

		private:

			const acodemia::rendering::Texture *p_texture;//stały wskaźnik na teksturę
			sf::IntRect m_rectangle;//obszar prostokątny klatki animacji
		};
	}//namespace animation
}//namespace acodemia
#endif // H_ANIMATION_FRAME_ACODEMIA
