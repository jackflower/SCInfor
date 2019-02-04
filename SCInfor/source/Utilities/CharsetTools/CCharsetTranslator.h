//  _______________________________________________
// | CCharsetTranslator.h - class definition       |
// | Jack Flower - May 2015                        |
// |_______________________________________________|
//

#ifndef H_CHARSET_TRANSLATOR_JACK
#define H_CHARSET_TRANSLATOR_JACK

#include <wchar.h>

namespace charsettools
{
	///
	///Klasa reprezentuje opakowanie danych - klasa pomocnicza
	///
	class CCharsetTranslator
	{
	public:

		///
		///Konstruktor
		///
		CCharsetTranslator();

		///
		///Destruktor
		///
		~CCharsetTranslator();

	public:

		char	a;		//pierwszy bajt, do którego zapisujemy odczytany z xml (UTF-8 bez BOM) kod znaku
		char	b;		//drugi bajt, do którego zapisujemy odczytany z xml (UTF-8 bez BOM) kod znaku
		wchar_t out;	//rzutowany poprzez static_cast<wchar_t> kod znaku
	};
}//namespace charsettools
#endif//#define H_CHARSET_TRANSLATOR_JACK
