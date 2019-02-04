//  ____________________________________
// | CPoolBase.h - class definition     |
// | Jack Flower October 2012           |
// |____________________________________|
//

#ifndef H_CPOOL_BASE_JACK
#define H_CPOOL_BASE_JACK

#include "../../RTTI/RTTI.h"

namespace memory
{
	///
	///Klasa reprezentuje bazow¹ klasê dla klas zarz¹dzaj¹cych pamiêci¹
	///
	class CPoolBase
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPoolBase();

		///
		///Destruktor wirtualny
		///
		virtual ~CPoolBase();
		
		///
		///Wirtualna abstarkcyjna metoda zwalni¹ca pamiêæ
		///
		///@param *obj - wskaŸnik void na obiekt jakiegoœ typu
		///
		virtual void DeallocMe(void *obj) = 0;
	};
}//namespace memory
#endif//H_CPOOL_BASE_JACK
