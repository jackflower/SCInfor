﻿//  ____________________________________________
// | MonsterTemplate.h - class definition       |
// | SCI - January 2014                         |
// |____________________________________________|
//

#ifndef H_MONSTER_TEMPLATE_JACK
#define H_MONSTER_TEMPLATE_JACK

#include "ActorTemplate.h"
#include "../Logic/Monster/CMonster.h"


///
///Forward declaration
///
namespace xml
{
	class CXml;
}

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec potwora
	///
	class MonsterTemplate : public ActorTemplate
	{

	public:

		///
		///Konstruktor
		///
		MonsterTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~MonsterTemplate();

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy CMonster
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CMonster *create(std::wstring id = L"");

	private:

		///
		///Wirtualna metoda wypełniająca danymi obiekt klasy CMonster
		///
		///@param *actor - wskaźnik na obiekt klasy CMonster
		///
		virtual void fill(CMonster *monster);

		//gdyby w klasie CMonster były jakieś pola
		//to tutaj, w klasie jej fabryki,
		//należałoby utworzyć takie same pola,
		//aby fabryka była kompletna i mogła uzbroić potwora
		//w te pola, które są w jej klasie bazowej Actor
		//i jej własne - tylko pola należące do tej klasy (potwora)

	};
}//namespace factory
#endif //H_MONSTER_TEMPLATE_JACK
