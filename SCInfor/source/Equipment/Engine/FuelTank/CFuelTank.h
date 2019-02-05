//  ______________________________________
// | CFuelTank.h - class definition       |
// | Jack Flower - December 2012          |
// |______________________________________|
//

#ifndef H_FUEL_TANK_JACK
#define H_FUEL_TANK_JACK

#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Actor/CActor.h"
#include "EFuelTankState.h"
#include "../../Switch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje zbiornik paliwa
	///
	class CFuelTank : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskać obiekt CFuelTank, należy wywołać CPhysicalManager::CreateFuelTank();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		CFuelTank(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param &CFuelTankCopy - obiekt klasy CFuelTank
		///
		CFuelTank(const CFuelTank& CFuelTankCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CFuelTank(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwę zbiornika
		///
		const std::string GetFuelTankName() const;

		///
		///Metoda ustawia nazwę zbiornika
		///
		///@param &fuel_tank_name - stała referencja na obiekt klasy std::string
		///
		void SetFuelTankName(const std::string& fuel_tank_name);

		///
		///Metoda zwraca pojemność zbiornika
		///
		const float GetFuelTankCapacity() const;

		///
		///Metoda ustawia pojemność zbiornika
		///
		///@param fuel_tank_capacity - pojemność zbiornika
		///
		void SetFuelTankCapacity(float fuel_tank_capacity);

		///
		///Metoda zwraca ilość paliwa
		///
		const float GetFuel() const;

		///
		///Metoda ustawia ilość paliwa
		///
		///@param fuel - ilość paliwa
		///
		void SetFuel(float fuel);

		///
		///Metoda zwraca stan obiektu CFuelTank
		///
		inline EFuelTankState & getFuelTankState() { return m_fueltank_state; }

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca referencjcę na moduł sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:

		std::string		m_fuel_tank_name;		//nazwa zbiornika paliwa
		float			m_fuel_tank_capacity;	//pojemność zbiornika paliwa (materiał pędny)
		float			m_fuel;					//ilość paliwa - (materiału pędnego)
		EFuelTankState	m_fueltank_state;		//wyliczenie stanów dla obiektu CFuelTank
		Switch			m_unit_controller;		//włącznik, sterownik, moduł zarządzania, starter, stacyjka

	};
}//namespace equipment
#endif //H_FUEL_TANK_JACK