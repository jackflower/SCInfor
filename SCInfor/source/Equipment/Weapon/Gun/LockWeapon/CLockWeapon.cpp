//  ________________________________________
// | CLockWeapon.cpp - class implementation |
// | Jack Flower April 2016                 |
// |________________________________________|
//

#include "CLockWeapon.h"
#include "../../../../Utilities/Random/CRandom.h"

namespace equipment
{
	namespace weapon
	{
		namespace lockweapon
		{
			//Konstruktor
			CLockWeapon::CLockWeapon()
			:
				m_damage				(0.0f),
				m_damage_range			(0.0f, 0.0f),
				m_damage_count			(0),
				m_duration_damage		(0.0f)
			{
			}

			//Konstruktor kopiuj¹cy
			CLockWeapon::CLockWeapon(const CLockWeapon & CLockWeaponCopy)
			:
				m_damage				(CLockWeaponCopy.m_damage),
				m_damage_range			(CLockWeaponCopy.m_damage_range),
				m_damage_count			(CLockWeaponCopy.m_damage_count),
				m_duration_damage		(CLockWeaponCopy.m_duration_damage)
			{
			}

			//Destruktor
			CLockWeapon::~CLockWeapon()
			{
				m_damage				= 0.0f;
				m_damage_range.first	= 0.0f;
				m_damage_range.second	= 0.0f;
				m_damage_count			= 0;
				m_duration_damage		= 0.0f;
			}

			//Metoda zwraca prawdopodobieñstwo uszkodzenia
			const bool CLockWeapon::getDamage()
			{
				return generateDamage();
			}

			//Metoda zwraca sta³¹ referencjê na przedzia³ liczbowy, w zakresie którego nastêpuje uszkodzenie
			const std::pair<float, float> & CLockWeapon::getDamageRange() const
			{
				return m_damage_range;
			}

			//Metoda ustawia przedzia³ liczbowy, w zakresie którego nastêpuje uszkodzenie
			void CLockWeapon::setDamageRange(float damage_range_first, float damage_range_second)
			{
				m_damage_range.first = damage_range_first;
				m_damage_range.second = damage_range_second;
			}

			//Metoda zwraca iloœæ wyst¹pieñ uszkodzeñ
			const unsigned CLockWeapon::getDamageCount() const
			{
				return m_damage_count;
			}

			//Metoda ustawia iloœæ wyst¹pieñ uszkodzeñ
			void CLockWeapon::setDamageCount(unsigned damage_count)
			{
				m_damage_count = damage_count;
			}

			//Metoda zwraca czas trwania uszkodzenia
			const float CLockWeapon::getDurationDamage() const
			{
				return m_duration_damage;
			}

			//Metoda ustawia czas trwania uszkodzenia
			void CLockWeapon::setDurationDamage(const float duration_damage)
			{
				m_duration_damage = duration_damage;
			}

			//Metoda generuje uszkodzenie
			const bool CLockWeapon::generateDamage()
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

//Nadanie wartoœci sta³ym sk³adowym statycznym
const std::pair<float, float> equipment::weapon::lockweapon::CLockWeapon::m_generator(0.0f, 1.0f);//generator