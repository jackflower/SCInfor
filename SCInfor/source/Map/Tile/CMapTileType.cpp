//  _________________________________________
// | CMapTileType.cpp - class implementation |
// | SCI - by Jack Flower April 2013         |
// |_________________________________________|
//

#include "CMapTileType.h"

namespace mapengine
{
	namespace tile
	{
		RTTI_IMPL_NOPARENT(CMapTileType);

		//Konstruktor kopiuj¹cy
		CMapTileType::CMapTileType(void)
		:
			m_code						(""),
			m_image_filename			(""),
			m_number_number_in_atlas	(-1)
		{
		}

		//Konstruktor kopiuj¹cy
		CMapTileType::CMapTileType(const CMapTileType& CMapTileTypeCopy)
		:
			m_code						(CMapTileTypeCopy.m_code),
			m_image_filename			(CMapTileTypeCopy.m_image_filename),
			m_number_number_in_atlas	(CMapTileTypeCopy.m_number_number_in_atlas)
		{
		}

		//Destruktor
		CMapTileType::~CMapTileType(void)
		{
			m_code						= "";
			m_image_filename			= "";
			m_number_number_in_atlas	= 0;
		}

		//Metoda zwraca kod typu kafla u¿ywanego na mapie ³adowanego z pliku xml
		const std::string & CMapTileType::GetCode() const
		{
			return m_code;
		}

		//Metoda ustawia kod typu kafla u¿ywanego na mapie ³adowanego z pliku xml
		void CMapTileType::SetCode(const std::string & code)
		{
			m_code = code;
		}

		//Metoda zwraca nazwê pliku z grafik¹ kafla
		const std::string & CMapTileType::GetImageFileName() const
		{
			return m_image_filename;
		}

		//Metoda ustawia nazwê pliku z grafik¹ kafla
		void CMapTileType::SetImageFileName(const std::string & image_filename)
		{
			m_image_filename = image_filename;
		}

		//Metoda zwraca numer obrazu kafla w atlasie tekstur
		const int CMapTileType::GetImageNumberInAtlas() const
		{
			return m_number_number_in_atlas;
		}

		//Metoda ustawia numer obrazu kafla w atlasie tekstur
		void CMapTileType::SetImageNumberInAtlas(int number_number_in_atlas)
		{
			m_number_number_in_atlas = number_number_in_atlas;
		}
	}//namespace tile
}//namespace mapengine
