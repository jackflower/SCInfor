//  ________________________________________________
// | GroundWorkCollision.cpp - class implementation |
// | Jack Flower - March 2015                       |
// |________________________________________________|
//

#include "GroundWorkCollision.h"

namespace mapengine
{
	namespace groundwork
	{
		RTTI_IMPL_NOPARENT(GroundWorkCollision);

		//Konstruktor
		GroundWorkCollision::GroundWorkCollision()
		:
			m_size(0, 0),
			m_ground_work_list()
		{
		}

		//Konstruktor kopiujący
		GroundWorkCollision::GroundWorkCollision(const GroundWorkCollision & GroundWorkCollisionCopy)
		:
			m_size(GroundWorkCollisionCopy.m_size),
			m_ground_work_list(GroundWorkCollisionCopy.m_ground_work_list)
		{
		}

		//Destruktor
		GroundWorkCollision::~GroundWorkCollision()
		{
			m_size.x = 0;
			m_size.y = 0;
			//m_ground_work_list
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string GroundWorkCollision::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca rozmiar mapy kolizji
		sf::Vector2i & GroundWorkCollision::getSize()
		{
			return m_size; 
		}
	}//namespace groundwork
}//namespace mapengine
