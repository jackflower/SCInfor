//  _________________________________
// | CMap.h - class definition       |
// | Jack Flower June 2013           |
// |_________________________________|
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
	class CDynamicRegion;
}

namespace mapengine
{
	///
	///Definicja typu - wektor wska�nik�w na obiekty klasy CDynamicRegion
	///
	typedef std::vector <CDynamicRegion*> DynamicRegionList;

	///
	///Klasa reprezentuje struktur� drzewa - w�ze� grafu
	///
	class CDynamicRegion
	{
		RTTI_DECL;
	
	public:

		///
		///Konstruktor
		///
		///@param region_id - edentyfukator regionu
		///
		explicit CDynamicRegion(int region_id);

		///
		///Destruktor
		///
		~CDynamicRegion();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca identyfikator regionu
		///
		int GetRegionID() const;

		///
		///Metoda dodaje do aktualnego wez�a w�ze� s�siada
		///
		///@param *p_region - wska�nik na obiekt klasy CDynamicRegion
		///
		void AddNeighbour(CDynamicRegion* p_region);
	    
		///
		///Metoda dodaje wektor pozycji do wektora pozycji obiektu
		///
		///@param &cell - wp�rz�dne pozycji
		///
		void AddCell(const sf::Vector2i& cell);

		///
		///Metoda zwraca wsp�rz�dne �rodka geometrycznego obiektu
		///
		const sf::Vector2i& GetCenter() const;

		///
		///Metoda zwraca wektor przechowuj�cy w�z�y przyleg�e do tego obiektu
		///
		const DynamicRegionList& GetNeighbours() const;

		///
		///Zaprzyja�niony operator
		///
		friend std::ostream& operator <<(std::ostream& out, const CDynamicRegion& region);

	private:
	    
		int								m_region_id;	//identyfikator regionu
		DynamicRegionList				m_neighbours;	//wektor przechowuj�cy w�z�y przyleg�e do tego obiektu
		std::vector<sf::Vector2i>		m_cells;		//wektor przechowuj�cy pozycje obiekt�w
		sf::Vector2i					m_center;		//wektor przechowuj�cy wsp�rz�dne �rodka geometrycznego obiektu
	};
}//namespace mapengine
#endif//H_DYNAMIC_REGION_JACK
