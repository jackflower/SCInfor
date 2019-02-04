//  _______________________________________
// | CVentilator.h - class definition      |
// | Jack Flower June 2014                 |
// |_______________________________________|
//

#ifndef H_VENTILATOR_JACK
#define H_VENTILATOR_JACK

#include "EVentilatorState.h"
#include "../../../Logic/Actor/CActor.h"
#include "../../CSwitch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje funkcjonalność wentylatora
	///
	class CVentilator : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;

		//Aby uzyskać obiekt CVentilator, należy wywołać CPhysicalManager::CreateVentilator();

	protected:

		///
		///Chroniony konstruktor domyślny - używany wyłącznie przez CPhysicalManager
		///
		CVentilator(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param CVentilatorCopy - stała referencja na obiekt klasy CVentilator
		///
		CVentilator(const CVentilator & CVentilatorCopy);

		///
		///Destruktor
		///
		~CVentilator();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwę
		///
		const std::string GetVentilatorName() const;

		///
		///Metoda ustawia nazwę
		///
		///@param & ventilator_name - nazwa - stała referencja na obiekt klasy std::string
		///
		void SetVentilatorName(const std::string & ventilator_name);

		///
		///Metoda zwraca wydajność wentylatora
		///
		const float getPerformance() const;

		///
		///Metoda ustawia wydajność wentylatora
		///
		///@param performance - wydajność wentylatora
		///
		void setPerformance(float performance);

		///
		///Metoda zwraca współczynnik wydajności zależny od temperatury otoczenia
		///
		const float getPerformanceFactor() const;

		///
		///Metoda ustawia współczynnik wydajności zależny od temperatury otoczenia
		///
		///@param performance_factor - współczynnik wydajności
		///
		void setPerformanceFactor(float performance_factor);

		///
		///Metoda zwraca zużycie energii przez wentylator
		///
		const float getEnergyConsumption() const;

		///
		///Metoda ustawia zużycie energii przez wentylator
		///
		///@param energy_consumption - zużycie energii przez wentylator
		///
		void setEnergyConsumption(float energy_consumption);

		///
		///Metoda zwraca współczynnik zużycia energii wentylatora
		///
		const float getEnergyConsumptionFactor() const;

		///
		///Metoda ustawia współczynnik zużycia energii wentylatora
		///
		///@param energy_consumption_factor - współczynnik zużycia energii wentylatora
		///
		void setEnergyConsumptionFactor(float energy_consumption_factor);

		///
		///Metoda zwraca referencjcę na moduł sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void UpdateAnimations(float dt);

		///
		///Metoda aktulizuje obiekt
		///
		///@param dt - czas
		///
		void Update(float dt);

	private:

		std::string			m_ventilator_name;				//nazwa wentylatora
		float				m_performance;					//wydajność
		float				m_performance_factor;			//współczynnik wydajności (zależy od temperatury) [ obliczany ]
		float				m_energy_consumption;			//zużycie energii
		float				m_energy_consumption_factor;	//współczynnik zużycia energii [ obliczany ]
		EVentilatorState	m_ventilator_state;				//wyliczenie stanów
		CSwitch				m_unit_controller;				//włącznik, sterownik, moduł zarządzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu - wentylator
		void updateVentilatorState(float dt);
	};
}//namespace equipment
#endif//H_VENTILATOR_JACK
