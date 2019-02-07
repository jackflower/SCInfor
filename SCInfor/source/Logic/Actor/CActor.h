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
	///Klasa reprezentuje klasê bazow¹, z której dziedzicz¹ wszystkie obiekty sceny np. CEnemy, CPlayer, etc...
	///
	class CActor : public CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskaæ obiekt CActor, nale¿y wywo³aæ CPhysicalManager::CreateActor();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		CActor(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CActorCopy - obiekt klasy CActor
		///
		CActor(const CActor &CActorCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CActor(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca masê obiektu
		///
		const float getMass() const;

		///
		///Metoda ustawia masê obiektu
		///
		///@param mass - masa obiektu
		///
		const void setMass(float mass);

		///
		///Metoda zwraca temperaturê
		///
		const float getTemperature() const;

		///
		///Metoda ustawia temperaturê
		///
		///@param temperature - temperatura
		///
		const void setTemperature(float temperature);

		///
		///Metoda zwraca flagê, czy obiekt siê porusza
		///
		bool const getIsMove() const;

		///
		///Metoda ustawia flagê, ¿e obiekt siê porusza
		///
		///@param is_move - flaga, czy obiekt siê porusza
		///
		const void setIsMove(bool is_move);

		///
		///Metoda zwraca flagê, czy obiekt mo¿e siê przemieszczaæ
		///
		const bool getIsMovabled() const;

		///
		///Metoda ustawia flagê, czy obiekt mo¿e siê przemieszczaæ
		///
		///@param movabled - parametr okreœlaj¹cy, czy obiekt mo¿e siê przemieszczaæ
		///
		const void setIsMovabled(bool movabled);

		///
		///Metoda zwraca prêdkoœæ obiektu
		///
		const float getSpeed() const;

		///
		///Metoda ustawia prêdkoœæ obiektu
		///
		///@param speed - prêdkoœæ obiektu
		///
		const void setSpeed(float speed);

		///
		///Metoda zwraca wskaŸnik na zestaw animacji
		///
		CAnimSet *GetAnimSet();

		///
		///Metoda ustawia zestaw animacji
		///
		///@param *anim_set - wskaŸnik na obiekt klasy CAnimSet
		///
		void SetAnimSet(CAnimSet *anim_set);

		///
		///Metoda zwraca referencjê na klasê bed¹c¹ opakowaniem fizyki
		///
		CActorTechnicalData & getTechnicalData();

		///
		///Metoda ustawia referencjê na klasê bed¹c¹ opakowaniem fizyki
		///
		///@param & technical_data - referencja na opakowanie fizyki
		///
		void setTechnicalData (CActorTechnicalData & technical_data);

		///
		///Metoda zwraca flagê, czy obiekt posiada silnik
		///
		const bool GetUseEngine() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada silnik
		///
		///@param use_engine - flaga, czy obiekt posiada engine
		///
		void SetUseEngine(bool use_engine);

		///
		///Metoda zwraca flagê, czy obiekt posiada akumulator energii
		///
		const bool GetUseEnergy() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada akumulator energii
		///
		///@param use_energy - flaga, czy obiekt posiada akumulator energii
		///
		void SetUseEnergy(bool use_energy);

		///
		///Metoda zwraca flagê, czy obiekt posiada dzia³o
		///
		const bool GetUseGun() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada dzia³o
		///
		///@param use_gun - flaga, czy obiekt posiada dzia³o
		///
		void SetUseGun(bool use_gun);

		///
		///Metoda zwraca flagê, czy obiekt posiada modu³ klimatyzatora
		///
		const bool GetUseAirconditioning() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada modu³ klimatyzatora
		///
		///@param use_airconditioning - flaga, czy obiekt posiada modu³ klimatyzatora
		///
		void SetUseAirconditioning(bool use_airconditioning);

		///
		///Metoda zwraca flagê, czy obiekt posiada modu³ wentylatora
		///
		const bool GetUseWentilator() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada modu³ wentylatora
		///
		///
		///@param use_ventilator - flaga, czy obiekt posiada modu³ wentylatora
		///
		void SetUseWentilator(bool use_ventilator);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy Engine
		///
		Engine* GetEngine();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy Engine
		///
		///@param *engine - wskaŸnik na obiekt klasy Engine
		///
		void SetEngine(Engine* engine);

		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getEngineTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setEngineTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getEnergyTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setEnergyTransformed(CTransformation & transformation);
		
		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getAirconditioningTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setAirconditioningTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getVentilatorTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setVentilatorTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getGunTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setGunTransformed(CTransformation & transformation);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy Energy
		///
		Energy* GetEnergy();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy Energy
		///
		///@param *engine - wskaŸnik na obiekt klasy Energy
		///
		void SetEnergy(Energy* energy);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy Airconditioning
		///
		Airconditioning* GetAirconditioning();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy Airconditioning
		///
		///@param *airconditioning - wskaŸnik na obiekt klasy Airconditioning
		///
		void SetAirconditioning(Airconditioning* airconditioning);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy Ventilator
		///
		Ventilator* GetVentilator();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy Ventilator
		///
		///@param *ventilator - wskaŸnik na obiekt klasy Ventilator
		///
		void SetVentilator(Ventilator* ventilator);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy Gun
		///
		Gun* GetGun();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy Gun
		///
		///@param *gun - wskaŸnik na obiekt klasy Gun
		///
		void SetGun(Gun* gun);

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca opakowanie stanów obiektu
		///
		const CActorStateData & getStateData() const;

		///
		///Metoda ustawia opakowanie stanów obiektu
		///
		///@param & state_data - sta³a referencja na obiekt klasy CActorStateData - opakowanie stanów obiektu
		///
		void getStateData(const CActorStateData & state_data);

		///
		///Metoda zwraca stan obiektu - aktualizcja reprezentacji obiektu
		///
		const EActorBasicState & getBasicState() const;

		///
		///Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
		///
		///@param & basic_state - sta³a referencja na wylicznie stanów obiektu
		///
		void setBasicState(const EActorBasicState & basic_state);

		///
		///Metoda zwraca stan ruchu obiektu
		///
		const EActorMoveState & getMoveState() const;

		///
		///Metoda ustawia stan ruchu obiektu
		///
		///@param & move_state - sta³a referencja na wylicznie stanów ruchu obiektu
		///
		void setMoveState(const EActorMoveState & move_state);

		///
		///Metoda zwraca stan behawioralny obiektu
		///
		const EActorSpawnState & getSpawnState() const;

		///
		///Metoda ustawia stan behawioralny obiektu
		///
		///@param & spawn_state - sta³a referencja na wyliczenie stanów behawioralnych obiektu (procesy ¿yciowe, trwanie)
		///
		void setSpawnState(const EActorSpawnState & spawn_state);

		///
		///Wirtualan metoda zabija obiekt klasy CActor i wywo³uje odpowiednie czynnoœci z tym zwi¹zane
		///
		virtual void Kill();

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:

		CAnimSet*						p_anim_set;				//wskaŸnik na obiekt klasy CAnimSet (zestaw animacji)
		CActorTechnicalData				m_technical_data;		//opakowanie fizyki
		EquipmentEngineData			m_engine_data;			//opakowanie funkcjonalnoœci silnika
		EquipmentEnergyData			m_energy_data;			//opakowanie funkcjonalnoœci energii
		EquipmentAirconditioningData	m_airconditiong_data;	//opakowanie funkcjonalnoœci klimatyzatora
		EquipmentVentilatorData		m_ventilator_data;		//opakowanie funkcjonalnoœci wentylatora
		EquipmentGunData				m_gun_data;				//opakowanie funkcjonalnoœci dzia³a
		CActorStateData					m_state_data;			//opakowanie wyliczenia stanów
		CActorController*				p_actor_controller;		//obiekt klasy CActorController - funkcjonalnoœæ sterowania

	protected:

		//Metoda aktualizuje komponenty
		void updateComponents(float dt);
		
	private:
		//metoda aktualizuje funkcjonalnoœæ Engine
		void updateEngine(float dt);

		//metoda aktualizuje funkcjonalnoœæ Energy
		void updateEnergy(float dt);
		
		//metoda aktualizuje funkcjonalnoœæ Airconditioning
		void updateAirconditioning(float dt);

		//metoda aktualizuje funkcjonalnoœæ Ventilator
		void updateVentilator(float dt);

		//metoda aktualizuje funkcjonalnoœæ Gun
		void updateGun(float dt);

		//metoda aktualizuje temperaturê (wnêtrze lub organizm)
		void updateTemperature(float dt);

		//metoda pomocnicza - metoda ustawia zestaw animacji - body
		void SetAnimSetBody(CAnimSet *anim_set);

		//metoda pomocnicza - metoda ustawia zestaw animacji - head
		void SetAnimSetHead(CAnimSet *anim_set);
	};
}//namespace logic
#endif //H_ACTOR_JACK
