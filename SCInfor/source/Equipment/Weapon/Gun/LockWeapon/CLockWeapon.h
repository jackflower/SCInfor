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
			///klasa bazowa reprezentuje generator uszkodze� uzbrojenia
			///
			class CLockWeapon
			{
			public:

				///
				///Konstruktor
				///
				CLockWeapon();

				///
				///Konstruktor kopiuj�cy
				///
				///@param & CLockWeaponCopy - sta�a referencja na obiekt klasy CLockWeapon
				///
				CLockWeapon(const CLockWeapon & CLockWeaponCopy);

				///
				///Destruktor
				///
				~CLockWeapon();

				///
				///Metoda zwraca prawdopodobie�stwo uszkodzenia
				///
				const bool getDamage();

				///
				///Metoda zwraca sta�� referencj� na przedzia� liczbowy, w zakresie kt�rego nast�puje uszkodzenie
				///
				const std::pair<float, float> & getDamageRange() const;

				///
				///Metoda ustawia przedzia� liczbowy, w zakresie kt�rego nast�puje uszkodzenie
				///
				///@param damage_range_first - zakres g�rny
				///
				///@param damage_range_second - zakres dolny
				///
				void setDamageRange(float damage_range_first, float damage_range_second);

				///
				///Metoda zwraca ilo�� wyst�pie� uszkodze�
				///
				const unsigned getDamageCount() const;

				///
				///Metoda ustawia ilo�� wyst�pie� uszkodze�
				///
				///@param damage_count - ilo�� wyst�pie� uszkodze�
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

				float					m_damage;			//losowane prawdopodobie�stwo wyst�pienia uszkodzenia
				std::pair<float, float> m_damage_range;		//przedzia� w zakresie kt�rego definiujemy zaci�cie dzia�a < 0..1 >
				unsigned				m_damage_count;		//licznik wyst�pie� uszkodze�
				float					m_duration_damage;	//czas trwania uszkodzenia

				//prywatna metoda generuje uszkodzenie
				const bool generateDamage();

				static const std::pair<float, float> m_generator;//przedzia� dla generatora < 0..1 >
			};
		}//namespace lockweapon
	}//namespace weapon
}//namespace equipment
#endif//H_LOCK_WEAPON_JACK
