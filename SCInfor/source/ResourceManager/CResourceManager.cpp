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
#include "../Factory/CPhysicalTemplate.h"
#include "../Factory/CActorTemplate.h"
#include "../Factory/CRobotTemplate.h"
#include "../Factory/CEnemyTemplate.h"
#include "../Factory/CPlayerTemplate.h"
#include "../Factory/CBulletTemplate.h"
#include "../Factory/CMonsterTemplate.h"
#include "../Factory/CFloraTemplate.h"
#include "../Factory/CPhysicalInfoTemplate.h"
#include "../Factory/InformationFactory/CInformationTemplate.h"
#include "../Factory/InformationFactory/CPresentationTemplate.h"
//#include "../Factory/InformationFactory/CCounterTemplate.h"
//#include "../Factory/InformationFactory/CDigitalCounterTemplate.h"
#include "../Factory/MapPhysicalFactory/CMapPhysicalTemplate.h"
#include "../Factory/MapPhysicalFactory/CGroundWorkTemplate.h"
#include "../Factory/MapPhysicalFactory/CGroundTemplate.h"
#include "../Factory/EquipmentFactory/EngineFactory/CEngineTemplate.h"
#include "../Factory/EquipmentFactory/EngineFactory/FuelTankFactory/CFuelTankTemplate.h"
#include "../Factory/EquipmentFactory/EngineFactory/FuelBarFactory/CFuelBarTemplate.h"
#include "../Factory/EquipmentFactory/EnergyFactory/CEnergyTemplate.h"
#include "../Factory/EquipmentFactory/EnergyFactory/EnergyTankFactory/CEnergyTankTemplate.h"
#include "../Factory/EquipmentFactory/EnergyFactory/BatteryFactory/CBatteryTemplate.h"
#include "../Factory/EquipmentFactory/EnergyFactory/BatteryFactory/CSolarBatteryTemplate.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/AirconditioningFactory/CAirconditioningTemplate.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/ThermalInsulationFactory/CThermalInsulationTemplate.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/VentilatorFactory/CVentilatorTemplate.h"
#include "../Factory/EquipmentFactory/IndustrialFactory/PowerModuleFactory/CWindTurbineTemplate.h"
#include "../Factory/EquipmentFactory/IndustrialFactory/PowerModuleFactory/CSolarCellTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/CWindPowerStationTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/CWindPowerStationMultipledTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/PowerRelayFactory/CPowerRelayStationTemplate.h"
#include "../Factory/EquipmentFactory/CommunicationFactory/CCommunicationTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/PowerRelayFactory/CSlotsRateTemplate.h"
#include "../Factory/EquipmentFactory/WeaponFactory/AmmoFactory/CAmmoTemplate.h"
#include "../Factory/EquipmentFactory/WeaponFactory/GunFactory/CGunTemplate.h"
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

	//Metoda ³aduje zasób CPhysicalTemplate
	ResourceHandle CResourceManager::LoadPhysicalTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadPhysicalTemplate() %s\n", name.c_str());
		return LoadResource<CPhysicalTemplate>(name);
	}

	//Metoda ³aduje zasób CMapPhysicalTemplate
	ResourceHandle CResourceManager::LoadMapPhysicalTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadMapPhysicalTemplate() %s\n", name.c_str());
		return LoadResource<CMapPhysicalTemplate>(name);
	}

	//Metoda ³aduje zasób CMap
	ResourceHandle CResourceManager::LoadMap(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadMap() %s\n", name.c_str());
		return LoadResource<CMap>(name);
	}

	//Metoda ³aduje zasób CGroundWorkTemplate
	ResourceHandle CResourceManager::LoadGroundWorkTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadGroundWorkTemplate() %s\n", name.c_str());
		return LoadResource<CGroundWorkTemplate>(name);
	}

	//Metoda ³aduje zasób CInformationTemplate
	ResourceHandle CResourceManager::LoadInformationTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadInformationTemplate() %s\n", name.c_str());
		return LoadResource<CInformationTemplate>(name);
	}

	//Metoda ³aduje zasób CPresentationTemplate
	ResourceHandle CResourceManager::LoadPresentationTemplate(const std::string& name)
	{
		fprintf(stderr, "CResourceManager::LoadPresentationTemplate() %s\n", name.c_str());
		return LoadResource<CPresentationTemplate>(name);
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

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CPhysicalTemplate
	CPhysicalTemplate* CResourceManager::GetPhysicalTemplate(const std::string& name)
	{
		return (CPhysicalTemplate*)GetResource<CPhysicalTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CMapPhysicalTemplate
	CMapPhysicalTemplate* CResourceManager::GetMapPhysicalTemplate(const std::string& name)
	{
		return (CMapPhysicalTemplate*)GetResource<CMapPhysicalTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CMap
	CMap* CResourceManager::GetMap(const std::string& name)
	{
		return (CMap*)GetResource<CMap>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CGround
	CGroundTemplate* CResourceManager::GetGround(const std::string& name)
	{
		return (CGroundTemplate*)GetResource<CGroundTemplate>(name);
	}
	
	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CGroundWorkTemplate
	CGroundWorkTemplate* CResourceManager::GetGroundWorkTemplate(const std::string& name)
	{
		return (CGroundWorkTemplate*)GetResource<CGroundWorkTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CInformationTemplate
	CInformationTemplate* CResourceManager::GetInformationTemplate(const std::string& name)
	{
		return (CInformationTemplate*)GetResource<CInformationTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy GetPresentationTemplate
	CPresentationTemplate* CResourceManager::GetPresentationTemplate(const std::string& name)
	{
		return (CPresentationTemplate*)GetResource<CPresentationTemplate>(name);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CPowerRelayStationTemplate
	CPowerRelayStationTemplate* CResourceManager::GetPowerRelayStationTemplate(const std::string& name)
	{
		return (CPowerRelayStationTemplate*)GetResource<CPowerRelayStationTemplate>(name);
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

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CPhysicalTemplate
	CPhysicalTemplate* CResourceManager::GetPhysicalTemplate(ResourceHandle handle)
	{
		return (CPhysicalTemplate*)GetResource<CPhysicalTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CmapPhysicalTemplate
	CMapPhysicalTemplate* CResourceManager::GetMapPhysicalTemplate(ResourceHandle handle)
	{
		return (CMapPhysicalTemplate*)GetResource<CMapPhysicalTemplate>(handle);
	}
	
	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CMap
	CMap* CResourceManager::GetMap(ResourceHandle handle)
	{
		return (CMap*)GetResource<CMap>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CGroundTemplate
	CGroundTemplate* CResourceManager::GetGroundTemplate(ResourceHandle handle)
	{
		return (CGroundTemplate*)GetResource<CGroundTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CGroundWorkTemplate
	CGroundWorkTemplate* CResourceManager::GetGroundWorkTemplate(ResourceHandle handle)
	{
		return (CGroundWorkTemplate*)GetResource<CGroundWorkTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CInformationTemplate
	CInformationTemplate* CResourceManager::GetInformationTemplate(ResourceHandle handle)
	{
		return (CInformationTemplate*)GetResource<CInformationTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CPresentationTemplate
	CPresentationTemplate* CResourceManager::GetPresentationTemplate(ResourceHandle handle)
	{
		return (CPresentationTemplate*)GetResource<CPresentationTemplate>(handle);
	}

	//Metoda zwraca wskaŸnik na zasób - obiekt klasy CPowerRelayStationTemplate
	CPowerRelayStationTemplate* CResourceManager::GetPowerRelayStationTemplate(ResourceHandle handle)
	{
		return (CPowerRelayStationTemplate*)GetResource<CPowerRelayStationTemplate>(handle);
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
				m_resources[handle]->Drop();						//niszczymy je (to co jest pod iteratorem)
			m_resources.erase(handle);								//i usuwamy z kontenera ten wspis
		}
	}

	//Metoda usuwa wszystkie zasoby
	void CResourceManager::Clear()
	{
		while(m_resources.size())						//dopóki w kontenerze s¹ obiekty przeszukujemy kontener
		{
			if(m_resources.begin()->second)				//jeœli pod pierwszym elementen s¹ dane
				m_resources.begin()->second->Drop();	//niszczymy je (to co jest pod iteratorem)
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
														// virtual bool Load(const std::string &file_name) = 0;
														// virtual void Drop() = 0;

		if(resource->Load(name))						//próbujemy za³adowaæ dane
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
			resource->Drop();							//niszczymy zasób /patrz cia³o metody Drop()/
			return InvalidResourceHandle;				//zwracamy zero...
		}
	}

	//Szablon prywatnej metody ³aduj¹ce zasoby (wzorce danych dla obiektów gry)
	template <> ResourceHandle CResourceManager::LoadResource<CPhysicalTemplate>(const std::string& name)
	{
		return ParseHandle(name);
	}

	//Szablon prywatnej metody ³aduj¹ce zasoby (wzorce danych dla obiektów gry)
	template <> ResourceHandle CResourceManager::LoadResource<CMapPhysicalTemplate>(const std::string& name)
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
		//		- CPhysicalTemplate						->tworzy->	CPhysical
		//		- CActorTemplate						->tworzy->	CActor
		//		- CRoborTemplate						->tworzy->	CRobot
		//		- CEnemyTemplate						->tworzy->	CEnemy
		//		- CPlayerTemplate						->tworzy->	CPlayer
		//		- CBulletTemplate						->tworzy->	CBullet
		//		- CMonsterTemplate						->tworzy->	CMonster
		//		- CFuelTankTemplate						->tworzy->	FuelTank
		//		- CEnergyTankTemplate					->tworzy->	EnergyTank
		//		- CFuelBarTemplate						->tworzy->	FuelBar
		//		- CEnergyTemplate						->tworzy->	Energy
		//		- CBatteryTemplate						->tworzy->	Battery
		//		- CSolarBatteryTemplate					->tworzy->	SolarBattery
		//		- CAirconditioningTemplate				->tworzy->	Airconditioning
		//		- CThermalInsulationTemplate			->tworzy->	ThermalInsulation
		//		- CVentilatorTemplate					->tworzy->	CVentilator
		//		- CWindTurbineTemplate					->tworzy->	WindTurbine
		//		- CSolarCellTemplate					->tworzy->	SolarCell
		//		- CWindPowerStationTemplate				->tworzy->	CWindPowerStation
		//		- CWindPowerStationMultipledTemplate	->tworzy->	CWindPowerStationMultipled
		//		- CGroundWorkTemplate					->tworzy->	CGroundWork

		//		- CGroundTemplate						->tworzy->	CGround

		//		- CMapPhysicalTemplate					->tworzy->	CMapPhysical
		//		- CInformationTemplate					->tworzy->	CInformation
		//		- CPowerRelayStationTemplate			->tworzy->	CPowerRelayStation
		//		- CCommunicationTemplate				->tworzy->	CCommunication
		//		- CSlotsRateTemplate					->tworzy->	CSlotsRate
		//		- CAmmoTemplate							->tworzy->	CAmmo
		//		- CGunTemplate							->tworzy->	CGun

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
			resource = new CEnemyTemplate();
		else if(type == "player")
			resource = new CPlayerTemplate();
		else if(type == "bullet")
			resource = new CBulletTemplate();
		else if(type == "engine")
			resource = new CEngineTemplate();
		else if(type == "fueltank")
			resource = new CFuelTankTemplate();
		else if(type == "fuelbar")
			resource = new CFuelBarTemplate();
		else if(type == "energy")
			resource = new CEnergyTemplate();
		else if(type == "battery")
			resource = new CBatteryTemplate();
		else if(type == "solarbattery")
			resource = new CSolarBatteryTemplate();
		else if(type == "physicalinfo")
			resource = new CPhysicalInfoTemplate();
		else if(type == "energy")
			resource = new CEnergyTemplate();
		else if(type == "energytank")
			resource = new CEnergyTankTemplate();
		else if(type == "monster")
			resource = new CMonsterTemplate();
		else if(type == "flora")
			resource = new CFloraTemplate();
		else if(type == "airconditioning")
			resource = new CAirconditioningTemplate();
		else if(type == "thermalinsulation")
			resource = new CThermalInsulationTemplate();
		else if(type == "ventilator")
			resource = new CVentilatorTemplate();
		else if(type == "windturbine")
			resource = new CWindTurbineTemplate();
		else if(type == "solarcell")
			resource = new CSolarCellTemplate();
		else if(type == "powerstation")
			resource = new CWindPowerStationTemplate();
		else if (type == "powerstationmultipled")
			resource = new CWindPowerStationMultipledTemplate();
		else if(type == "mapphysical")
			resource = new CMapPhysicalTemplate();
		else if(type == "groundwork")
			resource = new CGroundWorkTemplate();
		else if(type == "information")
			resource = new CInformationTemplate();
		else if(type == "presentation")
			resource = new CPresentationTemplate();
		else if(type == "relaystation")
			resource = new CPowerRelayStationTemplate();
		else if (type == "communication")
			resource = new CCommunicationTemplate();
		else if (type == "slotsrate")
			resource = new CSlotsRateTemplate();
		else if (type == "ground")
			resource = new CGroundTemplate();
		else if (type == "ammo")
			resource = new CAmmoTemplate();
		else if (type == "gun")
			resource = new CGunTemplate();
		else if (type == "robot")
			resource = new CRobotTemplate();
		else
			return InvalidResourceHandle;

		if(resource->Load(name))						//próbujemy za³adowaæ dane
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
			resource->Drop();							//niszczymy zasób /patrz cia³o metody Drop()/
			return InvalidResourceHandle;				//zwracamy zero...
		}
	}
}//namespace resource
