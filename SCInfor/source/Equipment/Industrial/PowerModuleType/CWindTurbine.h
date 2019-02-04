//  _________________________________________
// | CWindTurbine.h - class definition       |
// | Jack Flower - July 2014                 |
// |_________________________________________|
//


#ifndef H_WIND_TURBINE_JACK
#define H_WIND_TURBINE_JACK

#include "../PowerModule/CPowerModule.h"
#include "ETurbineState.h"

namespace equipment
{
	///
	///Klasa reprezentuej funkcjonalno�c turbiny
	///
	class CWindTurbine : public CPowerModule
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
		
		//Aby uzyska� obiekt CWindTurbine, nale�y wywo�a� CPhysicalManager::CreateWindTurbine();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		CWindTurbine(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CWindTurbineCopy - obiekt klasy CWindTurbine
		///
		CWindTurbine(const CWindTurbine &CWindTurbineCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CWindTurbine(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazw� turbiny
		///
		const std::string GetTurbineName() const;

		///
		///Metoda ustawia nazw� turbiny
		///
		///@param &turbine_name - nazwa turbiny sta�a referencja na std::string
		///
		void SetTurbineName(const std::string& turbine_name);

		///
		///Metoda zwraca pr�dko�� wirowania turbiny
		///
		const float getSpeedRotor() const;

		///
		///Metoda ustawia pr�dko�� wirowania turbiny
		///
		///@param speed_rotor - pr�dko�� wirowania turbiny
		///
		void setSpeedRotor(float speed_rotor);

		///
		///Metoda zwraca prze�o�enie pr�dko�ci obrotowej
		///
		const float getSpeedTransmission() const;

		///
		///Metoda ustawia prze�o�enie pr�dko�ci obrotowej
		///
		///@param speed_transmission - prze�o�enie pr�dko�ci obrotowej
		///
		void setSpeedTransmission(float speed_transmission);

		///
		///Metoda zwraca procentowy wsp�czynnik aktywacji turbiny
		///
		const float getPercentageActivation() const;

		///
		///Metoda ustawia procentowy wsp�czynnik aktywacji turbiny
		///
		///@param percentage_activation - procentowy wsp�czynnik aktywacji turbiny
		///
		void setPercentageActivation(float percentage_activation);

		///
		///Metoda zwraca czas trwania stanu, po zgromadzeniu pe�nej energii
		///
		const float getEnergyFuelDuration() const;

		///
		///Metoda ustawia czas trwania stanu, po zgromadzeniu pe�nej energii
		///
		///@param energy_full_duration - czas trwania stanu, po zgromadzeniu pe�nej energii
		///
		void setEnergyFuelDuration(float energy_full_duration);

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:

		std::string		m_turbine_name;						//nazwa turbiny
		float			m_speed_rotor;						//pr�dko�� wirowania turbiny
		float			m_speed_transmission;				//przek�adnia - prze�o�enie pr�dko�ci obrotowej
		float			m_percentage_activation;			//procentowy wsp�czynnik aktywacji turbiny
		float			m_energy_full_duration;				//czas trwania stanu, po zgromadzeniu pe�nej energii
		ETurbineState	m_turbine_state;					//wyliczenie stan�w logicznych turbiny (maszyna stan�w)

		float			m_cargo_open_duration;				//czas trwania otwierania luku cargo
		float			m_cargo_close_duration;				//czas trwania zamykania luku cargo
		float			m_calculated_speed_rotor;			//obliczana pr�dko�� wirowania �opat turbiny
		float			m_calculated_energy_full_duration;	//obliczany czas trwania stanu, po zgromadzeniu pe�nej energii

		//prywatna metoda aktualizuje stan obiektu
		void updateTurbineState(float dt);
	};
}//namespace equipment
#endif//H_WIND_TURBINE_JACK
