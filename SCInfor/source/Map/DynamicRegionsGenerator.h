//  _________________________________________
// | CollisionMap.h - class definition       |
// | Jack Flower July 2013                   |
// |_________________________________________|
//


#ifndef H_DYNAMIC_REGION_GENERATOR_JACK
#define H_DYNAMIC_REGION_GENERATOR_JACK

#include "Cell.h"
#include "DynamicRegion.h"
#include <SFML/System/Vector2.hpp>
#include <map>
#include <vector>

namespace mapengine
{
	///
	///Klasa reprezentuje
	///
	class DynamicRegionsGenerator
	{
		RTTI_DECL;
	
	public:

		///
		///Kostruktor
		///
		///@param map_size - rozmiar mapy stała referencja na obiekt klasy sf::Vector2i
		///
		///@param region_size - rozmiar regionu stała referencja na obiekt klasy sf::Vector2i
		///
		explicit DynamicRegionsGenerator(const sf::Vector2i & map_size, const sf::Vector2i & region_size);
		
		///
		///Destruktor
		///
		~DynamicRegionsGenerator();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda generuje regiony
		///
		///@param cellList - referencja na wektor do kontenera z obiekta,i klasy Cell
		///
		///@param regionList - referencja na wektor do kontenera ze wskaźnikami na obiekty klasy DynamicRegion
		///
		void GenerateRegions(std::vector<Cell> & cellList, std::vector<DynamicRegion*> & regionList);

	private:

		//definicje typów
		typedef std::vector<sf::Vector2i> PointList; //kontener przechowuje współrzędne węzłów mapy (punkty grafu)
		typedef std::map<int, PointList> OpenList; //mapa obiektów first/key/-liczba, secound - wespółrzędna punktu
		typedef std::multimap<int, int> LinkList; //zbiór krawędzi z połączeniami punktów
	    
		///
		///Metoda zjaduje następny punkt startowy
		///
		const sf::Vector2i findNextStartingPoint() const;

		///
		///Metoda tworzy połączenie pomiędzy regionami
		///
		///@param region - identyfikator regionu
		///
		///@param *newRegion - wskaźnik na obiekt klasy DynamicRegion
		///
		void generateLinks(int region, DynamicRegion *newRegion);
	    
		///
		///Metoda dokonuje konwersji pozycji na region
		///
		///@param position - pozycja - stała referencja na obiekt klasy sf::Vector2i
		///
		int positionToRegion(const sf::Vector2i & position) const;
		
		///
		///Metoda tworzy obiekt klasy DynamicRegion - węzeł grafu
		///
		///@param region - identyfikator
		///
		///@param regionID - identyfikator obiektu klasy DynamicRegion
		///
		void createRegion(int region, int regionID);
		
		///
		///Metoda wypełnia graf węzłami począwszy od zadanego punktu
		///
		///@param - starting_point - współrzędne punktu startowego
		///
		void fillRegion(const sf::Vector2i & starting_point);
	    
		///
		///Metoda zwraca wskaźnik na węzeł grafu na podstawie podanego identyfikatora
		///
		///@param regionID - identyfikator obiektu klasy DynamicRegion
		///
		DynamicRegion *findRegion(int regionID);

		///
		///Metoda przetwarza punkty wokół danego węzła
		///
		///@param source - współrzędne węzła wokół którego obliczamy sąsiadów
		///
		///@param offset - wartość ofsetu dla współrzędnych
		///
		void processPoint(const sf::Vector2i & source, const sf::Vector2i & offset);

		///
		///Metoda sprawdza, czy dany węzeł powinien być odwiedzany
		///
		///@param position - wektor pozycji - stała referencja na obiekt klasy sf::Vector2i
		///
		bool shouldBeVisited(const sf::Vector2i & position) const;

		static int mLastRegionID;
	    
		sf::Vector2i m_map_size; //wektor przechowujący rozmiar mapy
		sf::Vector2i m_region_size; //wektor przechowujący rozmiar regionu
		sf::Vector2i m_last_point_checked; //wektor przechowujacy współrzędne ostatnio sprawdzonego punktu
		OpenList m_open_List; //lista otwarta
		LinkList m_link_list; //liczba krawędzi
		std::vector<Cell> *p_cell_list; //wskaźnik na kontener z obiektami klasy Cell
		std::vector<DynamicRegion*> *p_region_list; //wskaźnik na kontener z obiektami klasy DynamicRegion
	};
}//namespace mapengine
#endif//H_DYNAMIC_REGION_GENERATOR_JACK
