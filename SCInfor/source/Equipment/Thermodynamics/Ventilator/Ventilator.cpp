//  ______________________________________
// | Ventilator.cpp - class implementtion |
// | Jack Flower June 2014                |
// |______________________________________|
//

#include "Ventilator.h"
#include "../../../Weather/Weather.h"
#include "../../../Rendering/Animations/AnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Displayable/Displayable.h"
#include "../../../Utilities/MathFunctions/MathFunctions.h"

using namespace weather;
using namespace maths;

namespace equipment
{
	RTTI_IMPL_NOPARENT(Ventilator);

	////Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
	Ventilator::Ventilator(const std::wstring& uniqueId)
	:
		Actor (uniqueId),//konstruktor klasy bazowej
		m_ventilator_name (""),
		m_performance (0.0f),
		m_performance_factor (0.0f),
		m_energy_consumption (0.0f),
		m_energy_consumption_factor	(0.0f),
		m_ventilator_state (EVentilatorState::VENTILATOR_DEFAULT),
		m_unit_controller (false)//urządzenie wyłączone - uruchamia się z opóźnieniem
	{
		//to do: layer
	}

	//Konstruktor kopiujący
	Ventilator::Ventilator(const Ventilator & VentilatorCopy)
	:
		Actor (VentilatorCopy),//konstruktor kopiujący klasy bazowej
		m_ventilator_name (VentilatorCopy.m_ventilator_name),
		m_performance (VentilatorCopy.m_performance),
		m_performance_factor (VentilatorCopy.m_performance_factor),
		m_energy_consumption (VentilatorCopy.m_energy_consumption),
		m_energy_consumption_factor(VentilatorCopy.m_energy_consumption_factor),
		m_ventilator_state (VentilatorCopy.m_ventilator_state),
		m_unit_controller (VentilatorCopy.m_unit_controller)
	{
		//to do: layer
	}

	//Destruktor
	Ventilator::~Ventilator()
	{
		//Actor
		m_ventilator_name = "";
		m_performance = 0.0f;
		m_performance_factor = 0.0f;
		m_energy_consumption = 0.0f;
		m_energy_consumption_factor	= 0.0f;
		m_ventilator_state = EVentilatorState::VENTILATOR_DEFAULT;
		//m_unit_controller
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Ventilator::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca nazwę
	const std::string Ventilator::getVentilatorName() const
	{
		return m_ventilator_name;
	}

	//Metoda ustawia nazwę
	void Ventilator::setVentilatorName(const std::string & ventilator_name)
	{
		m_ventilator_name = ventilator_name;
	}

	//Metoda zwraca wydajność wentylatora
	const float Ventilator::getPerformance() const
	{
		return m_performance;
	}

	//Metoda ustawia wydajność wentylatora
	void Ventilator::setPerformance(float performance)
	{
		m_performance = performance;
	}

	//Metoda zwraca współczynnik wydajności zależny od temperatury otoczenia
	const float Ventilator::getPerformanceFactor() const
	{
		return m_performance_factor;
	}

	//Metoda zwraca współczynnik wydajności zależny od temperatury otoczenia
	void Ventilator::setPerformanceFactor(float performance_factor)
	{
		m_performance_factor = performance_factor;
	}

	//Metoda zwraca zużycie energii przez wentylator
	const float Ventilator::getEnergyConsumption() const
	{
		return m_energy_consumption;
	}

	//Metoda ustawia zużycie energii przez wentylator
	void Ventilator::setEnergyConsumption(float energy_consumption)
	{
		m_energy_consumption = energy_consumption;
	}

	//Metoda zwraca współczynnik zużycia energii wentylatora
	const float Ventilator::getEnergyConsumptionFactor() const
	{
		return m_energy_consumption_factor;
	}

	//Metoda ustawia współczynnik zużycia energii wentylatora
	void Ventilator::setEnergyConsumptionFactor(float energy_consumption_factor)
	{
		m_energy_consumption_factor = energy_consumption_factor;
	}

	//Metoda zwraca referencjcę na moduł sterowania
	Switch & Ventilator::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
	void Ventilator::updateAnimations(float dt)
	{
		switch (m_ventilator_state)
		{
		case EVentilatorState::VENTILATOR_DEFAULT:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getVentilatorBodyDefaultAnim());
				setAnimationHead(p_anim_set->getVentilatorHeadDefaultAnim());
			}
			break;
		}
		case EVentilatorState::VENTILATOR_DAMAGE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getVentilatorBodyDamagetAnim());
				setAnimationHead(p_anim_set->getVentilatorHeadDamagetAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda aktulizuje obiekt
	void Ventilator::update(float dt)
	{
		//jeśli obiekt posiada wentylator, to znaczy, że właściciel tego obiektu,
		//może schładzać/nagrzewać wnętrze poprzez wymuszony ruch powietrza

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy włączonym urządzeniu
		if (m_unit_controller.getState())
		{
			//wyliczenie współczynnika wydajności w zależności od pozycji słońca - temperatury
			m_performance_factor = (gWeather.getSolarEnergyFactor() * m_performance);
			//wyliczenie współczynnika zużycia energii
			m_energy_consumption_factor = maths::Abs(m_performance_factor * m_energy_consumption);
		}

		//aktualizuja stanu obiektu - wentylator
		updateVentilatorState(dt);
	}
	//prywatna metoda aktualizuje stan obiektu - wentylator
	void Ventilator::updateVentilatorState(float dt)
	{
		//aktualizacja tylko przy włączonym urządzeniu
		if (m_unit_controller.getState())
			m_ventilator_state = EVentilatorState::VENTILATOR_DEFAULT;
		else
			m_ventilator_state = EVentilatorState::VENTILATOR_DAMAGE;

	}
}//namespace equipment
