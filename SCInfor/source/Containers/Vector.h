// ____________________________________
// | Vector.h - definicja klasy        |
// | Jack Flower - June 2019           |
// |___________________________________|
//

#ifndef H_VECTOR_JACK
#define H_VECTOR_JACK

#include <vector>
#include <algorithm>

namespace scinfor
{
	///
	///Klasa reprezentuje opakowania kontenera STL (std::vector) wraz
	///z wbudowanymi mechanizmami oraz implementacją wedgług standardy C++17
	///
	class Vector
	{
	public:

		///
		///Konstruktor domyślny
		///
		Vector();

		///
		///Destruktor wirtualny
		///
		virtual ~Vector();

	private:

	};
}//namespace scinfor
#endif//H_VECTOR_JACK
