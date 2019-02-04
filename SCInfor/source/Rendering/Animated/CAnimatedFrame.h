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
	///Klasa reprezentuje klatk� animacji
	//
	class CAnimatedFrame
	{
	public :
	
		///
		//Konstruktor domy�lny
		///
		CAnimatedFrame();
	
		///
		///Konstruktor kopiuj�cy
		///
		///@param & copy - sta�a referencja na obiekt klasy CAnimatedFrame
		///
		CAnimatedFrame(const CAnimatedFrame & copy);

		///
		///Konstruktor parametryczny
		///
		///@param & texture - tekstura
		///
		///@param & rectangle - obszar prostok�tny tekstury
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
		///Metoda zwraca sta�y wska�nik na tekstur� klatki animacji z wektora
		///
		const sf::Texture *GetFrameImage() const;

		///
		///Metoda zwraca koordynaty klatki animacji z wektora
		///
		const sf::IntRect GetFrameRectangle() const;

	private:

		const sf::Texture*	p_texture;		//wska�nik na tekstur�
		sf::IntRect			m_rectangle;	//obszar prostok�tny klatki animacji
	};
}//namespace animated
#endif // H_ANIMATED_FRAME_JACK
