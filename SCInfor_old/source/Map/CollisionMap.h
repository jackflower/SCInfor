//  _______________________________________
// | CollisionMap.h - class definition     |
// | Jack Flower July 2013                 |
// |_______________________________________|
//

#ifndef H_COLLISION_JACK
#define H_COLLISION_JACK

#include "Cell.h"
#include <SFML/System/Vector2.hpp>
#include <vector>

///
///Forward declaration
///
namespace mapengine
{
	class DynamicRegion;
}
class CPath;

namespace logic
{
	class Physical;
}

using namespace logic;

namespace mapengine
{
	///
	///Klasa reprezentuje funkcjonalność pozwalającą sprawdzić, czy dany punkt na mapie jest wolny
	///
	class CollisionMap
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CollisionMap();

		///
		///Destruktor
		///
		~CollisionMap();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda inicjuje mapę kolizji
		///
		///@paran size - wektor z rozmiarem mapy - obiekt klasy sf::Vector2i
		///
		void initialize(sf::Vector2i size);
		
		///
		///Metoda aktualizuje wszystkie obiekty znajdujące się na mapie kolizji
		///
		void updateAllPhysicals();

		///
		///Metoda aktualizuje obiekty znajdujące się na mapie kolizji w zależności od kategorii
		///
		///@category - kategoria obiektów, które należy zaktualizować
		///
		void updatePhysicals(int category);

		///
		///Metoda aktualizuje wskazany obiekt klasy Physical
		///
		///@param *physical - wskaźnik na obiekt klasy Physical
		///
		///@param collision - flaga kolizji
		///
		void updatePhysical(Physical *physical, bool collision);
		
		///
		///Metoda zwraca flagę, czy nastąpiła kolizja z jakimkolwiek obiektem z kontenera przechowującego obiekty klasy Cell
		///
		///@param collision - wektor kolizji - stała referencja na obiekt klasy sf::Vector2i
		///
		bool getCollisionByCell(const sf::Vector2i & collision) const;

		///
		///Metoda zwraca flagę, czy nastąpiła kolizja z obiektem opisanym współrzędnymi skrajnych wierzchołków
		///
		///@param leftUp - wektor współrzędnych lewego górnego rogu - stała referencja na obiekt klasy sf::Vector2i
		///
		///@param rightDown - wektor współrzędnych prawego dolnego rogu - stała referencja na obiekt klasy sf::Vector2i
		///
		bool getCollisionByRect(const sf::Vector2i & leftUp, const sf::Vector2i & rightDown) const;

		///
		///Metoda zwraca gęstość obiektów w obszarze klasy Cell
		///
		///@param cell - stała referencja na obiekt klasy sf::Vector2i
		///
		int getDensityByCell(const sf::Vector2i & cell);
	    
		///
		///Metoda zwraca gęstość obiektów opisanych współrzędnymi skrajnych wierzchołków
		///
		///@param leftUp - wektor współrzędnych lewego górnego rogu - stała referencja na obiekt klasy sf::Vector2i
		///
		///@param rightDown - wektor współrzędnych prawego dolnego rogu - stała referencja na obiekt klasy sf::Vector2i
		///
		int getDensityByRect(const sf::Vector2i & leftUp, const sf::Vector2i & rightDown);

		///
		///Metoda dynamicznie aktalizuje regiony mapy
		///
		void updateRegions();
		
		///
		///Metoda dodaje do kontenera węzeł ścieżki
		///
		///@param *path - ścieżka - stały wskaźnik na obiekt klasy CPath
		///
		void addPath(const CPath *path);
		
		///
		///Metoda usuwa z kontenera węzeł ścieżki
		///
		///@param *path - ścieżka - stały wskaźnik na obiekt klasy CPath
		///
		void removePath(const CPath *path);

		///
		///Metoda modyfikuje ściżkę
		///
		///@param *path - ścieżka - stały wskaźnik na obiekt klasy CPath
		///
		///@param delta  - parametr modyfikujący
		///
		void modifyPath(const CPath* path, int delta);
	    
		///
		///Metoda znajduje ścieżkę
		///
		///@param start - wektor pozycji starowej - stała referecja na obiekt klasy sf::Vector2f
		///
		///@param goal - wektor pozycji końcowej - stała referecja na obiekt klasy sf::Vector2f
		///
		///@param physicalSize - rozmiar obiektu - stała referecja na obiekt klasy sf::Vector2f
		///
		///@param **path - wskaźnik na wskaźnik na obiekt klasy CPath
		///
		bool findPath(const sf::Vector2f & start, const sf::Vector2f & goal, 
					  const sf::Vector2f & physicalSize, CPath ** path);
		
		///
		///Metoda zwraca pozycję kafla dla danych współrzędnych globalnych
		///
		///@param point - współrzędne globalne
		///
		sf::Vector2i getCellByCoords(const sf::Vector2f & point);

		///
		///Metoda zwraca współrzędne globalne dla danego kafla
		///
		///@param cell - wektor współrzędnych
		///
		sf::Vector2f getCoordsByCell(const sf::Vector2i & cell);
		
		///
		///Metoda zamienia rozmiar w ilość zajmowanych pol
		///
		///@param size - rozmiar
		///
		sf::Vector2i convertSizeToCells(const sf::Vector2f & size);

		///
		///Metoda zwraca wskaźnik na obiekt klasy DynamicRegion
		///
		///@param cell - współrzędne
		///
		DynamicRegion *getRegionByCell(const sf::Vector2i & cell);

		///
		///Metoda zwraca rozmiar mapy kolizji
		///
		inline sf::Vector2i getSize() { return m_size; }
		
		///
		///Metoda zwraca wektor - ilość komórek (przeliczona na ilość kafli)
		///
		inline sf::Vector2f getCellsPerTile() { return m_cell_per_tile; }

	private:

		sf::Vector2i m_size; //rozmiar mapy kolizji
		sf::Vector2f m_cell_per_tile; //ilość komórek (przeliczona na ilość kafli)
		sf::Vector2f m_single_cell_size; //rozmiar pojedyńczej komórki
		std::vector<Cell> m_cell_list; //kontener przechowujący obiekty klasy Cell
		std::vector<DynamicRegion*> m_region_list; //kontener przechowujący wskaźniki na obiekty klasy CRegion
		int m_enemy_density; //gęstość wrogów na mapie koli
	    
		inline int cellToIndex(const sf::Vector2i & e) const
		{
			return e.y * m_size.x + e.x;
		}

	};
}//namespace mapengine
#endif//H_COLLISION_JACK
