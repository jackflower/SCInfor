//  ________________________________
// | Day.h - class definition       |
// | Jack Flower - June 2014        |
// |________________________________|
//

#ifndef H_DAY_JACK
#define H_DAY_JACK

#include "../RTTI/RTTI.h"

namespace weather
{
	///
	///Klasa reprezentuje dobę - czas trwania w sekundach
	///
	class Day
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		Day();

		///
		///Konstruktor kopiujący
		///
		///@param copy - stała referencja na obiekt klasy Day
		///
		Day(const Day & copy);

		///
		///Konstruktor przenoszący
		///
		///@param other - referencja do r-wartości
		///
		Day(Day && other);

		///
		///Destruktor
		///
		~Day();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Przeciążony operator przypisania kopiowania
		///
		///@param copy - stała referencja na obiekt klasy Day
		///
		Day & operator=(const Day & copy);

		///
		///Przeciążony operator przypisania przenoszenia
		///
		///@param other -  referencja do r-wartości
		///
		Day & operator=(Day && other);

		///
		///Metoda zwraca czas trwania doby
		///
		const float getDayDuration() const;

		///
		///Metoda ustawia czas trwania doby
		///
		///@param day_duration - czas trwania doby
		///
		void setDayDuration(float day_duration);

	private:
		
		float m_day_duration; //czas trwania doby

	};
}//namespace weather
#endif//H_DAY_JACK
