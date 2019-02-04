//  _____________________________________
// | CBattery.cpp - class implementation |
// | Jack Flower May 2014                |
// |_____________________________________|
//

#include "CBattery.h"
#include <iostream>

namespace equipment
{
	namespace battery
	{
		RTTI_IMPL(CBattery, CActor);

		//Konstruktor domy�lny chroniony
		CBattery::CBattery(const std::wstring& uniqueId)
		:
			CActor							(uniqueId),//konstruktor klasy bazowej
			m_battery_name					(""),
			m_capacity						(0.0f),
			m_particle_energy				(0.0f),
			m_battery_regeneration_duration	(0.0f),
			m_battery_regeneration_timer	(0.0f),
			m_unit_controller				(false),//urz�dzenie wy��czone - uruchamia si� z op�nieniem
			m_battery_state					(EBatteryState::BATTERY_DEFAULT),
			m_battery_charge				(0.0f),
			run_battery						(false)
		{
		}

		//Konstruktor kopiuj�cy chroniony
		CBattery::CBattery(const CBattery& CBatteryCopy)
		:
			CActor							(CBatteryCopy),//konstruktor kopiuj�cy klasy bazowej
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
		CBattery::~CBattery()
		{
			//CActor						not edit
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
		const std::string CBattery::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca nazw� baterii
		const std::string CBattery::GetBatteryName() const
		{
			return m_battery_name;
		}

		//Metoda ustawia nazw� baterii
		const void CBattery::SetBatteryName(const std::string& battery_name)
		{
			m_battery_name = battery_name;
		}

		//Metoda zwraca pojemno�� baterii
		const float CBattery::getCapacity() const
		{
			return m_capacity;
		}

		//Metoda ustawia pojemno�� baterii
		void CBattery::setCapacity(float capacity)
		{
			m_capacity = capacity;
		}

		//Metoda zwraca fabryczn� pojemno�� baterii
		const float CBattery::getFactoryCapacity() const
		{
			return m_factory_capacity;
		}

		//Metoda ustawia fabryczn� pojemno�� baterii
		void CBattery::setFactoryCapacity(float factory_capacity)
		{
			m_factory_capacity = factory_capacity;
		}

		//Metoda zwraca cz�stk� energii - �adowanie/roz�adowanie
		const float CBattery::getParticleEnergy() const
		{
			return m_particle_energy;
		}

		//Metoda ustawia cz�stk� energii - �adowanie/roz�adowanie
		void CBattery::setParticleEnergy(float particle_energy)
		{
			m_particle_energy = particle_energy;
		}

		//Metoda zwraca czas procesu zu�ycia jednostki energii
		const float CBattery::getBatteryRegenerationDuration() const
		{
			return m_battery_regeneration_duration;
		}

		//Metoda ustawia czas procesu zu�ycia jednostki energii
		void CBattery::setBatteryRegenerationDuration(float battery_regeneration_duration)
		{
			m_battery_regeneration_duration = battery_regeneration_duration;
		}

		//Metoda zwraca referencjc� na modu� sterowania
		CSwitch & CBattery::getUnitController()
		{
			return m_unit_controller;
		}

		//Metoda zwraca wsp�czynnik stanu (poziomu) na�adowania baterii
		const float CBattery::getBatteryCharge() const
		{
			return m_battery_charge;
		}

		//Metoda ustawia wsp�czynnik stanu (poziomu) na�adowania baterii
		void CBattery::setBatteryCharge(const float battery_charge)
		{
			m_battery_charge = battery_charge;
		}

		//Metoda zwraca wyliczenie stan�w baterii
		const EBatteryState & CBattery::getBatteryState() const
		{
			return m_battery_state;
		}

		//Metoda ustawia wyliczenie stan�w baterii
		void CBattery::setBatteryState(const EBatteryState & battery_state)
		{
			m_battery_state = battery_state;
		}

		//Metoda uruchamia procesy i funkcjonalno�� baterii
		void CBattery::runBattery()
		{
			run_battery = true;
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CBattery::Update(float dt)
		{
			//aktywacja
			if(run_battery)//przy tej fladze, nast�puje w��czenie baterii...
				m_unit_controller.updateToRun(dt);

			//bateria si� roz�adowuje (proces starzenia)
			if(m_unit_controller.getState())
			{
				if(m_capacity)//je�li bateria ma pojemno��
				{
					m_battery_regeneration_timer = m_battery_regeneration_timer + dt;//kumulacja czasu
					if(m_battery_regeneration_timer >= m_battery_regeneration_duration)
					{
						m_capacity -= m_particle_energy;	//bateria si� wyczerpuje
						m_battery_regeneration_timer = 0.0f;//zeruj� czas
					}
				}
				//aktualizacja wsp�czynnika stanu (poziomu) na�adowania baterii
				m_battery_charge = m_capacity / m_factory_capacity;
			}
		
			//aktualizuja stanu obiektu
			updateBatteryState(dt);
		}

		//prywatna metoda aktualizuje stan obiektu
		void CBattery::updateBatteryState(float dt)
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
