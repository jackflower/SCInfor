//  _________________________________________________
// | CRelayStationTemplate.cpp - class implementaion |
// | Jack Flower - July 2015                         |
// |_________________________________________________|
//

#include "CRelayStationTemplate.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../ResourceManager/CResourceManager.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(CRelayStationTemplate, CActorTemplate);

	//Konstruktor
	CRelayStationTemplate::CRelayStationTemplate()
	:
		CActorTemplate				(),//konstruktor klasy bazowej
		m_templ_relay_station_name	(),
		m_templ_use_communication	(false),
		p_templ_communication		(NULL)
	{
	}

	//Destruktor wirtualny
	CRelayStationTemplate::~CRelayStationTemplate()
	{
		//CActorTemplate			not edit
		m_templ_relay_station_name	= "";
		m_templ_use_communication	= false;
		p_templ_communication		= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CRelayStationTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CRelayStationTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CRelayStationTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CRelayStationTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//dane obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "relay_station_config"))
		{
			m_templ_relay_station_name = xml.GetString(node, "relay_station_name");
			m_templ_use_communication = xml.GetBool(node, "use_communication");
		}

		//³adowanie modu³u komunikacyjnego
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "communication_data"))
		{
			//flaga, czy obiekt posiada modu³ komunikacyjny
			m_templ_use_communication = xml.GetBool(node, "use_communication");
			//zapisujê do zmiennej nazwê pliku z konfiguracj¹ modu³u komunikacji
			std::string communication_filename_tmp = xml.GetString(node, "communication_filename");
			if(m_templ_use_communication)
				p_templ_communication = (CCommunicationTemplate*)gResourceManager.GetPhysicalTemplate(communication_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CRelayStation
	CRelayStation* CRelayStationTemplate::Create(std::wstring id)
	{
		CRelayStation* relay_station = gPhysicalManager.CreateRelayStation(id);
		Fill(relay_station);
		return relay_station;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CRelayStationTemplate::Fill(CRelayStation *p_relay_station)
	{
		if(p_relay_station)
		{
			CActorTemplate::Fill(p_relay_station);

			//przekazanie danych...
			p_relay_station->setRelayStationName(m_templ_relay_station_name);
			p_relay_station->setUseCommunication(m_templ_use_communication);
				
			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				p_relay_station->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetPowerRelayStationBodyDefaultAnim()!= NULL)
					p_relay_station->SetAnimationBody(p_templ_animations->GetPowerRelayStationBodyDefaultAnim());

				//head
				if (p_templ_animations->GetPowerRelayStationHeadDefaultAnim()!= NULL)
					p_relay_station->SetAnimationHead(p_templ_animations->GetPowerRelayStationHeadDefaultAnim());
			}

			//jeœli obiekt posiada modu³ do komunikacji
			if(m_templ_use_communication)
			{
				if(p_templ_communication)
				{
					//pobieramy sk³adow¹ modu³ komunikacji i wzorzec wype³nia wskaŸnik danymi
					p_relay_station->SetCommunication(p_templ_communication->Create(L""));
					//przekazanie wskaŸnikowi na klasê CCommunication informacji o wzorcu
					p_relay_station->GetCommunication()->SetTemplate(p_templ_communication);
				}
			}

			//decorate
			p_relay_station->setSmoothing(true);
		}
	}
}//namespace factory
