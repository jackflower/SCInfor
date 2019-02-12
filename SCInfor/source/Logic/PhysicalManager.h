//  ____________________________________________
// | PhysicalManager.h - class definition       |
// | Jack Flower - November 2012                |
// |____________________________________________|
//

#ifndef H_PHYSICAL_MANAGER_JACK
#define H_PHYSICAL_MANAGER_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "../Game/Listener/IFrameListener.h"
#include <string>
#include <map>

#define gPhysicalManager PhysicalManager::GetSingleton()

///
///Forward declaration
///
namespace logic
{
	class Physical;
	class Actor;
	class Enemy;
	class Player;
	class Bullet;
	class Monster;
	class Flora;
	class PhysicalInfo;

	namespace unit
	{
		class Robot;
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

//fabryka może produkować obiekty wyżej wymienionych klasy

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
	///Klasa reprezentuje fabrykę produkującą obiekty gry i zarządzanie obiektami
	///
	class PhysicalManager : public CSingleton<PhysicalManager>, public IFrameListener
	{
	public:

		///
		///Konstruktor
		///
		PhysicalManager();

		///
		///Destruktor wirtualny
		///
		virtual ~PhysicalManager();

		///
		///Wirtualna metoda - czyści obiekty z kontenera
		///
		///@param secondsPassed - upływający czas
		///
		virtual void frameStarted(float secondsPassed);
		
		///
		///Metoda tworzy obiekt klasy Physical i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Physical *createPhysical(const std::wstring & unique_id = L"");

		///
		///Metoda tworzy obiekt klasy Actor i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Actor *createActor(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Robot i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Robot *createRobot(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Enemy i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Enemy *createEnemy(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Player i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Player *createPlayer(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Bullet i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Bullet *createBullet(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Engine i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Engine *createEngine(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy FuelTank i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		FuelTank *createFuelTank(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Energy i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Energy *createEnergy(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy EnergyTank i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		EnergyTank *createEnergyTank(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Monster i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Monster *createMonster(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Flora i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Flora *createFlora(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy FuelBar i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		FuelBar *createFuelBar(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy PhysicalInfo i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		PhysicalInfo *createPhysicalInfo(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Battery i zwraca wskaźnik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Battery *createBattery(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy SolarBattery i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		SolarBattery *createSolarBattery(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Airconditioning i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Airconditioning *createAirconditioning(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy ThermalInsulation i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		ThermalInsulation *createThermalInsulation(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Ventilator i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Ventilator *createVentilator(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Ammo i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Ammo *createAmmo(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Gun i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Gun *createGun(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy WindTurbine i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		WindTurbine *createWindTurbine(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy SolarCell i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		SolarCell *createSolarCell(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy PowerStation i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		PowerStation *createPowerStation(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy WindPowerStation i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		WindPowerStation *createWindPowerStation(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy WindPowerStationMultipled i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		WindPowerStationMultipled *createWindPowerStationMultipled(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy RelayStation i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		RelayStation *createRelayStation(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy PowerRelayStation i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		PowerRelayStation *createPowerRelayStation(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy SlotsRate i zwraca wskaźnik na ten obiekt
		///
		///@param  uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		SlotsRate *createSlotsRate(const std::wstring & uniqueId = L"");
		
		///
		///Metoda tworzy obiekt klasy Communication i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Communication *createCommunication(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy LightingEquipment i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		LightingEquipment *createLightingEquipment(const std::wstring & uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CGround i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		CGround *createGround(const std::wstring & uniqueId = L"");

		///
		///Metoda usuwa obiekt klasy Physical z kontenera
		///
		///@param *physical - wskaźnik na obiekt klasy Physical
		///
		void destroyPhysical(Physical *physical);
	    
		///
		///Metoda usuwa obiekt klasy Physical z kontenera
		///
		///@param id_physical - stała referencja na obiekt klasy std::wstring - unikalny identyfikator obiektu
		///
		void destroyPhysical(const std::wstring & id_physical);

		///
		///Metoda usuwa wszystkie obiekty z kontenera
		///
		///@param force_destroy_instantly - flaga, czy usunąć z kontenera wszystkie obiekty
		///
		void clear(bool force_destroy_instantly = false);

		///
		///Metoda zwraca stała referencję do kontenera z nazwami wszystkich zarejestorwanych obiektów Physical
		///
		const std::map<std::wstring, Physical*> & getNamedPhysicals();

		///
		///Metoda zwraca stała referencję do kontenera z wszystkimi wskaźnikami zarejestorwanych obiektów Physical
		///
		const std::vector<Physical*> & getPhysicals();

		///
		///Metoda zwraca wskaźnik na obiekt klasy Physical z kontenera na podstawie identyfikatora
		///
		///@param &physical_id - stała referencja na obiekt klasy std::wstring
		///
		Physical *getPhysicalById(const std::wstring & physical_id);
				
		
		//metody p o m o c n i c z e

		///
		///Metoda zwraca stałą referencję na kontener, w którym są wskaźniki na obiekty klasy WindPowerStation
		////elektrownie wiatrowe
		///
		const std::vector<WindPowerStation*> & getWindPowerstations();

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void cleanup();
		

	private:
		
		//
		//Szablon metody tworzenia obiektów
		//
		template<class T> T *create(const std::wstring & uniqueId);
	    
		std::map<std::wstring, Physical*> m_named_physicals; //kontener <map> na nazwane obiekty klasy Physical
		std::vector<Physical*> m_physicals; //kontener <vector> na wskaźniki na obiekty klasy Physical
		std::vector<WindPowerStation*> m_wind_powerstation; //elektrownie wiatrowa

															//
		//Prywatna metoda sprawdzająca jaki identyfikator nadać obiektowi przy utworzeniu
		//
		//@param new_unique_id - referencja na obiekt klasy std::wstring
		//
		void checkUniqueId(std::wstring & new_unique_id);
	};
}//namespace logic
#endif//H_PHYSICAL_MANAGER_JACK
