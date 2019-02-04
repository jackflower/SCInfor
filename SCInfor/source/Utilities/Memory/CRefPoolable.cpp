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

//Konstruktor kopiujπcy
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

//Wirtualna metoda zwalnia zajmowanπ pamiÍÊ
void CRefPoolable::Release()
{
	if (p_pool != NULL)
		p_pool->DeallocMe(this);
	else
		delete this;
}

//Wirtualna metoda ustawia wskaünik na obiekt klasy CPoolBase
void CRefPoolable::Bind(CPoolBase *pool)
{
	p_pool = pool;
}
