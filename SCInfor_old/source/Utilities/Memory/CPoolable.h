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
	///Klasa reprezentuje interfejs dla klas zarz�dzaj�cych pul� pami�ci
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
		///Wirtualna metoda wywo�ywana przez obiekty, kt�re sam� maj� sie zniszczy�
		///
		///@param *pool - wska�nik na obiekt klasy CPoolBase
		///
		virtual void Bind(CPoolBase *pool);
	};
}//namespace memory
#endif//H_POOLABLE_JACK
