//  __________________________________________
// | EnemyTemplate.cpp - class implementation |
// | Jack Flower - May 2013                   |
// |__________________________________________|
//

#include "EnemyTemplate.h"

namespace factory
{
	RTTI_IMPL(EnemyTemplate, ActorTemplate);

	//Konstruktor
	EnemyTemplate::EnemyTemplate()
	:
		ActorTemplate()//konstruktor klasy bazowej
	{
	} 

	//Destruktor wirtualny
	EnemyTemplate::~EnemyTemplate()
	{
		m_enemy_AI.clear();
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EnemyTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void EnemyTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool EnemyTemplate::load(const std::string & name)
	{
		Xml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool EnemyTemplate::load(Xml & xml)
	{
		//sprawdzamy, czy xml zawiera informację, że jest enemy
		if (xml.getString(xml.getRootNode(), "type") != "enemy")
			return false;

		//sprawdzamy, czy można załadować dane z klasy bazowej
		if (!ActorTemplate::load(xml))
			return false;

		//reszta, gdyby klasa Enemy (jej wzorzec EnemyTemplate)
		//miała jakieś pola do wczytania i przekazania...

		return true;
	}

	//Metoda tworzy obiekt klasy Enemy
	Enemy* EnemyTemplate::create(std::wstring id)
	{
		//Enemy* enemy = gPhysicalManager.CreateEnemy(id);
		//	float random =	gRand.Rndf( 0.0f, 1.0f );
		//TEN KOD - uzupełnić w  f a b r y k a c h !
		//	enemy->SetCategory(PHYSICAL_MONSTER);
		//TEN KOD - uzupełnić w  f a b r y k a c h !
		//	fill(enemy,random);
		//	if ( mAi.size() > 0 )
		//	{
		//		std::wstring aiScheme = mAi[ gRand.Rnd( 0, static_cast<unsigned>(mAi.size()) ) ];
		//		enemy->GetAI()->SetScheme( gAISchemeManager.GetScheme(aiScheme) );
		//	}

		//return enemy;
	
		Enemy* enemy = gPhysicalManager.createEnemy(id);
		fill(enemy);
		return enemy;
	}

	//Wirtualna metoda wypełniająca danymi obiekt klasy Enemy
	void EnemyTemplate::fill(Enemy *enemy)
	{
		ActorTemplate::fill(enemy);
		//ewentualnie reszta
	}

}//namespace factory
