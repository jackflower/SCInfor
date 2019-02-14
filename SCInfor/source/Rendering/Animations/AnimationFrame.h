//  _________________________________________
// | AnimationFrame.h - class definition     |
// | Jack Flower - March 2012                |
// |_________________________________________|
//

#ifndef H_ANIMATION_FRAME_JACK
#define H_ANIMATION_FRAME_JACK

#include <string>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include "../../RTTI/RTTI.h"

namespace rendering
{
	namespace animation
	{
		///
		///Klasa reprezentuje klatkę animacji
		///
		class AnimationFrame
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domyślny
			///
			AnimationFrame(void);

			///
			///Konstruktor parametryczny
			///
			///@param texture_name - nazwa tekstury
			///
			///@param rect - prostokątny obszar - rozmiar tekstury
			///
			AnimationFrame(const std::string & texture_name, const sf::IntRect & rectangle = sf::IntRect(0,0,0,0));

			///
			///Konstruktor kopiujący
			///
			///@param AnimationFrameCopy - stała referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame(const AnimationFrame & AnimationFrameCopy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			AnimationFrame(AnimationFrame && other);

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
			///Destruktor
			///
			~AnimationFrame();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca stałą referencję na nazwę tekstury std::string
			///
			const std::string & getTextureName() const;

			///
			///Metoda zwraca stałą referencję na prostokątny obszar tekstury sf::IntRect
			///
			const sf::IntRect & getImageRectangle() const;

		private:

			std::string m_texture_name;	//nazwa tekstury
			sf::IntRect m_rectangle; //prostokątny obszar tekstury
		};
	}//namespace animation
}//namespace rendering
#endif //H_ANIMATION_FRAME_JACK
