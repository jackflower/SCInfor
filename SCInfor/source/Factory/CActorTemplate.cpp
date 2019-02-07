//  ___________________________________________
// | CActorTemplate.cpp - class implementation |
// | Jack Flower - February 2013               |
// |___________________________________________|
//

#include <SFML/Graphics.hpp>
#include "CActorTemplate.h"
#include "CPhysicalInfoTemplate.h"
#include "EquipmentFactory/EnergyFactory/EnergyTemplate.h"
#include "EquipmentFactory/EngineFactory/CEngineTemplate.h"
#include "EquipmentFactory/ThermodynamicsFactory/AirconditioningFactory/CAirconditioningTemplate.h"
#include "EquipmentFactory/ThermodynamicsFactory/VentilatorFactory/CVentilatorTemplate.h"
#include "EquipmentFactory/WeaponFactory/GunFactory/CGunTemplate.h"
#include "EquipmentFactory/IndustrialFactory/PowerModuleFactory/CWindTurbineTemplate.h"
#include "EquipmentFactory/EngineFactory/FuelBarFactory/FuelBarTemplate.h"
#include "../Logic/Actor/CActor.h"
#include "../XML/CXml.h"
#include "../Rendering/Animations/CAnimSet.h"
#include "../ResourceManager/CResourceManager.h"
#include "../Rendering/Displayable/CDisplayable.h"
#include "../Weather/CWeather.h"

using namespace resource;
using namespace rendering::animation;
using namespace logic;
using namespace weather;

namespace factory
{
	RTTI_IMPL(CActorTemplate, CPhysicalTemplate);

	//Konstruktor
	CActorTemplate::CActorTemplate()
	:
		CPhysicalTemplate				(),//konstruktor klasy bazowej
		p_templ_animations				(NULL),
		m_templ_available_animations	(),
		m_templ_technical_data			(),
		m_templ_engine_data				(),
		m_templ_energy_data				(),
		m_templ_airconditioning_data	(),
		m_templ_ventilator_data			(),
		m_templ_gun_data				(),
		p_templ_engine					(NULL),
		p_templ_energy					(NULL),
		p_templ_airconditioning			(NULL),
		p_templ_ventilator				(NULL),
		p_templ_gun						(NULL),
		m_templ_use_physical_info		(false),
		p_templ_physical_info			(NULL)
	{
	}

	//Destruktor wirtualny
	CActorTemplate::~CActorTemplate()
	{
		p_templ_animations				= NULL;
		//m_templ_available_animations	not edit
		//m_templ_technical_data		not edit
		//m_templ_engine_data			not edit
		//m_templ_energy_data			not edit
		//m_templ_airconditioning_data	not edit
		//m_templ_ventilator_data		not edit
		//m_templ_gun_data				not edit
		p_templ_engine					= NULL;
		p_templ_energy					= NULL;
		p_templ_airconditioning			= NULL;
		p_templ_ventilator				= NULL;
		p_templ_gun						= NULL;
		m_templ_use_physical_info		= false;
		p_templ_physical_info			= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CActorTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
	void CActorTemplate::drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CActorTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml
	bool CActorTemplate::load(CXml &xml)
	{
		//�adowanie danych klasy bazowej CPhysical
		if (!CPhysicalTemplate::load(xml)) return false;

		//dane techniczne obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "technical_data"))
		{
			m_templ_technical_data.setMass(xml.GetFloat(node, "mass"));
			m_templ_technical_data.setTemperature(gWeather.getTemperature());
			m_templ_technical_data.setSpeed(xml.GetFloat(node, "speed"));
			m_templ_technical_data.setIsMovabled(xml.GetBool(node, "movabled"));
			m_templ_technical_data.setIsMove(m_templ_technical_data.getIsMove());
		}

		//�adowanie danych - obraz statyczny - reprezentacja graficzna
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "static_image"))
		{
			//za�lepka...
			//std::string image_body_name = xml.GetString(node, "image_name_body");
			//std::string image_head_name = xml.GetString(node, "image_name_head");
		}

		//�adowanie zestaw�w animacji
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "animset"))
		{
			for (xml_node<>* node = xml.GetChild(xml.GetRootNode(), "animset"); node; node = xml.GetSibling(node,"animset"))
			{
				CAnimSet * animations = new CAnimSet();
				animations->SetAnimSetName(xml.GetString(node, "name_animset"));
				animations->Parse(xml,node);
				m_templ_available_animations.push_back(animations);
			}
		}
		else
		{
			CAnimSet * animations = new CAnimSet();
			animations->Parse(xml);
			m_templ_available_animations.push_back(animations);
		}

		//je�li zestaw animacji liczy wi�cej, ni� jedn� animacj�
		if (m_templ_available_animations.size() > 0)
			//ustawiam si� w zestawie na pierwsz� pod zerowym indeksem
			p_templ_animations = m_templ_available_animations[0];
		else
			p_templ_animations = NULL;


		//�adowanie nazwy pliku z konfiguracj� engine
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "engine_data"))
		{
			

			//flaga, czy obiekt posiada silnik
			m_templ_engine_data.setUseEquipment(xml.GetBool(node, "use_engine"));
			//zapisuj� do zmiennej nazw� pliku z konfiguracj� engine
			std::string engine_filename_tmp = xml.GetString(node, "engine_filename");
			
			//emitery dla obiektu klasy Engine
			m_templ_engine_data.setEmiter(xml.GetFloat(node, "engine_emiter_x"), xml.GetFloat(node, "engine_emiter_y"));

			if(m_templ_engine_data.getUseEquipment())
				p_templ_engine = (CEngineTemplate*)gResourceManager.GetPhysicalTemplate(engine_filename_tmp);
		}

		//�adowanie nazwy pliku z konfiguracj� physical_info 
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "physical_info_data"))
		{
			//flaga, czy obiekt posiada physical_info
			m_templ_use_physical_info = xml.GetBool(node, "use_physical_info");
			//zapisuj� do zmiennej nazw� pliku z konfiguracj� physical_info
			std::string physical_info_filename_tmp = xml.GetString(node, "physical_info_filename");

			if(m_templ_use_physical_info)
				p_templ_physical_info = (CPhysicalInfoTemplate*)gResourceManager.GetPhysicalTemplate(physical_info_filename_tmp);
		}

		//�adowanie nazwy pliku z konfiguracj� energy
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "energy_data"))
		{
			//flaga, czy obiekt posiada modu� energii
			m_templ_energy_data.setUseEquipment(xml.GetBool(node, "use_energy"));
			//zapisuj� do zmiennej nazw� pliku z konfiguracj� energy
			std::string energy_filename_tmp = xml.GetString(node, "energy_filename");
			
			//emitery dla obiektu klasy Energy
			m_templ_energy_data.setEmiter(xml.GetFloat(node, "energy_emiter_x"), xml.GetFloat(node, "energy_emiter_y"));
			
			if(m_templ_energy_data.getUseEquipment())
				p_templ_energy = (EnergyTemplate*)gResourceManager.GetPhysicalTemplate(energy_filename_tmp);
		}

		//�adowanie modu�u klimatyzatora
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "airconditioning_data"))
		{
			//flaga, czy obiekt posiada modu� klimatyzatora
			m_templ_airconditioning_data.setUseEquipment(xml.GetBool(node, "use_airconditioning"));
			//zapisuj� do zmiennej nazw� pliku z konfiguracj� modu�u klimatyzatora
			std::string airconditioning_filename_tmp = xml.GetString(node, "airconditioning_filename");
			
			//emitery dla obiektu klasy Airconditioning (dopisa� w xml'u)
			m_templ_airconditioning_data.setEmiter(xml.GetFloat(node, "airconditioning_emiter_x"), xml.GetFloat(node, "airconditioning_emiter_y"));
			
			if(m_templ_airconditioning_data.getUseEquipment())
				p_templ_airconditioning = (CAirconditioningTemplate*)gResourceManager.GetPhysicalTemplate(airconditioning_filename_tmp);
		}

		//�adowanie modu�u wentylatora
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "ventilator_data"))
		{
			//flaga, czy obiekt posiada modu� wentylatora
			m_templ_ventilator_data.setUseEquipment(xml.GetBool(node, "use_ventilator"));
			//zapisuj� do zmiennej nazw� pliku z konfiguracj� modu�u wentylatora
			std::string ventilator_filename_tmp = xml.GetString(node, "ventilator_filename");

			//emitery dla obiektu klasy Ventilator (dopisa� w xml'u)
			m_templ_ventilator_data.setEmiter(xml.GetFloat(node, "ventilator_emiter_x"), xml.GetFloat(node, "ventilator_emiter_y"));

			if(m_templ_ventilator_data.getUseEquipment())
				p_templ_ventilator = (CVentilatorTemplate*)gResourceManager.GetPhysicalTemplate(ventilator_filename_tmp);
		}

		//�adowanie modu�u dzia�a (dopisa� w xml'u)...
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "gun_data"))
		{
			//flaga, czy obiekt posiada modu� wentylatora
			m_templ_gun_data.setUseEquipment(xml.GetBool(node, "use_gun"));
			//zapisuj� do zmiennej nazw� pliku z konfiguracj� modu�u wentylatora
			std::string gun_filename_tmp = xml.GetString(node, "gun_filename");

			//emitery dla obiektu klasy Gun (dopisa� w xml'u)
			m_templ_gun_data.setEmiter(xml.GetFloat(node, "gun_emiter_x"), xml.GetFloat(node, "gun_emiter_y"));

			if (m_templ_gun_data.getUseEquipment())
				p_templ_gun = (CGunTemplate*)gResourceManager.GetPhysicalTemplate(gun_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj�, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CActor
	CActor* CActorTemplate::create(std::wstring id)
	{
		CActor* actor = gPhysicalManager.CreateActor(id);
		fill(actor);
		return actor;
	}

	//Wirtualna metoda wype�niaj�ca danymi obiekt klasy CActor
	void CActorTemplate::fill(CActor *actor)
	{
		if(actor)
		{
			CPhysicalTemplate::fill(actor);

			//dane techniczne obiektu
			actor->setMass(m_templ_technical_data.getMass());
			actor->setTemperature(m_templ_technical_data.getTemperature());
			actor->setSpeed(m_templ_technical_data.getSpeed());
			actor->setIsMovabled(m_templ_technical_data.getIsMovabled());
			actor->setIsMove(m_templ_technical_data.getIsMove());
			actor->SetUseEngine(m_templ_engine_data.getUseEquipment());
			actor->SetUseEnergy(m_templ_energy_data.getUseEquipment());
			actor->SetUseAirconditioning(m_templ_airconditioning_data.getUseEquipment());
			actor->SetUseWentilator(m_templ_ventilator_data.getUseEquipment());
			actor->SetUseGun(m_templ_gun_data.getUseEquipment());

			//chyba info nie b�dzie u�ywane w aktorze (ekwipunek zamiast tego)
			//actor->SetUsePhysicalInfo(m_templ_use_physical_info);

			//przekazanie zestawu animacji do obiektu, kt�ry jest wype�niany danymi wzorca
			if (p_templ_animations)
			{
				actor->SetAnimSet(p_templ_animations);
				
				//body
				if (p_templ_animations->GetDefaultAnimBody()!= NULL)
					actor->SetAnimationBody(p_templ_animations->GetDefaultAnimBody());

				//head
				if (p_templ_animations->GetDefaultAnimHead()!= NULL)
					actor->SetAnimationHead(p_templ_animations->GetDefaultAnimHead());
			}

			//je�li obiekt posiada silnik engine
			if (m_templ_engine_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Engine
				actor->setEngineTransformed(m_templ_engine_data.getTransformed());
				
				if(p_templ_engine)
				{
					//:key 20160601
					//pobieramy nazw� silnika spod dereferencji wska�nika
					std::wstring engine_genre = p_templ_engine->GetGenre();

					//pobieramy sk�adow� engine i wzorzec wype�nia wska�nik danymi
					actor->SetEngine(p_templ_engine->create(L""));
					//
					//actor->SetEngine(p_templ_engine->create(engine_genre));
					//
					//przekazanie wska�nikowi na klas� Engine informacji o wzorcu
					actor->GetEngine()->SetTemplate(p_templ_engine);
					//decorator
					actor->GetEngine()->setSmoothing(true);
				}
			}
			
			//je�li obiekt posiada informacj� o stanie obiektu (energia-�ycie), (paliwo/tlen)
			if(m_templ_use_physical_info)
			{
				if(p_templ_physical_info)
				{
					//
					//blokada...
					///
					//pobieramy sk�adow� physical_info i wzorzec wype�nia wska�nik danymi
					//actor->SetPhysicalInfo(p_templ_physical_info->create(L""));
					//przekazanie wska�nikowi na klas� CPhysicalInfo informacji o wzorcu
					//actor->GetPhysicalInfo()->SetTemplate(p_templ_physical_info);
				}
			}

			//je�li obiekt posiada energi� (akumulator) energy
			if(m_templ_energy_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Energy
				actor->setEnergyTransformed(m_templ_energy_data.getTransformed());

				if(p_templ_energy)
				{
					//pobieramy sk�adow� energy i wzorzec wype�nia wska�nik danymi
					actor->SetEnergy(p_templ_energy->create(L""));
					//przekazanie wska�nikowi na klas� Energy informacji o wzorcu
					actor->GetEnergy()->SetTemplate(p_templ_energy);
					//decorator
					actor->GetEnergy()->setSmoothing(true);
				}
			}
			
			//je�li obiekt posiada modu� klimatyzatora
			if(m_templ_airconditioning_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Airconditioning
				actor->setAirconditioningTransformed(m_templ_airconditioning_data.getTransformed());

				if(p_templ_airconditioning)
				{
					//pobieramy sk�adow� modu� klimatyzatora i wzorzec wype�nia wska�nik danymi
					actor->SetAirconditioning(p_templ_airconditioning->create(L""));
					//przekazanie wska�nikowi na klas� Airconditioning informacji o wzorcu
					actor->GetAirconditioning()->SetTemplate(p_templ_airconditioning);
					//decorator
					actor->GetAirconditioning()->setSmoothing(true);
				}
			}

			//je�li obiekt posiada modu� wentylatora
			if(m_templ_ventilator_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Ventilator
				actor->setVentilatorTransformed(m_templ_ventilator_data.getTransformed());

				if(p_templ_ventilator)
				{
					//pobieramy sk�adow� modu� wentylatora i wzorzec wype�nia wska�nik danymi
					actor->SetVentilator(p_templ_ventilator->create(L""));
					//przekazanie wska�nikowi na klas� Ventilator informacji o wzorcu
					actor->GetVentilator()->SetTemplate(p_templ_ventilator);
					//decorator
					actor->GetVentilator()->setSmoothing(true);
				}
			}

			//je�li obiekt posiada dzia�o
			if (m_templ_gun_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Gun
				actor->setGunTransformed(m_templ_gun_data.getTransformed());

				if (p_templ_gun)
				{
					//pobieramy sk�adow� modu� wentylatora i wzorzec wype�nia wska�nik danymi
					actor->SetGun(p_templ_gun->create(L""));
					//przekazanie wska�nikowi na klas� Gun informacji o wzorcu
					actor->GetGun()->SetTemplate(p_templ_gun);
					//decorator
					actor->GetGun()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
