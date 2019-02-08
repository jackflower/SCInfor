//  _______________________________________________
// | VentilatorTemplate.cpp - class implementation |
// | Jack Flower June 2014                         |
// |_______________________________________________|
//

#include "VentilatorTemplate.h"

namespace factory
{
	RTTI_IMPL(VentilatorTemplate, ActorTemplate);

	//Konstruktor
	VentilatorTemplate::VentilatorTemplate()
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_templ_ventilator_name(""),
		m_templ_performance(0.0f),
		m_templ_performance_factor(0.0f),
		m_templ_energy_consumption(0.0f),
		m_templ_energy_consumption_factor(0.0f)
	{
	}

	//Destruktor wirtualny
	VentilatorTemplate::~VentilatorTemplate()
	{
		//ActorTemplate
		m_templ_ventilator_name = "";
		m_templ_performance = 0.0f;
		m_templ_performance_factor = 0.0f;
		m_templ_energy_consumption = 0.0f;
		m_templ_energy_consumption_factor = 0.0f;
	}
	
	//Metoda zwraca typ obiektu /RTTI/
	const std::string VentilatorTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void VentilatorTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool VentilatorTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml ładuje wspólne cechy Actor
	bool VentilatorTemplate::load(CXml & xml)
	{
		//ładowanie danych klasy bazowej Actor
		if (!ActorTemplate::load(xml)) return false;

		//dane wentylatora
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "ventilator_config"))
		{
			m_templ_ventilator_name = xml.GetString(node, "ventilator_name");
			m_templ_performance = xml.GetFloat(node, "performance");
			m_templ_performance_factor = xml.GetFloat(node, "performance_factor");
			m_templ_energy_consumption = xml.GetFloat(node, "energy_consumption");
			m_templ_energy_consumption_factor = xml.GetFloat(node, "energy_consumption_factor");
		}
		
		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Ventilator
	Ventilator *VentilatorTemplate::create(std::wstring id)
	{
		Ventilator* ventilator = gPhysicalManager.CreateVentilator(id);
		fill(ventilator);
		return ventilator;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void VentilatorTemplate::fill(Ventilator *p_ventilator)
	{
		if(p_ventilator)
		{
			ActorTemplate::fill(p_ventilator);
	
			//przekazanie danych...
			p_ventilator->setVentilatorName(m_templ_ventilator_name);
			p_ventilator->setPerformance(m_templ_performance);
			p_ventilator->setPerformanceFactor(m_templ_performance_factor);
			p_ventilator->setEnergyConsumption(m_templ_energy_consumption);
			p_ventilator->setEnergyConsumptionFactor(m_templ_energy_consumption_factor);
		}
	}
}//namespace factory
