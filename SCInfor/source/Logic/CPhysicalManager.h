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
	class CPhysical;
	class CActor;
	class CEnemy;
	class CPlayer;
	class CBullet;
	class CMonster;
	class CFlora;
	class CPhysicalInfo;
	namespace unit
	{
		class CRobot;
	}
	namespace powerstation
	{
		class CPowerStation;
		class CWindPowerStation;
		class CWindPowerStationMultipled;
	}
	namespace energetics
	{
		class CRelayStation;
		class CPowerRelayStation;
		class CSlotsRate;
	}
	namespace communication
	{
		class CCommunication;
	}
}

///
///Forward declaration
///
namespace equipment
{
	class Engine;
	class CFuelTank;
	class Energy;
	class EnergyTank;
	class CFuelBar;
	class CAirconditioning;
	class CThermalInsulation;
	class CVentilator;
	class CWindTurbine;
	class CSolarCell;
	class CLightingEquipment;

	namespace weapon
	{
		class CAmmo;
		class CGun;
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
		///Metoda tworzy obiekt klasy CPhysical i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CPhysical* CreatePhysical(const std::wstring& unique_id = L"");

		///
		///Metoda tworzy obiekt klasy CActor i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CActor *CreateActor(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CRobot i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CRobot *CreateRobot(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CEnemy i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CEnemy *CreateEnemy(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CPlayer i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CPlayer *CreatePlayer(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CBullet i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CBullet *CreateBullet(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy Engine i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		Engine *CreateEngine(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CFuelTank i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CFuelTank *CreateFuelTank(const std::wstring &uniqueId = L"");

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
		///Metoda tworzy obiekt klasy CMonster i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CMonster *CreateMonster(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CFlora i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CFlora *CreateFlora(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CFuelBar i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CFuelBar *CreateFuelBar(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CPhysicalInfo i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CPhysicalInfo *CreatePhysicalInfo(const std::wstring &uniqueId = L"");

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
		///Metoda tworzy obiekt klasy CAirconditioning i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CAirconditioning *CreateAirconditioning(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CThermalInsulation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CThermalInsulation *CreateThermalInsulation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CVentilator i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CVentilator *CreateVentilator(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CAmmo i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CAmmo *CreateAmmo(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CGun i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CGun *CreateGun(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CWindTurbine i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CWindTurbine *CreateWindTurbine(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CSolarCell i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CSolarCell *CreateSolarCell(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CPowerStation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CPowerStation *CreatePowerStation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CWindPowerStation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CWindPowerStation *CreateWindPowerStation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CWindPowerStationMultipled i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CWindPowerStationMultipled *CreateWindPowerStationMultipled(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CRelayStation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CRelayStation *CreateRelayStation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CPowerRelayStation i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CPowerRelayStation *CreatePowerRelayStation(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CSlotsRate i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CSlotsRate* CreateSlotsRate(const std::wstring &uniqueId = L"");
		
		///
		///Metoda tworzy obiekt klasy CCommunication i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CCommunication *CreateCommunication(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CLightingEquipment i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CLightingEquipment *CreateLightingEquipment(const std::wstring &uniqueId = L"");

		///
		///Metoda tworzy obiekt klasy CGround i zwraca wskaünik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta≥a referencja na obiekt klasy std::wstring
		///
		CGround *CreateGround(const std::wstring &uniqueId = L"");

		///
		///Metoda usuwa obiekt klasy CPhysical z kontenera
		///
		///@param *physical - wskaünik na obiekt klasy CPhysical
		///
		void DestroyPhysical(CPhysical* physical);
	    
		///
		///Metoda usuwa obiekt klasy CPhysical z kontenera
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
		///Metoda zwraca sta≥a referencjÍ do kontenera z nazwami wszystkich zarejestorwanych obiektÛw CPhysical
		///
		const std::map<std::wstring, CPhysical*>& GetNamedPhysicals();

		///
		///Metoda zwraca sta≥a referencjÍ do kontenera z wszystkimi wskaünikami zarejestorwanych obiektÛw CPhysical
		///
		const std::vector<CPhysical*>& GetPhysicals();

		///
		///Metoda zwraca wskaünik na obiekt klasy CPhysical z kontenera na podstawie identyfikatora
		///
		///@param &physical_id - sta≥a referencja na obiekt klasy std::wstring
		///
		CPhysical* GetPhysicalById(const std::wstring& physical_id);
				
		
		//metody p o m o c n i c z e

		///
		///Metoda zwraca sta≥π referencjÍ na kontener, w ktÛrym sπ wskaüniki na obiekty klasy CWindPowerStation
		////elektrownie wiatrowe
		///
		const std::vector<CWindPowerStation*>& GetWindPowerstations();

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void Cleanup();
		

	private:
		
		//
		//Szablon metody tworzenia obiektÛw
		//
		template<class T> T* Create(const std::wstring &uniqueId);
	    
		std::map<std::wstring, CPhysical*>	m_named_physicals;	//kontener <map> na nazwane obiekty klasy CPhysical
		std::vector<CPhysical*>				m_physicals;		//kontener <vector> na wskaüniki na obiekty klasy CPhysical
		std::vector<CWindPowerStation*>		m_wind_powerstation;		//elektrownie wiatrowa
		//
		//Prywatna metoda sprawdzajπca jaki identyfikator nadaÊ obiektowi przy utworzeniu
		//
		//@param &new_unique_id - referencja na obiekt klasy std::wstring
		//
		void CheckUniqueId(std::wstring& new_unique_id);
	};
}//namespace logic
#endif//H_PHYSICAL_MANAGER_JACK
