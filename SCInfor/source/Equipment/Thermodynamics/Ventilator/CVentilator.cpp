//  _______________________________________
// | CVentilator.cpp - class implementtion |
// | Jack Flower June 2014                 |
// |_______________________________________|
//

#include "CVentilator.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../../Utilities/MathFunctions/MathFunctions.h"

using namespace weather;
using namespace maths;

namespace equipment
{
	RTTI_IMPL_NOPARENT(CVentilator);

	////Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
	CVentilator::CVentilator(const std::wstring& uniqueId)
	:
		CActor						(uniqueId),//konstruktor klasy bazowej
		m_ventilator_name			(""),
		m_performance				(0.0f),
		m_performance_factor		(0.0f),
		m_energy_consumption		(0.0f),
		m_energy_consumption_factor	(0.0f),
		m_ventilator_state			(EVentilatorState::VENTILATOR_DEFAULT),
		m_unit_controller			(false)//urz¹dzenie wy³¹czone - uruchamia siê z opóŸnieniem
	{
	}

	//Konstruktor kopiuj¹cy
	CVentilator::CVentilator(const CVentilator & CVentilatorCopy)
	:
		CActor						(CVentilatorCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_ventilator_name			(CVentilatorCopy.m_ventilator_name),
		m_performance				(CVentilatorCopy.m_performance),
		m_performance_factor		(CVentilatorCopy.m_performance_factor),
		m_energy_consumption		(CVentilatorCopy.m_energy_consumption),
		m_energy_consumption_factor	(CVentilatorCopy.m_energy_consumption_factor),
		m_ventilator_state			(CVentilatorCopy.m_ventilator_state),
		m_unit_controller			(CVentilatorCopy.m_unit_controller)
	{
	}

	//Destruktor
	CVentilator::~CVentilator()
	{
		//CActor					not edit
		m_ventilator_name			= "";
		m_performance				= 0.0f;
		m_performance_factor		= 0.0f;
		m_energy_consumption		= 0.0f;
		m_energy_consumption_factor	= 0.0f;
		m_ventilator_state			= EVentilatorState::VENTILATOR_DEFAULT;
		//m_unit_controller			not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CVentilator::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwê
	const std::string CVentilator::GetVentilatorName() const
	{
		return m_ventilator_name;
	}

	//Metoda ustawia nazwê
	void CVentilator::SetVentilatorName(const std::string & ventilator_name)
	{
		m_ventilator_name = ventilator_name;
	}

	//Metoda zwraca wydajnoœæ wentylatora
	const float CVentilator::getPerformance() const
	{
		return m_performance;
	}

	//Metoda ustawia wydajnoœæ wentylatora
	void CVentilator::setPerformance(float performance)
	{
		m_performance = performance;
	}

	//Metoda zwraca wspó³czynnik wydajnoœci zale¿ny od temperatury otoczenia
	const float CVentilator::getPerformanceFactor() const
	{
		return m_performance_factor;
	}

	//Metoda zwraca wspó³czynnik wydajnoœci zale¿ny od temperatury otoczenia
	void CVentilator::setPerformanceFactor(float performance_factor)
	{
		m_performance_factor = performance_factor;
	}

	//Metoda zwraca zu¿ycie energii przez wentylator
	const float CVentilator::getEnergyConsumption() const
	{
		return m_energy_consumption;
	}

	//Metoda ustawia zu¿ycie energii przez wentylator
	void CVentilator::setEnergyConsumption(float energy_consumption)
	{
		m_energy_consumption = energy_consumption;
	}

	//Metoda zwraca wspó³czynnik zu¿ycia energii wentylatora
	const float CVentilator::getEnergyConsumptionFactor() const
	{
		return m_energy_consumption_factor;
	}

	//Metoda ustawia wspó³czynnik zu¿ycia energii wentylatora
	void CVentilator::setEnergyConsumptionFactor(float energy_consumption_factor)
	{
		m_energy_consumption_factor = energy_consumption_factor;
	}

	//Metoda zwraca referencjcê na modu³ sterowania
	Switch & CVentilator::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
	void CVentilator::updateAnimations(float dt)
	{
		switch (m_ventilator_state)
		{
		case EVentilatorState::VENTILATOR_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetVentilatorBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetVentilatorHeadDefaultAnim());
			}
			break;
		}
		case EVentilatorState::VENTILATOR_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetVentilatorBodyDamagetAnim());
				SetAnimationHead(p_anim_set->GetVentilatorHeadDamagetAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda aktulizuje obiekt
	void CVentilator::update(float dt)
	{
		//jeœli obiekt posiada wentylator, to znaczy, ¿e w³aœciciel tego obiektu,
		//mo¿e sch³adzaæ/nagrzewaæ wnêtrze poprzez wymuszony ruch powietrza

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy w³¹czonym urz¹dzeniu
		if (m_unit_controller.getState())
		{
			//wyliczenie wspó³czynnika wydajnoœci w zale¿noœci od pozycji s³oñca - temperatury
			m_performance_factor = (gWeather.getSolarEnergyFactor() * m_performance);
			//wyliczenie wspó³czynnika zu¿ycia energii
			m_energy_consumption_factor = maths::Abs(m_performance_factor * m_energy_consumption);
		}

		//aktualizuja stanu obiektu - wentylator
		updateVentilatorState(dt);
	}
	//prywatna metoda aktualizuje stan obiektu - wentylator
	void CVentilator::updateVentilatorState(float dt)
	{


		//aktualizacja tylko przy w³¹czonym urz¹dzeniu
		if (m_unit_controller.getState())
			m_ventilator_state = EVentilatorState::VENTILATOR_DEFAULT;
		else
			m_ventilator_state = EVentilatorState::VENTILATOR_DAMAGE;

	}
}//namespace equipment
