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
	///Klasa reprezentuje mechanizm obcinania (przycinania) (ang. clipping) p³aszczyzny do zadanych rozmiarów
	///
	class CClippedSprite : public sf::Sprite
	{
		RTTI_DECL;	//uwaga - musimy przyj¹æ za³o¿enie, ¿e klasa CSprite 
					//nie dziedziczy (dziedziczy po sf::Sprite), poniewa¿
					//klasa sf::Sprite to biblioteka, której nie mo¿emy
					//modyfikowaæ

	public:
		///
		///Konstruktor domyœlny
		///
		CClippedSprite();

		///
		///Metoda w³¹cza przycinanie
		///
		void EnableClipPlane(); 

		///
		///Metoda wy³¹cza przycinanie
		///
		void DisableClipPlane();

		///
		///Metoda ustawia p³aszczyznê-prost¹ przycinania
		///
		///@param a - wspó³czynnik prostej
		///
		///@param b - wspó³czynnik prostej
		///
		///@param c - wspó³czynnik prostej
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

		bool m_clip_plane_enabled;	//Flaga okreœlaj¹ca, czy generowaæ przycinanie p³aszczyzny
		float m_A;					//Wspó³czynnik p³aszczyzny-prostej obcinaj¹cej
		float m_B;					//Wspó³czynnik p³aszczyzny-prostej obcinaj¹cej
		float m_C;					//Wspó³czynnik p³aszczyzny-prostej obcinaj¹cej
									//Uk³ad wspó³rzednych przeskalowanego tak,
									//aby punkt [1.0,1.0] byl prawym dolnym rogiem sprite'a
	};
} //namespace displayable
#endif//_H_CLIPPED_SPRITE_JACK
