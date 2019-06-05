//  _______________________________________
// | LockWeapon.cpp - class implementation |
// | Jack Flower April 2016                |
// |_______________________________________|
//

#include "LockWeapon.h"
#include "../../../../Utilities/Random/CRandom.h"

namespace equipment
{
	namespace weapon
	{
		namespace lockweapon
		{
			//Konstruktor
			LockWeapon::LockWeapon()
			:
				m_damage{ 0.0f },
				m_damage_range{ 0.0f, 0.0f },
				m_damage_count{ 0 },
				m_duration_damage{ 0.0f }
			{
			}

			//Konstruktor kopiujący
			LockWeapon::LockWeapon(const LockWeapon & LockWeaponCopy)
			:
				m_damage{ LockWeaponCopy.m_damage },
				m_damage_range{ LockWeaponCopy.m_damage_range },
				m_damage_count{ LockWeaponCopy.m_damage_count },
				m_duration_damage{ LockWeaponCopy.m_duration_damage }
			{
			}

			//Destruktor
			LockWeapon::~LockWeapon()
			{
				m_damage = 0.0f;
				m_damage_range.first = 0.0f;
				m_damage_range.second = 0.0f;
				m_damage_count = 0;
				m_duration_damage = 0.0f;
			}

			//Metoda zwraca prawdopodobieństwo uszkodzenia
			const bool LockWeapon::getDamage()
			{
				return generateDamage();
			}

			//Metoda zwraca stałą referencję na przedział liczbowy, w zakresie którego następuje uszkodzenie
			const std::pair<float, float> & LockWeapon::getDamageRange() const
			{
				return m_damage_range;
			}

			//Metoda ustawia przedział liczbowy, w zakresie którego następuje uszkodzenie
			void LockWeapon::setDamageRange(float damage_range_first, float damage_range_second)
			{
				m_damage_range.first = damage_range_first;
				m_damage_range.second = damage_range_second;
			}

			//Metoda zwraca ilość wystąpień uszkodzeń
			const unsigned LockWeapon::getDamageCount() const
			{
				return m_damage_count;
			}

			//Metoda ustawia ilość wystąpień uszkodzeń
			void LockWeapon::setDamageCount(unsigned damage_count)
			{
				m_damage_count = damage_count;
			}

			//Metoda zwraca czas trwania uszkodzenia
			const float LockWeapon::getDurationDamage() const
			{
				return m_duration_damage;
			}

			//Metoda ustawia czas trwania uszkodzenia
			void LockWeapon::setDurationDamage(const float duration_damage)
			{
				m_duration_damage = duration_damage;
			}

			//Metoda generuje uszkodzenie
			const bool LockWeapon::generateDamage()
			{
				m_damage = gRandom.Rndf(m_generator.first, m_generator.second);
				if (m_damage > m_damage_range.first && m_damage < m_damage_range.second)
				{
					m_damage_count++;
					return true;
				}
				return false;
			}

		}//namespace lockweapon
	}//namespace weapon
}//namespace equipment

//Nadanie wartości stałym składowym statycznym
const std::pair<float, float> equipment::weapon::lockweapon::LockWeapon::m_generator(0.0f, 1.0f);//generator
