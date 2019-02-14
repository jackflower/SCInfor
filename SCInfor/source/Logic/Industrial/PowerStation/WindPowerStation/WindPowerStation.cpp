//  _____________________________________________
// | WindPowerStation.cpp - class implementation |
// | Jack Flower - July 2014                     |
// |_____________________________________________|
//

#include "WindPowerStation.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../Rendering/Animations/Animation.h"
#include "../../../../Rendering/Animations/CAnimationState.h"
#include "../../../../Rendering/Displayable/CDisplayable.h"
#include "../../../PhysicalManager.h"
#include <iostream>

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(WindPowerStation, PowerStation);

		//Chroniony konstruktor domyślny
		WindPowerStation::WindPowerStation(const std::wstring & uniqueId)
		:
			PowerStation(uniqueId),//konstruktor klasy bazowej
			m_windpower_station_state(EWindPowerStationState::WINDPOWER_STATION_DEFAULT),
			m_windturbine_data(),
			m_energy_condensation_time(0.0f),
			m_portion_energy_factor(s_portion_energy_factor),
			m_portion_energy(s_portion_energy_default),
			m_use_rotation_head(false),
			m_speed_rotation_head(0.0f),
			m_damage(0.0f),
			m_elapsed_time(0.0f)
		{
		}

		//Chroniony konstruktor kopiujący
		WindPowerStation::WindPowerStation(const WindPowerStation & WindPowerStationCopy)
		:
			PowerStation(WindPowerStationCopy),//konstruktor kopiujący klasy bazowej
			m_windpower_station_state(WindPowerStationCopy.m_windpower_station_state),
			m_windturbine_data(WindPowerStationCopy.m_windturbine_data),
			m_energy_condensation_time(WindPowerStationCopy.m_energy_condensation_time),
			m_portion_energy_factor(WindPowerStationCopy.m_portion_energy_factor),
			m_portion_energy(WindPowerStationCopy.m_portion_energy),
			m_use_rotation_head(WindPowerStationCopy.m_use_rotation_head),
			m_speed_rotation_head(WindPowerStationCopy.m_speed_rotation_head),
			m_damage(WindPowerStationCopy.m_damage),
			m_elapsed_time(WindPowerStationCopy.m_elapsed_time)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		WindPowerStation::~WindPowerStation()
		{
			//~PowerStation()
			m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_DEFAULT;
			//m_windturbine_data
			m_energy_condensation_time = 0.0f;
			m_portion_energy_factor = 0.0f;
			m_portion_energy = 0.0f;
			m_use_rotation_head = false;
			m_speed_rotation_head = 0.0f;
			m_damage = 0.0f;
			m_elapsed_time = 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string WindPowerStation::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca stan obiektu
		const EWindPowerStationState WindPowerStation::getPowerStationState() const
		{
			return m_windpower_station_state;
		}

		//Metoda ustawia stan obiektu
		void WindPowerStation::setPowerStationState(const EWindPowerStationState & windpower_station_state)
		{
			m_windpower_station_state = windpower_station_state;
		}

		//Metoda zwraca czas co jaki następuje kondensacja energii
		const float WindPowerStation::getEnergyCondensationTime() const
		{
			return m_energy_condensation_time;
		}

		//Metoda ustawia czas co jaki następuje kondensacja energii
		void WindPowerStation::setEnergyCondensationTime(const float energy_condensation_time)
		{
			m_energy_condensation_time = energy_condensation_time;
		}

		//Metoda zwraca współczynnik bezwładności
		const float WindPowerStation::getPortionEenergyFactor() const
		{
			return m_portion_energy_factor;
		}

		//Metoda ustawia współczynnik bezwładności
		void WindPowerStation::setPortionEenergyFactor(const float portion_energy_factor)
		{
			m_portion_energy_factor = portion_energy_factor;
		}

		//Metoda zwraca porcję energii - wartość przeładunku z turbiny
		const float WindPowerStation::getPortionEnergy() const
		{
			return m_portion_energy;
		}

		//Metoda ustawia porcję energii - wartość przeładunku z turbiny
		void WindPowerStation::setPortionEnergy(const float portion_energy)
		{
			m_portion_energy = portion_energy;
		}

		//Metoda zwraca flagę, czy elektrownia wiatrowa posiada turbię wiatrową
		const bool WindPowerStation::getUseWindTurbine() const
		{
			return m_windturbine_data.getUseEquipment();
		}

		//Metoda ustawia flagę, czy elektrownia wiatrowa posiada turbię wiatrową
		void WindPowerStation::setUseWindTurbine(const bool use_windturbine)
		{
			m_windturbine_data.setUseEquipment(use_windturbine);
		}

		//Metoda zwraca wskaźnik na obiekt klasy WindTurbine
		WindTurbine *WindPowerStation::getWindTurbine()
		{
			return m_windturbine_data.getTurbine();
		}
		
		//Metoda ustawia wskaźnik na obiekt klasy WindTurbine
		void WindPowerStation::setWindTurbine(WindTurbine *windturbine)
		{
			m_windturbine_data.setTurbine(windturbine);
		}

		//Metoda zwraca flagę, czy korpus się obraca (HEAD)
		const bool WindPowerStation::getUseRotationHead() const
		{
			return m_use_rotation_head;
		}

		//Metoda ustawia flagę, czy korpus się obraca (HEAD)
		void WindPowerStation::setUseRotationHead(const bool use_rotation_head)
		{
			m_use_rotation_head = use_rotation_head;
		}

		//Metoda zwraca prędkość obrotu korpusu (HEAD)
		const float WindPowerStation::getSpeedRotationHead() const
		{
			return m_speed_rotation_head;
		}

		//Metoda ustawia prędkość obrotu korpusu (HEAD)
		void WindPowerStation::setSpeedRotationHead(const float speed_rotation_head)
		{
			m_speed_rotation_head = speed_rotation_head;
		}

		//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
		void WindPowerStation::updateAnimations(float dt)
		{
			switch(m_windpower_station_state)
			{
			case EWindPowerStationState::WINDPOWER_STATION_DEFAULT:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetWindPowerStationBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetWindPowerStationHeadDefaultAnim());
				}
				break;
			}
			case EWindPowerStationState::WINDPOWER_STATION_UPDATE_ENERGY:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetWindPowerStationBodyUpdateEnergyAnim());
					setAnimationHead(p_anim_set->GetWindPowerStationHeadUpdateEnergyAnim());
				}
				break;
			}
			case EWindPowerStationState::WINDPOWER_STATION_DAMAGE:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetWindPowerStationBodyDamageAnim());
					setAnimationHead(p_anim_set->GetWindPowerStationHeadDamageAnim());
				}
				break;
			}
			case EWindPowerStationState::WINDPOWER_STATION_DEATH:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetWindPowerStationBodyDeathAnim());
					setAnimationHead(p_anim_set->GetWindPowerStationHeadDeathAnim());
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualna metoda aktualizująca obiekt
		void WindPowerStation::update(float dt)
		{
			//aktualizacja shadow engine
			Physical::updateShadow(dt);
			
			//Wywołanie z klasy bazowej - AI logowania do systemu...
			PowerStation::update(dt);

			//jeśli urządzenie jest włączone
			if(m_unit_controller.getState())
			{
				updateWindPowerState(dt);
				updateAnimations(dt);
			}

			//aktualizuja położenia turbiny względem właściciela
			updateCWindTurbineTransformation(dt);

			//jeśli flaga jest ustawiona na true - obraca się moduł - korpus (HEAD)
			if(m_use_rotation_head)
				rotateHead(m_speed_rotation_head);
		}

		//prywatna metoda aktualizuje stan obiektu
		void WindPowerStation::updateWindPowerState(float dt)
		{
			//stan początkowy - wyzwala stan gromadzenia energii
			if(m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DEFAULT)
			{
				//zliczam czas
				m_elapsed_time += dt;

				//na ustalony czas zmieniam stan, podczas którego aktualizuję energię
				if(m_elapsed_time >= m_energy_condensation_time)
				{
					//zmiana stanu - na stan kondensacji energii
					m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_UPDATE_ENERGY;
					m_elapsed_time = 0.0f;
				}
			}
				
			//obsługa stanu kondensacji energii
			if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_UPDATE_ENERGY)
			{
				//proces przebiega - elektrownia gromadzi i kondensuje energię
				if (m_stored_energy <= m_energy_capacitor)
				{
					//m_damage += dt;
					m_elapsed_time += dt;

					//jeśli wskaźnik jest zainicjowany
					if (m_windturbine_data.getTurbine())
					{
						//jeśli energia zgromadzona przez turbinę jest większa od porcji do przekazania
						if (m_windturbine_data.getTurbine()->getStoredEnergy() > m_portion_energy)
						{
							//zasilam porcją energii (uwzglęniam współczynnik)
							m_stored_energy += m_portion_energy * 0.5f;//m_portion_energy_factor?s
							//odejmuję z turbiny tę porcję energii
							m_windturbine_data.getTurbine()->setStoredEnergy(m_windturbine_data.getTurbine()->getStoredEnergy() - (m_portion_energy * 0.5f));
						}
					}

					//po czasie kondensacji energii powrót do stanu deafult
					if (m_elapsed_time >= m_energy_condensation_time)
					{
						//powrót do stanu początkowego
						m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_DEFAULT;
						//zeruję czas
						m_elapsed_time = 0.0f;
					}
				}
				else
					m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_DEFAULT;

				//stan uszkodzenia - niezależny od mechanizmu kondensowania energii - dedykowana funkcjonalność
				//if(m_damage > 3)
				//{
				//	m_windpower_station_state = WINDPOWER_STATION_DAMAGE;
				//	std::cout << "Zmiania na WINDPOWER_STATION_DAMAGE . . . " << std::endl;
				//}

				//obsługa stanu uszkodzenia
				if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DAMAGE)
				{
					//czekam określony czas na dotarcie servisu,
					//po tym czasie ustawiam stan WINDPOWER_STATION_DEATH
					//to do - s e r v i c e...
				}

				//obsługa stanu ostatecznego
				if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DEATH)
				{
					//czekam określony czas...prepare to delete...
					//po tym czasie ustawiam flagę do usunięcia
				}

				//diagnostyka
				//std::cout << "Turbina    : " << m_windturbine_data.getTurbine()->getStoredEnergy() << std::endl;
				//std::cout << "Elektrownia: " << m_stored_energy << std::endl;
				//std::cout << "Capacitor  : " << m_energy_capacitor << std::endl;
			}
		}

		//prywatna metoda aktualizuje położenie turbiny względem właściciela
		void WindPowerStation::updateCWindTurbineTransformation(float dt)
		{
			//docelowo prywatna metoda
			if (m_windturbine_data.getTurbine())
			{
				//Aktualizacja położenia turbiny względem właściciela (ta klasa)
				//generalnie podpinam WindTurbineData aby mieć
				//możliwość dowolnego dobory położenia turbin.
				//W tej klasie - nie korzystam z tego mechanizmu,
				//turbina jest położona na wspólnej osi jej właściciela
				m_windturbine_data.getTurbine()->setPosition(getPosition());
			}
		}

	}//namespace powerstation
}//namespace logic

//Nadanie wartości stałym składowym statycznym
float logic::powerstation::WindPowerStation::s_portion_energy_default	= 0.25f;	//default - porcja energii, którą będę mógł zabierać z turbiny (dla bezpieczeństwa)
float logic::powerstation::WindPowerStation::s_portion_energy_factor	= 0.5f;		//default - współczynnik bezwładności
