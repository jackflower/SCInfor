//  ________________________________________________
// | CMagazineAmmunition.cpp - class implementation |
// | Jack Flower June 2014                          |
// |________________________________________________|
//

#include "CMagazineAmmunition.h"
#include "../../../Logic/Bullet/CBullet.h"
#include <vector>

namespace equipment
{
	namespace weapon
	{

		RTTI_IMPL(CMagazineAmmunition, CActor);

		//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
		CMagazineAmmunition::CMagazineAmmunition(const std::wstring& uniqueId)
		:
			CActor		(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CMagazineAmmunition::CMagazineAmmunition(const CMagazineAmmunition& CMagazineAmmunitionCopy)
		:
			CActor		(CMagazineAmmunitionCopy)
		{
		}

		CMagazineAmmunition::~CMagazineAmmunition()
		{
			//CActor	not edit
		}
	}//namespace weapon
}//namespace equipment