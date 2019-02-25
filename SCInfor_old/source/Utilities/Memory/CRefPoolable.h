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
	///Klasa reprezetuje mechanizm zarz¹dzania pul¹ pamiêci i zliczanie referencji
	///
	class CRefPoolable: public CPoolable
	{

	public:

		///
		///Konstruktor
		///
		CRefPoolable();
		
		///
		///Konstruktor kopiuj¹cy
		///
		///@param &other - sta³a referencja na obiekt klasy CRefPoolable
		///
		CRefPoolable(const CRefPoolable &other);

		///
		///Destruktor wirtualny
		///
		virtual ~CRefPoolable();
	
		///
		///Wirtualna metoda zwalnia zajmowan¹ pamiêæ
		///
		virtual void Release();

		///
		///Wirtualna metoda ustawia wskaŸnik na obiekt klasy CPoolBase
		///
		///@param *pool - wskaŸnik na obiekt klasy CPoolBase
		///
		virtual void Bind(CPoolBase *pool);

		///
		///Metoda zwraca iloœæ referencji do obiektu
		///
		inline int &GetRefCnt()
		{
			return m_ref_count;
		}

	private:
    
		int			m_ref_count;	//liczni referencji
		CPoolBase*	p_pool;			//wskaŸnik na klasê reprezentuj¹c¹ bazow¹ klasê dla klas zarz¹dzaj¹cych pamiêci¹
	};
}//namespace memory
#endif//H_REFPOOLABLE_JACK
