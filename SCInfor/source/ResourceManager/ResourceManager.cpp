//  ____________________________________________
// | ResourceManager.cpp - class implementation |
// | Jack Flower - September 2012               |
// |____________________________________________|
//

#include "ResourceManager.h"
#include "../Utilities/StringUtils/StringUtils.h"
#include "ResourceTexture.h"
#include "Music.h"
#include "Sound.h"
#include "Font.h"
#include "../XML/Xml.h"
#include "../Factory/PhysicalTemplate.h"
#include "../Factory/ActorTemplate.h"
#include "../Factory/RobotTemplate.h"
#include "../Factory/EnemyTemplate.h"
#include "../Factory/PlayerTemplate.h"
#include "../Factory/BulletTemplate.h"
#include "../Factory/MonsterTemplate.h"
#include "../Factory/FloraTemplate.h"
#include "../Factory/PhysicalInfoTemplate.h"
#include "../Factory/InformationFactory/InformationTemplate.h"
#include "../Factory/InformationFactory/PresentationTemplate.h"
//#include "../Factory/InformationFactory/CCounterTemplate.h"
//#include "../Factory/InformationFactory/CDigitalCounterTemplate.h"
#include "../Factory/MapPhysicalFactory/MapPhysicalTemplate.h"
#include "../Factory/MapPhysicalFactory/GroundWorkTemplate.h"
#include "../Factory/MapPhysicalFactory/GroundTemplate.h"
#include "../Factory/EquipmentFactory/EngineFactory/EngineTemplate.h"
#include "../Factory/EquipmentFactory/EngineFactory/FuelTankFactory/FuelTankTemplate.h"
#include "../Factory/EquipmentFactory/EngineFactory/FuelBarFactory/FuelBarTemplate.h"
#include "../Factory/EquipmentFactory/EnergyFactory/EnergyTemplate.h"
#include "../Factory/EquipmentFactory/EnergyFactory/EnergyTankFactory/EnergyTankTemplate.h"
#include "../Factory/EquipmentFactory/EnergyFactory/BatteryFactory/BatteryTemplate.h"
#include "../Factory/EquipmentFactory/EnergyFactory/BatteryFactory/SolarBatteryTemplate.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/AirconditioningFactory/AirconditioningTemplate.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/ThermalInsulationFactory/ThermalInsulationTemplate.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/VentilatorFactory/VentilatorTemplate.h"
#include "../Factory/EquipmentFactory/IndustrialFactory/PowerModuleFactory/WindTurbineTemplate.h"
#include "../Factory/EquipmentFactory/IndustrialFactory/PowerModuleFactory/SolarCellTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/WindPowerStationTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/WindPowerStationMultipledTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/PowerRelayFactory/PowerRelayStationTemplate.h"
#include "../Factory/EquipmentFactory/CommunicationFactory/CommunicationTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/PowerRelayFactory/SlotsRateTemplate.h"
#include "../Factory/EquipmentFactory/WeaponFactory/AmmoFactory/AmmoTemplate.h"
#include "../Factory/EquipmentFactory/WeaponFactory/GunFactory/GunTemplate.h"
#include "../Map/Map.h"
#include "../Map/Ground/Ground.h"

template<> resource::ResourceManager* Singleton<resource::ResourceManager>::m_singleton = 0;
unsigned long long ResourceManager::m_resource_enumerator = 0x1000;

namespace resource
{
	//Konstruktor domyślny
	ResourceManager::ResourceManager()
	:
		m_errors_occured{ 0 }
	{
		fprintf(stderr, "ResourceManager::ResourceManager()\n");
	}

	//Destruktor wirtualny
	ResourceManager::~ResourceManager()
	{
		fprintf(stderr, "ResourceManager::~ResourceManager()\n");
		clear();//usuwamy wszystkie zasoby z kontenera
	}

	//Metody  ł a d u j ą c e  zasoby - implementacja

	//Metoda ładuje zasób ResourceTexture
	ResourceHandle ResourceManager::loadTexture(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadTexture() %s\n", name.c_str());
		return loadResource<ResourceTexture>(name);
	}
	
	//Metoda ładuje zasób Music
	ResourceHandle ResourceManager::loadMusic(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadMusic() %s\n", name.c_str());
		return loadResource<Music>(name);
	}

	//Metoda ładuje zasób Sound
	ResourceHandle ResourceManager::loadSound(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadSound() %s\n", name.c_str());
		return loadResource<Sound>(name);
	}

	//Metoda ładuje zasób Font
	ResourceHandle ResourceManager::loadFont(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadFont() %s\n", name.c_str());
		return loadResource<Font>(name);
	}

	//Metoda ładuje zasób PhysicalTemplate
	ResourceHandle ResourceManager::loadPhysicalTemplate(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadPhysicalTemplate() %s\n", name.c_str());
		return loadResource<PhysicalTemplate>(name);
	}

	//Metoda ładuje zasób MapPhysicalTemplate
	ResourceHandle ResourceManager::loadMapPhysicalTemplate(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadMapPhysicalTemplate() %s\n", name.c_str());
		return loadResource<MapPhysicalTemplate>(name);
	}

	//Metoda ładuje zasób Map
	ResourceHandle ResourceManager::loadMap(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadMap() %s\n", name.c_str());
		return loadResource<Map>(name);
	}

	//Metoda ładuje zasób GroundWorkTemplate
	ResourceHandle ResourceManager::loadGroundWorkTemplate(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadGroundWorkTemplate() %s\n", name.c_str());
		return loadResource<GroundWorkTemplate>(name);
	}

	//Metoda ładuje zasób InformationTemplate
	ResourceHandle ResourceManager::loadInformationTemplate(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadInformationTemplate() %s\n", name.c_str());
		return loadResource<InformationTemplate>(name);
	}

	//Metoda ładuje zasób PresentationTemplate
	ResourceHandle ResourceManager::loadPresentationTemplate(const std::string & name)
	{
		fprintf(stderr, "ResourceManager::loadPresentationTemplate() %s\n", name.c_str());
		return loadResource<PresentationTemplate>(name);
	}

	//Metody  z w r a c a j ą c e  zasoby - implementacja

	//Metoda zwraca wskaźnik na zasób - obiekt klasy ResourceTexture
	ResourceTexture *ResourceManager::getTexture(const std::string & name)
	{
		return (ResourceTexture*)getResource<ResourceTexture>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy Music
	Music *ResourceManager::getMusic(const std::string & name)
	{
		return (Music*)getResource<Music>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy Sound
	Sound *ResourceManager::getSound(const std::string & name)
	{
		return (Sound*)getResource<Sound>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy Font
	Font *ResourceManager::getFont(const std::string & name)
	{
		return (Font*)getResource<Font>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy PhysicalTemplate
	PhysicalTemplate *ResourceManager::getPhysicalTemplate(const std::string & name)
	{
		return (PhysicalTemplate*)getResource<PhysicalTemplate>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy MapPhysicalTemplate
	MapPhysicalTemplate *ResourceManager::getMapPhysicalTemplate(const std::string & name)
	{
		return (MapPhysicalTemplate*)getResource<MapPhysicalTemplate>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy Map
	Map *ResourceManager::getMap(const std::string & name)
	{
		return (Map*)getResource<Map>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy Ground
	GroundTemplate *ResourceManager::getGround(const std::string & name)
	{
		return (GroundTemplate*)getResource<GroundTemplate>(name);
	}
	
	//Metoda zwraca wskaźnik na zasób - obiekt klasy GroundWorkTemplate
	GroundWorkTemplate *ResourceManager::getGroundWorkTemplate(const std::string & name)
	{
		return (GroundWorkTemplate*)getResource<GroundWorkTemplate>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy InformationTemplate
	InformationTemplate *ResourceManager::getInformationTemplate(const std::string & name)
	{
		return (InformationTemplate*)getResource<InformationTemplate>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy GetPresentationTemplate
	PresentationTemplate *ResourceManager::getPresentationTemplate(const std::string & name)
	{
		return (PresentationTemplate*)getResource<PresentationTemplate>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy PowerRelayStationTemplate
	PowerRelayStationTemplate *ResourceManager::getPowerRelayStationTemplate(const std::string & name)
	{
		return (PowerRelayStationTemplate*)getResource<PowerRelayStationTemplate>(name);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy ResourceTexture
	ResourceTexture *ResourceManager::getTexture(ResourceHandle handle)
	{
		return (ResourceTexture*)getResource<ResourceTexture>(handle);
	}
	
	//Metoda zwraca wskaźnik na zasób - obiekt klasy Music
	Music *ResourceManager::getMusic(ResourceHandle handle)
	{
		return (Music*)getResource<Music>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy Sound
	Sound *ResourceManager::getSound(ResourceHandle handle)
	{
		return (Sound*)getResource<Sound>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy Font
	Font *ResourceManager::getFont(ResourceHandle handle)
	{
		return (Font*)getResource<Font>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy PhysicalTemplate
	PhysicalTemplate *ResourceManager::getPhysicalTemplate(ResourceHandle handle)
	{
		return (PhysicalTemplate*)getResource<PhysicalTemplate>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy CmapPhysicalTemplate
	MapPhysicalTemplate *ResourceManager::getMapPhysicalTemplate(ResourceHandle handle)
	{
		return (MapPhysicalTemplate*)getResource<MapPhysicalTemplate>(handle);
	}
	
	//Metoda zwraca wskaźnik na zasób - obiekt klasy Map
	Map *ResourceManager::getMap(ResourceHandle handle)
	{
		return (Map*)getResource<Map>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy GroundTemplate
	GroundTemplate *ResourceManager::getGroundTemplate(ResourceHandle handle)
	{
		return (GroundTemplate*)getResource<GroundTemplate>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy GroundWorkTemplate
	GroundWorkTemplate *ResourceManager::getGroundWorkTemplate(ResourceHandle handle)
	{
		return (GroundWorkTemplate*)getResource<GroundWorkTemplate>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy InformationTemplate
	InformationTemplate *ResourceManager::getInformationTemplate(ResourceHandle handle)
	{
		return (InformationTemplate*)getResource<InformationTemplate>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy PresentationTemplate
	PresentationTemplate *ResourceManager::getPresentationTemplate(ResourceHandle handle)
	{
		return (PresentationTemplate*)getResource<PresentationTemplate>(handle);
	}

	//Metoda zwraca wskaźnik na zasób - obiekt klasy PowerRelayStationTemplate
	PowerRelayStationTemplate *ResourceManager::getPowerRelayStationTemplate(ResourceHandle handle)
	{
		return (PowerRelayStationTemplate*)getResource<PowerRelayStationTemplate>(handle);
	}

	//Metoda księguje zarejstrowane nazwy załadowanych zasobów
	void ResourceManager::getAllStartingWith(const std::string & path, const std::string & type, std::vector<std::string> & out)
	{
		for (unsigned int i = 0; i < m_loaded_resource_names.size(); i++)
			if (m_loaded_resource_names[i].find(path) == 0)
				if (m_resources[stringutils::GetStringHash(m_loaded_resource_names[i])]->getType() == type)
					out.push_back(m_loaded_resource_names[i]);
	}

	//Metoda usuwa zasób na podstawie nazwy std::string
	void ResourceManager::dropResource(const std::string & name)
	{
		ResourceHandle handle = stringutils::GetStringHash(name); //zamieniamy nazwę zasobu na uchwyt
		if(m_resources.count(handle) > 0) //jeśli w kontenerze są obiekty
		{
			if(m_resources[handle] != nullptr) //jeśli pod wskazanym uchwytem są dane
				m_resources[handle]->drop(); //niszczymy je (to co jest pod iteratorem)
			m_resources.erase(handle); //i usuwamy z kontenera ten wspis
		}
	}

	//Metoda usuwa wszystkie zasoby
	void ResourceManager::clear()
	{
		while(m_resources.size()) //dopóki w kontenerze są obiekty przeszukujemy kontener
		{
			if(m_resources.begin()->second) //jeśli pod pierwszym elementen są dane
				m_resources.begin()->second->drop(); //niszczymy je (to co jest pod iteratorem)
			m_resources.erase(m_resources.begin()); //i usuwamy z kontenera ten wspis
			//ponownie ustawiając się na pierwszy element kontenera
		}
		fprintf(stderr, "ResourceManager::Clear()\n");
	}

	//Wirtualny interfejs - implementacja
	void ResourceManager::cleanup()
	{
		fprintf(stderr, "ResourceManager::cleanup()\n");
		clear();
		fprintf(stderr, "ResourceManager::cleanup() done...\n");
	}

	//Szablon prywatnej metody zwracającej wskaźnik na zasób na podstawie nazwy std::string
	template <typename T> T* ResourceManager::getResource(const std::string & name)
	{
		ResourceHandle handle = stringutils::GetStringHash(name); //zamieniamy nazwę na uchwyt
		if(m_resources.count(handle) > 0) //jeśli w kontenerze są obiekty
			return (T*)m_resources[handle]; //zwracamy zasób z kontenera pod tym kluczem
		else if(loadResource<T>(name)) //w przeciwnym wypadku próbujemy załadować zasób
			return (T*)m_resources[handle]; //i po załadowaniu zwrócić
		else //w przeciwnym wypadku
			return (T*)nullptr; //zwracamy wskaźnik na nullptr
	}

	//Szablon metody zwracającej zasób na podstawie uchwytu
	template <typename T> T* ResourceManager::getResource(ResourceHandle handle)
	{
		if(m_resources.count(handle) > 0)
			return (T*)m_resources[handle];
		else
			return (T*)nullptr;
	}

	//Szablon prywatnej metody ładującej zasób
	template <typename T> ResourceHandle ResourceManager::loadResource(const std::string & name)
	{
		ResourceHandle handle = InvalidResourceHandle; //na wszelki wypadek zerujemy uchwyt
		handle = stringutils::GetStringHash(name); //szyfrujemy funkcją haszującą std::string na liczbę

		Resource* resource = new T(); //Tworzymy nowy obiekt szablonu
	
		//ponieważ wskaźniki *Resource
		//przechowujemy w kontenerze zasobów.
		//Pamiętaj, że wskaźnikiem na obiekt klasy
		//bazowej Resource, możemy także pokazywać
		//na obiekty klas potomnych, czyli
		//np. ResourceTexture, Sound, Music,Font
		//i każdy inny zasób, który Resource Manager
		//może produkować.
		//Ważne:
		//Klasa taka musi dziedziczyć po klasie Resource,
		//a ta ma tylko wirtualny interface.
		//Zatem w klasach potomnych trzeba je zaimplemntować jako osobne metody:
		// virtual bool load(const std::string &file_name) = 0;
		// virtual void drop() = 0;

		if(resource->load(name)) //próbujemy załadować dane
		{
			m_resources[handle] = resource; //jeśli to się powiedzie, wstawiamy do kontenera 
			//wskaźnik na zasób (value), pod klucz (key)
			//handle (uchwyt), wygenerowana liczba
			//za pomocą funkcji hashującej
			m_loaded_resource_names.push_back(name); //wstawiamy nazwę do kontenera
			return handle; //zwracamy zasób, z którego można korzystać
		}
		else //jeśli załadowanie się nie powiodło
		{
			resource->drop(); //niszczymy zasób /patrz ciało metody drop()/
			return InvalidResourceHandle; //zwracamy zero...
		}
	}

	//Szablon prywatnej metody ładujące zasoby (wzorce danych dla obiektów gry)
	template <> ResourceHandle ResourceManager::loadResource<PhysicalTemplate>(const std::string& name)
	{
		return parseHandle(name);
	}

	//Szablon prywatnej metody ładujące zasoby (wzorce danych dla obiektów gry)
	template <> ResourceHandle ResourceManager::loadResource<MapPhysicalTemplate>(const std::string& name)
	{
		return parseHandle(name);
	}

	//Metoda parsuje i zwraca uchwyt zasobu
	ResourceHandle ResourceManager::parseHandle(const std::string& name)
	{

		ResourceHandle handle = InvalidResourceHandle; //na wszelki wypadek zerujemy uchwyt
		handle = stringutils::GetStringHash(name); //szyfrujemy funkcją haszującą std::string na liczbę

		if(m_resources.count(handle) != 0) //jeśli w kontenerze już jest taki zasób (wzorzec)
			return handle; //nie ma potrzeby go tworzyć - zwracamy go

		Xml xml(name, "root" ); //tworzymy obiekt xml i otwieramy plik z damymi
		
		//Z pliku xml wzorca (factory, template) odczytujemy z węzła <...type..>
		//rodzaj wzorca, jaki mamy utworzyć, a następnie umieszczamy go w kontenerze wzorców.
		//Na podstawie zarejestrowanych wzroców można tworzyć obiekty,
		//które te wzrorce potrafią generować.

		//Fabryki tworzą ze wzorców obiekty poniższych klas:
		//
		// - PhysicalTemplate                  ->tworzy->	Physical
		// - ActorTemplate                     ->tworzy->	Actor
		// - CRoborTemplate                    ->tworzy->	Robot
		// - EnemyTemplate                     ->tworzy->	Enemy
		// - PlayerTemplate                    ->tworzy->	Player
		// - BulletTemplate                    ->tworzy->	Bullet
		// - MonsterTemplate                   ->tworzy->	Monster
		// - FuelTankTemplate                  ->tworzy->	FuelTank
		// - EnergyTankTemplate                ->tworzy->	EnergyTank
		// - FuelBarTemplate                   ->tworzy->	FuelBar
		// - EnergyTemplate                    ->tworzy->	Energy
		// - BatteryTemplate                   ->tworzy->	Battery
		// - SolarBatteryTemplate              ->tworzy->	SolarBattery
		// - AirconditioningTemplate           ->tworzy->	Airconditioning
		// - ThermalInsulationTemplate         ->tworzy->	ThermalInsulation
		// - VentilatorTemplate                ->tworzy->	Ventilator
		// - WindTurbineTemplate               ->tworzy->	WindTurbine
		// - SolarCellTemplate                 ->tworzy->	SolarCell
		// - WindPowerStationTemplate          ->tworzy->	WindPowerStation
		// - WindPowerStationMultipledTemplate ->tworzy->	WindPowerStationMultipled
		// - GroundWorkTemplate                ->tworzy->	GroundWork
		// - GroundTemplate                    ->tworzy->	Ground
		// - MapPhysicalTemplate               ->tworzy->	MapPhysical
		// - InformationTemplate               ->tworzy->	Information
		// - PowerRelayStationTemplate         ->tworzy->	PowerRelayStation
		// - CommunicationTemplate             ->tworzy->	Communication
		// - SlotsRateTemplate                 ->tworzy->	SlotsRate
		// - AmmoTemplate                      ->tworzy->	Ammo
		// - GunTemplate                       ->tworzy->	Gun

		//Poza tym możemy załadować do pamięci, czyli do naszego ResourceManager
		//wzorce na obiekty całego levelu.
		//Takie rozwiązanie, wymusza jakby sposób interpretacji
		//ładowanie danych - raz, na początku rozgrywki (tylko raz czekamy, aż dane się załadują)
		//Ma to zasadnicze znaczenie, szczególnie, gdyby projektować
		//w technologiach web, mobilnych, telefony, etc...
		
		//pobieramy typ wzorca
		const std::string &type = xml.getString(xml.getRootNode(),"type");
		
		Resource *resource;	//tworzymy wskaźnik na zasób
		
		//p a r s o w a n i e
		if (type == "enemy")
			resource = new EnemyTemplate();
		else if(type == "player")
			resource = new PlayerTemplate();
		else if(type == "bullet")
			resource = new BulletTemplate();
		else if(type == "engine")
			resource = new EngineTemplate();
		else if(type == "fueltank")
			resource = new FuelTankTemplate();
		else if(type == "fuelbar")
			resource = new FuelBarTemplate();
		else if(type == "energy")
			resource = new EnergyTemplate();
		else if(type == "battery")
			resource = new BatteryTemplate();
		else if(type == "solarbattery")
			resource = new SolarBatteryTemplate();
		else if(type == "physicalinfo")
			resource = new PhysicalInfoTemplate();
		else if(type == "energy")
			resource = new EnergyTemplate();
		else if(type == "energytank")
			resource = new EnergyTankTemplate();
		else if(type == "monster")
			resource = new MonsterTemplate();
		else if(type == "flora")
			resource = new FloraTemplate();
		else if(type == "airconditioning")
			resource = new AirconditioningTemplate();
		else if(type == "thermalinsulation")
			resource = new ThermalInsulationTemplate();
		else if(type == "ventilator")
			resource = new VentilatorTemplate();
		else if(type == "windturbine")
			resource = new WindTurbineTemplate();
		else if(type == "solarcell")
			resource = new SolarCellTemplate();
		else if(type == "powerstation")
			resource = new WindPowerStationTemplate();
		else if (type == "powerstationmultipled")
			resource = new WindPowerStationMultipledTemplate();
		else if(type == "mapphysical")
			resource = new MapPhysicalTemplate();
		else if(type == "groundwork")
			resource = new GroundWorkTemplate();
		else if(type == "information")
			resource = new InformationTemplate();
		else if(type == "presentation")
			resource = new PresentationTemplate();
		else if(type == "relaystation")
			resource = new PowerRelayStationTemplate();
		else if (type == "communication")
			resource = new CommunicationTemplate();
		else if (type == "slotsrate")
			resource = new SlotsRateTemplate();
		else if (type == "ground")
			resource = new GroundTemplate();
		else if (type == "ammo")
			resource = new AmmoTemplate();
		else if (type == "gun")
			resource = new GunTemplate();
		else if (type == "robot")
			resource = new RobotTemplate();
		else
			return InvalidResourceHandle;

		if(resource->load(name)) //próbujemy załadować dane
		{
			m_resources[handle] = resource; //jeśli to się powiedzie, wstawiamy do kontenera 
            //wskaźnik na zasób w zależności
			//od typu odczytanego z pliku xml
			
			m_loaded_resource_names.push_back(name); //wstawiamy nazwę do kontenera
			return handle; //zwracamy zasób, z którego można korzystać
		}
		else //jeśli załadowanie się nie powiodło
		{
			fprintf(stderr,"ERROR: Resource %s not found\n", name.c_str());
			m_errors_occured++; //księgujemy ilość błędów
			resource->drop(); //niszczymy zasób /patrz ciało metody drop()/
			return InvalidResourceHandle; //zwracamy zero...
		}
	}
}//namespace resource
