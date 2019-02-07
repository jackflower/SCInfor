//  _____________________________________________________
// | CAirconditioningTemplate.cpp - class implementation |
// | Jack Flower June 2014                               |
// |_____________________________________________________|
//

#include "CAirconditioningTemplate.h"
#include "../../../../Weather/CWeather.h"
#include "../../../../Utilities/Random/CRandom.h"
#include "../../../../ResourceManager/CResourceManager.h"
#include "../../../../Rendering/Animations/CAnimSet.h"

using namespace weather;
using namespace resource;

namespace factory
{
	RTTI_IMPL(CAirconditioningTemplate, CActorTemplate);

	//Konstruktor
	CAirconditioningTemplate::CAirconditioningTemplate()
	:
		CActorTemplate						(),//konstruktor klasy bazowej
		m_templ_airconditioning_name		(""),
		m_templ_temperature					(0.0f),
		m_templ_temperature_set				(0.0f),
		m_templ_temperature_range			(0.0f, 0.0f),
		m_templ_temperature_increment		(0.0f),
		m_templ_energy_consumption			(0.0f),
		m_templ_fuel_consumption			(0.0f),
		m_templ_thermalinsulation_data		(),
		p_templ_thermal_insulation			(NULL)
	{
	}

	//Destruktor wirtualny
	CAirconditioningTemplate::~CAirconditioningTemplate()
	{
		//CActorTemplate					not edit
		m_templ_airconditioning_name		= "";
		m_templ_temperature					= 0.0f;
		m_templ_temperature_set				= 0.0f;
		m_templ_temperature_range.first		= 0.0f;
		m_templ_temperature_range.second	= 0.0f;
		m_templ_temperature_increment		= 0.0f;
		m_templ_energy_consumption			= 0.0f;
		m_templ_fuel_consumption			= 0.0f;
		//m_templ_thermalinsulation_data	not edit
		p_templ_thermal_insulation			= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CAirconditioningTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj�ca zas�b
	void CAirconditioningTemplate::drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CAirconditioningTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml
	bool CAirconditioningTemplate::load(CXml &xml)
	{
		//�adowanie danych klasy bazowej CActor
		if (!CActorTemplate::load(xml)) return false;

		//dane modu�u klimatyzatora
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "airconditioning_config"))
		{
			m_templ_airconditioning_name = xml.GetString(node, "airconditioning_name");
			m_templ_temperature = xml.GetFloat(node, "temperature");
			m_templ_temperature_set = xml.GetFloat(node, "temperature_set");
			m_templ_temperature_range.first = xml.GetFloat(node, "temperature_range_cold");
			m_templ_temperature_range.second = xml.GetFloat(node, "temperature_range_warm");
			m_templ_temperature_increment = xml.GetFloat(node, "temperature_increment");
			m_templ_energy_consumption = xml.GetFloat(node, "energy_consumption");
			m_templ_fuel_consumption = xml.GetFloat(node, "fuel_consumption");
		}

		//�adowanie nazwy pliku z konfiguracj� termoizolatora
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "thermalinsulation_config"))
		{
			//flaga, czy obiekt posiada modu� termoizolatora
			m_templ_thermalinsulation_data.setUseEquipment(xml.GetBool(node, "use_thermal_insulation"));//dopisa� do xml'a

			//nazwa pliku z konfiguracj� thermalinsulation
			std::string thermalinsulation_filename_tmp = xml.GetString(node, "thermalinsulation_filename");
		
			//emitery dla obiektu klasy ThermalInsulation
			m_templ_thermalinsulation_data.setEmiter(xml.GetFloat(node, "thermalinsulation_emiter_x"), xml.GetFloat(node, "thermalinsulation_emiter_y"));

			if(m_templ_thermalinsulation_data.getUseEquipment())
				p_templ_thermal_insulation = (CThermalInsulationTemplate*)gResourceManager.GetPhysicalTemplate(thermalinsulation_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Airconditioning
	Airconditioning* CAirconditioningTemplate::create(std::wstring id)
	{
		Airconditioning* airconditioning = gPhysicalManager.CreateAirconditioning(id);
		fill(airconditioning);
		return airconditioning;
	}

	//Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
	void CAirconditioningTemplate::fill(Airconditioning *p_airconditioning)
	{
		if(p_airconditioning)
		{
			CActorTemplate::fill(p_airconditioning);

			//przekazanie zestawu animacji do obiektu, kt�ry jest wype�niany danymi wzorca
			if (p_templ_animations)
			{
				p_airconditioning->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetAirconditioningBodyDefaultAnim() != NULL)
					p_airconditioning->SetAnimationBody(p_templ_animations->GetAirconditioningBodyDefaultAnim());

				//head
				if (p_templ_animations->GetAirconditioningHeadDefaultAnim() != NULL)
					p_airconditioning->SetAnimationHead(p_templ_animations->GetAirconditioningHeadDefaultAnim());
			}

			//Metoda ��dujaca dane �aduje poni�sze warto�ci z xml'a,
			//tylko ze wzgl�du na zgodno�� p�l w tej klasie z polami obiektu, kt�ry buduje.
			//
			//Na pocz�tku klimatyzator jako urz�dzenie - obiekt - posiada temperatur� otoczenia,
			//na podstawie kt�rej oraz jej przeliczania, stara si� doprowadzi� do temperatur�
			//do warto�ci ustalonej - oczekiwanej, aby odda� j� obiektowe, kt�ry jest
			//jego w�a�cicielem.
			m_templ_temperature = gWeather.getTemperature();
			
			//temperatura ustawiona na urz�dzeniu (klimatyzator) [ losowana z zakresu ]
			//losowanie...
			m_templ_temperature_set = gRandom.Rndf
			(
				m_templ_temperature_range.first,
				m_templ_temperature_range.second
			);

			//przekazanie skonfigurowanych danych...
			p_airconditioning->setAirconditioningName(m_templ_airconditioning_name);
			p_airconditioning->setTemperature(m_templ_temperature);
			p_airconditioning->setTemperatureSet(m_templ_temperature_set);
			p_airconditioning->setTemperatureCold(m_templ_temperature_range.first);
			p_airconditioning->setTemperatureWarm(m_templ_temperature_range.second);
			p_airconditioning->setTemperatureIncrement(m_templ_temperature_increment);
			p_airconditioning->setEnergyConsumption(m_templ_energy_consumption);
			p_airconditioning->setFuelConsumption(m_templ_fuel_consumption);
			p_airconditioning->setUseThermalInsulation(m_templ_thermalinsulation_data.getUseEquipment());

			//je�li obiekt posiada termoizolator
			if(m_templ_thermalinsulation_data.getUseEquipment())
			{
				//emitery dla obiektu klasy ThermalInsulation
				p_airconditioning->setThermalInsulationTransformed(m_templ_thermalinsulation_data.getTransformed());

				if(p_airconditioning)
				{
					//pobieramy sk�adow� thermalinsulation i wzorzec wype�nia wska�nik danymi
					p_airconditioning->setThermalInsulation(p_templ_thermal_insulation->create(L""));//nazwa z xml'a
					//przekazanie wska�nikowi na klas� Airconditioning informacji o wzorcu
					p_airconditioning->getThermalInsulation()->SetTemplate(p_templ_thermal_insulation);
					//decorator
					p_airconditioning->getThermalInsulation()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
