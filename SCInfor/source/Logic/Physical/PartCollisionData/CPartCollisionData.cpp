//  _______________________________________________
// | CPartCollisionData.cpp - class implementation |
// | Jack Flower - June 2016                       |
// |_______________________________________________|
//

#include "CPartCollisionData.h"
#include "CPartCollisionData.h"

namespace collisiondata
{
	RTTI_IMPL_NOPARENT(CPartCollisionData);

	//Konstruktor
	CPartCollisionData::CPartCollisionData()
	:
		m_colliding_body		(false),
		m_colliding_body_shadow	(false),
		m_colliding_head		(false),
		m_colliding_head_shadow	(false)
	{
	}

	//Konstruktor kopiuj¹cy
	CPartCollisionData::CPartCollisionData(const CPartCollisionData & CPartCollisionDataCopy)
		:
		m_colliding_body		(CPartCollisionDataCopy.m_colliding_body),
		m_colliding_body_shadow	(CPartCollisionDataCopy.m_colliding_body_shadow),
		m_colliding_head		(CPartCollisionDataCopy.m_colliding_head),
		m_colliding_head_shadow	(CPartCollisionDataCopy.m_colliding_head_shadow)
	{
	}

	//Destruktor
	CPartCollisionData::~CPartCollisionData()
	{
		m_colliding_body		= false;
		m_colliding_body_shadow	= false;
		m_colliding_head		= false;
		m_colliding_head_shadow	= false;
	}

	//Metoda zwraca flagê, czy obiekt koliduje - body
	const bool CPartCollisionData::getCollidingBody() const
	{
		return m_colliding_body;
	}

	//Metoda ustawia flagê, czy obiekt koliduje - body
	void CPartCollisionData::setCollidingBody(const bool colliding_body)
	{
		m_colliding_body = colliding_body;
	}

	//Metoda zwraca flagê, czy obiekt koliduje - body shadow
	const bool CPartCollisionData::getCollidingBodyShadow() const
	{
		return m_colliding_body_shadow;
	}

	//Metoda ustawia flagê, czy obiekt koliduje -  body shadow
	void CPartCollisionData::setCollidingBodyShadow(const bool colliding_body_shadow)
	{
		m_colliding_body_shadow = colliding_body_shadow;
	}

	//Metoda zwraca flagê, czy obiekt koliduje - head
	const bool CPartCollisionData::getCollidingHead() const
	{
		return m_colliding_head;
	}

	//Metoda ustawia flagê, czy obiekt koliduje -  head
	void CPartCollisionData::setCollidingHead(const bool colliding_head)
	{
		m_colliding_head = colliding_head;
	}

	//Metoda zwraca flagê, czy obiekt koliduje - head shadow
	const bool CPartCollisionData::getCollidingHeadShadow() const
	{
		return m_colliding_head_shadow;
	}

	//Metoda ustawia flagê, czy obiekt koliduje - head shadow
	void CPartCollisionData::setCollidingHeadShadow(const bool colliding_head_shadow)
	{
		m_colliding_head_shadow = colliding_head_shadow;
	}

}//namespace collisiondata