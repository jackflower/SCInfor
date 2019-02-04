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
	///Klasa reprezentuje funkcjnalnoœæ klimatyzacji - klimatyzatora
	///
	class CAirconditioning : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;

		//Aby uzyskaæ obiekt CAirconditioning, nale¿y wywo³aæ CPhysicalManager::CreateAirconditioning();

	protected:

		///
		///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		CAirconditioning(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param &CAirconditioningCopy - sta³a referencja na obiekt klasy CAirconditioning
		///
		CAirconditioning(const CAirconditioning &CAirconditioningCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		~CAirconditioning(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwê klimatyzatora
		///
		const std::string GetAirconditioningName() const;

		///
		///Metoda ustawia nazwê klimatyzatora
		///
		///@param &airconditioning_name - typ akumulatora sta³a referencja na std::string
		///
		void SetAirconditioningName(const std::string& airconditioning_name);

		///
		///Metoda zwraca temperaturê
		///
		const float getTemperature () const;

		///
		///Metoda ustawia temperaturê
		///
		///@param temperature - temperatura
		///
		void setTemperature (float temperature);

		///
		///Metoda zwraca temperaturê ustawion¹ na urz¹dzeniu (klimatyzator)
		///
		const float getTemperatureSet () const;

		///
		///Metoda ustawia temperaturê ustawion¹ na urz¹dzeniu (klimatyzator)
		///
		///@param temperature_set - temperatura ustawiona na urz¹dzeniu (klimatyzator)
		///
		void setTemperatureSet (float temperature_set);

		///
		///Metoda zwraca wartoœæ zimna klimatyzatora
		///
		const float getTemperatureCold() const;

		///
		///Metoda ustawia wartoœæ zimna klimatyzatora
		///
		///@param cold - wartoœæ zimna klimatyzatora
		///
		void setTemperatureCold(float cold);

		///
		///Metoda zwraca wartoœæ ciep³a klimatyzatora
		///
		const float getTemperatureWarm() const;

		///
		///Metoda ustawia wartoœæ ciep³a klimatyzatora
		///
		///@param warm - wartoœæ ciep³a klimatyzatora
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
		///Metoda zwraca zu¿ycie energii przez klimatyzator
		///
		const float getEnergyConsumption() const;

		///
		///Metoda ustawia zu¿ycie energii przez klimatyzator
		///
		///@param energy_consumption - zu¿ycie energii przez klimatyzator
		///
		void setEnergyConsumption(float energy_consumption);

		///
		///Metoda zwraca zu¿ycie paliwa przez klimatyzator
		///
		const float getFuelConsumption() const;

		///
		///Metoda ustawia zu¿ycie paliwa przez klimatyzator
		///
		///@param fuel_consumption - zu¿ycie paliwa przez klimatyzator
		///
		void setFuelConsumption(float fuel_consumption);

		///
		///Metoda zwraca flagê, czy obiekt posiada termoizolator
		///
		const bool getUseThermalInsulation() const;
		
		///
		///Metoda ustawia flagê, czy obiekt posiada termoizolator
		///
		///@param use_thermal_insulation - flaga, czy obiekt posiada termoizolator
		///
		void setUseThermalInsulation(bool use_thermal_insulation);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CThermalInsulation - termoizolator
		///
		CThermalInsulation *getThermalInsulation();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CThermalInsulation - termoizolator
		///
		///@param *thermal_insulation - wskaŸnik na obiekt klasy CThermalInsulation
		///
		void setThermalInsulation(CThermalInsulation * thermal_insulation);

		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getThermalInsulationTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param & transformation - referencja na obiekt klasy CTransformation
		///
		void setThermalInsulationTransformed(CTransformation & transformation);

		///
		///Metoda zwraca referencjcê na modu³ sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Wirtualna metoda aktualizuje logikê obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string				m_airconditioning_name;		//nazwa klimatyzatora
		float					m_temperature;				//temperatura - wyliczana temperatura klimatyzatora
		float					m_temperature_set;			//temperatura ustawiona na urz¹dzeniu (klimatyzator)
		std::pair<float, float> m_temperature_range;		//zakres temperatury - skutecznoœæ urz¹dzenia (first - cold, second - warm)
		float					m_temperature_increment;	//przyrost temperatury - cykl - dynammika
		float					m_energy_consumption;		//zu¿ycie energii przez klimatyzator
		float					m_fuel_consumption;			//zu¿ycie paliwa przez klimatyzator
		CThermalInsulationData	m_thermal_insulation_data;	//opakowanie funkcjonalnoœci termoizolatora
		EAirconditioningState	m_airconditioning_state;	//wyliczenie stanów
		Switch					m_unit_controller;			//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu - klimatyzator
		void updateAirconditioningState(float dt);

		//metoda aktualizuje wskaŸnik na obiekt CThermalInsulation - po³o¿enie wzglêdem w³aœciciela
		void updateThermalInsulationTransformation(float dt);

		//prywatna metoda zwraca flagê, czy wyliczana w czasie rzeczywistym 
		//temperatura otoczenie jest w zakresie pracy klimatyzatora
		//(temperatura otoczenie jest pobierana od rzeczywistej
		//temperatury na danej mapie œwiata)
		//w takim przypadu klimatyzator zapewni stabilizacjê temperatury
		//zgodnie z temperatur¹ klimatyzatora ustawion¹ na urz¹dzeniu
		//warunek analizuje tak¿e poprawkê na termoizolator
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
