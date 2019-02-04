/*
 ____________________________________________
| CPhysicalManager.cpp - implementacja klasy |
| Jack Flower - November 2012.               |
|____________________________________________|

*/

#include "CPhysicalManager.h"
#include "Physical/CPhysical.h"
#include "Physical/PhysicalInfo/CPhysicalInfo.h"
#include "Actor/CActor.h"
#include "Enemy/CEnemy.h"
#include "Player/CPlayer.h"
#include "Bullet/CBullet.h"
#include "Monster/CMonster.h"
#include "Flora/CFlora.h"
#include "Unit/CombatUnit/Robot/CRobot.h"
#include "../Equipment/Engine/CEngine.h"
#include "../Equipment/Engine/FuelTank/CFuelTank.h"
#include "../Equipment/Engine/FuelBar/CFuelBar.h"
#include "../Equipment/Energy/CEnergy.h"
#include "../Equipment/Energy/EnergyTank/CEnergyTank.h"
#include "../Equipment/Energy/Battery/CBattery.h"
#include "../Equipment/Energy/Battery/CSolarBattery.h"
#include "../Equipment/Thermodynamics/Airconditioning/CAirconditioning.h"
#include "../Equipment/Thermodynamics/ThermalInsulation/CThermalInsulation.h"
#include "../Equipment/Thermodynamics/Ventilator/CVentilator.h"
#include "../Equipment/Weapon/Ammo/CAmmo.h"
#include "../Equipment/Weapon/Gun/CGun.h"
#include "../Equipment/Lightingequipment/CLightingEquipment.h"
#include "../Equipment/Industrial/PowerModuleType/CWindTurbine.h"
#include "../Equipment/Industrial/PowerModuleType/CSolarCell.h"
#include "Industrial/PowerStation//CPowerStation.h"
#include "Industrial/PowerStation/WindPowerStation/CWindPowerStation.h"
#include "Industrial/PowerStation/WindPowerStation/CWindPowerStationMultipled.h"
#include "Energetics/PowerRelay/CRelayStation.h"
#include "Energetics/PowerRelay/CPowerRelayStation.h"
#include "Energetics/PowerRelay/CSlotsRate.h"
#include "Communication/CCommunication.h"
#include "../Map/Ground/CGround.h"
#include "../Utilities/StringUtils/StringUtils.h"
#include "../Game/Game.h"
#include <sstream>

using namespace game;

template<> CPhysicalManager* CSingleton<CPhysicalManager>::m_singleton = 0;

namespace logic
{
	//Konstruktor
	CPhysicalManager::CPhysicalManager()
	{
		fprintf(stderr, "CPhysicalManager::CPhysicalManager()\n");
		gGame.addFrameListener(this);
	}

	//Destruktor wirtualny
	CPhysicalManager::~CPhysicalManager()
	{
		fprintf(stderr, "CPhysicalManager::~CPhysicalManager()\n");
		Clear(true);
	}

	//Wirtualna metoda - czyúci obiekty z kontenera
	void CPhysicalManager::frameStarted(float secondsPassed)
	{
		//Czyszczenie obiektÛw
		std::vector<CPhysical*>				dirty;		//kontener na obiekty do zniszczenia
		std::vector<CPhysical*>::iterator	it;			//iterator tego kontenera

		for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		{
			if ((*it)->m_ready_for_destruction)			//jeúli obiekt jest gotowy do zniszczaenia
				dirty.push_back(*it);					//wstawiamy go do kontenera "úmierci"
		}

		for (unsigned int i = 0; i < dirty.size(); i++)	//iterujemy po tym kontenerze
			DestroyPhysical(dirty[i]);					//i usuwamy obiekty

	}

	//Szablon metody tworzenia obiektÛw
	template<class T>
	T* CPhysicalManager::Create(const std::wstring &uniqueId)
	{
		std::wstring new_unique_id = uniqueId;
		if (uniqueId != L"")
		{
			CheckUniqueId(new_unique_id);

			if (m_named_physicals.find(new_unique_id) != m_named_physicals.end())
			{
				fprintf(stderr, "PhysicalsManager::Create<T> - %ls key already in m_named_physicals map", new_unique_id.c_str());
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

	//Metoda tworzy obiekt klasy CPhysical i zwraca wskaünik na ten obiekt
	CPhysical *CPhysicalManager::CreatePhysical(const std::wstring& unique_id)
	{
		fprintf(stderr, "CPhysical created\n");
		return Create<CPhysical>(unique_id);
	}

	//Metoda tworzy obiekt klasy CActor i zwraca wskaünik na ten obiekt
	CActor *CPhysicalManager::CreateActor(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CActor created\n");
		return Create<CActor>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CRobot i zwraca wskaünik na ten obiekt
	CRobot *CPhysicalManager::CreateRobot(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CRobot created\n");
		return Create<CRobot>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CEnemy i zwraca wskaünik na ten obiekt
	CEnemy *CPhysicalManager::CreateEnemy(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CEnemy created\n");
		return Create<CEnemy>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CPlayer i zwraca wskaünik na ten obiekt
	CPlayer *CPhysicalManager::CreatePlayer(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CPlayer created\n");
		return Create<CPlayer>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CBullet i zwraca wskaünik na ten obiekt
	CBullet *CPhysicalManager::CreateBullet(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CBullet created\n");
		return Create<CBullet>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CEngine i zwraca wskaünik na ten obiekt
	CEngine *CPhysicalManager::CreateEngine(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CEngine created\n");
		return Create<CEngine>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CFuelTank i zwraca wskaünik na ten obiekt
	CFuelTank *CPhysicalManager::CreateFuelTank(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CFuelTank created\n");
		return Create<CFuelTank>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CEnergy i zwraca wskaünik na ten obiekt
	CEnergy *CPhysicalManager::CreateEnergy(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CEnergy created\n");
		return Create<CEnergy>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CEnergyTank i zwraca wskaünik na ten obiekt
	CEnergyTank *CPhysicalManager::CreateCEnergyTank(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CEnergyTank created\n");
		return Create<CEnergyTank>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CMonster i zwraca wskaünik na ten obiekt
	CMonster *CPhysicalManager::CreateMonster(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CMonster created\n");
		return Create<CMonster>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CFlora i zwraca wskaünik na ten obiekt
	CFlora *CPhysicalManager::CreateFlora(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CFlora created\n");
		return Create<CFlora>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CFuelBar i zwraca wskaünik na ten obiekt
	CFuelBar *CPhysicalManager::CreateFuelBar(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CFuelBar created\n");
		return Create<CFuelBar>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CPhysicalInfo i zwraca wskaünik na ten obiekt
	CPhysicalInfo *CPhysicalManager::CreatePhysicalInfo(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CPhysicalInfo created\n");
		return Create<CPhysicalInfo>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CBattery i zwraca wskaünik na ten obiekt
	CBattery *CPhysicalManager::CreateBattery(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CBattery created\n");
		return Create<CBattery>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CSolarBattery i zwraca wskaünik na ten obiekt
	CSolarBattery *CPhysicalManager::CreateSolarBattery(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CBatteCSolarBatteryry created\n");
		return Create<CSolarBattery>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CAirconditioning i zwraca wskaünik na ten obiekt
	CAirconditioning *CPhysicalManager::CreateAirconditioning(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CAirconditioning created\n");
		return Create<CAirconditioning>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CThermalInsulation i zwraca wskaünik na ten obiekt
	CThermalInsulation *CPhysicalManager::CreateThermalInsulation(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CThermalInsulation created\n");
		return Create<CThermalInsulation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CVentilator i zwraca wskaünik na ten obiekt
	CVentilator *CPhysicalManager::CreateVentilator(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CVentilator created\n");
		return Create<CVentilator>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CAmmo i zwraca wskaünik na ten obiekt
	CAmmo *CPhysicalManager::CreateAmmo(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CAmmo created\n");
		return Create<CAmmo>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CGun i zwraca wskaünik na ten obiekt
	CGun *CPhysicalManager::CreateGun(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CGun created\n");
		return Create<CGun>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CGun i zwraca wskaünik na ten obiekt
	CWindTurbine *CPhysicalManager::CreateWindTurbine(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CWindTurbine created\n");
		return Create<CWindTurbine>(uniqueId);
	}


	//Metoda tworzy obiekt klasy CSolarCell i zwraca wskaünik na ten obiekt
	CSolarCell *CPhysicalManager::CreateSolarCell(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CSolarCell created\n");
		return Create<CSolarCell>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CPowerStation i zwraca wskaünik na ten obiekt
	CPowerStation *CPhysicalManager::CreatePowerStation(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CPowerStation created\n");
		return Create<CPowerStation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CWindPowerStation i zwraca wskaünik na ten obiekt
	CWindPowerStation *CPhysicalManager::CreateWindPowerStation(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CWindPowerStation created\n");
		return Create<CWindPowerStation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CWindPowerStationMultipled i zwraca wskaünik na ten obiekt
	CWindPowerStationMultipled *CPhysicalManager::CreateWindPowerStationMultipled(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CWindPowerStationMultipled created\n");
		return Create<CWindPowerStationMultipled>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CRelayStation i zwraca wskaünik na ten obiekt
	CRelayStation *CPhysicalManager::CreateRelayStation(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CRelayStation created\n");
		return Create<CRelayStation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CPowerRelayStation i zwraca wskaünik na ten obiekt
	CPowerRelayStation *CPhysicalManager::CreatePowerRelayStation(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CPowerRelayStation created\n");
		return Create<CPowerRelayStation>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CSlotsRate i zwraca wskaünik na ten obiekt
	CSlotsRate* CPhysicalManager::CreateSlotsRate(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CSlotsRate created\n");
		return Create<CSlotsRate>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CCommunication i zwraca wskaünik na ten obiekt
	CCommunication *CPhysicalManager::CreateCommunication(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CCommunication created\n");
		return Create<CCommunication>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CLightingEquipment i zwraca wskaünik na ten obiekt
	CLightingEquipment *CPhysicalManager::CreateLightingEquipment(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CLightingEquipment created\n");
		return Create<CLightingEquipment>(uniqueId);
	}

	//Metoda tworzy obiekt klasy CGround i zwraca wskaünik na ten obiekt
	CGround *CPhysicalManager::CreateGround(const std::wstring &uniqueId)
	{
		fprintf(stderr, "CGround created\n");
		return Create<CGround>(uniqueId);
	}
	
	//Metoda usuwa obiekt klasy CPhysical z kontenera
	void CPhysicalManager::DestroyPhysical(CPhysical* physical)
	{
		if (physical->m_physical_manager_index >= 0)
		{
			m_physicals[physical->m_physical_manager_index] = m_physicals[m_physicals.size()-1];
			m_physicals[physical->m_physical_manager_index]->m_physical_manager_index = physical->m_physical_manager_index;
			m_physicals.pop_back();
			physical->m_physical_manager_index = -1;
			fprintf(stderr, "PhysicalsManager::DestroyPhysical - %ls\n", physical->GetUniqueId().c_str());
			DestroyPhysical(physical->GetUniqueId());
			delete physical;
		}
	}

	//Metoda usuwa obiekt klasy CPhysical z kontenera
	void CPhysicalManager::DestroyPhysical(const std::wstring& id_physical)
	{
		if (m_named_physicals.find(id_physical) != m_named_physicals.end())
		{
			CPhysical* physical = m_named_physicals[id_physical];
			m_named_physicals.erase(m_named_physicals.find( id_physical));
			DestroyPhysical(physical);
		}
	}

	//Metoda usuwa wszystkie obiekty z kontenera
	void CPhysicalManager::Clear(bool force_destroy_instantly)
	{
		std::vector<CPhysical*>::iterator it;

		for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		{
			(*it)->MarkForDelete();
		}

		if (force_destroy_instantly)
		{
			frameStarted(0.0f);
		}
	}

	//Metoda zwraca sta≥π referencjÍ do kontenera z nazwami wszystkich zarejestorwanych obiektÛw CPhysical
	const std::map<std::wstring, CPhysical*>& CPhysicalManager::GetNamedPhysicals()
	{
		return m_named_physicals;
	}

	//Metoda zwraca sta≥π referencjÍ do kontenera z wszystkimi wskaünikami zarejestorwanych obiektÛw CPhysical
	const std::vector<CPhysical *> &CPhysicalManager::GetPhysicals()
	{
		return m_physicals;
	}

	//Metoda zwraca wskaünik na obiekt klasy CPhysical z kontenera na podstawie identyfikatora
	CPhysical* CPhysicalManager::GetPhysicalById(const std::wstring& physical_id)
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

	//Metoda zwraca sta≥π referencjÍ na kontener, w ktÛrym sπ wskaüniki na obiekty klasy CWindPowerStation
	//elektrownie wiatrowe
	const std::vector<CWindPowerStation*>& CPhysicalManager::GetWindPowerstations()
	{
		std::vector<CPhysical*>::iterator	it;	//iterator tego kontenera
		for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		{
			if ((*it)->GetCategory() == PHYSICAL_WINDPOWERSTATION)
				m_wind_powerstation.push_back((CWindPowerStation*)*it);
		}
		return m_wind_powerstation;
	}

	///
	///Wirtualny interfejs - implementacja
	///
	void CPhysicalManager::Cleanup()
	{
		fprintf(stderr, "CPhysicalManager::Cleanup()\n");

		//nie jestem do koÒca pewien tego kodu...
		//std::vector<CPhysical*>::iterator it;
		//for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		//	DestroyPhysical(*(it));
		Clear();
		fprintf(stderr, "CPhysicalManager::Cleanup() done...\n");
	}


	//implementajca metod private:

	//Prywatna metoda sprawdzajπca jaki identyfikator nadaÊ obiektowi przy utworzeniu
	void CPhysicalManager::CheckUniqueId(std::wstring& new_unique_id)
	{
		static long physicalCount = 0;
		//jeúli identyfikator jest ciπgiem pustych znakÛw
		//lub w kontenerze sπ juø jakieú nazwy
		if ((new_unique_id == L"" ) || (m_named_physicals.count(new_unique_id) > 0))
			do
			{
				//to tworzymy nazwÍ zsyntetyzowanπ
				//do s≥owa "physical" do dajemy wartoúÊ licznika zamienionπ na string
				new_unique_id = L"physical" + stringutils::ToWString(physicalCount++);
			}
			while (m_named_physicals.find(new_unique_id) != m_named_physicals.end());
	}
}//namespace logic
