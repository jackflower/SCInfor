//  _____________________________________________
// | CAirconditioning.h - class definition       |
// | Jack Flower June 2014                       |
// |_____________________________________________|
//

#ifndef H_AIRCONDITIONING_JACK
#define H_AIRCONDITIONING_JACK

#include "EAirconditioningState.h"
#include "../ThermalInsulation/CThermalInsulation.h"
#include "../../EquipmentData/CThermalInsulationData.h"
#include "../../Switch.h"
#include "../../../Logic/Actor/CActor.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje funkcjnalno�� klimatyzacji - klimatyzatora
	///
	class CAirconditioning : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;

		//Aby uzyska� obiekt CAirconditioning, nale�y wywo�a� CPhysicalManager::CreateAirconditioning();

	protected:

		///
		///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
		///
		CAirconditioning(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param &CAirconditioningCopy - sta�a referencja na obiekt klasy CAirconditioning
		///
		CAirconditioning(const CAirconditioning &CAirconditioningCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		~CAirconditioning(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazw� klimatyzatora
		///
		const std::string GetAirconditioningName() const;

		///
		///Metoda ustawia nazw� klimatyzatora
		///
		///@param &airconditioning_name - typ akumulatora sta�a referencja na std::string
		///
		void SetAirconditioningName(const std::string& airconditioning_name);

		///
		///Metoda zwraca temperatur�
		///
		const float getTemperature () const;

		///
		///Metoda ustawia temperatur�
		///
		///@param temperature - temperatura
		///
		void setTemperature (float temperature);

		///
		///Metoda zwraca temperatur� ustawion� na urz�dzeniu (klimatyzator)
		///
		const float getTemperatureSet () const;

		///
		///Metoda ustawia temperatur� ustawion� na urz�dzeniu (klimatyzator)
		///
		///@param temperature_set - temperatura ustawiona na urz�dzeniu (klimatyzator)
		///
		void setTemperatureSet (float temperature_set);

		///
		///Metoda zwraca warto�� zimna klimatyzatora
		///
		const float getTemperatureCold() const;

		///
		///Metoda ustawia warto�� zimna klimatyzatora
		///
		///@param cold - warto�� zimna klimatyzatora
		///
		void setTemperatureCold(float cold);

		///
		///Metoda zwraca warto�� ciep�a klimatyzatora
		///
		const float getTemperatureWarm() const;

		///
		///Metoda ustawia warto�� ciep�a klimatyzatora
		///
		///@param warm - warto�� ciep�a klimatyzatora
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
		///Metoda zwraca zu�ycie energii przez klimatyzator
		///
		const float getEnergyConsumption() const;

		///
		///Metoda ustawia zu�ycie energii przez klimatyzator
		///
		///@param energy_consumption - zu�ycie energii przez klimatyzator
		///
		void setEnergyConsumption(float energy_consumption);

		///
		///Metoda zwraca zu�ycie paliwa przez klimatyzator
		///
		const float getFuelConsumption() const;

		///
		///Metoda ustawia zu�ycie paliwa przez klimatyzator
		///
		///@param fuel_consumption - zu�ycie paliwa przez klimatyzator
		///
		void setFuelConsumption(float fuel_consumption);

		///
		///Metoda zwraca flag�, czy obiekt posiada termoizolator
		///
		const bool getUseThermalInsulation() const;
		
		///
		///Metoda ustawia flag�, czy obiekt posiada termoizolator
		///
		///@param use_thermal_insulation - flaga, czy obiekt posiada termoizolator
		///
		void setUseThermalInsulation(bool use_thermal_insulation);

		///
		///Metoda zwraca wska�nik na obiekt klasy CThermalInsulation - termoizolator
		///
		CThermalInsulation *getThermalInsulation();

		///
		///Metoda ustawia wska�nik na obiekt klasy CThermalInsulation - termoizolator
		///
		///@param *thermal_insulation - wska�nik na obiekt klasy CThermalInsulation
		///
		void setThermalInsulation(CThermalInsulation * thermal_insulation);

		///
		///Metoda zwraca referencj� na opakowanie danych dla transformacji
		///
		CTransformation & getThermalInsulationTransformed();

		///
		///Metoda ustawia referencj� na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setThermalInsulationTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencjc� na modu� sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Wirtualna metoda aktualizuje logik� obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string				m_airconditioning_name;		//nazwa klimatyzatora
		float					m_temperature;				//temperatura - wyliczana temperatura klimatyzatora
		float					m_temperature_set;			//temperatura ustawiona na urz�dzeniu (klimatyzator)
		std::pair<float, float> m_temperature_range;		//zakres temperatury - skuteczno�� urz�dzenia (first - cold, second - warm)
		float					m_temperature_increment;	//przyrost temperatury - cykl - dynammika
		float					m_energy_consumption;		//zu�ycie energii przez klimatyzator
		float					m_fuel_consumption;			//zu�ycie paliwa przez klimatyzator
		CThermalInsulationData	m_thermal_insulation_data;	//opakowanie funkcjonalno�ci termoizolatora
		EAirconditioningState	m_airconditioning_state;	//wyliczenie stan�w
		Switch					m_unit_controller;			//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu - klimatyzator
		void updateAirconditioningState(float dt);

		//metoda aktualizuje wska�nik na obiekt CThermalInsulation - po�o�enie wzgl�dem w�a�ciciela
		void updateThermalInsulationTransformation(float dt);

		//prywatna metoda zwraca flag�, czy wyliczana w czasie rzeczywistym 
		//temperatura otoczenie jest w zakresie pracy klimatyzatora
		//(temperatura otoczenie jest pobierana od rzeczywistej
		//temperatury na danej mapie �wiata)
		//w takim przypadu klimatyzator zapewni stabilizacj� temperatury
		//zgodnie z temperatur� klimatyzatora ustawion� na urz�dzeniu
		//warunek analizuje tak�e poprawk� na termoizolator
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
