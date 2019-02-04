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
		m_unit_controller(false)//urz�dzenie wy��czone - uruchamia si� z op�nieniem
	{
		//inverse - docelowo jaka� metoda...
		SetZIndexBody(Z_PHYSICAL_ENERGY_HEAD);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_ENERGY_HEAD);
		SetZIndexHead(Z_PHYSICAL_ENERGY_BODY);
		SetZIndexShadowHead(Z_PHYSICAL_ENERGY_BODY);
	}

	//Konstruktor kopiuj�cy
	Energy::Energy(const Energy & EnergyCopy)
	:
		CActor(EnergyCopy),//konstruktor kopiuj�cy klasy bazowej
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

	//Metoda zwraca nazw� akumulatora energii
	const std::string Energy::getEnergyName() const
	{
		return m_energy_name;
	}

	//Metoda ustawia nazw� akumulatora energii
	void Energy::setEnergyName(const std::string & energy_name)
	{
		m_energy_name = energy_name;
	}

	//Metoda zwraca warto��, przy kt�rej nast�puje komunikat informacyjny o niskim poziomie energii
	const float Energy::getPercentageReserveEnergy() const
	{
		return m_percentage_reserve_energy;
	}

	//Metoda ustawia warto��, przy kt�rej nast�puje komunikat informacyjny o niskim poziomie energii
	void Energy::setPercentageReserveEnergy(float percentage_reserve_energy)
	{
		m_percentage_reserve_energy = percentage_reserve_energy;
	}

	//Metoda zwraca warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku energii
	const bool Energy::getEnergyEmptyMessage() const
	{
		return m_energy_empty_message;
	}

	//Metoda ustawia warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku energii
	void Energy::setEnergyEmptyMessage(bool energy_empty_message)
	{
		m_energy_empty_message = energy_empty_message;
	}

	//Metoda zwraca czas op�nienia komunikatu o braku energii
	const float Energy::getEnergyTimeDelayed() const
	{
		return m_energy_time_delayed;
	}

	//Metoda ustawia czas op�nienia komunikatu o braku energii
	void Energy::setEnergyTimeDelayed(float energy_time_delayed)
	{
		m_energy_time_delayed = energy_time_delayed;
	}

	//Metoda zwraca warto�� energii dla procesu jej regeneracji
	const float Energy::getEnergyRegeneration() const
	{
		return m_energy_regeneration;
	}

	//Metoda ustawia warto�� energii dla procesu jej regeneracji
	void Energy::setEnergyRegeneration(float energy_regeneration)
	{
		m_energy_regeneration = energy_regeneration;
	}

	//Metoda zwraca cz�stotliwo�� regeneracji procesu
	const float Energy::getEnergyRegenerationTime() const
	{
		return m_energy_regeneration_time;
	}

	//Metoda ustawia cz�stotliwo�� regeneracji procesu
	void Energy::setEnergyRegenerationTime(float energy_regeneration_time)
	{
		m_energy_regeneration_time = energy_regeneration_time;
	}

	//Metoda zwraca pr�dko�� wirowania wska�nika energii w akumulatorze
	const float Energy::getEnergyRotationSpeed() const
	{
		return m_energy_rotation_speed;
	}

	//Metoda ustawia pr�dko�� wirowania wska�nika energii w akumulatorze
	void Energy::setEnergyRotationSpeed(float energy_rotation_speed)
	{
		m_energy_rotation_speed = energy_rotation_speed;
	}

	//Metoda zwraca wska�nik na obiekt klasy CEnergyTank
	CEnergyTank * Energy::getEnergyTank()
	{
		return m_energytank_data.getEnergyTank();
	}

	//Metoda ustawia wska�nik na obiekt klasy CEnergyTank
	void Energy::setEnergyTank(CEnergyTank * energy_tank)
	{
		m_energytank_data.setEnergyTank(energy_tank);
	}

	//Metoda zwraca flag�, czy obiekt posiada akumulator energii
	const bool Energy::getUseEnergyTank() const
	{
		return m_energytank_data.getUseEquipment();
	}

	//Metoda ustawia flag�, czy obiekt posiada akumulator energii
	void Energy::setUseEnergyTank(bool use_energytank)
	{
		m_energytank_data.setUseEquipment(use_energytank);
	}

	//Metoda zwraca referencj� na opakowanie funkcjonalno�ci akumulatora
	CEquipmentEnergyTankData & Energy::getEquipmentEnergyTankData()
	{
		return m_energytank_data;
	}

	//Metoda ustawia referencj� na opakowanie funkcjonalno�ci akumulatora
	void Energy::setEquipmentEnergyTankData(CEquipmentEnergyTankData & energytank_data)
	{
		m_energytank_data = energytank_data;
	}

	//Metoda zwraca referencj� na opakowanie danych dla transformacji
	CTransformation & Energy::getEnergyTankTransformed()
	{
		return m_energytank_data.getTransformed();
	}

	//Metoda ustawia referencj� na opakowanie danych dla transformacji
	void Energy::setEnergyTankTransformed(CTransformation & energytank_transformation)
	{
		m_energytank_data.setTransformed(energytank_transformation);
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
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

	//Metoda zwraca wska�nik na obiekt klasy CBattery - bateria
	CBattery * Energy::getBattery()
	{
		return m_battery_data.getBattery();
	}

	//Metoda ustawia wska�nik na obiekt klasy CBattery - bateria
	void Energy::setBattery(CBattery *battery)
	{
		m_battery_data.setBattery(battery);
	}

	//Metoda zwraca flag�, czy obiekt posiada bateri�
	const bool Energy::getUseBattery() const
	{
		return m_battery_data.getUseEquipment();
	}

	//Metoda ustawia flag�, czy obiekt posiada bateri�
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

	//Metoda zwraca referencjc� na modu� sterowania
	CSwitch & Energy::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje logik� obiektu
	void Energy::update(float dt)
	{
		CPhysical::UpdateShadow(dt);	//aktualizacja shadow engine

		updateEnergyTankTransformation(dt);

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//je�li urz�dzenie jest w��czone
		if(m_unit_controller.getState())
		{
			m_energy_timer += dt; //odmiarzam czas

			//nale�y ustali� rotacj� (pr�dko�� i warunki)
			if(m_energytank_data.getEnergyTank())
			{
				//obliczamy procentow� zawarto�� energii w akumulatorze
				if(m_energytank_data.getEnergyTank()->GetEnergyTankCapacity())
					m_energy_percentage_energy = m_energytank_data.getEnergyTank()->GetEnergy()/ m_energytank_data.getEnergyTank()->GetEnergyTankCapacity();
				//aktualizacja pr�dko�ci wirowania �opatek wirnika w zale�no�ci od procentowej ilo�ci energii akumulatora
				m_energy_rotor_speed = m_energy_rotation_speed * m_energy_percentage_energy;

				//pr�dko�� rotacji wirnika alternatora zale�y od energii akumulatora i stanu obiektu
				if(m_energytank_data.getEnergyTank()->GetEnergy() && m_energy_state != ENERGY_DEATH)
					RotateHead(m_energy_rotor_speed * dt);
				
				//regeneracja - energii w akumulatorze jest mniej ni� wynosi pojemno�� akumulatora
				if(m_energytank_data.getEnergyTank()->GetEnergy() < m_energytank_data.getEnergyTank()->GetEnergyTankCapacity())
				{
					if(m_energy_timer >= m_energy_regeneration_time)//je�li up�yn�� jaki� czas
					{
						//regenerujemy energi�
						m_energytank_data.getEnergyTank()->SetEnergy(m_energytank_data.getEnergyTank()->GetEnergy() + (m_energy_regeneration * gWeather.getSolarEnergyFactor()));
						m_energy_timer = 0.0f;//zerujemy czas
					}
				}

				//pr�dko�� rotacji wirnika - modu� energii uszkodony - zasilanie bateryjne
				if(m_energy_state == ENERGY_DAMAGE)
					RotateHead(- m_energy_rotation_speed * 0.5f * dt);

				//pr�dko�� rotacji wirnika - modu� energii zniszczony
				if(m_energy_state == ENERGY_DEATH)
					RotateHead(- m_energy_rotation_speed * 0.25f * dt);
			}

			//aktualizacja energii - je�li jest energia
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
			//jest wystarczaj�ca ilo�� energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->GetEnergy() > m_energytank_data.getEnergyTank()->GetEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energy_state = ENERGY_DEFAULT;

			//rezerwa energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->GetEnergy() <= m_energytank_data.getEnergyTank()->GetEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energy_state = ENERGY_RESERVE;

			//brak energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->GetEnergy() <= 0.f)
				m_energy_state = ENERGY_EMPTY;

			//brak energii w akumulatorze trwa jaki� czas - stan krytyczny
			if(m_energy_state == ENERGY_EMPTY)
			{
				//czekam jaki� czas, gdy akumulator jest roz�adowany
				m_critical_timer += dt;
				if(m_critical_timer >= m_critical_duration)
				{
					m_energy_state = ENERGY_DAMAGE;		//ustawiam modu� energii - uszkodzony
					m_critical_timer = 0.0f;
				}
			}
		}

		//wykryto uszkodzenie - sprawdzam mo�liwo�� zasilania z baterii
		if(m_energy_state == ENERGY_DAMAGE)
		{
			//czekam jaki� czas - akumulator jest uszkodzony
			m_damage_timer += dt;
			if(m_damage_timer >= m_damage_duration)
			{
				m_energy_state = ENERGY_DEATH;				//modu� energii zniszczony
				m_battery_data.getBattery()->runBattery();	//prze��czam si� na zasilanie bateryjne
				m_damage_timer = 0.0f;
			}
		}

		//bateria jest zainicjowana, a modu� energii przesta� dzia�a�/istnie�
		if(m_battery_data.getBattery() && m_energy_state == ENERGY_DEATH)
		{
			//je�li modu� energii posiada bateri�
			if(m_battery_data.getBattery())
				//bateria si� wyczerpa�a
				if (m_battery_data.getBattery()->getCapacity() <= 0)
				{
					m_energy_rotation_speed = 0.0f;	//wirnik si� zatrzymuje...
					m_owner_death_candidate = true;	//informacja dla w�a�ciela tego obiektu o potencjalnym
				}
		}
	}

	//prywatna metoda aktualizuje obiekt - energytank - transformation and logic
	void Energy::updateEnergyTank(float dt)
	{
		if (m_energytank_data.getEnergyTank())
		{
			//jest wystarczaj�ca ilo�� energii
			if(m_energytank_data.getEnergyTank()->GetEnergy() > m_energytank_data.getEnergyTank()->GetEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energytank_data.getEnergyTank()->getEnergyTankState() = ENERGYTANK_DEFAULT;

			//rezerwa energii
			if(m_energytank_data.getEnergyTank()->GetEnergy() <= m_energytank_data.getEnergyTank()->GetEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energytank_data.getEnergyTank()->getEnergyTankState() = ENERGYTANK_RESERVE;

			//brak energii
			if(m_energytank_data.getEnergyTank()->GetEnergy() <= 0.f)
				m_energytank_data.getEnergyTank()->getEnergyTankState() = ENERGYTANK_EMPTY;
		}
	}

	//prywatna metoda aktualizuje sk�adowe transformacji wzgl�dem w�a�ciciela
	void Energy::updateEnergyTankTransformation(float dt)
	{
		//m_energytank_transformation.Transform(this, p_energy_tank);
		m_energytank_data.Transform(this, m_energytank_data.getEnergyTank());
	}
}//namespace equipment
