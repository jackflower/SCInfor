//  _________________________________
// | Wind.h - class definition       |
// | Jack Flower - April 2014        |
// |_________________________________|
//

#ifndef H_WIND_JACK
#define H_WIND_JACK

#include "../RTTI/RTTI.h"

namespace weather
{
	namespace wind
	{
		///
		///Klasa reprezentuje funkcjonalność wiatru
		///
		class Wind
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			Wind();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Wind
			///
			Wind(const Wind & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other - referencja do r-wartości
			///
			Wind(Wind && other);

			///
			///Destruktor
			///
			~Wind();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Wind
			///
			Wind & operator=(const Wind & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Wind & operator=(Wind && other);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca prędkość wiatru
			///
			const float getWindSpped() const;

			///
			///Metoda ustawia prędkość wiatru
			///
			///@param wind_speed - prędkość wiatru
			///
			void setWindSpped(float wind_speed);

			///
			///Metoda zwraca czas trwania wiatru
			///
			const float getWindDuriation() const;

			///
			///Metoda ustawia czas trwania wiatru
			///
			///@param duration_wind - czas trwania wiatru
			///
			void setWindDuriation(float duration_wind);

		private:
			
			float m_wind_speed; //prędkość wiatru
			float m_duration_wind; //czas trwania wiatru
		};
	}//	namespace wind
}//namespace weather
#endif//H_WIND_JACK
