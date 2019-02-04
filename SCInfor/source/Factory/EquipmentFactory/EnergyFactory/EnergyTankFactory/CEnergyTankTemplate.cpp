//  ________________________________________________
// | CEnergyTankTemplate.cpp - class implementation |
// | Jack Flower - November 2013                    |
// |________________________________________________|
//

#include "CEnergyTankTemplate.h"
#include "../../../../Logic/CPhysicalManager.h"
#include "../../../../Logic/Actor/CActor.h"
#include "../../../../Rendering/Animations/CAnimSet.h"

using namespace rendering::animation;
using namespace equipment;
using namespace logic;

namespace factory
{
	RTTI_IMPL(CEnergyTankTemplate, CActorTemplate);

	//Konstruktor
	CEnergyTankTemplate::CEnergyTankTemplate(void)
	:
		CActorTemplate						(),//konstruktor klasy bazowej
		m_templ_energy_tank_name			(""),
		m_templ_energy_tank_capacity		(0.0f),
		m_templ_energy						(0.0f),
		m_templ_energy_tank_rotation_speed	(0.0f)
	{
	}

	//Destruktor
	CEnergyTankTemplate::~CEnergyTankTemplate(void)
	{
		//CActorTemplate					not edit
		m_templ_energy_tank_name			= "";
		m_templ_energy_tank_capacity		= 0.0f;
		m_templ_energy						= 0.0f;
		m_templ_energy_tank_rotation_speed	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEnergyTankTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CEnergyTankTemplate::Drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CEnergyTankTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CEnergyTankTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//³adowanie wartoœci konfiguracji akumulatora energii
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "energytank_config"))
		{
			m_templ_energy_tank_name = xml.GetString(node, "energy_tank_name");
			m_templ_energy_tank_capacity = xml.GetFloat(node, "energy_tank_capacity");
			m_templ_energy = xml.GetFloat(node, "energy");
			m_templ_energy_tank_rotation_speed = xml.GetFloat(node, "energy_tank_rotation_speed");
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CFuelTank
	CEnergyTank* CEnergyTankTemplate::Create(std::wstring id)
	{
		CEnergyTank* energytank = gPhysicalManager.CreateCEnergyTank(id);
		Fill(energytank);
		return energytank;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CEnergyTankTemplate::Fill(CEnergyTank *p_energytank)
	{
		if(p_energytank)
		{
			CActorTemplate::Fill(p_energytank);

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				p_energytank->SetAnimSet(p_templ_animations);  
				
				//body
				if (p_templ_animations->GetEnergyTankBodyDefaultAnim()!= NULL)
					p_energytank->SetAnimationBody(p_templ_animations->GetEnergyTankBodyDefaultAnim());

				//head
				if (p_templ_animations->GetEnergyTankHeadDefaultAnim()!= NULL)
					p_energytank->SetAnimationHead(p_templ_animations->GetEnergyTankHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			p_energytank->SetEnergyTankName(m_templ_energy_tank_name);
			p_energytank->SetEnergyTankCapacity(m_templ_energy_tank_capacity);
			p_energytank->SetEnergy(m_templ_energy);
			p_energytank->SetEnergyTankRotationSpeed(m_templ_energy_tank_rotation_speed);
		}
	}
}//namespace factory
