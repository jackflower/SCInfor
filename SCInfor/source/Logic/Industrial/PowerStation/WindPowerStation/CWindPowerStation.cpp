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

		//Chroniony konstruktor domy�lny
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

		//Chroniony konstruktor kopiuj�cy
		CWindPowerStation::CWindPowerStation(const CWindPowerStation &CWindPowerStationCopy)
		:
			CPowerStation				(CWindPowerStationCopy),//konstruktor kopiuj�cy klasy bazowej
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

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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

		//Metoda zwraca czas co jaki nast�puje kondensacja energii
		const float CWindPowerStation::getEnergyCondensationTime() const
		{
			return m_energy_condensation_time;
		}

		//Metoda ustawia czas co jaki nast�puje kondensacja energii
		void CWindPowerStation::setEnergyCondensationTime(const float energy_condensation_time)
		{
			m_energy_condensation_time = energy_condensation_time;
		}

		//Metoda zwraca wsp�czynnik bezw�adno�ci
		const float CWindPowerStation::getPortionEenergyFactor() const
		{
			return m_portion_energy_factor;
		}

		//Metoda ustawia wsp�czynnik bezw�adno�ci
		void CWindPowerStation::setPortionEenergyFactor(const float portion_energy_factor)
		{
			m_portion_energy_factor = portion_energy_factor;
		}

		//Metoda zwraca porcj� energii - warto�� prze�adunku z turbiny
		const float CWindPowerStation::getPortionEnergy() const
		{
			return m_portion_energy;
		}

		//Metoda ustawia porcj� energii - warto�� prze�adunku z turbiny
		void CWindPowerStation::setPortionEnergy(const float portion_energy)
		{
			m_portion_energy = portion_energy;
		}

		//Metoda zwraca flag�, czy elektrownia wiatrowa posiada turbi� wiatrow�
		const bool CWindPowerStation::getUseWindTurbine() const
		{
			return m_windturbine_data.getUseEquipment();
		}

		//Metoda ustawia flag�, czy elektrownia wiatrowa posiada turbi� wiatrow�
		void CWindPowerStation::setUseWindTurbine(const bool use_windturbine)
		{
			m_windturbine_data.setUseEquipment(use_windturbine);
		}

		//Metoda zwraca wska�nik na obiekt klasy WindTurbine
		WindTurbine* CWindPowerStation::getWindTurbine()
		{
			return m_windturbine_data.getTurbine();
		}
		
		//Metoda ustawia wska�nik na obiekt klasy WindTurbine
		void CWindPowerStation::setWindTurbine(WindTurbine* windturbine)
		{
			m_windturbine_data.setTurbine(windturbine);
		}

		//Metoda zwraca flag�, czy korpus si� obraca (HEAD)
		const bool CWindPowerStation::getUseRotationHead() const
		{
			return m_use_rotation_head;
		}

		//Metoda ustawia flag�, czy korpus si� obraca (HEAD)
		void CWindPowerStation::setUseRotationHead(const bool use_rotation_head)
		{
			m_use_rotation_head = use_rotation_head;
		}

		//Metoda zwraca pr�dko�� obrotu korpusu (HEAD)
		const float CWindPowerStation::getSpeedRotationHead() const
		{
			return m_speed_rotation_head;
		}

		//Metoda ustawia pr�dko�� obrotu korpusu (HEAD)
		void CWindPowerStation::setSpeedRotationHead(const float speed_rotation_head)
		{
			m_speed_rotation_head = speed_rotation_head;
		}

		//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
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

		//Wirtualna metoda aktualizuj�ca obiekt
		void CWindPowerStation::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);
			
			//Wywo�anie z klasy bazowej - AI logowania do systemu...
			CPowerStation::update(dt);

			//je�li urz�dzenie jest w��czone
			if(m_unit_controller.getState())
			{
				updateWindPowerState(dt);
				updateAnimations(dt);
			}

			//aktualizuja po�o�enia turbiny wzgl�dem w�a�ciciela
			updateCWindTurbineTransformation(dt);

			//je�li flaga jest ustawiona na true - obraca si� modu� - korpus (HEAD)
			if(m_use_rotation_head)
				RotateHead(m_speed_rotation_head);
		}

		//prywatna metoda aktualizuje stan obiektu
		void CWindPowerStation::updateWindPowerState(float dt)
		{
			//stan pocz�tkowy - wyzwala stan gromadzenia energii
			if(m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DEFAULT)
			{
				//zliczam czas
				m_elapsed_time += dt;

				//na ustalony czas zmieniam stan, podczas kt�rego aktualizuj� energi�
				if(m_elapsed_time >= m_energy_condensation_time)
				{
					//zmiana stanu - na stan kondensacji energii
					m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_UPDATE_ENERGY;
					m_elapsed_time = 0.0f;
				}
			}
				
			//obs�uga stanu kondensacji energii
			if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_UPDATE_ENERGY)
			{
				//proces przebiega - elektrownia gromadzi i kondensuje energi�
				if (m_stored_energy <= m_energy_capacitor)
				{
					//m_damage += dt;
					m_elapsed_time += dt;

					//je�li wska�nik jest zainicjowany
					if (m_windturbine_data.getTurbine())
					{
						//je�li energia zgromadzona przez turbin� jest wi�ksza od porcji do przekazania
						if (m_windturbine_data.getTurbine()->getStoredEnergy() > m_portion_energy)
						{
							//zasilam porcj� energii (uwzgl�niam wsp�czynnik)
							m_stored_energy += m_portion_energy * 0.5f;//m_portion_energy_factor?s
							//odejmuj� z turbiny t� porcj� energii
							m_windturbine_data.getTurbine()->setStoredEnergy(m_windturbine_data.getTurbine()->getStoredEnergy() - (m_portion_energy * 0.5f));
						}
					}

					//po czasie kondensacji energii powr�t do stanu deafult
					if (m_elapsed_time >= m_energy_condensation_time)
					{
						//powr�t do stanu pocz�tkowego
						m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_DEFAULT;
						//zeruj� czas
						m_elapsed_time = 0.0f;
					}
				}
				else
					m_windpower_station_state = EWindPowerStationState::WINDPOWER_STATION_DEFAULT;

				//stan uszkodzenia - niezale�ny od mechanizmu kondensowania energii - dedykowana funkcjonalno��
				//if(m_damage > 3)
				//{
				//	m_windpower_station_state = WINDPOWER_STATION_DAMAGE;
				//	std::cout << "Zmiania na WINDPOWER_STATION_DAMAGE . . . " << std::endl;
				//}

				//obs�uga stanu uszkodzenia
				if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DAMAGE)
				{
					//czekam okre�lony czas na dotarcie servisu,
					//po tym czasie ustawiam stan WINDPOWER_STATION_DEATH
					//to do - s e r v i c e...
				}

				//obs�uga stanu ostatecznego
				if (m_windpower_station_state == EWindPowerStationState::WINDPOWER_STATION_DEATH)
				{
					//czekam okre�lony czas...prepare to delete...
					//po tym czasie ustawiam flag� do usuni�cia
				}

				//diagnostyka
				//std::cout << "Turbina    : " << m_windturbine_data.getTurbine()->getStoredEnergy() << std::endl;
				//std::cout << "Elektrownia: " << m_stored_energy << std::endl;
				//std::cout << "Capacitor  : " << m_energy_capacitor << std::endl;
			}
		}

		//prywatna metoda aktualizuje po�o�enie turbiny wzgl�dem w�a�ciciela
		void CWindPowerStation::updateCWindTurbineTransformation(float dt)
		{
			//docelowo prywatna metoda
			if (m_windturbine_data.getTurbine())
			{
				//Aktualizacja po�o�enia turbiny wzgl�dem w�a�ciciela (ta klasa)
				//generalnie podpinam CWindTurbineData aby mie�
				//mo�liwo�� dowolnego dobory po�o�enia turbin.
				//W tej klasie - nie korzystam z tego mechanizmu,
				//turbina jest po�o�ona na wsp�lnej osi jej w�a�ciciela
				m_windturbine_data.getTurbine()->SetPosition(GetPosition());
			}
		}

	}//namespace powerstation
}//namespace logic

//Nadanie warto�ci sta�ym sk�adowym statycznym
float logic::powerstation::CWindPowerStation::s_portion_energy_default	= 0.25f;	//default - porcja energii, kt�r� b�d� m�g� zabiera� z turbiny (dla bezpiecze�stwa)
float logic::powerstation::CWindPowerStation::s_portion_energy_factor	= 0.5f;		//default - wsp�czynnik bezw�adno�ci
