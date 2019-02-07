//  _______________________________________________
// | MagazineAmmunition.cpp - class implementation |
// | Jack Flower June 2014                         |
// |_______________________________________________|
//

#include "MagazineAmmunition.h"
#include "../../../Logic/Bullet/CBullet.h"
#include <vector>

namespace equipment
{
	namespace weapon
	{

		RTTI_IMPL(MagazineAmmunition, CActor);

		//Chroniony konstruktor domyślny - używany wyłącznie przez CPhysicalManager
		MagazineAmmunition::MagazineAmmunition(const std::wstring & uniqueId)
		:
			CActor(uniqueId),//konstruktor klasy bazowej
			m_ammunition_name(),
			m_ammunition_capacity(0),
			m_magazine_ammunition_caliber(),
			m_percentage_reserve_ammunition(0.0f),
			m_bullets()
		{
			//to do: layers
		}

		//Chroniony konstruktor kopiujący
		MagazineAmmunition::MagazineAmmunition(const MagazineAmmunition& MagazineAmmunitionCopy)
		:
			CActor(MagazineAmmunitionCopy),//konstruktor kopiujący klasy bazowej
			m_ammunition_name(MagazineAmmunitionCopy.m_ammunition_name),
			m_ammunition_capacity(MagazineAmmunitionCopy.m_ammunition_capacity),
			m_magazine_ammunition_caliber(MagazineAmmunitionCopy.m_magazine_ammunition_caliber),
			m_percentage_reserve_ammunition(MagazineAmmunitionCopy.m_percentage_reserve_ammunition),
			m_bullets(MagazineAmmunitionCopy.m_bullets)
		{
			//to do: layers
		}

		MagazineAmmunition::~MagazineAmmunition()
		{
			//CActor
			m_ammunition_name = "";
			m_ammunition_capacity = 0;
			//m_magazine_ammunition_caliber
			m_percentage_reserve_ammunition = 0.0f;
			//m_bullets
		}

	}//namespace weapon
}//namespace equipment