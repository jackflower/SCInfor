//  _____________________________________
// | Satelite.h - class definition klasy |
// | Jack Flower - May 2014              |
// |_____________________________________|
//

#ifndef H_SATELITE_JACK
#define H_SATELITE_JACK

#include "../../../../../RTTI/RTTI.h"
#include "../../../../Interaction/EntityTemperature.h"
#include "../../../../Interaction/Gravity.h"

using namespace interaction;

namespace universe
{
	namespace galaxy
	{
		namespace star
		{
			namespace planet
			{
				namespace satelite
				{
			
					///
					///Klasa reprezentuje satelit�
					///
					class Satelite
					{
						RTTI_DECL;

					public:

						///
						///Knstruktor
						///
						Satelite();

						///
						///Konstruktor kopiuj�cy
						///
						///@param copy - sta�a referecja na obiekt klasy Satelite
						///
						Satelite(const Satelite & copy);

						///
						///Konstruktor przenosz�cy
						///
						///@param other - referencja do r-warto�ci
						///
						Satelite(Satelite && other);

						///
						///Destruktor
						///
						~Satelite();

						///
						///Przeci��ony operator przypisania kopiowania
						///
						///@param copy - sta�a referencja na obiekt klasy Satelite
						///
						Satelite & operator=(const Satelite & copy);

						///
						///Przeci��ony operator przypisania przenoszenia
						///
						///@param other -  referencja do r-warto�ci
						///
						Satelite & operator=(Satelite && other);

						///
						///Metoda zwraca typ obiektu /RTTI/
						///
						const std::string getType() const;

						///
						///Metoda zwraca temperatur� satelity
						///
						const float getSateliteTemperature() const;

						///
						///Metoda ustawia temperatur� satelity
						///
						///@param satelite_temperature - temperatura satelity
						///
						void setSateliteTemperature(float satelite_temperature);

						///
						///Metoda zwraca grawitacj� satelity
						///
						const float getSateliteGravity() const;

						///
						///Metoda ustawia grawitacj� satelity
						///
						///@param satelite_gravity - grawitacj� satelity
						///
						void setSateliteGravity(float satelite_gravity);

					private:
					
						EntityTemperature m_satelite_temperature; //temperatura satelity
						Gravity m_satelite_gravity; //grawitacja
					};
				}//namespace satelite
			}//namespace planet
		}//namespace star
	}//namespace galaxy
}//namespace universe
#endif//H_SATELITE_JACK
