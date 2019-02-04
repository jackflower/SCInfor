//  ___________________________________
// | CSound.cpp - class implementation |
// | Jack Flower - October 2013        |
// |___________________________________|
//

#include "CSound.h"

namespace resource
{
	RTTI_IMPL(CSound, IResource);

	//Konstruktor
	CSound::CSound(void)
	:
		IResource		(),	//konstruktor klasy bazowej
		sf::SoundBuffer	()	//konstruktor klasy bazowej
	{
	}

	//Destruktor
	CSound::~CSound(void)
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CSound::GetType() const
	{
		return rtti.GetNameClass();
	}
		
	//Wirtualna metoda �aduj�ca zas�b - implementacja
	bool CSound::Load(const std::string &file_name)
	{
		if (loadFromFile(file_name))//je�li dane zosta�y za�adowane
			return true;			//zwracamy flag� true (ok)
		return false;				//false, je�li program nie za�adowa� pliku
	}

	//Wirtualna metoda zwalniaj�ca zas�b
	void CSound::Drop()
	{
		delete this;
	}
}//namespace resource
