//  ___________________________________________
// | CRobotTemplate.h - class definition       |
// | Jack Flower - June 2016                   |
// |___________________________________________|
//

#ifndef H_ROBOT_TEMPLATE_JACK
#define H_ROBOT_TEMPLATE_JACK

#include "CActorTemplate.h"
#include "../Logic/Unit/CombatUnit/Robot/CRobot.h"

using namespace logic::unit;

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec aktora
	///
	class CRobotTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CRobotTemplate();

		///
		///Destruktor wirtualny
		///
		~CRobotTemplate();

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

	protected:

		///
		///Metoda tworzy obiekt klasy CRobot
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CRobot* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CRobot
		///
		///@param *robot - wskaŸnik na obiekt klasy CRobot
		///
		virtual void fill(CRobot *robot);

	private:

		CStrategyDuration	m_templ_strategy_duration;	//opakowanie mechanizmu zarz¹dzania czasem stanów strategicznych

	};
}//namespace factory
#endif//H_ROBOT_TEMPLATE_JACK

