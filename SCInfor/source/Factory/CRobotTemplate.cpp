//  ___________________________________________
// | CRobotTemplate.cpp - class implementation |
// | Jack Flower - June 2016                   |
// |___________________________________________|
//

#include "CRobotTemplate.h"
#include "../Rendering/Animations/CAnimSet.h"

//using namespace resource;

namespace factory
{
	RTTI_IMPL(CRobotTemplate, CActorTemplate);

	//Konstruktor
	CRobotTemplate::CRobotTemplate()
	:
		CActorTemplate				(),//konstruktor klasy bazowej
		m_templ_strategy_duration	()
	{
	}

	//Destruktor wirtualny
	CRobotTemplate::~CRobotTemplate()
	{
		//m_templ_strategy_duration	not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CRobotTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CRobotTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CRobotTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CRobotTemplate::Load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//dane opakowania mechanizmu zarz¹dzania czasem stanów strategicznych obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "strategy_duration_data"))
		{
			m_templ_strategy_duration.setTimeAttackPrepare(xml.GetFloat(node, "time_attack_prepare"));
			m_templ_strategy_duration.setTimeAttackTerminate(xml.GetFloat(node, "time_attack_terminate"));
			m_templ_strategy_duration.setTimeDefensePrepare(xml.GetFloat(node, "time_defense_prepare"));
			m_templ_strategy_duration.setTimeDefenseTerminate(xml.GetFloat(node, "time_defense_terminate"));
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CRobot
	CRobot* CRobotTemplate::Create(std::wstring id)
	{
		CRobot* robot = gPhysicalManager.CreateRobot(id);
		Fill(robot);
		return robot;
	}

	//Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CRobot
	void CRobotTemplate::Fill(CRobot *robot)
	{
		if (robot)
		{
			CActorTemplate::Fill(robot);

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				robot->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetRobotBodyDefaultAnim() != NULL)
					robot->SetAnimationBody(p_templ_animations->GetRobotBodyDefaultAnim());

				//head
				if (p_templ_animations->GetRobotHeadDefaultAnim() != NULL)
					robot->SetAnimationHead(p_templ_animations->GetRobotHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			robot->setStrategyDuration(m_templ_strategy_duration);
		}
	}
}//namespace factory
