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
	const int	CURRENT_MAP_VERSION		= 1;	//nale�y pamieta�, aby w plikach xml
												//z map� trzyma� aktualn� wersj� map
												//poniewa� jest to do�� ryzykowny kawa�ek kodu
												//zatem - w xml pisa� wersj� 1, tak jak
												//tutaj zosta�a zadeklarowana
	const int	TILE_SIZE				= 64;	//rozmiar kalfa
    const float	TILE_EXTRA_PIXELS		= 1.0f;	//ramka w pikselach wok� kafli, gdyby atlas mia� "siatk�"
    const int	MAX_MONSTERS_DEFAULT	= 99999;//maksymalna ilo�� potwor�w na mapie
												//(du�o, ale zapobiega przed "idiotyzmem" moduj�cych
	///
	///Klasa reprezentuje map� gry - mapa �wiata gry
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
		///Konstruktor kopiuj�cy
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
		///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda rozmieszcza na mapie obiekty wczytane z pliku
		///
		///@param load_complete_map - flaga okre�la, czy dane maj� by� uwzgl�dniane na mapie
		///
		void RespawnMapObjects(bool load_complete_map);

		///
		///Metoda �aduj�ca dane
		///
		///@param &filename - sta�a referencja na std::string
		///
		bool load(const std::string &filename);

		///
		///Wirtualna metoda �aduj�ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Metoda usuwa z wektora wska�niki na obiekty klasy CMapTileType i dane pod tymi wska�nikami
		///
		void ClearTiles();

		///
		///Metoda usuwa z wektora wska�niki na obiekty klasy MapObjectDescriptor i dane pod tymi wska�nikami
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
		///Metoda zwraca nazw� pliku z map�
		///
		const std::string & getFilename();

		///
		///Metoda zwraca wektor z rozmiarem mapy w kaflach
		///
		sf::Vector2<int> getSize();

		///
		///Metoda zwraca wersj� mapy
		///
		int getVersion();

		///
		///Metoda zwraca flag�, czy na mapie b�dzie generowany wiatr
		///
		const bool getUseWind() const;

		///
		///Metoda ustawia flag�, czy na mapie b�dzie generowany wiatr
		///
		///@param use_wind - flaga, czy na mapie b�dzie generowany wiatr
		///
		void setUseWind(bool use_wind);

		///
		///Metoda zwraca maksymaln� ilo�� powtor�w �yj�cych na mapie
		///
		const int getMaxLivingMonsters() const;

		///
		///Metoda zapisuje map� do pliku
		///
		///@param & filename - nazwa pliku - sta�a refrencja do obiektu klasy std::string
		///
		bool save(const std::string & filename);

		///
		///Metoda serializuje obiekt
		///
		///@param &serialized_object - obiekt zserializowany - obiekt klasy std::stringstream
		///
		void serialize(std::stringstream & serialized_object);

	private:

		MapHeader*								m_map_header;				//wska�nik na struktur� opisuj�c� konfiguracj� mapy
		std::string								m_map_filename;				//nazwa pliku mapy
		sf::Vector2<int>						m_size;						//rozmiar mapy
		sf::IntRect								m_view_rectangle;			//obszar widoku (mapa w oku kamery)
		std::vector<CTile*>*					p_fields;					//wska�nik na wektor wska�nik�w do obiekt�w klasy CTile - kafli
		std::vector<CMapTileType*>				m_map_tile_types;			//wektor wska�nik�w na obiekty - opakowanie informacji o kaflu
		std::vector<MapObjectType*>			m_map_object_types;			//wektor wska�nik�w na obiekty fabryczne - wzorce dla obiekt�w mapy
		std::vector<MapObjectDescriptor*>		m_map_object_descriptors;	//wektor wska�nik�w na obiekty umieszczone na mapie

		//std::vector<CRegionDescriptor *>		mRegionDescriptors;
		bool									m_use_wind;					//flaga, czy na mapie b�dzie generowany wiatr
		int										m_max_living_monsters;		//maksymalna ilo�� potwor�w �yj�cych na mapie
		std::string								str_data;					//nazwa dla danych �adowanych z xml
 	};
} //namespace mapengine
#endif //H_MAP_JACK
