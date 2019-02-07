//  _____________________________________________________
// | MagazineAmmunitionTemplate.h - class implementacion |
// | Jack Flower February 2019                           |
// |_____________________________________________________|
//

#include "MagazineAmmunitionTemplate.h"


namespace factory
{

	RTTI_IMPL(MagazineAmmunitionTemplate, CActorTemplate);

	//Konstruktor domyślny
	MagazineAmmunitionTemplate::MagazineAmmunitionTemplate()
	:
		CActorTemplate()//konstruktor klasy bazowej
	{
	}

	//Destruktor wirtualny
	MagazineAmmunitionTemplate::~MagazineAmmunitionTemplate()
	{
		//CActorTemplate
	}
}//namespace factory

