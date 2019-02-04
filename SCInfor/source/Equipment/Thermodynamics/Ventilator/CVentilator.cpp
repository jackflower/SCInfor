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

	////Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
	CVentilator::CVentilator(const std::wstring& uniqueId)
	:
		CActor						(uniqueId),//konstruktor klasy bazowej
		m_ventilator_name			(""),
		m_performance				(0.0f),
		m_performance_factor		(0.0f),
		m_energy_consumption		(0.0f),
		m_energy_consumption_factor	(0.0f),
		m_ventilator_state			(EVentilatorState::VENTILATOR_DEFAULT),
		m_unit_controller			(false)//urz�dzenie wy��czone - uruchamia si� z op�nieniem
	{
	}

	//Konstruktor kopiuj�cy
	CVentilator::CVentilator(const CVentilator & CVentilatorCopy)
	:
		CActor						(CVentilatorCopy),//konstruktor kopiuj�cy klasy bazowej
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

	//Metoda zwraca nazw�
	const std::string CVentilator::GetVentilatorName() const
	{
		return m_ventilator_name;
	}

	//Metoda ustawia nazw�
	void CVentilator::SetVentilatorName(const std::string & ventilator_name)
	{
		m_ventilator_name = ventilator_name;
	}

	//Metoda zwraca wydajno�� wentylatora
	const float CVentilator::getPerformance() const
	{
		return m_performance;
	}

	//Metoda ustawia wydajno�� wentylatora
	void CVentilator::setPerformance(float performance)
	{
		m_performance = performance;
	}

	//Metoda zwraca wsp�czynnik wydajno�ci zale�ny od temperatury otoczenia
	const float CVentilator::getPerformanceFactor() const
	{
		return m_performance_factor;
	}

	//Metoda zwraca wsp�czynnik wydajno�ci zale�ny od temperatury otoczenia
	void CVentilator::setPerformanceFactor(float performance_factor)
	{
		m_performance_factor = performance_factor;
	}

	//Metoda zwraca zu�ycie energii przez wentylator
	const float CVentilator::getEnergyConsumption() const
	{
		return m_energy_consumption;
	}

	//Metoda ustawia zu�ycie energii przez wentylator
	void CVentilator::setEnergyConsumption(float energy_consumption)
	{
		m_energy_consumption = energy_consumption;
	}

	//Metoda zwraca wsp�czynnik zu�ycia energii wentylatora
	const float CVentilator::getEnergyConsumptionFactor() const
	{
		return m_energy_consumption_factor;
	}

	//Metoda ustawia wsp�czynnik zu�ycia energii wentylatora
	void CVentilator::setEnergyConsumptionFactor(float energy_consumption_factor)
	{
		m_energy_consumption_factor = energy_consumption_factor;
	}

	//Metoda zwraca referencjc� na modu� sterowania
	Switch & CVentilator::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
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
		//je�li obiekt posiada wentylator, to znaczy, �e w�a�ciciel tego obiektu,
		//mo�e sch�adza�/nagrzewa� wn�trze poprzez wymuszony ruch powietrza

		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy w��czonym urz�dzeniu
		if (m_unit_controller.getState())
		{
			//wyliczenie wsp�czynnika wydajno�ci w zale�no�ci od pozycji s�o�ca - temperatury
			m_performance_factor = (gWeather.getSolarEnergyFactor() * m_performance);
			//wyliczenie wsp�czynnika zu�ycia energii
			m_energy_consumption_factor = maths::Abs(m_performance_factor * m_energy_consumption);
		}

		//aktualizuja stanu obiektu - wentylator
		updateVentilatorState(dt);
	}
	//prywatna metoda aktualizuje stan obiektu - wentylator
	void CVentilator::updateVentilatorState(float dt)
	{


		//aktualizacja tylko przy w��czonym urz�dzeniu
		if (m_unit_controller.getState())
			m_ventilator_state = EVentilatorState::VENTILATOR_DEFAULT;
		else
			m_ventilator_state = EVentilatorState::VENTILATOR_DAMAGE;

	}
}//namespace equipment
