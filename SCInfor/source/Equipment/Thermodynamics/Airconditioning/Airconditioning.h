//  ____________________________________________
// | Airconditioning.h - class definition       |
// | Jack Flower June 2014                      |
// |____________________________________________|
//

#ifndef H_AIRCONDITIONING_JACK
#define H_AIRCONDITIONING_JACK

#include "EAirconditioningState.h"
#include "../ThermalInsulation/ThermalInsulation.h"
#include "../../EquipmentData/ThermalInsulationData.h"
#include "../../Switch.h"
#include "../../../Logic/Actor/CActor.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje funkcjnalność klimatyzacji - klimatyzatora
	///
	class Airconditioning : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;

		//Aby uzyskać obiekt Airconditioning, należy wywołać CPhysicalManager::CreateAirconditioning();

	protected:

		///
		///Chroniony konstruktor domyślny - używany wyłącznie przez CPhysicalManager
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		Airconditioning(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param AirconditioningCopy - stała referencja na obiekt klasy Airconditioning
		///
		Airconditioning(const Airconditioning & AirconditioningCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		///
		~Airconditioning(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę klimatyzatora
		///
		const std::string getAirconditioningName() const;

		///
		///Metoda ustawia nazwę klimatyzatora
		///
		///@param airconditioning_name - typ akumulatora stała referencja na std::string
		///
		void setAirconditioningName(const std::string & airconditioning_name);

		///
		///Metoda zwraca temperaturę
		///
		const float getTemperature () const;

		///
		///Metoda ustawia temperaturę
		///
		///@param temperature - temperatura
		///
		void setTemperature (float temperature);

		///
		///Metoda zwraca temperaturę ustawioną na urządzeniu (klimatyzator)
		///
		const float getTemperatureSet () const;

		///
		///Metoda ustawia temperaturę ustawioną na urządzeniu (klimatyzator)
		///
		///@param temperature_set - temperatura ustawiona na urządzeniu (klimatyzator)
		///
		void setTemperatureSet (float temperature_set);

		///
		///Metoda zwraca wartość zimna klimatyzatora
		///
		const float getTemperatureCold() const;

		///
		///Metoda ustawia wartość zimna klimatyzatora
		///
		///@param cold - wartość zimna klimatyzatora
		///
		void setTemperatureCold(float cold);

		///
		///Metoda zwraca wartość ciepła klimatyzatora
		///
		const float getTemperatureWarm() const;

		///
		///Metoda ustawia wartość ciepła klimatyzatora
		///
		///@param warm - wartość ciepła klimatyzatora
		///
		void setTemperatureWarm(float warm);

		///
		///Metoda zwraca przyrost temperatury - cykl - dynammika
		///
		const float getTemperatureIncrement() const;

		///
		///Metoda ustawia przyrost temperatury - cykl - dynammika
		///
		///@param temperature_increment - przyrost temperatury - cykl - dynammika
		///
		void setTemperatureIncrement(float temperature_increment);

		///
		///Metoda zwraca zużycie energii przez klimatyzator
		///
		const float getEnergyConsumption() const;

		///
		///Metoda ustawia zużycie energii przez klimatyzator
		///
		///@param energy_consumption - zużycie energii przez klimatyzator
		///
		void setEnergyConsumption(float energy_consumption);

		///
		///Metoda zwraca zużycie paliwa przez klimatyzator
		///
		const float getFuelConsumption() const;

		///
		///Metoda ustawia zużycie paliwa przez klimatyzator
		///
		///@param fuel_consumption - zużycie paliwa przez klimatyzator
		///
		void setFuelConsumption(float fuel_consumption);

		///
		///Metoda zwraca flagę, czy obiekt posiada termoizolator
		///
		const bool getUseThermalInsulation() const;
		
		///
		///Metoda ustawia flagę, czy obiekt posiada termoizolator
		///
		///@param use_thermal_insulation - flaga, czy obiekt posiada termoizolator
		///
		void setUseThermalInsulation(bool use_thermal_insulation);

		///
		///Metoda zwraca wskaźnik na obiekt klasy ThermalInsulation - termoizolator
		///
		ThermalInsulation *getThermalInsulation();

		///
		///Metoda ustawia wskaźnik na obiekt klasy ThermalInsulation - termoizolator
		///
		///@param *thermal_insulation - wskaźnik na obiekt klasy ThermalInsulation
		///
		void setThermalInsulation(ThermalInsulation * thermal_insulation);

		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getThermalInsulationTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setThermalInsulationTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencjcę na moduł sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Wirtualna metoda aktualizuje logikę obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string m_airconditioning_name; //nazwa klimatyzatora
		float m_temperature; //temperatura - wyliczana temperatura klimatyzatora
		float m_temperature_set; //temperatura ustawiona na urządzeniu (klimatyzator)
		std::pair<float, float> m_temperature_range; //zakres temperatury - skuteczność urządzenia (first - cold, second - warm)
		float m_temperature_increment; //przyrost temperatury - cykl - dynammika
		float m_energy_consumption;	//zużycie energii przez klimatyzator
		float m_fuel_consumption; //zużycie paliwa przez klimatyzator
		ThermalInsulationData m_thermal_insulation_data; //opakowanie funkcjonalności termoizolatora
		EAirconditioningState m_airconditioning_state; //wyliczenie stanów
		Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu - klimatyzator
		void updateAirconditioningState(float dt);

		//metoda aktualizuje wskaźnik na obiekt ThermalInsulation - położenie względem właściciela
		void updateThermalInsulationTransformation(float dt);

		//prywatna metoda zwraca flagę, czy wyliczana w czasie rzeczywistym 
		//temperatura otoczenie jest w zakresie pracy klimatyzatora
		//(temperatura otoczenie jest pobierana od rzeczywistej
		//temperatury na danej mapie świata)
		//w takim przypadu klimatyzator zapewni stabilizację temperatury
		//zgodnie z temperaturą klimatyzatora ustawioną na urządzeniu
		//warunek analizuje także poprawkę na termoizolator
		inline bool const TemperatureInRange()
		{
			if(m_thermal_insulation_data.getThermalInsulation())
			{
				return
					(m_thermal_insulation_data.getThermalInsulation()->getTemperatureAmbient() >= m_temperature_range.first &&
						m_thermal_insulation_data.getThermalInsulation()->getTemperatureAmbient() <= m_temperature_range.second )
						? true: false;
			}
			return false;
		}
	};
}//namespace equipment
#endif//H_AIRCONDITIONING_JACK
