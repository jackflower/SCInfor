/*
 _______________________________________________
| CEntityTemperature.h - definicja klasy.       |
| Jack Flower - June 2014.                      |
|_______________________________________________|

*/

#ifndef H_ENTITY_TEMPERATURE_JACK
#define H_ENTITY_TEMPERATURE_JACK

#include "../../RTTI/RTTI.h"


namespace universe
{
	class CEntityTemperature
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEntityTemperature(void);

		///
		///Konstruktor kopiuj�cy
		///
		///@param &CEntityTemperatureCopy - sta�a referencja na obiekt klasy CEntityTemperature
		///
		CEntityTemperature(const CEntityTemperature & CEntityTemperatureCopy);

		///
		///Destruktor
		///
		~CEntityTemperature(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca temperatur�
		///
		const float getEntityTemperature() const;

		///
		///Metoda ustawia temperatur�
		///
		///@param entity_temperature - temperatura
		///
		void setEntityTemperature(float entity_temperature);

	private:

		float m_entity_temperature;	//temperatura
	};
}//namespace universe
#endif//H_ENTITY_TEMPERATURE_JACK