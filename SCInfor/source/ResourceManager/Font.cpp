//  _________________________________
// | Font.cpp - class implementation |
// | Jack Flower - October 2013      |
// |_________________________________|
//

#include "Font.h"

namespace resource
{
	RTTI_IMPL(Font, Resource);

	//Konstruktor
	Font::Font()
	:
		Resource{}, //konstruktor klasy bazowej
		sf::Font{} //konstruktor klasy bazowej
	{
	}

	//Destruktor
	Font::~Font()
	{
	}
	
	//Metoda zwraca typ obiektu /RTTI/
	const std::string Font::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda ładująca zasób - implementacja
	bool Font::load(const std::string & file_name)
	{
		if (loadFromFile(file_name))//jeśli dane zostały załadowane
			return true;			//zwracamy flagę true (ok)
		return false;				//false, jeśli program nie załadował pliku
	}

	//Wirtualna metoda zwalniająca zasób
	void Font::drop()
	{
		delete this;
	}
}//namespace resource
