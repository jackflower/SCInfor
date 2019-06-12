//  _______________________________________________
// | GroundWorkTemplate.cpp - class implementation |
// | Jack Flower - March 2015                      |
// |_______________________________________________|
//


#include "GroundWorkTemplate.h"
#include "../../Utilities/Random/CRandom.h"

namespace factory
{
	RTTI_IMPL(GroundWorkTemplate, MapPhysicalTemplate);

	//Konstruktor
	GroundWorkTemplate::GroundWorkTemplate()
	:
		MapPhysicalTemplate{},//konstruktor klasy bazowej
		m_template_physicsground{}
	{
	}

	//Konstruktor kopiujący
	GroundWorkTemplate::GroundWorkTemplate(const GroundWorkTemplate & GroundWorkTemplateCopy)
	:
		MapPhysicalTemplate{ GroundWorkTemplateCopy },//konstruktor kopiujący klasy bazowej
		m_template_physicsground{ GroundWorkTemplateCopy.m_template_physicsground }
	{
	}

	//Destruktor wirtualny
	GroundWorkTemplate::~GroundWorkTemplate()
	{
		//~MapPhysicalTemplate()
		m_template_physicsground;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string GroundWorkTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void GroundWorkTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool GroundWorkTemplate::load(const std::string & name)
	{
		Xml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool GroundWorkTemplate::load(Xml & xml)
	{
		//ładowanie danych klasy bazowej MapPhysicalTemplate
		if (!MapPhysicalTemplate::load(xml)) return false;

		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "groundwork_config"))
		{
			 //fizyka podłoża
			m_template_physicsground.setFriction(xml.getFloat(node, "friction"));
			m_template_physicsground.setHumidity(xml.getFloat(node, "humidity"));
			m_template_physicsground.setThermalTransmittance(xml.getFloat(node, "thermal_transmittance"));
		}
		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy GroundWork
	GroundWork *GroundWorkTemplate::create(const std::wstring id)
	{
		GroundWork *groundwork = gMapPhysicalManager.createGroundWork(id);
		fill(groundwork);
		return groundwork;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void GroundWorkTemplate::fill(GroundWork *groundwork)
	{
		MapPhysicalTemplate::fill(groundwork);
		
		//odrobina chaosu...
		//docelowo lepiej to zaprojektować - jakaś klasa generująca "chaos"
		float flaga = gRandom.Rndf();

		if(flaga > 0.5f)
		{//bez chaosu...
			groundwork->setFriction(m_template_physicsground.getFriction());
			groundwork->setHumidity(m_template_physicsground.getHumidity());
			groundwork->setThermalTransmittance(m_template_physicsground.getThermalTransmittance());
		}
		else
		{//z chaosem...
			groundwork->setFriction(gRandom.Rndf(m_template_physicsground.getFriction()));
			groundwork->setHumidity(gRandom.Rndf(m_template_physicsground.getHumidity()));
			groundwork->setThermalTransmittance(gRandom.Rndf(m_template_physicsground.getThermalTransmittance()));
		}

		groundwork->setTemplate(this);
	}

	//Metoda zwraca współczynnik tarcia
	const float GroundWorkTemplate::getFriction() const
	{
		return m_template_physicsground.getFriction();
	}

	//Metoda ustawia współczynnik tarcia
	void GroundWorkTemplate::setFriction(float friction)
	{
		m_template_physicsground.setFriction(friction);
	}

	//Metoda zwraca współczynnik wilgotności
	const float GroundWorkTemplate::getHumidity() const
	{
		return m_template_physicsground.getHumidity();
	}

	//Metoda ustawia współczynnik wilgotności
	void GroundWorkTemplate::setHumidity(float humidity)
	{
		m_template_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca współczynnik przenikalności cieplnej
	const float GroundWorkTemplate::getThermalTransmittance() const
	{
		return m_template_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia współczynnik przenikalności cieplnej
	void GroundWorkTemplate::setThermalTransmittance(float thermal_transmittance)
	{
		m_template_physicsground.setThermalTransmittance(thermal_transmittance);
	}
}//namespace factory
