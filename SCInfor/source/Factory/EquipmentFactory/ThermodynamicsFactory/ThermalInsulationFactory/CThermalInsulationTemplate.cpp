//  _______________________________________________________
// | CThermalInsulationTemplate.cpp - class implementation |
// | Jack Flower June 2014                                 |
// |_______________________________________________________|
//

#include "CThermalInsulationTemplate.h"
#include "../../../../Weather/CWeather.h"
#include "../../../../Rendering/Animations/CAnimSet.h"

using namespace weather;

namespace factory
{
	RTTI_IMPL(CThermalInsulationTemplate, CActorTemplate);

	CThermalInsulationTemplate::CThermalInsulationTemplate()
	:
		m_templ_thermalinsulation_name		(""),
		m_templ_temperature_ambient			(0.0f),
		m_templ_thermal_protection			(0.0f),
		m_templ_thermal_protection_factor	(0.0f),
		m_templ_thermal_protection_consume	(0.0f),
		m_templ_thermal_protection_duration	(0.0f)
	{
	}

	CThermalInsulationTemplate::~CThermalInsulationTemplate()
	{
		m_templ_thermalinsulation_name		= "";
		m_templ_temperature_ambient			= 0.0f;
		m_templ_thermal_protection			= 0.0f;
		m_templ_thermal_protection_factor	= 0.0f;
		m_templ_thermal_protection_consume	= 0.0f;
		m_templ_thermal_protection_duration	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CThermalInsulationTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj�ca zas�b
	void CThermalInsulationTemplate::Drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CThermalInsulationTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml �aduje wsp�lne cechy CActor
	bool CThermalInsulationTemplate::Load(CXml &xml)
	{
		//�adowanie danych klasy bazowej CActor
		if (!CActorTemplate::Load(xml)) return false;

		//dane termoizolatora
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "thermalinsulation_config"))
		{
			m_templ_thermalinsulation_name = xml.GetString(node, "thermalinsulation_name");
			m_templ_temperature_ambient = xml.GetFloat(node, "temperature_ambient");
			m_templ_thermal_protection = xml.GetFloat(node, "thermal_protection");
			m_templ_thermal_protection_factor = xml.GetFloat(node, "thermal_protection_factor");
			m_templ_thermal_protection_consume = xml.GetFloat(node, "thermal_protection_consume");
			m_templ_thermal_protection_duration = xml.GetFloat(node, "thermal_protection_duration");
		}
		
		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy ThermalInsulation
	ThermalInsulation* CThermalInsulationTemplate::Create(std::wstring id)
	{
		ThermalInsulation* thermalinsulation = gPhysicalManager.CreateThermalInsulation(id);
		Fill(thermalinsulation);
		return thermalinsulation;
	}

	//Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
	void CThermalInsulationTemplate::Fill(ThermalInsulation *p_thermalinsulation)
	{
		if(p_thermalinsulation)
		{
			CActorTemplate::Fill(p_thermalinsulation);

			//przekazanie zestawu animacji do obiektu, kt�ry jest wype�niany danymi wzorca
			if (p_templ_animations)
			{
				p_thermalinsulation->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetThermalInsulationBodyDefaultAnim() != NULL)
					p_thermalinsulation->SetAnimationBody(p_templ_animations->GetThermalInsulationBodyDefaultAnim());

				//head
				if (p_templ_animations->GetThermalInsulationHeadDefaultAnim() != NULL)
					p_thermalinsulation->SetAnimationHead(p_templ_animations->GetThermalInsulationHeadDefaultAnim());
			}


			//obliczam warto�� zu�ycia ochrony termicznej w jednostce czasu (na sekund�) znaj�c czas trwania doby
			//termoizolacja zu�yje si� w ci�gu doby...
			if(gWeather.getDayDuration() != 0)
				m_templ_thermal_protection_consume = (gWeather.getUpdateTime() * m_templ_thermal_protection)/gWeather.getDayDuration();

			//przekazanie skonfigurowanych danych...
			p_thermalinsulation->setThermalInsulationName(m_templ_thermalinsulation_name);
			p_thermalinsulation->setTemperatureAmbient(m_templ_temperature_ambient);
			p_thermalinsulation->setThermalProtection(m_templ_thermal_protection);
			p_thermalinsulation->setThermalProtectionFactor(m_templ_thermal_protection_factor);
			p_thermalinsulation->setThermalProtectionConsume(m_templ_thermal_protection_consume);
			p_thermalinsulation->setThermalProtectionDuration(m_templ_thermal_protection_duration);
		}
	}
}//namespace factory
