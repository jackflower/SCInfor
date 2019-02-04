//  _______________________________________________
// | CMapPhysicalHeader.h - class definition       |
// | Jack Flower October 2012                      |
// |_______________________________________________|
//

#ifndef H_MAP_PHYSICAL_HEADER_JACK
#define H_MAP_PHYSICAL_HEADER_JACK

#include <SFML/System/Vector2.hpp>
#include "../RTTI/RTTI.h"

namespace mapengine
{

	///
	///Klasa reprezentuje opakowanie informacji o ca³ym pod³o¿u mapy
	///
	class CMapPhysicalHeader
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CMapPhysicalHeader();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param & CMapPhisicalHeaderCopy - sta³a referencja na obiekt klasy CMapPhysicalHeader
		///
		CMapPhysicalHeader(const CMapPhysicalHeader & CMapPhisicalHeaderCopy);

		///
		///Destruktor
		///
		~CMapPhysicalHeader();

		///
		///Metoda zwraca rozmiar pod³o¿a wyra¿ony w iloœci obiektów na mapie
		///
		const sf::Vector2u & getSizeInMapPhysical() const;

		///
		///Metoda ustawia rozmiar pod³o¿a wyra¿ony w iloœci obiektów na mapie
		///
		///@para size_in_map_physical - rozmiar - sta³a referencja na obiekto klasy sf::Vector2u
		///
		void setSizeInMapPhysical(const sf::Vector2u & size_in_map_physical);

		///
		///Metoda ustawia rozmiar pod³o¿a wyra¿ony w iloœci obiektów na mapie
		///
		///@param width_in_map_physical - iloœæ obiektach pod³o¿a w poziomie
		///
		///@param height_in_map_physical - iloœæ obiektach pod³o¿a w pionie
		///
		void setSizeInMapPhysical(unsigned width_in_map_physical, unsigned height_in_map_physical);

		///
		///Metoda ustawia rozmiar pod³o¿a wyra¿ony w iloœci obiektów na mapie
		///
		///@uniform - iloœæ obiektów pod³o¿a taka sama w pionie i w poziomie 
		///
		void setSizeInMapPhysical(unsigned uniform);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2u & GetSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@para size - rozmiar - sta³a referencja na obiekto klasy sf::Vector2u
		///
		void SetSize(const sf::Vector2u & size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param x - sk³adowa x
		///
		///@param y - sk³adowa y
		///
		void SetSize(unsigned x, unsigned y);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@uniform - rozmiar
		///
		void SetSize(unsigned uniform);

	private:

		sf::Vector2u	m_size_in_map_physical;		//rozmiar mapy z obiektami pod³o¿a wyra¿ona
		sf::Vector2u	m_size;						//rozmiar obiektu pod³o¿a

	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_HEADER_JACK