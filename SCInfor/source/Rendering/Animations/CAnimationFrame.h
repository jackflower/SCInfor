//  __________________________________________
// | CAnimationFrame.h - class definition     |
// | Jack Flower - March 2012                 |
// |__________________________________________|
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
		///Klasa reprezentuje klatk� animacji
		///
		class CAnimationFrame
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domy�lny
			///
			CAnimationFrame(void);

			///
			///Konstruktor parametryczny
			///
			///@param texture_name - nazwa tekstury
			///
			///@param rect - prostoktny obszar - rozmiar tekstury
			///
			CAnimationFrame(const std::string& texture_name, const sf::IntRect&	rectangle = sf::IntRect(0,0,0,0));

			///
			///Konstruktor kopiuj�cy
			///
			///@param CAnimationFrameCopy - sta�a referencja na obiekt klasy CAnimationFrame
			///
			CAnimationFrame(const CAnimationFrame& CAnimationFrameCopy);

			///
			///Destruktor
			///
			~CAnimationFrame(void);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca sta�� referencj� na nazw� tekstury std::string
			///
			const std::string& GetTextureName() const;

			///
			///Metoda zwraca sta�� referencj� na prostok�tny obszar tekstury sf::IntRect
			///
			const sf::IntRect& GetImageRectangle() const;

		private:

			std::string		m_texture_name;	//nazwa tekstury
			sf::IntRect		m_rectangle;	//prostok�tny obszar tekstury
		};
	}//namespace animation
}//namespace rendering
#endif //H_ANIMATION_FRAME_JACK