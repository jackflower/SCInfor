//  ______________________________________________
// | PowerRelayStation.cpp - class implementation |
// | Jack Flower - July 2015                      |
// |______________________________________________|
//

#include "PowerRelayStation.h"
#include "../../CPhysicalManager.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Animations/CAnimation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../../Utilities/Random/CRandom.h"
#include <iostream>

using namespace rendering::drawable;

namespace logic
{
	namespace energetics
	{
		RTTI_IMPL(PowerRelayStation, RelayStation);

		//Chroniony konstruktor domyślny
		PowerRelayStation::PowerRelayStation(const std::wstring & uniqueId)
			:
			RelayStation(uniqueId),//konstruktor klasy bazowej
			m_powerrelaystation_state(POWER_RELAY_STATION_DEFAULT),
			m_slotsrate_date(),
			m_powerstations_capacity(0),
			m_busy_slots(0),
			m_state_time_range(0.0f, 0.0f),
			m_rotation_speed_range(0.0f, 0.0f),
			m_state_time(0.0f),
			m_rotation_speed(0.0f),
			m_battery_data(),
			m_time_to_start(0.0f),
			m_duration_disconnect(0.0f)
		{
			SetZIndexBody(Z_PHYSICAL_RELAY_STATION_BODY);
			SetZIndexShadowBody(Z_PHYSICAL_SHADOW_RELAY_STATION_BODY);
			SetZIndexHead(Z_PHYSICAL_RELAY_STATION_HEAD);
			SetZIndexShadowHead(Z_PHYSICAL_SHADOW_RELAY_STATION_HEAD);
		}

		//Chroniony konstruktor kopiujący
		PowerRelayStation::PowerRelayStation(const PowerRelayStation & PowerRelayStationCopy)
			:
			RelayStation(PowerRelayStationCopy),//konstruktor kopiujacy klasy bazowej
			m_powerrelaystation_state(PowerRelayStationCopy.m_powerrelaystation_state),
			m_slotsrate_date(PowerRelayStationCopy.m_slotsrate_date),
			m_powerstations_capacity(PowerRelayStationCopy.m_powerstations_capacity),
			m_busy_slots(PowerRelayStationCopy.m_busy_slots),
			m_state_time_range(PowerRelayStationCopy.m_state_time_range),
			m_rotation_speed_range(PowerRelayStationCopy.m_rotation_speed_range),
			m_state_time(PowerRelayStationCopy.m_state_time),
			m_rotation_speed(PowerRelayStationCopy.m_rotation_speed),
			m_battery_data(PowerRelayStationCopy.m_battery_data),
			m_time_to_start(PowerRelayStationCopy.m_time_to_start),
			m_duration_disconnect(PowerRelayStationCopy.m_duration_disconnect)
		{
			SetZIndexBody(Z_PHYSICAL_RELAY_STATION_BODY);
			SetZIndexShadowBody(Z_PHYSICAL_SHADOW_RELAY_STATION_BODY);
			SetZIndexHead(Z_PHYSICAL_RELAY_STATION_HEAD);
			SetZIndexShadowHead(Z_PHYSICAL_SHADOW_RELAY_STATION_HEAD);
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		PowerRelayStation::~PowerRelayStation()
		{
			//~RelayStation()						not edit
			m_powerrelaystation_state = POWER_RELAY_STATION_DEFAULT;
			//m_slotsrate_date
			m_powerstations_capacity = 0;
			m_busy_slots = 0;
			m_state_time_range.first = 0.0f;
			m_state_time_range.second = 0.0f;
			m_rotation_speed_range.first = 0.0f;
			m_rotation_speed_range.second = 0.0f;
			m_state_time = 0.0f;
			m_rotation_speed = 0.0f;
			//m_battery_data
			m_time_to_start = 0.0f;
			m_duration_disconnect = 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string PowerRelayStation::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca flagę, czy obiekt posiada moduł prezentacji stanu slotów
		const bool PowerRelayStation::getUseSlotsRate() const
		{
			return m_slotsrate_date.getUseEquipment();
		}

		//Metoda ustawia flagę, czy obiekt posiada moduł prezentacji stanu slotów
		void PowerRelayStation::setUseSlotsRate(const bool use_slots_rate)
		{
			m_slotsrate_date.setUseEquipment(use_slots_rate);
		}

		//Metoda zwraca ilość elektrowni, które moduł może obsługiwać
		const int PowerRelayStation::getPowerstationsCapacity() const
		{
			return m_powerstations_capacity;
		}

		//Metoda ustawia ilość elektrowni, które moduł może obsługiwać
		void PowerRelayStation::setPowerstationsCapacity(const int powerstations_capacity)
		{
			m_powerstations_capacity = powerstations_capacity;
		}

		//Metoda zwraca stałą referencję na zakres czasu trwania stanu - wizualizacja aktywności
		const std::pair<float, float> & PowerRelayStation::getStateTimeRange() const
		{
			return m_state_time_range;
		}

		//Metoda ustawia stałą referencję na zakres czasu trwania stanu - wizualizacja aktywności
		void PowerRelayStation::setStateTimeRange(const std::pair<float, float> & state_time_range)
		{
			m_state_time_range = state_time_range;
		}

		//Metoda zwraca stałą referencję na zakres prędkości i kierunek obracania się mudułu
		const std::pair<float, float> & PowerRelayStation::getRotationSpeedRange() const
		{
			return m_rotation_speed_range;
		}

		//Metoda ustawia stałą referencję na zakres prędkości i kierunek obracania się mudułu
		void PowerRelayStation::setRotationSpeedRange(const std::pair<float, float> & rotation_speed_range)
		{
			m_rotation_speed_range = rotation_speed_range;
		}

		//Metoda zwraca ilość zajętych slotów, do których zalogowane są elektrownie
		const int PowerRelayStation::getBusySlots() const
		{
			return m_busy_slots;
		}

		//Metoda ustawia ilość zajętych slotów, do których zalogowane są elektrownie
		void PowerRelayStation::setBusySlots(const int busy_slots)
		{
			m_busy_slots = busy_slots;
		}

		//Metoda zwraca czas trwania stanu - wizualizacja aktywności
		const float PowerRelayStation::getStateTime() const
		{
			return m_state_time;
		}

		//Metoda ustawia czas trwania stanu - wizualizacja aktywności
		void PowerRelayStation::setStateTime(const float state_time)
		{
			m_state_time = state_time;
		}

		//Metoda zwraca prędkość i kierunek obracania się mudułu - wizualizacja aktywności
		const float PowerRelayStation::getRotationSpeed() const
		{
			return m_rotation_speed;
		}

		//Metoda ustawia prędkość i kierunek obracania się mudułu - wizualizacja aktywności
		void PowerRelayStation::setRotationSpeed(const float rotation_speed)
		{
			m_rotation_speed = rotation_speed;
		}

		//Metoda zwraca wskaźnik na obiekt klasy SlotsRate
		SlotsRate *PowerRelayStation::getSlotsRate()
		{
			return m_slotsrate_date.getSlotsRate();
		}

		//Metoda ustawia wskaźnik na obiekt klasy SlotsRate

		void PowerRelayStation::setSlotsRate(SlotsRate *slots_rate)
		{
			m_slotsrate_date.setSlotsRate(slots_rate);
		}

		//Metoda zwraca wskaźnik na obiekt klasy Battery
		Battery* PowerRelayStation::getBattery()
		{
			return m_battery_data.getBattery();
		}

		//Metoda ustawia wskaźnik na obiekt klasy Battery
		void PowerRelayStation::setBattery(Battery *battery)
		{
			m_battery_data.setBattery(battery);
		}

		//Metoda zwraca flagę, czy obiekt posiada baterię
		const bool PowerRelayStation::getUseBattery() const
		{
			return m_battery_data.getUseEquipment();
		}

		//Metoda ustawia flagę, czy obiekt posiada baterię
		void PowerRelayStation::setUseBattery(const bool use_battery)
		{
			m_battery_data.setUseEquipment(use_battery);
		}

		//Metoda zwraca czas do rozpoczęcia głównego zadania obiektu
		const float PowerRelayStation::getTimeToStart() const
		{
			return m_time_to_start;
		}

		//Metoda ustawia czas do rozpoczęcia głównego zadania obiektu
		void PowerRelayStation::setTimeToStart(const float time_to_start)
		{
			m_time_to_start = time_to_start;
		}

		//Metoda zwraca czas trwania procesu do wygaśnięcia głównego zadania obiektu
		const float PowerRelayStation::getDurationDisconnect() const
		{
			return m_duration_disconnect;
		}

		//Metoda ustawia czas trwania procesu do wygaśnięcia głównego zadania obiektu
		void PowerRelayStation::setDurationDisconnect(const float duration_disconnect)
		{
			m_duration_disconnect = duration_disconnect;
		}

		//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
		void PowerRelayStation::updateAnimations(float dt)
		{
			switch(m_powerrelaystation_state)
			{
			case POWER_RELAY_STATION_DEFAULT:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetPowerRelayStationBodyDefaultAnim());
					SetAnimationHead(p_anim_set->GetPowerRelayStationHeadDefaultAnim());
				}
				break;
			}
			case POWER_RELAY_STATION_UPDATE_CONNECTION:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetPowerRelayStationBodyUpdateConnectionAnim());
					SetAnimationHead(p_anim_set->GetPowerRelayStationHeadUpdateConnectionAnim());
				}
				break;
			}
			case POWER_RELAY_STATION_DISCONNECT:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetPowerRelayStationBodyDisconnectAnim());
					SetAnimationHead(p_anim_set->GetPowerRelayStationHeadDisconnectAnim());
				}
				break;
			}
			case POWER_RELAY_STATION_DAMAGE:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetPowerRelayStationBodyDamageAnim());
					SetAnimationHead(p_anim_set->GetPowerRelayStationHeadDamageAnim());
				}
				break;
			}
			case POWER_RELAY_STATION_DEATHT:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetPowerRelayStationBodyDeathAnim());
					SetAnimationHead(p_anim_set->GetPowerRelayStationHeadDeathAnim());
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualna metoda aktualizująca obiekt
		void PowerRelayStation::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			//aktualizacja geometrii - niezależnie od tego, czy urządzenie jest włączone
			if (m_slotsrate_date.getUseEquipment())
				updateSlotRateTransformation(dt);

			//włączam baterię (mechanizm z opóźnieniem) - jest to jedyne źródło zasilania
			m_battery_data.getBattery()->runBattery();

			//jeśli urządzenie jest włączone
			if(RelayStation::m_unit_controller.getState())
			{
				//czekam na aktywację (włączenie baterii)
				//ponieważ jest to jedyne źródło zasilania funkcjonalności tej klasy
				if (m_battery_data.getBattery()->getUnitController().getState())
				{
					updatePowerRelayStationBehavior(dt); //obiekt się "rozgląda"
					updatePowerRelayStationState(dt); //aktualizacja stanów
					updateAnimations(dt); //aktualizacja animacji
				}
			}
		}

		//prywatna metoda aktualizuje stan obiektu - behawiorystyka
		void PowerRelayStation::updatePowerRelayStationBehavior(float dt)
		{
			if (m_state_time <= 0)
			{
				//losowanie czasu trwania stanu
				m_state_time = gRandom.GetSingleton().Rndf(m_state_time_range.first, m_state_time_range.second);
				//losowanie prędkości i kierunku rotacji
				m_rotation_speed = gRandom.GetSingleton().Rndf(m_rotation_speed_range.first, m_rotation_speed_range.second);
			
				if (m_battery_data.getBattery())//behawiorystyka podlega prawom starzenia baterii jako źródła energii
					m_rotation_speed *= m_battery_data.getBattery()->getBatteryCharge();
			}
			
			if (m_state_time > 0)
			{
				SetRotationHead(GetRotationHead() + m_rotation_speed);
				m_state_time = m_state_time - dt;
			}
		}

		//prywatna metoda aktualizuje stan obiektu
		void PowerRelayStation::updatePowerRelayStationState(float dt)
		{
			//automat stanów - tryb default
			if (m_powerrelaystation_state == POWER_RELAY_STATION_DEFAULT)
			{
				if (RelayStation::m_unit_controller.getState())//jeśli urządzenie jest włączone
				{
					m_time_to_start -= dt;
					if (m_time_to_start <= 0)
						m_powerrelaystation_state = POWER_RELAY_STATION_UPDATE_CONNECTION;
				}
			}

			if (m_powerrelaystation_state == POWER_RELAY_STATION_UPDATE_CONNECTION)
			{
				if (RelayStation::m_unit_controller.getState())//jeśli urządzenie jest włączone
				{
					if (m_slotsrate_date.getUseEquipment())//jeśli obiekt posiada moduł prezentacji zajętości slotów
					{
						//logika zarządzania slots rate
						if (m_slotsrate_date.getSlotsRate())
						{
							m_busy_slots = 2;//symulacja...testy....
							//m_busy_slots = m_powerstations.size();
							//AI logujących się elektrowni
							//AI wylogowujących się elektrowni (login, logout, death, etc...)
							m_slotsrate_date.getSlotsRate()->setSlotCounter(m_busy_slots);
						}
					}

					if (m_battery_data.getBattery())
					{
						//urządzenie zasilane jest bateryjnie - jeśli bateria się wyczerpała
						if (m_battery_data.getBattery()->getCapacity() <= 0)
						{
							m_powerrelaystation_state = POWER_RELAY_STATION_DISCONNECT;
							if (m_slotsrate_date.getSlotsRate())
								m_slotsrate_date.getSlotsRate()->setSlotCounter(0);//zerowanie licznika slotów
							//...
							//poinformowanie zalogowanych elektrowni, że nie są już obsługiwane
							//code - odłączenie z kontenera
							//code - wyzerowanie flagi elektrowni, że nie jest już obsługiwana i może szukać innego przekaźnika
							m_powerstations.clear();//wyczyszczenie kontenera
							//...
						}
					}
				}
			}

			if (m_powerrelaystation_state == POWER_RELAY_STATION_DISCONNECT)
			{
				m_duration_disconnect -= dt;
				if (m_duration_disconnect <= 0)
				{
					RelayStation::m_unit_controller.setState(false);//wyłączamy urządzenie
					m_powerrelaystation_state = POWER_RELAY_STATION_DAMAGE;
				}
			}
			
			if (m_powerrelaystation_state == POWER_RELAY_STATION_DAMAGE)
			{
				//i po jakimś czasie...
				//MarkForDelete();
				//if (p_slots_rate)
				//	p_slots_rate->MarkForDelete();

				//serwis, wymiana baterii, death, etc...
			}
		}

		//metoda aktualizuje wskaźnik na obiekt SlotsRate - geometria
		void PowerRelayStation::updateSlotRateTransformation(float dt)
		{
			if (m_slotsrate_date.getSlotsRate())//wskaźnik jest zainicjowamy
			{
				m_slotsrate_date.getSlotsRate()->SetPosition(GetPosition());
				m_slotsrate_date.getSlotsRate()->SetScaleBody(GetScaleHead());
				m_slotsrate_date.getSlotsRate()->SetRotationBody(GetRotationHead());
			}
		}
	}//namespace energetics
}//namespace logic
