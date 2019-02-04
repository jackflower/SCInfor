//  _________________________________________
// | CPowerModule.h - class definition       |
// | Jack Flower - July 2014                 |
// |_________________________________________|
//

#ifndef H_POWER_MODULE_JACK
#define H_POWER_MODULE_JACK

#include "../../../Logic/Actor/CActor.h"
#include "../../CSwitch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa bazowa dla modu³ów wytwarzania, gromadzenia i przetwarzania energii
	///
	class CPowerModule : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskaæ obiekt CPowerModule, nale¿y wywo³aæ CPhysicalManager::CreatePowerModule();

		///
		///Chroniony konstruktor domyœlny
		///
		CPowerModule(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CPowerModuleCopy - obiekt klasy CPowerModule
		///
		CPowerModule(const CPowerModule &CPowerModuleCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CPowerModule(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca iloœæ energii, któr¹ mo¿na zgromadziæ
		///
		const float getEnergyCapacitor() const;

		///
		///Metoda ustawia iloœæ energii, któr¹ mo¿na zgromadziæ
		///
		///@param energy_capacitor - iloœæ energii, któr¹ mo¿na zgromadziæ
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
		///Metoda zwraca iloœæ zgromadzonej energii
		///
		const float getStoredEnergy() const;

		///
		///Metoda ustawia iloœæ zgromadzonej energii
		///
		///@param stored_energy - iloœæ zgromadzonej energii
		///
		void setStoredEnergy(float stored_energy);

	protected:

		float		m_energy_capacitor;	//energia, która mo¿e zostaæ zgromadzona
		float		m_power;			//moc
		float		m_stored_energy;	//zgromadzona energia
		CSwitch		m_unit_controller;	//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka

	private:
	};
}//namespace equipment
#endif//H_POWER_MODULE_JACK
