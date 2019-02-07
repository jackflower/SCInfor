//  ___________________________________________
// | CEnemyTemplate.h - class definition       |
// | Jack Flower - November 2012               |
// |___________________________________________|
//

#ifndef H_ENEMY_TEMPLATE_JACK
#define H_ENEMY_TEMPLATE_JACK

#include "CActorTemplate.h"
#include "../Logic/Enemy/CEnemy.h"
#include <string>
#include <vector>

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec wrogiej jednostki
	///
	class CEnemyTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEnemyTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CEnemyTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CEnemy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CEnemy* create(std::wstring id = L"");

	protected:

		///
		///Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CEnemy
		///
		///@param *enemy - wskaŸnik na obiekt klasy CEnemy
		///
		virtual void fill(CEnemy *enemy);


	private:

		std::vector<std::wstring> m_enemy_AI;	//kontener nazw dostêpnych schematów AI wroga...to do...
	};
}//namespace factory
#endif //H_ENEMY_TEMPLATE_JACK
