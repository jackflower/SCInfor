//  ____________________________________________
// | ResourceTexture.cpp - class implementation |
// | Jack Flower - October 2013                 |
// |____________________________________________|
//

#include "ResourceTexture.h"

namespace resource
{
	RTTI_IMPL(ResourceTexture, Resource);

	//Konstruktor
	ResourceTexture::ResourceTexture()
	:
		Resource{}, //konstruktor klasy bazowej
		sf::Texture{} //konstruktor klasy bazowej
	{
	}

	//Destruktor
	ResourceTexture::~ResourceTexture()
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string ResourceTexture::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda ładująca zasób - implementacja
	bool ResourceTexture::load(const std::string & file_name)
	{
		if (loadFromFile(file_name))//jeśli dane zostały załadowane
			return true;			//zwracamy flagę true (ok)
		return false;				//false, jeśli program nie załadował pliku
	}

	//Wirtualna metoda zwalniająca zasób
	void ResourceTexture::drop()
	{
		delete this;
	}
}//namespace resource
