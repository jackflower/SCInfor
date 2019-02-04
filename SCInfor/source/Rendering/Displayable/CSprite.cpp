//  ____________________________________
// | CSprite.cpp - class implementation |
// | Jack Flower - February 2012        |
// |____________________________________|
//

#include "CSprite.h"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>

namespace rendering
{
	namespace displayable
	{
		RTTI_IMPL_NOPARENT(CSprite);

		//Konstruktor domyœlny
		CSprite::CSprite()
		:
			sf::Sprite()//konstruktor klasy bazowej
		{
		}

		//Destruktor
		CSprite::~CSprite()
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CSprite::GetType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace displayable
}//namespace rendering
