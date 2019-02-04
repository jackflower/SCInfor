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

	//Wirtualna metoda �aduj�ca zas�b - implementacja
	bool CTexture::Load(const std::string &file_name)
	{
		if (loadFromFile(file_name))//je�li dane zosta�y za�adowane
			return true;			//zwracamy flag� true (ok)
		return false;				//false, je�li program nie za�adowa� pliku
	}

	//Wirtualna metoda zwalniaj�ca zas�b
	void CTexture::Drop()
	{
		delete this;
	}
}//namespace resource
