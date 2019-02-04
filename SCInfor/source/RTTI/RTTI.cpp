//  _________________________________
// | RTTI.cpp - class implementation |
// | Jack Flower October 2012        |
// |_________________________________|
//


#include "RTTI.h"

//Konstruktor
RTTI::RTTI(const std::string & class_name)
	:
	m_class_name(class_name),
	p_base_RTTI(NULL)
{
}

//Konstruktor
RTTI::RTTI(const std::string & class_name, const RTTI & baseRTTI)
	:
	m_class_name(class_name),
	p_base_RTTI(&baseRTTI)
{
}

//Metoda zwraca flag�, czy obiekt ma klas� bazow�
bool RTTI::DerivesFrom (const RTTI & rtti) const
{
    const RTTI * pCompare = this;

    while (pCompare != NULL)
    {
        if (pCompare == &rtti)
            return true;
        pCompare = pCompare->p_base_RTTI;
    }
    return false;
}
