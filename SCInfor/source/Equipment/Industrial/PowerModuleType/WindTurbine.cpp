//  ________________________________________
// | WindTurbine.cpp - class implementation |
// | Jack Flower - July 2014                |
// |________________________________________|
//

#include "WindTurbine.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Animations/CAnimation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../../Rendering/Drawable/Layers.h"
#include <iostream>

using namespace weather;
using namespace rendering::drawable;

namespace equipment
{
	RTTI_IMPL(WindTurbine, PowerModule);

	//Chroniony konstruktor domy�lny
	WindTurbine::WindTurbine(const std::wstring & uniqueId)
	:
		PowerModule(uniqueId),//konstruktor klasy bazowej
		m_turbine_name(),
		m_speed_rotor(0.0f),
		m_speed_transmission(1.0f),
		m_percentage_activation(0.0f),
		m_turbine_state(TURBINE_DEFAULT),
		m_cargo_open_duration(0.0f),
		m_cargo_close_duration(0.0f),
		m_energy_full_duration(0.0f),
		m_calculated_speed_rotor(0.0f),
		m_calculated_energy_full_duration(0.0f)
	{
		SetZIndexBody(Z_PHYSICAL_SHADOW_WIND_TURBINE_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_WIND_TURBINE_BODY);
		SetZIndexHead(Z_PHYSICAL_SHADOW_WIND_TURBINE_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_WIND_TURBINE_HEAD);
	}

	//Chroniony konstruktor kopiuj�cy
	WindTurbine::WindTurbine(const WindTurbine & WindTurbineCopy)
	:
		PowerModule(WindTurbineCopy),//konstruktor kopiuj�cy klasy bazowej
		m_turbine_name(WindTurbineCopy.m_turbine_name),
		m_speed_rotor(WindTurbineCopy.m_speed_rotor),
		m_speed_transmission(WindTurbineCopy.m_speed_transmission),
		m_percentage_activation(WindTurbineCopy.m_percentage_activation),
		m_turbine_state(WindTurbineCopy.m_turbine_state),
		m_cargo_open_duration(WindTurbineCopy.m_cargo_open_duration),
		m_cargo_close_duration(WindTurbineCopy.m_cargo_close_duration),
		m_energy_full_duration(WindTurbineCopy.m_energy_full_duration),
		m_calculated_speed_rotor(WindTurbineCopy.m_calculated_speed_rotor),
		m_calculated_energy_full_duration (WindTurbineCopy.m_calculated_energy_full_duration)
	{
		SetZIndexBody(Z_PHYSICAL_SHADOW_WIND_TURBINE_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_WIND_TURBINE_BODY);
		SetZIndexHead(Z_PHYSICAL_SHADOW_WIND_TURBINE_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_WIND_TURBINE_HEAD);
	}

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
	WindTurbine::~WindTurbine(void)
	{
		//PowerModule
		m_turbine_name = "";
		m_speed_rotor = 0.0f;
		m_speed_transmission = 0.0f;
		m_percentage_activation = 0.0f;
		m_turbine_state = TURBINE_DEFAULT;
		m_cargo_open_duration = 0.0f;
		m_cargo_close_duration = 0.0f;
		m_energy_full_duration = 0.0f;
		m_calculated_speed_rotor = 0.0f;
		m_calculated_energy_full_duration = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string WindTurbine::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazw� turbiny
	const std::string WindTurbine::getTurbineName() const
	{
		return m_turbine_name;
	}

	//Metoda ustawia nazw� turbiny
	void WindTurbine::setTurbineName(const std::string& turbine_name)
	{
		m_turbine_name = turbine_name;
	}

	//Metoda zwraca pr�dko�� wirowania turbiny
	const float WindTurbine::getSpeedRotor() const
	{
		return m_speed_rotor;
	}

	//Metoda ustawia pr�dko�� wirowania turbiny
	void WindTurbine::setSpeedRotor(float speed_rotor)
	{
		m_speed_rotor = speed_rotor;
	}

	//Metoda zwraca prze�o�enie pr�dko�ci obrotowej
	const float WindTurbine::getSpeedTransmission() const
	{
		return m_speed_transmission;
	}

	//Metoda ustawia prze�o�enie pr�dko�ci obrotowej
	void WindTurbine::setSpeedTransmission(float speed_transmission)
	{
		if(speed_transmission <= 0) return;
		m_speed_transmission = speed_transmission;
	}

	//Metoda zwraca procentowy wsp�czynnik aktywacji turbiny
	const float WindTurbine::getPercentageActivation() const
	{
		return m_percentage_activation;
	}

	//Metoda ustawia procentowy wsp�czynnik aktywacji turbiny
	void WindTurbine::setPercentageActivation(float percentage_activation)
	{
		m_percentage_activation = percentage_activation;
	}

	//Metoda zwraca czas trwania stanu, po zgromadzeniu pe�nej energii
	const float WindTurbine::getEnergyFuelDuration() const
	{
		return m_energy_full_duration;
	}

	//Metoda ustawia czas trwania stanu, po zgromadzeniu pe�nej energii
	void WindTurbine::setEnergyFuelDuration(float energy_full_duration)
	{
		m_energy_full_duration = energy_full_duration;
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
	void WindTurbine::updateAnimations(float dt)
	{
		switch(m_turbine_state)
		{
		case TURBINE_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetWindTurbineBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetWindTurbineHeadDefaultAnim());

				//animacja head odtwarza si� w p�tli
				GetDisplayableHead()->GetAnimationState()->SetLooped(true);
				GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
			}
			break;
		}
		case TURBINE_CARGO_DOOR_OPEN:
		{
			if (p_anim_set)
			{
				//SetAnimationBody(p_anim_set->GetWindTurbineBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetWindTurbineHeadCargoOpenAnim());
				
				//animacja head odtwarza si� jeden raz
				GetDisplayableHead()->GetAnimationState()->SetLooped(false);
				GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(false);
			}
			break;
		}
		case TURBINE_CARGO_DOOR_CLOSE:
		{
			if (p_anim_set)
			{
				//SetAnimationBody(p_anim_set->GetWindTurbineBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetWindTurbineHeadCargoCloseAnim());

				//animacja head odtwarza si� jeden raz
				GetDisplayableHead()->GetAnimationState()->SetLooped(false);
				GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(false);
			}
			break;
		}
		case TURBINE_UPDATE_ENERGY:
		{
			if (p_anim_set)
			{
				//SetAnimationBody(p_anim_set->GetWindTurbineBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetWindTurbineHeadUpdateEnergyAnim());
				//animacja head odtwarza si� w p�tli
				GetDisplayableHead()->GetAnimationState()->SetLooped(true);
				GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
			}
			break;
		}
		case TURBINE_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetWindTurbineBodyDamagetAnim());
				SetAnimationHead(p_anim_set->GetWindTurbineHeadDamagetAnim());

				//animacja head odtwarza si� w p�tli
				GetDisplayableHead()->GetAnimationState()->SetLooped(true);
				GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
			}
			break;
		}
		case TURBINE_DEATH:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetWindTurbineBodyDeathAnim());
				SetAnimationHead(p_anim_set->GetWindTurbineHeadDeathAnim());

				//animacja head odtwarza si� w p�tli
				GetDisplayableHead()->GetAnimationState()->SetLooped(true);
				GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
			}
			break;
		}
		default:
			break;
		}
	}

	//Wirtualna metoda aktualizuj�ca obiekt
	void WindTurbine::update(float dt)
	{
		CPhysical::UpdateShadow(dt);	//aktualizacja shadow engine

		//je�li urz�dzenie jest w��czone
		if(m_unit_controller.getState())
		{
			updateTurbineState(dt);
			updateAnimations(dt);
		}
	}

	//prywatna metoda aktualizuje stan obiektu
	void WindTurbine::updateTurbineState(float dt)
	{
		//proces przebiega - turbina gromadzi energi�
		if(m_stored_energy <= m_energy_capacitor)
		{
			if(m_turbine_state == TURBINE_DEFAULT)
			{
				if(gWeather.GetWindSpeed() >= gWeather.getWindSpeedRange().second * m_percentage_activation)
					m_turbine_state = TURBINE_CARGO_DOOR_OPEN;
			}
			if(m_turbine_state == TURBINE_CARGO_DOOR_OPEN)
			{
				//zliczam czas
				m_cargo_open_duration += dt;
				//po zako�czeniu odtworzania jednego cyklu animacji otwierania luku - zmiana stanu
				if(m_cargo_open_duration >= GetAnimationHead()->TotalLength())
				{
					//obliczam pr�dko�� �opatek turniny
					m_calculated_speed_rotor = m_speed_rotor * m_speed_transmission * gWeather.GetWindSpeed() * dt;
					//zmiana stanu - aktualizacja energii
					m_turbine_state = TURBINE_UPDATE_ENERGY;
					//zeruj� czas
					m_cargo_open_duration = 0.0f;
				}
			}
			if(m_turbine_state == TURBINE_UPDATE_ENERGY)
			{
				//w��czam obracanie �opatek turbiny
				SetRotationBody(GetRotationBody() + m_calculated_speed_rotor);
				if(GetRotationBody() > FULL_ROTATION)//wykonano pe�ny obr�t �opatek turbiny
					m_stored_energy += m_power;

				//diagnostyka
				//std::cout << "Inside Turbine:	"<< m_stored_energy << std::endl;
				if(gWeather.GetWindSpeed() < gWeather.getWindSpeedRange().second * m_percentage_activation)
					m_turbine_state = TURBINE_CARGO_DOOR_CLOSE;
			}
			if(m_turbine_state == TURBINE_CARGO_DOOR_CLOSE)
			{
				//zliczam czas
				m_cargo_close_duration += dt;
				//po zako�czeniu odtworzenia jednego cyklu animacji zamykania luku - zmiana stanu
				if(m_cargo_close_duration >= GetAnimationHead()->TotalLength())
				{
					//zmiana stanu - odnowienie procesu aktualizacji energii
					m_turbine_state = TURBINE_DEFAULT;
					//zeruj� czas
					m_cargo_close_duration = 0.0f;
				}
			}
		}

		//turbina zgromadzi�a energi� - jej stan musi przej�� do TURBINE_DEFAULT
		if(m_stored_energy >= m_energy_capacitor && m_turbine_state != TURBINE_DEFAULT)
		{
			//zliczam czas
			m_calculated_energy_full_duration += dt;
			if(m_calculated_energy_full_duration >= m_energy_full_duration)
			{
				m_turbine_state = TURBINE_CARGO_DOOR_CLOSE;
				//zeruj� czas
				m_calculated_energy_full_duration = 0.0f;
			}
		}

		//turbina zgromadzi�a energi� i luk cargo zosta� zamkni�ty - wymuszam TURBINE_DEFAULT
		if(m_stored_energy >= m_energy_capacitor && m_turbine_state == TURBINE_CARGO_DOOR_CLOSE)
		{
			//zliczam czas
			m_calculated_energy_full_duration += dt;
			if(m_calculated_energy_full_duration >= m_energy_full_duration)
			{
				m_turbine_state = TURBINE_DEFAULT;	//stan default
				//zeruj� czas
				m_calculated_energy_full_duration = 0.0f;
			}
		}

		if(m_turbine_state == TURBINE_DAMAGE)
		{
			//czekam okre�lony czas na dotarcie servisu,
			//po tym czasie ustawiam stan TURBINE_DEATH
			//to do...
			//serwis...
		}
		if(m_turbine_state == TURBINE_DEATH)
		{
			//czekam okre�lony czas...prepare to delete...
			//po tym czasie ustawiam flag� do usuni�cia
		}

		//dopisa� AI
		//TURBINE_DAMAGE
		//TURBINE_DEATH
		//jakie� warunki:
		//	-	np. wewn�trzna konsumpcja energii
		//	-	jaka� flaga, uszkodzenie turbiny
		//	-	je�li po jakim� czasie uszkodzenie nie zostanie usuni�te
		//		turbina ustawia flag� death (wtedy tylko wyspecjalizowany serwis)

		//diagnostyka
		//std::cout << "Inside Turbine:	"<< m_stored_energy << std::endl;

	}
}//namespace equipment
