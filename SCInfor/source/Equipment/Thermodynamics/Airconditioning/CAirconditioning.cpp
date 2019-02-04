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
	
	//Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
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
		m_unit_controller				(false)//urz�dzenie wy��czone - uruchamia si� z op�nieniem
	{
	}

	//Chroniony konstruktor kopiuj�cy
	CAirconditioning::CAirconditioning(const CAirconditioning &CAirconditioningCopy)
	:
		CActor							(CAirconditioningCopy),//konstruktor kopiuj�cy klasy bazowej
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

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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

	//Metoda zwraca nazw� klimatyzatora
	const std::string CAirconditioning::GetAirconditioningName() const
	{
		return m_airconditioning_name;
	}

	//Metoda ustawia nazw� klimatyzatora
	void CAirconditioning::SetAirconditioningName(const std::string& airconditioning_name)
	{
		m_airconditioning_name = airconditioning_name;
	}

	//Metoda zwraca temperatur�
	const float CAirconditioning::getTemperature () const
	{
		return m_temperature;
	}

	//Metoda ustawia temperatur�
	void CAirconditioning::setTemperature (float temperature)
	{
		m_temperature = temperature;
	}

	//Metoda zwraca temperatur� ustawion� na urz�dzeniu (klimatyzator)
	const float CAirconditioning::getTemperatureSet () const
	{
		return m_temperature_set;
	}

	//Metoda ustawia temperatur� ustawion� na urz�dzeniu (klimatyzator)
	void CAirconditioning::setTemperatureSet (float temperature_set)
	{
		m_temperature_set = temperature_set;
	}

	//Metoda zwraca warto�� zimna klimatyzatora
	const float CAirconditioning::getTemperatureCold() const
	{
		return m_temperature_range.first;
	}

	//Metoda ustawia warto�� zimna klimatyzatora
	void CAirconditioning::setTemperatureCold(float cold)
	{
		m_temperature_range.first = cold;
	}

	//Metoda zwraca warto�� ciep�a klimatyzatora
	const float CAirconditioning::getTemperatureWarm() const
	{
		return m_temperature_range.second;
	}

	//Metoda ustawia warto�� ciep�a klimatyzatora
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

	//Metoda zwraca zu�ycie energii przez klimatyzator
	const float CAirconditioning::getEnergyConsumption() const
	{
		return m_energy_consumption;
	}

	//Metoda ustawia zu�ycie energii przez klimatyzator
	void CAirconditioning::setEnergyConsumption(float energy_consumption)
	{
		m_energy_consumption = energy_consumption;
	}

	//Metoda zwraca zu�ycie paliwa przez klimatyzator
	const float CAirconditioning::getFuelConsumption() const
	{
		return m_fuel_consumption;
	}

	//Metoda ustawia zu�ycie paliwa przez klimatyzator
	void CAirconditioning::setFuelConsumption(float fuel_consumption)
	{
		m_fuel_consumption = fuel_consumption;
	}

	//Metoda zwraca flag�, czy obiekt posiada termoizolator
	const bool CAirconditioning::getUseThermalInsulation() const
	{
		return m_thermal_insulation_data.getUseEquipment();
	}
		
	//Metoda ustawia flag�, czy obiekt posiada termoizolator
	void CAirconditioning::setUseThermalInsulation(bool use_thermal_insulation)
	{
		m_thermal_insulation_data.setUseEquipment(use_thermal_insulation);
	}

	//Metoda zwraca wska�nik na obiekt klasy CThermalInsulation - termoizolator
	CThermalInsulation *CAirconditioning::getThermalInsulation()
	{
		return m_thermal_insulation_data.getThermalInsulation();
	}

	//Metoda ustawia wska�nik na obiekt klasy CThermalInsulation - termoizolator
	void CAirconditioning::setThermalInsulation(CThermalInsulation * thermal_insulation)
	{
		m_thermal_insulation_data.setThermalInsulation(thermal_insulation);
	}

	//Metoda zwraca referencj� na opakowanie danych dla transformacji
	CTransformation & CAirconditioning::getThermalInsulationTransformed()
	{
		return m_thermal_insulation_data.getTransformed();
	}

	//Metoda ustawia referencj� na opakowanie danych dla transformacji
	void CAirconditioning::setThermalInsulationTransformed(CTransformation & transformation)
	{
		m_thermal_insulation_data.setTransformed(transformation);
	}

	//Metoda zwraca referencjc� na modu� sterowania
	CSwitch & CAirconditioning::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
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

	//Wirtualna metoda aktualizuje logik� obiektu
	void CAirconditioning::Update(float dt)
	{
		//aktualizacja shadow engine
		CPhysical::UpdateShadow(dt);

		//aktualizacja po�o�enia wzgl�dem w�a�ciciela
		updateThermalInsulationTransformation(dt);

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy w��czonym urz�dzeniu
		if (m_unit_controller.getState())
		{
			//je�li obiekt posiada termoizolator
			if (m_thermal_insulation_data.getUseEquipment())
			{
				//aktualizacja temperatury modu�u klimatyzatora
				if (m_thermal_insulation_data.getThermalInsulation())
				{
					//temperatura mie�ci si� w zakresie pracy modu�u klimatyzatora (korekta termoizolatora)
					if (TemperatureInRange())
					{
						//je�li temperatura klimatyzatora jest wi�ksza ni� temperatura ustawiona na klimatyzatorze
						if (m_temperature >= m_temperature_set)
							m_temperature -= m_temperature_increment;//sch�adzanie do ustawie� klimatyzatora
						//w przeciwnym wypadku temperatura kliamatyzatora jest mniejsza ni� temperatura ustawiona na klimatyzatorze
						else
							m_temperature += m_temperature_increment;//nagrzewanie do ustawie� klimatyzatora
					}
					//temperatura klimatyzatora jest poza zakresem pracy modu�u klimatyzatora (korekta termoizolatora)
					else
					{
						//je�li temperatura klimatyzatora jest wi�ksza ni� temperatura otoczenia (korekta termoizolatora)
						if (m_temperature >= m_thermal_insulation_data.getThermalInsulation()->getTemperatureAmbient())
							m_temperature -= m_temperature_increment;//sch�adzanie do temperatury otoczenia
						//je�li temperatura klimatyzatora jest mniejsza ni� temperatura otoczenia
						else
							m_temperature += m_temperature_increment;//nagrzewanie do temperatury otoczenia
					}
				}
			}
			//w przeciwnym wypadku temperatura modu�u klimatyzatora to temperatura otoczenia
			else
				m_temperature = gWeather.getTemperature();
		}

		//aktualizuja stanu obiektu - klimatyzatora
		updateAirconditioningState(dt);
	}

	//prywatna metoda aktualizuje stan obiektu - klimatyzator
	void CAirconditioning::updateAirconditioningState(float dt)
	{
		//sch�adzanie
		if (m_temperature >= m_temperature_set)
			m_airconditioning_state = EAirconditioningState::AIRCONDITIONING_COOLING;
		//ogrzewanie
		else
			m_airconditioning_state = EAirconditioningState::AIRCONDITIONING_HEATING;
		
		//temepratura poza zakresem pracy klimatyzatora
		if (!TemperatureInRange())
			m_airconditioning_state = EAirconditioningState::AIRCONDITIONING_INEFFECTIVE;

		//future...docelowo warunek, kt�ry ustawia ten stan
		// EAirconditioningState::AIRCONDITIONING_DAMAGE
	}

	//metoda aktualizuje wska�nik na obiekt CThermalInsulation - po�o�enie wzgl�dem w�a�ciciela
	void CAirconditioning::updateThermalInsulationTransformation(float dt)
	{
		m_thermal_insulation_data.Transform(this, m_thermal_insulation_data.getThermalInsulation());
	}
}//namespace equipment
