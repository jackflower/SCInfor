//  ____________________________________
// | Caliber.h - class definition       |
// | Jack Flower - March 2016           |
// |____________________________________|
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
		class Caliber
		{
		public:

			///
			///Konstruktor
			///
			Caliber();

			///
			///Konstruktor kopiujący
			///
			///@param CaliberCopy - obiekt klasy Caliber
			///
			Caliber(const Caliber & CaliberCopy);

			///
			///Destruktor
			///
			~Caliber();

			///
			///Metoda zwraca nazwę kalibru
			///
			const std::string & getName() const;

			///
			///Metoda ustawia nazwę kalibru
			///
			///@param & name - stała referencja na obiekt klasy std::string
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
			///Metoda zwraca stałą referencję na wyliczenie ECaliber
			///
			const ECaliber & getCaliberType() const;

			///
			///Metoda ustawia referencję na wyliczenie ECaliber
			///
			///@param & caliber - stała referencja na wyliczenie ECaliber
			///
			void setCaliberType(const ECaliber & caliber);

		private:

			std::string m_name; //nazwa kalibru np. Caliber 44
			float m_caliber; //kaliber urzbrojenia
			ECaliber e_caliber;	//typ kalibru
		};
	}//namespace weapon
}//namespace equipment
#endif//H_CALIBER_JACK
