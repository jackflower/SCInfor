//  _________________________________________
// | CTemperature.h - class definition       |
// | Jack Flower - May 2014                  |
// |_________________________________________|


#ifndef H_TEMPERATURE_JACK
#define H_TEMPERATURE_JACK

#include "../RTTI/RTTI.h"

namespace weather
{
	namespace temperature
	{
		///
		///Klasa reprezentuje dynamicznie zmieniaj¹c¹ siê temperaturê w zale¿noœci od pozycji s³oñca
		///
		class CTemperature
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			CTemperature(void);

			///
			///Konstruktor kopiuj¹cy
			///
			///@param CTemperatureCopy - sta³a referecja na obiekt klasy CTemperature
			///
			CTemperature(const CTemperature & CTemperatureCopy);

			///
			///Destruktor
			///
			~CTemperature(void);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;
		
			///
			///Metoda zwraca temepraturê
			///
			const float getTemperature() const;

			///
			///Metoda ustawia temepraturê
			///
			///@param temperature - temperatura
			///
			void setTemperature(float temperature);

			///
			///Metoda zwraca temperaturê absolutn¹
			///
			const float getAbsoluteTemperature() const;

			///
			///Metoda ustawia temperaturê absolutn¹
			///
			///@param - temperatura absolutna
			///
			void setAbsoluteTemperature(float absolute_temperature);

			///
			///Metoda zwraca wspó³czynnik wahañ temperatury
			///
			const float getFluctuationTemperature() const;

			///
			///Metoda ustawia wspó³czynnik wahañ temperatury
			///
			///@param - wspó³czynnik wahañ temperatury
			///
			void setFluctuationTemperature(float temperature_fluctuations);

			///
			///Metoda aktualizuje logikê obiektu
			///
			///@param dt - czas
			///
			void Update(float dt);

		private:

			float m_temperature;				//temperatura
			float m_absolute_temperature;		//temperatura bezwglêdna
			float m_temperature_fluctuations;	//wspó³czynnik wahañ temperatury

		};
	}//namespace temperature
}//namespace weather
#endif//H_TEMPERATURE_JACK