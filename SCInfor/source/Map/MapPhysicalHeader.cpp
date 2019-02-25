//  ______________________________________________
// | MapPhysicalHeader.cpp - class implementation |
// | Jack Flower October 2012                     |
// |______________________________________________|
//

#include "MapPhysicalHeader.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(MapPhysicalHeader);

	//Konstruktor
	MapPhysicalHeader::MapPhysicalHeader()
	:
		m_size_in_map_physical(),
		m_size()
	{
	}

	//Konstruktor kopiujący
	MapPhysicalHeader::MapPhysicalHeader(const MapPhysicalHeader & MapPhisicalHeaderCopy)
	:
		m_size_in_map_physical(MapPhisicalHeaderCopy.m_size_in_map_physical),
		m_size(MapPhisicalHeaderCopy.m_size)
	{
	}

	//Destruktor
	MapPhysicalHeader::~MapPhysicalHeader()
	{
		//m_size_in_map_physical
		//m_size
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string MapPhysicalHeader::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca rozmiar podłoża wyrażony w ilości obiektów na mapie
	const sf::Vector2u & MapPhysicalHeader::getSizeInMapPhysical() const
	{
		return m_size_in_map_physical;
	}

	//Metoda ustawia rozmiar podłoża wyrażony w ilości obiektów na mapie
	void MapPhysicalHeader::setSizeInMapPhysical(const sf::Vector2u & size_in_map_physical)
	{
		m_size_in_map_physical = size_in_map_physical;
	}

	//Metoda ustawia rozmiar podłoża wyrażony w ilości obiektów na mapie
	void MapPhysicalHeader::setSizeInMapPhysical(unsigned width_in_map_physical, unsigned height_in_map_physical)
	{
		m_size_in_map_physical.x = width_in_map_physical;
		m_size_in_map_physical.y = height_in_map_physical;
	}

	//Metoda ustawia rozmiar podłoża wyrażony w ilości obiektów na mapie
	void MapPhysicalHeader::setSizeInMapPhysical(unsigned uniform)
	{
		m_size_in_map_physical.x = uniform;
		m_size_in_map_physical.y = uniform;
	}

	//Metoda zwraca rozmiar obiektu
	const sf::Vector2u & MapPhysicalHeader::getSize() const
	{
		return m_size;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysicalHeader::setSize(const sf::Vector2u & size)
	{
		m_size = size;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysicalHeader::setSize(unsigned x, unsigned y)
	{
		m_size.x = x;
		m_size.y = y;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysicalHeader::setSize(unsigned uniform)
	{
		m_size.x = uniform;
		m_size.y = uniform;
	}
}//namespace mapengine
