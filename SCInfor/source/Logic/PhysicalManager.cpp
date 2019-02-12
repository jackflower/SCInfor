//  ____________________________________________
// | PhysicalManager.cpp - class implementation |
// | Jack Flower - November 2012                |
// |____________________________________________|
//

#include "PhysicalManager.h"
#include "Physical/Physical.h"
#include "Physical/PhysicalInfo/PhysicalInfo.h"
#include "Actor/Actor.h"
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Bullet/Bullet.h"
#include "Monster/Monster.h"
#include "Flora/Flora.h"
#include "Unit/CombatUnit/Robot/Robot.h"
#include "../Equipment/Engine/Engine.h"
#include "../Equipment/Engine/FuelTank/FuelTank.h"
#include "../Equipment/Engine/FuelBar/FuelBar.h"
#include "../Equipment/Energy/Energy.h"
#include "../Equipment/Energy/EnergyTank/EnergyTank.h"
#include "../Equipment/Energy/Battery/Battery.h"
#include "../Equipment/Energy/Battery/SolarBattery.h"
#include "../Equipment/Thermodynamics/Airconditioning/Airconditioning.h"
#include "../Equipment/Thermodynamics/ThermalInsulation/ThermalInsulation.h"
#include "../Equipment/Thermodynamics/Ventilator/Ventilator.h"
#include "../Equipment/Weapon/Ammo/Ammo.h"
#include "../Equipment/Weapon/Gun/Gun.h"
#include "../Equipment/Lightingequipment/LightingEquipment.h"
#include "../Equipment/Industrial/PowerModuleType/WindTurbine.h"
#include "../Equipment/Industrial/PowerModuleType/SolarCell.h"
#include "Industrial/PowerStation//PowerStation.h"
#include "Industrial/PowerStation/WindPowerStation/WindPowerStation.h"
#include "Industrial/PowerStation/WindPowerStation/WindPowerStationMultipled.h"
#include "Energetics/PowerRelay/RelayStation.h"
#include "Energetics/PowerRelay/PowerRelayStation.h"
#include "Energetics/PowerRelay/SlotsRate.h"
#include "Communication/Communication.h"
#include "../Map/Ground/CGround.h"
#include "../Utilities/StringUtils/StringUtils.h"
#include "../Game/Game.h"
#include <sstream>

using namespace game;

template<> PhysicalManager* CSingleton<PhysicalManager>::m_singleton = 0;

namespace logic
{
	//Konstruktor
	PhysicalManager::PhysicalManager()
	{
		fprintf(stderr, "PhysicalManager::PhysicalManager()\n");
		gGame.addFrameListener(this);
	}

	//Destruktor wirtualny
	PhysicalManager::~PhysicalManager()
	{
		fprintf(stderr, "PhysicalManager::~PhysicalManager()\n");
		clear(true);
	}

	//Wirtualna metoda - czyści obiekty z kontenera
	void PhysicalManager::frameStarted(float secondsPassed)
	{
		//Czyszczenie obiektów
		std::vector<Physical*>				dirty;		//kontener na obiekty do zniszczenia
		std::vector<Physical*>::iterator	it;			//iterator tego kontenera

		for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		{
			if ((*it)->m_ready_for_destruction)			//jeśli obiekt jest gotowy do zniszczaenia
				dirty.push_back(*it);					//wstawiamy go do kontenera "śmierci"
		}

		for (unsigned int i = 0; i < dirty.size(); i++)	//iterujemy po tym kontenerze
			destroyPhysical(dirty[i]);					//i usuwamy obiekty

	}

	//Szablon metody tworzenia obiektów
	template<class T>
	T* PhysicalManager::create(const std::wstring &uniqueId)
	{
		std::wstring new_unique_id = uniqueId;
		if (uniqueId != L"")
		{
			checkUniqueId(new_unique_id);

			if (m_named_physicals.find(new_unique_id) != m_named_physicals.end())
			{
				fprintf(stderr, "PhysicalsManager::create<T> - %ls key already in m_named_physicals map", new_unique_id.c_str());
				return NULL;
			}

			m_named_physicals[new_unique_id] = NULL; // zarezerwowanie nazwy przed utworzeniem obiektu
		}

		T* obj = new T(new_unique_id);
		obj->m_physical_manager_index = (int)m_physicals.size();
		m_physicals.push_back(obj);
		if (uniqueId != L"")
			m_named_physicals[new_unique_id] = obj;
		return obj;
	}

	//Metoda tworzy obiekt klasy Physical i zwraca wskaźnik na ten obiekt
	Physical *PhysicalManager::createPhysical(const std::wstring & unique_id)
	{
		fprintf(stderr, "Physical created\n");
		return create<Physical>(unique_id);
	}

	//Metoda tworzy obiekt klasy Actor i zwraca wskaźnik na ten obiekt
	Actor *PhysicalManager::createActor(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Actor created\n");
		return create<Actor>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Robot i zwraca wskaźnik na ten obiekt
	Robot *PhysicalManager::createRobot(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Robot created\n");
		return create<Robot>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Enemy i zwraca wskaźnik na ten obiekt
	Enemy *PhysicalManager::createEnemy(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Enemy created\n");
		return create<Enemy>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Player i zwraca wskaźnik na ten obiekt
	Player *PhysicalManager::createPlayer(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Player created\n");
		return create<Player>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Bullet i zwraca wskaźnik na ten obiekt
	Bullet *PhysicalManager::createBullet(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Bullet created\n");
		return create<Bullet>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Engine i zwraca wskaźnik na ten obiekt
	Engine *PhysicalManager::createEngine(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Engine created\n");
		return create<Engine>(uniqueId);
	}

	//Metoda tworzy obiekt klasy FuelTank i zwraca wskaźnik na ten obiekt
	FuelTank *PhysicalManager::createFuelTank(const std::wstring & uniqueId)
	{
		fprintf(stderr, "FuelTank created\n");
		return create<FuelTank>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Energy i zwraca wskaźnik na ten obiekt
	Energy *PhysicalManager::createEnergy(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Energy created\n");
		return create<Energy>(uniqueId);
	}

	//Metoda tworzy obiekt klasy EnergyTank i zwraca wskaźnik na ten obiekt
	EnergyTank *PhysicalManager::createEnergyTank(const std::wstring & uniqueId)
	{
		fprintf(stderr, "EnergyTank created\n");
		return create<EnergyTank>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Monster i zwraca wskaźnik na ten obiekt
	Monster *PhysicalManager::createMonster(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Monster created\n");
		return create<Monster>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Flora i zwraca wskaźnik na ten obiekt
	Flora *PhysicalManager::createFlora(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Flora created\n");
		return create<Flora>(uniqueId);
	}

	//Metoda tworzy obiekt klasy FuelBar i zwraca wskaźnik na ten obiekt
	FuelBar *PhysicalManager::createFuelBar(const std::wstring & uniqueId)
	{
		fprintf(stderr, "FuelBar created\n");
		return create<FuelBar>(uniqueId);
	}

	//Metoda tworzy obiekt klasy PhysicalInfo i zwraca wskaźnik na ten obiekt
	PhysicalInfo *PhysicalManager::createPhysicalInfo(const std::wstring & uniqueId)
	{
		fprintf(stderr, "PhysicalInfo created\n");
		return create<PhysicalInfo>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Battery i zwraca wskaźnik na ten obiekt
	Battery *PhysicalManager::createBattery(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Battery created\n");
		return create<Battery>(uniqueId);
	}

	//Metoda tworzy obiekt klasy SolarBattery i zwraca wskaźnik na ten obiekt
	SolarBattery *PhysicalManager::createSolarBattery(const std::wstring & uniqueId)
	{
		fprintf(stderr, "CBatteCSolarBatteryry created\n");
		return create<SolarBattery>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Airconditioning i zwraca wskaźnik na ten obiekt
	Airconditioning *PhysicalManager::createAirconditioning(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Airconditioning created\n");
		return create<Airconditioning>(uniqueId);
	}

	//Metoda tworzy obiekt klasy ThermalInsulation i zwraca wskaźnik na ten obiekt
	ThermalInsulation *PhysicalManager::createThermalInsulation(const std::wstring & uniqueId)
	{
		fprintf(stderr, "ThermalInsulation created\n");
		return create<ThermalInsulation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Ventilator i zwraca wskaźnik na ten obiekt
	Ventilator *PhysicalManager::createVentilator(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Ventilator created\n");
		return create<Ventilator>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Ammo i zwraca wskaźnik na ten obiekt
	Ammo *PhysicalManager::createAmmo(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Ammo created\n");
		return create<Ammo>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Gun i zwraca wskaźnik na ten obiekt
	Gun *PhysicalManager::createGun(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Gun created\n");
		return create<Gun>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Gun i zwraca wskaźnik na ten obiekt
	WindTurbine *PhysicalManager::createWindTurbine(const std::wstring & uniqueId)
	{
		fprintf(stderr, "WindTurbine created\n");
		return create<WindTurbine>(uniqueId);
	}


	//Metoda tworzy obiekt klasy SolarCell i zwraca wskaźnik na ten obiekt
	SolarCell *PhysicalManager::createSolarCell(const std::wstring & uniqueId)
	{
		fprintf(stderr, "SolarCell created\n");
		return create<SolarCell>(uniqueId);
	}

	//Metoda tworzy obiekt klasy PowerStation i zwraca wskaźnik na ten obiekt
	PowerStation *PhysicalManager::createPowerStation(const std::wstring & uniqueId)
	{
		fprintf(stderr, "PowerStation created\n");
		return create<PowerStation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy WindPowerStation i zwraca wskaźnik na ten obiekt
	WindPowerStation *PhysicalManager::createWindPowerStation(const std::wstring & uniqueId)
	{
		fprintf(stderr, "WindPowerStation created\n");
		return create<WindPowerStation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy WindPowerStationMultipled i zwraca wskaźnik na ten obiekt
	WindPowerStationMultipled *PhysicalManager::createWindPowerStationMultipled(const std::wstring & uniqueId)
	{
		fprintf(stderr, "WindPowerStationMultipled created\n");
		return create<WindPowerStationMultipled>(uniqueId);
	}

	//Metoda tworzy obiekt klasy RelayStation i zwraca wskaźnik na ten obiekt
	RelayStation *PhysicalManager::createRelayStation(const std::wstring & uniqueId)
	{
		fprintf(stderr, "RelayStation created\n");
		return create<RelayStation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy PowerRelayStation i zwraca wskaźnik na ten obiekt
	PowerRelayStation *PhysicalManager::createPowerRelayStation(const std::wstring & uniqueId)
	{
		fprintf(stderr, "PowerRelayStation created\n");
		return create<PowerRelayStation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy SlotsRate i zwraca wskaźnik na ten obiekt
	SlotsRate* PhysicalManager::createSlotsRate(const std::wstring & uniqueId)
	{
		fprintf(stderr, "SlotsRate created\n");
		return create<SlotsRate>(uniqueId);
	}

	//Metoda tworzy obiekt klasy Communication i zwraca wskaźnik na ten obiekt
	Communication *PhysicalManager::createCommunication(const std::wstring & uniqueId)
	{
		fprintf(stderr, "Communication created\n");
		return create<Communication>(uniqueId);
	}

	//Metoda tworzy obiekt klasy LightingEquipment i zwraca wskaźnik na ten obiekt
	LightingEquipment *PhysicalManager::createLightingEquipment(const std::wstring & uniqueId)
	{
		fprintf(stderr, "LightingEquipment created\n");
		return create<LightingEquipment>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CGround i zwraca wskaźnik na ten obiekt
	CGround *PhysicalManager::createGround(const std::wstring & uniqueId)
	{
		fprintf(stderr, "CGround created\n");
		return create<CGround>(uniqueId);
	}
	
	//Metoda usuwa obiekt klasy Physical z kontenera
	void PhysicalManager::destroyPhysical(Physical *physical)
	{
		if (physical->m_physical_manager_index >= 0)
		{
			m_physicals[physical->m_physical_manager_index] = m_physicals[m_physicals.size()-1];
			m_physicals[physical->m_physical_manager_index]->m_physical_manager_index = physical->m_physical_manager_index;
			m_physicals.pop_back();
			physical->m_physical_manager_index = -1;
			fprintf(stderr, "PhysicalsManager::DestroyPhysical - %ls\n", physical->getUniqueId().c_str());
			destroyPhysical(physical->getUniqueId());
			delete physical;
		}
	}

	//Metoda usuwa obiekt klasy Physical z kontenera
	void PhysicalManager::destroyPhysical(const std::wstring & id_physical)
	{
		if (m_named_physicals.find(id_physical) != m_named_physicals.end())
		{
			Physical* physical = m_named_physicals[id_physical];
			m_named_physicals.erase(m_named_physicals.find( id_physical));
			destroyPhysical(physical);
		}
	}

	//Metoda usuwa wszystkie obiekty z kontenera
	void PhysicalManager::clear(bool force_destroy_instantly)
	{
		std::vector<Physical*>::iterator it;

		for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		{
			(*it)->markForDelete();
		}

		if (force_destroy_instantly)
		{
			frameStarted(0.0f);
		}
	}

	//Metoda zwraca stałą referencję do kontenera z nazwami wszystkich zarejestorwanych obiektów Physical
	const std::map<std::wstring, Physical*> & PhysicalManager::getNamedPhysicals()
	{
		return m_named_physicals;
	}

	//Metoda zwraca stałą referencję do kontenera z wszystkimi wskaźnikami zarejestorwanych obiektów Physical
	const std::vector<Physical *> & PhysicalManager::getPhysicals()
	{
		return m_physicals;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Physical z kontenera na podstawie identyfikatora
	Physical *PhysicalManager::getPhysicalById(const std::wstring & physical_id)
	{
		if (m_named_physicals.find(physical_id) != m_named_physicals.end())
			return m_named_physicals[physical_id];
		else
		{
			fprintf(stderr, "PhysicalsManager::GetPhysicalById - %ls key not found in m_named_physicals map", physical_id.c_str());
			return NULL;
		}
	}

	//metody p o m o c n i c z e	implementacja

	//Metoda zwraca stałą referencję na kontener, w którym są wskaźniki na obiekty klasy WindPowerStation
	//elektrownie wiatrowe
	const std::vector<WindPowerStation*> & PhysicalManager::getWindPowerstations()
	{
		std::vector<Physical*>::iterator it; //iterator tego kontenera
		for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		{
			if ((*it)->getCategory() == PHYSICAL_WINDPOWERSTATION)
				m_wind_powerstation.push_back((WindPowerStation*)*it);
		}
		return m_wind_powerstation;
	}

	///
	///Wirtualny interfejs - implementacja
	///
	void PhysicalManager::cleanup()
	{
		fprintf(stderr, "PhysicalManager::Cleanup()\n");

		//nie jestem do końca pewien tego kodu...
		//std::vector<Physical*>::iterator it;
		//for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		//	DestroyPhysical(*(it));
		clear();
		fprintf(stderr, "PhysicalManager::Cleanup() done...\n");
	}


	//implementajca metod private:

	//Prywatna metoda sprawdzająca jaki identyfikator nadać obiektowi przy utworzeniu
	void PhysicalManager::checkUniqueId(std::wstring & new_unique_id)
	{
		static long physicalCount = 0;
		//jeśli identyfikator jest ciągiem pustych znaków
		//lub w kontenerze są już jakieś nazwy
		if ((new_unique_id == L"" ) || (m_named_physicals.count(new_unique_id) > 0))
			do
			{
				//to tworzymy nazwę zsyntetyzowaną
				//do słowa "physical" do dajemy wartość licznika zamienioną na string
				new_unique_id = L"physical" + stringutils::ToWString(physicalCount++);
			}
			while (m_named_physicals.find(new_unique_id) != m_named_physicals.end());
	}
}//namespace logic
