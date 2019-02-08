//  _______________________________________________
// | CPowerRelayStation.cpp - class implementation |
// | Jack Flower - July 2015                       |
// |_______________________________________________|
//

#include "CPowerRelayStation.h"
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
		RTTI_IMPL(CPowerRelayStation, CRelayStation);

		//Chroniony konstruktor domyœlny
		CPowerRelayStation::CPowerRelayStation(const std::wstring& uniqueId)
			:
			CRelayStation				(uniqueId),//konstruktor klasy bazowej
			m_powerrelaystation_state	(POWER_RELAY_STATION_DEFAULT),
			m_slotsrate_date			(),
			m_powerstations_capacity	(0),
			m_busy_slots				(0),
			m_state_time_range			(0.0f, 0.0f),
			m_rotation_speed_range		(0.0f, 0.0f),
			m_state_time				(0.0f),
			m_rotation_speed			(0.0f),
			m_battery_data				(),
			m_time_to_start				(0.0f),
			m_duration_disconnect		(0.0f)
		{
			SetZIndexBody(Z_PHYSICAL_RELAY_STATION_BODY);
			SetZIndexShadowBody(Z_PHYSICAL_SHADOW_RELAY_STATION_BODY);
			SetZIndexHead(Z_PHYSICAL_RELAY_STATION_HEAD);
			SetZIndexShadowHead(Z_PHYSICAL_SHADOW_RELAY_STATION_HEAD);
		}

		//Chroniony konstruktor kopiuj¹cy
		CPowerRelayStation::CPowerRelayStation(const CPowerRelayStation &CPowerRelayStationCopy)
			:
			CRelayStation				(CPowerRelayStationCopy),//konstruktor kopiujacy klasy bazowej
			m_powerrelaystation_state	(CPowerRelayStationCopy.m_powerrelaystation_state),
			m_slotsrate_date			(CPowerRelayStationCopy.m_slotsrate_date),
			m_powerstations_capacity	(CPowerRelayStationCopy.m_powerstations_capacity),
			m_busy_slots				(CPowerRelayStationCopy.m_busy_slots),
			m_state_time_range			(CPowerRelayStationCopy.m_state_time_range),
			m_rotation_speed_range		(CPowerRelayStationCopy.m_rotation_speed_range),
			m_state_time				(CPowerRelayStationCopy.m_state_time),
			m_rotation_speed			(CPowerRelayStationCopy.m_rotation_speed),
			m_battery_data				(CPowerRelayStationCopy.m_battery_data),
			m_time_to_start				(CPowerRelayStationCopy.m_time_to_start),
			m_duration_disconnect		(CPowerRelayStationCopy.m_duration_disconnect)
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CPowerRelayStation::~CPowerRelayStation()
		{
			//Actor						not edit
			m_powerrelaystation_state		= POWER_RELAY_STATION_DEFAULT;
			//m_slotsrate_date				not edit
			m_powerstations_capacity		= 0;
			m_busy_slots					= 0;
			m_state_time_range.first		= 0.0f;
			m_state_time_range.second		= 0.0f;
			m_rotation_speed_range.first	= 0.0f;
			m_rotation_speed_range.second	= 0.0f;
			m_state_time					= 0.0f;
			m_rotation_speed				= 0.0f;
			//m_battery_data				not edit
			m_time_to_start					= 0.0f;
			m_duration_disconnect			= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CPowerRelayStation::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca flagê, czy obiekt posiada modu³ prezentacji stanu slotów
		const bool CPowerRelayStation::getUseSlotsRate() const
		{
			return m_slotsrate_date.getUseEquipment();
		}

		//Metoda ustawia flagê, czy obiekt posiada modu³ prezentacji stanu slotów
		void CPowerRelayStation::setUseSlotsRate(const bool use_slots_rate)
		{
			m_slotsrate_date.setUseEquipment(use_slots_rate);
		}

		//Metoda zwraca iloœæ elektrowni, które modu³ mo¿e obs³ugiwaæ
		const int CPowerRelayStation::getPowerstationsCapacity() const
		{
			return m_powerstations_capacity;
		}

		//Metoda ustawia iloœæ elektrowni, które modu³ mo¿e obs³ugiwaæ
		void CPowerRelayStation::setPowerstationsCapacity(const int powerstations_capacity)
		{
			m_powerstations_capacity = powerstations_capacity;
		}

		//Metoda zwraca sta³¹ referencjê na zakres czasu trwania stanu - wizualizacja aktywnoœci
		const std::pair<float, float> & CPowerRelayStation::getStateTimeRange() const
		{
			return m_state_time_range;
		}

		//Metoda ustawia sta³¹ referencjê na zakres czasu trwania stanu - wizualizacja aktywnoœci
		void CPowerRelayStation::setStateTimeRange(const std::pair<float, float> & state_time_range)
		{
			m_state_time_range = state_time_range;
		}

		//Metoda zwraca sta³¹ referencjê na zakres prêdkoœci i kierunek obracania siê mudu³u
		const std::pair<float, float> & CPowerRelayStation::getRotationSpeedRange() const
		{
			return m_rotation_speed_range;
		}

		//Metoda ustawia sta³¹ referencjê na zakres prêdkoœci i kierunek obracania siê mudu³u
		void CPowerRelayStation::setRotationSpeedRange(const std::pair<float, float> & rotation_speed_range)
		{
			m_rotation_speed_range = rotation_speed_range;
		}

		//Metoda zwraca iloœæ zajêtych slotów, do których zalogowane s¹ elektrownie
		const int CPowerRelayStation::getBusySlots() const
		{
			return m_busy_slots;
		}

		//Metoda ustawia iloœæ zajêtych slotów, do których zalogowane s¹ elektrownie
		void CPowerRelayStation::setBusySlots(const int busy_slots)
		{
			m_busy_slots = busy_slots;
		}

		//Metoda zwraca czas trwania stanu - wizualizacja aktywnoœci
		const float CPowerRelayStation::getStateTime() const
		{
			return m_state_time;
		}

		//Metoda ustawia czas trwania stanu - wizualizacja aktywnoœci
		void CPowerRelayStation::setStateTime(const float state_time)
		{
			m_state_time = state_time;
		}

		//Metoda zwraca prêdkoœæ i kierunek obracania siê mudu³u - wizualizacja aktywnoœci
		const float CPowerRelayStation::getRotationSpeed() const
		{
			return m_rotation_speed;
		}

		//Metoda ustawia prêdkoœæ i kierunek obracania siê mudu³u - wizualizacja aktywnoœci
		void CPowerRelayStation::setRotationSpeed(const float rotation_speed)
		{
			m_rotation_speed = rotation_speed;
		}

		//Metoda zwraca wskaŸnik na obiekt klasy CSlotsRate
		CSlotsRate* CPowerRelayStation::getSlotsRate()
		{
			return m_slotsrate_date.getSlotsRate();
		}

		//Metoda ustawia wskaŸnik na obiekt klasy CSlotsRate

		void CPowerRelayStation::setSlotsRate(CSlotsRate* slots_rate)
		{
			m_slotsrate_date.setSlotsRate(slots_rate);
		}

		//Metoda zwraca wskaŸnik na obiekt klasy Battery
		Battery* CPowerRelayStation::getBattery()
		{
			return m_battery_data.getBattery();
		}

		//Metoda ustawia wskaŸnik na obiekt klasy Battery
		void CPowerRelayStation::setBattery(Battery* battery)
		{
			m_battery_data.setBattery(battery);
		}

		//Metoda zwraca flagê, czy obiekt posiada bateriê
		const bool CPowerRelayStation::getUseBattery() const
		{
			return m_battery_data.getUseEquipment();
		}

		//Metoda ustawia flagê, czy obiekt posiada bateriê
		void CPowerRelayStation::setUseBattery(const bool use_battery)
		{
			m_battery_data.setUseEquipment(use_battery);
		}

		//Metoda zwraca czas do rozpoczêcia g³ównego zadania obiektu
		const float CPowerRelayStation::getTimeToStart() const
		{
			return m_time_to_start;
		}

		//Metoda ustawia czas do rozpoczêcia g³ównego zadania obiektu
		void CPowerRelayStation::setTimeToStart(const float time_to_start)
		{
			m_time_to_start = time_to_start;
		}

		//Metoda zwraca czas trwania procesu do wygaœniêcia g³ównego zadania obiektu
		const float CPowerRelayStation::getDurationDisconnect() const
		{
			return m_duration_disconnect;
		}

		//Metoda ustawia czas trwania procesu do wygaœniêcia g³ównego zadania obiektu
		void CPowerRelayStation::setDurationDisconnect(const float duration_disconnect)
		{
			m_duration_disconnect = duration_disconnect;
		}

		//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
		void CPowerRelayStation::updateAnimations(float dt)
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

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CPowerRelayStation::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			//aktualizacja geometrii - niezale¿nie od tego, czy urz¹dzenie jest w³¹czone
			if (m_slotsrate_date.getUseEquipment())
				updateSlotRateTransformation(dt);

			//w³¹czam bateriê (mechanizm z opóŸnieniem) - jest to jedyne Ÿród³o zasilania
			m_battery_data.getBattery()->runBattery();

			//jeœli urz¹dzenie jest w³¹czone
			if(CRelayStation::m_unit_controller.getState())
			{
				//czekam na aktywacjê (w³¹czenie baterii)
				//poniewa¿ jest to jedyne Ÿród³o zasilania funkcjonalnoœci tej klasy
				if (m_battery_data.getBattery()->getUnitController().getState())
				{
					updatePowerRelayStationBehavior(dt);//obiekt siê "rozgl¹da"
					updatePowerRelayStationState(dt);	//aktualizacja stanów
					updateAnimations(dt);				//aktualizacja animacji
				}
			}
		}

		//prywatna metoda aktualizuje stan obiektu - behawiorystyka
		void CPowerRelayStation::updatePowerRelayStationBehavior(float dt)
		{
			if (m_state_time <= 0)
			{
				//losowanie czasu trwania stanu
				m_state_time = gRandom.GetSingleton().Rndf(m_state_time_range.first, m_state_time_range.second);
				//losowanie prêdkoœci i kierunku rotacji
				m_rotation_speed = gRandom.GetSingleton().Rndf(m_rotation_speed_range.first, m_rotation_speed_range.second);
			
				if (m_battery_data.getBattery())//behawiorystyka podlega prawom starzenia baterii jako Ÿród³a energii
					m_rotation_speed *= m_battery_data.getBattery()->getBatteryCharge();
			}
			
			if (m_state_time > 0)
			{
				SetRotationHead(GetRotationHead() + m_rotation_speed);
				m_state_time = m_state_time - dt;
			}
		}

		//prywatna metoda aktualizuje stan obiektu
		void CPowerRelayStation::updatePowerRelayStationState(float dt)
		{
			//automat stanów - tryb default
			if (m_powerrelaystation_state == POWER_RELAY_STATION_DEFAULT)
			{
				if (CRelayStation::m_unit_controller.getState())//jeœli urz¹dzenie jest w³¹czone
				{
					m_time_to_start -= dt;
					if (m_time_to_start <= 0)
						m_powerrelaystation_state = POWER_RELAY_STATION_UPDATE_CONNECTION;
				}
			}

			if (m_powerrelaystation_state == POWER_RELAY_STATION_UPDATE_CONNECTION)
			{
				if (CRelayStation::m_unit_controller.getState())//jeœli urz¹dzenie jest w³¹czone
				{
					if (m_slotsrate_date.getUseEquipment())//jeœli obiekt posiada modu³ prezentacji zajêtoœci slotów
					{
						//logika zarz¹dzania slots rate
						if (m_slotsrate_date.getSlotsRate())
						{
							m_busy_slots = 2;//symulacja...testy....
							//m_busy_slots = m_powerstations.size();
							//AI loguj¹cych siê elektrowni
							//AI wylogowuj¹cych siê elektrowni (login, logout, death, etc...)
							m_slotsrate_date.getSlotsRate()->setSlotCounter(m_busy_slots);
						}
					}

					if (m_battery_data.getBattery())
					{
						//urz¹dzenie zasilane jest bateryjnie - jeœli bateria siê wyczerpa³a
						if (m_battery_data.getBattery()->getCapacity() <= 0)
						{
							m_powerrelaystation_state = POWER_RELAY_STATION_DISCONNECT;
							if (m_slotsrate_date.getSlotsRate())
								m_slotsrate_date.getSlotsRate()->setSlotCounter(0);//zerowanie licznika slotów
							//...
							//poinformowanie zalogowanych elektrowni, ¿e nie s¹ ju¿ obs³ugiwane
							//code - od³¹czenie z kontenera
							//code - wyzerowanie flagi elektrowni, ¿e nie jest ju¿ obs³ugiwana i mo¿e szukaæ innego przekaŸnika
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
					CRelayStation::m_unit_controller.setState(false);//wy³¹czamy urz¹dzenie
					m_powerrelaystation_state = POWER_RELAY_STATION_DAMAGE;
				}
			}
			
			if (m_powerrelaystation_state == POWER_RELAY_STATION_DAMAGE)
			{
				//i po jakimœ czasie...
				//MarkForDelete();
				//if (p_slots_rate)
				//	p_slots_rate->MarkForDelete();

				//serwis, wymiana baterii, death, etc...
			}
		}

		//metoda aktualizuje wskaŸnik na obiekt CSlotsRate - geometria
		void CPowerRelayStation::updateSlotRateTransformation(float dt)
		{
			if (m_slotsrate_date.getSlotsRate())//wskaŸnik jest zainicjowamy
			{
				m_slotsrate_date.getSlotsRate()->SetPosition(GetPosition());
				m_slotsrate_date.getSlotsRate()->SetScaleBody(GetScaleHead());
				m_slotsrate_date.getSlotsRate()->SetRotationBody(GetRotationHead());
			}
		}
	}//namespace energetics
}//namespace logic
