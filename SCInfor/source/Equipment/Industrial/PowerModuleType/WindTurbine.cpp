//  ________________________________________
// | WindTurbine.cpp - class implementation |
// | Jack Flower - July 2014                |
// |________________________________________|
//

#include "WindTurbine.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/AnimSet.h"
#include "../../../Rendering/Animations/Animation.h"
#include "../../../Rendering/Animations/AnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../../Rendering/Drawable/Layers.h"
#include <iostream>

using namespace weather;
using namespace rendering::drawable;

namespace equipment
{
	RTTI_IMPL(WindTurbine, PowerModule);

	//Chroniony konstruktor domyślny
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
		setZIndexBody(Z_PHYSICAL_SHADOW_WIND_TURBINE_BODY);
		setZIndexShadowBody(Z_PHYSICAL_WIND_TURBINE_BODY);
		setZIndexHead(Z_PHYSICAL_SHADOW_WIND_TURBINE_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_WIND_TURBINE_HEAD);
	}

	//Chroniony konstruktor kopiujący
	WindTurbine::WindTurbine(const WindTurbine & WindTurbineCopy)
	:
		PowerModule(WindTurbineCopy),//konstruktor kopiujący klasy bazowej
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
		setZIndexBody(Z_PHYSICAL_SHADOW_WIND_TURBINE_BODY);
		setZIndexShadowBody(Z_PHYSICAL_WIND_TURBINE_BODY);
		setZIndexHead(Z_PHYSICAL_SHADOW_WIND_TURBINE_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_WIND_TURBINE_HEAD);
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
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

	//Metoda zwraca nazwę turbiny
	const std::string WindTurbine::getTurbineName() const
	{
		return m_turbine_name;
	}

	//Metoda ustawia nazwę turbiny
	void WindTurbine::setTurbineName(const std::string& turbine_name)
	{
		m_turbine_name = turbine_name;
	}

	//Metoda zwraca prędkość wirowania turbiny
	const float WindTurbine::getSpeedRotor() const
	{
		return m_speed_rotor;
	}

	//Metoda ustawia prędkość wirowania turbiny
	void WindTurbine::setSpeedRotor(float speed_rotor)
	{
		m_speed_rotor = speed_rotor;
	}

	//Metoda zwraca przełożenie prędkości obrotowej
	const float WindTurbine::getSpeedTransmission() const
	{
		return m_speed_transmission;
	}

	//Metoda ustawia przełożenie prędkości obrotowej
	void WindTurbine::setSpeedTransmission(float speed_transmission)
	{
		if(speed_transmission <= 0) return;
		m_speed_transmission = speed_transmission;
	}

	//Metoda zwraca procentowy współczynnik aktywacji turbiny
	const float WindTurbine::getPercentageActivation() const
	{
		return m_percentage_activation;
	}

	//Metoda ustawia procentowy współczynnik aktywacji turbiny
	void WindTurbine::setPercentageActivation(float percentage_activation)
	{
		m_percentage_activation = percentage_activation;
	}

	//Metoda zwraca czas trwania stanu, po zgromadzeniu pełnej energii
	const float WindTurbine::getEnergyFuelDuration() const
	{
		return m_energy_full_duration;
	}

	//Metoda ustawia czas trwania stanu, po zgromadzeniu pełnej energii
	void WindTurbine::setEnergyFuelDuration(float energy_full_duration)
	{
		m_energy_full_duration = energy_full_duration;
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
	void WindTurbine::updateAnimations(float dt)
	{
		switch(m_turbine_state)
		{
		case TURBINE_DEFAULT:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getWindTurbineBodyDefaultAnim());
				setAnimationHead(p_anim_set->getWindTurbineHeadDefaultAnim());

				//animacja head odtwarza się w pętli
				getDisplayableHead()->GetAnimationState()->setLooped(true);
				getDisplayableHeadShadow()->GetAnimationState()->setLooped(true);
			}
			break;
		}
		case TURBINE_CARGO_DOOR_OPEN:
		{
			if (p_anim_set)
			{
				//SetAnimationBody(p_anim_set->getWindTurbineBodyDefaultAnim());
				setAnimationHead(p_anim_set->getWindTurbineHeadCargoOpenAnim());
				
				//animacja head odtwarza się jeden raz
				getDisplayableHead()->GetAnimationState()->setLooped(false);
				getDisplayableHeadShadow()->GetAnimationState()->setLooped(false);
			}
			break;
		}
		case TURBINE_CARGO_DOOR_CLOSE:
		{
			if (p_anim_set)
			{
				//SetAnimationBody(p_anim_set->getWindTurbineBodyDefaultAnim());
				setAnimationHead(p_anim_set->getWindTurbineHeadCargoCloseAnim());

				//animacja head odtwarza się jeden raz
				getDisplayableHead()->GetAnimationState()->setLooped(false);
				getDisplayableHeadShadow()->GetAnimationState()->setLooped(false);
			}
			break;
		}
		case TURBINE_UPDATE_ENERGY:
		{
			if (p_anim_set)
			{
				//SetAnimationBody(p_anim_set->getWindTurbineBodyDefaultAnim());
				setAnimationHead(p_anim_set->getWindTurbineHeadUpdateEnergyAnim());
				//animacja head odtwarza się w pętli
				getDisplayableHead()->GetAnimationState()->setLooped(true);
				getDisplayableHeadShadow()->GetAnimationState()->setLooped(true);
			}
			break;
		}
		case TURBINE_DAMAGE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getWindTurbineBodyDamagetAnim());
				setAnimationHead(p_anim_set->getWindTurbineHeadDamagetAnim());

				//animacja head odtwarza się w pętli
				getDisplayableHead()->GetAnimationState()->setLooped(true);
				getDisplayableHeadShadow()->GetAnimationState()->setLooped(true);
			}
			break;
		}
		case TURBINE_DEATH:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getWindTurbineBodyDeathAnim());
				setAnimationHead(p_anim_set->getWindTurbineHeadDeathAnim());

				//animacja head odtwarza się w pętli
				getDisplayableHead()->GetAnimationState()->setLooped(true);
				getDisplayableHeadShadow()->GetAnimationState()->setLooped(true);
			}
			break;
		}
		default:
			break;
		}
	}

	//Wirtualna metoda aktualizująca obiekt
	void WindTurbine::update(float dt)
	{
		Physical::updateShadow(dt);	//aktualizacja shadow engine

		//jeśli urządzenie jest włączone
		if(m_unit_controller.getState())
		{
			updateTurbineState(dt);
			updateAnimations(dt);
		}
	}

	//prywatna metoda aktualizuje stan obiektu
	void WindTurbine::updateTurbineState(float dt)
	{
		//proces przebiega - turbina gromadzi energię
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
				//po zakończeniu odtworzania jednego cyklu animacji otwierania luku - zmiana stanu
				if(m_cargo_open_duration >= getAnimationHead()->totalLength())
				{
					//obliczam prędkość łopatek turniny
					m_calculated_speed_rotor = m_speed_rotor * m_speed_transmission * gWeather.GetWindSpeed() * dt;
					//zmiana stanu - aktualizacja energii
					m_turbine_state = TURBINE_UPDATE_ENERGY;
					//zeruję czas
					m_cargo_open_duration = 0.0f;
				}
			}
			if(m_turbine_state == TURBINE_UPDATE_ENERGY)
			{
				//włączam obracanie łopatek turbiny
				setRotationBody(getRotationBody() + m_calculated_speed_rotor);
				if(getRotationBody() > FULL_ROTATION)//wykonano pełny obrót łopatek turbiny
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
				//po zakończeniu odtworzenia jednego cyklu animacji zamykania luku - zmiana stanu
				if(m_cargo_close_duration >= getAnimationHead()->totalLength())
				{
					//zmiana stanu - odnowienie procesu aktualizacji energii
					m_turbine_state = TURBINE_DEFAULT;
					//zeruję czas
					m_cargo_close_duration = 0.0f;
				}
			}
		}

		//turbina zgromadziła energię - jej stan musi przejść do TURBINE_DEFAULT
		if(m_stored_energy >= m_energy_capacitor && m_turbine_state != TURBINE_DEFAULT)
		{
			//zliczam czas
			m_calculated_energy_full_duration += dt;
			if(m_calculated_energy_full_duration >= m_energy_full_duration)
			{
				m_turbine_state = TURBINE_CARGO_DOOR_CLOSE;
				//zeruję czas
				m_calculated_energy_full_duration = 0.0f;
			}
		}

		//turbina zgromadziła energię i luk cargo został zamknięty - wymuszam TURBINE_DEFAULT
		if(m_stored_energy >= m_energy_capacitor && m_turbine_state == TURBINE_CARGO_DOOR_CLOSE)
		{
			//zliczam czas
			m_calculated_energy_full_duration += dt;
			if(m_calculated_energy_full_duration >= m_energy_full_duration)
			{
				m_turbine_state = TURBINE_DEFAULT;	//stan default
				//zeruję czas
				m_calculated_energy_full_duration = 0.0f;
			}
		}

		if(m_turbine_state == TURBINE_DAMAGE)
		{
			//czekam określony czas na dotarcie servisu,
			//po tym czasie ustawiam stan TURBINE_DEATH
			//to do...
			//serwis...
		}
		if(m_turbine_state == TURBINE_DEATH)
		{
			//czekam określony czas...prepare to delete...
			//po tym czasie ustawiam flagę do usunięcia
		}

		//dopisać AI
		//TURBINE_DAMAGE
		//TURBINE_DEATH
		//jakieś warunki:
		//	-	np. wewnętrzna konsumpcja energii
		//	-	jakaś flaga, uszkodzenie turbiny
		//	-	jeśli po jakimś czasie uszkodzenie nie zostanie usunięte
		//		turbina ustawia flagę death (wtedy tylko wyspecjalizowany serwis)

		//diagnostyka
		//std::cout << "Inside Turbine:	"<< m_stored_energy << std::endl;

	}
}//namespace equipment
