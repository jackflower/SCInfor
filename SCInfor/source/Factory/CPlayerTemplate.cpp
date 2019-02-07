//  ____________________________________________
// | CPlayerTemplate.cpp - class implementation |
// | Jack Flower - May 2013                     |
// |____________________________________________|
//

#include "CPlayerTemplate.h"
#include "../XML/CXml.h"
#include "../Logic/CPhysicalManager.h"

namespace factory
{
	RTTI_IMPL(CPlayerTemplate, CActorTemplate);

	//Konstruktor
	CPlayerTemplate::CPlayerTemplate()
	:
		CActorTemplate()
	{
	} 

	//Destruktor wirtualny
	CPlayerTemplate::~CPlayerTemplate()
	{
		m_player_AI.clear();
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPlayerTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
	void CPlayerTemplate::drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CPlayerTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml
	bool CPlayerTemplate::load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacj�, �e jest player
		if (xml.GetString(xml.GetRootNode(), "type") != "player")
			return false;

		//sprawdzamy, czy mo�na za�adowa� dane z klasy bazowej
		if (!CActorTemplate::load(xml))
			return false;

		//reszta, gdyby klasa CPlayer (jej wzorzec CPlayerTemplate)
		//mia�y jakie� pola do wczytania i przekazania...

		return true;
	}

	//Metoda tworzy obiekt klasy CPlayer
	CPlayer* CPlayerTemplate::create(std::wstring id)
	{
		CPlayer* player = gPhysicalManager.CreatePlayer(id);
		fill(player);
		//gdyby by�y jakie� pola do przekazania, nale�y to uczyni�...
		return player;
	}
}//namespace factory
