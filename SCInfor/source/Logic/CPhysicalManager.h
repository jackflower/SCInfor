/*
 ____________________________________________
| CPhysicalManager.h - definicja klasy       |
| Jack Flower - November 2012.               |
|____________________________________________|

*/

#ifndef H_PHYSICAL_MANAGER_JACK
#define H_PHYSICAL_MANAGER_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "../Game/Listener/IFrameListener.h"
#include <string>
#include <map>

#define gPhysicalManager CPhysicalManager::GetSingleton()

///
///Forward declaration
///
namespace logic
{
	class Physical;
	class Actor;
	class Enemy;
	class CPlayer;
	class Bullet;
	class Monster;
	class Flora;
	class PhysicalInfo;
	namespace unit
	{
		class CRobot;
	}
	namespace powerstation
	{
		class PowerStation;
		class WindPowerStation;
		class WindPowerStationMultipled;
	}
	namespace energetics
	{
		class RelayStation;
		class PowerRelayStation;
		class SlotsRate;
	}
	namespace communication
	{
		class Communication;
	}
}

///
///Forward declaration
///
namespace equipment
{
	class Engine;
	class FuelTank;
	class Energy;
	class EnergyTank;
	class FuelBar;
	class Airconditioning;
	class ThermalInsulation;
	class Ventilator;
	class WindTurbine;
	class SolarCell;
	class LightingEquipment;

	namespace weapon
	{
		class Ammo;
		class Gun;
	}

	namespace battery
	{
		class Battery;
		class SolarBattery;
	}
}

///
///Forward declaration
///
namespace mapengine
{
	class CGround;
}

//fabryka moøe produkowaÊ obiekty wyøej wymienionych klasy

using namespace listener;
using namespace equipment;
using namespace equipment::weapon;
using namespace equipment::battery;
using namespace logic::powerstation;
using namespace logic::energetics;
using namespace logic::communication;
using namespace logic::unit;
using namespace mapengine;

namespace logic
{
	///
	///Klasa reprezentuje fabrykÍ produkujπcπ obiekty gry i zarzπdzanie obiektami
	///
	class CPhysicalManager : public CSingleton<CPhysicalManager>, public IFrameListener
	{
	public:

		///
		///Konstruktor
		///
		CPhysicalManager();

		///
		///Destruktor wirtualny
		///
		virtual ~CPhysicalManager();

		///
		///Wirtualna metoda - czyúci obiekty z kontenera
		///
		///@param secondsPassed - up≥ywajπcy czas
		///
		virtual void frameStarted(float secondsPassed);
		
		///
		///Metoda tworzy obiekt klasy Physical i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Physical* CreatePhysical(const std::wstring& unique_id = L"");

		///
		///Metoda tworzy obiekt klasy Actor i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Actor *CreateActor(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CRobot i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CRobot *CreateRobot(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Enemy i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Enemy *CreateEnemy(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CPlayer i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CPlayer *CreatePlayer(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Bullet i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Bullet *CreateBullet(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Engine i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Engine *CreateEngine(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy FuelTank i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		FuelTank *CreateFuelTank(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Energy i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Energy *CreateEnergy(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy EnergyTank i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		EnergyTank *CreateEnergyTank(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Monster i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Monster *CreateMonster(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Flora i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Flora *CreateFlora(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy FuelBar i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		FuelBar *CreateFuelBar(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy PhysicalInfo i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		PhysicalInfo *CreatePhysicalInfo(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Battery i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Battery *CreateBattery(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy SolarBattery i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		SolarBattery *CreateSolarBattery(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Airconditioning i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Airconditioning *CreateAirconditioning(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy ThermalInsulation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		ThermalInsulation *CreateThermalInsulation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Ventilator i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Ventilator *CreateVentilator(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Ammo i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Ammo *CreateAmmo(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Gun i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Gun *CreateGun(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy WindTurbine i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		WindTurbine *CreateWindTurbine(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy SolarCell i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		SolarCell *CreateSolarCell(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy PowerStation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		PowerStation *CreatePowerStation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy WindPowerStation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		WindPowerStation *CreateWindPowerStation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy WindPowerStationMultipled i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		WindPowerStationMultipled *CreateWindPowerStationMultipled(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy RelayStation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		RelayStation *CreateRelayStation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy PowerRelayStation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		PowerRelayStation *CreatePowerRelayStation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy SlotsRate i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		SlotsRate* CreateSlotsRate(const std::wstring &uniqueId = L"");
		
		///
		///Metoda tworzy obiekt klasy Communication i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Communication *CreateCommunication(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy LightingEquipment i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		LightingEquipment *CreateLightingEquipment(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CGround i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CGround *CreateGround(const std::wstring &uniqueId = L"");

		///
		///Metoda usuwa obiekt klasy Physical z kontenera
		///
		///@param *physical - wskaünik na obiekt klasy Physical
		///
		void DestroyPhysical(Physical* physical);
	    
		///
		///Metoda usuwa obiekt klasy Physical z kontenera
		///
		///@param &id_physical - sta≥a referencja na obiekt klasy std::wstring - unikalny identyfikator obiektu
		///
		void DestroyPhysical(const std::wstring& id_physical);

		///
		///Metoda usuwa wszystkie obiekty z kontenera
		///
		///@param force_destroy_instantly - flaga, czy usunπÊ z kontenera wszystkie obiekty
		///
		void Clear(bool force_destroy_instantly = false);

		///
		///Metoda zwraca sta≥a referencjÍ do kontenera z nazwami wszystkich zarejestorwanych obiektÛw Physical
		///
		const std::map<std::wstring, Physical*>& GetNamedPhysicals();

		///
		///Metoda zwraca sta≥a referencjÍ do kontenera z wszystkimi wskaünikami zarejestorwanych obiektÛw Physical
		///
		const std::vector<Physical*>& GetPhysicals();

		///
		///Metoda zwraca wskaünik na obiekt klasy Physical z kontenera na podstawie identyfikatora
		///
		///@param &physical_id - sta≥a referencja na obiekt klasy std::wstring
		///
		Physical* GetPhysicalById(const std::wstring& physical_id);
				
		
		//metody p o m o c n i c z e

		///
		///Metoda zwraca sta≥π referencjÍ na kontener, w ktÛrym sπ wskaüniki na obiekty klasy WindPowerStation
		////elektrownie wiatrowe
		///
		const std::vector<WindPowerStation*>& GetWindPowerstations();

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void Cleanup();
		

	private:
		
		//
		//Szablon metody tworzenia obiektÛw
		//
		template<class T> T* create(const std::wstring &uniqueId);
	    
		std::map<std::wstring, Physical*>	m_named_physicals;	//kontener <map> na nazwane obiekty klasy Physical
		std::vector<Physical*>				m_physicals;		//kontener <vector> na wskaüniki na obiekty klasy Physical
		std::vector<WindPowerStation*>		m_wind_powerstation;		//elektrownie wiatrowa
		//
		//Prywatna metoda sprawdzajπca jaki identyfikator nadaÊ obiektowi przy utworzeniu
		//
		//@param &new_unique_id - referencja na obiekt klasy std::wstring
		//
		void CheckUniqueId(std::wstring& new_unique_id);
	};
}//namespace logic
#endif//H_PHYSICAL_MANAGER_JACK
