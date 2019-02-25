//  ________________________________________________
// | RelayStationTemplate.cpp - class implementaion |
// | Jack Flower - July 2015                        |
// |________________________________________________|
//

#include "RelayStationTemplate.h"
#include "../../../../Rendering/Animations/AnimSet.h"
#include "../../../../ResourceManager/ResourceManager.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(RelayStationTemplate, ActorTemplate);

	//Konstruktor
	RelayStationTemplate::RelayStationTemplate()
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_templ_relay_station_name(),
		m_templ_use_communication(false),
		p_templ_communication(NULL)
	{
	}

	//Destruktor wirtualny
	RelayStationTemplate::~RelayStationTemplate()
	{
		//ActorTemplate
		m_templ_relay_station_name = "";
		m_templ_use_communication = false;
		p_templ_communication = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string RelayStationTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void RelayStationTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool RelayStationTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool RelayStationTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//dane obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "relay_station_config"))
		{
			m_templ_relay_station_name = xml.GetString(node, "relay_station_name");
			m_templ_use_communication = xml.GetBool(node, "use_communication");
		}

		//ładowanie modułu komunikacyjnego
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "communication_data"))
		{
			//flaga, czy obiekt posiada moduł komunikacyjny
			m_templ_use_communication = xml.GetBool(node, "use_communication");
			//zapisuję do zmiennej nazwę pliku z konfiguracją modułu komunikacji
			std::string communication_filename_tmp = xml.GetString(node, "communication_filename");
			if(m_templ_use_communication)
				p_templ_communication = (CommunicationTemplate*)gResourceManager.getPhysicalTemplate(communication_filename_tmp);
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy RelayStation
	RelayStation *RelayStationTemplate::create(std::wstring id)
	{
		RelayStation *relay_station = gPhysicalManager.createRelayStation(id);
		fill(relay_station);
		return relay_station;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void RelayStationTemplate::fill(RelayStation *p_relay_station)
	{
		if(p_relay_station)
		{
			ActorTemplate::fill(p_relay_station);

			//przekazanie danych...
			p_relay_station->setRelayStationName(m_templ_relay_station_name);
			p_relay_station->setUseCommunication(m_templ_use_communication);
				
			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_relay_station->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->getPowerRelayStationBodyDefaultAnim()!= NULL)
					p_relay_station->setAnimationBody(p_templ_animations->getPowerRelayStationBodyDefaultAnim());

				//head
				if (p_templ_animations->getPowerRelayStationHeadDefaultAnim()!= NULL)
					p_relay_station->setAnimationHead(p_templ_animations->getPowerRelayStationHeadDefaultAnim());
			}

			//jeśli obiekt posiada moduł do komunikacji
			if(m_templ_use_communication)
			{
				if(p_templ_communication)
				{
					//pobieramy składową moduł komunikacji i wzorzec wypełnia wskaźnik danymi
					p_relay_station->setCommunication(p_templ_communication->create(L""));
					//przekazanie wskaźnikowi na klasę Communication informacji o wzorcu
					p_relay_station->getCommunication()->setTemplate(p_templ_communication);
				}
			}

			//decorate
			p_relay_station->setSmoothing(true);
		}
	}
}//namespace factory

