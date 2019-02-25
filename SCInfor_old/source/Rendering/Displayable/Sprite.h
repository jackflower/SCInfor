//  ___________________________________
// | Sprite.h - class definition       |
// | Jack Flower - February 2012       |
// |___________________________________|
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
		class Sprite : public sf::Sprite
		{

			RTTI_DECL;	//uwaga - musimy przyjąć założenie, że klasa Sprite 
						//nie dziedziczy (dziedziczy po sf::Sprite), ponieważ
						//klasa sf::Sprite to biblioteka, której nie możemy
						//modyfikować

		public:

			///
			///Konstruktor domyślny
			///
			Sprite();

			///
			///Destruktor
			///
			~Sprite();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

		};
	}//namespace displayable
}//namespace rendering
#endif //H_SPRITE_JACK

