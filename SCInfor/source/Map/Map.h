//  ________________________________
// | Map.h - class definition       |
// | Jack Flower October 2012       |
// |________________________________|
//

#ifndef H_MAP_JACK
#define H_MAP_JACK

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include "../ResourceManager/Resource.h"
#include "MapHeader.h"
#include "Tile/Tile.h"
#include "Tile/MapTileType.h"
#include "MapPhysicalObject/MapObjectType.h"
#include "MapPhysicalObject/MapObjectDescriptor.h"

///
///Forward declaration
///
namespace mapengine
{
	class MapObjectDescriptor;
	class MapPhysicalDescriptor;
	namespace tile
	{
		class Tile;
	}
}

using  namespace mapengine::tile;

namespace mapengine
{
	const int	CURRENT_MAP_VERSION		= 1;	//należy pamietać, aby w plikach xml
												//z mapą trzymać aktualną wersję map
												//ponieważ jest to dość ryzykowny kawałek kodu
												//zatem - w xml pisać wersję 1, tak jak
												//tutaj została zadeklarowana
	const int	TILE_SIZE				= 64;	//rozmiar kalfa
    const float	TILE_EXTRA_PIXELS		= 1.0f;	//ramka w pikselach wokół kafli, gdyby atlas miał "siatkę"
    const int	MAX_MONSTERS_DEFAULT	= 99999;//maksymalna ilość potworów na mapie
												//(dużo, ale zapobiega przed "idiotyzmem" modujących
	///
	///Klasa reprezentuje mapę gry - mapa świata gry
	///
	class Map : public Resource
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		Map();

		///
		///Konstruktor kopiujący
		///
		///@param MapCopy - obiekt klasy Map
		///
		Map(const Map & MapCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~Map();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda rozmieszcza na mapie obiekty wczytane z pliku
		///
		///@param load_complete_map - flaga określa, czy dane mają być uwzględniane na mapie
		///
		void respawnMapObjects(bool load_complete_map);

		///
		///Metoda ładująca dane
		///
		///@param filename - stała referencja na std::string
		///
		bool load(const std::string & filename);

		///
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

		///
		///Metoda usuwa z wektora wskaźniki na obiekty klasy MapTileType i dane pod tymi wskaźnikami
		///
		void ClearTiles();

		///
		///Metoda usuwa z wektora wskaźniki na obiekty klasy MapObjectDescriptor i dane pod tymi wskaźnikami
		///
		void ClearMapObjects();

		//void ClearDoodahs();

		///
		///Metoda zwraca indeks wzorca na podstawie nazwy
		///
		///@param map_object_type_name - nazwa identyfikatora wzorca fabrycznego
		///
		int getMapObjectTypeIndex(const std::string & map_object_type_name);

		///
		///Metoda zwraca na podstawie nazwy indeks kafla w tablicy
		///
		///@param map_tile_type_name - nazwa kafla w tablicy
		///
		int getTileTypeIndex(const std::string & map_tile_type_name);

		///
		///Metoda zwraca nazwę pliku z mapą
		///
		const std::string & getFilename();

		///
		///Metoda zwraca wektor z rozmiarem mapy w kaflach
		///
		sf::Vector2<int> getSize();

		///
		///Metoda zwraca wersję mapy
		///
		int getVersion();

		///
		///Metoda zwraca flagę, czy na mapie będzie generowany wiatr
		///
		const bool getUseWind() const;

		///
		///Metoda ustawia flagę, czy na mapie będzie generowany wiatr
		///
		///@param use_wind - flaga, czy na mapie będzie generowany wiatr
		///
		void setUseWind(bool use_wind);

		///
		///Metoda zwraca maksymalną ilość powtorów żyjących na mapie
		///
		const int getMaxLivingMonsters() const;

		///
		///Metoda zapisuje mapę do pliku
		///
		///@param filename - nazwa pliku - stała refrencja do obiektu klasy std::string
		///
		bool save(const std::string & filename);

		///
		///Metoda serializuje obiekt
		///
		///@param serialized_object - obiekt zserializowany - obiekt klasy std::stringstream
		///
		void serialize(std::stringstream & serialized_object);

	private:

		MapHeader *m_map_header; //wskaźnik na strukturę opisującą konfigurację mapy
		std::string m_map_filename; //nazwa pliku mapy
		sf::Vector2<int> m_size; //rozmiar mapy
		sf::IntRect m_view_rectangle; //obszar widoku (mapa w oku kamery)
		std::vector<Tile*> *p_fields; //wskaźnik na wektor wskaźników do obiektów klasy Tile - kafli
		std::vector<MapTileType*> m_map_tile_types; //wektor wskaźników na obiekty - opakowanie informacji o kaflu
		std::vector<MapObjectType*> m_map_object_types; //wektor wskaźników na obiekty fabryczne - wzorce dla obiektów mapy
		std::vector<MapObjectDescriptor*> m_map_object_descriptors;	//wektor wskaźników na obiekty umieszczone na mapie

		//std::vector<CRegionDescriptor *> mRegionDescriptors;
		bool m_use_wind; //flaga, czy na mapie będzie generowany wiatr
		int m_max_living_monsters; //maksymalna ilość potworów żyjących na mapie
		std::string str_data; //nazwa dla danych ładowanych z xml
 	};
} //namespace mapengine
#endif //H_MAP_JACK
