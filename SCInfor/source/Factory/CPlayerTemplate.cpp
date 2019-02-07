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

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CPlayerTemplate::drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CPlayerTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CPlayerTemplate::load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacjê, ¿e jest player
		if (xml.GetString(xml.GetRootNode(), "type") != "player")
			return false;

		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej
		if (!CActorTemplate::load(xml))
			return false;

		//reszta, gdyby klasa CPlayer (jej wzorzec CPlayerTemplate)
		//mia³y jakieœ pola do wczytania i przekazania...

		return true;
	}

	//Metoda tworzy obiekt klasy CPlayer
	CPlayer* CPlayerTemplate::create(std::wstring id)
	{
		CPlayer* player = gPhysicalManager.CreatePlayer(id);
		fill(player);
		//gdyby by³y jakieœ pola do przekazania, nale¿y to uczyniæ...
		return player;
	}
}//namespace factory
