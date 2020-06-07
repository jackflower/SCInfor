//  __________________________________________
// | ActorTemplate.cpp - class implementation |
// | Jack Flower - February 2013              |
// |__________________________________________|
//

#include <SFML/Graphics.hpp>
#include "ActorTemplate.h"
#include "PhysicalInfoTemplate.h"
#include "EquipmentFactory/EnergyFactory/EnergyTemplate.h"
#include "EquipmentFactory/EngineFactory/EngineTemplate.h"
#include "EquipmentFactory/ThermodynamicsFactory/AirconditioningFactory/AirconditioningTemplate.h"
#include "EquipmentFactory/ThermodynamicsFactory/VentilatorFactory/VentilatorTemplate.h"
#include "EquipmentFactory/WeaponFactory/GunFactory/GunTemplate.h"
#include "EquipmentFactory/IndustrialFactory/PowerModuleFactory/WindTurbineTemplate.h"
#include "EquipmentFactory/EngineFactory/FuelBarFactory/FuelBarTemplate.h"
#include "../Logic/Actor/Actor.h"
#include "../XML/Xml.h"
#include "../Rendering/Animations/AnimSet.h"
#include "../ResourceManager/ResourceManager.h"
#include "../Rendering/Displayable/Displayable.h"
#include "../Weather/Weather.h"

using namespace resource;
using namespace rendering::animation;
using namespace logic;
using namespace weather;

namespace factory
{
	RTTI_IMPL(ActorTemplate, PhysicalTemplate);

	//Konstruktor
	ActorTemplate::ActorTemplate()
	:
		PhysicalTemplate{},//konstruktor klasy bazowej
		p_templ_animations{ nullptr },
		m_templ_available_animations{},
		m_templ_technical_data{},
		m_templ_engine_data{},
		m_templ_energy_data{},
		m_templ_airconditioning_data{},
		m_templ_ventilator_data{},
		m_templ_gun_data{},
		p_templ_engine{ nullptr },
		p_templ_energy{ nullptr },
		p_templ_airconditioning{ nullptr },
		p_templ_ventilator{ nullptr },
		p_templ_gun{ nullptr },
		m_templ_use_physical_info{ false },
		p_templ_physical_info{ nullptr }
	{
	}

	//Destruktor wirtualny
	ActorTemplate::~ActorTemplate()
	{
		p_templ_animations = nullptr;
		m_templ_available_animations;
		m_templ_technical_data;
		m_templ_engine_data;
		m_templ_energy_data;
		m_templ_airconditioning_data;
		m_templ_ventilator_data;
		m_templ_gun_data;
		p_templ_engine = nullptr;
		p_templ_energy = nullptr;
		p_templ_airconditioning = nullptr;
		p_templ_ventilator = nullptr;
		p_templ_gun = nullptr;
		m_templ_use_physical_info = false;
		p_templ_physical_info = nullptr;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string ActorTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void ActorTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool ActorTemplate::load(const std::string & name)
	{
		Xml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool ActorTemplate::load(Xml & xml)
	{
		//ładowanie danych klasy bazowej Physical
		if (!PhysicalTemplate::load(xml)) return false;

		//dane techniczne obiektu
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "technical_data"))
		{
			m_templ_technical_data.setMass(xml.getFloat(node, "mass"));
			m_templ_technical_data.setTemperature(gWeather.getTemperature());
			m_templ_technical_data.setSpeed(xml.getFloat(node, "speed"));
			m_templ_technical_data.setIsMovabled(xml.getBool(node, "movabled"));
			m_templ_technical_data.setIsMove(m_templ_technical_data.getIsMove());
		}

		//ładowanie danych - obraz statyczny - reprezentacja graficzna
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "static_image"))
		{
			//zaślepka...
			//std::string image_body_name = xml.getString(node, "image_name_body");
			//std::string image_head_name = xml.getString(node, "image_name_head");
		}

		//ładowanie zestawów animacji
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "animset"))
		{
			for (xml_node<>* node = xml.getChild(xml.getRootNode(), "animset"); node; node = xml.getSibling(node,"animset"))
			{
				AnimSet *animations = new AnimSet();
				animations->setAnimSetName(xml.getString(node, "name_animset"));
				animations->parse(xml,node);
				m_templ_available_animations.push_back(animations);
			}
		}
		else
		{
			AnimSet *animations = new AnimSet();
			animations->parse(xml);
			m_templ_available_animations.push_back(animations);
		}

		//jeśli zestaw animacji liczy więcej, niż jedną animację
		if (m_templ_available_animations.size() > 0)
			//ustawiam się w zestawie na pierwszą pod zerowym indeksem
			p_templ_animations = m_templ_available_animations[0];
		else
			p_templ_animations = nullptr;


		//ładowanie nazwy pliku z konfiguracją engine
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "engine_data"))
		{
			//flaga, czy obiekt posiada silnik
			m_templ_engine_data.setUseEquipment(xml.getBool(node, "use_engine"));
			//zapisuję do zmiennej nazwę pliku z konfiguracją engine
			std::string engine_filename_tmp = xml.getString(node, "engine_filename");
			
			//emitery dla obiektu klasy Engine
			m_templ_engine_data.setEmiter(xml.getFloat(node, "engine_emiter_x"), xml.getFloat(node, "engine_emiter_y"));

			if(m_templ_engine_data.getUseEquipment())
				p_templ_engine = (EngineTemplate*)gResourceManager.getPhysicalTemplate(engine_filename_tmp);
		}

		//ładowanie nazwy pliku z konfiguracją physical_info 
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "physical_info_data"))
		{
			//flaga, czy obiekt posiada physical_info
			m_templ_use_physical_info = xml.getBool(node, "use_physical_info");
			//zapisuję do zmiennej nazwę pliku z konfiguracją physical_info
			std::string physical_info_filename_tmp = xml.getString(node, "physical_info_filename");

			if(m_templ_use_physical_info)
				p_templ_physical_info = (PhysicalInfoTemplate*)gResourceManager.getPhysicalTemplate(physical_info_filename_tmp);
		}

		//ładowanie nazwy pliku z konfiguracją energy
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "energy_data"))
		{
			//flaga, czy obiekt posiada moduł energii
			m_templ_energy_data.setUseEquipment(xml.getBool(node, "use_energy"));
			//zapisuję do zmiennej nazwę pliku z konfiguracją energy
			std::string energy_filename_tmp = xml.getString(node, "energy_filename");
			
			//emitery dla obiektu klasy Energy
			m_templ_energy_data.setEmiter(xml.getFloat(node, "energy_emiter_x"), xml.getFloat(node, "energy_emiter_y"));
			
			if(m_templ_energy_data.getUseEquipment())
				p_templ_energy = (EnergyTemplate*)gResourceManager.getPhysicalTemplate(energy_filename_tmp);
		}

		//ładowanie modułu klimatyzatora
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "airconditioning_data"))
		{
			//flaga, czy obiekt posiada moduł klimatyzatora
			m_templ_airconditioning_data.setUseEquipment(xml.getBool(node, "use_airconditioning"));
			//zapisuję do zmiennej nazwę pliku z konfiguracją modułu klimatyzatora
			std::string airconditioning_filename_tmp = xml.getString(node, "airconditioning_filename");
			
			//emitery dla obiektu klasy Airconditioning (dopisać w xml'u)
			m_templ_airconditioning_data.setEmiter(xml.getFloat(node, "airconditioning_emiter_x"), xml.getFloat(node, "airconditioning_emiter_y"));
			
			if(m_templ_airconditioning_data.getUseEquipment())
				p_templ_airconditioning = (AirconditioningTemplate*)gResourceManager.getPhysicalTemplate(airconditioning_filename_tmp);
		}

		//ładowanie modułu wentylatora
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "ventilator_data"))
		{
			//flaga, czy obiekt posiada moduł wentylatora
			m_templ_ventilator_data.setUseEquipment(xml.getBool(node, "use_ventilator"));
			//zapisuję do zmiennej nazwę pliku z konfiguracją modułu wentylatora
			std::string ventilator_filename_tmp = xml.getString(node, "ventilator_filename");

			//emitery dla obiektu klasy Ventilator (dopisać w xml'u)
			m_templ_ventilator_data.setEmiter(xml.getFloat(node, "ventilator_emiter_x"), xml.getFloat(node, "ventilator_emiter_y"));

			if(m_templ_ventilator_data.getUseEquipment())
				p_templ_ventilator = (VentilatorTemplate*)gResourceManager.getPhysicalTemplate(ventilator_filename_tmp);
		}

		//ładowanie modułu działa (dopisać w xml'u)...
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "gun_data"))
		{
			//flaga, czy obiekt posiada moduł wentylatora
			m_templ_gun_data.setUseEquipment(xml.getBool(node, "use_gun"));
			//zapisuję do zmiennej nazwę pliku z konfiguracją modułu wentylatora
			std::string gun_filename_tmp = xml.getString(node, "gun_filename");

			//emitery dla obiektu klasy Gun (dopisać w xml'u)
			m_templ_gun_data.setEmiter(xml.getFloat(node, "gun_emiter_x"), xml.getFloat(node, "gun_emiter_y"));

			if (m_templ_gun_data.getUseEquipment())
				p_templ_gun = (GunTemplate*)gResourceManager.getPhysicalTemplate(gun_filename_tmp);
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Actor
	Actor *ActorTemplate::create(std::wstring id)
	{
		Actor *actor = gPhysicalManager.createActor(id);
		fill(actor);
		return actor;
	}

	//Wirtualna metoda wypełniająca danymi obiekt klasy Actor
	void ActorTemplate::fill(Actor *actor)
	{
		if(actor)
		{
			PhysicalTemplate::fill(actor);

			//dane techniczne obiektu
			actor->setMass(m_templ_technical_data.getMass());
			actor->setTemperature(m_templ_technical_data.getTemperature());
			actor->setSpeed(m_templ_technical_data.getSpeed());
			actor->setIsMovabled(m_templ_technical_data.getIsMovabled());
			actor->setIsMove(m_templ_technical_data.getIsMove());
			actor->setUseEngine(m_templ_engine_data.getUseEquipment());
			actor->setUseEnergy(m_templ_energy_data.getUseEquipment());
			actor->setUseAirconditioning(m_templ_airconditioning_data.getUseEquipment());
			actor->setUseWentilator(m_templ_ventilator_data.getUseEquipment());
			actor->setUseGun(m_templ_gun_data.getUseEquipment());

			//chyba info nie będzie używane w aktorze (ekwipunek zamiast tego)
			//actor->SetUsePhysicalInfo(m_templ_use_physical_info);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				actor->setAnimSet(p_templ_animations);
				
				//body
				if (p_templ_animations->getDefaultAnimBody()!= nullptr)
					actor->setAnimationBody(p_templ_animations->getDefaultAnimBody());

				//head
				if (p_templ_animations->getDefaultAnimHead()!= nullptr)
					actor->setAnimationHead(p_templ_animations->getDefaultAnimHead());
			}

			//jeśli obiekt posiada silnik engine
			if (m_templ_engine_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Engine
				actor->setEngineTransformed(m_templ_engine_data.getTransformed());
				
				if(p_templ_engine)
				{
					//:key 20160601
					//pobieramy nazwę silnika spod dereferencji wskaźnika
					std::wstring engine_genre = p_templ_engine->getGenre();

					//pobieramy składową engine i wzorzec wypełnia wskaźnik danymi
					actor->setEngine(p_templ_engine->create(L""));
					//
					//actor->SetEngine(p_templ_engine->create(engine_genre));
					//
					//przekazanie wskaźnikowi na klasę Engine informacji o wzorcu
					actor->getEngine()->setTemplate(p_templ_engine);
					//decorator
					actor->getEngine()->setSmoothing(true);
				}
			}
			
			//jeśli obiekt posiada informację o stanie obiektu (energia-życie), (paliwo/tlen)
			if(m_templ_use_physical_info)
			{
				if(p_templ_physical_info)
				{
					//
					//blokada...
					///
					//pobieramy składową physical_info i wzorzec wypełnia wskaźnik danymi
					//actor->SetPhysicalInfo(p_templ_physical_info->create(L""));
					//przekazanie wskaźnikowi na klasę PhysicalInfo informacji o wzorcu
					//actor->GetPhysicalInfo()->SetTemplate(p_templ_physical_info);
				}
			}

			//jeśli obiekt posiada energię (akumulator) energy
			if(m_templ_energy_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Energy
				actor->setEnergyTransformed(m_templ_energy_data.getTransformed());

				if(p_templ_energy)
				{
					//pobieramy składową energy i wzorzec wypełnia wskaźnik danymi
					actor->setEnergy(p_templ_energy->create(L""));
					//przekazanie wskaźnikowi na klasę Energy informacji o wzorcu
					actor->getEnergy()->setTemplate(p_templ_energy);
					//decorator
					actor->getEnergy()->setSmoothing(true);
				}
			}
			
			//jeśli obiekt posiada moduł klimatyzatora
			if(m_templ_airconditioning_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Airconditioning
				actor->setAirconditioningTransformed(m_templ_airconditioning_data.getTransformed());

				if(p_templ_airconditioning)
				{
					//pobieramy składową moduł klimatyzatora i wzorzec wypełnia wskaźnik danymi
					actor->setAirconditioning(p_templ_airconditioning->create(L""));
					//przekazanie wskaźnikowi na klasę Airconditioning informacji o wzorcu
					actor->getAirconditioning()->setTemplate(p_templ_airconditioning);
					//decorator
					actor->getAirconditioning()->setSmoothing(true);
				}
			}

			//jeśli obiekt posiada moduł wentylatora
			if(m_templ_ventilator_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Ventilator
				actor->setVentilatorTransformed(m_templ_ventilator_data.getTransformed());

				if(p_templ_ventilator)
				{
					//pobieramy składową moduł wentylatora i wzorzec wypełnia wskaźnik danymi
					actor->setVentilator(p_templ_ventilator->create(L""));
					//przekazanie wskaźnikowi na klasę Ventilator informacji o wzorcu
					actor->getVentilator()->setTemplate(p_templ_ventilator);
					//decorator
					actor->getVentilator()->setSmoothing(true);
				}
			}

			//jeśli obiekt posiada działo
			if (m_templ_gun_data.getUseEquipment())
			{
				//emitery dla obiektu klasy Gun
				actor->setGunTransformed(m_templ_gun_data.getTransformed());

				if (p_templ_gun)
				{
					//pobieramy składową moduł wentylatora i wzorzec wypełnia wskaźnik danymi
					actor->setGun(p_templ_gun->create(L""));
					//przekazanie wskaźnikowi na klasę Gun informacji o wzorcu
					actor->getGun()->setTemplate(p_templ_gun);
					//decorator
					actor->getGun()->setSmoothing(true);
				}
			}
		}
		int warta = 0;
	}
}//namespace factory
