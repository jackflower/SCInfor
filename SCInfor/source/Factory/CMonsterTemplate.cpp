//  _____________________________________________
// | CMonsterTemplate.cpp - class implementation |
// | SCI - January 2014                          |
// |_____________________________________________|
//

#include "CMonsterTemplate.h"
#include "../XML/CXml.h"
#include "../Logic/CPhysicalManager.h"

namespace factory
{
	//Konstruktor
	CMonsterTemplate::CMonsterTemplate()
	:
		CActorTemplate()//konstruktor klasy bazowej
	{
	} 

	//Destruktor wirtualny
	CMonsterTemplate::~CMonsterTemplate()
	{
	}

	//Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
	void CMonsterTemplate::drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CMonsterTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml
	bool CMonsterTemplate::load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacj�, �e jest potw�r
		if (xml.GetString(xml.GetRootNode(), "type") != "monster")
			return false;

		//sprawdzamy, czy mo�na za�adowa� dane z klasy bazowej
		if (!CActorTemplate::load(xml))
			return false;

		//gdyby w klasie CMonster by�y jakie� pola
		//to tutaj, w klasie jej fabryki
		//nale�a�oby wczyta� te pola z pliku xml,
		//aby fabryka by�a kompletna

		return true;
	}

	//Metoda tworzy obiekt klasy CMonster
	CMonster* CMonsterTemplate::create(std::wstring id)
	{
		CMonster* monster = gPhysicalManager.CreateMonster(id);
		fill(monster);

		//gdyby w klasie CMonster by�y jakie� pola
		//to tutaj, nele�a�oby te pola przekaza� z fabryki do potwora,
		//aby fabryka by�a kompletna

		return monster;
	}

	//Wirtualna metoda wype�niaj�ca danymi obiekt klasy CMonster
	void CMonsterTemplate::fill(CMonster *monster)
	{
		CActorTemplate::fill(monster);
		//ewentualnie reszta
	}

}//namespace factory