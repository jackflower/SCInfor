//  ______________________________________________
// | PartCollisionData.cpp - class implementation |
// | Jack Flower - June 2016                      |
// |______________________________________________|
//

#include "PartCollisionData.h"
#include "PartCollisionData.h"

namespace collisiondata
{
	RTTI_IMPL_NOPARENT(PartCollisionData);

	//Konstruktor
	PartCollisionData::PartCollisionData()
	:
		m_colliding_body(false),
		m_colliding_body_shadow(false),
		m_colliding_head(false),
		m_colliding_head_shadow(false)
	{
	}

	//Konstruktor kopiujący
	PartCollisionData::PartCollisionData(const PartCollisionData & PartCollisionDataCopy)
		:
		m_colliding_body(PartCollisionDataCopy.m_colliding_body),
		m_colliding_body_shadow(PartCollisionDataCopy.m_colliding_body_shadow),
		m_colliding_head(PartCollisionDataCopy.m_colliding_head),
		m_colliding_head_shadow(PartCollisionDataCopy.m_colliding_head_shadow)
	{
	}

	//Destruktor
	PartCollisionData::~PartCollisionData()
	{
		m_colliding_body = false;
		m_colliding_body_shadow	= false;
		m_colliding_head = false;
		m_colliding_head_shadow	= false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PartCollisionData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca flagę, czy obiekt koliduje - body
	const bool PartCollisionData::getCollidingBody() const
	{
		return m_colliding_body;
	}

	//Metoda ustawia flagę, czy obiekt koliduje - body
	void PartCollisionData::setCollidingBody(const bool colliding_body)
	{
		m_colliding_body = colliding_body;
	}

	//Metoda zwraca flagę, czy obiekt koliduje - body shadow
	const bool PartCollisionData::getCollidingBodyShadow() const
	{
		return m_colliding_body_shadow;
	}

	//Metoda ustawia flagę, czy obiekt koliduje -  body shadow
	void PartCollisionData::setCollidingBodyShadow(const bool colliding_body_shadow)
	{
		m_colliding_body_shadow = colliding_body_shadow;
	}

	//Metoda zwraca flagę, czy obiekt koliduje - head
	const bool PartCollisionData::getCollidingHead() const
	{
		return m_colliding_head;
	}

	//Metoda ustawia flagę, czy obiekt koliduje -  head
	void PartCollisionData::setCollidingHead(const bool colliding_head)
	{
		m_colliding_head = colliding_head;
	}

	//Metoda zwraca flagę, czy obiekt koliduje - head shadow
	const bool PartCollisionData::getCollidingHeadShadow() const
	{
		return m_colliding_head_shadow;
	}

	//Metoda ustawia flagę, czy obiekt koliduje - head shadow
	void PartCollisionData::setCollidingHeadShadow(const bool colliding_head_shadow)
	{
		m_colliding_head_shadow = colliding_head_shadow;
	}
}//namespace collisiondata
