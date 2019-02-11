//  ____________________________________________
// | Airconditioning.cpp - class implementation |
// | Jack Flower June 2014                      |
// |____________________________________________|
//

#include "Airconditioning.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Displayable/CDisplayable.h"

using namespace weather;
using namespace rendering::displayable;

namespace equipment
{
	RTTI_IMPL(Airconditioning, Actor);
	
	//Chroniony konstruktor domyślny - używany wyłącznie przez CPhysicalManager
	Airconditioning::Airconditioning(const std::wstring & uniqueId)
	:
		Actor(uniqueId),//konstruktor klasy bazowej
		m_temperature(0.0f),
		m_temperature_set(0.0f),
		m_temperature_range(0.0f, 0.0f),
		m_temperature_increment(0.0f),
		m_energy_consumption(0.0f),
		m_fuel_consumption(0.0f),
		m_thermal_insulation_data(),
		m_airconditioning_state(EAirconditioningState::AIRCONDITIONING_DEFAULT),
		m_unit_controller(false)//urządzenie wyłączone - uruchamia się z opóźnieniem
	{
		//to do: layers
	}

	//Chroniony konstruktor kopiujący
	Airconditioning::Airconditioning(const Airconditioning & AirconditioningCopy)
	:
		Actor(AirconditioningCopy),//konstruktor kopiujący klasy bazowej
		m_temperature(AirconditioningCopy.m_temperature),
		m_temperature_set(AirconditioningCopy.m_temperature_set),
		m_temperature_range(AirconditioningCopy.m_temperature_range),
		m_temperature_increment(AirconditioningCopy.m_temperature_increment),
		m_energy_consumption(AirconditioningCopy.m_energy_consumption),
		m_fuel_consumption(AirconditioningCopy.m_fuel_consumption),
		m_thermal_insulation_data(AirconditioningCopy.m_thermal_insulation_data),
		m_airconditioning_state(AirconditioningCopy.m_airconditioning_state),
		m_unit_controller(AirconditioningCopy.m_unit_controller)
	{
		//to do: layers
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
	Airconditioning::~Airconditioning(void)
	{
		//Actor
		m_temperature = 0.0f;
		m_temperature_set = 0.0f;
		m_temperature_range.first = 0.0f;
		m_temperature_range.second = 0.0f;
		m_temperature_increment = 0.0f;
		m_energy_consumption = 0.0f;
		m_fuel_consumption = 0.0f;
		//m_thermal_insulation_data
		m_airconditioning_state = EAirconditioningState::AIRCONDITIONING_DEFAULT;
		//m_unit_controller
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Airconditioning::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwę klimatyzatora
	const std::string Airconditioning::getAirconditioningName() const
	{
		return m_airconditioning_name;
	}

	//Metoda ustawia nazwę klimatyzatora
	void Airconditioning::setAirconditioningName(const std::string& airconditioning_name)
	{
		m_airconditioning_name = airconditioning_name;
	}

	//Metoda zwraca temperaturę
	const float Airconditioning::getTemperature () const
	{
		return m_temperature;
	}

	//Metoda ustawia temperaturę
	void Airconditioning::setTemperature (float temperature)
	{
		m_temperature = temperature;
	}

	//Metoda zwraca temperaturę ustawioną na urządzeniu (klimatyzator)
	const float Airconditioning::getTemperatureSet () const
	{
		return m_temperature_set;
	}

	//Metoda ustawia temperaturę ustawioną na urządzeniu (klimatyzator)
	void Airconditioning::setTemperatureSet (float temperature_set)
	{
		m_temperature_set = temperature_set;
	}

	//Metoda zwraca wartość zimna klimatyzatora
	const float Airconditioning::getTemperatureCold() const
	{
		return m_temperature_range.first;
	}

	//Metoda ustawia wartość zimna klimatyzatora
	void Airconditioning::setTemperatureCold(float cold)
	{
		m_temperature_range.first = cold;
	}

	//Metoda zwraca wartość ciepła klimatyzatora
	const float Airconditioning::getTemperatureWarm() const
	{
		return m_temperature_range.second;
	}

	//Metoda ustawia wartość ciepła klimatyzatora
	void Airconditioning::setTemperatureWarm(float warm)
	{
		m_temperature_range.second = warm;
	}

	//Metoda zwraca przyrost temperatury - cykl - dynammika
	const float Airconditioning::getTemperatureIncrement() const
	{
		return m_temperature_increment;
	}

	//Metoda ustawia przyrost temperatury - cykl - dynammika
	void Airconditioning::setTemperatureIncrement(float temperature_increment)
	{
		m_temperature_increment = temperature_increment;
	}

	//Metoda zwraca zużycie energii przez klimatyzator
	const float Airconditioning::getEnergyConsumption() const
	{
		return m_energy_consumption;
	}

	//Metoda ustawia zużycie energii przez klimatyzator
	void Airconditioning::setEnergyConsumption(float energy_consumption)
	{
		m_energy_consumption = energy_consumption;
	}

	//Metoda zwraca zużycie paliwa przez klimatyzator
	const float Airconditioning::getFuelConsumption() const
	{
		return m_fuel_consumption;
	}

	//Metoda ustawia zużycie paliwa przez klimatyzator
	void Airconditioning::setFuelConsumption(float fuel_consumption)
	{
		m_fuel_consumption = fuel_consumption;
	}

	//Metoda zwraca flagę, czy obiekt posiada termoizolator
	const bool Airconditioning::getUseThermalInsulation() const
	{
		return m_thermal_insulation_data.getUseEquipment();
	}
		
	//Metoda ustawia flagę, czy obiekt posiada termoizolator
	void Airconditioning::setUseThermalInsulation(bool use_thermal_insulation)
	{
		m_thermal_insulation_data.setUseEquipment(use_thermal_insulation);
	}

	//Metoda zwraca wskaźnik na obiekt klasy ThermalInsulation - termoizolator
	ThermalInsulation *Airconditioning::getThermalInsulation()
	{
		return m_thermal_insulation_data.getThermalInsulation();
	}

	//Metoda ustawia wskaźnik na obiekt klasy ThermalInsulation - termoizolator
	void Airconditioning::setThermalInsulation(ThermalInsulation * thermal_insulation)
	{
		m_thermal_insulation_data.setThermalInsulation(thermal_insulation);
	}

	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & Airconditioning::getThermalInsulationTransformed()
	{
		return m_thermal_insulation_data.getTransformed();
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void Airconditioning::setThermalInsulationTransformed(CTransformation & transformation)
	{
		m_thermal_insulation_data.setTransformed(transformation);
	}

	//Metoda zwraca referencjcę na moduł sterowania
	Switch & Airconditioning::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
	void Airconditioning::updateAnimations(float dt)
	{
		switch (m_airconditioning_state)
		{
		case EAirconditioningState::AIRCONDITIONING_DEFAULT:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetAirconditioningBodyDefaultAnim());
				setAnimationHead(p_anim_set->GetAirconditioningHeadDefaultAnim());
			}
			break;
		}
		case EAirconditioningState::AIRCONDITIONING_HEATING:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetAirconditioningBodyHeatingtAnim());
				setAnimationHead(p_anim_set->GetAirconditioningHeadHeatingtAnim());
			}
			break;
		}
		case EAirconditioningState::AIRCONDITIONING_COOLING:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetAirconditioningBodyCoolingAnim());
				setAnimationHead(p_anim_set->GetAirconditioningHeadCoolingAnim());
			}
			break;
		}
		case EAirconditioningState::AIRCONDITIONING_INEFFECTIVE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetAirconditioningBodyIneffectiveAnim());
				setAnimationHead(p_anim_set->GetAirconditioningHeadIneffectiveAnim());
			}
			break;
		}
		case EAirconditioningState::AIRCONDITIONING_DAMAGE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetAirconditioningBodyDamageAnim());
				setAnimationHead(p_anim_set->GetAirconditioningHeadDamageAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	void Airconditioning::update(float dt)
	{
		//aktualizacja shadow engine
		Physical::updateShadow(dt);

		//aktualizacja położenia względem właściciela
		updateThermalInsulationTransformation(dt);

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy włączonym urządzeniu
		if (m_unit_controller.getState())
		{
			//jeśli obiekt posiada termoizolator
			if (m_thermal_insulation_data.getUseEquipment())
			{
				//aktualizacja temperatury modułu klimatyzatora
				if (m_thermal_insulation_data.getThermalInsulation())
				{
					//temperatura mieści się w zakresie pracy modułu klimatyzatora (korekta termoizolatora)
					if (TemperatureInRange())
					{
						//jeśli temperatura klimatyzatora jest większa niż temperatura ustawiona na klimatyzatorze
						if (m_temperature >= m_temperature_set)
							m_temperature -= m_temperature_increment;//schładzanie do ustawień klimatyzatora
						//w przeciwnym wypadku temperatura kliamatyzatora jest mniejsza niż temperatura ustawiona na klimatyzatorze
						else
							m_temperature += m_temperature_increment;//nagrzewanie do ustawień klimatyzatora
					}
					//temperatura klimatyzatora jest poza zakresem pracy modułu klimatyzatora (korekta termoizolatora)
					else
					{
						//jeśli temperatura klimatyzatora jest większa niż temperatura otoczenia (korekta termoizolatora)
						if (m_temperature >= m_thermal_insulation_data.getThermalInsulation()->getTemperatureAmbient())
							m_temperature -= m_temperature_increment;//schładzanie do temperatury otoczenia
						//jeśli temperatura klimatyzatora jest mniejsza niż temperatura otoczenia
						else
							m_temperature += m_temperature_increment;//nagrzewanie do temperatury otoczenia
					}
				}
			}
			//w przeciwnym wypadku temperatura modułu klimatyzatora to temperatura otoczenia
			else
				m_temperature = gWeather.getTemperature();
		}

		//aktualizuja stanu obiektu - klimatyzatora
		updateAirconditioningState(dt);
	}

	//prywatna metoda aktualizuje stan obiektu - klimatyzator
	void Airconditioning::updateAirconditioningState(float dt)
	{
		//schładzanie
		if (m_temperature >= m_temperature_set)
			m_airconditioning_state = EAirconditioningState::AIRCONDITIONING_COOLING;
		//ogrzewanie
		else
			m_airconditioning_state = EAirconditioningState::AIRCONDITIONING_HEATING;
		
		//temepratura poza zakresem pracy klimatyzatora
		if (!TemperatureInRange())
			m_airconditioning_state = EAirconditioningState::AIRCONDITIONING_INEFFECTIVE;

		//future...docelowo warunek, który ustawia ten stan
		// EAirconditioningState::AIRCONDITIONING_DAMAGE
	}

	//metoda aktualizuje wskaźnik na obiekt ThermalInsulation - położenie względem właściciela
	void Airconditioning::updateThermalInsulationTransformation(float dt)
	{
		m_thermal_insulation_data.Transform(this, m_thermal_insulation_data.getThermalInsulation());
	}
}//namespace equipment
