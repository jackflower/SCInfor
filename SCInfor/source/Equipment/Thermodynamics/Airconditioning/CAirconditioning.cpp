//  _____________________________________________
// | CAirconditioning.cpp - class implementation |
// | Jack Flower June 2014                       |
// |_____________________________________________|
//

#include "CAirconditioning.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Displayable/CDisplayable.h"

using namespace weather;
using namespace rendering::displayable;

namespace equipment
{
	RTTI_IMPL(CAirconditioning, CActor);
	
	//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
	CAirconditioning::CAirconditioning(const std::wstring& uniqueId)
	:
		CActor							(uniqueId),//konstruktor klasy bazowej
		m_temperature					(0.0f),
		m_temperature_set				(0.0f),
		m_temperature_range				(0.0f, 0.0f),
		m_temperature_increment			(0.0f),
		m_energy_consumption			(0.0f),
		m_fuel_consumption				(0.0f),
		m_thermal_insulation_data		(),
		m_airconditioning_state			(EAirconditioningState::AIRCONDITIONING_DEFAULT),
		m_unit_controller				(false)//urz¹dzenie wy³¹czone - uruchamia siê z opóŸnieniem
	{
	}

	//Chroniony konstruktor kopiuj¹cy
	CAirconditioning::CAirconditioning(const CAirconditioning &CAirconditioningCopy)
	:
		CActor							(CAirconditioningCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_temperature					(CAirconditioningCopy.m_temperature),
		m_temperature_set				(CAirconditioningCopy.m_temperature_set),
		m_temperature_range				(CAirconditioningCopy.m_temperature_range),
		m_temperature_increment			(CAirconditioningCopy.m_temperature_increment),
		m_energy_consumption			(CAirconditioningCopy.m_energy_consumption),
		m_fuel_consumption				(CAirconditioningCopy.m_fuel_consumption),
		m_thermal_insulation_data		(CAirconditioningCopy.m_thermal_insulation_data),
		m_airconditioning_state			(CAirconditioningCopy.m_airconditioning_state),
		m_unit_controller				(CAirconditioningCopy.m_unit_controller)
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
	CAirconditioning::~CAirconditioning(void)
	{
		//CActor						not edit
		m_temperature					= 0.0f;
		m_temperature_set				= 0.0f;
		m_temperature_range.first		= 0.0f;
		m_temperature_range.second		= 0.0f;
		m_temperature_increment			= 0.0f;
		m_energy_consumption			= 0.0f;
		m_fuel_consumption				= 0.0f;
		//m_thermal_insulation_data		not edit
		m_airconditioning_state			= EAirconditioningState::AIRCONDITIONING_DEFAULT;
		//m_unit_controller				not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CAirconditioning::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwê klimatyzatora
	const std::string CAirconditioning::GetAirconditioningName() const
	{
		return m_airconditioning_name;
	}

	//Metoda ustawia nazwê klimatyzatora
	void CAirconditioning::SetAirconditioningName(const std::string& airconditioning_name)
	{
		m_airconditioning_name = airconditioning_name;
	}

	//Metoda zwraca temperaturê
	const float CAirconditioning::getTemperature () const
	{
		return m_temperature;
	}

	//Metoda ustawia temperaturê
	void CAirconditioning::setTemperature (float temperature)
	{
		m_temperature = temperature;
	}

	//Metoda zwraca temperaturê ustawion¹ na urz¹dzeniu (klimatyzator)
	const float CAirconditioning::getTemperatureSet () const
	{
		return m_temperature_set;
	}

	//Metoda ustawia temperaturê ustawion¹ na urz¹dzeniu (klimatyzator)
	void CAirconditioning::setTemperatureSet (float temperature_set)
	{
		m_temperature_set = temperature_set;
	}

	//Metoda zwraca wartoœæ zimna klimatyzatora
	const float CAirconditioning::getTemperatureCold() const
	{
		return m_temperature_range.first;
	}

	//Metoda ustawia wartoœæ zimna klimatyzatora
	void CAirconditioning::setTemperatureCold(float cold)
	{
		m_temperature_range.first = cold;
	}

	//Metoda zwraca wartoœæ ciep³a klimatyzatora
	const float CAirconditioning::getTemperatureWarm() const
	{
		return m_temperature_range.second;
	}

	//Metoda ustawia wartoœæ ciep³a klimatyzatora
	void CAirconditioning::setTemperatureWarm(float warm)
	{
		m_temperature_range.second = warm;
	}

	//Metoda zwraca przyrost temperatury - cykl - dynammika
	const float CAirconditioning::getTemperatureIncrement() const
	{
		return m_temperature_increment;
	}

	//Metoda ustawia przyrost temperatury - cykl - dynammika
	void CAirconditioning::setTemperatureIncrement(float temperature_increment)
	{
		m_temperature_increment = temperature_increment;
	}

	//Metoda zwraca zu¿ycie energii przez klimatyzator
	const float CAirconditioning::getEnergyConsumption() const
	{
		return m_energy_consumption;
	}

	//Metoda ustawia zu¿ycie energii przez klimatyzator
	void CAirconditioning::setEnergyConsumption(float energy_consumption)
	{
		m_energy_consumption = energy_consumption;
	}

	//Metoda zwraca zu¿ycie paliwa przez klimatyzator
	const float CAirconditioning::getFuelConsumption() const
	{
		return m_fuel_consumption;
	}

	//Metoda ustawia zu¿ycie paliwa przez klimatyzator
	void CAirconditioning::setFuelConsumption(float fuel_consumption)
	{
		m_fuel_consumption = fuel_consumption;
	}

	//Metoda zwraca flagê, czy obiekt posiada termoizolator
	const bool CAirconditioning::getUseThermalInsulation() const
	{
		return m_thermal_insulation_data.getUseEquipment();
	}
		
	//Metoda ustawia flagê, czy obiekt posiada termoizolator
	void CAirconditioning::setUseThermalInsulation(bool use_thermal_insulation)
	{
		m_thermal_insulation_data.setUseEquipment(use_thermal_insulation);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CThermalInsulation - termoizolator
	CThermalInsulation *CAirconditioning::getThermalInsulation()
	{
		return m_thermal_insulation_data.getThermalInsulation();
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CThermalInsulation - termoizolator
	void CAirconditioning::setThermalInsulation(CThermalInsulation * thermal_insulation)
	{
		m_thermal_insulation_data.setThermalInsulation(thermal_insulation);
	}

	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & CAirconditioning::getThermalInsulationTransformed()
	{
		return m_thermal_insulation_data.getTransformed();
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void CAirconditioning::setThermalInsulationTransformed(CTransformation & transformation)
	{
		m_thermal_insulation_data.setTransformed(transformation);
	}

	//Metoda zwraca referencjcê na modu³ sterowania
	CSwitch & CAirconditioning::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
	void CAirconditioning::updateAnimations(float dt)
	{
		switch (m_airconditioning_state)
		{
		case EAirconditioningState::AIRCONDITIONING_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetAirconditioningBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetAirconditioningHeadDefaultAnim());
			}
			break;
		}
		case EAirconditioningState::AIRCONDITIONING_HEATING:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetAirconditioningBodyHeatingtAnim());
				SetAnimationHead(p_anim_set->GetAirconditioningHeadHeatingtAnim());
			}
			break;
		}
		case EAirconditioningState::AIRCONDITIONING_COOLING:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetAirconditioningBodyCoolingAnim());
				SetAnimationHead(p_anim_set->GetAirconditioningHeadCoolingAnim());
			}
			break;
		}
		case EAirconditioningState::AIRCONDITIONING_INEFFECTIVE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetAirconditioningBodyIneffectiveAnim());
				SetAnimationHead(p_anim_set->GetAirconditioningHeadIneffectiveAnim());
			}
			break;
		}
		case EAirconditioningState::AIRCONDITIONING_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetAirconditioningBodyDamageAnim());
				SetAnimationHead(p_anim_set->GetAirconditioningHeadDamageAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Wirtualna metoda aktualizuje logikê obiektu
	void CAirconditioning::Update(float dt)
	{
		//aktualizacja shadow engine
		CPhysical::UpdateShadow(dt);

		//aktualizacja po³o¿enia wzglêdem w³aœciciela
		updateThermalInsulationTransformation(dt);

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy w³¹czonym urz¹dzeniu
		if (m_unit_controller.getState())
		{
			//jeœli obiekt posiada termoizolator
			if (m_thermal_insulation_data.getUseEquipment())
			{
				//aktualizacja temperatury modu³u klimatyzatora
				if (m_thermal_insulation_data.getThermalInsulation())
				{
					//temperatura mieœci siê w zakresie pracy modu³u klimatyzatora (korekta termoizolatora)
					if (TemperatureInRange())
					{
						//jeœli temperatura klimatyzatora jest wiêksza ni¿ temperatura ustawiona na klimatyzatorze
						if (m_temperature >= m_temperature_set)
							m_temperature -= m_temperature_increment;//sch³adzanie do ustawieñ klimatyzatora
						//w przeciwnym wypadku temperatura kliamatyzatora jest mniejsza ni¿ temperatura ustawiona na klimatyzatorze
						else
							m_temperature += m_temperature_increment;//nagrzewanie do ustawieñ klimatyzatora
					}
					//temperatura klimatyzatora jest poza zakresem pracy modu³u klimatyzatora (korekta termoizolatora)
					else
					{
						//jeœli temperatura klimatyzatora jest wiêksza ni¿ temperatura otoczenia (korekta termoizolatora)
						if (m_temperature >= m_thermal_insulation_data.getThermalInsulation()->getTemperatureAmbient())
							m_temperature -= m_temperature_increment;//sch³adzanie do temperatury otoczenia
						//jeœli temperatura klimatyzatora jest mniejsza ni¿ temperatura otoczenia
						else
							m_temperature += m_temperature_increment;//nagrzewanie do temperatury otoczenia
					}
				}
			}
			//w przeciwnym wypadku temperatura modu³u klimatyzatora to temperatura otoczenia
			else
				m_temperature = gWeather.getTemperature();
		}

		//aktualizuja stanu obiektu - klimatyzatora
		updateAirconditioningState(dt);
	}

	//prywatna metoda aktualizuje stan obiektu - klimatyzator
	void CAirconditioning::updateAirconditioningState(float dt)
	{
		//sch³adzanie
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

	//metoda aktualizuje wskaŸnik na obiekt CThermalInsulation - po³o¿enie wzglêdem w³aœciciela
	void CAirconditioning::updateThermalInsulationTransformation(float dt)
	{
		m_thermal_insulation_data.Transform(this, m_thermal_insulation_data.getThermalInsulation());
	}
}//namespace equipment
