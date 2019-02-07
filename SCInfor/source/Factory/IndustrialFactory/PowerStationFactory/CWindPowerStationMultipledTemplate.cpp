//  _______________________________________________________________
// | CWindPowerStationMultipledTemplate.cpp - class implementation |
// | Jack Flower - April 2016                                      |
// |_______________________________________________________________|
//

#include "CWindPowerStationMultipledTemplate.h"
#include "../../../Logic/Industrial/PowerStation/WindPowerStation/CWindPowerStation.h"

namespace factory
{
	RTTI_IMPL(CWindPowerStationMultipledTemplate, CPowerStationTemplate);

	//Konstruktor
	CWindPowerStationMultipledTemplate::CWindPowerStationMultipledTemplate()
	{
	}

	//Destruktor wirtualny
	CWindPowerStationMultipledTemplate::~CWindPowerStationMultipledTemplate()
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CWindPowerStationMultipledTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
	void CWindPowerStationMultipledTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda �aduj�ca dane
	bool CWindPowerStationMultipledTemplate::load(const std::string &name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda �aduj�ca dane
	bool CWindPowerStationMultipledTemplate::load(CXml &xml)
	{
		//sprawdzamy, czy mo�na za�adowa� dane z klasy bazowej CWindPowerStationTemplate
		if (!CWindPowerStationTemplate::load(xml)) return false;

		//dane obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "Alabama"))
		{
			//sk�adowe tej klasy...
			//o ile b�d�...
		}

		//nazwa pliku z konfiguracj� turbiny wiatrowej
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "windturbine_data"))
		{
			//czytam raz nazw� pliku, z wzorcem do tworzenia turbin...
			//for(...)
			//flaga, czy obiekt posiada turbin� wiatrow�
			//m_templ_use_windturbine = xml.GetBool(node, "use_windturbine");
			//zapisuj� do zmiennej nazw� pliku z konfiguracj� turbiny wiatrowej
			//std::string windturbine_filename_tmp = xml.GetString(node, "windturbine_filename");

			//if (m_templ_use_windturbine)
			//	p_templ_windturbine = (WindTurbineTemplate*)gResourceManager.GetPhysicalTemplate(windturbine_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CWindPowerStationMultipled
	CWindPowerStationMultipled* CWindPowerStationMultipledTemplate::create(std::wstring id)
	{
		//CWindPowerStationMultipled* windpower_station_multipled = gPhysicalManager.XXX(id);
		//fill(windpower_station);
		//return windpower_station;
		return NULL;//atrapa...
	}

	//Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
	void CWindPowerStationMultipledTemplate::fill(CWindPowerStationMultipled *p_windpower_station_multipled)
	{
		if (p_windpower_station_multipled)
		{
			CWindPowerStationTemplate::fill(p_windpower_station_multipled);

			//for(kontener)
			//templ_windturbines.push_back(...)

			//kategoria
			//p_windpower_station_multipled->SetCategory(PHYSICAL_WINDPOWERSTATION);

			//przekazanie danych...
			//p_windpower_station_multipled->setXXX(xxx);

			//je�li obiekt posiada turbin�
			//if (m_templ_use_windturbine)
			//{
				//if (p_templ_windturbine)
				//{
					//inicjujemy wska�nik na sk�adow� - wska�nik na obiekt wzorzeca dla klasy WindTurbineTemplate
				//	p_windpower_station->setWindTurbine(p_templ_windturbine->create(L""));
					//przekazanie wska�nikowi na klas� CWindPowerStation informacji o wzorcu obiektu
				//	p_windpower_station->getWindTurbine()->SetTemplate(p_templ_windturbine);
				//}
			//}
			//decorate
			p_windpower_station_multipled->setSmoothing(true);
		}
	}

}//namespace factory
