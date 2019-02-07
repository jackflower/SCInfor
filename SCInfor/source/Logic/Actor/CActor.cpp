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

	//Chroniony konstruktor domy�lny
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

	//Chroniony konstruktor kopiuj�cy
	CActor::CActor(const CActor &CActorCopy)
	:
		CPhysical				(CActorCopy),//konstruktor kopiuj�cy klasy bazowej
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

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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

	//Metoda zwraca mas� obiektu
	const float CActor::getMass() const
	{
		return m_technical_data.getMass();
	}

	//Metoda ustawia mas� obiektu
	const void CActor::setMass(float mass)
	{
		if (mass < 0) return;
		m_technical_data.setMass(mass);
	}

	//Metoda zwraca temperatur�
	const float CActor::getTemperature() const
	{
		return m_technical_data.getTemperature();
	}

	//Metoda ustawia temperatur�
	const void CActor::setTemperature(float temperature)
	{
		m_technical_data.setTemperature(temperature);
	}

	//Metoda zwraca flag�, czy obiekt si� porusza
	bool const CActor::getIsMove() const
	{
		return m_technical_data.getIsMove();
	}

	//Metoda ustawia flag�, �e obiekt si� porusza
	const void CActor::setIsMove(bool is_move)
	{
		m_technical_data.setIsMove(is_move);
	}

	//Metoda zwraca flag�, czy obiekt mo�e si� przemieszcza�
	const bool CActor::getIsMovabled() const
	{
		return m_technical_data.getIsMovabled();
	}

	//Metoda ustawia flag�, czy obiekt mo�e si� przemieszcza�
	const void CActor::setIsMovabled(bool movabled)
	{
		m_technical_data.setIsMovabled(movabled);
	}

	//Metoda zwraca pr�dko�� obiektu
	const float CActor::getSpeed() const
	{
		return m_technical_data.getSpeed();
	}

	//Metoda ustawia pr�dko�� obiektu
	const void CActor::setSpeed(float speed)
	{
		if (speed < 0) return;
		m_technical_data.setSpeed(speed);
	}

	//Metoda zwraca wska�nik na zestaw animacji
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

	//Metoda zwraca referencj� na klas� bed�c� opakowaniem fizyki
	CActorTechnicalData & CActor::getTechnicalData()
	{
		return m_technical_data;
	}

	//Metoda ustawia referencj� na klas� bed�c� opakowaniem fizyki
	void CActor::setTechnicalData(CActorTechnicalData & technical_data)
	{
		m_technical_data = technical_data;
	}

	//Metoda zwraca flag�, czy obiekt posiada silnik
	const bool CActor::GetUseEngine() const
	{
		return m_engine_data.getUseEquipment();
	}

	//Metoda ustawia flag�, czy obiekt posiada silnik
	void CActor::SetUseEngine(bool use_engine)
	{
		m_engine_data.setUseEquipment(use_engine);
	}

	//Metoda zwraca flag�, czy obiekt posiada akumulator energii
	const bool CActor::GetUseEnergy() const
	{
		return m_energy_data.getUseEquipment();
	}

	//Metoda ustawia flag�, czy obiekt posiada akumulator energii
	void CActor::SetUseEnergy(bool use_energy)
	{
		m_energy_data.setUseEquipment(use_energy);
	}

	//Metoda zwraca flag�, czy obiekt posiada dzia�o
	const bool CActor::GetUseGun() const
	{
		return m_gun_data.getUseEquipment();
	}

	//Metoda ustawia flag�, czy obiekt posiada dzia�o
	void CActor::SetUseGun(bool use_gun)
	{
		m_gun_data.setUseEquipment(use_gun);
	}

	//Metoda zwraca flag�, czy obiekt posiada modu� klimatyzatora
	const bool CActor::GetUseAirconditioning() const
	{
		return m_airconditiong_data.getUseEquipment();
	}

	//Metoda ustawia flag�, czy obiekt posiada modu� klimatyzatora
	void CActor::SetUseAirconditioning(bool use_airconditioning)
	{
		m_airconditiong_data.setUseEquipment(use_airconditioning);
	}

	//Metoda zwraca flag�, czy obiekt posiada modu� wentylatora
	const bool CActor::GetUseWentilator() const
	{
		return m_ventilator_data.getUseEquipment();
	}

	//Metoda ustawia flag�, czy obiekt posiada modu� wentylatora
	void CActor::SetUseWentilator(bool use_ventilator)
	{
		m_ventilator_data.setUseEquipment(use_ventilator);
	}

	//Metoda zwraca wska�nik na obiekt klasy Engine
	Engine* CActor::GetEngine()
	{
		return m_engine_data.getEngine();
	}

	//Metoda ustawia wska�nik na obiekt klasy Engine
	void CActor::SetEngine(Engine* engine)
	{
		m_engine_data.setEngine(engine);
	}

	//Metoda zwraca referencj� na opakowanie danych dla transformacji
	CTransformation & CActor::getEngineTransformed()
	{
		return m_engine_data.getTransformed();
	}

	//Metoda ustawia referencj� na opakowanie danych dla transformacji
	void CActor::setEngineTransformed(CTransformation & transformation)
	{
		m_engine_data.setTransformed(transformation);
	}

	//Metoda zwraca referencj� na opakowanie danych dla transformacji
	CTransformation & CActor::getEnergyTransformed()
	{
		return m_energy_data.getTransformed();
	}

	//Metoda ustawia referencj� na opakowanie danych dla transformacji
	void CActor::setEnergyTransformed(CTransformation & transformation)
	{
		m_energy_data.setTransformed(transformation);
	}

	//Metoda zwraca referencj� na opakowanie danych dla transformacji
	CTransformation & CActor::getAirconditioningTransformed()
	{
		return m_airconditiong_data.getTransformed();
	}

	//Metoda ustawia referencj� na opakowanie danych dla transformacji
	void CActor::setAirconditioningTransformed(CTransformation & transformation)
	{
		m_airconditiong_data.setTransformed(transformation);
	}
	
	//Metoda zwraca referencj� na opakowanie danych dla transformacji
	CTransformation & CActor::getVentilatorTransformed()
	{
		return m_ventilator_data.getTransformed();
	}

	//Metoda ustawia referencj� na opakowanie danych dla transformacji
	void CActor::setVentilatorTransformed(CTransformation & transformation)
	{
		m_ventilator_data.setTransformed(transformation);
	}

	//Metoda zwraca referencj� na opakowanie danych dla transformacji
	CTransformation & CActor::getGunTransformed()
	{
		return m_gun_data.getTransformed();
	}

	//Metoda ustawia referencj� na opakowanie danych dla transformacji
	void CActor::setGunTransformed(CTransformation & transformation)
	{
		m_gun_data.setTransformed(transformation);
	}

	//Metoda zwraca wska�nik na obiekt klasy Energy
	Energy* CActor::GetEnergy()
	{
		return m_energy_data.getEnergy();
	}

	//Metoda ustawia wska�nik na obiekt klasy Energy
	void CActor::SetEnergy(Energy* energy)
	{
		m_energy_data.setEnergy(energy);
	}

	//Metoda zwraca wska�nik na obiekt klasy Airconditioning
	Airconditioning* CActor::GetAirconditioning()
	{
		return m_airconditiong_data.getAirconditioning();
	}

	//Metoda ustawia wska�nik na obiekt klasy Airconditioning
	void CActor::SetAirconditioning(Airconditioning* airconditioning)
	{
		m_airconditiong_data.setAirconditioning(airconditioning);
	}

	//Metoda zwraca wska�nik na obiekt klasy Ventilator
	Ventilator* CActor::GetVentilator()
	{
		return m_ventilator_data.getVentilator();
	}

	//Metoda ustawia wska�nik na obiekt klasy Ventilator
	void CActor::SetVentilator(Ventilator* ventilator)
	{
		m_ventilator_data.setVentilator(ventilator);
	}

	//Metoda zwraca wska�nik na obiekt klasy Gun
	Gun* CActor::GetGun()
	{
		return m_gun_data.getGun();
	}

	//Metoda ustawia wska�nik na obiekt klasy Gun
	///
	void CActor::SetGun(Gun* gun)
	{
		m_gun_data.setGun(gun);
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
	void CActor::updateAnimations(float dt)
	{
		//aktualizacja aktora w zale�no�ci od EActorState
		//(ten plik b�dzie dopiero utworzony)
		//actor state - future...
		//test:
		//SetAnimationBody(p_anim_set->GetMoveAnimBody());
	}

	//Metoda zwraca opakowanie stan�w obiektu
	const CActorStateData & CActor::getStateData() const
	{
		return m_state_data;
	}

	//Metoda ustawia opakowanie stan�w obiektu
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

	//Wirtualan metoda zabija obiekt klasy CActor i wywo�uje odpowiednie czynno�ci z tym zwi�zane
	void CActor::Kill()
	{
		CPhysical::Kill();
		//to do...
	}

	//Wirtualna metoda aktualizuj�ca obiekt
	void CActor::update(float dt)
	{
		//aktualizacja klasy bazowej
		CPhysical::update(dt);		

		//aktualizacja animacji
		updateAnimations(dt);

		CActor::updateComponents(dt);

		////opakowa� do metody...(CActor) Begin
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

		//opakowa� do metody...(CActor) End
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

	//metoda aktualizuje funkcjonalno�� Engine
	void CActor::updateEngine(float dt)
	{
		//transformacja
		m_engine_data.Transform(this, m_engine_data.getEngine());
	}

	//metoda aktualizuje funkcjonalno�� Energy
	void CActor::updateEnergy(float dt)
	{
		//transformacja
		m_energy_data.Transform(this, m_energy_data.getEnergy());
	}

	//metoda aktualizuje funkcjonalno�� Airconditioning
	void CActor::updateAirconditioning(float dt)
	{
		if (m_airconditiong_data.getAirconditioning())//modu� klimatyzatora
		{
			if(m_energy_data.getEnergy())//modu� klimatyzatora zu�ywa energi�
			{
				if(m_energy_data.getEnergy()->getEnergyTank()->getEnergy())//w akumulatorze jest energia
					m_energy_data.getEnergy()->getEnergyTank()->setEnergy(m_energy_data.getEnergy()->getEnergyTank()->getEnergy() - m_airconditiong_data.getAirconditioning()->getEnergyConsumption());
			}
		}

		//transformacja
		m_airconditiong_data.Transform(this, m_airconditiong_data.getAirconditioning());
	}

	//metoda aktualizuje funkcjonalno�� Ventilator
	void CActor::updateVentilator(float dt)
	{
		if(m_ventilator_data.getVentilator())//mudu� klimatyzatora
		{
			if(m_energy_data.getEnergy())//modu� wentylatora zu�ywa energi�
			{
				if(m_energy_data.getEnergy()->getEnergyTank()->getEnergy())//w akumulatorze jest energia
					m_energy_data.getEnergy()->getEnergyTank()->setEnergy(m_energy_data.getEnergy()->getEnergyTank()->getEnergy() - m_ventilator_data.getVentilator()->getEnergyConsumptionFactor());
			}
		}

		//transformacja
		m_ventilator_data.Transform(this, m_ventilator_data.getVentilator());
	}

	//metoda aktualizuje funkcjonalno�� Gun
	void CActor::updateGun(float dt)
	{
		//logic...
		//transformacja
		m_gun_data.Transform(this, m_gun_data.getGun());
	}

	//metoda aktualizuje temperatur�
	void CActor::updateTemperature(float dt)
	{
		//obiekt posiada modu� klimatyzatora
		if(m_airconditiong_data.getAirconditioning())
		{
			//je�li urz�dzenie jest w��czone
			if(m_airconditiong_data.getAirconditioning()->getUnitController().getState())
				//temperatura modu�u klimatyzatora
				m_technical_data.setTemperature(m_airconditiong_data.getAirconditioning()->getTemperature());
			else
				//temperatura otoczenia
				m_technical_data.setTemperature(gWeather.getTemperature());
		}
		//obiekt nie posiada modu�u klimatyzatora
		else				
			//temperatura otoczenia
			m_technical_data.setTemperature(gWeather.getTemperature());
		
		//obiekt posiada modu� wentylatora (poprawka temperatury - wentylator)
		//przy temperaturze dodatniej sch�adza, przy ujemnej nagrzewa
		if(m_ventilator_data.getVentilator())
			m_technical_data.setTemperature(m_technical_data.getTemperature() - m_ventilator_data.getVentilator()->getPerformanceFactor());
	}

	//metoda ustawia zestaw animacji - body
	void CActor::SetAnimSetBody(CAnimSet *anim_set)
	{
		//je�li zestaw animacji jest zainicjowany
		if (p_anim_set)//body
		{
			//p�ynna zmiana animacji - body
			CAnimation *curr_anim = GetAnimationBody();

			//kontener przechowuj�cy stary (dotychczasowy) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &old_anims = p_anim_set->GetAnims();

			//kontener przechowuj�cy nowy (parametr tej metody) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &new_anims = anim_set->GetAnims();

			//indeks, pod kt�rym mo�e znajdowa� si� szukana animacja
			unsigned int index = -1;

			//przeszukuj� stary zestaw animacji, aby odszuka� w nim animacj� do podmiany
			for (unsigned int i = 0; i < old_anims.size(); i++)
			{
				//je�li znalaz�em szukan� animacj� w starym (dotychczasowym) kontenerze
				if (old_anims[i].GetAnimation() == curr_anim)
				{
					index = i;	//zapami�tuj� pod jakim jest indeksem w kontenerze
					break;		//i przerywam przeszukiwanie
				}
			}

			//je�li indeks jest wi�kszy od zera oraz indeks jest mniejszy od rozmiaru kontenera
			//z zestawem (nie mo�na przekroczy� rozmiaru nowego kontenera)
			//i w nowym zestawie (parametr), pod tym indeksem jest animacja
			if ((index >= 0) && (index < new_anims.size()) && (new_anims[index].GetAnimation() != NULL))
			{
				//zapami�tuj� czas trwania bie��cej animacji
				float currTime = GetDisplayableBody()->GetAnimationState()->GetCurrentTime();

				//podmieniam star� animacj� ze starego zestawu na now� animacj� z nowego zestawu
				SetAnimationBody(new_anims[index].GetAnimation());

				//przewijam animacj� do "czasu", w kt�rym rozpocz�� si� proces podmiany animacji
				GetDisplayableBody()->GetAnimationState()->RewindTo(currTime);
			}
		}
	}

	//metoda pomocnicza - metoda ustawia zestaw animacji - head
	void CActor::SetAnimSetHead(CAnimSet *anim_set)
	{
		//je�li zestaw animacji jest zainicjowany
		if (p_anim_set)//head
		{
			//p�ynna zmiana animacji - head
			CAnimation *curr_anim = GetAnimationHead();

			//kontener przechowuj�cy stary (dotychczasowy) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &old_anims = p_anim_set->GetAnims();

			//kontener przechowuj�cy nowy (parametr tej metody) zestaw animacji
			const std::vector<CNameAnimPairTranslator> &new_anims = anim_set->GetAnims();

			//indeks, pod kt�rym mo�e znajdowa� si� szukana animacja
			unsigned int index = -1;

			//przeszukuj� stary zestaw animacji, aby odszuka� w nim animacj� do podmiany
			for (unsigned int i = 0; i < old_anims.size(); i++)
			{
				//je�li znalaz�em szukan� animacj� w starym (dotychczasowym) kontenerze
				if (old_anims[i].GetAnimation() == curr_anim)
				{
					index = i;	//zapami�tuj� pod jakim jest indeksem w kontenerze
					break;		//i przerywam przeszukiwanie
				}
			}

			//je�li indeks jest wi�kszy od zera oraz indeks jest mniejszy od rozmiaru kontenera
			//z zestawem (nie mo�na przekroczy� rozmiaru nowego kontenera)
			//i w nowym zestawie (parametr), pod tym indeksem jest animacja
			if ((index >= 0) && (index < new_anims.size()) && (new_anims[index].GetAnimation() != NULL))
			{
				//zapami�tuj� czas trwania bie��cej animacji
				float currTime = GetDisplayableHead()->GetAnimationState()->GetCurrentTime();

				//podmieniam star� animacj� ze starego zestawu na now� animacj� z nowego zestawu
				SetAnimationHead(new_anims[index].GetAnimation());

				//przewijam animacj� do "czasu", w kt�rym rozpocz�� si� proces podmiany animacji
				GetDisplayableHead()->GetAnimationState()->RewindTo(currTime);
			}
		}
	}
}//namespace logic
