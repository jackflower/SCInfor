//  ________________________________________________
// | CGroundWorkTemplate.cpp - class implementation |
// | Jack Flower - March 2015                       |
// |________________________________________________|
//


#include "CGroundWorkTemplate.h"
#include "../../Utilities/Random/CRandom.h"

namespace factory
{
	RTTI_IMPL(CGroundWorkTemplate, CMapPhysicalTemplate);

	//Konstruktor
	CGroundWorkTemplate::CGroundWorkTemplate()
	:
		CMapPhysicalTemplate		(),//konstruktor klasy bazowej
		m_template_physicsground	()
	{
	}

	//Konstruktor kopiuj¹cy
	CGroundWorkTemplate::CGroundWorkTemplate(const CGroundWorkTemplate & CGroundWorkTemplateCopy)
	:
		CMapPhysicalTemplate		(CGroundWorkTemplateCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_template_physicsground	(CGroundWorkTemplateCopy.m_template_physicsground)
	{
	}

	//Destruktor wirtualny
	CGroundWorkTemplate::~CGroundWorkTemplate()
	{
		//CMapPhysicalTemplate		not edit
		//m_template_physicsground	not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CGroundWorkTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CGroundWorkTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CGroundWorkTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CGroundWorkTemplate::Load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CMapPhysicalTemplate
		if (!CMapPhysicalTemplate::Load(xml)) return false;

		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "groundwork_config"))
		{
			 //fizyka pod³o¿a
			m_template_physicsground.setFriction(xml.GetFloat(node, "friction"));
			m_template_physicsground.setHumidity(xml.GetFloat(node, "humidity"));
			m_template_physicsground.setThermalTransmittance(xml.GetFloat(node, "thermal_transmittance"));
		}
		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CGroundWork
	CGroundWork* CGroundWorkTemplate::Create(const std::wstring id)
	{
		CGroundWork* groundwork = gMapPhysicalManager.CreateGroundWork(id);
		Fill(groundwork);
		return groundwork;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CGroundWorkTemplate::Fill(CGroundWork *groundwork)
	{
		CMapPhysicalTemplate::Fill(groundwork);
		
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

		groundwork->SetTemplate(this);
	}

	//Metoda zwraca wspó³czynnik tarcia
	const float CGroundWorkTemplate::getFriction() const
	{
		return m_template_physicsground.getFriction();
	}

	//Metoda ustawia wspó³czynnik tarcia
	void CGroundWorkTemplate::setFriction(float friction)
	{
		m_template_physicsground.setFriction(friction);
	}

	//Metoda zwraca wspó³czynnik wilgotnoœci
	const float CGroundWorkTemplate::getHumidity() const
	{
		return m_template_physicsground.getHumidity();
	}

	//Metoda ustawia wspó³czynnik wilgotnoœci
	void CGroundWorkTemplate::setHumidity(float humidity)
	{
		m_template_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca wspó³czynnik przenikalnoœci cieplnej
	const float CGroundWorkTemplate::getThermalTransmittance() const
	{
		return m_template_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia wspó³czynnik przenikalnoœci cieplnej
	void CGroundWorkTemplate::setThermalTransmittance(float thermal_transmittance)
	{
		m_template_physicsground.setThermalTransmittance(thermal_transmittance);
	}
}//namespace factory
