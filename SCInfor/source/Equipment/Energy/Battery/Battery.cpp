//  ____________________________________
// | Battery.cpp - class implementation |
// | Jack Flower May 2014               |
// |____________________________________|
//

#include "Battery.h"
#include <iostream>

namespace equipment
{
	namespace battery
	{
		RTTI_IMPL(Battery, Actor);

		//Konstruktor domyślny chroniony
		Battery::Battery(const std::wstring& uniqueId)
		:
			Actor							(uniqueId),//konstruktor klasy bazowej
			m_battery_name					(""),
			m_capacity						(0.0f),
			m_particle_energy				(0.0f),
			m_battery_regeneration_duration	(0.0f),
			m_battery_regeneration_timer	(0.0f),
			m_unit_controller				(false),//urządzenie wyłączone - uruchamia się z opóźnieniem
			m_battery_state					(EBatteryState::BATTERY_DEFAULT),
			m_battery_charge				(0.0f),
			run_battery						(false)
		{
		}

		//Konstruktor kopiujący chroniony
		Battery::Battery(const Battery& CBatteryCopy)
		:
			Actor							(CBatteryCopy),//konstruktor kopiujący klasy bazowej
			m_battery_name					(CBatteryCopy.m_battery_name),
			m_capacity						(CBatteryCopy.m_capacity),
			m_particle_energy				(CBatteryCopy.m_particle_energy),
			m_battery_regeneration_duration (CBatteryCopy.m_battery_regeneration_duration),
			m_battery_regeneration_timer	(CBatteryCopy.m_battery_regeneration_timer),
			m_unit_controller				(CBatteryCopy.m_unit_controller),
			m_battery_state					(CBatteryCopy.m_battery_state),
			m_battery_charge				(CBatteryCopy.m_battery_charge),
			run_battery						(CBatteryCopy.run_battery)
		{
		}

		//Destruktor chroniony
		Battery::~Battery()
		{
			//Actor						not edit
			m_battery_name					= "";
			m_capacity						= 0.0f;
			m_particle_energy				= 0.0f;
			m_battery_regeneration_duration = 0.0f;
			m_battery_regeneration_timer	= 0.0f;
			//m_unit_controller				not edit
			m_battery_state					= EBatteryState::BATTERY_DEFAULT;
			m_battery_charge				= 0.0f;
			run_battery						= false;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Battery::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca nazwę baterii
		const std::string Battery::getBatteryName() const
		{
			return m_battery_name;
		}

		//Metoda ustawia nazwę baterii
		void Battery::setBatteryName(const std::string& battery_name)
		{
			m_battery_name = battery_name;
		}

		//Metoda zwraca pojemność baterii
		const float Battery::getCapacity() const
		{
			return m_capacity;
		}

		//Metoda ustawia pojemność baterii
		void Battery::setCapacity(float capacity)
		{
			m_capacity = capacity;
		}

		//Metoda zwraca fabryczną pojemność baterii
		const float Battery::getFactoryCapacity() const
		{
			return m_factory_capacity;
		}

		//Metoda ustawia fabryczną pojemność baterii
		void Battery::setFactoryCapacity(float factory_capacity)
		{
			m_factory_capacity = factory_capacity;
		}

		//Metoda zwraca cząstkę energii - ładowanie/rozładowanie
		const float Battery::getParticleEnergy() const
		{
			return m_particle_energy;
		}

		//Metoda ustawia cząstkę energii - ładowanie/rozładowanie
		void Battery::setParticleEnergy(float particle_energy)
		{
			m_particle_energy = particle_energy;
		}

		//Metoda zwraca czas procesu zużycia jednostki energii
		const float Battery::getBatteryRegenerationDuration() const
		{
			return m_battery_regeneration_duration;
		}

		//Metoda ustawia czas procesu zużycia jednostki energii
		void Battery::setBatteryRegenerationDuration(float battery_regeneration_duration)
		{
			m_battery_regeneration_duration = battery_regeneration_duration;
		}

		//Metoda zwraca referencjcę na moduł sterowania
		Switch & Battery::getUnitController()
		{
			return m_unit_controller;
		}

		//Metoda zwraca współczynnik stanu (poziomu) naładowania baterii
		const float Battery::getBatteryCharge() const
		{
			return m_battery_charge;
		}

		//Metoda ustawia współczynnik stanu (poziomu) naładowania baterii
		void Battery::setBatteryCharge(const float battery_charge)
		{
			m_battery_charge = battery_charge;
		}

		//Metoda zwraca wyliczenie stanów baterii
		const EBatteryState & Battery::getBatteryState() const
		{
			return m_battery_state;
		}

		//Metoda ustawia wyliczenie stanów baterii
		void Battery::setBatteryState(const EBatteryState & battery_state)
		{
			m_battery_state = battery_state;
		}

		//Metoda uruchamia procesy i funkcjonalność baterii
		void Battery::runBattery()
		{
			run_battery = true;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Battery::update(float dt)
		{
			//aktywacja
			if(run_battery)//przy tej fladze, następuje włączenie baterii...
				m_unit_controller.updateToRun(dt);

			//bateria się rozładowuje (proces starzenia)
			if(m_unit_controller.getState())
			{
				if(m_capacity)//jeśli bateria ma pojemność
				{
					m_battery_regeneration_timer = m_battery_regeneration_timer + dt;//kumulacja czasu
					if(m_battery_regeneration_timer >= m_battery_regeneration_duration)
					{
						m_capacity -= m_particle_energy;	//bateria się wyczerpuje
						m_battery_regeneration_timer = 0.0f;//zeruję czas
					}
				}
				//aktualizacja współczynnika stanu (poziomu) naładowania baterii
				m_battery_charge = m_capacity / m_factory_capacity;
			}
		
			//aktualizuja stanu obiektu
			updateBatteryState(dt);
		}

		//prywatna metoda aktualizuje stan obiektu
		void Battery::updateBatteryState(float dt)
		{
			if (m_capacity > m_factory_capacity * 0.25f)
				m_battery_state = EBatteryState::BATTERY_CHARGED;

			if (m_capacity > 0.0f && m_capacity <= m_factory_capacity * 0.25f)
				m_battery_state = EBatteryState::BATTERY_RESERVE;

			if (m_capacity <= 0.0f)
				m_battery_state = EBatteryState::BATTERY_DISCHARGED;
		}
	}//namespace battery
}//namespace equipment
