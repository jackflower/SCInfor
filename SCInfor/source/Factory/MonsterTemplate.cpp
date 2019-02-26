//  ____________________________________________
// | MonsterTemplate.cpp - class implementation |
// | SCI - January 2014                         |
// |____________________________________________|
//

#include "MonsterTemplate.h"
#include "../XML/Xml.h"
#include "../Logic/PhysicalManager.h"

namespace factory
{
	//Konstruktor
	MonsterTemplate::MonsterTemplate()
	:
		ActorTemplate()//konstruktor klasy bazowej
	{
	} 

	//Destruktor wirtualny
	MonsterTemplate::~MonsterTemplate()
	{
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void MonsterTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool MonsterTemplate::load(const std::string & name)
	{
		Xml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool MonsterTemplate::load(Xml & xml)
	{
		//sprawdzamy, czy xml zawiera informację, że jest potwór
		if (xml.getString(xml.getRootNode(), "type") != "monster")
			return false;

		//sprawdzamy, czy można załadować dane z klasy bazowej
		if (!ActorTemplate::load(xml))
			return false;

		//gdyby w klasie Monster były jakieś pola
		//to tutaj, w klasie jej fabryki
		//należałoby wczytać te pola z pliku xml,
		//aby fabryka była kompletna

		return true;
	}

	//Metoda tworzy obiekt klasy Monster
	Monster *MonsterTemplate::create(std::wstring id)
	{
		Monster *monster = gPhysicalManager.createMonster(id);
		fill(monster);

		//gdyby w klasie Monster były jakieś pola
		//to tutaj, neleżałoby te pola przekazać z fabryki do potwora,
		//aby fabryka była kompletna

		return monster;
	}

	//Wirtualna metoda wypełniająca danymi obiekt klasy Monster
	void MonsterTemplate::fill(Monster *monster)
	{
		ActorTemplate::fill(monster);
		//ewentualnie reszta
	}
}//namespace factory
