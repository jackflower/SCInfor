//  _____________________________________
// | FuelTank.h - class definition       |
// | Jack Flower - December 2012         |
// |_____________________________________|
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
	class FuelTank : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskać obiekt FuelTank, należy wywołać CPhysicalManager::CreateFuelTank();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		FuelTank(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param FuelTankCopy - stała referencja na obiekt klasy FuelTank
		///
		FuelTank(const FuelTank & FuelTankCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~FuelTank(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę zbiornika
		///
		const std::string getFuelTankName() const;

		///
		///Metoda ustawia nazwę zbiornika
		///
		///@param fuel_tank_name - stała referencja na obiekt klasy std::string
		///
		void setFuelTankName(const std::string & fuel_tank_name);

		///
		///Metoda zwraca pojemność zbiornika
		///
		const float getFuelTankCapacity() const;

		///
		///Metoda ustawia pojemność zbiornika
		///
		///@param fuel_tank_capacity - pojemność zbiornika
		///
		void setFuelTankCapacity(float fuel_tank_capacity);

		///
		///Metoda zwraca ilość paliwa
		///
		const float getFuel() const;

		///
		///Metoda ustawia ilość paliwa
		///
		///@param fuel - ilość paliwa
		///
		void setFuel(float fuel);

		///
		///Metoda zwraca stan obiektu FuelTank
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

		std::string m_fuel_tank_name; //nazwa zbiornika paliwa
		float m_fuel_tank_capacity;	//pojemność zbiornika paliwa (materiał pędny)
		float m_fuel; //ilość paliwa - (materiału pędnego)
		EFuelTankState m_fueltank_state; //wyliczenie stanów dla obiektu FuelTank
		Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka

	};
}//namespace equipment
#endif //H_FUEL_TANK_JACK
