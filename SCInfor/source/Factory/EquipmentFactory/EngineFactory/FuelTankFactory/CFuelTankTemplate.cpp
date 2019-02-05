//  ______________________________________________
// | CFuelTankTemplate.cpp - class implementation |
// | Jack Flower - November 2013                  |
// |______________________________________________|
//

#include "CFuelTankTemplate.h"
#include "../../../../Logic/CPhysicalManager.h"
#include "../../../../Logic/Actor/CActor.h"
#include "../../../../Rendering/Animations/CAnimSet.h"

using namespace rendering::animation;
using namespace equipment;
using namespace logic;

namespace factory
{
	RTTI_IMPL(CFuelTankTemplate, CActorTemplate);

	//Konstruktor
	CFuelTankTemplate::CFuelTankTemplate(void)
	:
		CActorTemplate				(),//konstruktor klasy bazowej
		m_templ_fuel_tank_name		(""),
		m_templ_fuel_tank_capacity	(0.0f),
		m_templ_fuel				(0.0f)
	{
	}

	//Destruktor
	CFuelTankTemplate::~CFuelTankTemplate(void)
	{
		//CActorTemplate			not edit
		m_templ_fuel_tank_name		= "";
		m_templ_fuel_tank_capacity	= 0.0f;
		m_templ_fuel				= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CFuelTankTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CFuelTankTemplate::Drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CFuelTankTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CFuelTankTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//³adowanie wartoœci konfiguracji zbiornika paliwa
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "fueltank_config"))
		{
			m_templ_fuel_tank_name = xml.GetString(node, "fuel_tank_name");
			m_templ_fuel_tank_capacity = xml.GetFloat(node, "fuel_tank_capacity");
			m_templ_fuel = xml.GetFloat(node, "fuel");
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy FuelTank
	FuelTank* CFuelTankTemplate::Create(std::wstring id)
	{
		FuelTank* fueltank = gPhysicalManager.CreateFuelTank(id);
		Fill(fueltank);
		return fueltank;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CFuelTankTemplate::Fill(FuelTank *p_fueltank)
	{
		if(p_fueltank)
		{
			CActorTemplate::Fill(p_fueltank);

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				p_fueltank->SetAnimSet(p_templ_animations);  
				
				//body
				if (p_templ_animations->GetFuelBodyDefaultAnim()!= NULL)
					p_fueltank->SetAnimationBody(p_templ_animations->GetFuelBodyDefaultAnim());

				//head
				if (p_templ_animations->GetFuelHeadDefaultAnim()!= NULL)
					p_fueltank->SetAnimationHead(p_templ_animations->GetFuelHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			p_fueltank->setFuelTankName(m_templ_fuel_tank_name);
			p_fueltank->setFuelTankCapacity(m_templ_fuel_tank_capacity);
			p_fueltank->setFuel(m_templ_fuel);
		}
	}
}//namespace factory
