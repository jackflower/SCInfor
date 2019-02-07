//  __________________________________________________
// | CPowerStationTemplate.cpp - class implementation |
// | Jack Flower - May 2015                           |
// |__________________________________________________|
//

#include "CPowerStationTemplate.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../ResourceManager/CResourceManager.h"
#include "../../EquipmentFactory/CommunicationFactory/CommunicationTemplate.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(CPowerStationTemplate, CActorTemplate);

	//Konstruktor
	CPowerStationTemplate::CPowerStationTemplate()
	:
		CActorTemplate					(),//konstruktor klasy bazowej
		m_templ_power_station_name		(),
		m_templ_energy_capacitor		(0.0f),
		m_templ_amount_power_modules	(0),
		p_templ_communication			(NULL)
	{
	}

	//Destruktor wirtualny
	CPowerStationTemplate::~CPowerStationTemplate()
	{
		//CActorTemplate				not edit
		m_templ_power_station_name		= "";
		m_templ_energy_capacitor		= 0.0f;
		m_templ_amount_power_modules	= 0;
		p_templ_communication			= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPowerStationTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
	void CPowerStationTemplate::drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CPowerStationTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
	bool CPowerStationTemplate::load(CXml &xml)
	{
		//sprawdzamy, czy mo�na za�adowa� dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::load(xml)) return false;

		//dane obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "power_station_config"))
		{
			m_templ_power_station_name = xml.GetString(node, "power_station_name");
			m_templ_energy_capacitor = xml.GetFloat(node,"energy_capacitor");
			m_templ_amount_power_modules = xml.GetInt(node, "amount_power_modules");
		}

		//�adowanie modu�u komunikacyjnego
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "communication_data"))
		{
			//flaga, czy obiekt posiada modu� komunikacyjny
			mm_templ_communication_data.setUseEquipment(xml.GetBool(node, "use_communication"));

			//zapisuj� do zmiennej nazw� pliku z konfiguracj� modu�u komunikacji
			std::string communication_filename_tmp = xml.GetString(node, "communication_filename");
			
			//emitery dla obiektu klasy CCommunication
			mm_templ_communication_data.setEmiter(xml.GetFloat(node, "communication_emiter_x"), xml.GetFloat(node, "communication_emiter_y"));

			if(mm_templ_communication_data.getUseEquipment())
				p_templ_communication = (CommunicationTemplate*)gResourceManager.GetPhysicalTemplate(communication_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CPowerStation
	CPowerStation* CPowerStationTemplate::create(std::wstring id)
	{
		CPowerStation* power_station = gPhysicalManager.CreatePowerStation(id);
		fill(power_station);
		return power_station;
	}

	//Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
	void CPowerStationTemplate::fill(CPowerStation *p_power_station)
	{
		if(p_power_station)
		{
			CActorTemplate::fill(p_power_station);

			//przekazanie zestawu animacji do obiektu, kt�ry jest wype�niany danymi wzorca
			if (p_templ_animations)
			{
				p_power_station->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetWindPowerStationBodyDefaultAnim() != NULL)
					p_power_station->SetAnimationBody(p_templ_animations->GetWindPowerStationBodyDefaultAnim());

				//head
				if (p_templ_animations->GetWindPowerStationHeadDefaultAnim() != NULL)
					p_power_station->SetAnimationHead(p_templ_animations->GetWindPowerStationHeadDefaultAnim());
			}

			//kategoria
			p_power_station->SetCategory(PHYSICAL_POWERSTATION);

			//pola tej klasy wzorca
			p_power_station->SetPowerStationName(m_templ_power_station_name);
			p_power_station->setEnergyCapacitor(m_templ_energy_capacitor);
			p_power_station->setAmountPowerModules(m_templ_amount_power_modules);
			p_power_station->setUseCommunication(mm_templ_communication_data.getUseEquipment());

			//je�li obiekt posiada modu� do komunikacji
			if(mm_templ_communication_data.getUseEquipment())
			{
				if(p_templ_communication)
				{
					//pobieramy sk�adow� modu� komunikacji i wzorzec wype�nia wska�nik danymi
					p_power_station->SetCommunication(p_templ_communication->create(L""));
					//przekazanie wska�nikowi na klas� CCommunication informacji o wzorcu
					p_power_station->GetCommunication()->SetTemplate(p_templ_communication);
					//decorate
					p_power_station->GetCommunication()->setSmoothing(true);
				}
			}

			//decorate
			p_power_station->setSmoothing(true);
		}
	}
}//namespace factory
