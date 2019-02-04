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

	//Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
	void CEnemyTemplate::Drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CEnemyTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml
	bool CEnemyTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacj�, �e jest enemy
		if (xml.GetString(xml.GetRootNode(), "type") != "enemy")
			return false;

		//sprawdzamy, czy mo�na za�adowa� dane z klasy bazowej
		if (!CActorTemplate::Load(xml))
			return false;

		//reszta, gdyby klasa CEnemy (jej wzorzec CEnemyTemplate)
		//mia�a jakie� pola do wczytania i przekazania...

		return true;
	}

	//Metoda tworzy obiekt klasy CEnemy
	CEnemy* CEnemyTemplate::Create(std::wstring id)
	{

		//CEnemy* enemy = gPhysicalManager.CreateEnemy(id);
		//	float random =	gRand.Rndf( 0.0f, 1.0f );
		//TEN KOD - uzupe�ni� w  f a b r y k a c h !
		//	enemy->SetCategory(PHYSICAL_MONSTER);
		//TEN KOD - uzupe�ni� w  f a b r y k a c h !
		//	Fill(enemy,random);
		//	if ( mAi.size() > 0 )
		//	{
		//		std::wstring aiScheme = mAi[ gRand.Rnd( 0, static_cast<unsigned>(mAi.size()) ) ];
		//		enemy->GetAI()->SetScheme( gAISchemeManager.GetScheme(aiScheme) );
		//	}

		//return enemy;
	
		CEnemy* enemy = gPhysicalManager.CreateEnemy(id);
		Fill(enemy);
		return enemy;
	}

	//Wirtualna metoda wype�niaj�ca danymi obiekt klasy CEnemy
	void CEnemyTemplate::Fill(CEnemy *enemy)
	{
		CActorTemplate::Fill(enemy);
		//ewentualnie reszta
	}

}//namespace factory
