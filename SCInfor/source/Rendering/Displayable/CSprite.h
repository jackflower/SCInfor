//  ____________________________________
// | CSprite.h - class definition       |
// | Jack Flower - February 2012.       |
// |____________________________________|
//

#ifndef H_SPRITE_JACK
#define H_SPRITE_JACK

#include <SFML/Graphics/Sprite.hpp>
#include "../../RTTI/RTTI.h"

namespace rendering
{
	namespace displayable
	{
		///
		///Klasa reprezentuje opakowanie klasy sf::sprite
		///
		class CSprite : public sf::Sprite
		{

			RTTI_DECL;	//uwaga - musimy przyj�� za�o�enie, �e klasa CSprite 
						//nie dziedziczy (dziedziczy po sf::Sprite), poniewa�
						//klasa sf::Sprite to biblioteka, kt�rej nie mo�emy
						//modyfikowa�

		public:

			///
			///Konstruktor domy�lny
			///
			CSprite();

			///
			///Destruktor
			///
			~CSprite();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

		};
	}//namespace displayable
}//namespace rendering
#endif //_H_SPRITE_JACK
