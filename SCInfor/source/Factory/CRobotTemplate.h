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
		///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml
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
		///Wirtualna metoda wype�niaj�ca danymi obiekt klasy CRobot
		///
		///@param *robot - wska�nik na obiekt klasy CRobot
		///
		virtual void fill(CRobot *robot);

	private:

		CStrategyDuration	m_templ_strategy_duration;	//opakowanie mechanizmu zarz�dzania czasem stan�w strategicznych

	};
}//namespace factory
#endif//H_ROBOT_TEMPLATE_JACK

