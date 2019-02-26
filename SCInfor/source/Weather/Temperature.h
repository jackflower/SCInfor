//  ________________________________________
// | Temperature.h - class definition       |
// | Jack Flower - May 2014                 |
// |________________________________________|


#ifndef H_TEMPERATURE_JACK
#define H_TEMPERATURE_JACK

#include "../RTTI/RTTI.h"

namespace weather
{
	namespace temperature
	{
		///
		///Klasa reprezentuje dynamicznie zmieniającą się temperaturę w zależności od pozycji słońca
		///
		class Temperature
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			Temperature();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referecja na obiekt klasy Temperature
			///
			Temperature(const Temperature & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other - referencja do r-wartości
			///
			Temperature(Temperature && other);

			///
			///Destruktor
			///
			~Temperature();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Temperature
			///
			Temperature & operator=(const Temperature & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Temperature & operator=(Temperature && other);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;
		
			///
			///Metoda zwraca temepraturę
			///
			const float getTemperature() const;

			///
			///Metoda ustawia temepraturę
			///
			///@param temperature - temperatura
			///
			void setTemperature(float temperature);

			///
			///Metoda zwraca temperaturę absolutną
			///
			const float getAbsoluteTemperature() const;

			///
			///Metoda ustawia temperaturę absolutną
			///
			///@param - temperatura absolutna
			///
			void setAbsoluteTemperature(float absolute_temperature);

			///
			///Metoda zwraca współczynnik wahań temperatury
			///
			const float getFluctuationTemperature() const;

			///
			///Metoda ustawia współczynnik wahań temperatury
			///
			///@param - współczynnik wahań temperatury
			///
			void setFluctuationTemperature(float temperature_fluctuations);

			///
			///Metoda aktualizuje logikę obiektu
			///
			///@param dt - czas
			///
			void update(float dt);

		private:

			float m_temperature; //temperatura
			float m_absolute_temperature; //temperatura bezwględna
			float m_temperature_fluctuations; //współczynnik wahań temperatury

		};
	}//namespace temperature
}//namespace weather
#endif//H_TEMPERATURE_JACK