//  _______________________________________
// | CHudSprite.h - class definition       |
// | Jack Flower October 2012              |
// |_______________________________________|
//

#ifndef _H_HUD_SPRITE_JACK
#define _H_HUD_SPRITE_JACK

#include "../Drawable/IDrawable.h"
#include <SFML/Graphics/Rect.hpp>

///
///Forward declaration
///
namespace displayable
{
	class CClippedSprite;
}

///
///Forward declaration
///
namespace sf
{
    class Sprite;
    class RenderWindow;
}

using namespace rendering::drawable;

namespace displayable
{

	///
	///Klasa reprezentuje sprite'a HUD - sprite "przyklejonego" do kamery
	///
	class CHudSprite : public IDrawable
	{
		RTTI_DECL;
	public:

		///
		///Konstruktor
		///
		CHudSprite();

		///
		///Destruktor wirtualny
		///
		virtual ~CHudSprite();

		///
		///Metoda zwraca wska�nik na obiekt klasy CClippedSprite
		///
		sf::Sprite* GetSprite();

		///
		///Metoda zwraca wska�nik na obiekt klasy CClippedSprite
		///
		CClippedSprite* GetClippedSprite();

		///
		///Metoda ustawia obszar przycinania
		///
		///@param left - wsp�rz�dna bezwzgl�dna
		///
		///@param top - wsp�rz�dna bezwzgl�dna
		///
		///@param right - wsp�rz�dna bezwzgl�dna
		///
		///@param bottom - wsp�rz�dna bezwzgl�dna
		///
		void SetClipRect(int left, int top, int right, int bottom);
		
		///
		///Metoda ustawia obszar przycinania
		///
		///@param &rect - sta�a referencja na obiekt klasy sf::FloatRect
		///
		void SetClipRect(const sf::FloatRect& rect); 

		///
		///Wirtualna metoda renderuj�ca obiekt klasy CHudSprite
		///
		///@render render_window - parametr drawable
		///
		virtual void Draw(sf::RenderWindow* render_window);

	private:
		
		CClippedSprite*		m_sprite;				//wska�nik na obiekt klasy CClippedSprite
		bool				m_clip_rect_enabled;	//flaga okre�laj�ca, czy jest w��czone przycinanie
		int					m_clip_rect[4];			//tablica na wierzcho�k�w
	};

} //namespace displayable
#endif //_H_HUD_SPRITE_JACK
