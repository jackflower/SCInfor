//  _______________________________________________
// | CSolarCellTemplate.cpp - class implementation |
// | Jack Flower - August 2014                     |
// |_______________________________________________|
//

#include "CSolarCellTemplate.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../ResourceManager/CResourceManager.h"
using namespace resource;

namespace factory
{
	RTTI_IMPL(CSolarCellTemplate, CActorTemplate);

	//Konstruktor
	CSolarCellTemplate::CSolarCellTemplate(void)
	:
		CActorTemplate					(),	//konstruktor klasy bazowej
		m_templ_solarcell_name			(),
		m_templ_stored_energy			(0.0f),
		m_templ_power					(0.0f),
		m_templ_energy_duration			(0.0f),
		m_templ_rotation_speed			(0.0f)
	{
	}

	//Destruktor wirtualny
	CSolarCellTemplate::~CSolarCellTemplate(void)
	{
		//CActorTemplate				not edit
		m_templ_solarcell_name			= "";
		m_templ_stored_energy			= 0.0f;
		m_templ_power					= 0.0f;
		m_templ_energy_duration			= 0.0f;
		m_templ_rotation_speed			= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CSolarCellTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CSolarCellTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CSolarCellTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CSolarCellTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//³adowanie wartoœci konfiguracji dla turbiny
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "solarcell_config"))
		{
			m_templ_solarcell_name = xml.GetString(node, "solarcell_name");
			m_templ_stored_energy = xml.GetFloat(node, "stored_energy");
			m_templ_power = xml.GetFloat(node, "power");
			m_templ_energy_duration = xml.GetFloat(node, "energy_duration");
			m_templ_rotation_speed = xml.GetFloat(node, "rotation_speed");
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy SolarCell
	SolarCell* CSolarCellTemplate::Create(std::wstring id)
	{
		SolarCell* solarcell = gPhysicalManager.CreateSolarCell(id);
		Fill(solarcell);
		return solarcell;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CSolarCellTemplate::Fill(SolarCell *p_solarcell)
	{
		if(p_solarcell)
		{
			CActorTemplate::Fill(p_solarcell);

			//przekazanie danych...
			p_solarcell->setSolarCellName(m_templ_solarcell_name);
			p_solarcell->setEnergyCapacitor(m_templ_stored_energy);
			p_solarcell->setPower(m_templ_power);
			p_solarcell->setEnergyDuration(m_templ_energy_duration);
			p_solarcell->setRotationSpeed(m_templ_rotation_speed);
			
			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				p_solarcell->SetAnimSet(p_templ_animations);

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
