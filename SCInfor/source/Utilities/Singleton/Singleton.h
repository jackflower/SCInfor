//  _________________________________________
// | Singleton.h - template class definition |
// | Jack Flower - July 2012                 |
// |_________________________________________|
//

#ifndef H_SINGLETONE_JACK
#define H_SINGLETONE_JACK

#include <assert.h>
#include "SingletonCleaner.h"

///
///Szablon reprezentuje wzorzec Singleton
///
template <typename T> class Singleton : public ICleanupable
{

protected:
    
    ///
	///Konstruktor chroniony
	///
	Singleton()
    {
		assert(!m_singleton);
		m_singleton = static_cast<T*>(this);
		SingletonCleaner::GetSingleton().Register(this);
    }

    ///
	///Destruktor chroniony
	///
	virtual ~Singleton()
	{
		assert(m_singleton);
		m_singleton = 0;
	}
	
	static T* m_singleton;	//statyczna składowa - wskaźnik na instancję obiektu

public:

	///
	///Wirtualna metoda czyszcząca singleton - implementacja w klasach pochodnych
	///
	virtual void cleanup() {};

    ///
	///Metoda statyczna zwracająca dereferencję wskaźnika obiektu
	///
	static T& GetSingleton()
	{
		if (m_singleton == 0)
			new T();
		return (*m_singleton);
	}
    
	///
	///Metoda statyczna zwracająca wskaźnik obiektu
	///
	static T* GetSingletonPtr()
	{
		return m_singleton;
	}
};

//2016-01-31
//Blokuję w szablonie zerowanie składowej statycznej m_singleton
//Blokowanie następuje w klasach potomnych
//template <typename T> T* Singleton<T>::m_singleton = 0;

#endif//H_SINGLETONE_JACK
