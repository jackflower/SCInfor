//  _____________________________________________________
// | MagazineAmmunitionTemplate.h - class implementacion |
// | Jack Flower February 2019                           |
// |_____________________________________________________|
//

#include "MagazineAmmunitionTemplate.h"


namespace factory
{

	RTTI_IMPL(MagazineAmmunitionTemplate, ActorTemplate);

	//Konstruktor domyślny
	MagazineAmmunitionTemplate::MagazineAmmunitionTemplate()
	:
		ActorTemplate()//konstruktor klasy bazowej
	{
	}

	//Destruktor wirtualny
	MagazineAmmunitionTemplate::~MagazineAmmunitionTemplate()
	{
		//ActorTemplate
	}
}//namespace factory

