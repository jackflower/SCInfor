//  ___________________________________________
// | CClippedSprite.h - class definition       |
// | Jack Flower February 2012                 |
// |___________________________________________|
//

#ifndef _H_CLIPPED_SPRITE_JACK
#define _H_CLIPPED_SPRITE_JACK

#include <SFML/Graphics/Sprite.hpp>
#include "../../RTTI/RTTI.h"

namespace displayable
{

	///
	///Klasa reprezentuje mechanizm obcinania (przycinania) (ang. clipping) p�aszczyzny do zadanych rozmiar�w
	///
	class CClippedSprite : public sf::Sprite
	{
		RTTI_DECL;	//uwaga - musimy przyj�� za�o�enie, �e klasa CSprite 
					//nie dziedziczy (dziedziczy po sf::Sprite), poniewa�
					//klasa sf::Sprite to biblioteka, kt�rej nie mo�emy
					//modyfikowa�

	public:
		///
		///Konstruktor domy�lny
		///
		CClippedSprite();

		///
		///Metoda w��cza przycinanie
		///
		void EnableClipPlane(); 

		///
		///Metoda wy��cza przycinanie
		///
		void DisableClipPlane();

		///
		///Metoda ustawia p�aszczyzn�-prost� przycinania
		///
		///@param a - wsp�czynnik prostej
		///
		///@param b - wsp�czynnik prostej
		///
		///@param c - wsp�czynnik prostej
		///
		void SetClipPlane(float a, float b, float c) 
		{ 
			m_A = a; 
			m_B = b; 
			m_C = c; 
		}

		///
		///Wirtualna metoda renderingu
		///
		///@param &renderTarget - referencja na obiekt klasy sf::RenderTarget
		///
		//virtual void Render(sf::RenderTarget &renderTarget) const;

	private:

		bool m_clip_plane_enabled;	//Flaga okre�laj�ca, czy generowa� przycinanie p�aszczyzny
		float m_A;					//Wsp�czynnik p�aszczyzny-prostej obcinaj�cej
		float m_B;					//Wsp�czynnik p�aszczyzny-prostej obcinaj�cej
		float m_C;					//Wsp�czynnik p�aszczyzny-prostej obcinaj�cej
									//Uk�ad wsp�rzednych przeskalowanego tak,
									//aby punkt [1.0,1.0] byl prawym dolnym rogiem sprite'a
	};
} //namespace displayable
#endif//_H_CLIPPED_SPRITE_JACK
