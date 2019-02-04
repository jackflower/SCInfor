//  ______________________________________
// | CPoolable.h - class definition       |
// | Jack Flower October 2012             |
// |______________________________________|
//

#ifndef H_POOLABLE_JACK
#define H_POOLABLE_JACK

#include "CPool.h"

namespace memory
{
	///
	///Klasa reprezentuje interfejs dla klas zarz¹dzaj¹cych pul¹ pamiêci
	///
	class CPoolable
	{
	public:

		///
		///Konstruktor
		///
		CPoolable(){}
    
		///
		///Destruktor wirtualny
		///
		virtual ~CPoolable();

		///
		///Wirtualna metoda wywo³ywana przez obiekty, które sam¹ maj¹ sie zniszczyæ
		///
		///@param *pool - wskaŸnik na obiekt klasy CPoolBase
		///
		virtual void Bind(CPoolBase *pool);
	};
}//namespace memory
#endif//H_POOLABLE_JACK
