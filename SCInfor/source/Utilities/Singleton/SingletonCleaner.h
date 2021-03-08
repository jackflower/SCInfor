//  ___________________________________________
// | SingletonCleaner.h - class definition     |
// | Jack Flower - December 2012               |
// |___________________________________________|
//


#ifndef H_SINGLETON_CLEANER_JACK
#define H_SINGLETON_CLEANER_JACK

#include <assert.h>
#include <vector>
#include <cstdio>

#include "ICleanupable.h"

///
///Klasa reprezentuje kontener na wskaźniki obiektów klas pochodnych interfejsu ICleanupable(Singletony)
///Jej zadaniem jest usuwanie Singletonów
///
class SingletonCleaner
{
public:

	///
	///Konstruktor domyślny
	///
	SingletonCleaner();

	///
	///Destruktor wirtualny
	///
    virtual ~SingletonCleaner();

	///
	///Metoda rejestruje obiekty dziedziczące po klasie ICleanupable (Singletony)
	///
	///@param *p_cleanupable - wskaźnik na obiekty klas pochodnych interfejsu ICleanupable
	///
    void Register(ICleanupable *p_cleanupable);

	///
	///Metoda statyczna zwracająca referencję do tego obiektu
	///
	static SingletonCleaner& GetSingleton();

private:

    std::vector<ICleanupable *>	m_cleanupables;	//kontener na wskaźniki obiektów klas pochodnych interfejsu ICleanupable(Singletony)
    static SingletonCleaner*	s_instance;		//wskaźnik na statyczną (jedyną) instancję tego obiektu - na ten obiekt

};

#endif//H_SINGLETON_CLEANER_JACK