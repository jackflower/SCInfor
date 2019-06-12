//  __________________________________________
// | RobotTemplate.cpp - class implementation |
// | Jack Flower - June 2016                  |
// |__________________________________________|
//

#include "RobotTemplate.h"
#include "../Rendering/Animations/AnimSet.h"

//using namespace resource;

namespace factory
{
	RTTI_IMPL(RobotTemplate, ActorTemplate);

	//Konstruktor
	RobotTemplate::RobotTemplate()
	:
		ActorTemplate{},//konstruktor klasy bazowej
		m_templ_strategy_duration{}
	{
	}

	//Destruktor wirtualny
	RobotTemplate::~RobotTemplate()
	{
		//~ActorTemplate()
		m_templ_strategy_duration;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string RobotTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void RobotTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool RobotTemplate::load(const std::string & name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool RobotTemplate::load(Xml & xml)
	{
		//ładowanie danych klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//dane opakowania mechanizmu zarządzania czasem stanów strategicznych obiektu
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "strategy_duration_data"))
		{
			m_templ_strategy_duration.setTimeAttackPrepare(xml.getFloat(node, "time_attack_prepare"));
			m_templ_strategy_duration.setTimeAttackTerminate(xml.getFloat(node, "time_attack_terminate"));
			m_templ_strategy_duration.setTimeDefensePrepare(xml.getFloat(node, "time_defense_prepare"));
			m_templ_strategy_duration.setTimeDefenseTerminate(xml.getFloat(node, "time_defense_terminate"));
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Robot
	Robot *RobotTemplate::create(std::wstring id)
	{
		Robot *robot = gPhysicalManager.createRobot(id);
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
				if (p_templ_animations->getRobotBodyDefaultAnim() != nullptr)
					robot->setAnimationBody(p_templ_animations->getRobotBodyDefaultAnim());

				//head
				if (p_templ_animations->getRobotHeadDefaultAnim() != nullptr)
					robot->setAnimationHead(p_templ_animations->getRobotHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			robot->setStrategyDuration(m_templ_strategy_duration);
		}
	}
}//namespace factory
