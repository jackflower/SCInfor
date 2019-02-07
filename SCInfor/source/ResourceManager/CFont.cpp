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

	//Wirtualna metoda ³aduj¹ca zasób - implementacja
	bool CFont::load(const std::string &file_name)
	{
		if (loadFromFile(file_name))//jeœli dane zosta³y za³adowane
			return true;			//zwracamy flagê true (ok)
		return false;				//false, jeœli program nie za³adowa³ pliku
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CFont::drop()
	{
		delete this;
	}
}//namespace resource
