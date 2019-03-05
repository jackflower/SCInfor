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
					///Klasa reprezentuje satelitê
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
						///Konstruktor kopiuj¹cy
						///
						///@param copy - sta³a referecja na obiekt klasy Satelite
						///
						Satelite(const Satelite & copy);

						///
						///Konstruktor przenosz¹cy
						///
						///@param other - referencja do r-wartoœci
						///
						Satelite(Satelite && other);

						///
						///Destruktor
						///
						~Satelite();

						///
						///Przeci¹¿ony operator przypisania kopiowania
						///
						///@param copy - sta³a referencja na obiekt klasy Satelite
						///
						Satelite & operator=(const Satelite & copy);

						///
						///Przeci¹¿ony operator przypisania przenoszenia
						///
						///@param other -  referencja do r-wartoœci
						///
						Satelite & operator=(Satelite && other);

						///
						///Metoda zwraca typ obiektu /RTTI/
						///
						const std::string getType() const;

						///
						///Metoda zwraca temperaturê satelity
						///
						const float getSateliteTemperature() const;

						///
						///Metoda ustawia temperaturê satelity
						///
						///@param satelite_temperature - temperatura satelity
						///
						void setSateliteTemperature(float satelite_temperature);

						///
						///Metoda zwraca grawitacjê satelity
						///
						const float getSateliteGravity() const;

						///
						///Metoda ustawia grawitacjê satelity
						///
						///@param satelite_gravity - grawitacjê satelity
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
