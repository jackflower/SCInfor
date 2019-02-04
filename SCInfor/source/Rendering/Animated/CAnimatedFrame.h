//  __________________________________________
// | CAnimatedFrame.h - class definition      |
// | Jack Flower - March 2009                 |
// | update May 2017                          |
// |__________________________________________|
//

#ifndef H_ANIMATED_FRAME_JACK
#define H_ANIMATED_FRAME_JACK

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace animated
{
	///
	///Klasa reprezentuje klatkê animacji
	//
	class CAnimatedFrame
	{
	public :
	
		///
		//Konstruktor domyœlny
		///
		CAnimatedFrame();
	
		///
		///Konstruktor kopiuj¹cy
		///
		///@param & copy - sta³a referencja na obiekt klasy CAnimatedFrame
		///
		CAnimatedFrame(const CAnimatedFrame & copy);

		///
		///Konstruktor parametryczny
		///
		///@param & texture - tekstura
		///
		///@param & rectangle - obszar prostok¹tny tekstury
		///
		CAnimatedFrame(const sf::Texture & texture, const sf::IntRect & rectangle);

		///
		///Konstruktor parametryczny
		///
		///@param & texture - tekstura
		///
		CAnimatedFrame(const sf::Texture & texture);
	
		///
		///Destruktor
		///
		~CAnimatedFrame();

		///
		///Metoda zwraca sta³y wskaŸnik na teksturê klatki animacji z wektora
		///
		const sf::Texture *GetFrameImage() const;

		///
		///Metoda zwraca koordynaty klatki animacji z wektora
		///
		const sf::IntRect GetFrameRectangle() const;

	private:

		const sf::Texture*	p_texture;		//wskaŸnik na teksturê
		sf::IntRect			m_rectangle;	//obszar prostok¹tny klatki animacji
	};
}//namespace animated
#endif // H_ANIMATED_FRAME_JACK
