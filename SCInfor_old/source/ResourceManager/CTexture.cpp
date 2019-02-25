//  _____________________________________
// | CTexture.cpp - class implementation |
// | Jack Flower - October 2013          |
// |_____________________________________|
//

#include "CTexture.h"

namespace resource
{
	RTTI_IMPL(CTexture, IResource);

	//Konstruktor
	CTexture::CTexture(void)
	:
		IResource	(),	//konstruktor klasy bazowej
		sf::Texture	()	//konstruktor klasy bazowej
	{
	}

	//Destruktor
	CTexture::~CTexture(void)
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CTexture::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda ładująca zasób - implementacja
	bool CTexture::load(const std::string &file_name)
	{
		if (loadFromFile(file_name))//jeśli dane zostały załadowane
			return true;			//zwracamy flagę true (ok)
		return false;				//false, jeśli program nie załadował pliku
	}

	//Wirtualna metoda zwalniająca zasób
	void CTexture::drop()
	{
		delete this;
	}
}//namespace resource
