//  ______________________________________
// | HudSprite.h - class definition       |
// | Jack Flower October 2012             |
// |______________________________________|
//

#ifndef H_HUD_SPRITE_JACK
#define H_HUD_SPRITE_JACK

#include "../Drawable/Drawable.h"
#include <SFML/Graphics/Rect.hpp>

///
///Forward declaration
///
namespace displayable
{
	class ClippedSprite;
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
	class HudSprite : public Drawable
	{
		RTTI_DECL;
	public:

		///
		///Konstruktor
		///
		HudSprite();

		///
		///Destruktor wirtualny
		///
		virtual ~HudSprite();

		///
		///Metoda zwraca wskaźnik na obiekt klasy sf::Sprite
		///
		sf::Sprite *getSprite();

		///
		///Metoda zwraca wskaźnik na obiekt klasy ClippedSprite
		///
		ClippedSprite *getClippedSprite();

		///
		///Metoda ustawia obszar przycinania
		///
		///@param left - współrzędna bezwzględna
		///
		///@param top - współrzędna bezwzględna
		///
		///@param right - współrzędna bezwzględna
		///
		///@param bottom - współrzędna bezwzględna
		///
		void setClipRect(int left, int top, int right, int bottom);
		
		///
		///Metoda ustawia obszar przycinania
		///
		///@param rect - stała referencja na obiekt klasy sf::FloatRect
		///
		void setClipRect(const sf::FloatRect & rect); 

		///
		///Wirtualna metoda renderująca obiekt klasy HudSprite
		///
		///@render render_window - parametr drawable
		///
		virtual void draw(sf::RenderWindow *render_window);

	private:
		
		ClippedSprite *m_sprite; //wskaźnik na obiekt klasy ClippedSprite
		bool m_clip_rect_enabled; //flaga określająca, czy jest włączone przycinanie
		int m_clip_rect[4]; //tablica na wierzchołków
	};

} //namespace displayable
#endif //H_HUD_SPRITE_JACK
