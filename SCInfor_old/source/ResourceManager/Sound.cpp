//  __________________________________
// | Sound.cpp - class implementation |
// | Jack Flower - October 2013       |
// |__________________________________|
//

#include "Sound.h"

namespace resource
{
	RTTI_IMPL(Sound, IResource);

	//Konstruktor
	Sound::Sound()
	:
		IResource{}, //konstruktor klasy bazowej
		sf::SoundBuffer{} //konstruktor klasy bazowej
	{
	}

	//Destruktor
	Sound::~Sound()
	{
		//~IResource()
		//~sf::SoundBuffer()
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Sound::getType() const
	{
		return rtti.GetNameClass();
	}
		
	//Wirtualna metoda ładująca zasób - implementacja
	bool Sound::load(const std::string &file_name)
	{
		if (loadFromFile(file_name))//jeśli dane zostały załadowane
			return true;			//zwracamy flagę true (ok)
		return false;				//false, jeśli program nie załadował pliku
	}

	//Wirtualna metoda zwalniająca zasób
	void Sound::drop()
	{
		delete this;
	}
}//namespace resource
