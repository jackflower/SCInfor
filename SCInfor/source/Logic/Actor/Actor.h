//  __________________________________
// | Actor.h - class definition       |
// | Jack Flower - December 2012      |
// |__________________________________|
//

#ifndef H_ACTOR_JACK
#define H_ACTOR_JACK

#include "ActorStateData/ActorStateData.h"
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
	class ActorController;
}

using namespace transformation;
using namespace equipment;
using namespace equipmentdata;
using namespace statesdata;
using namespace equipment::weapon;

namespace logic
{
	///
	///Klasa reprezentuje klasę bazową, z której dziedziczą wszystkie obiekty sceny np. Enemy, Player, etc...
	///
	class Actor : public CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskać obiekt Actor, należy wywołać CPhysicalManager::CreateActor();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		Actor(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param ActorCopy - stała referencja na obiekt klasy Actor
		///
		Actor(const Actor & ActorCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		///
		virtual ~Actor();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca masę obiektu
		///
		const float getMass() const;

		///
		///Metoda ustawia masę obiektu
		///
		///@param mass - masa obiektu
		///
		const void setMass(float mass);

		///
		///Metoda zwraca temperaturę
		///
		const float getTemperature() const;

		///
		///Metoda ustawia temperaturę
		///
		///@param temperature - temperatura
		///
		const void setTemperature(float temperature);

		///
		///Metoda zwraca flagę, czy obiekt się porusza
		///
		bool const getIsMove() const;

		///
		///Metoda ustawia flagę, że obiekt się porusza
		///
		///@param is_move - flaga, czy obiekt się porusza
		///
		const void setIsMove(bool is_move);

		///
		///Metoda zwraca flagę, czy obiekt może się przemieszczać
		///
		const bool getIsMovabled() const;

		///
		///Metoda ustawia flagę, czy obiekt może się przemieszczać
		///
		///@param movabled - parametr określający, czy obiekt może się przemieszczać
		///
		const void setIsMovabled(bool movabled);

		///
		///Metoda zwraca prędkość obiektu
		///
		const float getSpeed() const;

		///
		///Metoda ustawia prędkość obiektu
		///
		///@param speed - prędkość obiektu
		///
		const void setSpeed(float speed);

		///
		///Metoda zwraca wskaźnik na zestaw animacji
		///
		CAnimSet *getAnimSet();

		///
		///Metoda ustawia zestaw animacji
		///
		///@param *anim_set - wskaźnik na obiekt klasy CAnimSet
		///
		void setAnimSet(CAnimSet *anim_set);

		///
		///Metoda zwraca referencję na klasę bedącą opakowaniem fizyki
		///
		CActorTechnicalData & getTechnicalData();

		///
		///Metoda ustawia referencję na klasę bedącą opakowaniem fizyki
		///
		///@param technical_data - referencja na opakowanie fizyki
		///
		void setTechnicalData (CActorTechnicalData & technical_data);

		///
		///Metoda zwraca flagę, czy obiekt posiada silnik
		///
		const bool getUseEngine() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada silnik
		///
		///@param use_engine - flaga, czy obiekt posiada engine
		///
		void setUseEngine(bool use_engine);

		///
		///Metoda zwraca flagę, czy obiekt posiada akumulator energii
		///
		const bool getUseEnergy() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada akumulator energii
		///
		///@param use_energy - flaga, czy obiekt posiada akumulator energii
		///
		void setUseEnergy(bool use_energy);

		///
		///Metoda zwraca flagę, czy obiekt posiada działo
		///
		const bool getUseGun() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada działo
		///
		///@param use_gun - flaga, czy obiekt posiada działo
		///
		void setUseGun(bool use_gun);

		///
		///Metoda zwraca flagę, czy obiekt posiada moduł klimatyzatora
		///
		const bool getUseAirconditioning() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada moduł klimatyzatora
		///
		///@param use_airconditioning - flaga, czy obiekt posiada moduł klimatyzatora
		///
		void setUseAirconditioning(bool use_airconditioning);

		///
		///Metoda zwraca flagę, czy obiekt posiada moduł wentylatora
		///
		const bool getUseWentilator() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada moduł wentylatora
		///
		///
		///@param use_ventilator - flaga, czy obiekt posiada moduł wentylatora
		///
		void setUseWentilator(bool use_ventilator);

		///
		///Metoda zwraca wskaźnik na obiekt klasy Engine
		///
		Engine *getEngine();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Engine
		///
		///@param *engine - wskaźnik na obiekt klasy Engine
		///
		void setEngine(Engine *engine);

		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getEngineTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param transformation - referencja na obiekt klasy CTransformation
		///
		void setEngineTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getEnergyTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param transformation - referencja na obiekt klasy CTransformation
		///
		void setEnergyTransformed(CTransformation & transformation);
		
		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getAirconditioningTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param transformation - referencja na obiekt klasy CTransformation
		///
		void setAirconditioningTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getVentilatorTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param transformation - referencja na obiekt klasy CTransformation
		///
		void setVentilatorTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getGunTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param transformation - referencja na obiekt klasy CTransformation
		///
		void setGunTransformed(CTransformation & transformation);

		///
		///Metoda zwraca wskaźnik na obiekt klasy Energy
		///
		Energy *getEnergy();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Energy
		///
		///@param *engine - wskaźnik na obiekt klasy Energy
		///
		void setEnergy(Energy *energy);

		///
		///Metoda zwraca wskaźnik na obiekt klasy Airconditioning
		///
		Airconditioning *getAirconditioning();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Airconditioning
		///
		///@param *airconditioning - wskaźnik na obiekt klasy Airconditioning
		///
		void setAirconditioning(Airconditioning *airconditioning);

		///
		///Metoda zwraca wskaźnik na obiekt klasy Ventilator
		///
		Ventilator *getVentilator();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Ventilator
		///
		///@param *ventilator - wskaźnik na obiekt klasy Ventilator
		///
		void setVentilator(Ventilator *ventilator);

		///
		///Metoda zwraca wskaźnik na obiekt klasy Gun
		///
		Gun *getGun();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Gun
		///
		///@param *gun - wskaźnik na obiekt klasy Gun
		///
		void setGun(Gun *gun);

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca opakowanie stanów obiektu
		///
		const ActorStateData & getStateData() const;

		///
		///Metoda ustawia opakowanie stanów obiektu
		///
		///@param state_data - stała referencja na obiekt klasy ActorStateData - opakowanie stanów obiektu
		///
		void getStateData(const ActorStateData & state_data);

		///
		///Metoda zwraca stan obiektu - aktualizcja reprezentacji obiektu
		///
		const EActorBasicState & getBasicState() const;

		///
		///Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
		///
		///@param basic_state - stała referencja na wylicznie stanów obiektu
		///
		void setBasicState(const EActorBasicState & basic_state);

		///
		///Metoda zwraca stan ruchu obiektu
		///
		const EActorMoveState & getMoveState() const;

		///
		///Metoda ustawia stan ruchu obiektu
		///
		///@param move_state - stała referencja na wylicznie stanów ruchu obiektu
		///
		void setMoveState(const EActorMoveState & move_state);

		///
		///Metoda zwraca stan behawioralny obiektu
		///
		const EActorSpawnState & getSpawnState() const;

		///
		///Metoda ustawia stan behawioralny obiektu
		///
		///@param spawn_state - stała referencja na wyliczenie stanów behawioralnych obiektu (procesy życiowe, trwanie)
		///
		void setSpawnState(const EActorSpawnState & spawn_state);

		///
		///Wirtualna metoda zabija obiekt klasy Actor i wywołuje odpowiednie czynności z tym związane
		///
		void kill();

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:

		CAnimSet *p_anim_set; //wskaźnik na obiekt klasy CAnimSet (zestaw animacji)
		CActorTechnicalData m_technical_data; //opakowanie fizyki
		EquipmentEngineData m_engine_data; //opakowanie funkcjonalności silnika
		EquipmentEnergyData m_energy_data; //opakowanie funkcjonalności energii
		EquipmentAirconditioningData m_airconditiong_data; //opakowanie funkcjonalności klimatyzatora
		EquipmentVentilatorData m_ventilator_data; //opakowanie funkcjonalności wentylatora
		EquipmentGunData m_gun_data; //opakowanie funkcjonalności działa
		ActorStateData m_state_data; //opakowanie wyliczenia stanów
		ActorController *p_actor_controller; //obiekt klasy ActorController - funkcjonalność sterowania

	protected:

		//Metoda aktualizuje komponenty
		void updateComponents(float dt);
		
	private:
		//metoda aktualizuje funkcjonalność Engine
		void updateEngine(float dt);

		//metoda aktualizuje funkcjonalność Energy
		void updateEnergy(float dt);
		
		//metoda aktualizuje funkcjonalność Airconditioning
		void updateAirconditioning(float dt);

		//metoda aktualizuje funkcjonalność Ventilator
		void updateVentilator(float dt);

		//metoda aktualizuje funkcjonalność Gun
		void updateGun(float dt);

		//metoda aktualizuje temperaturę (wnętrze lub organizm)
		void updateTemperature(float dt);

		//metoda pomocnicza - metoda ustawia zestaw animacji - body
		void setAnimSetBody(CAnimSet *anim_set);

		//metoda pomocnicza - metoda ustawia zestaw animacji - head
		void setAnimSetHead(CAnimSet *anim_set);
	};
}//namespace logic
#endif //H_ACTOR_JACK
