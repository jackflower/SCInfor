//  _______________________________
// | EPhysicalPart.h - enumeration |
// | Jack Flower - October 2012    |
// |_______________________________|
//

#ifndef H_PHYSICAL_PART_JACK
#define H_PHYSICAL_PART_JACK

namespace logic
{
	///
	///Wyliczenie reprezentuje elementy sk�adowe klasy CPhysical
	///
	enum EPhysicalPart
	{
		BODY,	//cz�� podstawa (np. w przypadku czo�gu - podwozie)
		HEAD	//cz�� dodatkowa (np. w przypadku czo�gu - wie�a)
	};
}
#endif //H_PHYSICAL_PART_JACK