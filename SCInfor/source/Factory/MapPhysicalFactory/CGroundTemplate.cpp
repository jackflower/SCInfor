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

	//Konstruktor kopiuj¹cy
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

	//Wirtualna metoda zwalniaj¹ca zasób
	void CGroundTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CGroundTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CGroundTemplate::Load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CPhysical
		if (!CActorTemplate::Load(xml)) return false;
		
		//dane dla fizyki pod³o¿a
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "ground_physics_config"))
		{
			m_template_physicsground.setFriction(xml.GetFloat(node, "friction"));
			m_template_physicsground.setHumidity(xml.GetFloat(node, "humidity"));
			m_template_physicsground.setThermalTransmittance(xml.GetFloat(node, "thermal_transmittance"));
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CGroundWork
	CGround* CGroundTemplate::Create(const std::wstring id)
	{
		CGround* ground = gPhysicalManager.CreateGround(id);
		Fill(ground);
		return ground;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CGroundTemplate::Fill(CGround *ground)
	{
		CActorTemplate::Fill(ground);
		
		//chaos...lepiej to zaprojektowaæ...
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

	//Metoda zwraca wspó³czynnik tarcia
	const float CGroundTemplate::getTemplateFriction() const
	{
		return m_template_physicsground.getFriction();
	}

	//Metoda ustawia wspó³czynnik tarcia
	void CGroundTemplate::setTemplateFriction(float friction)
	{
		m_template_physicsground.setFriction(friction);
	}

	//Metoda zwraca wspó³czynnik wilgotnoœci
	const float CGroundTemplate::getTemplateHumidity() const
	{
		return m_template_physicsground.getHumidity();
	}

	//Metoda ustawia wspó³czynnik wilgotnoœci
	void CGroundTemplate::setTemplateHumidity(float humidity)
	{
		m_template_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca wspó³czynnik przenikalnoœci cieplnej
	const float CGroundTemplate::getTemplateThermalTransmittance() const
	{
		return m_template_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia wspó³czynnik przenikalnoœci cieplnej
	void CGroundTemplate::setTemplateThermalTransmittance(float thermal_transmittance)
	{
		m_template_physicsground.setThermalTransmittance(thermal_transmittance);
	}
}//namespace factory
