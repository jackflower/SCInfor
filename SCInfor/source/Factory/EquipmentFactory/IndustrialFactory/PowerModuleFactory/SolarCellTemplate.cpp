//  ______________________________________________
// | SolarCellTemplate.cpp - class implementation |
// | Jack Flower - August 2014                    |
// |______________________________________________|
//

#include "SolarCellTemplate.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../ResourceManager/CResourceManager.h"
using namespace resource;

namespace factory
{
	RTTI_IMPL(SolarCellTemplate, ActorTemplate);

	//Konstruktor
	SolarCellTemplate::SolarCellTemplate()
	:
		ActorTemplate(),	//konstruktor klasy bazowej
		m_templ_solarcell_name(),
		m_templ_stored_energy(0.0f),
		m_templ_power(0.0f),
		m_templ_energy_duration(0.0f),
		m_templ_rotation_speed(0.0f)
	{
	}

	//Destruktor wirtualny
	SolarCellTemplate::~SolarCellTemplate()
	{
		//ActorTemplate
		m_templ_solarcell_name = "";
		m_templ_stored_energy = 0.0f;
		m_templ_power = 0.0f;
		m_templ_energy_duration = 0.0f;
		m_templ_rotation_speed = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string SolarCellTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void SolarCellTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool SolarCellTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool SolarCellTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//ładowanie wartości konfiguracji dla turbiny
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "solarcell_config"))
		{
			m_templ_solarcell_name = xml.GetString(node, "solarcell_name");
			m_templ_stored_energy = xml.GetFloat(node, "stored_energy");
			m_templ_power = xml.GetFloat(node, "power");
			m_templ_energy_duration = xml.GetFloat(node, "energy_duration");
			m_templ_rotation_speed = xml.GetFloat(node, "rotation_speed");
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy SolarCell
	SolarCell* SolarCellTemplate::create(std::wstring id)
	{
		SolarCell *solarcell = gPhysicalManager.CreateSolarCell(id);
		fill(solarcell);
		return solarcell;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void SolarCellTemplate::fill(SolarCell *p_solarcell)
	{
		if(p_solarcell)
		{
			ActorTemplate::fill(p_solarcell);

			//przekazanie danych...
			p_solarcell->setSolarCellName(m_templ_solarcell_name);
			p_solarcell->setEnergyCapacitor(m_templ_stored_energy);
			p_solarcell->setPower(m_templ_power);
			p_solarcell->setEnergyDuration(m_templ_energy_duration);
			p_solarcell->setRotationSpeed(m_templ_rotation_speed);
			
			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_solarcell->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetSolarCellBodyDefaultAnim()!= NULL)
					p_solarcell->SetAnimationBody(p_templ_animations->GetSolarCellBodyDefaultAnim());

				//head
				if (p_templ_animations->GetSolarCellHeadDefaultAnim()!= NULL)
					p_solarcell->SetAnimationHead(p_templ_animations->GetSolarCellHeadDefaultAnim());
			}
			//decorate
			p_solarcell->setSmoothing(true);
		}
	}
}//namespace factory
