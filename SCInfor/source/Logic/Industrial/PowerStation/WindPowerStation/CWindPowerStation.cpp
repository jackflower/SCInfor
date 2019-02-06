//  ______________________________________________
// | CWindPowerStation.cpp - class implementation |
// | Jack Flower - July 2014                      |
// |______________________________________________|
//

#include "CWindPowerStation.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../Rendering/Animations/CAnimation.h"
#include "../../../../Rendering/Animations/CAnimationState.h"
#include "../../../../Rendering/Displayable/CDisplayable.h"
#include "../../../CPhysicalManager.h"
#include <iostream>

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CWindPowerStation, CPowerStation);

		//Chroniony konstruktor domyœlny
		CWindPowerStation::CWindPowerStation(const std::wstring& uniqueId)
		:
			CPowerStation				(uniqueId),//konstruktor klasy bazowej
			m_windpower_station_state	(EWindPowerStationState::WINDPOWER_STATION_DEFAULT),
			m_windturbine_data			(),
			m_energy_condensation_time	(0.0f),
			m_portion_energy_factor		(s_portion_energy_factor),
			m_portion_energy			(s_portion_energy_default),
			m_use_rotation_head			(false),
			m_speed_rotation_head		(0.0f),
			m_damage					(0.0f),
			m_elapsed_time				(0.0f)
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CWindPowerStation::CWindPowerStation(const CWindPowerStation &CWindPowerStationCopy)
		:
			CPowerStation				(CWindPowerStationCopy),//konstruktor kopiuj¹cy klasy bazowej
			m_windpower_station_state	(CWindPowerStationCopy.m_windpower_station_state),
			m_windturbine_data			(CWindPowerStationCopy.m_windturbine_data),
			m_energy_condensation_time	(CWindPowerStationCopy.m_energy_condensation_time),
			m_portion_energy_factor		(CWindPowerStationCopy.m_portion_energy_factor),
			m_portion_energy			(CWindPowerStationCopy.m_portion_energy),
			m_use_rotation_head			(CWindPowerStationCopy.m_use_rotation_head),
			m_speed_rotation_head		(CWindPowerStationCopy.m_speed_rotation_head),
			m_damage					(CWindPowerStationCopy.m_damage),
			m_elapsed_time				(CWindPowerStationCopy.m_elapsed_time)
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CWindPowerStation::~CWindPowerStation()
		{
			//CPowerStation				not edit
			m_windpower_station_state	= EWindPowerStationState::WINDPOWER_STATION_DEFAULT;
			//m_windturbine_data		not edit
			m_energy_condensation_time	= 0.0f;
			m_portion_energy_factor		= 0.0f;
			m_portion_energy			= 0.0f;
			m_use_rotation_head			= false;
			m_speed_rotation_head		= 0.0f;
			m_damage					= 0.0f;
			m_elapsed_time				= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CWindPowerStation::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca stan obiektu
		const EWindPowerStationState CWindPowerStation::getPowerStationState() const
		{
			return m_windpower_station_state;
		}

		//Metoda ustawia stan obiektu
		void CWindPowerStation::setPowerStationState(const EWindPowerStationState windpower_station_state)
		{
			m_windpower_station_state = windpower_station_state;
		}

		//Metoda zwraca czas co jaki nastêpuje kondensacja energii
		const float CWindPowerStation::getEnergyCondensationTime() const
		{
			return m_energy_condensation_time;
		}

		//Metoda ustawia czas co jaki nastêpuje kondensacja energii
		void CWindPowerStation::setEnergyCondensationTime(const float energy_condensation_time)
		{
			m_energy_condensation_time = energy_condensation_time;
		}

		//Metoda zwraca wspó³czynnik bezw³adnoœci
		const float CWindPowerStation::getPortionEenergyFactor() const
		{
			return m_portion_energy_factor;
		}

		//Metoda ustawia wspó³czynnik bezw³adnoœci
		void CWindPowerStation::setPortionEenergyFactor(const float portion_energy_factor)
		{
			m_portion_energy_factor = portion_energy_factor;
		}

		//Metoda zwraca porcjê energii - wartoœæ prze³adunku z turbiny
		const float CWindPowerStation::getPortionEnergy() const
		{
			return m_portion_energy;
		}

		//Metoda ustawia porcjê energii - wartoœæ prze³adunku z turbiny
		void CWindPowerStation::setPortionEnergy(const float portion_energy)
		{
			m_portion_energy = portion_energy;
		}

		//Metoda zwraca flagê, czy elektrownia wiatrowa posiada turbiê wiatrow¹
		const bool CWindPowerStation::getUseWindTurbine() const
		{
			return m_windturbine_data.getUseEquipment();
		}

		//Metoda ustawia flagê, czy elektrownia wiatrowa posiada turbiê wiatrow¹
		void CWindPowerStation::setUseWindTurbine(const bool use_windturbine)
		{
			m_windturbine_data.setUseEquipment(use_windturbine);
		}

		//Metoda zwraca wskaŸnik na obiekt klasy WindTurbine
		WindTurbine* CWindPowerStation::getWindTurbine()
		{
			return m_windturbine_data.getTurbine();
		}
		
		//Metoda ustawia wskaŸnik na obiekt klasy WindTurbine
		void CWindPowerStation::setWindTurbine(WindTurbine* windturbine)
		{
			m_windturbine_data.setTurbine(windturbine);
		}

		//Metoda zwraca flagê, czy korpus siê obraca (HEAD)
		const bool CWindPowerStation::getUseRotationHead() const
		{
			return m_use_rotation_head;
		}

		//Metoda ustawia flagê, czy korpus siê obraca (HEAD)
		void CWindPowerStation::setUseRotationHead(const bool use_rotation_head)
		{
			m_use_rotation_head = use_rotation_head;
		}

		//Metoda zwraca prêdkoœæ obrotu korpusu (HEAD)
		const float CWindPowerStation::getSpeedRotationHead() const
		{
			return m_speed_rotation_head;
		}

		//Metoda ustawia prêdkoœæ obrotu korpusu (HEAD)
		void CWindPowerStation::setSpeedRotationHead(const float speed_rotation_head)
		{
			m_speed_rotation_head = speed_rotation_head;
		}

		//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
		void CWindPowerStation::updateAnimations(float dt)
		{
			switch(m_windpower_station_state)
			{
			case EWindPowerStationState::WINDPOWER_STATION_DEFAULT:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetWindPowerStationBodyDefaultAnim());
					SetAnimationHead(p_anim_set->GetWindPowerStationHeadDefaultAnim());
				}
				break;
			}
			case EWindPowerStationState::WINDPOWER_STATION_UPDATE_ENERGY:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetWindPowerStationBodyUpdateEnergyAnim());
					SetAnimationHead(p_anim_set->GetWindPowerStationHeadUpdateEnergyAnim());
				}
				break;
			}
			case EWindPowerStationState::WINDPOWER_STATION_DAMAGE:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetWindPowerStationBodyDamageAnim());
					SetAnimationHead(p_anim_set->GetWindPowerStationHeadDamageAnim());
				}
				break;
			}
			case EWindPowerStationState::WINDPOWER_STATION_DEATH:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetWindPowerStationBodyDeathAnim());
					SetAnimationHead(p_anim_set->GetWindPowerStationHeadDeathAnim());
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CWindPowerStation::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);
			
			//Wywo³anie z klasy bazowej - AI logowania do systemu...
			CPowerStation::update(dt);

			//jeœli urz¹dzenie jest w³¹czone
			if(m_unit_controller.getState())
			{
				updateWindPowerState(dt);
				updateAnimations(dt);
			}

			//aktualizuja po³o¿enia turbiny wzglêdem w³aœciciela
			updateCWindTurbineTransformation(dt);

			//jeœli flaga jest ustawiona na true - obraca siê modu³ - korpus (HEAD)
			if(m_use_rotation_head)
				RotateHead(m_speed_rotation_head);
		}

		//prywatna metoda aktualizuje stan obiektu
		void CWindPowerStation::updateWindPowerState(float dt)
		{
			//stan pocz¹tkowy - wyzwala stan gromadzenia energii
			if(m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DEFAULT)
			{
				//zliczam czas
				m_elapsed_time += dt;

				//na ustalony czas zmieniam stan, podczas którego aktualizujê energiê
				if(m_elapsed_time >= m_energy_condensation_time)
				{
					//zmiana stanu - na stan kondensacji energii
					m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_UPDATE_ENERGY;
					m_elapsed_time = 0.0f;
				}
			}
				
			//obs³uga stanu kondensacji energii
			if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_UPDATE_ENERGY)
			{
				//proces przebiega - elektrownia gromadzi i kondensuje energiê
				if (m_stored_energy <= m_energy_capacitor)
				{
					//m_damage += dt;
					m_elapsed_time += dt;

					//jeœli wskaŸnik jest zainicjowany
					if (m_windturbine_data.getTurbine())
					{
						//jeœli energia zgromadzona przez turbinê jest wiêksza od porcji do przekazania
						if (m_windturbine_data.getTurbine()->getStoredEnergy() > m_portion_energy)
						{
							//zasilam porcj¹ energii (uwzglêniam wspó³czynnik)
							m_stored_energy += m_portion_energy * 0.5f;//m_portion_energy_factor?s
							//odejmujê z turbiny tê porcjê energii
							m_windturbine_data.getTurbine()->setStoredEnergy(m_windturbine_data.getTurbine()->getStoredEnergy() - (m_portion_energy * 0.5f));
						}
					}

					//po czasie kondensacji energii powrót do stanu deafult
					if (m_elapsed_time >= m_energy_condensation_time)
					{
						//powrót do stanu pocz¹tkowego
						m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_DEFAULT;
						//zerujê czas
						m_elapsed_time = 0.0f;
					}
				}
				else
					m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_DEFAULT;

				//stan uszkodzenia - niezale¿ny od mechanizmu kondensowania energii - dedykowana funkcjonalnoœæ
				//if(m_damage > 3)
				//{
				//	m_windpower_station_state = WINDPOWER_STATION_DAMAGE;
				//	std::cout << "Zmiania na WINDPOWER_STATION_DAMAGE . . . " << std::endl;
				//}

				//obs³uga stanu uszkodzenia
				if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DAMAGE)
				{
					//czekam okreœlony czas na dotarcie servisu,
					//po tym czasie ustawiam stan WINDPOWER_STATION_DEATH
					//to do - s e r v i c e...
				}

				//obs³uga stanu ostatecznego
				if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DEATH)
				{
					//czekam okreœlony czas...prepare to delete...
					//po tym czasie ustawiam flagê do usuniêcia
				}

				//diagnostyka
				//std::cout << "Turbina    : " << m_windturbine_data.getTurbine()->getStoredEnergy() << std::endl;
				//std::cout << "Elektrownia: " << m_stored_energy << std::endl;
				//std::cout << "Capacitor  : " << m_energy_capacitor << std::endl;
			}
		}

		//prywatna metoda aktualizuje po³o¿enie turbiny wzglêdem w³aœciciela
		void CWindPowerStation::updateCWindTurbineTransformation(float dt)
		{
			//docelowo prywatna metoda
			if (m_windturbine_data.getTurbine())
			{
				//Aktualizacja po³o¿enia turbiny wzglêdem w³aœciciela (ta klasa)
				//generalnie podpinam CWindTurbineData aby mieæ
				//mo¿liwoœæ dowolnego dobory po³o¿enia turbin.
				//W tej klasie - nie korzystam z tego mechanizmu,
				//turbina jest po³o¿ona na wspólnej osi jej w³aœciciela
				m_windturbine_data.getTurbine()->SetPosition(GetPosition());
			}
		}

	}//namespace powerstation
}//namespace logic

//Nadanie wartoœci sta³ym sk³adowym statycznym
float logic::powerstation::CWindPowerStation::s_portion_energy_default	= 0.25f;	//default - porcja energii, któr¹ bêdê móg³ zabieraæ z turbiny (dla bezpieczeñstwa)
float logic::powerstation::CWindPowerStation::s_portion_energy_factor	= 0.5f;		//default - wspó³czynnik bezw³adnoœci
