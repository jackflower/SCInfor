//  _____________________________________
// | CCaliber.h - class definition       |
// | Jack Flower - March 2016            |
// |_____________________________________|
//

#ifndef H_CALIBER_JACK
#define H_CALIBER_JACK

#include <string>
#include "ECaliber.h"

namespace equipment
{
	namespace weapon
	{
		///
		///Klasa reprezentuje opakowanie informacji o kalibrze uzbrojenia
		///
		class CCaliber
		{
		public:

			///
			///Konstruktor
			///
			CCaliber();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param CCaliberCopy - obiekt klasy CCaliber
			///
			CCaliber(const CCaliber& CCaliberCopy);

			///
			///Destruktor
			///
			~CCaliber();

			///
			///Metoda zwraca nazwê kalibru
			///
			const std::string & getName() const;

			///
			///Metoda ustawia nazwê kalibru
			///
			///@param & name - sta³a referencja na obiekt klasy std::string
			///
			void setName(const std::string & name);

			///
			///Metoda zwraca kaliber uzbrojenia
			///
			const float getCaliber() const;

			///
			///Metoda ustawia kaliber uzbrojenia
			///
			///
			///@param caliber - kaliber uzbrojenia
			///
			void setCaliber(const float caliber);

			///
			///Metoda zwraca sta³¹ referencjê na wyliczenie ECaliber
			///
			const ECaliber & getCaliberType() const;

			///
			///Metoda ustawia referencjê na wyliczenie ECaliber
			///
			///@param & caliber - sta³a referencja na wyliczenie ECaliber
			///
			void setCaliberType(const ECaliber & caliber);

		private:

			std::string		m_name;		//nazwa kalibru np. Caliber 44
			float			m_caliber;	//kaliber urzbrojenia
			ECaliber		e_caliber;	//typ kalibru
		};
	}//namespace weapon
}//namespace equipment
#endif//H_CALIBER_JACK
