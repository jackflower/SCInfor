//  _____________________________________________
// | CMonsterTemplate.h - class definition       |
// | SCI - January 2014                          |
// |_____________________________________________|
//

#ifndef H_MONSTER_TEMPLATE_JACK
#define H_MONSTER_TEMPLATE_JACK

#include "CActorTemplate.h"
#include "../Logic/Monster/CMonster.h"
#include <string>
#include <vector>

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
	class CMonsterTemplate : public CActorTemplate
	{

	public:

		///
		///Konstruktor
		///
		CMonsterTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CMonsterTemplate();

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CMonster
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CMonster* Create(std::wstring id = L"");

	private:

		///
		///Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CMonster
		///
		///@param *actor - wskaŸnik na obiekt klasy CMonster
		///
		virtual void Fill(CMonster *monster);

		//gdyby w klasie CMonster by³y jakieœ pola
		//to tutaj, w klasie jej fabryki,
		//nale¿a³oby utworzyæ takie same pola,
		//aby fabryka by³a kompletna i mog³a uzbroiæ potwora
		//w te pola, które s¹ w jej klasie bazowej CActor
		//i jej w³asne - tylko pola nale¿¹ce do tej klasy (potwora)

	};
}//namespace factory
#endif //H_MONSTER_TEMPLATE_JACK
