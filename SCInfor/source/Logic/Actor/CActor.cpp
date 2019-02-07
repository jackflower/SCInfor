//  ___________________________________
// | CActor.cpp - class implementation |
// | Jack Flower - December 2012       |
// |___________________________________|
//

#include "CActor.h"
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
	RTTI_IMPL(CActor, CPhysical);

	//Chroniony konstruktor domyœlny
	CActor::CActor(const std::wstring& uniqueId)
	:
		CPhysical				(uniqueId),	//konstruktor klasy bazowej
		p_anim_set				(NULL),
		m_technical_data		(),
		m_engine_data			(),
		m_energy_data			(),
		m_airconditiong_data	(),
		m_ventilator_data		(),
		m_gun_data				(),
		m_state_data			(),
		p_actor_controller		(NULL)
	{
	}

	//Chroniony konstruktor kopiuj¹cy
	CActor::CActor(const CActor &CActorCopy)
	:
		CPhysical				(CActorCopy),//konstruktor kopiuj¹cy klasy bazowej
		p_anim_set				(CActorCopy.p_anim_set),
		m_technical_data		(CActorCopy.m_technical_data),
		m_engine_data			(CActorCopy.m_engine_data),
		m_energy_data			(CActorCopy.m_energy_data),
		m_airconditiong_data	(CActorCopy.m_airconditiong_data),
		m_ventilator_data		(CActorCopy.m_ventilator_data),
		m_gun_data				(CActorCopy.m_gun_data),
		m_state_data			(CActorCopy.m_state_data),
		p_actor_controller		(CActorCopy.p_actor_controller)
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
	CActor::~CActor(void)
	{
		p_anim_set					= NULL;
		//m_technical_data			not edit
		//m_engine_data				not edit
		//m_energy_data				not edit
		//m_airconditiong_data		not edit
		//m_ventilator_data			not edit
		//m_gun_data				not edit
		//m_state_data				not edit
		p_actor_controller			= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CActor::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca masê obiektu
	const float CActor::getMass() const
	{
		return m_technical_data.getMass();
	}

	//Metoda ustawia masê obiektu
	const void CActor::setMass(float mass)
	{
		if (mass < 0) return;
		m_technical_data.setMass(mass);
	}

	//Metoda zwraca temperaturê
	const float CActor::getTemperature() const
	{
		return m_technical_data.getTemperature();
	}

	//Metoda ustawia temperaturê
	const void CActor::setTemperature(float temperature)
	{
		m_technical_data.setTemperature(temperature);
	}

	//Metoda zwraca flagê, czy obiekt siê porusza
	bool const CActor::getIsMove() const
	{
		return m_technical_data.getIsMove();
	}

	//Metoda ustawia flagê, ¿e obiekt siê porusza
	const void CActor::setIsMove(bool is_move)
	{
		m_technical_data.setIsMove(is_move);
	}

	//Metoda zwraca flagê, czy obiekt mo¿e siê przemieszczaæ
	const bool CActor::getIsMovabled() const
	{
		return m_technical_data.getIsMovabled();
	}

	//Metoda ustawia flagê, czy obiekt mo¿e siê przemieszczaæ
	const void CActor::setIsMovabled(bool movabled)
	{
		m_technical_data.setIsMovabled(movabled);
	}

	//Metoda zwraca prêdkoœæ obiektu
	const float CActor::getSpeed() const
	{
		return m_technical_data.getSpeed();
	}

	//Metoda ustawia prêdkoœæ obiektu
	const void CActor::setSpeed(float speed)
	{
		if (speed < 0) return;
		m_technical_data.setSpeed(speed);
	}

	//Metoda zwraca wskaŸnik na zestaw animacji
	CAnimSet *CActor::GetAnimSet()
	{
		return p_anim_set;
	}

	//Metoda ustawia zestaw animacji
	void CActor::SetAnimSet(CAnimSet *anim_set)
	{
		SetAnimSetBody(anim_set);	//body
		SetAnimSetHead(anim_set);	//head
		p_anim_set = anim_set;		//zmiana zestawu animacji na nowy (parametr)
	}

	//Metoda zwraca referencjê na klasê bed¹c¹ opakowaniem fizyki
	CActorTechnicalData & CActor::getTechnicalData()
	{
		return m_technical_data;
	}

	//Metoda ustawia referencjê na klasê bed¹c¹ opakowaniem fizyki
	void CActor::setTechnicalData(CActorTechnicalData & technical_data)
	{
		m_technical_data = technical_data;
	}

	//Metoda zwraca flagê, czy obiekt posiada silnik
	const bool CActor::GetUseEngine() const
	{
		return m_engine_data.getUseEquipment();
	}

	//Metoda ustawia flagê, czy obiekt posiada silnik
	void CActor::SetUseEngine(bool use_engine)
	{
		m_engine_data.setUseEquipment(use_engine);
	}

	//Metoda zwraca flagê, czy obiekt posiada akumulator energii
	const bool CActor::GetUseEnergy() const
	{
		return m_energy_data.getUseEquipment();
	}

	//Metoda ustawia flagê, czy obiekt posiada akumulator energii
	void CActor::SetUseEnergy(bool use_energy)
	{
		m_energy_data.setUseEquipment(use_energy);
	}

	//Metoda zwraca flagê, czy obiekt posiada dzia³o
	const bool CActor::GetUseGun() const
	{
		return m_gun_data.getUseEquipment();
	}

	//Metoda ustawia flagê, czy obiekt posiada dzia³o
	void CActor::SetUseGun(bool use_gun)
	{
		m_gun_data.setUseEquipment(use_gun);
	}

	//Metoda zwraca flagê, czy obiekt posiada modu³ klimatyzatora
	const bool CActor::GetUseAirconditioning() const
	{
		return m_airconditiong_data.getUseEquipment();
	}

	//Metoda ustawia flagê, czy obiekt posiada modu³ klimatyzatora
	void CActor::SetUseAirconditioning(bool use_airconditioning)
	{
		m_airconditiong_data.setUseEquipment(use_airconditioning);
	}

	//Metoda zwraca flagê, czy obiekt posiada modu³ wentylatora
	const bool CActor::GetUseWentilator() const
	{
		return m_ventilator_data.getUseEquipment();
	}

	//Metoda ustawia flagê, czy obiekt posiada modu³ wentylatora
	void CActor::SetUseWentilator(bool use_ventilator)
	{
		m_ventilator_data.setUseEquipment(use_ventilator);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy Engine
	Engine* CActor::GetEngine()
	{
		return m_engine_data.getEngine();
	}

	//Metoda ustawia wskaŸnik na obiekt klasy Engine
	void CActor::SetEngine(Engine* engine)
	{
		m_engine_data.setEngine(engine);
	}

	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & CActor::getEngineTransformed()
	{
		return m_engine_data.getTransformed();
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void CActor::setEngineTransformed(CTransformation & transformation)
	{
		m_engine_data.setTransformed(transformation);
	}

	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & CActor::getEnergyTransformed()
	{
		return m_energy_data.getTransformed();
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void CActor::setEnergyTransformed(CTransformation & transformation)
	{
		m_energy_data.setTransformed(transformation);
	}

	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & CActor::getAirconditioningTransformed()
	{
		return m_airconditiong_data.getTransformed();
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void CActor::setAirconditioningTransformed(CTransformation & transformation)
	{
		m_airconditiong_data.setTransformed(transformation);
	}
	
	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & CActor::getVentilatorTransformed()
	{
		return m_ventilator_data.getTransformed();
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void CActor::setVentilatorTransformed(CTransformation & transformation)
	{
		m_ventilator_data.setTransformed(transformation);
	}

	//Metoda zwraca referencjê na opakowanie danych dla transformacji
	CTransformation & CActor::getGunTransformed()
	{
		return m_gun_data.getTransformed();
	}

	//Metoda ustawia referencjê na opakowanie danych dla transformacji
	void CActor::setGunTransformed(CTransformation & transformation)
	{
		m_gun_data.setTransformed(transformation);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy Energy
	Energy* CActor::GetEnergy()
	{
		return m_energy_data.getEnergy();
	}

	//Metoda ustawia wskaŸnik na obiekt klasy Energy
	void CActor::SetEnergy(Energy* energy)
	{
		m_energy_data.setEnergy(energy);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy Airconditioning
	Airconditioning* CActor::GetAirconditioning()
	{
		return m_airconditiong_data.getAirconditioning();
	}

	//Metoda ustawia wskaŸnik na obiekt klasy Airconditioning
	void CActor::SetAirconditioning(Airconditioning* airconditioning)
	{
		m_airconditiong_data.setAirconditioning(airconditioning);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy Ventilator
	Ventilator* CActor::GetVentilator()
	{
		return m_ventilator_data.getVentilator();
	}

	//Metoda ustawia wskaŸnik na obiekt klasy Ventilator
	void CActor::SetVentilator(Ventilator* ventilator)
	{
		m_ventilator_data.setVentilator(ventilator);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy Gun
	Gun* CActor::GetGun()
	{
		return m_gun_data.getGun();
	}

	//Metoda ustawia wskaŸnik na obiekt klasy Gun
	///
	void CActor::SetGun(Gun* gun)
	{
		m_gun_data.setGun(gun);
	}

	//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
	void CActor::updateAnimations(float dt)
	{
		//aktualizacja aktora w zale¿noœci od EActorState
		//(ten plik bêdzie dopiero utworzony)
		//actor state - future...
		//test:
		//SetAnimationBody(p_anim_set->GetMoveAnimBody());
	}

	//Metoda zwraca opakowanie stanów obiektu
	const CActorStateData & CActor::getStateData() const
	{
		return m_state_data;
	}

	//Metoda ustawia opakowanie stanów obiektu
	void CActor::getStateData(const CActorStateData & state_data)
	{
		m_state_data = state_data;
	}

	//Metoda zwraca stan obiektu - aktualizcja reprezentacji obiektu
	const EActorBasicState & CActor::getBasicState() const
	{
		return m_state_data.getBasicState();
	}

	//Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
	void CActor::setBasicState(const EActorBasicState & basic_state)
	{
		m_state_data.setBasicState(basic_state);
	}

	//Metoda zwraca stan ruchu obiektu
	const EActorMoveState & CActor::getMoveState() const
	{
		return m_state_data.getMoveState();
	}

	//Metoda ustawia stan ruchu obiektu
	void CActor::setMoveState(const EActorMoveState & move_state)
	{
		m_state_data.setMoveState(move_state);
	}

	//Metoda zwraca stan behawioralny obiektu
	const EActorSpawnState & CActor::getSpawnState() const
	{
		return m_state_data.getSpawnState();
	}

	//Metoda ustawia stan behawioralny obiektu
	void CActor::setSpawnState(const EActorSpawnState & spawn_state)
	{
		m_state_data.setSpawnState(spawn_state);
	}

	//Wirtualan metoda zabija obiekt klasy CActor i wywo³uje odpowiednie czynnoœci z tym zwi¹zane
	void CActor::Kill()
	{
		CPhysical::Kill();
		//to do...
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CActor::update(float dt)
	{
		//aktualizacja klasy bazowej
		CPhysical::update(dt);		

		//aktualizacja animacji
		updateAnimations(dt);

		CActor::updateComponents(dt);

		////opakowaæ do metody...(CActor) Begin
		//if(m_engine_data.getEngine())
		//	updateEngine(dt);

		//if(m_energy_data.getEnergy())
		//	updateEnergy(dt);

		//if(m_airconditiong_data.getAirconditioning())
		//	updateAirconditioning(dt);

		//if(m_ventilator_data.getVentilator())
		//	updateVentilator(dt);

		////aktualizuja temperatury
		//updateTemperature(dt);

		//opakowaæ do metody...(CActor) End
	}


	//implementacja metod protected:

	//Metoda aktualizuje komponenty
	void CActor::updateComponents(float dt)
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

	//metoda aktualizuje funkcjonalnoœæ Engine
	void CActor::updateEngine(float dt)
	{
		//transformacja
		m_engine_data.Transform(this, m_engine_data.getEngine());
	}

	//metoda aktualizuje funkcjonalnoœæ Energy
	void CActor::updateEnergy(float dt)
	{
		//transformacja
		m_energy_data.Transform(this, m_energy_data.getEnergy());
	}

	//metoda aktualizuje funkcjonalnoœæ Airconditioning
	void CActor::updateAirconditioning(float dt)
	{
		if (m_airconditiong_data.getAirconditioning())//modu³ klimatyzatora
		{
			if(m_energy_data.getEnergy())//modu³ klimatyzatora zu¿ywa energiê
			{
				if(m_energy_data.getEnergy()->getEnergyTank()->getEnergy())//w akumulatorze jest energia
					m_energy_data.getEnergy()->getEnergyTank()->setEnergy(m_energy_data.getEnergy()->getEnergyTank()->getEnergy() - m_airconditiong_data.getAirconditioning()->getEnergyConsumption());
			}
		}

		//transformacja
		m_airconditiong_data.Transform(this, m_airconditiong_data.getAirconditioning());
	}

	//metoda aktualizuje funkcjonalnoœæ Ventilator
	void CActor::updateVentilator(float dt)
	{
		if(m_ventilator_data.getVentilator())//mudu³ klimatyzatora
		{
			if(m_energy_data.getEnergy())//modu³ wentylatora zu¿ywa energiê
			{
				if(m_energy_data.getEnergy()->getEnergyTank()->getEnergy())//w akumulatorze jest energia
					m_energy_data.getEnergy()->getEnergyTank()->setEnergy(m_energy_data.getEnergy()->getEnergyTank()->getEnergy() - m_ventilator_data.getVentilator()->getEnergyConsumptionFactor());
			}
		}

		//transformacja
		m_ventilator_data.Transform(this, m_ventilator_data.getVentilator());
	}

	//metoda aktualizuje funkcjonalnoœæ Gun
	void CActor::updateGun(float dt)
	{
		//logic...
		//transformacja
		m_gun_data.Transform(this, m_gun_data.getGun());
	}

	//metoda aktualizuje temperaturê
	void CActor::updateTemperature(float dt)
	{
		//obiekt posiada modu³ klimatyzatora
		if(m_airconditiong_data.getAirconditioning())
		{
			//jeœli urz¹dzenie jest w³¹czone
			if(m_airconditiong_data.getAirconditioning()->getUnitController().getState())
				//temperatura modu³u klimatyzatora
				m_technical_data.setTemperature(m_airconditiong_data.getAirconditioning()->getTemperature());
			else
				//temperatura otoczenia
				m_technical_data.setTemperature(gWeather.getTemperature());
		}
		//obiekt nie posiada modu³u klimatyzatora
		else				
			//temperatura otoczenia
			m_technical_data.setTemperature(gWeather.getTemperature());
		
		//obiekt posiada modu³ wentylatora (poprawka temperatury - wentylator)
		//przy temperaturze dodatniej sch³adza, przy ujemnej nagrzewa
		if(m_ventilator_data.getVentilator())
			m_technical_data.setTemperature(m_technical_data.getTemperature() - m_ventilator_data.getVentilator()->getPerformanceFactor());
	}

	//metoda ustawia zestaw animacji - body
	void CActor::SetAnimSetBody(CAnimSet *anim_set)
	{
		//jeœli zestaw animacji jest zainicjowany
		if (p_anim_set)//body
		{
			//p³ynna zmiana animacji - body
			CAnimation *curr_anim = GetAnimationBody();

			//kontener przechowuj¹cy stary (dotychczasowy) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &old_anims = p_anim_set->GetAnims();

			//kontener przechowuj¹cy nowy (parametr tej metody) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &new_anims = anim_set->GetAnims();

			//indeks, pod którym mo¿e znajdowaæ siê szukana animacja
			unsigned int index = -1;

			//przeszukujê stary zestaw animacji, aby odszukaæ w nim animacjê do podmiany
			for (unsigned int i = 0; i < old_anims.size(); i++)
			{
				//jeœli znalaz³em szukan¹ animacjê w starym (dotychczasowym) kontenerze
				if (old_anims[i].GetAnimation() == curr_anim)
				{
					index = i;	//zapamiêtujê pod jakim jest indeksem w kontenerze
					break;		//i przerywam przeszukiwanie
				}
			}

			//jeœli indeks jest wiêkszy od zera oraz indeks jest mniejszy od rozmiaru kontenera
			//z zestawem (nie mo¿na przekroczyæ rozmiaru nowego kontenera)
			//i w nowym zestawie (parametr), pod tym indeksem jest animacja
			if ((index >= 0) && (index < new_anims.size()) && (new_anims[index].GetAnimation() != NULL))
			{
				//zapamiêtujê czas trwania bie¿¹cej animacji
				float currTime = GetDisplayableBody()->GetAnimationState()->GetCurrentTime();

				//podmieniam star¹ animacjê ze starego zestawu na now¹ animacjê z nowego zestawu
				SetAnimationBody(new_anims[index].GetAnimation());

				//przewijam animacjê do "czasu", w którym rozpocz¹³ siê proces podmiany animacji
				GetDisplayableBody()->GetAnimationState()->RewindTo(currTime);
			}
		}
	}

	//metoda pomocnicza - metoda ustawia zestaw animacji - head
	void CActor::SetAnimSetHead(CAnimSet *anim_set)
	{
		//jeœli zestaw animacji jest zainicjowany
		if (p_anim_set)//head
		{
			//p³ynna zmiana animacji - head
			CAnimation *curr_anim = GetAnimationHead();

			//kontener przechowuj¹cy stary (dotychczasowy) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &old_anims = p_anim_set->GetAnims();

			//kontener przechowuj¹cy nowy (parametr tej metody) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &new_anims = anim_set->GetAnims();

			//indeks, pod którym mo¿e znajdowaæ siê szukana animacja
			unsigned int index = -1;

			//przeszukujê stary zestaw animacji, aby odszukaæ w nim animacjê do podmiany
			for (unsigned int i = 0; i < old_anims.size(); i++)
			{
				//jeœli znalaz³em szukan¹ animacjê w starym (dotychczasowym) kontenerze
				if (old_anims[i].GetAnimation() == curr_anim)
				{
					index = i;	//zapamiêtujê pod jakim jest indeksem w kontenerze
					break;		//i przerywam przeszukiwanie
				}
			}

			//jeœli indeks jest wiêkszy od zera oraz indeks jest mniejszy od rozmiaru kontenera
			//z zestawem (nie mo¿na przekroczyæ rozmiaru nowego kontenera)
			//i w nowym zestawie (parametr), pod tym indeksem jest animacja
			if ((index >= 0) && (index < new_anims.size()) && (new_anims[index].GetAnimation() != NULL))
			{
				//zapamiêtujê czas trwania bie¿¹cej animacji
				float currTime = GetDisplayableHead()->GetAnimationState()->GetCurrentTime();

				//podmieniam star¹ animacjê ze starego zestawu na now¹ animacjê z nowego zestawu
				SetAnimationHead(new_anims[index].GetAnimation());

				//przewijam animacjê do "czasu", w którym rozpocz¹³ siê proces podmiany animacji
				GetDisplayableHead()->GetAnimationState()->RewindTo(currTime);
			}
		}
	}
}//namespace logic
