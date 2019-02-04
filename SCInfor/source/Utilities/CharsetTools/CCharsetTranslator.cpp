//  _______________________________________________
// | CCharsetTranslator.cpp - class implementation |
// | Jack Flower - May 2015                        |
// |_______________________________________________|
//

#include "CCharsetTranslator.h"

namespace charsettools
{
	//Konstruktor
	CCharsetTranslator::CCharsetTranslator()
	:
		a	(),
		b	(),
		out	()
	{
	}

	//Destruktor
	CCharsetTranslator::~CCharsetTranslator()
	{
		a	= 0;
		b	= 0;
		out	= 0;
	}
}//namespace charsettools
