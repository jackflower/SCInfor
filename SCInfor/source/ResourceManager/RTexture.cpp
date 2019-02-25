//  _____________________________________
// | RTexture.cpp - class implementation |
// | Jack Flower - October 2013          |
// |_____________________________________|
//

#include "RTexture.h"

namespace resource
{
	RTTI_IMPL(RTexture, Resource);

	//Konstruktor
	RTexture::RTexture()
	:
		Resource{}, //konstruktor klasy bazowej
		sf::Texture{} //konstruktor klasy bazowej
	{
	}

	//Destruktor
	RTexture::~RTexture()
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string RTexture::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda ładująca zasób - implementacja
	bool RTexture::load(const std::string & file_name)
	{
		if (loadFromFile(file_name))//jeśli dane zostały załadowane
			return true;			//zwracamy flagę true (ok)
		return false;				//false, jeśli program nie załadował pliku
	}

	//Wirtualna metoda zwalniająca zasób
	void RTexture::drop()
	{
		delete this;
	}
}//namespace resource
