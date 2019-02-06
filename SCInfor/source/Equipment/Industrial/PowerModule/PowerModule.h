//  ________________________________________
// | PowerModule.h - class definition       |
// | Jack Flower - July 2014                |
// |________________________________________|
//

#ifndef H_POWER_MODULE_JACK
#define H_POWER_MODULE_JACK

#include "../../../Logic/Actor/CActor.h"
#include "../../Switch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa bazowa dla modułów wytwarzania, gromadzenia i przetwarzania energii
	///
	class PowerModule : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskać obiekt PowerModule, należy wywołać CPhysicalManager::CreatePowerModule();

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		PowerModule(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param PowerModuleCopy - obiekt klasy PowerModule
		///
		PowerModule(const PowerModule & PowerModuleCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		///
		virtual ~PowerModule(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca ilość energii, którą można zgromadzić
		///
		const float getEnergyCapacitor() const;

		///
		///Metoda ustawia ilość energii, którą można zgromadzić
		///
		///@param energy_capacitor - ilość energii, którą można zgromadzić
		///
		void setEnergyCapacitor(float energy_capacitor);

		///
		///Metoda zwraca moc
		///
		const float getPower() const;

		///
		///Metoda ustawia moc
		///
		///@param power - moc
		///
		void setPower(float power);

		///
		///Metoda zwraca ilość zgromadzonej energii
		///
		const float getStoredEnergy() const;

		///
		///Metoda ustawia ilość zgromadzonej energii
		///
		///@param stored_energy - ilość zgromadzonej energii
		///
		void setStoredEnergy(float stored_energy);

	protected:

		float m_energy_capacitor; //energia, która może zostać zgromadzona
		float m_power; //moc
		float m_stored_energy; //zgromadzona energia
		Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka

	private:
	};
}//namespace equipment
#endif//H_POWER_MODULE_JACK
