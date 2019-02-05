//  ____________________________________
// | CEngine.h - class definition       |
// | Jack Flower - December 2012        |
// |____________________________________|
//

#ifndef H_ENGINE_JACK
#define H_ENGINE_JACK

#include "EEngineState.h"
#include "../../Logic/Actor/CActor.h"
#include "../../RTTI/RTTI.h"
#include "../EquipmentData/CEquipmentFuelTankData.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje abstrakcyjny silnik napędzajacy dowolny obiekt
	///
	class CEngine : public CActor
	{
		RTTI_DECL;
			
		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskać obiekt CEngine, należy wywołać CPhysicalManager::CreateEngine();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		CEngine(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param &CEngineCopy - obiekt klasy CEngine
		///
		CEngine(const CEngine& CEngineCopy);
				
		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		///
		virtual ~CEngine(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwę silnika
		///
		const std::string GetEngineName() const;

		///
		///Metoda ustawia typ silnika
		///
		///@param &engine_name - typ silnika stała referencja na std::string
		///
		void SetEngineName(const std::string& engine_name);

		///
		///Metoda zwraca wskaźnik na obiekt klasy CFuelTank
		///
		CFuelTank* GetFuelTank();

		///
		///Metoda ustawia wskaźnik na obiekt klasy CFuelTank
		///
		///@param *fuel_tank - wskaźnik na obiekt klasy CFuelTank
		///
		void SetFuelTank(CFuelTank* fuel_tank);

		///
		///Metoda zwraca flagę, czy obiekt posiada zbiornik paliwa
		///
		const bool GetUseFuelTank() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada zbiornik paliwa
		///
		///@param use_fueltank - flaga, czy obiekt posiada zbiornik paliwa
		///
		void SetUseFuelTank(bool use_fueltank);

		///
		///Metoda zwraca referencję na opakowanie funkcjonalności zbiornika paliwa
		///
		CEquipmentFuelTankData & getEquipmentFuelTankData();

		///
		///Metoda ustawia referencję na opakowanie funkcjonalności zbiornika paliwa
		///
		///@param & fueltank_data - referencja na obiekt klasy CEquipmentFuelTankData
		///
		void setEquipmentFuelTankData(CEquipmentFuelTankData & fueltank_data);

		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getFuelTankTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param & fuel_tank_transformation - referencja na obiekt klasy CTransformation
		///
		void setFuelTankTransformed(CTransformation & fuel_tank_transformation);

		///
		///Metoda zwraca wartość, przy której następuje komunikat informacyjny o rezerwie paliwa (procent)
		///
		const float GetPercentageReserveFuel() const;

		///
		///Metoda ustawia wartość, przy której następuje komunikat informacyjny o rezerwie paliwa
		///
		///@param percentage_reserve_fuel - procentowa wartość paliwa, przy której następuje komunikat informacyjny o rezerwie paliwa
		///
		void SetPercentageReserveFuel(float percentage_reserve_fuel);

		///
		///Metoda zwraca wartość flagi, czy obiekt może wysyłać komunikaty o braku paliwa
		///
		const bool GetFuelEmptyMessage() const;

		///
		///Metoda ustawia wartość flagi, czy obiekt może wysyłać komunikaty o braku paliwa
		///
		///@param fuel_empty_message - flaga, czy obiekt może wysyłać komunikaty o braku paliwa
		///
		void SetFuelEmptyMessage(bool fuel_empty_message);

		///
		///Metoda zwraca czas opóźnienia komunikatu o braku paliwa
		///
		const float GetTankTimeDelayed() const;

		///
		///Metoda ustawia czas opóźnienia komunikatu o braku paliwa
		///
		///@param tank_time_delayed - czas opóźnienia komunikatu o braku paliwa
		///
		void SetTankTimeDelayed(float tank_time_delayed);

		///
		///Metoda zwraca zużycie paliwa gdy obiekt się nie przemieszcza
		///
		const float GetFuelConsumption() const;

		///
		///Metoda ustawia zużycie paliwa gdy obiekt się nie przemieszcza
		///
		///@param fuel_consumption - zużycie paliwa gdy obiekt się nie przemieszcza
		///
		void SetFuelConsumption(float fuel_consumption);

		///
		///Metoda zwraca zużycie paliwa gdy obiekt się przemieszcza - związane z prędkością obiektu
		///
		const float GetFuelConsumptionMove() const;

		///
		///Metoda ustawia zużycie paliwa gdy obiekt się przemieszcza - związane z prędkością obiektu
		///
		///@param fuel_consumption_move - zużycie paliwa gdy obiekt się przemieszcza
		///
		void SetFuelConsumptionMove(float fuel_consumption_move);

		///
		///Metoda uruchamia pracę silnika
		///
		const bool GetRunEngine() const;

		///
		///Metoda ustawia pracę silnika
		///
		///@param engine_run - stan pracy silnika (start/stop)
		///
		void SetRunEngine(bool engine_run);

		///
		///Metoda zwraca częstotliwość regeneracji procesu
		///
		const float GetEngineRegenerationTime() const;

		///
		///Metoda ustawia częstotliwość regeneracji procesu
		///
		///@param engine_regeneration_time - częstotliwość regeneracji procesu
		///
		void SetEngineRegenerationTime(float engine_regeneration_time);

		///
		///Metoda zwraca prędkość wirowania łopatek silnika
		///
		const float GetEngineRotationSpeed() const;

		///
		///Metoda ustawia prędkość wirowania łopatek silnika
		///
		///@param engine_rotation_speed - prędkość wirowania łopatek silnika
		///
		void SetEngineRotationSpeed(float engine_rotation_speed);

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca stan obiektu CEngine
		///
		inline EEngineState & getEngineState() { return m_engine_state; }

		///
		///Metoda zwraca referencjcę na moduł sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logikę obiektu
		///
		///@param dt - czas
		///
		virtual void update(float dt);


	private:

		std::string				m_engine_name;				//nazwa silnika (spalinowy, elektryczny, atomowy, biologiczny...etc)
		CEquipmentFuelTankData	m_fueltank_data;			//opakowanie funkcjonalności zbiornika paliwa
		float					m_percentage_reserve_fuel;	//procentowa wartość paliwa, przy której następuje komunikat informacyjny o rezerwie paliwa (default 10% - konstruktor)
		float					m_fuel_consumption;			//zużycie paliwa gdy obiekt się nie przemieszcza (aktualizowane co sekundę)
		float					m_fuel_consumption_move;	//zużycie paliwa gdy obiekt się przemieszcza - związane z prędkością obiektu
		float					m_tank_time_delayed;		//czas opóźnienia komunikatu o braku paliwa - jako dana wejściowa dla sf::Randomizer
		bool					m_fuel_empty_message;		//flaga, czy biekt może wysyłać komunikaty o braku paliwa
		bool					m_engine_run;				//stacyjka - start/stop engine
		float					m_engine_rotation_speed;	//prędkość wirowania wirnika w silniku
		float					m_engine_regeneration_time;	//częstotliwość regeneracji procesu
		EEngineState			m_engine_state;				//wyliczenie stanów dla obiektu CEngine
		float					m_engine_timer;				//wyliczany upływający czas procesów logiki
		float					m_rotor_speed;				//wyliczana prędkość wirowania łopat wirnika silnika
		float					m_percentage_fuel;			//wyliczana procentowa zawartość paliwa w zbiorniku
		Switch					m_unit_controller;			//włącznik, sterownik, moduł zarządzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu - engine
		void updateEngineState(float dt);

		//prywatna metoda aktualizuje obiekt - fueltank (zbiornik paliwa)
		void updateFuelTank(float dt);

		//prywatna metoda aktualizuje składowe transformacji względem właściciela
		void updateFuelTankTransformation(float dt);
	};
}//namespace equipment
#endif //H_ENGINE_JACK
