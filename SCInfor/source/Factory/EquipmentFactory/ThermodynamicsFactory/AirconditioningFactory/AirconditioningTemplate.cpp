//  ____________________________________________________
// | AirconditioningTemplate.cpp - class implementation |
// | Jack Flower June 2014                              |
// |____________________________________________________|
//

#include "AirconditioningTemplate.h"
#include "../../../../Weather/CWeather.h"
#include "../../../../Utilities/Random/CRandom.h"
#include "../../../../ResourceManager/ResourceManager.h"
#include "../../../../Rendering/Animations/AnimSet.h"

using namespace weather;
using namespace resource;

namespace factory
{
	RTTI_IMPL(AirconditioningTemplate, ActorTemplate);

	//Konstruktor
	AirconditioningTemplate::AirconditioningTemplate()
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_templ_airconditioning_name(""),
		m_templ_temperature(0.0f),
		m_templ_temperature_set(0.0f),
		m_templ_temperature_range(0.0f, 0.0f),
		m_templ_temperature_increment(0.0f),
		m_templ_energy_consumption(0.0f),
		m_templ_fuel_consumption(0.0f),
		m_templ_thermalinsulation_data(),
		p_templ_thermal_insulation(NULL)
	{
	}

	//Destruktor wirtualny
	AirconditioningTemplate::~AirconditioningTemplate()
	{
		//ActorTemplate
		m_templ_airconditioning_name = "";
		m_templ_temperature = 0.0f;
		m_templ_temperature_set = 0.0f;
		m_templ_temperature_range.first = 0.0f;
		m_templ_temperature_range.second = 0.0f;
		m_templ_temperature_increment = 0.0f;
		m_templ_energy_consumption = 0.0f;
		m_templ_fuel_consumption = 0.0f;
		//m_templ_thermalinsulation_data
		p_templ_thermal_insulation = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string AirconditioningTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void AirconditioningTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool AirconditioningTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool AirconditioningTemplate::load(CXml & xml)
	{
		//ładowanie danych klasy bazowej Actor
		if (!ActorTemplate::load(xml)) return false;

		//dane modułu klimatyzatora
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

		//ładowanie nazwy pliku z konfiguracją termoizolatora
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "thermalinsulation_config"))
		{
			//flaga, czy obiekt posiada moduł termoizolatora
			m_templ_thermalinsulation_data.setUseEquipment(xml.GetBool(node, "use_thermal_insulation"));//dopisać do xml'a

			//nazwa pliku z konfiguracją thermalinsulation
			std::string thermalinsulation_filename_tmp = xml.GetString(node, "thermalinsulation_filename");
		
			//emitery dla obiektu klasy ThermalInsulation
			m_templ_thermalinsulation_data.setEmiter(xml.GetFloat(node, "thermalinsulation_emiter_x"), xml.GetFloat(node, "thermalinsulation_emiter_y"));

			if(m_templ_thermalinsulation_data.getUseEquipment())
				p_templ_thermal_insulation = (ThermalInsulationTemplate*)gResourceManager.getPhysicalTemplate(thermalinsulation_filename_tmp);
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Airconditioning
	Airconditioning* AirconditioningTemplate::create(std::wstring id)
	{
		Airconditioning * airconditioning = gPhysicalManager.createAirconditioning(id);
		fill(airconditioning);
		return airconditioning;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void AirconditioningTemplate::fill(Airconditioning *p_airconditioning)
	{
		if(p_airconditioning)
		{
			ActorTemplate::fill(p_airconditioning);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_airconditioning->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->getAirconditioningBodyDefaultAnim() != NULL)
					p_airconditioning->setAnimationBody(p_templ_animations->getAirconditioningBodyDefaultAnim());

				//head
				if (p_templ_animations->getAirconditioningHeadDefaultAnim() != NULL)
					p_airconditioning->setAnimationHead(p_templ_animations->getAirconditioningHeadDefaultAnim());
			}

			//Metoda łądujaca dane ładuje poniższe wartości z xml'a,
			//tylko ze względu na zgodność pól w tej klasie z polami obiektu, który buduje.
			//
			//Na początku klimatyzator jako urządzenie - obiekt - posiada temperaturę otoczenia,
			//na podstawie której oraz jej przeliczania, stara się doprowadzić do temperaturę
			//do wartości ustalonej - oczekiwanej, aby oddać ją obiektowe, który jest
			//jego właścicielem.
			m_templ_temperature = gWeather.getTemperature();
			
			//temperatura ustawiona na urządzeniu (klimatyzator) [ losowana z zakresu ]
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

			//jeśli obiekt posiada termoizolator
			if(m_templ_thermalinsulation_data.getUseEquipment())
			{
				//emitery dla obiektu klasy ThermalInsulation
				p_airconditioning->setThermalInsulationTransformed(m_templ_thermalinsulation_data.getTransformed());

				if(p_airconditioning)
				{
					//pobieramy składową thermalinsulation i wzorzec wypełnia wskaźnik danymi
					p_airconditioning->setThermalInsulation(p_templ_thermal_insulation->create(L""));//nazwa z xml'a
					//przekazanie wskaźnikowi na klasę Airconditioning informacji o wzorcu
					p_airconditioning->getThermalInsulation()->setTemplate(p_templ_thermal_insulation);
					//decorator
					p_airconditioning->getThermalInsulation()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
