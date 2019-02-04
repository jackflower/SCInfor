/*
 ___________________________________________
| CSingleton.h - template class definition. |
| Jack Flower - July 2012.                  |
|___________________________________________|

*/

#ifndef H_SINGLETONE_JACK
#define H_SINGLETONE_JACK

#include <assert.h>
#include "CSingletonCleaner.h"

///
///Szablon reprezentuje wzorzec Singleton
///
template <typename T> class CSingleton : public ICleanupable
{

protected:
    
    ///
	///Konstruktor chroniony
	///
    CSingleton()
    {
		assert(!m_singleton);
		m_singleton = static_cast<T*>(this);
		CSingletonCleaner::GetSingleton().Register(this);
    }

    ///
	///Destruktor chroniony
	///
	virtual ~CSingleton()
	{
		assert(m_singleton);
		m_singleton = 0;
	}
	
	static T* m_singleton;	//statyczna sk³adowa - wskaŸnik na instancjê obiektu

public:

	///
	///Wirtualna metoda czyszcz¹ca singleton - implementacja w klasach pochodnych
	///
	virtual void Cleanup() {};

    ///
	///Metoda statyczna zwracaj¹ca dereferencjê wskaŸnika obiektu
	///
	static T& GetSingleton()
	{
		if (m_singleton == 0)
			new T();
		return (*m_singleton);
	}
    
	///
	///Metoda statyczna zwracaj¹ca wskaŸnik obiektu
	///
	static T* GetSingletonPtr()
	{
		return m_singleton;
	}
};

//2016-01-31
//Blokujê w szablonie zerowanie sk³adowej statycznej m_singleton
//Blokowanie nastêpuje w klasach potomnych
//template <typename T> T* CSingleton<T>::m_singleton = 0;

#endif//H_SINGLETONE_JACK
