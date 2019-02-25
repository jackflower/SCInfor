//  _________________________________________________________
// | Resource.cpp - implementacja abstrakcyjnego interfejsu  |
// | Jack Flower - September 2012                            |
// |_________________________________________________________|
//

#include "Resource.h"

namespace resource
{
	RTTI_IMPL_NOPARENT(Resource);

	//Konstruktor
	Resource::Resource()
	{
	}

	//Destruktor wirtualny
	Resource::~Resource()
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Resource::getType() const
	{
		return rtti.getNameClass();
	}

}//namespace resource
