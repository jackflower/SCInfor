//  ____________________________________
// | CEnergy.cpp - class implementation |
// | Jack Flower February 2014          |
// |____________________________________|
//

#include "CEnergy.h"
#include "../../Logic/CPhysicalManager.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Utilities/Utilities/Utilities.h"
#include "../../Weather/CWeather.h"

using namespace weather;

namespace equipment
{

	RTTI_IMPL(CEnergy, CActor);

	//Konstruktor
	CEnergy::CEnergy(const std::wstring& uniqueId)
	:
		CActor							(uniqueId),//konstruktor klasy bazowej
		m_energy_name					(),
		m_energytank_data				(),
		m_percentage_reserve_energy		(0.1f),
		m_energy_time_delayed			(0.0f),
		m_energy_empty_message			(false),
		m_energy_regeneration			(0.0f),
		m_energy_regeneration_time		(0.0f),
		m_energy_timer					(0.0f),
		m_energy_percentage_energy		(0.0f),
		m_energy_rotor_speed			(0.0f),
		m_energy_rotation_speed			(750.0f),
		m_energy_state					(ENERGY_DEFAULT),
		m_battery_data					(),
		m_critical_duration				(0.0f),
		m_critical_timer				(0.0f),
		m_damage_duration				(0.0f),
		m_damage_timer					(0.0f),
		m_owner_death_candidate			(false),
		m_unit_controller				(false)//urz¹dzenie wy³¹czone - uruchamia siê z opóŸnieniem
	{
		//inverse - docelowo jakaœ metoda...
		SetZIndexBody(Z_PHYSICAL_ENERGY_HEAD);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_ENERGY_HEAD);
		SetZIndexHead(Z_PHYSICAL_ENERGY_BODY);
		SetZIndexShadowHead(Z_PHYSICAL_ENERGY_BODY);
	}

	//Konstruktor kopiuj¹cy
	CEnergy::CEnergy(const CEnergy& CEnergyCopy)
	:
		CActor							(CEnergyCopy),
		m_energy_name					(CEnergyCopy.m_energy_name),
		m_energytank_data				(CEnergyCopy.m_energytank_data),
		m_percentage_reserve_energy		(CEnergyCopy.m_percentage_reserve_energy),
		m_energy_time_delayed			(CEnergyCopy.m_energy_time_delayed),
		m_energy_empty_message			(CEnergyCopy.m_energy_empty_message),
		m_energy_regeneration			(CEnergyCopy.m_energy_regeneration),
		m_energy_regeneration_time		(CEnergyCopy.m_energy_regeneration_time),
		m_energy_timer					(CEnergyCopy.m_energy_timer),
		m_energy_percentage_energy		(CEnergyCopy.m_energy_percentage_energy),
		m_energy_rotor_speed			(CEnergyCopy.m_energy_rotor_speed),
		m_energy_rotation_speed			(CEnergyCopy.m_energy_rotation_speed),
		m_energy_state					(CEnergyCopy.m_energy_state),
		m_battery_data					(CEnergyCopy.m_battery_data),
		m_critical_duration				(CEnergyCopy.m_critical_duration),
		m_critical_timer				(CEnergyCopy.m_critical_timer),
		m_damage_duration				(CEnergyCopy.m_damage_duration),
		m_damage_timer					(CEnergyCopy.m_damage_timer),
		m_owner_death_candidate			(CEnergyCopy.m_owner_death_candidate),
		m_unit_controller				(CEnergyCopy.m_unit_controller)
	{
	}

	//Destruktor
	CEnergy::~CEnergy(void)
	{
		//CActor						not edit
		m_energy_name					= "";
		//m_energytank_data				not edit
		m_percentage_reserve_energy		= 0.0f;
		m_energy_time_delayed			= 0.0f;
		m_energy_empty_message			= false;
		m_energy_regeneration			= 0.0f;
		m_energy_timer					= 0.0f;
		m_energy_percentage_energy		= 0.0f;
		m_energy_rotor_speed			= 0.0f;
		m_energy_rotation_speed			= 0.0f;
		m_energy_state					= ENERGY_DEFAULT;
		//m_battery_data				not edit
		m_critical_duration				= 0.0f;
		m_critical_timer				= 0.0f;
		m_damage_duration				= 0.0f;
		m_damage_timer					= 0.0f;
		m_owner_death_candidate			= false;
		//m_unit_controller				not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEnergy::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwê akumulatora energii
	const std::string CEnergy::GetEnergyName() const
	{
		return m_energy_name;
	}

	//Metoda ustawia nazwê akumulatora energii
	const void CEnergy::SetEnergyName(const std::string& energy_name)
	{
		m_energy_name = energy_name;
	}

	//Metoda zwraca wartoœæ, przy której nastêpuje komunikat informacyjny o niskim poziomie energii
	const float CEnergy::GetPercentageReserveEnergy() const
	{
		return m_percentage_reserve_energy;
	}

	//Metoda ustawia wartoœæ, przy której nastêpuje komunikat informacyjny o niskim poziomie energii
	const void CEnergy::SetPercentageReserveEnergy(float percentage_reserve_energy)
	{
		m_percentage_reserve_energy = percentage_reserve_energy;
	}

	//Metoda zwraca wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku energii
	const bool CEnergy::GetEnergyEmptyMessage() const
	{
		return m_energy_empty_message;
	}

	//Metoda ustawia wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku energii
	const void CEnergy::SetEnergyEmptyMessage(bool energy_empty_message)
	{
		m_energy_empty_message = energy_empty_message;
	}

	//Metoda zwraca czas opóŸnienia komunikatu o braku energii
	const float CEnergy::GetEnergyTimeDelayed() const
	{
		return m_energy_time_delayed;
	}

	//Metoda ustawia czas opóŸnienia komunikatu o braku energii
	const void CEnergy::SetEnergyTimeDelayed(float energy_time_delayed)
	{
		m_energy_time_delayed = energy_time_delayed;
	}

	//Metoda zwraca wartoœæ energii dla procesu jej regeneracji
	const float CEnergy::GetEnergyRegeneration() const
	{
		return m_energy_regeneration;
	}

	//Metoda ustawia wartoœæ energii dla procesu jej regeneracji
	const void CEnergy::SetEnergyRegeneration(float energy_regeneration)
	{
		m_energy_regeneration = energy_regeneration;
	}

	//Metoda zwraca czêstotliwoœæ regeneracji procesu
	const float CEnergy::GetEnergyRegenerationTime() const
	{
		return m_energy_regeneration_time;
	}

	//Metoda ustawia czêstotliwoœæ regeneracji procesu
	void CEnergy::SetEnergyRegenerationTime(float energy_regeneration_time)
	{
		m_energy_regeneration_time = energy_regeneration_time;
	}

	//Metoda zwraca prêdkoœæ wirowania wskaŸnika energii w akumulatorze
	const float CEnergy::GetEnergyRotationSpeed() const
	{
		return m_energy_rotation_speed;
	}

	//Metoda ustawia prêdkoœæ wirowania wskaŸnika energii w akumulatorze
	void CEnergy::SetEnergyRotationSpeed(float energy_rotation_speed)
	{
		m_energy_rotation_speed = energy_rotation_speed;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CEnergyTank
	CEnergyTank* CEnergy::GetEnergyTank()
	{
		return m_energytank_data.getEnergyTank();
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CEnergyTank
	void CEnergy::SetEnergyTank(CEnergyTank* energy_tank)
	{
		m_energytank_data.setEnergyTank(energy_tank);
	}

	//Metoda zwraca flagê, czy obiekt posiada akumulator energii
	const bool CEnergy::GetUseEnergyTank() const
	{
		return m_energytank_data.getUseEquipment();
	}

	//Metoda ustawia flagê, czy obiekt posiada akumulator energii
	void CEnergy::SetUseEnergyTank(bool use_energytank)
	{
		m_energytank_data.setUseEquipment(use_energytank);
	}

	//Metoda zwraca referencjê na opakowanie funkcjonalnoœci akumulatora
	CEquipmentEnergyTankData & CEnergy::getEquipmentEnergyTankData()
	{
		return m_energytank_data;
	}

	//Metoda ustawia referencjê na opakowanie funkcjonalnoœci akumulatora
	void CEnergy::setEquipmentEnergyTankData(CEquipmentEnergyTankData & energytank_data)
	{
		m_energytank_data = energytank_data;
	}

	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & CEnergy::getEnergyTankTransformed()
	{
		return m_energytank_data.getTransformed();
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void CEnergy::setEnergyTankTransformed(CTransformation & energytank_transformation)
	{
		m_energytank_data.setTransformed(energytank_transformation);
	}

	//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
	void CEnergy::UpdateAnimations(float dt)
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

	//Metoda zwraca wskaŸnik na obiekt klasy CBattery - bateria
	CBattery *CEnergy::getBattery()
	{
		return m_battery_data.getBattery();
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CBattery - bateria
	void CEnergy::setBattery(CBattery *battery)
	{
		m_battery_data.setBattery(battery);
	}

	//Metoda zwraca flagê, czy obiekt posiada bateriê
	const bool CEnergy::getUseBattery() const
	{
		return m_battery_data.getUseEquipment();
	}

	//Metoda ustawia flagê, czy obiekt posiada bateriê
	void CEnergy::setUseBattery(bool use_battery)
	{
		m_battery_data.setUseEquipment(use_battery);
	}

	//Metoda zwraca czas trwania stanu krytycznego
	const float CEnergy::getCriticalDuration() const
	{
		return m_critical_duration;
	}

	//Metoda ustawia czas trwania stanu krytycznego
	void CEnergy::setCriticalDuration(float critical_duration)
	{
		m_critical_duration = critical_duration;
	}

	//Metoda zwraca czas trwania stanu uszkodzenia
	const float CEnergy::getDamageDuration() const
	{
		return m_damage_duration;
	}

	//Metoda ustawia czas trwania stanu uszkodzenia
	void CEnergy::setDamageDuration(float damage_duration)
	{
		m_damage_duration = damage_duration;
	}

	//Metoda zwraca referencjcê na modu³ sterowania
	CSwitch & CEnergy::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje logikê obiektu
	void CEnergy::Update(float dt)
	{
		CPhysical::UpdateShadow(dt);	//aktualizacja shadow engine

		updateEnergyTankTransformation(dt);

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//jeœli urz¹dzenie jest w³¹czone
		if(m_unit_controller.getState())
		{
			m_energy_timer += dt; //odmiarzam czas

			//nale¿y ustaliæ rotacjê (prêdkoœæ i warunki)
			if(m_energytank_data.getEnergyTank())
			{
				//obliczamy procentow¹ zawartoœæ energii w akumulatorze
				if(m_energytank_data.getEnergyTank()->GetEnergyTankCapacity())
					m_energy_percentage_energy = m_energytank_data.getEnergyTank()->GetEnergy()/ m_energytank_data.getEnergyTank()->GetEnergyTankCapacity();
				//aktualizacja prêdkoœci wirowania ³opatek wirnika w zale¿noœci od procentowej iloœci energii akumulatora
				m_energy_rotor_speed = m_energy_rotation_speed * m_energy_percentage_energy;

				//prêdkoœæ rotacji wirnika alternatora zale¿y od energii akumulatora i stanu obiektu
				if(m_energytank_data.getEnergyTank()->GetEnergy() && m_energy_state != ENERGY_DEATH)
					RotateHead(m_energy_rotor_speed * dt);
				
				//regeneracja - energii w akumulatorze jest mniej ni¿ wynosi pojemnoœæ akumulatora
				if(m_energytank_data.getEnergyTank()->GetEnergy() < m_energytank_data.getEnergyTank()->GetEnergyTankCapacity())
				{
					if(m_energy_timer >= m_energy_regeneration_time)//jeœli up³yn¹³ jakiœ czas
					{
						//regenerujemy energiê
						m_energytank_data.getEnergyTank()->SetEnergy(m_energytank_data.getEnergyTank()->GetEnergy() + (m_energy_regeneration * gWeather.getSolarEnergyFactor()));
						m_energy_timer = 0.0f;//zerujemy czas
					}
				}

				//prêdkoœæ rotacji wirnika - modu³ energii uszkodony - zasilanie bateryjne
				if(m_energy_state == ENERGY_DAMAGE)
					RotateHead(- m_energy_rotation_speed * 0.5f * dt);

				//prêdkoœæ rotacji wirnika - modu³ energii zniszczony
				if(m_energy_state == ENERGY_DEATH)
					RotateHead(- m_energy_rotation_speed * 0.25f * dt);
			}

			//aktualizacja energii - jeœli jest energia
			if(m_energytank_data.getEnergyTank())
				updateEnergyTank(dt);

			UpdateEnergyState(dt);	//aktualizuja stanu obiektu
			UpdateAnimations(dt);	//aktualizacja animacji (stany energy)
		}
	}

	//implementacja metod private:

	//Metoda aktualizuje stan obiektu
	void CEnergy::UpdateEnergyState(float dt)
	{
		if(m_energytank_data.getEnergyTank() && m_energy_state != ENERGY_DAMAGE && m_energy_state != ENERGY_DEATH)
		{
			//jest wystarczaj¹ca iloœæ energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->GetEnergy() > m_energytank_data.getEnergyTank()->GetEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energy_state = ENERGY_DEFAULT;

			//rezerwa energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->GetEnergy() <= m_energytank_data.getEnergyTank()->GetEnergyTankCapacity() * m_percentage_reserve_energy)
				m_energy_state = ENERGY_RESERVE;

			//brak energii w akumulatorze
			if(m_energytank_data.getEnergyTank()->GetEnergy() <= 0.f)
				m_energy_state = ENERGY_EMPTY;

			//brak energii w akumulatorze trwa jakiœ czas - stan krytyczny
			if(m_energy_state == ENERGY_EMPTY)
			{
				//czekam jakiœ czas, gdy akumulator jest roz³adowany
				m_critical_timer += dt;
				if(m_critical_timer >= m_critical_duration)
				{
					m_energy_state = ENERGY_DAMAGE;		//ustawiam modu³ energii - uszkodzony
					m_critical_timer = 0.0f;
				}
			}
		}

		//wykryto uszkodzenie - sprawdzam mo¿liwoœæ zasilania z baterii
		if(m_energy_state == ENERGY_DAMAGE)
		{
			//czekam jakiœ czas - akumulator jest uszkodzony
			m_damage_timer += dt;
			if(m_damage_timer >= m_damage_duration)
			{
				m_energy_state = ENERGY_DEATH;				//modu³ energii zniszczony
				m_battery_data.getBattery()->runBattery();	//prze³¹czam siê na zasilanie bateryjne
				m_damage_timer = 0.0f;
			}
		}

		//bateria jest zainicjowana, a modu³ energii przesta³ dzia³aæ/istnieæ
		if(m_battery_data.getBattery() && m_energy_state == ENERGY_DEATH)
		{
			//jeœli modu³ energii posiada bateriê
			if(m_battery_data.getBattery())
				//bateria siê wyczerpa³a
				if (m_battery_data.getBattery()->getCapacity() <= 0)
				{
					m_energy_rotation_speed = 0.0f;	//wirnik siê zatrzymuje...
					m_owner_death_candidate = true;	//informacja dla w³aœciela tego obiektu o potencjalnym
				}
		}
	}

	//prywatna metoda aktualizuje obiekt - energytank - transformation and logic
	void CEnergy::updateEnergyTank(float dt)
	{
		if (m_energytank_data.getEnergyTank())
		{
			//jest wystarczaj¹ca iloœæ energii
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

	//prywatna metoda aktualizuje sk³adowe transformacji wzglêdem w³aœciciela
	void CEnergy::updateEnergyTankTransformation(float dt)
	{
		//m_energytank_transformation.Transform(this, p_energy_tank);
		m_energytank_data.Transform(this, m_energytank_data.getEnergyTank());
	}
}//namespace equipment
