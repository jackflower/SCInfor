//  __________________________________________
// | CCollisionMap.h - class definition       |
// | Jack Flower July 2013                    |
// |__________________________________________|
//


#ifndef H_DYNAMIC_REGION_GENERATOR_JACK
#define H_DYNAMIC_REGION_GENERATOR_JACK

#include "CCell.h"
#include "CDynamicRegion.h"
#include <SFML/System/Vector2.hpp>
#include <map>
#include <vector>

namespace mapengine
{
	///
	///Klasa reprezentuje
	///
	class CDynamicRegionsGenerator
	{
		RTTI_DECL;
	
	public:

		///
		///Kostruktor
		///
		///@param &map_size - rozmiar mapy sta³a referencja na obiekt klasy sf::Vector2i
		///
		///@param &region_size - rozmiar regionu sta³a referencja na obiekt klasy sf::Vector2i
		///
		explicit CDynamicRegionsGenerator(const sf::Vector2i & map_size, const sf::Vector2i & region_size);
		
		///
		///Destruktor
		///
		~CDynamicRegionsGenerator();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda generuje regiony
		///
		///@param &cellList - referencja na wektor do kontenera std::vector<CCell>& cellList
		///
		///@param &regionList - referencja na wektor do kontenera std::vector<CDynamicRegion*>& regionList
		///
		void GenerateRegions(std::vector<CCell>& cellList, std::vector<CDynamicRegion*>& regionList);

	private:

		//definicje typów
		typedef std::vector<sf::Vector2i> PointList;	//kontener przechowuje wspó³rzêdne wêz³ów mapy (punkty grafu)
		typedef std::map<int, PointList> OpenList;		//mapa obiektów first/key/-liczba, secound - wespó³rzêdna punktu
		typedef std::multimap<int, int> LinkList;		//zbiór krawêdzi z po³¹czeniami punktów
	    
		///
		///Metoda zjaduje nastêpny punkt startowy
		///
		const sf::Vector2i FindNextStartingPoint() const;

		///
		///Metoda tworzy po³¹czenie pomiêdzy regionami
		///
		///@param region - identyfikator regionu
		///
		///@param *newRegion - wskaŸnik na obiekt klasy CDynamicRegion
		///
		void GenerateLinks(int region, CDynamicRegion* newRegion);
	    
		///
		///Metoda dokonuje konwersji pozycji na region
		///
		///@param &position - pozycja - sta³a referencja na obiekt klasy sf::Vector2i
		///
		int PositionToRegion(const sf::Vector2i& position) const;
		
		///
		///Metoda tworzy obiekt klasy CDynamicRegion - wêze³ grafu
		///
		///@param region - identyfikator
		///
		///@param regionID - identyfikator obiektu klasy CDynamicRegion
		///
		void CreateRegion(int region, int regionID);
		
		///
		///Metoda wype³nia graf wêz³ami pocz¹wszy od zadanego punktu
		///
		///@param - &starting_point - wspó³rzêdne punktu startowego
		///
		void FillRegion(const sf::Vector2i & starting_point);
	    
		///
		///Metoda zwraca wskaŸnik na wêze³ grafu na podstawie podanego identyfikatora
		///
		///@param regionID - identyfikator obiektu klasy CDynamicRegion
		///
		CDynamicRegion* FindRegion(int regionID);

		///
		///Metoda przetwarza punkty wokó³ danego wêz³a
		///
		///@param &source - wspó³rzêdne wêz³a wokó³ którego obliczamy s¹siadów
		///
		///@param &offset - wartoœæ ofsetu dla wspó³rzêdnych
		///
		void ProcessPoint(const sf::Vector2i & source, const sf::Vector2i & offset);

		///
		///Metoda sprawdza, czy dany wêze³ powinien byæ odwiedzany
		///
		///@param &position - wektor pozycji - sta³a referencja na obiekt klasy sf::Vector2i
		///
		bool ShouldBeVisited(const sf::Vector2i& position) const;

		static int mLastRegionID;
	    
		sf::Vector2i					m_map_size;				//wektor przechowuj¹cy rozmiar mapy
		sf::Vector2i					m_region_size;			//wektor przechowuj¹cy rozmiar regionu
		sf::Vector2i					m_last_point_checked;	//wektor przechowujacy wspó³rzêdne ostatnio sprawdzonego punktu
		OpenList						m_open_List;			//lista otwarta
		LinkList						m_link_list;			//liczba krawêdzi
		std::vector<CCell>*				p_cell_list;			//wskaŸnik na kontener z obiektami klasy CCell
		std::vector<CDynamicRegion*>*	p_region_list;			//wskaŸnik na kontener z obiektami klasy CDynamicRegion
	};
}//namespace mapengine
#endif//H_DYNAMIC_REGION_GENERATOR_JACK
