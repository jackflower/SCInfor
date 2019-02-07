//  ________________________________________________
// | CVentilatorTemplate.cpp - class implementation |
// | Jack Flower June 2014                          |
// |________________________________________________|
//

#include "CVentilatorTemplate.h"

namespace factory
{
	RTTI_IMPL(CVentilatorTemplate, CActorTemplate);

	//Konstruktor
	CVentilatorTemplate::CVentilatorTemplate()
	:
		CActorTemplate						(),//konstruktor klasy bazowej
		m_templ_ventilator_name				(""),
		m_templ_performance					(0.0f),
		m_templ_performance_factor			(0.0f),
		m_templ_energy_consumption			(0.0f),
		m_templ_energy_consumption_factor	(0.0f)
	{
	}

	//Destruktor wirtualny
	CVentilatorTemplate::~CVentilatorTemplate()
	{
		//CActorTemplate					not edit
		m_templ_ventilator_name				= "";
		m_templ_performance					= 0.0f;
		m_templ_performance_factor			= 0.0f;
		m_templ_energy_consumption			= 0.0f;
		m_templ_energy_consumption_factor	= 0.0f;
	}
	
	//Metoda zwraca typ obiektu /RTTI/
	const std::string CVentilatorTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj�ca zas�b
	void CVentilatorTemplate::drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CVentilatorTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml �aduje wsp�lne cechy CActor
	bool CVentilatorTemplate::load(CXml &xml)
	{
		//�adowanie danych klasy bazowej CActor
		if (!CActorTemplate::load(xml)) return false;

		//dane wentylatora
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "ventilator_config"))
		{
			m_templ_ventilator_name = xml.GetString(node, "ventilator_name");
			m_templ_performance = xml.GetFloat(node, "performance");
			m_templ_performance_factor = xml.GetFloat(node, "performance_factor");
			m_templ_energy_consumption = xml.GetFloat(node, "energy_consumption");
			m_templ_energy_consumption_factor = xml.GetFloat(node, "energy_consumption_factor");
		}
		
		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Ventilator
	Ventilator* CVentilatorTemplate::create(std::wstring id)
	{
		Ventilator* ventilator = gPhysicalManager.CreateVentilator(id);
		fill(ventilator);
		return ventilator;
	}

	//Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
	void CVentilatorTemplate::fill(Ventilator *p_ventilator)
	{
		if(p_ventilator)
		{
			CActorTemplate::fill(p_ventilator);
	
			//przekazanie danych...
			p_ventilator->setVentilatorName(m_templ_ventilator_name);
			p_ventilator->setPerformance(m_templ_performance);
			p_ventilator->setPerformanceFactor(m_templ_performance_factor);
			p_ventilator->setEnergyConsumption(m_templ_energy_consumption);
			p_ventilator->setEnergyConsumptionFactor(m_templ_energy_consumption_factor);
		}
	}
}//namespace factory
