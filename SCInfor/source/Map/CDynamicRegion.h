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
	///Definicja typu - wektor wskaŸników na obiekty klasy CDynamicRegion
	///
	typedef std::vector <CDynamicRegion*> DynamicRegionList;

	///
	///Klasa reprezentuje strukturê drzewa - wêze³ grafu
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
		///Metoda dodaje do aktualnego wez³a wêze³ s¹siada
		///
		///@param *p_region - wskaŸnik na obiekt klasy CDynamicRegion
		///
		void AddNeighbour(CDynamicRegion* p_region);
	    
		///
		///Metoda dodaje wektor pozycji do wektora pozycji obiektu
		///
		///@param &cell - wpó³rzêdne pozycji
		///
		void AddCell(const sf::Vector2i& cell);

		///
		///Metoda zwraca wspó³rzêdne œrodka geometrycznego obiektu
		///
		const sf::Vector2i& GetCenter() const;

		///
		///Metoda zwraca wektor przechowuj¹cy wêz³y przyleg³e do tego obiektu
		///
		const DynamicRegionList& GetNeighbours() const;

		///
		///ZaprzyjaŸniony operator
		///
		friend std::ostream& operator <<(std::ostream& out, const CDynamicRegion& region);

	private:
	    
		int								m_region_id;	//identyfikator regionu
		DynamicRegionList				m_neighbours;	//wektor przechowuj¹cy wêz³y przyleg³e do tego obiektu
		std::vector<sf::Vector2i>		m_cells;		//wektor przechowuj¹cy pozycje obiektów
		sf::Vector2i					m_center;		//wektor przechowuj¹cy wspó³rzêdne œrodka geometrycznego obiektu
	};
}//namespace mapengine
#endif//H_DYNAMIC_REGION_JACK
