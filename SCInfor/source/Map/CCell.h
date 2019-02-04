//  __________________________________
// | CCell.h - class definition       |
// | Jack Flower - Fabruary 2015.     |
// |__________________________________|
//

#ifndef H_CELL_JACK
#define H_CELL_JACK

#include "../RTTI/RTTI.h"

namespace mapengine
{
	///
	///Klasa reprezentuje komórkê regionu (obszaru)
	///
	class CCell
	{
		RTTI_DECL;
	
	public:

		///
		///Konstruktor
		///
		CCell();

		///
		///Destruktor
		///
		~CCell();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca flagê kolizji w obrêbie komóki (regionu, obszaru)
		///
		bool getCollision() const;

		///
		///Metoda ustawia flagê kolizji w obrêbie komóki (regionu, obszaru)
		///
		///@param collision - flaga kolizji
		///
		void setCollision(bool collision);

		///
		///Metoda zwraca gêstoœæ w obrêbie regionu
		///
		int getDensity();

		///
		///Metoda ustawia gêstoœæ w obrêbie regionu
		///
		///@param density - gêstoœæ w obrêbie regionu
		///
		void setDensity(int density);

		///
		///Metoda zwraca identyfikator regionu komórki
		///
		int getRegionId();

		///
		///Metoda ustawia identyfikator regionu komórki
		///
		///@param regionId - identyfikator regionu komórki
		///
		void setRegionId(int regionId);

	private:

		bool	m_collision;	//flaga kolizji
		int		m_density;		//gêstoœæ w obrêbie regionu
		int		m_regionId;		//identyfikator regionu komórki
	};
} //namespace mapengine
#endif //H_CELL_JACK
