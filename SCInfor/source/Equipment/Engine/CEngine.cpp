//  ____________________________________
// | CEngine.cpp - class implementation |
// | Jack Flower - December 2012        |
// |____________________________________|
//

#include "CEngine.h"
#include "../../Logic/CPhysicalManager.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Utilities/Utilities/Utilities.h"

using namespace rendering::drawable;
using namespace rendering::animation;
using namespace rendering::displayable;

namespace equipment
{
	RTTI_IMPL(CEngine, CActor)

	//Chroniony konstruktor domy�lny
	CEngine::CEngine(const std::wstring& uniqueId)
	:
		CActor							(uniqueId),//konstruktor klasy bazowej
		m_engine_name					(),
		m_fueltank_data					(),
		m_percentage_reserve_fuel		(0.1f),
		m_fuel_consumption				(0.0f),
		m_fuel_consumption_move			(0.0f),
		m_tank_time_delayed				(0.0f),
		m_fuel_empty_message			(false),
		m_engine_run					(false),
		m_engine_rotation_speed			(0.0f),
		m_engine_regeneration_time		(0.0f),
		m_engine_state					(ENGINE_DEFAULT),
		m_engine_timer					(0.0f),
		m_rotor_speed					(0.0f),
		m_percentage_fuel				(0.0f),
		m_unit_controller				(true)//urz�dzenie w��czone
	{
		SetZIndexBody(Z_PHYSICAL_ENGINE_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_ENGINE_BODY);
		SetZIndexHead(Z_PHYSICAL_ENGINE_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_SHADOW_ENGINE_HEAD);
	}

	//Chroniony konstruktor kopiuj�cy
	CEngine::CEngine(const CEngine& CEngineCopy)
	:
		CActor							(CEngineCopy),//konstruktor kopiuj�cy klasy bazowej
		m_engine_name					(CEngineCopy.m_engine_name),
		m_fueltank_data					(CEngineCopy.m_fueltank_data),
		m_percentage_reserve_fuel		(CEngineCopy.m_percentage_reserve_fuel),
		m_fuel_consumption				(CEngineCopy.m_fuel_consumption),
		m_fuel_consumption_move			(CEngineCopy.m_fuel_consumption_move),
		m_tank_time_delayed				(CEngineCopy.m_tank_time_delayed),
		m_fuel_empty_message			(CEngineCopy.m_fuel_empty_message),
		m_engine_run					(CEngineCopy.m_engine_run),
		m_engine_regeneration_time		(CEngineCopy.m_engine_regeneration_time),
		m_engine_rotation_speed			(CEngineCopy.m_engine_rotation_speed),
		m_engine_state					(CEngineCopy.m_engine_state),
		m_engine_timer					(CEngineCopy.m_engine_timer),
		m_rotor_speed					(CEngineCopy.m_rotor_speed),
		m_percentage_fuel				(CEngineCopy.m_percentage_fuel),
		m_unit_controller				(CEngineCopy.m_unit_controller)
	{
	}

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
	CEngine::~CEngine(void)
	{
		//CActor						not edit
		m_engine_name					= "";
		//m_fueltank_data				not edit
		m_percentage_reserve_fuel		= 0.0f;
		m_fuel_consumption				= 0.0f;
		m_fuel_consumption_move			= 0.0f;
		m_tank_time_delayed				= 0.0f;
		m_fuel_empty_message			= false;
		m_engine_run					= false;
		m_engine_regeneration_time		= 0.0f;
		m_engine_rotation_speed			= 0.0f;
		m_engine_state					= ENGINE_DEFAULT;
		m_engine_timer					= 0.0f;
		m_rotor_speed					= 0.0f;
		m_percentage_fuel				= 0.0f;
		//m_unit_controller				not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEngine::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca typ silnika
	const std::string CEngine::GetEngineName() const
	{
		return m_engine_name;
	}

	//Metoda ustawia typ silnika
	void CEngine::SetEngineName(const std::string& engine_name)
	{
		m_engine_name = engine_name;
	}

	//Metoda zwraca wska�nik na obiekt klasy CFuelTank
	CFuelTank* CEngine::GetFuelTank()
	{
		return m_fueltank_data.getFuelTank();
	}

	//Metoda ustawia wska�nik na obiekt klasy CFuelTank
	void CEngine::SetFuelTank(CFuelTank* fuel_tank)
	{
		m_fueltank_data.setFuelTank(fuel_tank);
	}

	//Metoda zwraca flag�, czy obiekt posiada zbiornik paliwa
	const bool CEngine::GetUseFuelTank() const
	{
		return m_fueltank_data.getUseEquipment();
	}

	//Metoda ustawia flag�, czy obiekt posiada zbiornik paliwa
	void CEngine::SetUseFuelTank(bool use_fueltank)
	{
		m_fueltank_data.setUseEquipment(use_fueltank);
	}

	//Metoda zwraca referencj� na opakowanie funkcjonalno�ci zbiornika paliwa
	CEquipmentFuelTankData & CEngine::getEquipmentFuelTankData()
	{
		return m_fueltank_data;
	}

	//Metoda ustawia referencj� na opakowanie funkcjonalno�ci zbiornika paliwa
	void CEngine::setEquipmentFuelTankData(CEquipmentFuelTankData & fueltank_data)
	{
		m_fueltank_data = fueltank_data;
	}

	//Metoda zwraca referencj� na opakowanie danych dla transformacji
	CTransformation & CEngine::getFuelTankTransformed()
	{
		return m_fueltank_data.getTransformed();
	}

	//Metoda ustawia referencj� na opakowanie danych dla transformacji
	void CEngine::setFuelTankTransformed(CTransformation & fuel_tank_transformation)
	{
		m_fueltank_data.setTransformed(fuel_tank_transformation);
	}

	//Metoda zwraca warto��, przy kt�rej nast�puje komunikat informacyjny o rezerwie paliwa (procent)
	const float CEngine::GetPercentageReserveFuel() const
	{
		return m_percentage_reserve_fuel;
	}

	//Metoda ustawia warto��, przy kt�rej nast�puje komunikat informacyjny o rezerwie paliwa
	void CEngine::SetPercentageReserveFuel(float percentage_reserve_fuel)
	{
		m_percentage_reserve_fuel = percentage_reserve_fuel;
	}

	//Metoda zwraca warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku paliwa
	const bool CEngine::GetFuelEmptyMessage() const
	{
		return m_fuel_empty_message;
	}

	//Metoda ustawia warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku paliwa
	void CEngine::SetFuelEmptyMessage(bool fuel_empty_message)
	{
		m_fuel_empty_message = fuel_empty_message;
	}

	//Metoda zwraca czas op�nienia komunikatu o braku paliwa
	const float CEngine::GetTankTimeDelayed() const
	{
		return m_tank_time_delayed;
	}

	//Metoda ustawia czas op�nienia komunikatu o braku paliwa
	void CEngine::SetTankTimeDelayed(float tank_time_delayed)
	{
		m_tank_time_delayed = tank_time_delayed;
	}

	//Metoda zwraca zu�ycie paliwa gdy obiekt si� nie przemieszcza
	const float CEngine::GetFuelConsumption() const
	{
		return m_fuel_consumption;
	}

	//Metoda ustawia zu�ycie paliwa gdy obiekt si� nie przemieszcza
	void CEngine::SetFuelConsumption(float fuel_consumption)
	{
		m_fuel_consumption = fuel_consumption;
	}

	//Metoda zwraca zu�ycie paliwa gdy obiekt si� przemieszcza - zwi�zane z pr�dko�ci� obiektu
	const float CEngine::GetFuelConsumptionMove() const
	{
		return m_fuel_consumption_move;
	}

	//Metoda ustawia zu�ycie paliwa gdy obiekt si� przemieszcza - zwi�zane z pr�dko�ci� obiektu
	void CEngine::SetFuelConsumptionMove(float fuel_consumption_move)
	{
		m_fuel_consumption_move = fuel_consumption_move;
	}

	//Metoda uruchamia prac� silnika
	const bool CEngine::GetRunEngine() const
	{
		return m_engine_run;
	}

	//Metoda ustawia prac� silnika
	void CEngine::SetRunEngine(bool engine_run)
	{
		m_engine_run = engine_run;
	}

	//Metoda zwraca cz�stotliwo�� regeneracji procesu
	const float CEngine::GetEngineRegenerationTime() const
	{
		return m_engine_regeneration_time;
	}

	//Metoda ustawia cz�stotliwo�� regeneracji procesu
	void CEngine::SetEngineRegenerationTime(float engine_regeneration_time)
	{
		m_engine_regeneration_time = engine_regeneration_time;
	}

	//Metoda zwraca pr�dko�� wirowania �opatek silnika
	const float CEngine::GetEngineRotationSpeed() const
	{
		return m_engine_rotation_speed;
	}

	//Metoda ustawia pr�dko�� wirowania �opatek silnika
	void CEngine::SetEngineRotationSpeed(float engine_rotation_speed)
	{
		m_engine_rotation_speed = engine_rotation_speed;
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
	void CEngine::updateAnimations(float dt)
	{
		switch(m_engine_state)
		{
		case EEngineState::ENGINE_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadDefaultAnim());
			}
			break;
		}
		case EEngineState::ENGINE_START:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyStartAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadStartAnim());
			}
			break;
		}
		case EEngineState::ENGINE_STOP:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyStopAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadStopAnim());
			}
			break;
		}
		case EEngineState::ENGINE_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyDamageAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadDamageAnim());
			}
			break;
		}
		case EEngineState::ENGINE_DEATH:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEngineBodyDeathAnim());
				SetAnimationHead(p_anim_set->GetEngineHeadDeathAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda zwraca referencjc� na modu� sterowania
	CSwitch & CEngine::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje logik� obiektu
	void CEngine::Update(float dt)
	{
		CPhysical::UpdateShadow(dt);//aktualizacja shadow engine

		updateFuelTankTransformation(dt);

		if(m_unit_controller.getState())
		{
			m_engine_timer += dt;	//kumulacja up�ywaj�cego czasu

			if(m_engine_run)//je�li silnik pracuje, �opatki wirnika si� obracaj�
				RotateHead(m_rotor_speed * dt);
			
			//engine - aktualizacja paliwa
			if(m_fueltank_data.getFuelTank())
			{
				//aktualizacja stanu paliwa ma miejsce je�li jest paliwo oraz silnik jest w��czony
				if (m_fueltank_data.getFuelTank()->GetFuel() && m_engine_run)
				{
					if (m_engine_timer >= m_engine_regeneration_time)//je�li up�yn�� skumulowany czas
					{
						if(m_fueltank_data.getFuelTank()->GetFuel())//je�li jest paliwo - zu�ywamy je
							m_fueltank_data.getFuelTank()->SetFuel(m_fueltank_data.getFuelTank()->GetFuel() - m_fuel_consumption);
						m_engine_timer = 0.0f;//resetujemy czas procesu
					}
					//obliczamy procentow� zawarto�� paliwa w zbiorniku
					if(m_fueltank_data.getFuelTank()->GetFuelTankCapacity())
						m_percentage_fuel = m_fueltank_data.getFuelTank()->GetFuel()/ m_fueltank_data.getFuelTank()->GetFuelTankCapacity();
					//aktualizacja pr�dko�ci wirowania �opatek wirnika w zale�no�ci od procentowej ilo�ci paliwa
					m_rotor_speed = m_engine_rotation_speed * m_percentage_fuel;
				}

				//brak paliwa - silnik stop
				if(!m_fueltank_data.getFuelTank()->GetFuel())
				{
					m_engine_run = false;
					m_rotor_speed = 0.0f;
				}

				//aktualizacja paliwa - je�li jest paliwo
				if(m_fueltank_data.getFuelTank())
					updateFuelTank(dt);
			}

			updateEngineState(dt);	//aktualizuja stanu obiektu
			updateAnimations(dt);	//aktualizacja animacji (stany engine)
		}
	}

	//implementacja metod private:

	//Metoda aktualizuje stan obiektu
	void CEngine::updateEngineState(float dt)
	{
		//to ulegnie zmianie
		//tymczasowa logika (docelowo energia, paliwo, etc...)
		if(m_engine_run)
			m_engine_state = EEngineState::ENGINE_START;
		else
			m_engine_state = EEngineState::ENGINE_STOP;
	}

	//prywatna metoda aktualizuje obiekt - fueltank (zbiornik paliwa)
	void CEngine::updateFuelTank(float dt)
	{
		if (m_fueltank_data.getFuelTank())
		{
			//jest wystarczaj�ca ilo�� paliwa
			if(m_fueltank_data.getFuelTank()->GetFuel() > m_fueltank_data.getFuelTank()->GetFuelTankCapacity() * m_percentage_reserve_fuel)
				m_fueltank_data.getFuelTank()->getFuelTankState() = EFuelTankState::FUELTANK_DEFAULT;

			//rezerwa paliwa
			if(m_fueltank_data.getFuelTank()->GetFuel() <= m_fueltank_data.getFuelTank()->GetFuelTankCapacity() * m_percentage_reserve_fuel)
				m_fueltank_data.getFuelTank()->getFuelTankState() = EFuelTankState::FUELTANK_RESERVE;

			//brak paliwa
			if(m_fueltank_data.getFuelTank()->GetFuel() <= 0.f)
				m_fueltank_data.getFuelTank()->getFuelTankState() = EFuelTankState::FUELTANK_EMPTY;
		}
	}

	//prywatna metoda aktualizuje sk�adowe transformacji wzgl�dem w�a�ciciela
	void CEngine::updateFuelTankTransformation(float dt)
	{
		m_fueltank_data.getTransformed().Transform(this, m_fueltank_data.getFuelTank());
	}
}//namespace equipment
