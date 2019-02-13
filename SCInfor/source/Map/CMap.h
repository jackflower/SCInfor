//  _________________________________
// | CMap.h - class definition       |
// | Jack Flower October 2012        |
// |_________________________________|
//

#ifndef H_MAP_JACK
#define H_MAP_JACK

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include "../ResourceManager/IResource.h"
#include "MapHeader.h"
#include "Tile/CTile.h"
#include "Tile/CMapTileType.h"
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
		class CTile;
	}
}

using  namespace mapengine::tile;

namespace mapengine
{
	const int	CURRENT_MAP_VERSION		= 1;	//nale¿y pamietaæ, aby w plikach xml
												//z map¹ trzymaæ aktualn¹ wersjê map
												//poniewa¿ jest to doœæ ryzykowny kawa³ek kodu
												//zatem - w xml pisaæ wersjê 1, tak jak
												//tutaj zosta³a zadeklarowana
	const int	TILE_SIZE				= 64;	//rozmiar kalfa
    const float	TILE_EXTRA_PIXELS		= 1.0f;	//ramka w pikselach wokó³ kafli, gdyby atlas mia³ "siatkê"
    const int	MAX_MONSTERS_DEFAULT	= 99999;//maksymalna iloœæ potworów na mapie
												//(du¿o, ale zapobiega przed "idiotyzmem" moduj¹cych
	///
	///Klasa reprezentuje mapê gry - mapa œwiata gry
	///
	class CMap : public IResource
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CMap(void);

		///
		///Konstruktor kopiuj¹cy
		///
		///@param &CMapCopy - obiekt klasy CMap
		///
		CMap(const CMap& CMapCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CMap(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda rozmieszcza na mapie obiekty wczytane z pliku
		///
		///@param load_complete_map - flaga okreœla, czy dane maj¹ byæ uwzglêdniane na mapie
		///
		void RespawnMapObjects(bool load_complete_map);

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &filename - sta³a referencja na std::string
		///
		bool load(const std::string &filename);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Metoda usuwa z wektora wskaŸniki na obiekty klasy CMapTileType i dane pod tymi wskaŸnikami
		///
		void ClearTiles();

		///
		///Metoda usuwa z wektora wskaŸniki na obiekty klasy MapObjectDescriptor i dane pod tymi wskaŸnikami
		///
		void ClearMapObjects();

		//void ClearDoodahs();

		///
		///Metoda zwraca indeks wzorca na podstawie nazwy
		///
		///@param map_object_type_name - nazwa identyfikatora wzorca fabrycznego
		///
		int getMapObjectTypeIndex(const std::string &map_object_type_name);

		///
		///Metoda zwraca na podstawie nazwy indeks kafla w tablicy
		///
		///@param map_tile_type_name - nazwa kafla w tablicy
		///
		int getTileTypeIndex(const std::string &map_tile_type_name);

		///
		///Metoda zwraca nazwê pliku z map¹
		///
		const std::string & getFilename();

		///
		///Metoda zwraca wektor z rozmiarem mapy w kaflach
		///
		sf::Vector2<int> getSize();

		///
		///Metoda zwraca wersjê mapy
		///
		int getVersion();

		///
		///Metoda zwraca flagê, czy na mapie bêdzie generowany wiatr
		///
		const bool getUseWind() const;

		///
		///Metoda ustawia flagê, czy na mapie bêdzie generowany wiatr
		///
		///@param use_wind - flaga, czy na mapie bêdzie generowany wiatr
		///
		void setUseWind(bool use_wind);

		///
		///Metoda zwraca maksymaln¹ iloœæ powtorów ¿yj¹cych na mapie
		///
		const int getMaxLivingMonsters() const;

		///
		///Metoda zapisuje mapê do pliku
		///
		///@param & filename - nazwa pliku - sta³a refrencja do obiektu klasy std::string
		///
		bool save(const std::string & filename);

		///
		///Metoda serializuje obiekt
		///
		///@param &serialized_object - obiekt zserializowany - obiekt klasy std::stringstream
		///
		void serialize(std::stringstream & serialized_object);

	private:

		MapHeader*								m_map_header;				//wskaŸnik na strukturê opisuj¹c¹ konfiguracjê mapy
		std::string								m_map_filename;				//nazwa pliku mapy
		sf::Vector2<int>						m_size;						//rozmiar mapy
		sf::IntRect								m_view_rectangle;			//obszar widoku (mapa w oku kamery)
		std::vector<CTile*>*					p_fields;					//wskaŸnik na wektor wskaŸników do obiektów klasy CTile - kafli
		std::vector<CMapTileType*>				m_map_tile_types;			//wektor wskaŸników na obiekty - opakowanie informacji o kaflu
		std::vector<MapObjectType*>			m_map_object_types;			//wektor wskaŸników na obiekty fabryczne - wzorce dla obiektów mapy
		std::vector<MapObjectDescriptor*>		m_map_object_descriptors;	//wektor wskaŸników na obiekty umieszczone na mapie

		//std::vector<CRegionDescriptor *>		mRegionDescriptors;
		bool									m_use_wind;					//flaga, czy na mapie bêdzie generowany wiatr
		int										m_max_living_monsters;		//maksymalna iloœæ potworów ¿yj¹cych na mapie
		std::string								str_data;					//nazwa dla danych ³adowanych z xml
 	};
} //namespace mapengine
#endif //H_MAP_JACK
