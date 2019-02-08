//  ___________________________________
// | Engine.cpp - class implementation |
// | Jack Flower - December 2012       |
// |___________________________________|
//

#include "Engine.h"
#include "../../Logic/CPhysicalManager.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Utilities/Utilities/Utilities.h"

using namespace rendering::drawable;
using namespace rendering::animation;
using namespace rendering::displayable;

namespace equipment
{
	RTTI_IMPL(Engine, Actor)

	//Chroniony konstruktor domyślny
	Engine::Engine(const std::wstring & uniqueId)
	:
		Actor(uniqueId),//konstruktor klasy bazowej
		m_engine_name(),
		m_fueltank_data(),
		m_percentage_reserve_fuel(0.1f),
		m_fuel_consumption(0.0f),
		m_fuel_consumption_move(0.0f),
		m_tank_time_delayed(0.0f),
		m_fuel_empty_message(false),
		m_engine_run(false),
		m_engine_rotation_speed(0.0f),
		m_engine_regeneration_time(0.0f),
		m_engine_state(ENGINE_DEFAULT),
		m_engine_timer(0.0f),
		m_rotor_speed(0.0f),
		m_percentage_fuel(0.0f),
		m_unit_controller(true)//urządzenie włączone
	{
		SetZIndexBody(Z_PHYSICAL_ENGINE_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_ENGINE_BODY);
		SetZIndexHead(Z_PHYSICAL_ENGINE_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_SHADOW_ENGINE_HEAD);
	}

	//Chroniony konstruktor kopiujący
	Engine::Engine(const Engine & EngineCopy)
	:
		Actor(EngineCopy),//konstruktor kopiujący klasy bazowej
		m_engine_name(EngineCopy.m_engine_name),
		m_fueltank_data(EngineCopy.m_fueltank_data),
		m_percentage_reserve_fuel(EngineCopy.m_percentage_reserve_fuel),
		m_fuel_consumption(EngineCopy.m_fuel_consumption),
		m_fuel_consumption_move(EngineCopy.m_fuel_consumption_move),
		m_tank_time_delayed(EngineCopy.m_tank_time_delayed),
		m_fuel_empty_message(EngineCopy.m_fuel_empty_message),
		m_engine_run(EngineCopy.m_engine_run),
		m_engine_regeneration_time(EngineCopy.m_engine_regeneration_time),
		m_engine_rotation_speed(EngineCopy.m_engine_rotation_speed),
		m_engine_state(EngineCopy.m_engine_state),
		m_engine_timer(EngineCopy.m_engine_timer),
		m_rotor_speed(EngineCopy.m_rotor_speed),
		m_percentage_fuel(EngineCopy.m_percentage_fuel),
		m_unit_controller(EngineCopy.m_unit_controller)
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
	Engine::~Engine(void)
	{
		//Actor
		m_engine_name = "";
		//m_fueltank_data
		m_percentage_reserve_fuel = 0.0f;
		m_fuel_consumption = 0.0f;
		m_fuel_consumption_move = 0.0f;
		m_tank_time_delayed = 0.0f;
		m_fuel_empty_message = false;
		m_engine_run = false;
		m_engine_regeneration_time = 0.0f;
		m_engine_rotation_speed = 0.0f;
		m_engine_state = ENGINE_DEFAULT;
		m_engine_timer = 0.0f;
		m_rotor_speed = 0.0f;
		m_percentage_fuel = 0.0f;
		//m_unit_controller
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Engine::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca typ silnika
	const std::string Engine::getEngineName() const
	{
		return m_engine_name;
	}

	//Metoda ustawia typ silnika
	void Engine::setEngineName(const std::string& engine_name)
	{
		m_engine_name = engine_name;
	}

	//Metoda zwraca wskaźnik na obiekt klasy FuelTank
	FuelTank* Engine::getFuelTank()
	{
		return m_fueltank_data.getFuelTank();
	}

	//Metoda ustawia wskaźnik na obiekt klasy FuelTank
	void Engine::setFuelTank(FuelTank* fuel_tank)
	{
		m_fueltank_data.setFuelTank(fuel_tank);
	}

	//Metoda zwraca flagę, czy obiekt posiada zbiornik paliwa
	const bool Engine::getUseFuelTank() const
	{
		return m_fueltank_data.getUseEquipment();
	}

	//Metoda ustawia flagę, czy obiekt posiada zbiornik paliwa
	void Engine::setUseFuelTank(bool use_fueltank)
	{
		m_fueltank_data.setUseEquipment(use_fueltank);
	}

	//Metoda zwraca referencję na opakowanie funkcjonalności zbiornika paliwa
	EquipmentFuelTankData & Engine::getEquipmentFuelTankData()
	{
		return m_fueltank_data;
	}

	//Metoda ustawia referencję na opakowanie funkcjonalności zbiornika paliwa
	void Engine::setEquipmentFuelTankData(EquipmentFuelTankData & fueltank_data)
	{
		m_fueltank_data = fueltank_data;
	}

	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & Engine::getFuelTankTransformed()
	{
		return m_fueltank_data.getTransformed();
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void Engine::setFuelTankTransformed(CTransformation & fuel_tank_transformation)
	{
		m_fueltank_data.setTransformed(fuel_tank_transformation);
	}

	//Metoda zwraca wartość, przy której następuje komunikat informacyjny o rezerwie paliwa (procent)
	const float Engine::getPercentageReserveFuel() const
	{
		return m_percentage_reserve_fuel;
	}

	//Metoda ustawia wartość, przy której następuje komunikat informacyjny o rezerwie paliwa
	void Engine::setPercentageReserveFuel(float percentage_reserve_fuel)
	{
		m_percentage_reserve_fuel = percentage_reserve_fuel;
	}

	//Metoda zwraca wartość flagi, czy obiekt może wysyłać komunikaty o braku paliwa
	const bool Engine::getFuelEmptyMessage() const
	{
		return m_fuel_empty_message;
	}

	//Metoda ustawia wartość flagi, czy obiekt może wysyłać komunikaty o braku paliwa
	void Engine::setFuelEmptyMessage(bool fuel_empty_message)
	{
		m_fuel_empty_message = fuel_empty_message;
	}

	//Metoda zwraca czas opóźnienia komunikatu o braku paliwa
	const float Engine::getTankTimeDelayed() const
	{
		return m_tank_time_delayed;
	}

	//Metoda ustawia czas opóźnienia komunikatu o braku paliwa
	void Engine::setTankTimeDelayed(float tank_time_delayed)
	{
		m_tank_time_delayed = tank_time_delayed;
	}

	//Metoda zwraca zużycie paliwa gdy obiekt się nie przemieszcza
	const float Engine::getFuelConsumption() const
	{
		return m_fuel_consumption;
	}

	//Metoda ustawia zużycie paliwa gdy obiekt się nie przemieszcza
	void Engine::setFuelConsumption(float fuel_consumption)
	{
		m_fuel_consumption = fuel_consumption;
	}

	//Metoda zwraca zużycie paliwa gdy obiekt się przemieszcza - związane z prędkością obiektu
	const float Engine::getFuelConsumptionMove() const
	{
		return m_fuel_consumption_move;
	}

	//Metoda ustawia zużycie paliwa gdy obiekt się przemieszcza - związane z prędkością obiektu
	void Engine::setFuelConsumptionMove(float fuel_consumption_move)
	{
		m_fuel_consumption_move = fuel_consumption_move;
	}

	//Metoda uruchamia pracę silnika
	const bool Engine::getRunEngine() const
	{
		return m_engine_run;
	}

	//Metoda ustawia pracę silnika
	void Engine::setRunEngine(bool engine_run)
	{
		m_engine_run = engine_run;
	}

	//Metoda zwraca częstotliwość regeneracji procesu
	const float Engine::getEngineRegenerationTime() const
	{
		return m_engine_regeneration_time;
	}

	//Metoda ustawia częstotliwość regeneracji procesu
	void Engine::setEngineRegenerationTime(float engine_regeneration_time)
	{
		m_engine_regeneration_time = engine_regeneration_time;
	}

	//Metoda zwraca prędkość wirowania łopatek silnika
	const float Engine::getEngineRotationSpeed() const
	{
		return m_engine_rotation_speed;
	}

	//Metoda ustawia prędkość wirowania łopatek silnika
	void Engine::setEngineRotationSpeed(float engine_rotation_speed)
	{
		m_engine_rotation_speed = engine_rotation_speed;
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
	void Engine::updateAnimations(float dt)
	{
		switch(m_engine_state)
		{
		case EEngineState::ENGINE_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadDefaultAnim());
			}
			break;
		}
		case EEngineState::ENGINE_START:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyStartAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadStartAnim());
			}
			break;
		}
		case EEngineState::ENGINE_STOP:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyStopAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadStopAnim());
			}
			break;
		}
		case EEngineState::ENGINE_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyDamageAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadDamageAnim());
			}
			break;
		}
		case EEngineState::ENGINE_DEATH:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyDeathAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadDeathAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda zwraca referencjcę na moduł sterowania
	Switch & Engine::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	void Engine::update(float dt)
	{
		CPhysical::UpdateShadow(dt);//aktualizacja shadow engine

		updateFuelTankTransformation(dt);

		if(m_unit_controller.getState())
		{
			m_engine_timer += dt;	//kumulacja upływającego czasu

			if(m_engine_run)//jeśli silnik pracuje, łopatki wirnika się obracają
				RotateHead(m_rotor_speed * dt);
			
			//engine - aktualizacja paliwa
			if(m_fueltank_data.getFuelTank())
			{
				//aktualizacja stanu paliwa ma miejsce jeśli jest paliwo oraz silnik jest włączony
				if (m_fueltank_data.getFuelTank()->getFuel() && m_engine_run)
				{
					if (m_engine_timer >= m_engine_regeneration_time)//jeśli upłynął skumulowany czas
					{
						if(m_fueltank_data.getFuelTank()->getFuel())//jeśli jest paliwo - zużywamy je
							m_fueltank_data.getFuelTank()->setFuel(m_fueltank_data.getFuelTank()->getFuel() - m_fuel_consumption);
						m_engine_timer = 0.0f;//resetujemy czas procesu
					}
					//obliczamy procentową zawartość paliwa w zbiorniku
					if(m_fueltank_data.getFuelTank()->getFuelTankCapacity())
						m_percentage_fuel = m_fueltank_data.getFuelTank()->getFuel()/ m_fueltank_data.getFuelTank()->getFuelTankCapacity();
					//aktualizacja prędkości wirowania łopatek wirnika w zależności od procentowej ilości paliwa
					m_rotor_speed = m_engine_rotation_speed * m_percentage_fuel;
				}

				//brak paliwa - silnik stop
				if(!m_fueltank_data.getFuelTank()->getFuel())
				{
					m_engine_run = false;
					m_rotor_speed = 0.0f;
				}

				//aktualizacja paliwa - jeśli jest paliwo
				if(m_fueltank_data.getFuelTank())
					updateFuelTank(dt);
			}

			updateEngineState(dt);	//aktualizuja stanu obiektu
			updateAnimations(dt);	//aktualizacja animacji (stany engine)
		}
	}

	//implementacja metod private:

	//Metoda aktualizuje stan obiektu
	void Engine::updateEngineState(float dt)
	{
		//to ulegnie zmianie
		//tymczasowa logika (docelowo energia, paliwo, etc...)
		if(m_engine_run)
			m_engine_state = EEngineState::ENGINE_START;
		else
			m_engine_state = EEngineState::ENGINE_STOP;
	}

	//prywatna metoda aktualizuje obiekt - fueltank (zbiornik paliwa)
	void Engine::updateFuelTank(float dt)
	{
		if (m_fueltank_data.getFuelTank())
		{
			//jest wystarczająca ilość paliwa
			if(m_fueltank_data.getFuelTank()->getFuel() > m_fueltank_data.getFuelTank()->getFuelTankCapacity() * m_percentage_reserve_fuel)
				m_fueltank_data.getFuelTank()->getFuelTankState() = EFuelTankState::FUELTANK_DEFAULT;

			//rezerwa paliwa
			if(m_fueltank_data.getFuelTank()->getFuel() <= m_fueltank_data.getFuelTank()->getFuelTankCapacity() * m_percentage_reserve_fuel)
				m_fueltank_data.getFuelTank()->getFuelTankState() = EFuelTankState::FUELTANK_RESERVE;

			//brak paliwa
			if(m_fueltank_data.getFuelTank()->getFuel() <= 0.f)
				m_fueltank_data.getFuelTank()->getFuelTankState() = EFuelTankState::FUELTANK_EMPTY;
		}
	}

	//prywatna metoda aktualizuje składowe transformacji względem właściciela
	void Engine::updateFuelTankTransformation(float dt)
	{
		m_fueltank_data.getTransformed().Transform(this, m_fueltank_data.getFuelTank());
	}
}//namespace equipment
