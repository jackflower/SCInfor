//  ______________________________________________________________
// | WindPowerStationMultipledTemplate.cpp - class implementation |
// | Jack Flower - April 2016                                     |
// |______________________________________________________________|
//

#include "WindPowerStationMultipledTemplate.h"
#include "../../../Logic/Industrial/PowerStation/WindPowerStation/WindPowerStation.h"

namespace factory
{
	RTTI_IMPL(WindPowerStationMultipledTemplate, PowerStationTemplate);

	//Konstruktor
	WindPowerStationMultipledTemplate::WindPowerStationMultipledTemplate()
	:
		WindPowerStationTemplate()//konstruktor klasy bazowej
	{
	}

	//Destruktor wirtualny
	WindPowerStationMultipledTemplate::~WindPowerStationMultipledTemplate()
	{
		//WindPowerStationTemplate
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string WindPowerStationMultipledTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void WindPowerStationMultipledTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool WindPowerStationMultipledTemplate::load(const std::string & name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool WindPowerStationMultipledTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej WindPowerStationTemplate
		if (!WindPowerStationTemplate::load(xml)) return false;

		//dane obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "Alabama"))
		{
			//sk³adowe tej klasy...
			//o ile bêd¹...
		}

		//nazwa pliku z konfiguracj¹ turbiny wiatrowej
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "windturbine_data"))
		{
			//czytam raz nazwê pliku, z wzorcem do tworzenia turbin...
			//for(...)
			//flaga, czy obiekt posiada turbinê wiatrow¹
			//m_templ_use_windturbine = xml.GetBool(node, "use_windturbine");
			//zapisujê do zmiennej nazwê pliku z konfiguracj¹ turbiny wiatrowej
			//std::string windturbine_filename_tmp = xml.GetString(node, "windturbine_filename");

			//if (m_templ_use_windturbine)
			//	p_templ_windturbine = (WindTurbineTemplate*)gResourceManager.GetPhysicalTemplate(windturbine_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy WindPowerStationMultipled
	WindPowerStationMultipled* WindPowerStationMultipledTemplate::create(std::wstring id)
	{
		//WindPowerStationMultipled* windpower_station_multipled = gPhysicalManager.XXX(id);
		//fill(windpower_station);
		//return windpower_station;
		return NULL;//atrapa...
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void WindPowerStationMultipledTemplate::fill(WindPowerStationMultipled *p_windpower_station_multipled)
	{
		if (p_windpower_station_multipled)
		{
			WindPowerStationTemplate::fill(p_windpower_station_multipled);

			//for(kontener)
			//templ_windturbines.push_back(...)

			//kategoria
			//p_windpower_station_multipled->SetCategory(PHYSICAL_WINDPOWERSTATION);

			//przekazanie danych...
			//p_windpower_station_multipled->setXXX(xxx);

			//jeœli obiekt posiada turbinê
			//if (m_templ_use_windturbine)
			//{
				//if (p_templ_windturbine)
				//{
					//inicjujemy wskaŸnik na sk³adow¹ - wskaŸnik na obiekt wzorzeca dla klasy WindTurbineTemplate
				//	p_windpower_station->setWindTurbine(p_templ_windturbine->create(L""));
					//przekazanie wskaŸnikowi na klasê WindPowerStation informacji o wzorcu obiektu
				//	p_windpower_station->getWindTurbine()->SetTemplate(p_templ_windturbine);
				//}
			//}
			//decorate
			p_windpower_station_multipled->setSmoothing(true);
		}
	}

}//namespace factory
