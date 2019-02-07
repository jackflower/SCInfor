//  ______________________________________________
// | CEngineTemplate.h - class definition         |
// | Jack Flower - December 2013                  |
// |______________________________________________|
//

#ifndef H_ENGINE_TEMPLATE_JACK
#define H_ENGINE_TEMPLATE_JACK

#include "../../../Equipment/Engine/Engine.h"
#include "FuelTankFactory/CFuelTankTemplate.h"
#include "../../../Equipment/EquipmentData/EquipmentFuelTankData.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec silnika
	///
	class CEngineTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEngineTemplate(void);

		///
		///Destruktor
		///
		~CEngineTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void drop();

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy Engine
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Engine* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_engine - wskaŸnik na obiekt klasy Engine
		///
		virtual void fill(Engine *p_engine);


		//metody  p o m o c n i c z e

		inline const std::string GetEngineName() const
		{
			return m_templ_engine_name;
		}

		inline void SetEngineName(const std::string templ_engine_name)
		{
			m_templ_engine_name = templ_engine_name;
		}

		inline const float GetPercetageReserveFuel() const
		{
			return m_templ_percentage_reserve_fuel;
		}

		inline void SetPercetageReserveFuel(float templ_percentage_reserve_fuel)
		{
			m_templ_percentage_reserve_fuel = templ_percentage_reserve_fuel;
		}

		inline const float GetFuelConsumption() const
		{
			return m_templ_fuel_consumption;
		}

		inline void SetFuelConsumption(float templ_fuel_consumption)
		{
			m_templ_fuel_consumption = templ_fuel_consumption;
		}

		inline const float GetFuelConsumptionMove() const
		{
			return m_templ_fuel_consumption_move;
		}

		inline void SetFuelConsumptionMove(float templ_fuel_consumption_move)
		{
			m_templ_fuel_consumption_move = templ_fuel_consumption_move;
		}

		inline const float GetTankTimeDelayed() const
		{
			return m_templ_tank_time_delayed;
		}

		inline void SetTankTimeDelayed(float templ_tank_time_delayed)
		{
			m_templ_tank_time_delayed = templ_tank_time_delayed;
		}

		inline const bool GetFuelEmptyMessage() const
		{
			return m_templ_fuel_empty_message;
		}

		inline void SetFuelEmptyMessage(bool templ_fuel_empty_message)
		{
			m_templ_fuel_empty_message = templ_fuel_empty_message;
		}

		inline const bool GetEngineRun() const
		{
			return m_templ_engine_run;
		}

		inline void SetEngineRun(bool templ_engine_run)
		{
			m_templ_engine_run = templ_engine_run;
		}

		inline const float GetRegenarationTime() const
		{
			return m_templ_regeneration_time;
		}

		inline void SetRegenarationTime(float templ_regeneration_time)
		{
			m_templ_regeneration_time = templ_regeneration_time;
		}

		inline const float GetEngineRotationSpeed() const
		{
			return m_templ_engine_rotation_speed;
		}

		inline void SetEngineRotationSpeed(float templ_engine_rotation_speed)
		{
			m_templ_engine_rotation_speed = templ_engine_rotation_speed;
		}

	protected:

	private:

		std::string				m_templ_engine_name;				//nazwa silnika (spalinowy, elektryczny, atomowy, biologiczny...etc)
		EquipmentFuelTankData	m_templ_fueltank_data;				//opakowanie funkcjonalnoœci zbiornika paliwa
		CFuelTankTemplate*		p_templ_fuel_tank;					//wskaŸnik na dane wzorca zbiornika paliwa
		float					m_templ_percentage_reserve_fuel;	//procentowa wartoœæ paliwa, przy której nastêpuje komunikat informacyjny o rezerwie paliwa (default 10% - konstruktor)
		float					m_templ_fuel_consumption;			//zu¿ycie paliwa gdy obiekt siê nie przemieszcza (aktualizowane co sekundê)
		float					m_templ_fuel_consumption_move;		//zu¿ycie paliwa gdy obiekt siê przemieszcza - zwi¹zane z prêdkoœci¹ obiektu
		float					m_templ_tank_time_delayed;			//czas opóŸnienia komunikatu o braku paliwa
		bool					m_templ_fuel_empty_message;			//flaga, czy obiekt mo¿e wysy³aæ komunikaty o braku paliwa
		bool					m_templ_engine_run;					//stacyjka (hardware (start/stop)
		float					m_templ_engine_rotation_speed;		//prêdkoœæ wirowania wirnika w silniku
		float					m_templ_regeneration_time;			//czêstotliwoœæ regeneracji procesu
	};
}//namespace factory
#endif//H_ENGINE_TEMPLATE_JACK
