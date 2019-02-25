//  ______________________________________
// | CPoolable.cpp - class implementation |
// | Jack Flower October 2012             |
// |______________________________________|
//

#include "CPoolable.h"

namespace memory
{
	//Destruktor wirtualny
	CPoolable::~CPoolable()
	{
	}

	//Wirtualna metoda wywo³ywana przez obiekty, które sam¹ maj¹ sie zniszczyæ
	void CPoolable::Bind(CPoolBase *pool)
	{
	}
}//namespace memory
