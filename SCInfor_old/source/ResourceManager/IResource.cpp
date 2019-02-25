//  __________________________________________________________
// | IResource.cpp - implementacja abstrakcyjnego interfejsu  |
// | Jack Flower - September 2012                             |
// |__________________________________________________________|
//

#include "IResource.h"

namespace resource
{
	RTTI_IMPL_NOPARENT(IResource);

	//Konstruktor
	IResource::IResource()
	{
	}

	//Destruktor wirtualny
	IResource::~IResource()
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string IResource::GetType() const
	{
		return rtti.GetNameClass();
	}

}//namespace resource
