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

	//Metoda zwraca flagê kolizji w obrêbie komóki (regionu, obszaru)
	bool CCell::getCollision() const
	{
		return m_collision;
	}

	//Metoda ustawia flagê kolizji w obrêbie komóki (regionu, obszaru)
	void CCell::setCollision(bool collision)
	{
		m_collision = collision;
	}

	//Metoda zwraca gêstoœæ w obrêbie regionu
	int CCell::getDensity()
	{
		return m_density;
	}

	//Metoda ustawia gêstoœæ w obrêbie regionu
	void CCell::setDensity(int density)
	{
		m_density = density;
	}

	///Metoda zwraca identyfikator regionu komórki
	int CCell::getRegionId()
	{
		return m_regionId;
	}

	//Metoda ustawia identyfikator regionu komórki
	void CCell::setRegionId(int regionId)
	{
		m_regionId = regionId;
	}
} //namespace mapengine