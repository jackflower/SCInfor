//  ___________________________________
// | Energy.cpp - class implementation |
// | Jack Flower February 2014         |
// |___________________________________|
//

#include "Energy.h"
#include "../../Logic/CPhysicalManager.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Utilities/Utilities/Utilities.h"
#include "../../Weather/CWeather.h"

using namespace weather;

namespace equipment
{

	RTTI_IMPL(Energy, CActor);

	//Konstruktor
	Energy::Energy(const std::wstring & uniqueId)
	:
		CActor(uniqueId),//konstruktor klasy bazowej
		m_energy_name(),
		m_energytank_data(),
		m_percentage_reserve_energy(0.1f),
		m_energy_time_delayed(0.0f),
		m_energy_empty_message(false),
		m_energy_regeneration(0.0f),
		m_energy_regeneration_time(0.0f),
		m_energy_timer(0.0f),
		m_energy_percentage_energy(0.0f),
		m_energy_rotor_speed(0.0f),
		m_energy_rotation_speed(750.0f),
		m_energy_state(ENERGY_DEFAULT),
		m_battery_data(),
		m_critical_duration(0.0f),
		m_critical_timer(0.0f),
		m_damage_duration(0.0f),
		m_damage_timer(0.0f),
		m_owner_death_candidate(false),
		m_unit_controller(false)//urządzenie wyłączone - uruchamia się z opóźnieniem
	{
		//inverse - docelowo jakaś metoda...
		SetZIndexBody(Z_PHYSICAL_ENERGY_HEAD);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_ENERGY_HEAD);
		SetZIndexHead(Z_PHYSICAL_ENERGY_BODY);
		SetZIndexShadowHead(Z_PHYSICAL_ENERGY_BODY);
	}

	//Konstruktor kopiujący
	Energy::Energy(const Energy & EnergyCopy)
	:
		CActor(EnergyCopy),//konstruktor kopiujący klasy bazowej
		m_energy_name(EnergyCopy.m_energy_name),
		m_energytank_data(EnergyCopy.m_energytank_data),
		m_percentage_reserve_energy(EnergyCopy.m_percentage_reserve_energy),
		m_energy_time_delayed(EnergyCopy.m_energy_time_delayed),
		m_energy_empty_message(EnergyCopy.m_energy_empty_message),
		m_energy_regeneration(EnergyCopy.m_energy_regeneration),
		m_energy_regeneration_time(EnergyCopy.m_energy_regeneration_time),
		m_energy_timer(EnergyCopy.m_energy_timer),
		m_energy_percentage_energy(EnergyCopy.m_energy_percentage_energy),
		m_energy_rotor_speed(EnergyCopy.m_energy_rotor_speed),
		m_energy_rotation_speed(EnergyCopy.m_energy_rotation_speed),
		m_energy_state(EnergyCopy.m_energy_state),
		m_battery_data(EnergyCopy.m_battery_data),
		m_critical_duration(EnergyCopy.m_critical_duration),
		m_critical_timer(EnergyCopy.m_critical_timer),
		m_damage_duration(EnergyCopy.m_damage_duration),
		m_damage_timer(EnergyCopy.m_damage_timer),
		m_owner_death_candidate(EnergyCopy.m_owner_death_candidate),
		m_unit_controller(EnergyCopy.m_unit_controller)
	{
	}

	//Destruktor
	Energy::~Energy(void)
	{
		//CActor
		m_energy_name = "";
		//m_energytank_data
		m_percentage_reserve_energy = 0.0f;
		m_energy_time_delayed = 0.0f;
		m_energy_empty_message = false;
		m_energy_regeneration = 0.0f;
		m_energy_timer = 0.0f;
		m_energy_percentage_energy = 0.0f;
		m_energy_rotor_speed = 0.0f;
		m_energy_rotation_speed = 0.0f;
		m_energy_state = ENERGY_DEFAULT;
		//m_battery_data
		m_critical_duration = 0.0f;
		m_critical_timer = 0.0f;
		m_damage_duration = 0.0f;
		m_damage_timer = 0.0f;
		m_owner_death_candidate = false;
		//m_unit_controller
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Energy::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwę akumulatora energii
	const std::string Energy::getEnergyName() const
	{
		return m_energy_name;
	}

	//Metoda ustawia nazwę akumulatora energii
	void Energy::setEnergyName(const std::string & energy_name)
	{
		m_energy_name = energy_name;
	}

	//Metoda zwraca wartość, przy której następuje komunikat informacyjny o niskim poziomie energii
	const float Energy::getPercentageReserveEnergy() const
	{
		return m_percentage_reserve_energy;
	}

	//Metoda ustawia wartość, przy której następuje komunikat informacyjny o niskim poziomie energii
	void Energy::setPercentageReserveEnergy(float percentage_reserve_energy)
	{
		m_percentage_reserve_energy = percentage_reserve_energy;
	}

	//Metoda zwraca wartość flagi, czy obiekt może wysyłać komunikaty o braku energii
	const bool Energy::getEnergyEmptyMessage() const
	{
		return m_energy_empty_message;
	}

	//Metoda ustawia wartość flagi, czy obiekt może wysyłać komunikaty o braku energii
	void Energy::setEnergyEmptyMessage(bool energy_empty_message)
	{
		m_energy_empty_message = energy_empty_message;
	}

	//Metoda zwraca czas opóźnienia komunikatu o braku energii
	const float Energy::getEnergyTimeDelayed() const
	{
		return m_energy_time_delayed;
	}

	//Metoda ustawia czas opóźnienia komunikatu o braku energii
	void Energy::setEnergyTimeDelayed(float energy_time_delayed)
	{
		m_energy_time_delayed = energy_time_delayed;
	}

	//Metoda zwraca wartość energii dla procesu jej regeneracji
	const float Energy::getEnergyRegeneration() const
	{
		return m_energy_regeneration;
	}

	//Metoda ustawia wartość energii dla procesu jej regeneracji
	void Energy::setEnergyRegeneration(float energy_regeneration)
	{
		m_energy_regeneration = energy_regeneration;
	}

	//Metoda zwraca częstotliwość regeneracji procesu
	const float Energy::getEnergyRegenerationTime() const
	{
		return m_energy_regeneration_time;
	}

	//Metoda ustawia częstotliwość regeneracji procesu
	void Energy::setEnergyRegenerationTime(float energy_regeneration_time)
	{
		m_energy_regeneration_time = energy_regeneration_time;
	}

	//Metoda zwraca prędkość wirowania wskaźnika energii w akumulatorze
	const float Energy::getEnergyRotationSpeed() const
	{
		return m_energy_rotation_speed;
	}

	//Metoda ustawia prędkość wirowania wskaźnika energii w akumulatorze
	void Energy::setEnergyRotationSpeed(float energy_rotation_speed)
	{
		m_energy_rotation_speed = energy_rotation_speed;
	}

	//Metoda zwraca wskaźnik na obiekt klasy EnergyTank
	EnergyTank * Energy::getEnergyTank()
	{
		return m_energytank_data.getEnergyTank();
	}

	//Metoda ustawia wskaźnik na obiekt klasy EnergyTank
	void Energy::setEnergyTank(EnergyTank * energy_tank)
	{
		m_energytank_data.setEnergyTank(energy_tank);
	}

	//Metoda zwraca flagę, czy obiekt posiada akumulator energii
	const bool Energy::getUseEnergyTank() const
	{
		return m_energytank_data.getUseEquipment();
	}

	//Metoda ustawia flagę, czy obiekt posiada akumulator energii
	void Energy::setUseEnergyTank(bool use_energytank)
	{
		m_energytank_data.setUseEquipment(use_energytank);
	}

	//Metoda zwraca referencję na opakowanie funkcjonalności akumulatora
	CEquipmentEnergyTankData & Energy::getEquipmentEnergyTankData()
	{
		return m_energytank_data;
	}

	//Metoda ustawia referencję na opakowanie funkcjonalności akumulatora
	void Energy::setEquipmentEnergyTankData(CEquipmentEnergyTankData & energytank_data)
	{
		m_energytank_data = energytank_data;
	}

	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & Energy::getEnergyTankTransformed()
	{
		return m_energytank_data.getTransformed();
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void Energy::setEnergyTankTransformed(CTransformation & energytank_transformation)
	{
		m_energytank_data.setTransformed(energytank_transformation);
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
	void Energy::updateAnimations(float dt)
	{
		switch(m_energy_state)
		{
		case ENERGY_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetEnergyHeadDefaultAnim());
			}
			break;
		}
		case ENERGY_RESERVE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyBodyReserveAnim());
				SetAnimationHead(p_anim_set->GetEnergyHeadReserveAnim());
			}
			break;
		}
		case ENERGY_EMPTY:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyBodyEmptyAnim());
				SetAnimationHead(p_anim_set->GetEnergyHeadEmptyAnim());
			}
			break;
		}
		case ENERGY_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyBodyDamageAnim());
				SetAnimationHead(p_anim_set->GetEnergyHeadDamageAnim());
			}
			break;
		}
		case ENERGY_DEATH:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyBodyDeathAnim());
				SetAnimationHead(p_anim_set->GetEnergyHeadDeathAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda zwraca wskaźnik na obiekt klasy Battery - bateria
	Battery * Energy::getBattery()
	{
		return m_battery_data.getBattery();
	}

	//Metoda ustawia wskaźnik na obiekt klasy Battery - bateria
	void Energy::setBattery(Battery *battery)
	{
		m_battery_data.setBattery(battery);
	}

	//Metoda zwraca flagę, czy obiekt posiada baterię
	const bool Energy::getUseBattery() const
	{
		return m_battery_data.getUseEquipment();
	}

	//Metoda ustawia flagę, czy obiekt posiada baterię
	void Energy::setUseBattery(bool use_battery)
	{
		m_battery_data.setUseEquipment(use_battery);
	}

	//Metoda zwraca czas trwania stanu krytycznego
	const float Energy::getCriticalDuration() const
	{
		return m_critical_duration;
	}

	//Metoda ustawia czas trwania stanu krytycznego
	void Energy::setCriticalDuration(float critical_duration)
	{
		m_critical_duration = critical_duration;
	}

	//Metoda zwraca czas trwania stanu uszkodzenia
	const float Energy::getDamageDuration() const
	{
		return m_damage_duration;
	}

	//Metoda ustawia czas trwania stanu uszkodzenia
	void Energy::setDamageDuration(float damage_duration)
	{
		m_damage_duration = damage_duration;
	}

	//Metoda zwraca referencjcę na moduł sterowania
	Switch & Energy::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	void Energy::update(float dt)
	{
		CPhysical::UpdateShadow(dt);	//aktualizacja shadow engine

		updateEnergyTankTransformation(dt);

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//jeśli urządzenie jest włączone
		if(m_unit_controller.getState())
		{
			m_energy_timer += dt; //odmiarzam czas

			//należy ustalić rotację (prędkość i warunki)
			if(m_energytank_data.getEnergyTank())
			{
				//obliczamy procentową zawartość energii w akumulatorze
				if(m_energytank_data.getEnergyTank()->getEnergyTankCapacity())
					m_energy_percentage_energy = m_energytank_data.getEnergyTank()->getEnergy()/ m_energytank_data.getEnergyTank()->getEnergyTankCapacity();
				//aktualizacja prędkości wirowania łopatek wirnika w zależności od procentowej ilości energii akumulatora
				m_energy_rotor_speed = m_energy_rotation_speed * m_energy_percentage_energy;

				//prędkość rotacji wirnika alternatora zależy od energii akumulatora i stanu obiektu
				if(m_energytank_data.getEnergyTank()->GetEnergy() && m_energy_state != ENERGY_DEATH)
					RotateHead(m_energy_rotor_speed * dt);
				
				//regeneracja - energii w akumulatorze jest mniej niż wynosi pojemność akumulatora
				if(m_energytank_data.getEnergyTank()->getEnergy() < m_energytank_data.getEnergyTank()->getEnergyTankCapacity())
				{
					if(m_energy_timer >= m_energy_regeneration_time)//jeśli upłynął jakiś czas
					{
						//regenerujemy energię
						m_energytank_data.getEnergyTank()->setEnergy(m_energytank_data.getEnergyTank()->getEnergy() + (m_energy_regeneration * gWeather.getSolarEnergyFactor()));
						m_energy_timer = 0.0f;//zerujemy czas
					}
				}

				//prędkość rotacji wirnika - moduł energii uszkodony - zasilanie bateryjne
				if(m_energy_state == ENERGY_DAMAGE)
					RotateHead(- m_energy_rotation_speed * 0.5f * dt);

				//prędkość rotacji wirnika - moduł energii zniszczony
				if(m_energy_state == ENERGY_DEATH)
					RotateHead(- m_energy_rotation_speed * 0.25f * dt);
			}

			//aktualizacja energii - jeśli jest energia
			if(m_energytank_data.getEnergyTank())
				updateEnergyTank(dt);

			updateEnergyState(dt);	//aktualizuja stanu obiektu
			updateAnimations(dt);	//aktualizacja animacji (stany energy)
		}
	}

	//implementacja metod private:

	//Metoda aktualizuje stan obiektu
	void Energy::updateEnergyState(float dt)
	{
		if(m_energytank_data.getEnergyTank() && m_energy_state != ENERGY_DAMAGE && m_energy_state != ENERGY_DEATH)
		{
			//jest wystarczająca ilość energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->getEnergy() > m_energytank_data.getEnergyTank()->getEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energy_state = ENERGY_DEFAULT;

			//rezerwa energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->getEnergy() <= m_energytank_data.getEnergyTank()->getEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energy_state = ENERGY_RESERVE;

			//brak energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->getEnergy() <= 0.f)
				m_energy_state = ENERGY_EMPTY;

			//brak energii w akumulatorze trwa jakiś czas - stan krytyczny
			if(m_energy_state == ENERGY_EMPTY)
			{
				//czekam jakiś czas, gdy akumulator jest rozładowany
				m_critical_timer += dt;
				if(m_critical_timer >= m_critical_duration)
				{
					m_energy_state = ENERGY_DAMAGE;		//ustawiam moduł energii - uszkodzony
					m_critical_timer = 0.0f;
				}
			}
		}

		//wykryto uszkodzenie - sprawdzam możliwość zasilania z baterii
		if(m_energy_state == ENERGY_DAMAGE)
		{
			//czekam jakiś czas - akumulator jest uszkodzony
			m_damage_timer += dt;
			if(m_damage_timer >= m_damage_duration)
			{
				m_energy_state = ENERGY_DEATH;				//moduł energii zniszczony
				m_battery_data.getBattery()->runBattery();	//przełączam się na zasilanie bateryjne
				m_damage_timer = 0.0f;
			}
		}

		//bateria jest zainicjowana, a moduł energii przestał działać/istnieć
		if(m_battery_data.getBattery() && m_energy_state == ENERGY_DEATH)
		{
			//jeśli moduł energii posiada baterię
			if(m_battery_data.getBattery())
				//bateria się wyczerpała
				if (m_battery_data.getBattery()->getCapacity() <= 0)
				{
					m_energy_rotation_speed = 0.0f;	//wirnik się zatrzymuje...
					m_owner_death_candidate = true;	//informacja dla właściela tego obiektu o potencjalnym
				}
		}
	}

	//prywatna metoda aktualizuje obiekt - energytank - transformation and logic
	void Energy::updateEnergyTank(float dt)
	{
		if (m_energytank_data.getEnergyTank())
		{
			//jest wystarczająca ilość energii
			if(m_energytank_data.getEnergyTank()->getEnergy() > m_energytank_data.getEnergyTank()->getEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energytank_data.getEnergyTank()->getEnergyTankState() = ENERGYTANK_DEFAULT;

			//rezerwa energii
			if(m_energytank_data.getEnergyTank()->getEnergy() <= m_energytank_data.getEnergyTank()->getEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energytank_data.getEnergyTank()->getEnergyTankState() = ENERGYTANK_RESERVE;

			//brak energii
			if(m_energytank_data.getEnergyTank()->getEnergy() <= 0.f)
				m_energytank_data.getEnergyTank()->getEnergyTankState() = ENERGYTANK_EMPTY;
		}
	}

	//prywatna metoda aktualizuje składowe transformacji względem właściciela
	void Energy::updateEnergyTankTransformation(float dt)
	{
		//m_energytank_transformation.Transform(this, p_energy_tank);
		m_energytank_data.Transform(this, m_energytank_data.getEnergyTank());
	}
}//namespace equipment
