//  ________________________________________
// | CLockWeapon.h - class definition       |
// | Jack Flower April 2016                 |
// |________________________________________|
//

#ifndef H_LOCK_WEAPON_JACK
#define H_LOCK_WEAPON_JACK

#include <iostream>

namespace equipment
{
	namespace weapon
	{
		namespace lockweapon
		{
			///
			///klasa bazowa reprezentuje generator uszkodzeñ uzbrojenia
			///
			class CLockWeapon
			{
			public:

				///
				///Konstruktor
				///
				CLockWeapon();

				///
				///Konstruktor kopiuj¹cy
				///
				///@param & CLockWeaponCopy - sta³a referencja na obiekt klasy CLockWeapon
				///
				CLockWeapon(const CLockWeapon & CLockWeaponCopy);

				///
				///Destruktor
				///
				~CLockWeapon();

				///
				///Metoda zwraca prawdopodobieñstwo uszkodzenia
				///
				const bool getDamage();

				///
				///Metoda zwraca sta³¹ referencjê na przedzia³ liczbowy, w zakresie którego nastêpuje uszkodzenie
				///
				const std::pair<float, float> & getDamageRange() const;

				///
				///Metoda ustawia przedzia³ liczbowy, w zakresie którego nastêpuje uszkodzenie
				///
				///@param damage_range_first - zakres górny
				///
				///@param damage_range_second - zakres dolny
				///
				void setDamageRange(float damage_range_first, float damage_range_second);

				///
				///Metoda zwraca iloœæ wyst¹pieñ uszkodzeñ
				///
				const unsigned getDamageCount() const;

				///
				///Metoda ustawia iloœæ wyst¹pieñ uszkodzeñ
				///
				///@param damage_count - iloœæ wyst¹pieñ uszkodzeñ
				///
				void setDamageCount(unsigned damage_count);

				///
				///Metoda zwraca czas trwania uszkodzenia
				///
				const float getDurationDamage() const;

				///
				///Metoda ustawia czas trwania uszkodzenia
				///
				///@param duration_damage - czas trwania uszkodzenia
				///
				void setDurationDamage(const float duration_damage);

			private:

				float					m_damage;			//losowane prawdopodobieñstwo wyst¹pienia uszkodzenia
				std::pair<float, float> m_damage_range;		//przedzia³ w zakresie którego definiujemy zaciêcie dzia³a < 0..1 >
				unsigned				m_damage_count;		//licznik wyst¹pieñ uszkodzeñ
				float					m_duration_damage;	//czas trwania uszkodzenia

				//prywatna metoda generuje uszkodzenie
				const bool generateDamage();

				static const std::pair<float, float> m_generator;//przedzia³ dla generatora < 0..1 >
			};
		}//namespace lockweapon
	}//namespace weapon
}//namespace equipment
#endif//H_LOCK_WEAPON_JACK
