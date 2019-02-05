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

	//Wirtualna metoda zwalniaj�ca zas�b
	void CFuelTankTemplate::Drop()
	{
		delete this;
	}

	//Wirtualna metoda �aduj�ca dane
	bool CFuelTankTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
	bool CFuelTankTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo�na za�adowa� dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//�adowanie warto�ci konfiguracji zbiornika paliwa
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "fueltank_config"))
		{
			m_templ_fuel_tank_name = xml.GetString(node, "fuel_tank_name");
			m_templ_fuel_tank_capacity = xml.GetFloat(node, "fuel_tank_capacity");
			m_templ_fuel = xml.GetFloat(node, "fuel");
		}

		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy FuelTank
	FuelTank* CFuelTankTemplate::Create(std::wstring id)
	{
		FuelTank* fueltank = gPhysicalManager.CreateFuelTank(id);
		Fill(fueltank);
		return fueltank;
	}

	//Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
	void CFuelTankTemplate::Fill(FuelTank *p_fueltank)
	{
		if(p_fueltank)
		{
			CActorTemplate::Fill(p_fueltank);

			//przekazanie zestawu animacji do obiektu, kt�ry jest wype�niany danymi wzorca
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
