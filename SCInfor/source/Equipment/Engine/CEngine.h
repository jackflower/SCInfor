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
	///Klasa reprezentuje abstrakcyjny silnik nap�dzajacy dowolny obiekt
	///
	class CEngine : public CActor
	{
		RTTI_DECL;
			
		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
			
		//Aby uzyska� obiekt CEngine, nale�y wywo�a� CPhysicalManager::CreateEngine();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
		///
		CEngine(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param &CEngineCopy - obiekt klasy CEngine
		///
		CEngine(const CEngine& CEngineCopy);
				
		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CEngine(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazw� silnika
		///
		const std::string GetEngineName() const;

		///
		///Metoda ustawia typ silnika
		///
		///@param &engine_name - typ silnika sta�a referencja na std::string
		///
		void SetEngineName(const std::string& engine_name);

		///
		///Metoda zwraca wska�nik na obiekt klasy CFuelTank
		///
		CFuelTank* GetFuelTank();

		///
		///Metoda ustawia wska�nik na obiekt klasy CFuelTank
		///
		///@param *fuel_tank - wska�nik na obiekt klasy CFuelTank
		///
		void SetFuelTank(CFuelTank* fuel_tank);

		///
		///Metoda zwraca flag�, czy obiekt posiada zbiornik paliwa
		///
		const bool GetUseFuelTank() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada zbiornik paliwa
		///
		///@param use_fueltank - flaga, czy obiekt posiada zbiornik paliwa
		///
		void SetUseFuelTank(bool use_fueltank);

		///
		///Metoda zwraca referencj� na opakowanie funkcjonalno�ci zbiornika paliwa
		///
		CEquipmentFuelTankData & getEquipmentFuelTankData();

		///
		///Metoda ustawia referencj� na opakowanie funkcjonalno�ci zbiornika paliwa
		///
		///@param & fueltank_data - referencja na obiekt klasy CEquipmentFuelTankData
		///
		void setEquipmentFuelTankData(CEquipmentFuelTankData & fueltank_data);

		///
		///Metoda zwraca referencj� na opakowanie danych dla transformacji
		///
		CTransformation & getFuelTankTransformed();

		///
		///Metoda ustawia referencj� na opakowanie danych dla transformacji
		///
		///@param & fuel_tank_transformation - referencja na obiekt klasy CTransformation
		///
		void setFuelTankTransformed(CTransformation & fuel_tank_transformation);

		///
		///Metoda zwraca warto��, przy kt�rej nast�puje komunikat informacyjny o rezerwie paliwa (procent)
		///
		const float GetPercentageReserveFuel() const;

		///
		///Metoda ustawia warto��, przy kt�rej nast�puje komunikat informacyjny o rezerwie paliwa
		///
		///@param percentage_reserve_fuel - procentowa warto�� paliwa, przy kt�rej nast�puje komunikat informacyjny o rezerwie paliwa
		///
		void SetPercentageReserveFuel(float percentage_reserve_fuel);

		///
		///Metoda zwraca warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku paliwa
		///
		const bool GetFuelEmptyMessage() const;

		///
		///Metoda ustawia warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku paliwa
		///
		///@param fuel_empty_message - flaga, czy obiekt mo�e wysy�a� komunikaty o braku paliwa
		///
		void SetFuelEmptyMessage(bool fuel_empty_message);

		///
		///Metoda zwraca czas op�nienia komunikatu o braku paliwa
		///
		const float GetTankTimeDelayed() const;

		///
		///Metoda ustawia czas op�nienia komunikatu o braku paliwa
		///
		///@param tank_time_delayed - czas op�nienia komunikatu o braku paliwa
		///
		void SetTankTimeDelayed(float tank_time_delayed);

		///
		///Metoda zwraca zu�ycie paliwa gdy obiekt si� nie przemieszcza
		///
		const float GetFuelConsumption() const;

		///
		///Metoda ustawia zu�ycie paliwa gdy obiekt si� nie przemieszcza
		///
		///@param fuel_consumption - zu�ycie paliwa gdy obiekt si� nie przemieszcza
		///
		void SetFuelConsumption(float fuel_consumption);

		///
		///Metoda zwraca zu�ycie paliwa gdy obiekt si� przemieszcza - zwi�zane z pr�dko�ci� obiektu
		///
		const float GetFuelConsumptionMove() const;

		///
		///Metoda ustawia zu�ycie paliwa gdy obiekt si� przemieszcza - zwi�zane z pr�dko�ci� obiektu
		///
		///@param fuel_consumption_move - zu�ycie paliwa gdy obiekt si� przemieszcza
		///
		void SetFuelConsumptionMove(float fuel_consumption_move);

		///
		///Metoda uruchamia prac� silnika
		///
		const bool GetRunEngine() const;

		///
		///Metoda ustawia prac� silnika
		///
		///@param engine_run - stan pracy silnika (start/stop)
		///
		void SetRunEngine(bool engine_run);

		///
		///Metoda zwraca cz�stotliwo�� regeneracji procesu
		///
		const float GetEngineRegenerationTime() const;

		///
		///Metoda ustawia cz�stotliwo�� regeneracji procesu
		///
		///@param engine_regeneration_time - cz�stotliwo�� regeneracji procesu
		///
		void SetEngineRegenerationTime(float engine_regeneration_time);

		///
		///Metoda zwraca pr�dko�� wirowania �opatek silnika
		///
		const float GetEngineRotationSpeed() const;

		///
		///Metoda ustawia pr�dko�� wirowania �opatek silnika
		///
		///@param engine_rotation_speed - pr�dko�� wirowania �opatek silnika
		///
		void SetEngineRotationSpeed(float engine_rotation_speed);

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca stan obiektu CEngine
		///
		inline EEngineState & getEngineState() { return m_engine_state; }

		///
		///Metoda zwraca referencjc� na modu� sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logik� obiektu
		///
		///@param dt - czas
		///
		virtual void Update(float dt);


	private:

		std::string				m_engine_name;				//nazwa silnika (spalinowy, elektryczny, atomowy, biologiczny...etc)
		CEquipmentFuelTankData	m_fueltank_data;			//opakowanie funkcjonalno�ci zbiornika paliwa
		float					m_percentage_reserve_fuel;	//procentowa warto�� paliwa, przy kt�rej nast�puje komunikat informacyjny o rezerwie paliwa (default 10% - konstruktor)
		float					m_fuel_consumption;			//zu�ycie paliwa gdy obiekt si� nie przemieszcza (aktualizowane co sekund�)
		float					m_fuel_consumption_move;	//zu�ycie paliwa gdy obiekt si� przemieszcza - zwi�zane z pr�dko�ci� obiektu
		float					m_tank_time_delayed;		//czas op�nienia komunikatu o braku paliwa - jako dana wej�ciowa dla sf::Randomizer
		bool					m_fuel_empty_message;		//flaga, czy biekt mo�e wysy�a� komunikaty o braku paliwa
		bool					m_engine_run;				//stacyjka - start/stop engine
		float					m_engine_rotation_speed;	//pr�dko�� wirowania wirnika w silniku
		float					m_engine_regeneration_time;	//cz�stotliwo�� regeneracji procesu
		EEngineState			m_engine_state;				//wyliczenie stan�w dla obiektu CEngine
		float					m_engine_timer;				//wyliczany up�ywaj�cy czas proces�w logiki
		float					m_rotor_speed;				//wyliczana pr�dko�� wirowania �opat wirnika silnika
		float					m_percentage_fuel;			//wyliczana procentowa zawarto�� paliwa w zbiorniku
		CSwitch					m_unit_controller;			//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu - engine
		void updateEngineState(float dt);

		//prywatna metoda aktualizuje obiekt - fueltank (zbiornik paliwa)
		void updateFuelTank(float dt);

		//prywatna metoda aktualizuje sk�adowe transformacji wzgl�dem w�a�ciciela
		void updateFuelTankTransformation(float dt);
	};
}//namespace equipment
#endif //H_ENGINE_JACK
