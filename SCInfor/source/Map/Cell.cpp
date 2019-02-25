//  _________________________________
// | Cell.cpp - class implementation |
// | Jack Flower - Fabruary 2015     |
// |_________________________________|
//

#include "Cell.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(Cell);

	//Konstruktor
	Cell::Cell()
	:
		m_collision(false),
		m_density(0),
		m_regionId(0)
	{
	}

	//Destruktor
	Cell::~Cell()
	{
		m_collision	= false;
		m_density	= 0;
		m_regionId	= 0;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Cell::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca flagę kolizji w obrębie komóki (regionu, obszaru)
	bool Cell::getCollision() const
	{
		return m_collision;
	}

	//Metoda ustawia flagę kolizji w obrębie komóki (regionu, obszaru)
	void Cell::setCollision(bool collision)
	{
		m_collision = collision;
	}

	//Metoda zwraca gęstość w obrębie regionu
	int Cell::getDensity()
	{
		return m_density;
	}

	//Metoda ustawia gęstość w obrębie regionu
	void Cell::setDensity(int density)
	{
		m_density = density;
	}

	///Metoda zwraca identyfikator regionu komórki
	int Cell::getRegionId()
	{
		return m_regionId;
	}

	//Metoda ustawia identyfikator regionu komórki
	void Cell::setRegionId(int regionId)
	{
		m_regionId = regionId;
	}
} //namespace mapengine
