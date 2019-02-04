//  _________________________________________________
// | CGroundWorkCollision.cpp - class implementation |
// | Jack Flower - March 2015                        |
// |_________________________________________________|
//

#include "CGroundWorkCollision.h"

namespace mapengine
{
	namespace groundwork
	{
		RTTI_IMPL_NOPARENT(CGroundWorkCollision);

		//Konstruktor
		CGroundWorkCollision::CGroundWorkCollision()
		:
			m_size				(0, 0),
			m_ground_work_list	()
		{
		}

		//Konstruktor kopiuj¹cy
		CGroundWorkCollision::CGroundWorkCollision(const CGroundWorkCollision & CGroundWorkCollisionCopy)
		:
			m_size				(CGroundWorkCollisionCopy.m_size),
			m_ground_work_list	(CGroundWorkCollisionCopy.m_ground_work_list)
		{
		}

		//Destruktor
		CGroundWorkCollision::~CGroundWorkCollision()
		{
			m_size.x			= 0;
			m_size.y			= 0;
			//m_ground_work_list not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CGroundWorkCollision::GetType() const
		{
			return rtti.GetNameClass();
		}
	}//namespace groundwork
}//namespace mapengine
