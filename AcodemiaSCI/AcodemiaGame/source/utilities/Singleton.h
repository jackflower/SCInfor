////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#ifndef H_SINGLETON_ACODEMIA
#define H_SINGLETON_ACODEMIA
///
///Szablon reprezentuje wzorzec Singleton
///
template <typename T> class Singleton
{

protected:

	///
	///Konstruktor
	///
	Singleton()
	{
	}

	///
	///Destruktor wirtualny
	///
	virtual ~Singleton()
	{
	}

public:

	static T & getSingleton()
	{
		static T m_singleton;
		return m_singleton;
	}
};
#endif//H_SINGLETON_ACODEMIA
