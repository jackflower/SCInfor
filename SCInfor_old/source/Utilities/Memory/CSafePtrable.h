//  ___________________________________
// | CSafePtrable.h - class definition |
// | Jack Flower October 2012          |
// |___________________________________|
//

#ifndef H_SAFE_PTRABLE_JACK
#define H_SAFE_PTRABLE_JACK

#include "CSafePtr.h"

namespace memory
{
	///
	///Szablon klasy reprezentuje jakiœ byt bezpiecznego wskaŸnika
	///
	template<class T>
	class CSafePtrable
	{

	public:

		///
		///Konstruktor
		///
		CSafePtrable()
		:
			any((T*)this)
		{
		}
		
		///
		///Destruktor wirtualny
		///
		virtual ~CSafePtrable()
		{
			any.NullAll();
		}

		///
		///Metoda zwraca kopiê jakiegoœ obiektu (to MA byc kopia - bez &)
		///
		inline CSafePtr<T> GetSafePointer() const 
		{
			return any;
		}

	private:

		CSafePtr<T> any;	//jakiœ obiekt
	};
}//namespace memory
#endif//H_SAFE_PTRABLE_JACK
