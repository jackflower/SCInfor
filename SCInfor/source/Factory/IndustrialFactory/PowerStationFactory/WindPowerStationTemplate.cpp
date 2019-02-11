//  _____________________________________________________
// | WindPowerStationTemplate.cpp - class implementation |
// | Jack Flower - August 2014                           |
// |_____________________________________________________|
//

#include "WindPowerStationTemplate.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../ResourceManager/CResourceManager.h"
using namespace resource;

namespace factory
{
	RTTI_IMPL(WindPowerStationTemplate, PowerStationTemplate);

	//Konstruktor
	WindPowerStationTemplate::WindPowerStationTemplate()
	:
		PowerStationTemplate(),//konstruktor klasy bazowej
		m_templ_energy_condensation_time(0.0f),
		m_templ_use_windturbine(false),
		m_templ_portion_energy(0.0f),
		m_templ_use_rotation_head(false),
		m_templ_speed_rotation_head(0.0f),
		p_templ_windturbine(NULL)
	{
	}

	//Destruktor wirtualny
	WindPowerStationTemplate::~WindPowerStationTemplate()
	{
		//PowerStationTemplate
		m_templ_energy_condensation_time = 0.0f;
		m_templ_use_windturbine = false;
		m_templ_portion_energy = 0.0f;
		m_templ_use_rotation_head = false;
		m_templ_speed_rotation_head = 0.0f;
		p_templ_windturbine = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string WindPowerStationTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void WindPowerStationTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool WindPowerStationTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane
	bool WindPowerStationTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej PowerStationTemplate
		if (!PowerStationTemplate::load(xml)) return false;

		//dane obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "windpower_station_config"))
		{
			m_templ_energy_condensation_time = xml.GetFloat(node, "energy_condensation_time");
			m_templ_portion_energy = xml.GetFloat(node, "portion_energy");
			m_templ_use_rotation_head = xml.GetBool(node, "use_rotation_head");
			m_templ_speed_rotation_head = xml.GetFloat(node, "speed_rotation_head");
		}

		//nazwa pliku z konfiguracją turbiny wiatrowej
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "windturbine_data"))
		{
			//flaga, czy obiekt posiada turbinę wiatrową
			m_templ_use_windturbine = xml.GetBool(node, "use_windturbine");
			//zapisuję do zmiennej nazwę pliku z konfiguracją turbiny wiatrowej
			std::string windturbine_filename_tmp = xml.GetString(node, "windturbine_filename");
			
			if(m_templ_use_windturbine)
				p_templ_windturbine = (WindTurbineTemplate*)gResourceManager.GetPhysicalTemplate(windturbine_filename_tmp);
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy WindTurbine
	WindPowerStation* WindPowerStationTemplate::create(std::wstring id)
	{
		WindPowerStation* windpower_station = gPhysicalManager.CreateWindPowerStation(id);
		fill(windpower_station);
		return windpower_station;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void WindPowerStationTemplate::fill(WindPowerStation *p_windpower_station)
	{
		if(p_windpower_station)
		{
			PowerStationTemplate::fill(p_windpower_station);
			
			//kategoria
			p_windpower_station->setCategory(PHYSICAL_WINDPOWERSTATION);

			//przekazanie danych...
			p_windpower_station->setEnergyCondensationTime(m_templ_energy_condensation_time);
			p_windpower_station->setPortionEnergy(m_templ_portion_energy);
			p_windpower_station->setUseWindTurbine(m_templ_use_windturbine);
			p_windpower_station->setUseRotationHead(m_templ_use_rotation_head);
			p_windpower_station->setSpeedRotationHead(m_templ_speed_rotation_head);

			//jeśli obiekt posiada turbinę
			if(m_templ_use_windturbine)
			{
				if(p_templ_windturbine)
				{
					//wstępna przymiarka do nadawania unique_id
					std::wstring name_parent = this->getGenre();
					std::wstring name_child = p_templ_windturbine->getGenre();

					//inicjujemy wskaźnik na składową - wskaźnik na obiekt wzorzeca dla klasy WindTurbineTemplate
					p_windpower_station->setWindTurbine(p_templ_windturbine->create(L""));
					//przekazanie wskaźnikowi na klasę WindPowerStation informacji o wzorcu obiektu
					p_windpower_station->getWindTurbine()->setTemplate(p_templ_windturbine);
					//decorate
					p_windpower_station->getWindTurbine()->setSmoothing(true);
				}
			}
			//decorate
			p_windpower_station->setSmoothing(true);
		}
	}
}//namespace factory
