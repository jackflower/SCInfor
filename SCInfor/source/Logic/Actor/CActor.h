//  ___________________________________
// | CActor.h - class definition       |
// | Jack Flower - December 2012       |
// |___________________________________|
//

#ifndef H_ACTOR_JACK
#define H_ACTOR_JACK

#include "ActorStateData/CActorStateData.h"
#include "../Physical/CPhysical.h"
#include "../Physics/CActorTechnicalData.h"
#include "../../Equipment/EquipmentData/EquipmentEngineData.h"
#include "../../Equipment/EquipmentData/EquipmentEnergyData.h"
#include "../../Equipment/EquipmentData/EquipmentAirconditioningData.h"
#include "../../Equipment/EquipmentData/EquipmentVentilatorData.h"
#include "../../Equipment/EquipmentData/EquipmentGunData.h"

using namespace physics;
using namespace physics::technical;

///
///Forward declaration
///
namespace rendering
{
	namespace displayable
	{
		class CDisplayable;
	}

	namespace animation
	{
		class CAnimSet;
	}
}

///
///Forward declaration
///
namespace equipment
{
	class Engine;
	class Energy;
	class Airconditioning;
	class Ventilator;
	namespace weapon
	{
		class Gun;
	}
}

///
///Forward declaration
///
namespace logic
{
	class CActorController;
}

using namespace transformation;
using namespace equipment;
using namespace equipmentdata;
using namespace statesdata;
using namespace equipment::weapon;

namespace logic
{
	///
	///Klasa reprezentuje klas� bazow�, z kt�rej dziedzicz� wszystkie obiekty sceny np. CEnemy, CPlayer, etc...
	///
	class CActor : public CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
		
		//Aby uzyska� obiekt CActor, nale�y wywo�a� CPhysicalManager::CreateActor();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		CActor(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CActorCopy - obiekt klasy CActor
		///
		CActor(const CActor &CActorCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CActor(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca mas� obiektu
		///
		const float getMass() const;

		///
		///Metoda ustawia mas� obiektu
		///
		///@param mass - masa obiektu
		///
		const void setMass(float mass);

		///
		///Metoda zwraca temperatur�
		///
		const float getTemperature() const;

		///
		///Metoda ustawia temperatur�
		///
		///@param temperature - temperatura
		///
		const void setTemperature(float temperature);

		///
		///Metoda zwraca flag�, czy obiekt si� porusza
		///
		bool const getIsMove() const;

		///
		///Metoda ustawia flag�, �e obiekt si� porusza
		///
		///@param is_move - flaga, czy obiekt si� porusza
		///
		const void setIsMove(bool is_move);

		///
		///Metoda zwraca flag�, czy obiekt mo�e si� przemieszcza�
		///
		const bool getIsMovabled() const;

		///
		///Metoda ustawia flag�, czy obiekt mo�e si� przemieszcza�
		///
		///@param movabled - parametr okre�laj�cy, czy obiekt mo�e si� przemieszcza�
		///
		const void setIsMovabled(bool movabled);

		///
		///Metoda zwraca pr�dko�� obiektu
		///
		const float getSpeed() const;

		///
		///Metoda ustawia pr�dko�� obiektu
		///
		///@param speed - pr�dko�� obiektu
		///
		const void setSpeed(float speed);

		///
		///Metoda zwraca wska�nik na zestaw animacji
		///
		CAnimSet *GetAnimSet();

		///
		///Metoda ustawia zestaw animacji
		///
		///@param *anim_set - wska�nik na obiekt klasy CAnimSet
		///
		void SetAnimSet(CAnimSet *anim_set);

		///
		///Metoda zwraca referencj� na klas� bed�c� opakowaniem fizyki
		///
		CActorTechnicalData & getTechnicalData();

		///
		///Metoda ustawia referencj� na klas� bed�c� opakowaniem fizyki
		///
		///@param & technical_data - referencja na opakowanie fizyki
		///
		void setTechnicalData (CActorTechnicalData & technical_data);

		///
		///Metoda zwraca flag�, czy obiekt posiada silnik
		///
		const bool GetUseEngine() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada silnik
		///
		///@param use_engine - flaga, czy obiekt posiada engine
		///
		void SetUseEngine(bool use_engine);

		///
		///Metoda zwraca flag�, czy obiekt posiada akumulator energii
		///
		const bool GetUseEnergy() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada akumulator energii
		///
		///@param use_energy - flaga, czy obiekt posiada akumulator energii
		///
		void SetUseEnergy(bool use_energy);

		///
		///Metoda zwraca flag�, czy obiekt posiada dzia�o
		///
		const bool GetUseGun() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada dzia�o
		///
		///@param use_gun - flaga, czy obiekt posiada dzia�o
		///
		void SetUseGun(bool use_gun);

		///
		///Metoda zwraca flag�, czy obiekt posiada modu� klimatyzatora
		///
		const bool GetUseAirconditioning() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada modu� klimatyzatora
		///
		///@param use_airconditioning - flaga, czy obiekt posiada modu� klimatyzatora
		///
		void SetUseAirconditioning(bool use_airconditioning);

		///
		///Metoda zwraca flag�, czy obiekt posiada modu� wentylatora
		///
		const bool GetUseWentilator() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada modu� wentylatora
		///
		///
		///@param use_ventilator - flaga, czy obiekt posiada modu� wentylatora
		///
		void SetUseWentilator(bool use_ventilator);

		///
		///Metoda zwraca wska�nik na obiekt klasy Engine
		///
		Engine* GetEngine();

		///
		///Metoda ustawia wska�nik na obiekt klasy Engine
		///
		///@param *engine - wska�nik na obiekt klasy Engine
		///
		void SetEngine(Engine* engine);

		///
		///Metoda zwraca referencj� na opakowanie danych dla transformacji
		///
		CTransformation & getEngineTransformed();

		///
		///Metoda ustawia referencj� na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setEngineTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencj� na opakowanie danych dla transformacji
		///
		CTransformation & getEnergyTransformed();

		///
		///Metoda ustawia referencj� na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setEnergyTransformed(CTransformation & transformation);
		
		///
		///Metoda zwraca referencj� na opakowanie danych dla transformacji
		///
		CTransformation & getAirconditioningTransformed();

		///
		///Metoda ustawia referencj� na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setAirconditioningTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencj� na opakowanie danych dla transformacji
		///
		CTransformation & getVentilatorTransformed();

		///
		///Metoda ustawia referencj� na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setVentilatorTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencj� na opakowanie danych dla transformacji
		///
		CTransformation & getGunTransformed();

		///
		///Metoda ustawia referencj� na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setGunTransformed(CTransformation & transformation);

		///
		///Metoda zwraca wska�nik na obiekt klasy Energy
		///
		Energy* GetEnergy();

		///
		///Metoda ustawia wska�nik na obiekt klasy Energy
		///
		///@param *engine - wska�nik na obiekt klasy Energy
		///
		void SetEnergy(Energy* energy);

		///
		///Metoda zwraca wska�nik na obiekt klasy Airconditioning
		///
		Airconditioning* GetAirconditioning();

		///
		///Metoda ustawia wska�nik na obiekt klasy Airconditioning
		///
		///@param *airconditioning - wska�nik na obiekt klasy Airconditioning
		///
		void SetAirconditioning(Airconditioning* airconditioning);

		///
		///Metoda zwraca wska�nik na obiekt klasy Ventilator
		///
		Ventilator* GetVentilator();

		///
		///Metoda ustawia wska�nik na obiekt klasy Ventilator
		///
		///@param *ventilator - wska�nik na obiekt klasy Ventilator
		///
		void SetVentilator(Ventilator* ventilator);

		///
		///Metoda zwraca wska�nik na obiekt klasy Gun
		///
		Gun* GetGun();

		///
		///Metoda ustawia wska�nik na obiekt klasy Gun
		///
		///@param *gun - wska�nik na obiekt klasy Gun
		///
		void SetGun(Gun* gun);

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca opakowanie stan�w obiektu
		///
		const CActorStateData & getStateData() const;

		///
		///Metoda ustawia opakowanie stan�w obiektu
		///
		///@param & state_data - sta�a referencja na obiekt klasy CActorStateData - opakowanie stan�w obiektu
		///
		void getStateData(const CActorStateData & state_data);

		///
		///Metoda zwraca stan obiektu - aktualizcja reprezentacji obiektu
		///
		const EActorBasicState & getBasicState() const;

		///
		///Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
		///
		///@param & basic_state - sta�a referencja na wylicznie stan�w obiektu
		///
		void setBasicState(const EActorBasicState & basic_state);

		///
		///Metoda zwraca stan ruchu obiektu
		///
		const EActorMoveState & getMoveState() const;

		///
		///Metoda ustawia stan ruchu obiektu
		///
		///@param & move_state - sta�a referencja na wylicznie stan�w ruchu obiektu
		///
		void setMoveState(const EActorMoveState & move_state);

		///
		///Metoda zwraca stan behawioralny obiektu
		///
		const EActorSpawnState & getSpawnState() const;

		///
		///Metoda ustawia stan behawioralny obiektu
		///
		///@param & spawn_state - sta�a referencja na wyliczenie stan�w behawioralnych obiektu (procesy �yciowe, trwanie)
		///
		void setSpawnState(const EActorSpawnState & spawn_state);

		///
		///Wirtualan metoda zabija obiekt klasy CActor i wywo�uje odpowiednie czynno�ci z tym zwi�zane
		///
		virtual void Kill();

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:

		CAnimSet*						p_anim_set;				//wska�nik na obiekt klasy CAnimSet (zestaw animacji)
		CActorTechnicalData				m_technical_data;		//opakowanie fizyki
		EquipmentEngineData			m_engine_data;			//opakowanie funkcjonalno�ci silnika
		EquipmentEnergyData			m_energy_data;			//opakowanie funkcjonalno�ci energii
		EquipmentAirconditioningData	m_airconditiong_data;	//opakowanie funkcjonalno�ci klimatyzatora
		EquipmentVentilatorData		m_ventilator_data;		//opakowanie funkcjonalno�ci wentylatora
		EquipmentGunData				m_gun_data;				//opakowanie funkcjonalno�ci dzia�a
		CActorStateData					m_state_data;			//opakowanie wyliczenia stan�w
		CActorController*				p_actor_controller;		//obiekt klasy CActorController - funkcjonalno�� sterowania

	protected:

		//Metoda aktualizuje komponenty
		void updateComponents(float dt);
		
	private:
		//metoda aktualizuje funkcjonalno�� Engine
		void updateEngine(float dt);

		//metoda aktualizuje funkcjonalno�� Energy
		void updateEnergy(float dt);
		
		//metoda aktualizuje funkcjonalno�� Airconditioning
		void updateAirconditioning(float dt);

		//metoda aktualizuje funkcjonalno�� Ventilator
		void updateVentilator(float dt);

		//metoda aktualizuje funkcjonalno�� Gun
		void updateGun(float dt);

		//metoda aktualizuje temperatur� (wn�trze lub organizm)
		void updateTemperature(float dt);

		//metoda pomocnicza - metoda ustawia zestaw animacji - body
		void SetAnimSetBody(CAnimSet *anim_set);

		//metoda pomocnicza - metoda ustawia zestaw animacji - head
		void SetAnimSetHead(CAnimSet *anim_set);
	};
}//namespace logic
#endif //H_ACTOR_JACK
