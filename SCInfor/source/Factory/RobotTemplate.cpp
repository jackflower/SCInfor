//  __________________________________________
// | RobotTemplate.cpp - class implementation |
// | Jack Flower - June 2016                  |
// |__________________________________________|
//

#include "RobotTemplate.h"
#include "../Rendering/Animations/CAnimSet.h"

//using namespace resource;

namespace factory
{
	RTTI_IMPL(RobotTemplate, ActorTemplate);

	//Konstruktor
	RobotTemplate::RobotTemplate()
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_templ_strategy_duration()
	{
	}

	//Destruktor wirtualny
	RobotTemplate::~RobotTemplate()
	{
		//~ActorTemplate()
		//m_templ_strategy_duration
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string RobotTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void RobotTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool RobotTemplate::load(const std::string & name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool RobotTemplate::load(CXml & xml)
	{
		//ładowanie danych klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//dane opakowania mechanizmu zarządzania czasem stanów strategicznych obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "strategy_duration_data"))
		{
			m_templ_strategy_duration.setTimeAttackPrepare(xml.GetFloat(node, "time_attack_prepare"));
			m_templ_strategy_duration.setTimeAttackTerminate(xml.GetFloat(node, "time_attack_terminate"));
			m_templ_strategy_duration.setTimeDefensePrepare(xml.GetFloat(node, "time_defense_prepare"));
			m_templ_strategy_duration.setTimeDefenseTerminate(xml.GetFloat(node, "time_defense_terminate"));
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Robot
	Robot *RobotTemplate::create(std::wstring id)
	{
		Robot *robot = gPhysicalManager.CreateRobot(id);
		fill(robot);
		return robot;
	}

	//Wirtualna metoda wypełniająca danymi obiekt klasy Robot
	void RobotTemplate::fill(Robot *robot)
	{
		if (robot)
		{
			ActorTemplate::fill(robot);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				robot->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetRobotBodyDefaultAnim() != NULL)
					robot->setAnimationBody(p_templ_animations->GetRobotBodyDefaultAnim());

				//head
				if (p_templ_animations->GetRobotHeadDefaultAnim() != NULL)
					robot->setAnimationHead(p_templ_animations->GetRobotHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			robot->setStrategyDuration(m_templ_strategy_duration);
		}
	}
}//namespace factory
