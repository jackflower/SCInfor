//  _________________________________
// | Cell.h - class definition       |
// | Jack Flower - Fabruary 2015     |
// |_________________________________|
//

#ifndef H_CELL_JACK
#define H_CELL_JACK

#include "../RTTI/RTTI.h"

namespace mapengine
{
	///
	///Klasa reprezentuje komórkę regionu (obszaru)
	///
	class Cell
	{
		RTTI_DECL;
	
	public:

		///
		///Konstruktor
		///
		Cell();

		///
		///Destruktor
		///
		~Cell();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca flagę kolizji w obrębie komóki (regionu, obszaru)
		///
		bool getCollision() const;

		///
		///Metoda ustawia flagę kolizji w obrębie komóki (regionu, obszaru)
		///
		///@param collision - flaga kolizji
		///
		void setCollision(bool collision);

		///
		///Metoda zwraca gęstość w obrębie regionu
		///
		int getDensity();

		///
		///Metoda ustawia gęstość w obrębie regionu
		///
		///@param density - gęstość w obrębie regionu
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

		bool m_collision; //flaga kolizji
		int	 m_density; //gęstość w obrębie regionu
		int	 m_regionId; //identyfikator regionu komórki
	};
} //namespace mapengine
#endif //H_CELL_JACK
