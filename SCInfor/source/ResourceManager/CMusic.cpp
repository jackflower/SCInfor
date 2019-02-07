//  ___________________________________
// | CMusic.cpp - class implementation |
// | Jack Flower - October 2013        |
// |___________________________________|
//

#include "CMusic.h"

namespace resource
{
	RTTI_IMPL(CMusic, IResource);

	//Konstruktor
	CMusic::CMusic(void)
	:
		IResource	(),	//konstruktor klasy bazowej
		sf::Music	()	//konstruktor klasy bazowej
	{
	}

	//Destruktor
	CMusic::~CMusic(void)
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CMusic::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda �aduj�ca zas�b - implementacja
	bool CMusic::load(const std::string &file_name)
	{
		if (openFromFile(file_name))//je�li dane zosta�y za�adowane
			return true;			//zwracamy flag� true (ok)
		return false;				//false, je�li program nie za�adowa� pliku
	}

	//Wirtualna metoda zwalniaj�ca zas�b
	void CMusic::drop()
	{
		delete this;
	}
}//namespace resource
