//  _____________________________________________
// | FuelTankTemplate.cpp - class implementation |
// | Jack Flower - November 2013                 |
// |_____________________________________________|
//

#include "FuelTankTemplate.h"
#include "../../../../Logic/CPhysicalManager.h"
#include "../../../../Logic/Actor/CActor.h"
#include "../../../../Rendering/Animations/CAnimSet.h"

using namespace rendering::animation;
using namespace equipment;
using namespace logic;

namespace factory
{
	RTTI_IMPL(FuelTankTemplate, CActorTemplate);

	//Konstruktor
	FuelTankTemplate::FuelTankTemplate()
	:
		CActorTemplate(),//konstruktor klasy bazowej
		m_templ_fuel_tank_name(""),
		m_templ_fuel_tank_capacity(0.0f),
		m_templ_fuel(0.0f)
	{
	}

	//Destruktor
	FuelTankTemplate::~FuelTankTemplate()
	{
		//CActorTemplate
		m_templ_fuel_tank_name = "";
		m_templ_fuel_tank_capacity = 0.0f;
		m_templ_fuel = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string FuelTankTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void FuelTankTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool FuelTankTemplate::load(const std::string &name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool FuelTankTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::load(xml)) return false;

		//ładowanie wartości konfiguracji zbiornika paliwa
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "fueltank_config"))
		{
			m_templ_fuel_tank_name = xml.GetString(node, "fuel_tank_name");
			m_templ_fuel_tank_capacity = xml.GetFloat(node, "fuel_tank_capacity");
			m_templ_fuel = xml.GetFloat(node, "fuel");
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy FuelTank
	FuelTank* FuelTankTemplate::create(std::wstring id)
	{
		FuelTank* fueltank = gPhysicalManager.CreateFuelTank(id);
		fill(fueltank);
		return fueltank;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void FuelTankTemplate::fill(FuelTank *p_fueltank)
	{
		if(p_fueltank)
		{
			CActorTemplate::fill(p_fueltank);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
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
