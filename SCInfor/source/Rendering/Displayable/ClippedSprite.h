//  __________________________________________
// | ClippedSprite.h - class definition       |
// | Jack Flower February 2012                |
// |__________________________________________|
//

#ifndef H_CLIPPED_SPRITE_JACK
#define H_CLIPPED_SPRITE_JACK

#include <SFML/Graphics/Sprite.hpp>
#include "../../RTTI/RTTI.h"

namespace displayable
{

	///
	///Klasa reprezentuje mechanizm obcinania (przycinania) (ang. clipping) płaszczyzny do zadanych rozmiarów
	///
	class ClippedSprite : public sf::Sprite
	{
		RTTI_DECL;	//uwaga - musimy przyjąć założenie, że klasa Sprite 
					//nie dziedziczy (dziedziczy po sf::Sprite), ponieważ
					//klasa sf::Sprite to biblioteka, której nie możemy
					//modyfikować

	public:
		///
		///Konstruktor domyślny
		///
		ClippedSprite();

		///
		///Metoda włącza przycinanie
		///
		void enableClipPlane(); 

		///
		///Metoda wyłącza przycinanie
		///
		void disableClipPlane();

		///
		///Metoda ustawia płaszczyznę-prostą przycinania
		///
		///@param a - współczynnik prostej
		///
		///@param b - współczynnik prostej
		///
		///@param c - współczynnik prostej
		///
		void setClipPlane(float a, float b, float c) 
		{ 
			m_A = a; 
			m_B = b; 
			m_C = c; 
		}

		///
		///Wirtualna metoda renderingu
		///
		///@param renderTarget - referencja na obiekt klasy sf::RenderTarget
		///
		//virtual void Render(sf::RenderTarget & renderTarget) const;

	private:

		bool m_clip_plane_enabled; //Flaga określająca, czy generować przycinanie płaszczyzny
		float m_A; //Współczynnik płaszczyzny-prostej obcinającej
		float m_B; //Współczynnik płaszczyzny-prostej obcinającej
		float m_C; //Współczynnik płaszczyzny-prostej obcinającej
        //Układ współrzednych przeskalowanego tak,
        //aby punkt [1.0,1.0] był prawym dolnym rogiem sprite'a
	};
} //namespace displayable
#endif//H_CLIPPED_SPRITE_JACK
