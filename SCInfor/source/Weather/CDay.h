//  _________________________________
// | CDay.h - class definition       |
// | Jack Flower - June 2014         |
// |_________________________________|
//

#ifndef H_DAY_JACK
#define H_DAY_JACK

namespace weather
{
	///
	///Klasa reprezentuje dobê - czas trwania w sekundach
	///
	class CDay
	{
	public:

		///
		///Konstruktor
		///
		CDay();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param &CDayCopy - sta³a referencja na obiekt klasy CDay
		///
		CDay(const CDay & CDayCopy);

		///
		///Destruktor
		///
		~CDay();

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
		
		float m_day_duration;		//czas trwania doby

	};
}//namespace weather
#endif//H_DAY_JACK