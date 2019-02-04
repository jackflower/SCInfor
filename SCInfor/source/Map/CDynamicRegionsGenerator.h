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
		///@param &map_size - rozmiar mapy sta�a referencja na obiekt klasy sf::Vector2i
		///
		///@param &region_size - rozmiar regionu sta�a referencja na obiekt klasy sf::Vector2i
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

		//definicje typ�w
		typedef std::vector<sf::Vector2i> PointList;	//kontener przechowuje wsp�rz�dne w�z��w mapy (punkty grafu)
		typedef std::map<int, PointList> OpenList;		//mapa obiekt�w first/key/-liczba, secound - wesp�rz�dna punktu
		typedef std::multimap<int, int> LinkList;		//zbi�r kraw�dzi z po��czeniami punkt�w
	    
		///
		///Metoda zjaduje nast�pny punkt startowy
		///
		const sf::Vector2i FindNextStartingPoint() const;

		///
		///Metoda tworzy po��czenie pomi�dzy regionami
		///
		///@param region - identyfikator regionu
		///
		///@param *newRegion - wska�nik na obiekt klasy CDynamicRegion
		///
		void GenerateLinks(int region, CDynamicRegion* newRegion);
	    
		///
		///Metoda dokonuje konwersji pozycji na region
		///
		///@param &position - pozycja - sta�a referencja na obiekt klasy sf::Vector2i
		///
		int PositionToRegion(const sf::Vector2i& position) const;
		
		///
		///Metoda tworzy obiekt klasy CDynamicRegion - w�ze� grafu
		///
		///@param region - identyfikator
		///
		///@param regionID - identyfikator obiektu klasy CDynamicRegion
		///
		void CreateRegion(int region, int regionID);
		
		///
		///Metoda wype�nia graf w�z�ami pocz�wszy od zadanego punktu
		///
		///@param - &starting_point - wsp�rz�dne punktu startowego
		///
		void FillRegion(const sf::Vector2i & starting_point);
	    
		///
		///Metoda zwraca wska�nik na w�ze� grafu na podstawie podanego identyfikatora
		///
		///@param regionID - identyfikator obiektu klasy CDynamicRegion
		///
		CDynamicRegion* FindRegion(int regionID);

		///
		///Metoda przetwarza punkty wok� danego w�z�a
		///
		///@param &source - wsp�rz�dne w�z�a wok� kt�rego obliczamy s�siad�w
		///
		///@param &offset - warto�� ofsetu dla wsp�rz�dnych
		///
		void ProcessPoint(const sf::Vector2i & source, const sf::Vector2i & offset);

		///
		///Metoda sprawdza, czy dany w�ze� powinien by� odwiedzany
		///
		///@param &position - wektor pozycji - sta�a referencja na obiekt klasy sf::Vector2i
		///
		bool ShouldBeVisited(const sf::Vector2i& position) const;

		static int mLastRegionID;
	    
		sf::Vector2i					m_map_size;				//wektor przechowuj�cy rozmiar mapy
		sf::Vector2i					m_region_size;			//wektor przechowuj�cy rozmiar regionu
		sf::Vector2i					m_last_point_checked;	//wektor przechowujacy wsp�rz�dne ostatnio sprawdzonego punktu
		OpenList						m_open_List;			//lista otwarta
		LinkList						m_link_list;			//liczba kraw�dzi
		std::vector<CCell>*				p_cell_list;			//wska�nik na kontener z obiektami klasy CCell
		std::vector<CDynamicRegion*>*	p_region_list;			//wska�nik na kontener z obiektami klasy CDynamicRegion
	};
}//namespace mapengine
#endif//H_DYNAMIC_REGION_GENERATOR_JACK
