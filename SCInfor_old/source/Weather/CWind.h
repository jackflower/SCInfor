//  __________________________________
// | CWind.h - class definition       |
// | Jack Flower - April 2014         |
// |__________________________________|
//

#ifndef H_WIND_JACK
#define H_WIND_JACK

#include "../RTTI/RTTI.h"

namespace weather
{
	namespace wind
	{
		///
		///Klasa reprezentuje funkcjonalnoœæ wiatru
		///
		class CWind
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			CWind();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param &CWindCopy - sta³a referencja na obiekt klasy CWind
			///
			CWind(const CWind& CWindCopy);

			///
			///Destruktor
			///
			~CWind();

			///
			///Metoda zwraca prêdkoœæ wiatru
			///
			const float getWindSpped() const;

			///
			///Metoda ustawia prêdkoœæ wiatru
			///
			///@param wind_speed - prêdkoœæ wiatru
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
			
			float	m_wind_speed;		//prêdkoœæ wiatru
			float	m_duration_wind;	//czas trwania wiatru
		};
	}//	namespace wind
}//namespace weather
#endif//H_WIND_JACK