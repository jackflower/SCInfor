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
	///Klasa reprezentuje kom�rk� regionu (obszaru)
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
		///Metoda zwraca flag� kolizji w obr�bie kom�ki (regionu, obszaru)
		///
		bool getCollision() const;

		///
		///Metoda ustawia flag� kolizji w obr�bie kom�ki (regionu, obszaru)
		///
		///@param collision - flaga kolizji
		///
		void setCollision(bool collision);

		///
		///Metoda zwraca g�sto�� w obr�bie regionu
		///
		int getDensity();

		///
		///Metoda ustawia g�sto�� w obr�bie regionu
		///
		///@param density - g�sto�� w obr�bie regionu
		///
		void setDensity(int density);

		///
		///Metoda zwraca identyfikator regionu kom�rki
		///
		int getRegionId();

		///
		///Metoda ustawia identyfikator regionu kom�rki
		///
		///@param regionId - identyfikator regionu kom�rki
		///
		void setRegionId(int regionId);

	private:

		bool	m_collision;	//flaga kolizji
		int		m_density;		//g�sto�� w obr�bie regionu
		int		m_regionId;		//identyfikator regionu kom�rki
	};
} //namespace mapengine
#endif //H_CELL_JACK
