//  _____________________________________________
// | EngineTemplate.h - class definition         |
// | Jack Flower - December 2013                 |
// |_____________________________________________|
//

#ifndef H_ENGINE_TEMPLATE_JACK
#define H_ENGINE_TEMPLATE_JACK

#include "../../../Equipment/Engine/Engine.h"
#include "FuelTankFactory/FuelTankTemplate.h"
#include "../../../Equipment/EquipmentData/EquipmentFuelTankData.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec silnika
	///
	class EngineTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EngineTemplate();

		///
		///Destruktor
		///
		~EngineTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

		///
		///Wirtualna metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		virtual bool load(Xml & xml);

		///
		///Metoda tworzy obiekt klasy Engine
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Engine *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_engine - wskaźnik na obiekt klasy Engine
		///
		virtual void fill(Engine *p_engine);


		//metody  p o m o c n i c z e

		inline const std::string getEngineName() const
		{
			return m_templ_engine_name;
		}

		inline void setEngineName(const std::string templ_engine_name)
		{
			m_templ_engine_name = templ_engine_name;
		}

		inline const float getPercetageReserveFuel() const
		{
			return m_templ_percentage_reserve_fuel;
		}

		inline void setPercetageReserveFuel(float templ_percentage_reserve_fuel)
		{
			m_templ_percentage_reserve_fuel = templ_percentage_reserve_fuel;
		}

		inline const float getFuelConsumption() const
		{
			return m_templ_fuel_consumption;
		}

		inline void setFuelConsumption(float templ_fuel_consumption)
		{
			m_templ_fuel_consumption = templ_fuel_consumption;
		}

		inline const float getFuelConsumptionMove() const
		{
			return m_templ_fuel_consumption_move;
		}

		inline void setFuelConsumptionMove(float templ_fuel_consumption_move)
		{
			m_templ_fuel_consumption_move = templ_fuel_consumption_move;
		}

		inline const float getTankTimeDelayed() const
		{
			return m_templ_tank_time_delayed;
		}

		inline void setTankTimeDelayed(float templ_tank_time_delayed)
		{
			m_templ_tank_time_delayed = templ_tank_time_delayed;
		}

		inline const bool getFuelEmptyMessage() const
		{
			return m_templ_fuel_empty_message;
		}

		inline void setFuelEmptyMessage(bool templ_fuel_empty_message)
		{
			m_templ_fuel_empty_message = templ_fuel_empty_message;
		}

		inline const bool getEngineRun() const
		{
			return m_templ_engine_run;
		}

		inline void setEngineRun(bool templ_engine_run)
		{
			m_templ_engine_run = templ_engine_run;
		}

		inline const float getRegenarationTime() const
		{
			return m_templ_regeneration_time;
		}

		inline void setRegenarationTime(float templ_regeneration_time)
		{
			m_templ_regeneration_time = templ_regeneration_time;
		}

		inline const float getEngineRotationSpeed() const
		{
			return m_templ_engine_rotation_speed;
		}

		inline void setEngineRotationSpeed(float templ_engine_rotation_speed)
		{
			m_templ_engine_rotation_speed = templ_engine_rotation_speed;
		}

	protected:

	private:

		std::string m_templ_engine_name; //nazwa silnika (spalinowy, elektryczny, atomowy, biologiczny...etc)
		EquipmentFuelTankData	m_templ_fueltank_data; //opakowanie funkcjonalności zbiornika paliwa
		FuelTankTemplate *p_templ_fuel_tank; //wskaźnik na dane wzorca zbiornika paliwa
		float m_templ_percentage_reserve_fuel; //procentowa wartość paliwa, przy której następuje komunikat informacyjny o rezerwie paliwa (default 10% - konstruktor)
		float m_templ_fuel_consumption; //zużycie paliwa gdy obiekt się nie przemieszcza (aktualizowane co sekundę)
		float m_templ_fuel_consumption_move; //zużycie paliwa gdy obiekt się przemieszcza - związane z prędkością obiektu
		float m_templ_tank_time_delayed; //czas opóźnienia komunikatu o braku paliwa
		bool m_templ_fuel_empty_message; //flaga, czy obiekt może wysyłać komunikaty o braku paliwa
		bool m_templ_engine_run; //stacyjka (hardware (start/stop)
		float m_templ_engine_rotation_speed; //prędkość wirowania wirnika w silniku
		float m_templ_regeneration_time; //częstotliwość regeneracji procesu
	};
}//namespace factory
#endif//H_ENGINE_TEMPLATE_JACK
