//  _________________________________________
// | CMapTileType.h - class definition       |
// | SCI - by Jack Flower April 2013         |
// |_________________________________________|
//

#ifndef H_MAP_TILE_TYPE_JACK
#define H_MAP_TILE_TYPE_JACK

#include "../../RTTI/RTTI.h"

namespace mapengine
{
	namespace tile
	{
		///
		///Klasa reprezentuje opakowanie informacji o kaflu
		///
		class CMapTileType
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			CMapTileType(void);

			///
			///Konstruktor kopiuj¹cy
			///
			///@param &CMapTileTypeCopy - obiekt klasy CMapTileType
			///
			CMapTileType(const CMapTileType& CMapTileTypeCopy);

			///
			///Destruktor
			///
			~CMapTileType(void);

			//metody pomocnicze - hermetyzacja

			///
			///Metoda zwraca kod typu kafla u¿ywanego na mapie ³adowanego z pliku xml
			///
			const std::string & GetCode() const;

			///
			///Metoda ustawia kod typu kafla u¿ywanego na mapie ³adowanego z pliku xml
			///
			///@param & code - nazwa kodu - sta³a referencja na obiekt klasy std::string
			///
			void SetCode(const std::string & code);

			///
			///Metoda zwraca nazwê pliku z grafik¹ kafla
			///
			const std::string & GetImageFileName() const;

			///
			///Metoda ustawia nazwê pliku z grafik¹ kafla
			///
			///@param & image_filename - nazwa pliku - sta³a referencja na obiekt klasy std::string
			///
			void SetImageFileName(const std::string & image_filename);

			///
			///Metoda zwraca numer obrazu kafla w atlasie tekstur
			///
			const int GetImageNumberInAtlas() const;

			///
			///Metoda ustawia numer obrazu kafla w atlasie tekstur
			///
			///@param number_number_in_atlas - numer obrazu kafla w atlasie tekstur
			///
			void SetImageNumberInAtlas(int number_number_in_atlas);

		private:

			std::string		m_code;						//nazwa kodu dla typu kafla u¿ywana w pliku xml
			std::string		m_image_filename;			//nazwa pliku obrazu kafla
			int				m_number_number_in_atlas;	//indeks w atlasie lub -1, czyli ca³y obraz
		};
	}//namespace tile
}//namespace mapengine
#endif //H_MAP_TILE_TYPE_JACK
