// __________________________________________
// | CRefPoolable.h - class definition       |
// | Jack Flower October 2012                |
// |_________________________________________|
//

#ifndef H_REFPOOLABLE_JACK
#define H_REFPOOLABLE_JACK

#include <cstdio>
#include "CPoolable.h"
#include "CPool.h"

namespace memory
{
	///
	///Klasa reprezetuje mechanizm zarz�dzania pul� pami�ci i zliczanie referencji
	///
	class CRefPoolable: public CPoolable
	{

	public:

		///
		///Konstruktor
		///
		CRefPoolable();
		
		///
		///Konstruktor kopiuj�cy
		///
		///@param &other - sta�a referencja na obiekt klasy CRefPoolable
		///
		CRefPoolable(const CRefPoolable &other);

		///
		///Destruktor wirtualny
		///
		virtual ~CRefPoolable();
	
		///
		///Wirtualna metoda zwalnia zajmowan� pami��
		///
		virtual void Release();

		///
		///Wirtualna metoda ustawia wska�nik na obiekt klasy CPoolBase
		///
		///@param *pool - wska�nik na obiekt klasy CPoolBase
		///
		virtual void Bind(CPoolBase *pool);

		///
		///Metoda zwraca ilo�� referencji do obiektu
		///
		inline int &GetRefCnt()
		{
			return m_ref_count;
		}

	private:
    
		int			m_ref_count;	//liczni referencji
		CPoolBase*	p_pool;			//wska�nik na klas� reprezentuj�c� bazow� klas� dla klas zarz�dzaj�cych pami�ci�
	};
}//namespace memory
#endif//H_REFPOOLABLE_JACK
