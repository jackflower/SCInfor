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
	///Klasa reprezentuje bazow� klas� dla klas zarz�dzaj�cych pami�ci�
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
		///Wirtualna abstarkcyjna metoda zwalni�ca pami��
		///
		///@param *obj - wska�nik void na obiekt jakiego� typu
		///
		virtual void DeallocMe(void *obj) = 0;
	};
}//namespace memory
#endif//H_CPOOL_BASE_JACK
