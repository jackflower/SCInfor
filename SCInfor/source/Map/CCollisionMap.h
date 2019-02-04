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
	///Klasa reprezentuje funkcjonalnoœæ pozwalaj¹c¹ sprawdziæ, czy dany punkt na mapie jest wolny
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
		///Metoda inicjuje mapê kolizji
		///
		///@paran size - wektor z rozmiarem mapy - obiekt klasy sf::Vector2i
		///
		void Initialize(sf::Vector2i size);
		
		///
		///Metoda aktualizuje wszystkie obiekty znajduj¹ce siê na mapie kolizji
		///
		void UpdateAllPhysicals();

		///
		///Metoda aktualizuje obiekty znajduj¹ce siê na mapie kolizji w zale¿noœci od kategorii
		///
		///@category - kategoria obiektów, które nale¿y zaktualizowaæ
		///
		void UpdatePhysicals(int category);

		///
		///Metoda aktualizuje wskazany obiekt klasy CPhysical
		///
		///@param *physical - wskaŸnik na obiekt klasy CPhysical
		///
		///@param collision - flaga kolizji
		///
		void UpdatePhysical(CPhysical *physical, bool collision);
		
		///
		///Metoda zwraca flagê, czy nast¹pi³a kolizja z jakimkolwiek obiektem z kontenera przechowuj¹cego obiekty klasy CCell
		///
		///@param &collision - wektor kolizji - sta³a referencja na obiekt klasy sf::Vector2i
		///
		bool GetCollisionByCell(const sf::Vector2i& collision) const;

		///
		///Metoda zwraca flagê, czy nast¹pi³a kolizja z obiektem opisanym wspó³rzêdnymi skrajnych wierzcho³ków
		///
		///@param &leftUp - wektor wspó³rzêdnych lewego górnego rogu - sta³a referencja na obiekt klasy sf::Vector2i
		///
		///@param &rightDown - wektor wspó³rzêdnych prawego dolnego rogu - sta³a referencja na obiekt klasy sf::Vector2i
		///
		bool GetCollisionByRect(const sf::Vector2i& leftUp, const sf::Vector2i& rightDown) const;

		///
		///Metoda zwraca gêstoœæ obiektów w obszarze klasy CCell
		///
		///@param &cell - sta³a referencja na obiekt klasy sf::Vector2i
		///
		int GetDensityByCell(const sf::Vector2i& cell);
	    
		///
		///Metoda zwraca gêstoœæ obiektów opisanych wspó³rzêdnymi skrajnych wierzcho³ków
		///
		///@param &leftUp - wektor wspó³rzêdnych lewego górnego rogu - sta³a referencja na obiekt klasy sf::Vector2i
		///
		///@param &rightDown - wektor wspó³rzêdnych prawego dolnego rogu - sta³a referencja na obiekt klasy sf::Vector2i
		///
		int GetDensityByRect(const sf::Vector2i& leftUp, const sf::Vector2i& rightDown);

		///
		///Metoda dynamicznie aktalizuje regiony mapy
		///
		void UpdateRegions();
		
		///
		///Metoda dodaje do kontenera wêze³ œcie¿ki
		///
		///@param *path - œcie¿ka - sta³y wskaŸnik na obiekt klasy CPath
		///
		void AddPath(const CPath* path);
		
		///
		///Metoda usuwa z kontenera wêze³ œcie¿ki
		///
		///@param *path - œcie¿ka - sta³y wskaŸnik na obiekt klasy CPath
		///
		void RemovePath(const CPath * path);

		///
		///Metoda modyfikuje œci¿kê
		///
		///@param *path - œcie¿ka - sta³y wskaŸnik na obiekt klasy CPath
		///
		///@param delta  - parametr modyfikuj¹cy
		///
		void ModifyPath(const CPath* path, int delta);
	    
		///
		///Metoda znajduje œcie¿kê
		///
		///@param &start - wektor pozycji starowej - sta³a referecja na obiekt klasy sf::Vector2f
		///
		///@param &goal - wektor pozycji koñcowej - sta³a referecja na obiekt klasy sf::Vector2f
		///
		///@param &physicalSize - rozmiar obiektu - sta³a referecja na obiekt klasy sf::Vector2f
		///
		///@param **path - wskaŸnik na wskaŸnik na obiekt klasy CPath
		///
		bool FindPath(const sf::Vector2f & start, const sf::Vector2f & goal, 
					  const sf::Vector2f & physicalSize, CPath ** path);
		
		///
		///Metoda zwraca pozycjê kafla dla danych wspó³rzêdnych globalnych
		///
		///@param &point - wspó³rzêdne globalne
		///
		sf::Vector2i GetCellByCoords(const sf::Vector2f& point);

		///
		///Metoda zwraca wspó³rzêdne globalne dla danego kafla
		///
		///@param &cell - wektor wspó³rzêdnych
		///
		sf::Vector2f GetCoordsByCell(const sf::Vector2i& cell);
		
		///
		///Metoda zamienia rozmiar w iloœæ zajmowanych pol
		///
		///@param &size - rozmiar
		///
		sf::Vector2i ConvertSizeToCells(const sf::Vector2f& size);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDynamicRegion
		///
		///@param &cell - wspó³rzêdne
		///
		CDynamicRegion *GetRegionByCell(const sf::Vector2i & cell);

		///
		///Metoda zwraca rozmiar mapy kolizji
		///
		inline sf::Vector2i GetSize() { return m_size; }
		
		///
		///Metoda zwraca wektor - iloœæ komórek (przeliczona na iloœæ kafli)
		///
		inline sf::Vector2f GetCellsPerTile() { return m_cell_per_tile; }

	private:

		sf::Vector2i					m_size;				//rozmiar mapy kolizji
		sf::Vector2f					m_cell_per_tile;	//iloœæ komórek (przeliczona na iloœæ kafli)
		sf::Vector2f					m_single_cell_size;	//rozmiar pojedyñczej komórki
		std::vector<CCell>				m_cell_list;		//kontener przechowuj¹cy obiekty klasy CCell
		std::vector<CDynamicRegion*>	m_region_list;		//kontener przechowuj¹cy wskaŸniki na obiekty klasy CRegion
		int								m_enemy_density;	//gêstoœæ wrogów na mapie koli
	    
		inline int CellToIndex(const sf::Vector2i & e) const   { return e.y * m_size.x + e.x; }

	};
}//namespace mapengine
#endif//H_COLLISION_JACK
