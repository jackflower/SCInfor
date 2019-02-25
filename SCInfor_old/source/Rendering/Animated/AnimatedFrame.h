//  __________________________________________
// | AnimatedFrame.h - class definition       |
// | Jack Flower - March 2009                 |
// |__________________________________________|
//

#ifndef H_ANIMATED_FRAME_JACK
#define H_ANIMATED_FRAME_JACK

#include "../Displayable/Texture.h"
#include "../../RTTI/RTTI.h"

using namespace rendering::displayable;

namespace animated
{
	///
	///Klasa reprezentuje klatkę animacji
	//
	class AnimatedFrame
	{
		RTTI_DECL;

	public :
	
		///
		//Konstruktor domyślny
		///
		AnimatedFrame();
	
		///
		///Konstruktor kopiujący
		///
		///@param copy - stała referencja na obiekt klasy AnimatedFrame
		///
		AnimatedFrame(const AnimatedFrame & copy);

		///
		///Konstruktor przenoszący
		///
		///@param other - referencja do r-wartości
		///
		AnimatedFrame(AnimatedFrame && other);

		///
		///Konstruktor parametryczny
		///
		///@param texture - tekstura
		///
		///@param rectangle - obszar prostokątny tekstury
		///
		AnimatedFrame(const Texture & texture, const sf::IntRect & rectangle);

		///
		///Konstruktor parametryczny
		///
		///@param texture - tekstura
		///
		AnimatedFrame(const Texture & texture);
	
		///
		///Destruktor
		///
		~AnimatedFrame();

		///
		///Przeciążony operator przypisania kopiowania
		///
		///@param copy - stała referencja na obiekt klasy AnimatedFrame
		///
		AnimatedFrame & operator=(const AnimatedFrame & copy);

		///
		///Przeciążony operator przypisania przenoszenia
		///
		///@param other - referencja do r-wartości
		///
		AnimatedFrame & operator=(AnimatedFrame && other);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca stały wskaźnik na teksturę klatki animacji z wektora
		///
		const sf::Texture *getFrameImage() const;

		///
		///Metoda zwraca koordynaty klatki animacji z wektora
		///
		const sf::IntRect getFrameRectangle() const;

	private:

		const Texture *p_texture; //stały wskaźnik na teksturę
		sf::IntRect m_rectangle; //obszar prostokątny klatki animacji
	};
}//namespace animated
#endif // H_ANIMATED_FRAME_JACK
