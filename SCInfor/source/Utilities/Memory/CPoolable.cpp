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

	//Wirtualna metoda wywo�ywana przez obiekty, kt�re sam� maj� sie zniszczy�
	void CPoolable::Bind(CPoolBase *pool)
	{
	}
}//namespace memory
