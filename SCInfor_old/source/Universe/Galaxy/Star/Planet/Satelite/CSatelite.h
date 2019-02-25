/*
 ______________________________________
| CSatelite.h - definicja klasy.       |
| Jack Flower - May 2014.              |
|______________________________________|

*/

#ifndef H_SATELITE_JACK
#define H_SATELITE_JACK

#include "../../../../../RTTI/RTTI.h"
#include "../../../../Interaction/CEntityTemperature.h"
#include "../../../../Interaction/CGravity.h"

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
					class CSatelite
					{
						RTTI_DECL;

					public:

						///
						///Knstruktor
						///
						CSatelite(void);

						///
						///Konstruktor kopiuj¹cy
						///
						///@param CSatelite - sta³a referecja na obiekt klasy CSateliteCopy
						///
						CSatelite(const CSatelite & CSateliteCopy);

						///
						///Destruktor
						///
						~CSatelite(void);

						///
						///Metoda zwraca typ obiektu /RTTI/
						///
						const std::string GetType() const;

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
					
						CEntityTemperature	m_satelite_temperature;	//temperatura satelity
						CGravity			m_satelite_gravity;		//grawitacja
					};
				}//namespace satelite
			}//namespace planet
		}//namespace star
	}//namespace galaxy
}//namespace universe
#endif//H_SATELITE_JACK