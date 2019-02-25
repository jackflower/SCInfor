//  __________________________________________
// | DynamicRegion.h - class definition       |
// | Jack Flower June 2013                    |
// |__________________________________________|
//

#ifndef H_DYNAMIC_REGION_JACK
#define H_DYNAMIC_REGION_JACK

#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <vector>
#include "../RTTI/RTTI.h"

///
///Forward declaration
///
namespace mapengine
{
	class DynamicRegion;
}

namespace mapengine
{
	///
	///Definicja typu - wektor wskaźników na obiekty klasy DynamicRegion
	///
	typedef std::vector <DynamicRegion*> DynamicRegionList;

	///
	///Klasa reprezentuje strukturę drzewa - węzeł grafu
	///
	class DynamicRegion
	{
		RTTI_DECL;
	
	public:

		///
		///Konstruktor
		///
		///@param region_id - edentyfukator regionu
		///
		explicit DynamicRegion(int region_id);

		///
		///Destruktor
		///
		~DynamicRegion();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca identyfikator regionu
		///
		int getRegionID() const;

		///
		///Metoda dodaje do aktualnego wezła węzeł sąsiada
		///
		///@param *p_region - wskaźnik na obiekt klasy DynamicRegion
		///
		void addNeighbour(DynamicRegion *p_region);
	    
		///
		///Metoda dodaje wektor pozycji do wektora pozycji obiektu
		///
		///@param cell - wpółrzędne pozycji
		///
		void addCell(const sf::Vector2i & cell);

		///
		///Metoda zwraca współrzędne środka geometrycznego obiektu
		///
		const sf::Vector2i & getCenter() const;

		///
		///Metoda zwraca wektor przechowujący węzły przyległe do tego obiektu
		///
		const DynamicRegionList & getNeighbours() const;

		///
		///Zaprzyjaźniony operator
		///
		friend std::ostream & operator <<(std::ostream & out, const DynamicRegion & region);

	private:
	    
		int m_region_id; //identyfikator regionu
		DynamicRegionList m_neighbours;	//wektor przechowujący węzły przyległe do tego obiektu
		std::vector<sf::Vector2i> m_cells; //wektor przechowujący pozycje obiektów
		sf::Vector2i m_center; //wektor przechowujący współrzędne środka geometrycznego obiektu
	};
}//namespace mapengine
#endif//H_DYNAMIC_REGION_JACK
