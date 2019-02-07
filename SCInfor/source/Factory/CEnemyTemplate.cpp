//  ___________________________________________
// | CEnemyTemplate.cpp - class implementation |
// | Jack Flower - May 2013                    |
// |___________________________________________|
//

#include "CEnemyTemplate.h"

namespace factory
{
	RTTI_IMPL(CEnemyTemplate, CActorTemplate);

	//Konstruktor
	CEnemyTemplate::CEnemyTemplate()
	:
		CActorTemplate()
	{
	} 

	//Destruktor wirtualny
	CEnemyTemplate::~CEnemyTemplate()
	{
		m_enemy_AI.clear();
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEnemyTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CEnemyTemplate::drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CEnemyTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CEnemyTemplate::load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacjê, ¿e jest enemy
		if (xml.GetString(xml.GetRootNode(), "type") != "enemy")
			return false;

		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej
		if (!CActorTemplate::load(xml))
			return false;

		//reszta, gdyby klasa CEnemy (jej wzorzec CEnemyTemplate)
		//mia³a jakieœ pola do wczytania i przekazania...

		return true;
	}

	//Metoda tworzy obiekt klasy CEnemy
	CEnemy* CEnemyTemplate::create(std::wstring id)
	{

		//CEnemy* enemy = gPhysicalManager.CreateEnemy(id);
		//	float random =	gRand.Rndf( 0.0f, 1.0f );
		//TEN KOD - uzupe³niæ w  f a b r y k a c h !
		//	enemy->SetCategory(PHYSICAL_MONSTER);
		//TEN KOD - uzupe³niæ w  f a b r y k a c h !
		//	fill(enemy,random);
		//	if ( mAi.size() > 0 )
		//	{
		//		std::wstring aiScheme = mAi[ gRand.Rnd( 0, static_cast<unsigned>(mAi.size()) ) ];
		//		enemy->GetAI()->SetScheme( gAISchemeManager.GetScheme(aiScheme) );
		//	}

		//return enemy;
	
		CEnemy* enemy = gPhysicalManager.CreateEnemy(id);
		fill(enemy);
		return enemy;
	}

	//Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CEnemy
	void CEnemyTemplate::fill(CEnemy *enemy)
	{
		CActorTemplate::fill(enemy);
		//ewentualnie reszta
	}

}//namespace factory
