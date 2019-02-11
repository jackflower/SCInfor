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
	///Wyliczenie reprezentuje elementy składowe klasy Physical
	///
	enum EPhysicalPart
	{
		BODY,	//część podstawa (np. w przypadku czołgu - podwozie)
		HEAD	//część dodatkowa (np. w przypadku czołgu - wieża)
	};
}
#endif //H_PHYSICAL_PART_JACK