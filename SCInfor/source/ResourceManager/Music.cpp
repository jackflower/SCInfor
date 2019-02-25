//  __________________________________
// | Music.cpp - class implementation |
// | Jack Flower - October 2013       |
// |__________________________________|
//

#include "Music.h"

namespace resource
{
	RTTI_IMPL(Music, Resource);

	//Konstruktor
	Music::Music()
	:
		Resource{}, //konstruktor klasy bazowej
		sf::Music{}	//konstruktor klasy bazowej
	{
	}

	//Destruktor
	Music::~Music()
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Music::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda ładująca zasób - implementacja
	bool Music::load(const std::string & file_name)
	{
		if (openFromFile(file_name))//jeśli dane zostały załadowane
			return true;			//zwracamy flagę true (ok)
		return false;				//false, jeśli program nie załadował pliku
	}

	//Wirtualna metoda zwalniająca zasób
	void Music::drop()
	{
		delete this;
	}
}//namespace resource
