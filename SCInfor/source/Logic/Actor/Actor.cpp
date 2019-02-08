//  __________________________________
// | Actor.cpp - class implementation |
// | Jack Flower - December 2012      |
// |__________________________________|
//

#include "Actor.h"
#include "../CPhysicalManager.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Animations/CAnimationState.h"
#include "../../Rendering/Animations/CNameAnimPairTranslator.h"
#include "../../Equipment/Engine/Engine.h"
#include "../../Equipment/Energy/Energy.h"
#include "../../Equipment/Thermodynamics/Airconditioning/Airconditioning.h"
#include "../../Equipment/Thermodynamics/Ventilator/Ventilator.h"
#include "../../Equipment/Weapon/Gun/Gun.h"
#include "../../Utilities/Utilities/Utilities.h"
#include "../../Game/Game.h"
#include "../../Weather/CWeather.h"
#include <iostream>

using namespace rendering::displayable;
using namespace game;
using namespace weather;

namespace logic
{
	RTTI_IMPL(Actor, CPhysical);

	//Chroniony konstruktor domyślny
	Actor::Actor(const std::wstring & uniqueId)
	:
		CPhysical(uniqueId),	//konstruktor klasy bazowej
		p_anim_set(NULL),
		m_technical_data(),
		m_engine_data(),
		m_energy_data(),
		m_airconditiong_data(),
		m_ventilator_data(),
		m_gun_data(),
		m_state_data(),
		p_actor_controller(NULL)
	{
	}

	//Chroniony konstruktor kopiujący
	Actor::Actor(const Actor & ActorCopy)
	:
		CPhysical(ActorCopy),//konstruktor kopiujący klasy bazowej
		p_anim_set(ActorCopy.p_anim_set),
		m_technical_data(ActorCopy.m_technical_data),
		m_engine_data(ActorCopy.m_engine_data),
		m_energy_data(ActorCopy.m_energy_data),
		m_airconditiong_data(ActorCopy.m_airconditiong_data),
		m_ventilator_data(ActorCopy.m_ventilator_data),
		m_gun_data(ActorCopy.m_gun_data),
		m_state_data(ActorCopy.m_state_data),
		p_actor_controller(ActorCopy.p_actor_controller)
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
	Actor::~Actor(void)
	{
		//~CPhysical()
		p_anim_set = NULL;
		//m_technical_data
		//m_engine_data
		//m_energy_data
		//m_airconditiong_data
		//m_ventilator_data
		//m_gun_data
		//m_state_data
		p_actor_controller= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Actor::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca masę obiektu
	const float Actor::getMass() const
	{
		return m_technical_data.getMass();
	}

	//Metoda ustawia masę obiektu
	const void Actor::setMass(float mass)
	{
		if (mass < 0) return;
		m_technical_data.setMass(mass);
	}

	//Metoda zwraca temperaturę
	const float Actor::getTemperature() const
	{
		return m_technical_data.getTemperature();
	}

	//Metoda ustawia temperaturę
	const void Actor::setTemperature(float temperature)
	{
		m_technical_data.setTemperature(temperature);
	}

	//Metoda zwraca flagę, czy obiekt się porusza
	bool const Actor::getIsMove() const
	{
		return m_technical_data.getIsMove();
	}

	//Metoda ustawia flagę, że obiekt się porusza
	const void Actor::setIsMove(bool is_move)
	{
		m_technical_data.setIsMove(is_move);
	}

	//Metoda zwraca flagę, czy obiekt może się przemieszczać
	const bool Actor::getIsMovabled() const
	{
		return m_technical_data.getIsMovabled();
	}

	//Metoda ustawia flagę, czy obiekt może się przemieszczać
	const void Actor::setIsMovabled(bool movabled)
	{
		m_technical_data.setIsMovabled(movabled);
	}

	//Metoda zwraca prędkość obiektu
	const float Actor::getSpeed() const
	{
		return m_technical_data.getSpeed();
	}

	//Metoda ustawia prędkość obiektu
	const void Actor::setSpeed(float speed)
	{
		if (speed < 0) return;
		m_technical_data.setSpeed(speed);
	}

	//Metoda zwraca wskaźnik na zestaw animacji
	CAnimSet *Actor::getAnimSet()
	{
		return p_anim_set;
	}

	//Metoda ustawia zestaw animacji
	void Actor::setAnimSet(CAnimSet *anim_set)
	{
		setAnimSetBody(anim_set); //body
		setAnimSetHead(anim_set); //head
		p_anim_set = anim_set; //zmiana zestawu animacji na nowy (parametr)
	}

	//Metoda zwraca referencję na klasę bedącą opakowaniem fizyki
	CActorTechnicalData & Actor::getTechnicalData()
	{
		return m_technical_data;
	}

	//Metoda ustawia referencję na klasę bedącą opakowaniem fizyki
	void Actor::setTechnicalData(CActorTechnicalData & technical_data)
	{
		m_technical_data = technical_data;
	}

	//Metoda zwraca flagę, czy obiekt posiada silnik
	const bool Actor::getUseEngine() const
	{
		return m_engine_data.getUseEquipment();
	}

	//Metoda ustawia flagę, czy obiekt posiada silnik
	void Actor::setUseEngine(bool use_engine)
	{
		m_engine_data.setUseEquipment(use_engine);
	}

	//Metoda zwraca flagę, czy obiekt posiada akumulator energii
	const bool Actor::getUseEnergy() const
	{
		return m_energy_data.getUseEquipment();
	}

	//Metoda ustawia flagę, czy obiekt posiada akumulator energii
	void Actor::setUseEnergy(bool use_energy)
	{
		m_energy_data.setUseEquipment(use_energy);
	}

	//Metoda zwraca flagę, czy obiekt posiada działo
	const bool Actor::getUseGun() const
	{
		return m_gun_data.getUseEquipment();
	}

	//Metoda ustawia flagę, czy obiekt posiada działo
	void Actor::setUseGun(bool use_gun)
	{
		m_gun_data.setUseEquipment(use_gun);
	}

	//Metoda zwraca flagę, czy obiekt posiada moduł klimatyzatora
	const bool Actor::getUseAirconditioning() const
	{
		return m_airconditiong_data.getUseEquipment();
	}

	//Metoda ustawia flagę, czy obiekt posiada moduł klimatyzatora
	void Actor::setUseAirconditioning(bool use_airconditioning)
	{
		m_airconditiong_data.setUseEquipment(use_airconditioning);
	}

	//Metoda zwraca flagę, czy obiekt posiada moduł wentylatora
	const bool Actor::getUseWentilator() const
	{
		return m_ventilator_data.getUseEquipment();
	}

	//Metoda ustawia flagę, czy obiekt posiada moduł wentylatora
	void Actor::setUseWentilator(bool use_ventilator)
	{
		m_ventilator_data.setUseEquipment(use_ventilator);
	}

	//Metoda zwraca wskaźnik na obiekt klasy Engine
	Engine *Actor::getEngine()
	{
		return m_engine_data.getEngine();
	}

	//Metoda ustawia wskaźnik na obiekt klasy Engine
	void Actor::setEngine(Engine *engine)
	{
		m_engine_data.setEngine(engine);
	}

	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & Actor::getEngineTransformed()
	{
		return m_engine_data.getTransformed();
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void Actor::setEngineTransformed(CTransformation & transformation)
	{
		m_engine_data.setTransformed(transformation);
	}

	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & Actor::getEnergyTransformed()
	{
		return m_energy_data.getTransformed();
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void Actor::setEnergyTransformed(CTransformation & transformation)
	{
		m_energy_data.setTransformed(transformation);
	}

	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & Actor::getAirconditioningTransformed()
	{
		return m_airconditiong_data.getTransformed();
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void Actor::setAirconditioningTransformed(CTransformation & transformation)
	{
		m_airconditiong_data.setTransformed(transformation);
	}
	
	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & Actor::getVentilatorTransformed()
	{
		return m_ventilator_data.getTransformed();
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void Actor::setVentilatorTransformed(CTransformation & transformation)
	{
		m_ventilator_data.setTransformed(transformation);
	}

	//Metoda zwraca referencję na opakowanie danych dla transformacji
	CTransformation & Actor::getGunTransformed()
	{
		return m_gun_data.getTransformed();
	}

	//Metoda ustawia referencję na opakowanie danych dla transformacji
	void Actor::setGunTransformed(CTransformation & transformation)
	{
		m_gun_data.setTransformed(transformation);
	}

	//Metoda zwraca wskaźnik na obiekt klasy Energy
	Energy* Actor::getEnergy()
	{
		return m_energy_data.getEnergy();
	}

	//Metoda ustawia wskaźnik na obiekt klasy Energy
	void Actor::setEnergy(Energy *energy)
	{
		m_energy_data.setEnergy(energy);
	}

	//Metoda zwraca wskaźnik na obiekt klasy Airconditioning
	Airconditioning *Actor::getAirconditioning()
	{
		return m_airconditiong_data.getAirconditioning();
	}

	//Metoda ustawia wskaźnik na obiekt klasy Airconditioning
	void Actor::setAirconditioning(Airconditioning* airconditioning)
	{
		m_airconditiong_data.setAirconditioning(airconditioning);
	}

	//Metoda zwraca wskaźnik na obiekt klasy Ventilator
	Ventilator *Actor::getVentilator()
	{
		return m_ventilator_data.getVentilator();
	}

	//Metoda ustawia wskaźnik na obiekt klasy Ventilator
	void Actor::setVentilator(Ventilator *ventilator)
	{
		m_ventilator_data.setVentilator(ventilator);
	}

	//Metoda zwraca wskaźnik na obiekt klasy Gun
	Gun *Actor::getGun()
	{
		return m_gun_data.getGun();
	}

	//Metoda ustawia wskaźnik na obiekt klasy Gun
	///
	void Actor::setGun(Gun *gun)
	{
		m_gun_data.setGun(gun);
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
	void Actor::updateAnimations(float dt)
	{
		//aktualizacja aktora w zależności od EActorState
		//(ten plik będzie dopiero utworzony)
		//actor state - future...
		//test:
		//SetAnimationBody(p_anim_set->GetMoveAnimBody());
	}

	//Metoda zwraca opakowanie stanów obiektu
	const ActorStateData & Actor::getStateData() const
	{
		return m_state_data;
	}

	//Metoda ustawia opakowanie stanów obiektu
	void Actor::getStateData(const ActorStateData & state_data)
	{
		m_state_data = state_data;
	}

	//Metoda zwraca stan obiektu - aktualizcja reprezentacji obiektu
	const EActorBasicState & Actor::getBasicState() const
	{
		return m_state_data.getBasicState();
	}

	//Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
	void Actor::setBasicState(const EActorBasicState & basic_state)
	{
		m_state_data.setBasicState(basic_state);
	}

	//Metoda zwraca stan ruchu obiektu
	const EActorMoveState & Actor::getMoveState() const
	{
		return m_state_data.getMoveState();
	}

	//Metoda ustawia stan ruchu obiektu
	void Actor::setMoveState(const EActorMoveState & move_state)
	{
		m_state_data.setMoveState(move_state);
	}

	//Metoda zwraca stan behawioralny obiektu
	const EActorSpawnState & Actor::getSpawnState() const
	{
		return m_state_data.getSpawnState();
	}

	//Metoda ustawia stan behawioralny obiektu
	void Actor::setSpawnState(const EActorSpawnState & spawn_state)
	{
		m_state_data.setSpawnState(spawn_state);
	}

	//Wirtualan metoda zabija obiekt klasy Actor i wywołuje odpowiednie czynności z tym związane
	void Actor::kill()
	{
		CPhysical::kill();
		//to do...
	}

	//Wirtualna metoda aktualizująca obiekt
	void Actor::update(float dt)
	{
		//aktualizacja klasy bazowej
		CPhysical::update(dt);		

		//aktualizacja animacji
		updateAnimations(dt);

		Actor::updateComponents(dt);
	}


	//implementacja metod protected:

	//Metoda aktualizuje komponenty
	void Actor::updateComponents(float dt)
	{
		//tutaj wszystkie komponenty...
		if (m_engine_data.getEngine())
			updateEngine(dt);

		if (m_energy_data.getEnergy())
			updateEnergy(dt);

		if (m_airconditiong_data.getAirconditioning())
			updateAirconditioning(dt);

		if (m_ventilator_data.getVentilator())
			updateVentilator(dt);

		if (m_gun_data.getGun())
			updateGun(dt);

		//aktualizuja temperatury
		updateTemperature(dt);
	}

	//implementacja metod private:

	//metoda aktualizuje funkcjonalność Engine
	void Actor::updateEngine(float dt)
	{
		//transformacja
		m_engine_data.Transform(this, m_engine_data.getEngine());
	}

	//metoda aktualizuje funkcjonalność Energy
	void Actor::updateEnergy(float dt)
	{
		//transformacja
		m_energy_data.Transform(this, m_energy_data.getEnergy());
	}

	//metoda aktualizuje funkcjonalność Airconditioning
	void Actor::updateAirconditioning(float dt)
	{
		if (m_airconditiong_data.getAirconditioning())//moduł klimatyzatora
		{
			if(m_energy_data.getEnergy())//moduł klimatyzatora zużywa energię
			{
				if(m_energy_data.getEnergy()->getEnergyTank()->getEnergy())//w akumulatorze jest energia
					m_energy_data.getEnergy()->getEnergyTank()->setEnergy(m_energy_data.getEnergy()->getEnergyTank()->getEnergy() - m_airconditiong_data.getAirconditioning()->getEnergyConsumption());
			}
		}

		//transformacja
		m_airconditiong_data.Transform(this, m_airconditiong_data.getAirconditioning());
	}

	//metoda aktualizuje funkcjonalność Ventilator
	void Actor::updateVentilator(float dt)
	{
		if(m_ventilator_data.getVentilator())//muduł klimatyzatora
		{
			if(m_energy_data.getEnergy())//moduł wentylatora zużywa energię
			{
				if(m_energy_data.getEnergy()->getEnergyTank()->getEnergy())//w akumulatorze jest energia
					m_energy_data.getEnergy()->getEnergyTank()->setEnergy(m_energy_data.getEnergy()->getEnergyTank()->getEnergy() - m_ventilator_data.getVentilator()->getEnergyConsumptionFactor());
			}
		}

		//transformacja
		m_ventilator_data.Transform(this, m_ventilator_data.getVentilator());
	}

	//metoda aktualizuje funkcjonalność Gun
	void Actor::updateGun(float dt)
	{
		//logic...
		//transformacja
		m_gun_data.Transform(this, m_gun_data.getGun());
	}

	//metoda aktualizuje temperaturę
	void Actor::updateTemperature(float dt)
	{
		//obiekt posiada moduł klimatyzatora
		if(m_airconditiong_data.getAirconditioning())
		{
			//jeśli urządzenie jest włączone
			if(m_airconditiong_data.getAirconditioning()->getUnitController().getState())
				//temperatura modułu klimatyzatora
				m_technical_data.setTemperature(m_airconditiong_data.getAirconditioning()->getTemperature());
			else
				//temperatura otoczenia
				m_technical_data.setTemperature(gWeather.getTemperature());
		}
		//obiekt nie posiada modułu klimatyzatora
		else				
			//temperatura otoczenia
			m_technical_data.setTemperature(gWeather.getTemperature());
		
		//obiekt posiada moduł wentylatora (poprawka temperatury - wentylator)
		//przy temperaturze dodatniej schładza, przy ujemnej nagrzewa
		if(m_ventilator_data.getVentilator())
			m_technical_data.setTemperature(m_technical_data.getTemperature() - m_ventilator_data.getVentilator()->getPerformanceFactor());
	}

	//metoda ustawia zestaw animacji - body
	void Actor::setAnimSetBody(CAnimSet *anim_set)
	{
		//jeśli zestaw animacji jest zainicjowany
		if (p_anim_set)//body
		{
			//płynna zmiana animacji - body
			CAnimation *curr_anim = GetAnimationBody();

			//kontener przechowujący stary (dotychczasowy) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &old_anims = p_anim_set->GetAnims();

			//kontener przechowujący nowy (parametr tej metody) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &new_anims = anim_set->GetAnims();

			//indeks, pod którym może znajdować się szukana animacja
			unsigned int index = -1;

			//przeszukuję stary zestaw animacji, aby odszukać w nim animację do podmiany
			for (unsigned int i = 0; i < old_anims.size(); i++)
			{
				//jeśli znalazłem szukaną animację w starym (dotychczasowym) kontenerze
				if (old_anims[i].GetAnimation() == curr_anim)
				{
					index = i;	//zapamiętuję pod jakim jest indeksem w kontenerze
					break;		//i przerywam przeszukiwanie
				}
			}

			//jeśli indeks jest większy od zera oraz indeks jest mniejszy od rozmiaru kontenera
			//z zestawem (nie można przekroczyć rozmiaru nowego kontenera)
			//i w nowym zestawie (parametr), pod tym indeksem jest animacja
			if ((index >= 0) && (index < new_anims.size()) && (new_anims[index].GetAnimation() != NULL))
			{
				//zapamiętuję czas trwania bieżącej animacji
				float currTime = GetDisplayableBody()->GetAnimationState()->GetCurrentTime();

				//podmieniam starą animację ze starego zestawu na nową animację z nowego zestawu
				SetAnimationBody(new_anims[index].GetAnimation());

				//przewijam animację do "czasu", w którym rozpoczął się proces podmiany animacji
				GetDisplayableBody()->GetAnimationState()->RewindTo(currTime);
			}
		}
	}

	//metoda pomocnicza - metoda ustawia zestaw animacji - head
	void Actor::setAnimSetHead(CAnimSet *anim_set)
	{
		//jeśli zestaw animacji jest zainicjowany
		if (p_anim_set)//head
		{
			//płynna zmiana animacji - head
			CAnimation *curr_anim = GetAnimationHead();

			//kontener przechowujący stary (dotychczasowy) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &old_anims = p_anim_set->GetAnims();

			//kontener przechowujący nowy (parametr tej metody) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &new_anims = anim_set->GetAnims();

			//indeks, pod którym może znajdować się szukana animacja
			unsigned int index = -1;

			//przeszukuję stary zestaw animacji, aby odszukać w nim animację do podmiany
			for (unsigned int i = 0; i < old_anims.size(); i++)
			{
				//jeśli znalazłem szukaną animację w starym (dotychczasowym) kontenerze
				if (old_anims[i].GetAnimation() == curr_anim)
				{
					index = i;	//zapamiętuję pod jakim jest indeksem w kontenerze
					break;		//i przerywam przeszukiwanie
				}
			}

			//jeśli indeks jest większy od zera oraz indeks jest mniejszy od rozmiaru kontenera
			//z zestawem (nie można przekroczyć rozmiaru nowego kontenera)
			//i w nowym zestawie (parametr), pod tym indeksem jest animacja
			if ((index >= 0) && (index < new_anims.size()) && (new_anims[index].GetAnimation() != NULL))
			{
				//zapamiętuję czas trwania bieżącej animacji
				float currTime = GetDisplayableHead()->GetAnimationState()->GetCurrentTime();

				//podmieniam starą animację ze starego zestawu na nową animację z nowego zestawu
				SetAnimationHead(new_anims[index].GetAnimation());

				//przewijam animację do "czasu", w którym rozpoczął się proces podmiany animacji
				GetDisplayableHead()->GetAnimationState()->RewindTo(currTime);
			}
		}
	}
}//namespace logic
