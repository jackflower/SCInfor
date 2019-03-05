//  ______________________________________________
// | EntityTemperature.h - class definition       |
// | Jack Flower - June 2014.                     |
// |______________________________________________|
//

#ifndef H_ENTITY_TEMPERATURE_JACK
#define H_ENTITY_TEMPERATURE_JACK

#include "../../RTTI/RTTI.h"


namespace universe
{
	class EntityTemperature
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EntityTemperature();

		///
		///Konstruktor kopiujący
		///
		///@param copy - stała referencja na obiekt klasy EntityTemperature
		///
		EntityTemperature(const EntityTemperature & copy);

		///
		///Destruktor
		///
		~EntityTemperature();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca temperaturę
		///
		const float getEntityTemperature() const;

		///
		///Metoda ustawia temperaturę
		///
		///@param entity_temperature - temperatura
		///
		void setEntityTemperature(float entity_temperature);

	private:

		float m_entity_temperature;	//temperatura
	};
}//namespace universe
#endif//H_ENTITY_TEMPERATURE_JACK
