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

		//Chroniony konstruktor domy�lny
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

		//Chroniony konstruktor kopiuj�cy
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

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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

		//Metoda zwraca flag�, czy obiekt posiada modu� prezentacji stanu slot�w
		const bool CPowerRelayStation::getUseSlotsRate() const
		{
			return m_slotsrate_date.getUseEquipment();
		}

		//Metoda ustawia flag�, czy obiekt posiada modu� prezentacji stanu slot�w
		void CPowerRelayStation::setUseSlotsRate(const bool use_slots_rate)
		{
			m_slotsrate_date.setUseEquipment(use_slots_rate);
		}

		//Metoda zwraca ilo�� elektrowni, kt�re modu� mo�e obs�ugiwa�
		const int CPowerRelayStation::getPowerstationsCapacity() const
		{
			return m_powerstations_capacity;
		}

		//Metoda ustawia ilo�� elektrowni, kt�re modu� mo�e obs�ugiwa�
		void CPowerRelayStation::setPowerstationsCapacity(const int powerstations_capacity)
		{
			m_powerstations_capacity = powerstations_capacity;
		}

		//Metoda zwraca sta�� referencj� na zakres czasu trwania stanu - wizualizacja aktywno�ci
		const std::pair<float, float> & CPowerRelayStation::getStateTimeRange() const
		{
			return m_state_time_range;
		}

		//Metoda ustawia sta�� referencj� na zakres czasu trwania stanu - wizualizacja aktywno�ci
		void CPowerRelayStation::setStateTimeRange(const std::pair<float, float> & state_time_range)
		{
			m_state_time_range = state_time_range;
		}

		//Metoda zwraca sta�� referencj� na zakres pr�dko�ci i kierunek obracania si� mudu�u
		const std::pair<float, float> & CPowerRelayStation::getRotationSpeedRange() const
		{
			return m_rotation_speed_range;
		}

		//Metoda ustawia sta�� referencj� na zakres pr�dko�ci i kierunek obracania si� mudu�u
		void CPowerRelayStation::setRotationSpeedRange(const std::pair<float, float> & rotation_speed_range)
		{
			m_rotation_speed_range = rotation_speed_range;
		}

		//Metoda zwraca ilo�� zaj�tych slot�w, do kt�rych zalogowane s� elektrownie
		const int CPowerRelayStation::getBusySlots() const
		{
			return m_busy_slots;
		}

		//Metoda ustawia ilo�� zaj�tych slot�w, do kt�rych zalogowane s� elektrownie
		void CPowerRelayStation::setBusySlots(const int busy_slots)
		{
			m_busy_slots = busy_slots;
		}

		//Metoda zwraca czas trwania stanu - wizualizacja aktywno�ci
		const float CPowerRelayStation::getStateTime() const
		{
			return m_state_time;
		}

		//Metoda ustawia czas trwania stanu - wizualizacja aktywno�ci
		void CPowerRelayStation::setStateTime(const float state_time)
		{
			m_state_time = state_time;
		}

		//Metoda zwraca pr�dko�� i kierunek obracania si� mudu�u - wizualizacja aktywno�ci
		const float CPowerRelayStation::getRotationSpeed() const
		{
			return m_rotation_speed;
		}

		//Metoda ustawia pr�dko�� i kierunek obracania si� mudu�u - wizualizacja aktywno�ci
		void CPowerRelayStation::setRotationSpeed(const float rotation_speed)
		{
			m_rotation_speed = rotation_speed;
		}

		//Metoda zwraca wska�nik na obiekt klasy CSlotsRate
		CSlotsRate* CPowerRelayStation::getSlotsRate()
		{
			return m_slotsrate_date.getSlotsRate();
		}

		//Metoda ustawia wska�nik na obiekt klasy CSlotsRate

		void CPowerRelayStation::setSlotsRate(CSlotsRate* slots_rate)
		{
			m_slotsrate_date.setSlotsRate(slots_rate);
		}

		//Metoda zwraca wska�nik na obiekt klasy Battery
		Battery* CPowerRelayStation::getBattery()
		{
			return m_battery_data.getBattery();
		}

		//Metoda ustawia wska�nik na obiekt klasy Battery
		void CPowerRelayStation::setBattery(Battery* battery)
		{
			m_battery_data.setBattery(battery);
		}

		//Metoda zwraca flag�, czy obiekt posiada bateri�
		const bool CPowerRelayStation::getUseBattery() const
		{
			return m_battery_data.getUseEquipment();
		}

		//Metoda ustawia flag�, czy obiekt posiada bateri�
		void CPowerRelayStation::setUseBattery(const bool use_battery)
		{
			m_battery_data.setUseEquipment(use_battery);
		}

		//Metoda zwraca czas do rozpocz�cia g��wnego zadania obiektu
		const float CPowerRelayStation::getTimeToStart() const
		{
			return m_time_to_start;
		}

		//Metoda ustawia czas do rozpocz�cia g��wnego zadania obiektu
		void CPowerRelayStation::setTimeToStart(const float time_to_start)
		{
			m_time_to_start = time_to_start;
		}

		//Metoda zwraca czas trwania procesu do wyga�ni�cia g��wnego zadania obiektu
		const float CPowerRelayStation::getDurationDisconnect() const
		{
			return m_duration_disconnect;
		}

		//Metoda ustawia czas trwania procesu do wyga�ni�cia g��wnego zadania obiektu
		void CPowerRelayStation::setDurationDisconnect(const float duration_disconnect)
		{
			m_duration_disconnect = duration_disconnect;
		}

		//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
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

		//Wirtualna metoda aktualizuj�ca obiekt
		void CPowerRelayStation::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			//aktualizacja geometrii - niezale�nie od tego, czy urz�dzenie jest w��czone
			if (m_slotsrate_date.getUseEquipment())
				updateSlotRateTransformation(dt);

			//w��czam bateri� (mechanizm z op�nieniem) - jest to jedyne �r�d�o zasilania
			m_battery_data.getBattery()->runBattery();

			//je�li urz�dzenie jest w��czone
			if(CRelayStation::m_unit_controller.getState())
			{
				//czekam na aktywacj� (w��czenie baterii)
				//poniewa� jest to jedyne �r�d�o zasilania funkcjonalno�ci tej klasy
				if (m_battery_data.getBattery()->getUnitController().getState())
				{
					updatePowerRelayStationBehavior(dt);//obiekt si� "rozgl�da"
					updatePowerRelayStationState(dt);	//aktualizacja stan�w
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
				//losowanie pr�dko�ci i kierunku rotacji
				m_rotation_speed = gRandom.GetSingleton().Rndf(m_rotation_speed_range.first, m_rotation_speed_range.second);
			
				if (m_battery_data.getBattery())//behawiorystyka podlega prawom starzenia baterii jako �r�d�a energii
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
			//automat stan�w - tryb default
			if (m_powerrelaystation_state == POWER_RELAY_STATION_DEFAULT)
			{
				if (CRelayStation::m_unit_controller.getState())//je�li urz�dzenie jest w��czone
				{
					m_time_to_start -= dt;
					if (m_time_to_start <= 0)
						m_powerrelaystation_state = POWER_RELAY_STATION_UPDATE_CONNECTION;
				}
			}

			if (m_powerrelaystation_state == POWER_RELAY_STATION_UPDATE_CONNECTION)
			{
				if (CRelayStation::m_unit_controller.getState())//je�li urz�dzenie jest w��czone
				{
					if (m_slotsrate_date.getUseEquipment())//je�li obiekt posiada modu� prezentacji zaj�to�ci slot�w
					{
						//logika zarz�dzania slots rate
						if (m_slotsrate_date.getSlotsRate())
						{
							m_busy_slots = 2;//symulacja...testy....
							//m_busy_slots = m_powerstations.size();
							//AI loguj�cych si� elektrowni
							//AI wylogowuj�cych si� elektrowni (login, logout, death, etc...)
							m_slotsrate_date.getSlotsRate()->setSlotCounter(m_busy_slots);
						}
					}

					if (m_battery_data.getBattery())
					{
						//urz�dzenie zasilane jest bateryjnie - je�li bateria si� wyczerpa�a
						if (m_battery_data.getBattery()->getCapacity() <= 0)
						{
							m_powerrelaystation_state = POWER_RELAY_STATION_DISCONNECT;
							if (m_slotsrate_date.getSlotsRate())
								m_slotsrate_date.getSlotsRate()->setSlotCounter(0);//zerowanie licznika slot�w
							//...
							//poinformowanie zalogowanych elektrowni, �e nie s� ju� obs�ugiwane
							//code - od��czenie z kontenera
							//code - wyzerowanie flagi elektrowni, �e nie jest ju� obs�ugiwana i mo�e szuka� innego przeka�nika
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
					CRelayStation::m_unit_controller.setState(false);//wy��czamy urz�dzenie
					m_powerrelaystation_state = POWER_RELAY_STATION_DAMAGE;
				}
			}
			
			if (m_powerrelaystation_state == POWER_RELAY_STATION_DAMAGE)
			{
				//i po jakim� czasie...
				//MarkForDelete();
				//if (p_slots_rate)
				//	p_slots_rate->MarkForDelete();

				//serwis, wymiana baterii, death, etc...
			}
		}

		//metoda aktualizuje wska�nik na obiekt CSlotsRate - geometria
		void CPowerRelayStation::updateSlotRateTransformation(float dt)
		{
			if (m_slotsrate_date.getSlotsRate())//wska�nik jest zainicjowamy
			{
				m_slotsrate_date.getSlotsRate()->SetPosition(GetPosition());
				m_slotsrate_date.getSlotsRate()->SetScaleBody(GetScaleHead());
				m_slotsrate_date.getSlotsRate()->SetRotationBody(GetRotationHead());
			}
		}
	}//namespace energetics
}//namespace logic
