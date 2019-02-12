//  _____________________________________________
// | CResourceManager.cpp - class implementation |
// | Jack Flower - September 2012                |
// |_____________________________________________|
//

#include "CResourceManager.h"
#include "../Utilities/StringUtils/StringUtils.h"
#include "CTexture.h"
#include "CMusic.h"
#include "CSound.h"
#include "CFont.h"
#include "../XML/CXml.h"
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
#include "../Map/CMap.h"
#include "../Map/Ground/CGround.h"

template<> resource::CResourceManager* CSingleton<resource::CResourceManager>::m_singleton = 0;
unsigned long long CResourceManager::m_resource_enumerator = 0x1000;

namespace resource
{
	//Konstruktor domyœlny
	CResourceManager::CResourceManager()
	:
		m_errors_occured(0)
	{
		fprintf(stderr, "CResourceManager::CResourceManager()\n");
	}

	//Destruktor wirtualny
	CResourceManager::~CResourceManager()
	{
		fprintf(stderr, "CResourceManager::~CResourceManager()\n");
		Clear();//usuwamy wszystkie zasoby z kontenera
	}

	//Metody  ³ a d u j ¹ c e  zasoby - implementacja

	//Metoda ³aduje zasób CTexture
	ResourceHandle CResourceManager::LoadTexture(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadTexture() %s\n", name.c_str());
		return LoadResource<CTexture>(name);
	}
	
	//Metoda ³aduje zasób CMusic
	ResourceHandle CResourceManager::LoadMusic(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadMusic() %s\n", name.c_str());
		return LoadResource<CMusic>(name);
	}

	//Metoda ³aduje zasób CSound
	ResourceHandle CResourceManager::LoadSound(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadSound() %s\n", name.c_str());
		return LoadResource<CSound>(name);
	}

	//Metoda ³aduje zasób CFont
	ResourceHandle CResourceManager::LoadFont(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadFont() %s\n", name.c_str());
		return LoadResource<CFont>(name);
	}

	//Metoda ³aduje zasób PhysicalTemplate
	ResourceHandle CResourceManager::LoadPhysicalTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadPhysicalTemplate() %s\n", name.c_str());
		return LoadResource<PhysicalTemplate>(name);
	}

	//Metoda ³aduje zasób MapPhysicalTemplate
	ResourceHandle CResourceManager::LoadMapPhysicalTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadMapPhysicalTemplate() %s\n", name.c_str());
		return LoadResource<MapPhysicalTemplate>(name);
	}

	//Metoda ³aduje zasób CMap
	ResourceHandle CResourceManager::LoadMap(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadMap() %s\n", name.c_str());
		return LoadResource<CMap>(name);
	}

	//Metoda ³aduje zasób GroundWorkTemplate
	ResourceHandle CResourceManager::LoadGroundWorkTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadGroundWorkTemplate() %s\n", name.c_str());
		return LoadResource<GroundWorkTemplate>(name);
	}

	//Metoda ³aduje zasób InformationTemplate
	ResourceHandle CResourceManager::LoadInformationTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadInformationTemplate() %s\n", name.c_str());
		return LoadResource<InformationTemplate>(name);
	}

	//Metoda ³aduje zasób PresentationTemplate
	ResourceHandle CResourceManager::LoadPresentationTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadPresentationTemplate() %s\n", name.c_str());
		return LoadResource<PresentationTemplate>(name);
	}

	//Metody  z w r a c a j ¹ c e  zasoby - implementacja

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CTexture
	CTexture* CResourceManager::GetTexture(const std::string& name)
	{
		return (CTexture*)GetResource<CTexture>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CMusic
	CMusic* CResourceManager::GetMusic(const std::string& name)
	{
		return (CMusic*)GetResource<CMusic>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CSound
	CSound* CResourceManager::GetSound(const std::string& name)
	{
		return (CSound*)GetResource<CSound>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CFont
	CFont* CResourceManager::GetFont(const std::string& name)
	{
		return (CFont*)GetResource<CFont>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy PhysicalTemplate
	PhysicalTemplate* CResourceManager::GetPhysicalTemplate(const std::string& name)
	{
		return (PhysicalTemplate*)GetResource<PhysicalTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy MapPhysicalTemplate
	MapPhysicalTemplate* CResourceManager::GetMapPhysicalTemplate(const std::string& name)
	{
		return (MapPhysicalTemplate*)GetResource<MapPhysicalTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CMap
	CMap* CResourceManager::GetMap(const std::string& name)
	{
		return (CMap*)GetResource<CMap>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CGround
	GroundTemplate* CResourceManager::GetGround(const std::string& name)
	{
		return (GroundTemplate*)GetResource<GroundTemplate>(name);
	}
	
	//Metoda zwraca wskaŸnik na zasób - obiekt klasy GroundWorkTemplate
	GroundWorkTemplate* CResourceManager::GetGroundWorkTemplate(const std::string& name)
	{
		return (GroundWorkTemplate*)GetResource<GroundWorkTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy InformationTemplate
	InformationTemplate* CResourceManager::GetInformationTemplate(const std::string& name)
	{
		return (InformationTemplate*)GetResource<InformationTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy GetPresentationTemplate
	PresentationTemplate* CResourceManager::GetPresentationTemplate(const std::string& name)
	{
		return (PresentationTemplate*)GetResource<PresentationTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy PowerRelayStationTemplate
	PowerRelayStationTemplate* CResourceManager::GetPowerRelayStationTemplate(const std::string& name)
	{
		return (PowerRelayStationTemplate*)GetResource<PowerRelayStationTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CTexture
	CTexture* CResourceManager::GetTexture(ResourceHandle handle)
	{
		return (CTexture*)GetResource<CTexture>(handle);
	}
	
	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CMusic
	CMusic* CResourceManager::GetMusic(ResourceHandle handle)
	{
		return (CMusic*)GetResource<CMusic>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CSound
	CSound* CResourceManager::GetSound(ResourceHandle handle)
	{
		return (CSound*)GetResource<CSound>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CFont
	CFont* CResourceManager::GetFont(ResourceHandle handle)
	{
		return (CFont*)GetResource<CFont>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy PhysicalTemplate
	PhysicalTemplate* CResourceManager::GetPhysicalTemplate(ResourceHandle handle)
	{
		return (PhysicalTemplate*)GetResource<PhysicalTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CmapPhysicalTemplate
	MapPhysicalTemplate* CResourceManager::GetMapPhysicalTemplate(ResourceHandle handle)
	{
		return (MapPhysicalTemplate*)GetResource<MapPhysicalTemplate>(handle);
	}
	
	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CMap
	CMap* CResourceManager::GetMap(ResourceHandle handle)
	{
		return (CMap*)GetResource<CMap>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy GroundTemplate
	GroundTemplate* CResourceManager::GetGroundTemplate(ResourceHandle handle)
	{
		return (GroundTemplate*)GetResource<GroundTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy GroundWorkTemplate
	GroundWorkTemplate* CResourceManager::GetGroundWorkTemplate(ResourceHandle handle)
	{
		return (GroundWorkTemplate*)GetResource<GroundWorkTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy InformationTemplate
	InformationTemplate* CResourceManager::GetInformationTemplate(ResourceHandle handle)
	{
		return (InformationTemplate*)GetResource<InformationTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy PresentationTemplate
	PresentationTemplate* CResourceManager::GetPresentationTemplate(ResourceHandle handle)
	{
		return (PresentationTemplate*)GetResource<PresentationTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy PowerRelayStationTemplate
	PowerRelayStationTemplate* CResourceManager::GetPowerRelayStationTemplate(ResourceHandle handle)
	{
		return (PowerRelayStationTemplate*)GetResource<PowerRelayStationTemplate>(handle);
	}

	//Metoda ksiêguje zarejstrowane nazwy za³adowanych zasobów
	void CResourceManager::GetAllStartingWith(const std::string &path, const std::string &type, std::vector<std::string> &out)
	{
		for (unsigned int i = 0; i < m_loaded_resource_names.size(); i++)
			if (m_loaded_resource_names[i].find(path) == 0)
				if (m_resources[stringutils::GetStringHash(m_loaded_resource_names[i])]->GetType() == type)
					out.push_back(m_loaded_resource_names[i]);
	}

	//Metoda usuwa zasób na podstawie nazwy std::string
	void CResourceManager::DropResource(const std::string& name)
	{
		ResourceHandle handle = stringutils::GetStringHash(name);	//zamieniamy nazwê zasobu na uchwyt
		if(m_resources.count(handle) > 0)							//jeœli w kontenerze s¹ obiekty
		{
			if(m_resources[handle] != NULL)							//jeœli pod wskazanym uchwytem s¹ dane
				m_resources[handle]->drop();						//niszczymy je (to co jest pod iteratorem)
			m_resources.erase(handle);								//i usuwamy z kontenera ten wspis
		}
	}

	//Metoda usuwa wszystkie zasoby
	void CResourceManager::Clear()
	{
		while(m_resources.size())						//dopóki w kontenerze s¹ obiekty przeszukujemy kontener
		{
			if(m_resources.begin()->second)				//jeœli pod pierwszym elementen s¹ dane
				m_resources.begin()->second->drop();	//niszczymy je (to co jest pod iteratorem)
			m_resources.erase(m_resources.begin());		//i usuwamy z kontenera ten wspis
														//ponownie ustawiaj¹c siê na pierwszy element kontenera
		}
		fprintf(stderr, "CResourceManager::Clear()\n");
	}

	//Wirtualny interfejs - implementacja
	void CResourceManager::Cleanup()
	{
		fprintf(stderr, "CResourceManager::Cleanup()\n");
		Clear();
		fprintf(stderr, "CResourceManager::Cleanup() done...\n");
	}

	//Szablon prywatnej metody zwracaj¹cej wskaŸnik na zasób na podstawie nazwy std::string
	template <typename T> T* CResourceManager::GetResource(const std::string& name)
	{
		ResourceHandle handle = stringutils::GetStringHash(name);	//zamieniamy nazwê na uchwyt
		if(m_resources.count(handle) > 0)							//jeœli w kontenerze s¹ obiekty
			return (T*)m_resources[handle];							//zwracamy zasób z kontenera pod tym kluczem
		else if(LoadResource<T>(name))								//w przeciwnym wypadku próbujemy za³adowaæ zasób
			return (T*)m_resources[handle];							//i po za³adowaniu zwróciæ
		else														//w przeciwnym wypadku
			return (T*)NULL;										//zwracamy wskaŸnik na NULL
	}

	//Szablon metody zwracaj¹cej zasób na podstawie uchwytu
	template <typename T> T* CResourceManager::GetResource(ResourceHandle handle)
	{
		if(m_resources.count(handle) > 0)
			return (T*)m_resources[handle];
		else
			return (T*)NULL;
	}

	//Szablon prywatnej metody ³aduj¹cej zasób
	template <typename T> ResourceHandle CResourceManager::LoadResource(const std::string& name)
	{
		ResourceHandle handle = InvalidResourceHandle;	//na wszelki wypadek zerujemy uchwyt
		handle = stringutils::GetStringHash(name);		//szyfrujemy funkcj¹ haszuj¹c¹ std::string na liczbê

		IResource* resource = new T();					//Tworzymy nowy obiekt szablonu
														//poniewa¿ wskaŸniki *IResource
														//przechowujemy w kontenerze zasobów.
														//Pamiêtaj, ¿e wskaŸnikiem na obiekt klasy
														//bazowej IResource, mo¿emy tak¿e pokazywaæ
														//na obiekty klas potomnych, czyli
														//np. CTexture, CSound, CMusic,CFont
														//i ka¿dy inny zasób. który Resource Manager
														//mo¿e produkowaæ
														//Wa¿ne:
														//Klasa taka musi dziedziczyæ po klasie IResource,
														//a ta ma tylko wirtualny interface.
														//Zatem w klasach potomnych trzeba zaimplemntowaæ
														//jako osobne metody:
														// virtual bool load(const std::string &file_name) = 0;
														// virtual void drop() = 0;

		if(resource->load(name))						//próbujemy za³adowaæ dane
		{
			m_resources[handle] = resource;				//jeœli to siê powiedzie, wstawiamy do kontenera 
														//wskaŸnik na zasób (value), pod klucz (key)
														//handle (uchwyt), wygenerowana liczba
														//za pomoc¹ funkcji hashuj¹cej
			m_loaded_resource_names.push_back(name);	//wstawiamy nazwê do kontenera
			return handle;								//zwracamy zasób, z którego mo¿na korzystaæ
			
		}
		else											//jeœli za³adowanie siê nie powiod³o
		{
			resource->drop();							//niszczymy zasób /patrz cia³o metody drop()/
			return InvalidResourceHandle;				//zwracamy zero...
		}
	}

	//Szablon prywatnej metody ³aduj¹ce zasoby (wzorce danych dla obiektów gry)
	template <> ResourceHandle CResourceManager::LoadResource<PhysicalTemplate>(const std::string& name)
	{
		return ParseHandle(name);
	}

	//Szablon prywatnej metody ³aduj¹ce zasoby (wzorce danych dla obiektów gry)
	template <> ResourceHandle CResourceManager::LoadResource<MapPhysicalTemplate>(const std::string& name)
	{
		return ParseHandle(name);
	}

	//Metoda parsuje i zwraca uchwyt zasobu
	ResourceHandle CResourceManager::ParseHandle(const std::string& name)
	{

		ResourceHandle handle = InvalidResourceHandle;	//na wszelki wypadek zerujemy uchwyt
		handle = stringutils::GetStringHash(name);		//szyfrujemy funkcj¹ haszuj¹c¹ std::string na liczbê

		if(m_resources.count(handle) != 0)				//jeœli w kontenerze ju¿ jest taki zasób (wzorzec)
			return handle;								//nie ma potrzeby go tworzyæ - zwracamy go

		CXml xml(name, "root" );						//tworzymy obiekt xml i otwieramy plik z damymi
		
		//Z pliku xml wzorca (factory, template) odczytujemy z wêz³a type
		//rodzaj wzorca, jaki mamy utworzyæ, a nastêpnie umieszczamy
		//go w kontenerze wzorców.
		//Na podstawie zarejestrowanych wzroców mo¿na tworzyæ obiekty,
		//które te wzrorce potrafi¹ generowaæ.

		//Fabryki tworz¹ ze wzorców obiekty poni¿szych klas:
		//
		//		- PhysicalTemplate						->tworzy->	Physical
		//		- ActorTemplate						->tworzy->	Actor
		//		- CRoborTemplate						->tworzy->	Robot
		//		- EnemyTemplate						->tworzy->	Enemy
		//		- PlayerTemplate						->tworzy->	Player
		//		- BulletTemplate						->tworzy->	Bullet
		//		- MonsterTemplate						->tworzy->	Monster
		//		- FuelTankTemplate						->tworzy->	FuelTank
		//		- EnergyTankTemplate					->tworzy->	EnergyTank
		//		- FuelBarTemplate						->tworzy->	FuelBar
		//		- EnergyTemplate						->tworzy->	Energy
		//		- BatteryTemplate						->tworzy->	Battery
		//		- SolarBatteryTemplate					->tworzy->	SolarBattery
		//		- AirconditioningTemplate				->tworzy->	Airconditioning
		//		- ThermalInsulationTemplate			->tworzy->	ThermalInsulation
		//		- VentilatorTemplate					->tworzy->	Ventilator
		//		- WindTurbineTemplate					->tworzy->	WindTurbine
		//		- SolarCellTemplate					->tworzy->	SolarCell
		//		- WindPowerStationTemplate				->tworzy->	WindPowerStation
		//		- WindPowerStationMultipledTemplate	->tworzy->	WindPowerStationMultipled
		//		- GroundWorkTemplate					->tworzy->	CGroundWork

		//		- GroundTemplate						->tworzy->	CGround

		//		- MapPhysicalTemplate					->tworzy->	CMapPhysical
		//		- InformationTemplate					->tworzy->	Information
		//		- PowerRelayStationTemplate			->tworzy->	PowerRelayStation
		//		- CommunicationTemplate				->tworzy->	Communication
		//		- SlotsRateTemplate					->tworzy->	SlotsRate
		//		- AmmoTemplate							->tworzy->	Ammo
		//		- GunTemplate							->tworzy->	Gun

		//Poza tym mo¿emy za³adowaæ do pamiêci, czyli do naszego CResourceManager
		//wzorce na obiekty ca³ego levelu.
		//Takie rozwi¹zanie, wymusza jakby sposób interpretacji
		//³adowanie danych - raz, na pocz¹tku rozgrywki (tylko raz czekamy, a¿ dane siê za³aduj¹)
		//Ma to zasadnicze znaczenie, szczególnie, gdyby projektowaæ
		//w technologiach web, mobilnych, telefony, etc...
		
		//pobieramy typ wzorca
		const std::string &type = xml.GetString(xml.GetRootNode(),"type");
		
		IResource *resource;	//tworzymy wskaŸnik na zasób
		
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

		if(resource->load(name))						//próbujemy za³adowaæ dane
		{
			m_resources[handle] = resource;				//jeœli to siê powiedzie, wstawiamy do kontenera 
														//wskaŸnik na zasób w zale¿noœci
														//od typu odczytanego z pliku xml
			
			m_loaded_resource_names.push_back(name);	//wstawiamy nazwê do kontenera
			return handle;								//zwracamy zasób, z którego mo¿na korzystaæ
		}
		else											//jeœli za³adowanie siê nie powiod³o
		{
			fprintf(stderr,"ERROR: Resource %s not found\n", name.c_str());
			m_errors_occured++;							//ksiêgujemy iloœæ b³êdów
			resource->drop();							//niszczymy zasób /patrz cia³o metody drop()/
			return InvalidResourceHandle;				//zwracamy zero...
		}
	}
}//namespace resource
