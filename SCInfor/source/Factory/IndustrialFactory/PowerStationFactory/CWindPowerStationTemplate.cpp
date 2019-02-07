//  ______________________________________________________
// | CWindPowerStationTemplate.cpp - class implementation |
// | Jack Flower - August 2014                            |
// |______________________________________________________|
//

#include "CWindPowerStationTemplate.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../ResourceManager/CResourceManager.h"
using namespace resource;

namespace factory
{
	RTTI_IMPL(CWindPowerStationTemplate, CPowerStationTemplate);

	//Konstruktor
	CWindPowerStationTemplate::CWindPowerStationTemplate(void)
	:
		CPowerStationTemplate				(),//konstruktor klasy bazowej
		m_templ_energy_condensation_time	(0.0f),
		m_templ_use_windturbine				(false),
		m_templ_portion_energy				(0.0f),
		m_templ_use_rotation_head			(false),
		m_templ_speed_rotation_head			(0.0f),
		p_templ_windturbine					(NULL)
	{
	}

	//Destruktor wirtualny
	CWindPowerStationTemplate::~CWindPowerStationTemplate(void)
	{
		//CPowerStationTemplate				not edit
		m_templ_energy_condensation_time	= 0.0f;
		m_templ_use_windturbine				= false;
		m_templ_portion_energy				= 0.0f;
		m_templ_use_rotation_head			= false;
		m_templ_speed_rotation_head			= 0.0f;
		p_templ_windturbine					= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CWindPowerStationTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CWindPowerStationTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CWindPowerStationTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CWindPowerStationTemplate::load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CPowerStationTemplate
		if (!CPowerStationTemplate::load(xml)) return false;

		//dane obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "windpower_station_config"))
		{
			m_templ_energy_condensation_time = xml.GetFloat(node, "energy_condensation_time");
			m_templ_portion_energy = xml.GetFloat(node, "portion_energy");
			m_templ_use_rotation_head = xml.GetBool(node, "use_rotation_head");
			m_templ_speed_rotation_head = xml.GetFloat(node, "speed_rotation_head");
		}

		//nazwa pliku z konfiguracj¹ turbiny wiatrowej
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "windturbine_data"))
		{
			//flaga, czy obiekt posiada turbinê wiatrow¹
			m_templ_use_windturbine = xml.GetBool(node, "use_windturbine");
			//zapisujê do zmiennej nazwê pliku z konfiguracj¹ turbiny wiatrowej
			std::string windturbine_filename_tmp = xml.GetString(node, "windturbine_filename");
			
			if(m_templ_use_windturbine)
				p_templ_windturbine = (CWindTurbineTemplate*)gResourceManager.GetPhysicalTemplate(windturbine_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy WindTurbine
	CWindPowerStation* CWindPowerStationTemplate::create(std::wstring id)
	{
		CWindPowerStation* windpower_station = gPhysicalManager.CreateWindPowerStation(id);
		fill(windpower_station);
		return windpower_station;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CWindPowerStationTemplate::fill(CWindPowerStation *p_windpower_station)
	{
		if(p_windpower_station)
		{
			CPowerStationTemplate::fill(p_windpower_station);
			
			//kategoria
			p_windpower_station->SetCategory(PHYSICAL_WINDPOWERSTATION);

			//przekazanie danych...
			p_windpower_station->setEnergyCondensationTime(m_templ_energy_condensation_time);
			p_windpower_station->setPortionEnergy(m_templ_portion_energy);
			p_windpower_station->setUseWindTurbine(m_templ_use_windturbine);
			p_windpower_station->setUseRotationHead(m_templ_use_rotation_head);
			p_windpower_station->setSpeedRotationHead(m_templ_speed_rotation_head);

			//jeœli obiekt posiada turbinê
			if(m_templ_use_windturbine)
			{
				if(p_templ_windturbine)
				{
					//wstêpna przymiarka do nadawania unique_id
					std::wstring name_parent = this->GetGenre();
					std::wstring name_child = p_templ_windturbine->GetGenre();

					//inicjujemy wskaŸnik na sk³adow¹ - wskaŸnik na obiekt wzorzeca dla klasy CWindTurbineTemplate
					p_windpower_station->setWindTurbine(p_templ_windturbine->create(L""));
					//przekazanie wskaŸnikowi na klasê CWindPowerStation informacji o wzorcu obiektu
					p_windpower_station->getWindTurbine()->SetTemplate(p_templ_windturbine);
					//decorate
					p_windpower_station->getWindTurbine()->setSmoothing(true);
				}
			}
			//decorate
			p_windpower_station->setSmoothing(true);
		}
	}
}//namespace factory
