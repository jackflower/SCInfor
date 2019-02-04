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

	//Konstruktor kopiuj�cy
	CGroundWorkTemplate::CGroundWorkTemplate(const CGroundWorkTemplate & CGroundWorkTemplateCopy)
	:
		CMapPhysicalTemplate		(CGroundWorkTemplateCopy),//konstruktor kopiuj�cy klasy bazowej
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

	//Wirtualna metoda zwalniaj�ca zas�b
	void CGroundWorkTemplate::Drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CGroundWorkTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
	bool CGroundWorkTemplate::Load(CXml &xml)
	{
		//�adowanie danych klasy bazowej CMapPhysicalTemplate
		if (!CMapPhysicalTemplate::Load(xml)) return false;

		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "groundwork_config"))
		{
			 //fizyka pod�o�a
			m_template_physicsground.setFriction(xml.GetFloat(node, "friction"));
			m_template_physicsground.setHumidity(xml.GetFloat(node, "humidity"));
			m_template_physicsground.setThermalTransmittance(xml.GetFloat(node, "thermal_transmittance"));
		}
		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CGroundWork
	CGroundWork* CGroundWorkTemplate::Create(const std::wstring id)
	{
		CGroundWork* groundwork = gMapPhysicalManager.CreateGroundWork(id);
		Fill(groundwork);
		return groundwork;
	}

	//Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
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

	//Metoda zwraca wsp�czynnik tarcia
	const float CGroundWorkTemplate::getFriction() const
	{
		return m_template_physicsground.getFriction();
	}

	//Metoda ustawia wsp�czynnik tarcia
	void CGroundWorkTemplate::setFriction(float friction)
	{
		m_template_physicsground.setFriction(friction);
	}

	//Metoda zwraca wsp�czynnik wilgotno�ci
	const float CGroundWorkTemplate::getHumidity() const
	{
		return m_template_physicsground.getHumidity();
	}

	//Metoda ustawia wsp�czynnik wilgotno�ci
	void CGroundWorkTemplate::setHumidity(float humidity)
	{
		m_template_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca wsp�czynnik przenikalno�ci cieplnej
	const float CGroundWorkTemplate::getThermalTransmittance() const
	{
		return m_template_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia wsp�czynnik przenikalno�ci cieplnej
	void CGroundWorkTemplate::setThermalTransmittance(float thermal_transmittance)
	{
		m_template_physicsground.setThermalTransmittance(thermal_transmittance);
	}
}//namespace factory
