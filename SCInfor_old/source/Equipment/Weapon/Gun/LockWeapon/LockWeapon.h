//  _______________________________________
// | LockWeapon.h - class definition       |
// | Jack Flower April 2016                |
// |_______________________________________|
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
			///klasa bazowa reprezentuje generator uszkodzeń uzbrojenia
			///
			class LockWeapon
			{
			public:

				///
				///Konstruktor
				///
				LockWeapon();

				///
				///Konstruktor kopiujący
				///
				///@param LockWeaponCopy - stała referencja na obiekt klasy LockWeapon
				///
				LockWeapon(const LockWeapon & LockWeaponCopy);

				///
				///Destruktor
				///
				~LockWeapon();

				///
				///Metoda zwraca prawdopodobieństwo uszkodzenia
				///
				const bool getDamage();

				///
				///Metoda zwraca stałą referencję na przedział liczbowy, w zakresie którego następuje uszkodzenie
				///
				const std::pair<float, float> & getDamageRange() const;

				///
				///Metoda ustawia przedział liczbowy, w zakresie którego następuje uszkodzenie
				///
				///@param damage_range_first - zakres górny
				///
				///@param damage_range_second - zakres dolny
				///
				void setDamageRange(float damage_range_first, float damage_range_second);

				///
				///Metoda zwraca ilość wystąpień uszkodzeń
				///
				const unsigned getDamageCount() const;

				///
				///Metoda ustawia ilość wystąpień uszkodzeń
				///
				///@param damage_count - ilość wystąpień uszkodzeń
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

				float m_damage; //losowane prawdopodobieństwo wystąpienia uszkodzenia
				std::pair<float, float> m_damage_range; //przedział w zakresie którego definiujemy zacięcie działa < 0..1 >
				unsigned m_damage_count; //licznik wystąpień uszkodzeń
				float m_duration_damage; //czas trwania uszkodzenia

				//prywatna metoda generuje uszkodzenie
				const bool generateDamage();

				static const std::pair<float, float> m_generator;//przedział dla generatora < 0..1 >
			};
		}//namespace lockweapon
	}//namespace weapon
}//namespace equipment
#endif//H_LOCK_WEAPON_JACK
