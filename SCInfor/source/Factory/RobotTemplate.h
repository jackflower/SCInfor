//  __________________________________________
// | RobotTemplate.h - class definition       |
// | Jack Flower - June 2016                  |
// |__________________________________________|
//

#ifndef H_ROBOT_TEMPLATE_JACK
#define H_ROBOT_TEMPLATE_JACK

#include "ActorTemplate.h"
#include "../Logic/Unit/CombatUnit/Robot/CRobot.h"

using namespace logic::unit;

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec aktora
	///
	class RobotTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		RobotTemplate();

		///
		///Destruktor wirtualny
		///
		~RobotTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

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

	protected:

		///
		///Metoda tworzy obiekt klasy CRobot
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CRobot *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca danymi obiekt klasy CRobot
		///
		///@param *robot - wskaźnik na obiekt klasy CRobot
		///
		virtual void fill(CRobot *robot);

	private:

		CStrategyDuration m_templ_strategy_duration; //opakowanie mechanizmu zarządzania czasem stanów strategicznych

	};
}//namespace factory
#endif//H_ROBOT_TEMPLATE_JACK
