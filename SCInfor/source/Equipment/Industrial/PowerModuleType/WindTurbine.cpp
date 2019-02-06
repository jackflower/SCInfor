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

	//Chroniony konstruktor domyœlny
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

	//Chroniony konstruktor kopiuj¹cy
	WindTurbine::WindTurbine(const WindTurbine & WindTurbineCopy)
	:
		PowerModule(WindTurbineCopy),//konstruktor kopiuj¹cy klasy bazowej
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

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
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

	//Metoda zwraca nazwê turbiny
	const std::string WindTurbine::getTurbineName() const
	{
		return m_turbine_name;
	}

	//Metoda ustawia nazwê turbiny
	void WindTurbine::setTurbineName(const std::string& turbine_name)
	{
		m_turbine_name = turbine_name;
	}

	//Metoda zwraca prêdkoœæ wirowania turbiny
	const float WindTurbine::getSpeedRotor() const
	{
		return m_speed_rotor;
	}

	//Metoda ustawia prêdkoœæ wirowania turbiny
	void WindTurbine::setSpeedRotor(float speed_rotor)
	{
		m_speed_rotor = speed_rotor;
	}

	//Metoda zwraca prze³o¿enie prêdkoœci obrotowej
	const float WindTurbine::getSpeedTransmission() const
	{
		return m_speed_transmission;
	}

	//Metoda ustawia prze³o¿enie prêdkoœci obrotowej
	void WindTurbine::setSpeedTransmission(float speed_transmission)
	{
		if(speed_transmission <= 0) return;
		m_speed_transmission = speed_transmission;
	}

	//Metoda zwraca procentowy wspó³czynnik aktywacji turbiny
	const float WindTurbine::getPercentageActivation() const
	{
		return m_percentage_activation;
	}

	//Metoda ustawia procentowy wspó³czynnik aktywacji turbiny
	void WindTurbine::setPercentageActivation(float percentage_activation)
	{
		m_percentage_activation = percentage_activation;
	}

	//Metoda zwraca czas trwania stanu, po zgromadzeniu pe³nej energii
	const float WindTurbine::getEnergyFuelDuration() const
	{
		return m_energy_full_duration;
	}

	//Metoda ustawia czas trwania stanu, po zgromadzeniu pe³nej energii
	void WindTurbine::setEnergyFuelDuration(float energy_full_duration)
	{
		m_energy_full_duration = energy_full_duration;
	}

	//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
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

				//animacja head odtwarza siê w pêtli
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
				
				//animacja head odtwarza siê jeden raz
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

				//animacja head odtwarza siê jeden raz
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
				//animacja head odtwarza siê w pêtli
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

				//animacja head odtwarza siê w pêtli
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

				//animacja head odtwarza siê w pêtli
				GetDisplayableHead()->GetAnimationState()->SetLooped(true);
				GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
			}
			break;
		}
		default:
			break;
		}
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void WindTurbine::update(float dt)
	{
		CPhysical::UpdateShadow(dt);	//aktualizacja shadow engine

		//jeœli urz¹dzenie jest w³¹czone
		if(m_unit_controller.getState())
		{
			updateTurbineState(dt);
			updateAnimations(dt);
		}
	}

	//prywatna metoda aktualizuje stan obiektu
	void WindTurbine::updateTurbineState(float dt)
	{
		//proces przebiega - turbina gromadzi energiê
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
				//po zakoñczeniu odtworzania jednego cyklu animacji otwierania luku - zmiana stanu
				if(m_cargo_open_duration >= GetAnimationHead()->TotalLength())
				{
					//obliczam prêdkoœæ ³opatek turniny
					m_calculated_speed_rotor = m_speed_rotor * m_speed_transmission * gWeather.GetWindSpeed() * dt;
					//zmiana stanu - aktualizacja energii
					m_turbine_state = TURBINE_UPDATE_ENERGY;
					//zerujê czas
					m_cargo_open_duration = 0.0f;
				}
			}
			if(m_turbine_state == TURBINE_UPDATE_ENERGY)
			{
				//w³¹czam obracanie ³opatek turbiny
				SetRotationBody(GetRotationBody() + m_calculated_speed_rotor);
				if(GetRotationBody() > FULL_ROTATION)//wykonano pe³ny obrót ³opatek turbiny
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
				//po zakoñczeniu odtworzenia jednego cyklu animacji zamykania luku - zmiana stanu
				if(m_cargo_close_duration >= GetAnimationHead()->TotalLength())
				{
					//zmiana stanu - odnowienie procesu aktualizacji energii
					m_turbine_state = TURBINE_DEFAULT;
					//zerujê czas
					m_cargo_close_duration = 0.0f;
				}
			}
		}

		//turbina zgromadzi³a energiê - jej stan musi przejœæ do TURBINE_DEFAULT
		if(m_stored_energy >= m_energy_capacitor && m_turbine_state != TURBINE_DEFAULT)
		{
			//zliczam czas
			m_calculated_energy_full_duration += dt;
			if(m_calculated_energy_full_duration >= m_energy_full_duration)
			{
				m_turbine_state = TURBINE_CARGO_DOOR_CLOSE;
				//zerujê czas
				m_calculated_energy_full_duration = 0.0f;
			}
		}

		//turbina zgromadzi³a energiê i luk cargo zosta³ zamkniêty - wymuszam TURBINE_DEFAULT
		if(m_stored_energy >= m_energy_capacitor && m_turbine_state == TURBINE_CARGO_DOOR_CLOSE)
		{
			//zliczam czas
			m_calculated_energy_full_duration += dt;
			if(m_calculated_energy_full_duration >= m_energy_full_duration)
			{
				m_turbine_state = TURBINE_DEFAULT;	//stan default
				//zerujê czas
				m_calculated_energy_full_duration = 0.0f;
			}
		}

		if(m_turbine_state == TURBINE_DAMAGE)
		{
			//czekam okreœlony czas na dotarcie servisu,
			//po tym czasie ustawiam stan TURBINE_DEATH
			//to do...
			//serwis...
		}
		if(m_turbine_state == TURBINE_DEATH)
		{
			//czekam okreœlony czas...prepare to delete...
			//po tym czasie ustawiam flagê do usuniêcia
		}

		//dopisaæ AI
		//TURBINE_DAMAGE
		//TURBINE_DEATH
		//jakieœ warunki:
		//	-	np. wewnêtrzna konsumpcja energii
		//	-	jakaœ flaga, uszkodzenie turbiny
		//	-	jeœli po jakimœ czasie uszkodzenie nie zostanie usuniête
		//		turbina ustawia flagê death (wtedy tylko wyspecjalizowany serwis)

		//diagnostyka
		//std::cout << "Inside Turbine:	"<< m_stored_energy << std::endl;

	}
}//namespace equipment
