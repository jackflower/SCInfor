//  _______________________________________________
// | CMapPhysicalHeader.cpp - class implementation |
// | Jack Flower October 2012                      |
// |_______________________________________________|
//

#include "CMapPhysicalHeader.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CMapPhysicalHeader);

	//Konstruktor
	CMapPhysicalHeader::CMapPhysicalHeader()
	{
	}

	//Konstruktor kopiuj¹cy
	CMapPhysicalHeader::CMapPhysicalHeader(const CMapPhysicalHeader & CMapPhisicalHeaderCopy)
	{
	}

	//Destruktor
	CMapPhysicalHeader::~CMapPhysicalHeader()
	{
	}

	//Metoda zwraca rozmiar pod³o¿a wyra¿ony w iloœci obiektów na mapie
	const sf::Vector2u & CMapPhysicalHeader::getSizeInMapPhysical() const
	{
		return m_size_in_map_physical;
	}

	//Metoda ustawia rozmiar pod³o¿a wyra¿ony w iloœci obiektów na mapie
	void CMapPhysicalHeader::setSizeInMapPhysical(const sf::Vector2u & size_in_map_physical)
	{
		m_size_in_map_physical = size_in_map_physical;
	}

	//Metoda ustawia rozmiar pod³o¿a wyra¿ony w iloœci obiektów na mapie
	void CMapPhysicalHeader::setSizeInMapPhysical(unsigned width_in_map_physical, unsigned height_in_map_physical)
	{
		m_size_in_map_physical.x = width_in_map_physical;
		m_size_in_map_physical.y = height_in_map_physical;
	}

	//Metoda ustawia rozmiar pod³o¿a wyra¿ony w iloœci obiektów na mapie
	void CMapPhysicalHeader::setSizeInMapPhysical(unsigned uniform)
	{
		m_size_in_map_physical.x = uniform;
		m_size_in_map_physical.y = uniform;
	}

	//Metoda zwraca rozmiar obiektu
	const sf::Vector2u & CMapPhysicalHeader::GetSize() const
	{
		return m_size;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysicalHeader::SetSize(const sf::Vector2u & size)
	{
		m_size = size;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysicalHeader::SetSize(unsigned x, unsigned y)
	{
		m_size.x = x;
		m_size.y = y;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysicalHeader::SetSize(unsigned uniform)
	{
		m_size.x = uniform;
		m_size.y = uniform;
	}
}//namespace mapengine
