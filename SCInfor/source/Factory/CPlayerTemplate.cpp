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
	void CPlayerTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CPlayerTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CPlayerTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacjê, ¿e jest player
		if (xml.GetString(xml.GetRootNode(), "type") != "player")
			return false;

		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej
		if (!CActorTemplate::Load(xml))
			return false;

		//reszta, gdyby klasa CPlayer (jej wzorzec CPlayerTemplate)
		//mia³y jakieœ pola do wczytania i przekazania...

		return true;
	}

	//Metoda tworzy obiekt klasy CPlayer
	CPlayer* CPlayerTemplate::Create(std::wstring id)
	{
		CPlayer* player = gPhysicalManager.CreatePlayer(id);
		Fill(player);
		//gdyby by³y jakieœ pola do przekazania, nale¿y to uczyniæ...
		return player;
	}
}//namespace factory
