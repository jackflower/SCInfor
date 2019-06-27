//  ___________________________________
// | Sprite.cpp - class implementation |
// | Jack Flower - February 2012       |
// |___________________________________|
//

#include "Sprite.h"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>

namespace rendering
{
	namespace displayable
	{
		RTTI_IMPL_NOPARENT(Sprite);

		//Konstruktor domyślny
		Sprite::Sprite()
		:
			sf::Sprite{}//konstruktor klasy bazowej
		{
		}

		//Destruktor
		Sprite::~Sprite()
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Sprite::getType() const
		{
			return rtti.getNameClass();
		}

	}//namespace displayable
}//namespace rendering
