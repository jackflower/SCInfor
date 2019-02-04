//  ____________________________________________
// | CGroundTemplate.cpp - class implementation |
// | Jack Flower - March 2015                   |
// |____________________________________________|
//


#include "CGroundTemplate.h"
#include "../../Utilities/Random/CRandom.h"

namespace factory
{
	RTTI_IMPL(CGroundTemplate, CActorTemplate);

	//Konstruktor
	CGroundTemplate::CGroundTemplate()
	{
		//to do..
	}

	//Konstruktor kopiuj�cy
	CGroundTemplate::CGroundTemplate(const CGroundTemplate & CGroundTemplateCopy)
	{
	}

	//Destruktor wirtualny
	CGroundTemplate::~CGroundTemplate()
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CGroundTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj�ca zas�b
	void CGroundTemplate::Drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CGroundTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
	bool CGroundTemplate::Load(CXml &xml)
	{
		//�adowanie danych klasy bazowej CPhysical
		if (!CActorTemplate::Load(xml)) return false;
		
		//dane dla fizyki pod�o�a
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "ground_physics_config"))
		{
			m_template_physicsground.setFriction(xml.GetFloat(node, "friction"));
			m_template_physicsground.setHumidity(xml.GetFloat(node, "humidity"));
			m_template_physicsground.setThermalTransmittance(xml.GetFloat(node, "thermal_transmittance"));
		}

		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CGroundWork
	CGround* CGroundTemplate::Create(const std::wstring id)
	{
		CGround* ground = gPhysicalManager.CreateGround(id);
		Fill(ground);
		return ground;
	}

	//Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
	void CGroundTemplate::Fill(CGround *ground)
	{
		CActorTemplate::Fill(ground);
		
		//chaos...lepiej to zaprojektowa�...
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

		ground->SetTemplate(this);
	}

	//Metoda zwraca wsp�czynnik tarcia
	const float CGroundTemplate::getTemplateFriction() const
	{
		return m_template_physicsground.getFriction();
	}

	//Metoda ustawia wsp�czynnik tarcia
	void CGroundTemplate::setTemplateFriction(float friction)
	{
		m_template_physicsground.setFriction(friction);
	}

	//Metoda zwraca wsp�czynnik wilgotno�ci
	const float CGroundTemplate::getTemplateHumidity() const
	{
		return m_template_physicsground.getHumidity();
	}

	//Metoda ustawia wsp�czynnik wilgotno�ci
	void CGroundTemplate::setTemplateHumidity(float humidity)
	{
		m_template_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca wsp�czynnik przenikalno�ci cieplnej
	const float CGroundTemplate::getTemplateThermalTransmittance() const
	{
		return m_template_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia wsp�czynnik przenikalno�ci cieplnej
	void CGroundTemplate::setTemplateThermalTransmittance(float thermal_transmittance)
	{
		m_template_physicsground.setThermalTransmittance(thermal_transmittance);
	}
}//namespace factory
