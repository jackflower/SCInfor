//  ______________________________________________
// | MapPhysicalHeader.h - class definition       |
// | Jack Flower October 2012                     |
// |______________________________________________|
//

#ifndef H_MAP_PHYSICAL_HEADER_JACK
#define H_MAP_PHYSICAL_HEADER_JACK

#include <SFML/System/Vector2.hpp>
#include "../RTTI/RTTI.h"

namespace mapengine
{

	///
	///Klasa reprezentuje opakowanie informacji o całym podłożu mapy
	///
	class MapPhysicalHeader
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		MapPhysicalHeader();

		///
		///Konstruktor kopiujący
		///
		///@param MapPhisicalHeaderCopy - stała referencja na obiekt klasy MapPhysicalHeader
		///
		MapPhysicalHeader(const MapPhysicalHeader & MapPhisicalHeaderCopy);

		///
		///Destruktor
		///
		~MapPhysicalHeader();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca rozmiar podłoża wyrażony w ilości obiektów na mapie
		///
		const sf::Vector2u & getSizeInMapPhysical() const;

		///
		///Metoda ustawia rozmiar podłoża wyrażony w ilości obiektów na mapie
		///
		///@para size_in_map_physical - rozmiar - stała referencja na obiekto klasy sf::Vector2u
		///
		void setSizeInMapPhysical(const sf::Vector2u & size_in_map_physical);

		///
		///Metoda ustawia rozmiar podłoża wyrażony w ilości obiektów na mapie
		///
		///@param width_in_map_physical - ilość obiektach podłoża w poziomie
		///
		///@param height_in_map_physical - ilość obiektach podłoża w pionie
		///
		void setSizeInMapPhysical(unsigned width_in_map_physical, unsigned height_in_map_physical);

		///
		///Metoda ustawia rozmiar podłoża wyrażony w ilości obiektów na mapie
		///
		///@uniform - ilość obiektów podłoża taka sama w pionie i w poziomie 
		///
		void setSizeInMapPhysical(unsigned uniform);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2u & getSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@para size - rozmiar - stała referencja na obiekto klasy sf::Vector2u
		///
		void setSize(const sf::Vector2u & size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param x - składowa x
		///
		///@param y - składowa y
		///
		void setSize(unsigned x, unsigned y);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@uniform - rozmiar
		///
		void setSize(unsigned uniform);

	private:

		sf::Vector2u m_size_in_map_physical; //rozmiar mapy z obiektami podłoża wyrażona w kaflach
		sf::Vector2u m_size; //rozmiar obiektu podłoża

	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_HEADER_JACK