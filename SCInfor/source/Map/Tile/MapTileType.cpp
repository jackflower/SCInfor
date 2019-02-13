//  ________________________________________
// | MapTileType.cpp - class implementation |
// | SCI - by Jack Flower April 2013        |
// |________________________________________|
//

#include "MapTileType.h"

namespace mapengine
{
	namespace tile
	{
		RTTI_IMPL_NOPARENT(MapTileType);

		//Konstruktor kopiujący
		MapTileType::MapTileType()
		:
			m_code(""),
			m_image_filename(""),
			m_number_number_in_atlas(-1)
		{
		}

		//Konstruktor kopiujący
		MapTileType::MapTileType(const MapTileType & MapTileTypeCopy)
		:
			m_code(MapTileTypeCopy.m_code),
			m_image_filename(MapTileTypeCopy.m_image_filename),
			m_number_number_in_atlas(MapTileTypeCopy.m_number_number_in_atlas)
		{
		}

		//Destruktor
		MapTileType::~MapTileType(void)
		{
			m_code = "";
			m_image_filename = "";
			m_number_number_in_atlas = 0;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string MapTileType::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca kod typu kafla używanego na mapie ładowanego z pliku xml
		const std::string & MapTileType::getCode() const
		{
			return m_code;
		}

		//Metoda ustawia kod typu kafla używanego na mapie ładowanego z pliku xml
		void MapTileType::setCode(const std::string & code)
		{
			m_code = code;
		}

		//Metoda zwraca nazwę pliku z grafiką kafla
		const std::string & MapTileType::getImageFileName() const
		{
			return m_image_filename;
		}

		//Metoda ustawia nazwę pliku z grafiką kafla
		void MapTileType::setImageFileName(const std::string & image_filename)
		{
			m_image_filename = image_filename;
		}

		//Metoda zwraca numer obrazu kafla w atlasie tekstur
		const int MapTileType::getImageNumberInAtlas() const
		{
			return m_number_number_in_atlas;
		}

		//Metoda ustawia numer obrazu kafla w atlasie tekstur
		void MapTileType::setImageNumberInAtlas(int number_number_in_atlas)
		{
			m_number_number_in_atlas = number_number_in_atlas;
		}
	}//namespace tile
}//namespace mapengine
