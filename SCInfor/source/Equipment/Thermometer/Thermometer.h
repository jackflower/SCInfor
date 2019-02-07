﻿//  ________________________________________
// | Thermometer.h - class definition       |
// | Jack Flower - April 2015               |
// |________________________________________|
//

#ifndef H_THERMOMETER_JACK
#define H_THERMOMETER_JACK

#include "../../RTTI/RTTI.h"
#include "../../Logic/Physical/CPhysical.h"
#include "EDisplayType.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje termometr - urządzenie pomiarowe
	///
	class Thermometer : public CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskać obiekt Thermometer, należy wywołać CPhysicalManager::CreateThermometer();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		Thermometer(const std::wstring & uniqueId);
	
		///
		///Chroniony konstruktor kopiujący
		///
		///@param ThermometerCopy - obiekt klasy Thermometer
		///
		Thermometer(const Thermometer & ThermometerCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		///
		virtual ~Thermometer();

	public:

		///
		///Metoda zwraca temperaturę
		///
		const float getTemperature() const;

		///
		///Metoda ustawia temperaturę
		///
		///@param temperature - temperatura
		///
		const void setTemperature(float temperature);

		///
		///Wirtualna metoda aktualizuje logikę obiektu
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:
		
		typedef struct {float min; float max;} Range;//definicja typu
		
		Range			m_range;		//zakres pomiaru temperatury
		float			m_temperature;	//temperatura pomiaru
		EDisplayType	e_display_type;	//typ prezentacji temperatury
	};
}
#endif//H_THERMOMETER_JACK