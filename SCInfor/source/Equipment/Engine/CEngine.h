//  ____________________________________
// | CEngine.h - class definition       |
// | Jack Flower - December 2012        |
// |____________________________________|
//

#ifndef H_ENGINE_JACK
#define H_ENGINE_JACK

#include "EEngineState.h"
#include "../../Logic/Actor/CActor.h"
#include "../../RTTI/RTTI.h"
#include "../EquipmentData/CEquipmentFuelTankData.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje abstrakcyjny silnik napêdzajacy dowolny obiekt
	///
	class CEngine : public CActor
	{
		RTTI_DECL;
			
		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskaæ obiekt CEngine, nale¿y wywo³aæ CPhysicalManager::CreateEngine();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta³a referncja na obiekt klasy std::wstring
		///
		CEngine(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param &CEngineCopy - obiekt klasy CEngine
		///
		CEngine(const CEngine& CEngineCopy);
				
		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CEngine(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwê silnika
		///
		const std::string GetEngineName() const;

		///
		///Metoda ustawia typ silnika
		///
		///@param &engine_name - typ silnika sta³a referencja na std::string
		///
		void SetEngineName(const std::string& engine_name);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CFuelTank
		///
		CFuelTank* GetFuelTank();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CFuelTank
		///
		///@param *fuel_tank - wskaŸnik na obiekt klasy CFuelTank
		///
		void SetFuelTank(CFuelTank* fuel_tank);

		///
		///Metoda zwraca flagê, czy obiekt posiada zbiornik paliwa
		///
		const bool GetUseFuelTank() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada zbiornik paliwa
		///
		///@param use_fueltank - flaga, czy obiekt posiada zbiornik paliwa
		///
		void SetUseFuelTank(bool use_fueltank);

		///
		///Metoda zwraca referencjê na opakowanie funkcjonalnoœci zbiornika paliwa
		///
		CEquipmentFuelTankData & getEquipmentFuelTankData();

		///
		///Metoda ustawia referencjê na opakowanie funkcjonalnoœci zbiornika paliwa
		///
		///@param & fueltank_data - referencja na obiekt klasy CEquipmentFuelTankData
		///
		void setEquipmentFuelTankData(CEquipmentFuelTankData & fueltank_data);

		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getFuelTankTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param & fuel_tank_transformation - referencja na obiekt klasy CTransformation
		///
		void setFuelTankTransformed(CTransformation & fuel_tank_transformation);

		///
		///Metoda zwraca wartoœæ, przy której nastêpuje komunikat informacyjny o rezerwie paliwa (procent)
		///
		const float GetPercentageReserveFuel() const;

		///
		///Metoda ustawia wartoœæ, przy której nastêpuje komunikat informacyjny o rezerwie paliwa
		///
		///@param percentage_reserve_fuel - procentowa wartoœæ paliwa, przy której nastêpuje komunikat informacyjny o rezerwie paliwa
		///
		void SetPercentageReserveFuel(float percentage_reserve_fuel);

		///
		///Metoda zwraca wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku paliwa
		///
		const bool GetFuelEmptyMessage() const;

		///
		///Metoda ustawia wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku paliwa
		///
		///@param fuel_empty_message - flaga, czy obiekt mo¿e wysy³aæ komunikaty o braku paliwa
		///
		void SetFuelEmptyMessage(bool fuel_empty_message);

		///
		///Metoda zwraca czas opóŸnienia komunikatu o braku paliwa
		///
		const float GetTankTimeDelayed() const;

		///
		///Metoda ustawia czas opóŸnienia komunikatu o braku paliwa
		///
		///@param tank_time_delayed - czas opóŸnienia komunikatu o braku paliwa
		///
		void SetTankTimeDelayed(float tank_time_delayed);

		///
		///Metoda zwraca zu¿ycie paliwa gdy obiekt siê nie przemieszcza
		///
		const float GetFuelConsumption() const;

		///
		///Metoda ustawia zu¿ycie paliwa gdy obiekt siê nie przemieszcza
		///
		///@param fuel_consumption - zu¿ycie paliwa gdy obiekt siê nie przemieszcza
		///
		void SetFuelConsumption(float fuel_consumption);

		///
		///Metoda zwraca zu¿ycie paliwa gdy obiekt siê przemieszcza - zwi¹zane z prêdkoœci¹ obiektu
		///
		const float GetFuelConsumptionMove() const;

		///
		///Metoda ustawia zu¿ycie paliwa gdy obiekt siê przemieszcza - zwi¹zane z prêdkoœci¹ obiektu
		///
		///@param fuel_consumption_move - zu¿ycie paliwa gdy obiekt siê przemieszcza
		///
		void SetFuelConsumptionMove(float fuel_consumption_move);

		///
		///Metoda uruchamia pracê silnika
		///
		const bool GetRunEngine() const;

		///
		///Metoda ustawia pracê silnika
		///
		///@param engine_run - stan pracy silnika (start/stop)
		///
		void SetRunEngine(bool engine_run);

		///
		///Metoda zwraca czêstotliwoœæ regeneracji procesu
		///
		const float GetEngineRegenerationTime() const;

		///
		///Metoda ustawia czêstotliwoœæ regeneracji procesu
		///
		///@param engine_regeneration_time - czêstotliwoœæ regeneracji procesu
		///
		void SetEngineRegenerationTime(float engine_regeneration_time);

		///
		///Metoda zwraca prêdkoœæ wirowania ³opatek silnika
		///
		const float GetEngineRotationSpeed() const;

		///
		///Metoda ustawia prêdkoœæ wirowania ³opatek silnika
		///
		///@param engine_rotation_speed - prêdkoœæ wirowania ³opatek silnika
		///
		void SetEngineRotationSpeed(float engine_rotation_speed);

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca stan obiektu CEngine
		///
		inline EEngineState & getEngineState() { return m_engine_state; }

		///
		///Metoda zwraca referencjcê na modu³ sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logikê obiektu
		///
		///@param dt - czas
		///
		virtual void Update(float dt);


	private:

		std::string				m_engine_name;				//nazwa silnika (spalinowy, elektryczny, atomowy, biologiczny...etc)
		CEquipmentFuelTankData	m_fueltank_data;			//opakowanie funkcjonalnoœci zbiornika paliwa
		float					m_percentage_reserve_fuel;	//procentowa wartoœæ paliwa, przy której nastêpuje komunikat informacyjny o rezerwie paliwa (default 10% - konstruktor)
		float					m_fuel_consumption;			//zu¿ycie paliwa gdy obiekt siê nie przemieszcza (aktualizowane co sekundê)
		float					m_fuel_consumption_move;	//zu¿ycie paliwa gdy obiekt siê przemieszcza - zwi¹zane z prêdkoœci¹ obiektu
		float					m_tank_time_delayed;		//czas opóŸnienia komunikatu o braku paliwa - jako dana wejœciowa dla sf::Randomizer
		bool					m_fuel_empty_message;		//flaga, czy biekt mo¿e wysy³aæ komunikaty o braku paliwa
		bool					m_engine_run;				//stacyjka - start/stop engine
		float					m_engine_rotation_speed;	//prêdkoœæ wirowania wirnika w silniku
		float					m_engine_regeneration_time;	//czêstotliwoœæ regeneracji procesu
		EEngineState			m_engine_state;				//wyliczenie stanów dla obiektu CEngine
		float					m_engine_timer;				//wyliczany up³ywaj¹cy czas procesów logiki
		float					m_rotor_speed;				//wyliczana prêdkoœæ wirowania ³opat wirnika silnika
		float					m_percentage_fuel;			//wyliczana procentowa zawartoœæ paliwa w zbiorniku
		CSwitch					m_unit_controller;			//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu - engine
		void updateEngineState(float dt);

		//prywatna metoda aktualizuje obiekt - fueltank (zbiornik paliwa)
		void updateFuelTank(float dt);

		//prywatna metoda aktualizuje sk³adowe transformacji wzglêdem w³aœciciela
		void updateFuelTankTransformation(float dt);
	};
}//namespace equipment
#endif //H_ENGINE_JACK
