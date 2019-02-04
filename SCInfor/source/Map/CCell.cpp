//  __________________________________
// | CCell.cpp - class implementation |
// | Jack Flower - Fabruary 2015.     |
// |__________________________________|
//

#include "CCell.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CCell);

	//Konstruktor
	CCell::CCell()
	:
		m_collision	(false),
		m_density	(0),
		m_regionId	(0)
	{
	}

	//Destruktor
	CCell::~CCell()
	{
		m_collision	= false;
		m_density	= 0;
		m_regionId	= 0;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CCell::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca flag� kolizji w obr�bie kom�ki (regionu, obszaru)
	bool CCell::getCollision() const
	{
		return m_collision;
	}

	//Metoda ustawia flag� kolizji w obr�bie kom�ki (regionu, obszaru)
	void CCell::setCollision(bool collision)
	{
		m_collision = collision;
	}

	//Metoda zwraca g�sto�� w obr�bie regionu
	int CCell::getDensity()
	{
		return m_density;
	}

	//Metoda ustawia g�sto�� w obr�bie regionu
	void CCell::setDensity(int density)
	{
		m_density = density;
	}

	///Metoda zwraca identyfikator regionu kom�rki
	int CCell::getRegionId()
	{
		return m_regionId;
	}

	//Metoda ustawia identyfikator regionu kom�rki
	void CCell::setRegionId(int regionId)
	{
		m_regionId = regionId;
	}
} //namespace mapengine