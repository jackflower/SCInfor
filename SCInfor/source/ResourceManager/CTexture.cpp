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

	//Wirtualna metoda ³aduj¹ca zasób - implementacja
	bool CTexture::Load(const std::string &file_name)
	{
		if (loadFromFile(file_name))//jeœli dane zosta³y za³adowane
			return true;			//zwracamy flagê true (ok)
		return false;				//false, jeœli program nie za³adowa³ pliku
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CTexture::Drop()
	{
		delete this;
	}
}//namespace resource
