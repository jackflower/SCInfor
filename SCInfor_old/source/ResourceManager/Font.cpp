//  _________________________________
// | Font.cpp - class implementation |
// | Jack Flower - October 2013      |
// |_________________________________|
//

#include "Font.h"

namespace resource
{
	RTTI_IMPL(Font, IResource);

	//Konstruktor
	Font::Font()
	:
		IResource{}, //konstruktor klasy bazowej
		sf::Font{} //konstruktor klasy bazowej
	{
	}

	//Konstruktor kopiujący
	Font::Font(const Font & copy)
	:
		//IResource{ copy }, //konstruktor kopiujący klasy bazowej
		sf::Font{ copy } //konstruktor kopiujący klasy bazowej
	{
	}

	//Konstruktor przenoszący
	Font::Font(Font && other)
	:
		//IResource{ other }, //konstruktor przenoszący klasy bazowej
		sf::Font{ other } //konstruktor przenoszący klasy bazowej
	{
	}

	//Destruktor
	Font::~Font()
	{
		//~IResource()
		//~sf::Font()
	}
	
	//Metoda zwraca typ obiektu /RTTI/
	const std::string Font::getType() const
	{
		return rtti.GetNameClass();
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
