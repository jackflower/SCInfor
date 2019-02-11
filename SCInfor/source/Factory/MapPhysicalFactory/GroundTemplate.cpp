//  ___________________________________________
// | GroundTemplate.cpp - class implementation |
// | Jack Flower - March 2015                  |
// |___________________________________________|
//


#include "GroundTemplate.h"
#include "../../Utilities/Random/CRandom.h"

namespace factory
{
	RTTI_IMPL(GroundTemplate, ActorTemplate);

	//Konstruktor
	GroundTemplate::GroundTemplate()
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_template_physicsground()
	{
		//to do..
	}

	//Konstruktor kopiujący
	GroundTemplate::GroundTemplate(const GroundTemplate & GroundTemplateCopy)
	:
		ActorTemplate(GroundTemplateCopy),//konstruktor kopiujący klasy bazowej
		m_template_physicsground(GroundTemplateCopy.m_template_physicsground)
	{
	}

	//Destruktor wirtualny
	GroundTemplate::~GroundTemplate()
	{
		//ActorTemplate
		//m_template_physicsground
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string GroundTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void GroundTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool GroundTemplate::load(const std::string & name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool GroundTemplate::load(CXml & xml)
	{
		//ładowanie danych klasy bazowej Physical
		if (!ActorTemplate::load(xml)) return false;
		
		//dane dla fizyki podłoża
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "ground_physics_config"))
		{
			m_template_physicsground.setFriction(xml.GetFloat(node, "friction"));
			m_template_physicsground.setHumidity(xml.GetFloat(node, "humidity"));
			m_template_physicsground.setThermalTransmittance(xml.GetFloat(node, "thermal_transmittance"));
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CGroundWork
	CGround *GroundTemplate::create(const std::wstring id)
	{
		CGround *ground = gPhysicalManager.CreateGround(id);
		fill(ground);
		return ground;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void GroundTemplate::fill(CGround *ground)
	{
		ActorTemplate::fill(ground);
		
		//chaos...lepiej to zaprojektować...
		float flaga = gRandom.Rndf();

		if (flaga > 0.5f)
		{//bez chaosu...
			ground->setFriction(m_template_physicsground.getFriction());
			ground->setHumidity(m_template_physicsground.getHumidity());
			ground->setThermalTransmittance(m_template_physicsground.getThermalTransmittance());
		}
		else
		{//z chaosem...
			ground->setFriction(gRandom.Rndf(m_template_physicsground.getFriction()));
			ground->setHumidity(gRandom.Rndf(m_template_physicsground.getHumidity()));
			ground->setThermalTransmittance(gRandom.Rndf(m_template_physicsground.getThermalTransmittance()));
		}

		ground->setTemplate(this);
	}

	//Metoda zwraca współczynnik tarcia
	const float GroundTemplate::getTemplateFriction() const
	{
		return m_template_physicsground.getFriction();
	}

	//Metoda ustawia współczynnik tarcia
	void GroundTemplate::setTemplateFriction(float friction)
	{
		m_template_physicsground.setFriction(friction);
	}

	//Metoda zwraca współczynnik wilgotności
	const float GroundTemplate::getTemplateHumidity() const
	{
		return m_template_physicsground.getHumidity();
	}

	//Metoda ustawia współczynnik wilgotności
	void GroundTemplate::setTemplateHumidity(float humidity)
	{
		m_template_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca współczynnik przenikalności cieplnej
	const float GroundTemplate::getTemplateThermalTransmittance() const
	{
		return m_template_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia współczynnik przenikalności cieplnej
	void GroundTemplate::setTemplateThermalTransmittance(float thermal_transmittance)
	{
		m_template_physicsground.setThermalTransmittance(thermal_transmittance);
	}
}//namespace factory
