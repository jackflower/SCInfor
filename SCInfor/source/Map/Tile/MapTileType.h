//  ________________________________________
// | MapTileType.h - class definition       |
// | SCI - by Jack Flower April 2013        |
// |________________________________________|
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
		class MapTileType
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			MapTileType();

			///
			///Konstruktor kopiujący
			///
			///@param MapTileTypeCopy - obiekt klasy MapTileType
			///
			MapTileType(const MapTileType & MapTileTypeCopy);

			///
			///Destruktor
			///
			~MapTileType(void);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca kod typu kafla używanego na mapie ładowanego z pliku xml
			///
			const std::string & getCode() const;

			///
			///Metoda ustawia kod typu kafla używanego na mapie ładowanego z pliku xml
			///
			///@param code - nazwa kodu - stała referencja na obiekt klasy std::string
			///
			void setCode(const std::string & code);

			///
			///Metoda zwraca nazwę pliku z grafiką kafla
			///
			const std::string & getImageFileName() const;

			///
			///Metoda ustawia nazwę pliku z grafiką kafla
			///
			///@param image_filename - nazwa pliku - stała referencja na obiekt klasy std::string
			///
			void setImageFileName(const std::string & image_filename);

			///
			///Metoda zwraca numer obrazu kafla w atlasie tekstur
			///
			const int getImageNumberInAtlas() const;

			///
			///Metoda ustawia numer obrazu kafla w atlasie tekstur
			///
			///@param number_number_in_atlas - numer obrazu kafla w atlasie tekstur
			///
			void setImageNumberInAtlas(int number_number_in_atlas);

		private:

			std::string m_code; //nazwa kodu dla typu kafla używana w pliku xml
			std::string m_image_filename; //nazwa pliku obrazu kafla
			int m_number_number_in_atlas; //indeks w atlasie lub -1, czyli cały obraz
		};
	}//namespace tile
}//namespace mapengine
#endif //H_MAP_TILE_TYPE_JACK
