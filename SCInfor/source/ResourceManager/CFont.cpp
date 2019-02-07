//  __________________________________
// | CFont.cpp - class implementation |
// | Jack Flower - October 2013       |
// |__________________________________|
//

#include "CFont.h"

namespace resource
{
	RTTI_IMPL(CFont, IResource);

	//Konstruktor
	CFont::CFont(void)
	:
		IResource	(),	//konstruktor klasy bazowej
		sf::Font	()	//konstruktor klasy bazowej
	{
	}

	//Destruktor
	CFont::~CFont(void)
	{
	}
	
	//Metoda zwraca typ obiektu /RTTI/
	const std::string CFont::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda �aduj�ca zas�b - implementacja
	bool CFont::load(const std::string &file_name)
	{
		if (loadFromFile(file_name))//je�li dane zosta�y za�adowane
			return true;			//zwracamy flag� true (ok)
		return false;				//false, je�li program nie za�adowa� pliku
	}

	//Wirtualna metoda zwalniaj�ca zas�b
	void CFont::drop()
	{
		delete this;
	}
}//namespace resource
