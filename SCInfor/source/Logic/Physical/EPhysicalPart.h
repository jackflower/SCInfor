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
	///Wyliczenie reprezentuje elementy sk³adowe klasy CPhysical
	///
	enum EPhysicalPart
	{
		BODY,	//czêœæ podstawa (np. w przypadku czo³gu - podwozie)
		HEAD	//czêœæ dodatkowa (np. w przypadku czo³gu - wie¿a)
	};
}
#endif //H_PHYSICAL_PART_JACK