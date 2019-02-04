//  ________________________________________
// | CCollisionMap.h - class definition     |
// | Jack Flower July 2013                  |
// |________________________________________|
//

#ifndef H_COLLISION_JACK
#define H_COLLISION_JACK

#include "CCell.h"
#include <SFML/System/Vector2.hpp>
#include <vector>

///
///Forward declaration
///
namespace mapengine
{
	class CDynamicRegion;
}
class CPath;

namespace logic
{
	class CPhysical;
}

using namespace logic;

namespace mapengine
{
	///
	///Klasa reprezentuje funkcjonalno�� pozwalaj�c� sprawdzi�, czy dany punkt na mapie jest wolny
	///
	class CCollisionMap
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CCollisionMap();

		///
		///Destruktor
		///
		~CCollisionMap();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda inicjuje map� kolizji
		///
		///@paran size - wektor z rozmiarem mapy - obiekt klasy sf::Vector2i
		///
		void Initialize(sf::Vector2i size);
		
		///
		///Metoda aktualizuje wszystkie obiekty znajduj�ce si� na mapie kolizji
		///
		void UpdateAllPhysicals();

		///
		///Metoda aktualizuje obiekty znajduj�ce si� na mapie kolizji w zale�no�ci od kategorii
		///
		///@category - kategoria obiekt�w, kt�re nale�y zaktualizowa�
		///
		void UpdatePhysicals(int category);

		///
		///Metoda aktualizuje wskazany obiekt klasy CPhysical
		///
		///@param *physical - wska�nik na obiekt klasy CPhysical
		///
		///@param collision - flaga kolizji
		///
		void UpdatePhysical(CPhysical *physical, bool collision);
		
		///
		///Metoda zwraca flag�, czy nast�pi�a kolizja z jakimkolwiek obiektem z kontenera przechowuj�cego obiekty klasy CCell
		///
		///@param &collision - wektor kolizji - sta�a referencja na obiekt klasy sf::Vector2i
		///
		bool GetCollisionByCell(const sf::Vector2i& collision) const;

		///
		///Metoda zwraca flag�, czy nast�pi�a kolizja z obiektem opisanym wsp�rz�dnymi skrajnych wierzcho�k�w
		///
		///@param &leftUp - wektor wsp�rz�dnych lewego g�rnego rogu - sta�a referencja na obiekt klasy sf::Vector2i
		///
		///@param &rightDown - wektor wsp�rz�dnych prawego dolnego rogu - sta�a referencja na obiekt klasy sf::Vector2i
		///
		bool GetCollisionByRect(const sf::Vector2i& leftUp, const sf::Vector2i& rightDown) const;

		///
		///Metoda zwraca g�sto�� obiekt�w w obszarze klasy CCell
		///
		///@param &cell - sta�a referencja na obiekt klasy sf::Vector2i
		///
		int GetDensityByCell(const sf::Vector2i& cell);
	    
		///
		///Metoda zwraca g�sto�� obiekt�w opisanych wsp�rz�dnymi skrajnych wierzcho�k�w
		///
		///@param &leftUp - wektor wsp�rz�dnych lewego g�rnego rogu - sta�a referencja na obiekt klasy sf::Vector2i
		///
		///@param &rightDown - wektor wsp�rz�dnych prawego dolnego rogu - sta�a referencja na obiekt klasy sf::Vector2i
		///
		int GetDensityByRect(const sf::Vector2i& leftUp, const sf::Vector2i& rightDown);

		///
		///Metoda dynamicznie aktalizuje regiony mapy
		///
		void UpdateRegions();
		
		///
		///Metoda dodaje do kontenera w�ze� �cie�ki
		///
		///@param *path - �cie�ka - sta�y wska�nik na obiekt klasy CPath
		///
		void AddPath(const CPath* path);
		
		///
		///Metoda usuwa z kontenera w�ze� �cie�ki
		///
		///@param *path - �cie�ka - sta�y wska�nik na obiekt klasy CPath
		///
		void RemovePath(const CPath * path);

		///
		///Metoda modyfikuje �ci�k�
		///
		///@param *path - �cie�ka - sta�y wska�nik na obiekt klasy CPath
		///
		///@param delta  - parametr modyfikuj�cy
		///
		void ModifyPath(const CPath* path, int delta);
	    
		///
		///Metoda znajduje �cie�k�
		///
		///@param &start - wektor pozycji starowej - sta�a referecja na obiekt klasy sf::Vector2f
		///
		///@param &goal - wektor pozycji ko�cowej - sta�a referecja na obiekt klasy sf::Vector2f
		///
		///@param &physicalSize - rozmiar obiektu - sta�a referecja na obiekt klasy sf::Vector2f
		///
		///@param **path - wska�nik na wska�nik na obiekt klasy CPath
		///
		bool FindPath(const sf::Vector2f & start, const sf::Vector2f & goal, 
					  const sf::Vector2f & physicalSize, CPath ** path);
		
		///
		///Metoda zwraca pozycj� kafla dla danych wsp�rz�dnych globalnych
		///
		///@param &point - wsp�rz�dne globalne
		///
		sf::Vector2i GetCellByCoords(const sf::Vector2f& point);

		///
		///Metoda zwraca wsp�rz�dne globalne dla danego kafla
		///
		///@param &cell - wektor wsp�rz�dnych
		///
		sf::Vector2f GetCoordsByCell(const sf::Vector2i& cell);
		
		///
		///Metoda zamienia rozmiar w ilo�� zajmowanych pol
		///
		///@param &size - rozmiar
		///
		sf::Vector2i ConvertSizeToCells(const sf::Vector2f& size);

		///
		///Metoda zwraca wska�nik na obiekt klasy CDynamicRegion
		///
		///@param &cell - wsp�rz�dne
		///
		CDynamicRegion *GetRegionByCell(const sf::Vector2i & cell);

		///
		///Metoda zwraca rozmiar mapy kolizji
		///
		inline sf::Vector2i GetSize() { return m_size; }
		
		///
		///Metoda zwraca wektor - ilo�� kom�rek (przeliczona na ilo�� kafli)
		///
		inline sf::Vector2f GetCellsPerTile() { return m_cell_per_tile; }

	private:

		sf::Vector2i					m_size;				//rozmiar mapy kolizji
		sf::Vector2f					m_cell_per_tile;	//ilo�� kom�rek (przeliczona na ilo�� kafli)
		sf::Vector2f					m_single_cell_size;	//rozmiar pojedy�czej kom�rki
		std::vector<CCell>				m_cell_list;		//kontener przechowuj�cy obiekty klasy CCell
		std::vector<CDynamicRegion*>	m_region_list;		//kontener przechowuj�cy wska�niki na obiekty klasy CRegion
		int								m_enemy_density;	//g�sto�� wrog�w na mapie koli
	    
		inline int CellToIndex(const sf::Vector2i & e) const   { return e.y * m_size.x + e.x; }

	};
}//namespace mapengine
#endif//H_COLLISION_JACK
