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

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CMonsterTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CMonsterTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CMonsterTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacjê, ¿e jest potwór
		if (xml.GetString(xml.GetRootNode(), "type") != "monster")
			return false;

		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej
		if (!CActorTemplate::Load(xml))
			return false;

		//gdyby w klasie CMonster by³y jakieœ pola
		//to tutaj, w klasie jej fabryki
		//nale¿a³oby wczytaæ te pola z pliku xml,
		//aby fabryka by³a kompletna

		return true;
	}

	//Metoda tworzy obiekt klasy CMonster
	CMonster* CMonsterTemplate::Create(std::wstring id)
	{
		CMonster* monster = gPhysicalManager.CreateMonster(id);
		Fill(monster);

		//gdyby w klasie CMonster by³y jakieœ pola
		//to tutaj, nele¿a³oby te pola przekazaæ z fabryki do potwora,
		//aby fabryka by³a kompletna

		return monster;
	}

	//Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CMonster
	void CMonsterTemplate::Fill(CMonster *monster)
	{
		CActorTemplate::Fill(monster);
		//ewentualnie reszta
	}

}//namespace factory