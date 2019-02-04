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
		///Klasa reprezentuje dynamicznie zmieniaj�c� si� temperatur� w zale�no�ci od pozycji s�o�ca
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
			///Konstruktor kopiuj�cy
			///
			///@param CTemperatureCopy - sta�a referecja na obiekt klasy CTemperature
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
			///Metoda zwraca temepratur�
			///
			const float getTemperature() const;

			///
			///Metoda ustawia temepratur�
			///
			///@param temperature - temperatura
			///
			void setTemperature(float temperature);

			///
			///Metoda zwraca temperatur� absolutn�
			///
			const float getAbsoluteTemperature() const;

			///
			///Metoda ustawia temperatur� absolutn�
			///
			///@param - temperatura absolutna
			///
			void setAbsoluteTemperature(float absolute_temperature);

			///
			///Metoda zwraca wsp�czynnik waha� temperatury
			///
			const float getFluctuationTemperature() const;

			///
			///Metoda ustawia wsp�czynnik waha� temperatury
			///
			///@param - wsp�czynnik waha� temperatury
			///
			void setFluctuationTemperature(float temperature_fluctuations);

			///
			///Metoda aktualizuje logik� obiektu
			///
			///@param dt - czas
			///
			void Update(float dt);

		private:

			float m_temperature;				//temperatura
			float m_absolute_temperature;		//temperatura bezwgl�dna
			float m_temperature_fluctuations;	//wsp�czynnik waha� temperatury

		};
	}//namespace temperature
}//namespace weather
#endif//H_TEMPERATURE_JACK