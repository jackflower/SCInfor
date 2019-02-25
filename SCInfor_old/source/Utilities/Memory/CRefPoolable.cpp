//  _________________________________________
// | CRefPoolable.cpp - class implementation |
// | Jack Flower October 2012                |
// |_________________________________________|
//

#include "CRefPoolable.h"

using namespace memory;

//Konstruktor
CRefPoolable::CRefPoolable()
:
	m_ref_count	(0),
	p_pool		(NULL)
{
}

//Konstruktor kopiuj�cy
CRefPoolable::CRefPoolable(const CRefPoolable &other)
:
	m_ref_count	(0),
	p_pool		(other.p_pool)
{
}

//Destruktor wirtualny
CRefPoolable::~CRefPoolable()
{
	m_ref_count = 0;
	p_pool		= NULL;
}

//Wirtualna metoda zwalnia zajmowan� pami��
void CRefPoolable::Release()
{
	if (p_pool != NULL)
		p_pool->DeallocMe(this);
	else
		delete this;
}

//Wirtualna metoda ustawia wska�nik na obiekt klasy CPoolBase
void CRefPoolable::Bind(CPoolBase *pool)
{
	p_pool = pool;
}
