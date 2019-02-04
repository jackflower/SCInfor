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

	//Wirtualna metoda zwalniaj¹ca zasób
	void CVentilatorTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CVentilatorTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml ³aduje wspólne cechy CActor
	bool CVentilatorTemplate::Load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CActor
		if (!CActorTemplate::Load(xml)) return false;

		//dane wentylatora
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "ventilator_config"))
		{
			m_templ_ventilator_name = xml.GetString(node, "ventilator_name");
			m_templ_performance = xml.GetFloat(node, "performance");
			m_templ_performance_factor = xml.GetFloat(node, "performance_factor");
			m_templ_energy_consumption = xml.GetFloat(node, "energy_consumption");
			m_templ_energy_consumption_factor = xml.GetFloat(node, "energy_consumption_factor");
		}
		
		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CVentilator
	CVentilator* CVentilatorTemplate::Create(std::wstring id)
	{
		CVentilator* ventilator = gPhysicalManager.CreateVentilator(id);
		Fill(ventilator);
		return ventilator;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CVentilatorTemplate::Fill(CVentilator *p_ventilator)
	{
		if(p_ventilator)
		{
			CActorTemplate::Fill(p_ventilator);
	
			//przekazanie danych...
			p_ventilator->SetVentilatorName(m_templ_ventilator_name);
			p_ventilator->setPerformance(m_templ_performance);
			p_ventilator->setPerformanceFactor(m_templ_performance_factor);
			p_ventilator->setEnergyConsumption(m_templ_energy_consumption);
			p_ventilator->setEnergyConsumptionFactor(m_templ_energy_consumption_factor);
		}
	}
}//namespace factory
