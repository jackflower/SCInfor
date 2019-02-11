//  ________________________________________________
// | WindTurbineTemplate.cpp - class implementation |
// | Jack Flower - July 2014                        |
// |________________________________________________|
//

#include "WindTurbineTemplate.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../ResourceManager/CResourceManager.h"
using namespace resource;

namespace factory
{
	RTTI_IMPL(WindTurbineTemplate, ActorTemplate);

	//Konstruktor
	WindTurbineTemplate::WindTurbineTemplate()
	:
		ActorTemplate(),	//konstruktor klasy bazowej
		m_templ_turbine_name(),
		m_templ_speed_rotor(0.0f),
		m_templ_speed_transmission(1.0f),
		m_templ_energy_capacitor(0.0f),
		m_templ_power(0.0f),
		m_templ_energy_full_duration(0.0f)
	{
	}

	//Destruktor wirtualny
	WindTurbineTemplate::~WindTurbineTemplate()
	{
		//ActorTemplate
		m_templ_turbine_name = "";
		m_templ_speed_rotor = 0.0f;
		m_templ_speed_transmission = 0.0f;
		m_templ_energy_capacitor = 0.0f;
		m_templ_power = 0.0f;
		m_templ_energy_full_duration = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string WindTurbineTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void WindTurbineTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool WindTurbineTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool WindTurbineTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//ładowanie wartości konfiguracji dla turbiny
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "turbine_config"))
		{
			m_templ_turbine_name = xml.GetString(node, "turbine_name");
			m_templ_speed_rotor = xml.GetFloat(node, "speed_rotor");
			m_templ_speed_transmission = xml.GetFloat(node, "speed_transmission");
			m_templ_energy_capacitor = xml.GetFloat(node, "energy_capacitor");
			m_templ_power = xml.GetFloat(node, "power_turbine");
			m_templ_percentage_activation = xml.GetFloat(node, "percentage_activation");
			m_templ_energy_full_duration = xml.GetFloat(node, "energy_full_duration");
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy WindTurbine
	WindTurbine *WindTurbineTemplate::create(std::wstring id)
	{
		WindTurbine* turbine = gPhysicalManager.CreateWindTurbine(id);
		fill(turbine);
		return turbine;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void WindTurbineTemplate::fill(WindTurbine *p_turbine)
	{
		if(p_turbine)
		{
			ActorTemplate::fill(p_turbine);

			//przekazanie danych...
			p_turbine->setTurbineName(m_templ_turbine_name);
			p_turbine->setSpeedRotor(m_templ_speed_rotor);
			p_turbine->setSpeedTransmission(m_templ_speed_transmission);
			p_turbine->setEnergyCapacitor(m_templ_energy_capacitor);
			p_turbine->setPower(m_templ_power);
			p_turbine->setPercentageActivation(m_templ_percentage_activation);
			p_turbine->setEnergyFuelDuration(m_templ_energy_full_duration);
			
			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_turbine->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetWindTurbineBodyDefaultAnim()!= NULL)
					p_turbine->setAnimationBody(p_templ_animations->GetWindTurbineBodyDefaultAnim());

				//head
				if (p_templ_animations->GetWindTurbineHeadDefaultAnim()!= NULL)
					p_turbine->setAnimationHead(p_templ_animations->GetWindTurbineHeadDefaultAnim());
			}
			//decorate
			p_turbine->setSmoothing(true);
		}
	}
}//namespace factory
