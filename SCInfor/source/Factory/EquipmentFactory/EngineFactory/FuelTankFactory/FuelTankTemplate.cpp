//  _____________________________________________
// | FuelTankTemplate.cpp - class implementation |
// | Jack Flower - November 2013                 |
// |_____________________________________________|
//

#include "FuelTankTemplate.h"
#include "../../../../Logic/PhysicalManager.h"
#include "../../../../Logic/Actor/Actor.h"
#include "../../../../Rendering/Animations/AnimSet.h"

using namespace rendering::animation;
using namespace equipment;
using namespace logic;

namespace factory
{
	RTTI_IMPL(FuelTankTemplate, ActorTemplate);

	//Konstruktor
	FuelTankTemplate::FuelTankTemplate()
	:
		ActorTemplate{},//konstruktor klasy bazowej
		m_templ_fuel_tank_name{ "" },
		m_templ_fuel_tank_capacity{ 0.0f },
		m_templ_fuel{ 0.0f }
	{
	}

	//Destruktor
	FuelTankTemplate::~FuelTankTemplate()
	{
		//~ActorTemplate()
		m_templ_fuel_tank_name = "";
		m_templ_fuel_tank_capacity = 0.0f;
		m_templ_fuel = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string FuelTankTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void FuelTankTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool FuelTankTemplate::load(const std::string & name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool FuelTankTemplate::load(Xml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//ładowanie wartości konfiguracji zbiornika paliwa
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "fueltank_config"))
		{
			m_templ_fuel_tank_name = xml.getString(node, "fuel_tank_name");
			m_templ_fuel_tank_capacity = xml.getFloat(node, "fuel_tank_capacity");
			m_templ_fuel = xml.getFloat(node, "fuel");
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy FuelTank
	FuelTank* FuelTankTemplate::create(std::wstring id)
	{
		FuelTank *fueltank = gPhysicalManager.createFuelTank(id);
		fill(fueltank);
		return fueltank;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void FuelTankTemplate::fill(FuelTank *p_fueltank)
	{
		if(p_fueltank)
		{
			ActorTemplate::fill(p_fueltank);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_fueltank->setAnimSet(p_templ_animations);  
				
				//body
				if (p_templ_animations->getFuelBodyDefaultAnim()!= nullptr)
					p_fueltank->setAnimationBody(p_templ_animations->getFuelBodyDefaultAnim());

				//head
				if (p_templ_animations->getFuelHeadDefaultAnim()!= nullptr)
					p_fueltank->setAnimationHead(p_templ_animations->getFuelHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			p_fueltank->setFuelTankName(m_templ_fuel_tank_name);
			p_fueltank->setFuelTankCapacity(m_templ_fuel_tank_capacity);
			p_fueltank->setFuel(m_templ_fuel);
		}
	}
}//namespace factory
