//  ___________________________________________
// | SingletonCleaner.h - class implementation |
// | Jack Flower - December 2012               |
// |___________________________________________|
//

#include "SingletonCleaner.h"

//Konstruktor domyślny
SingletonCleaner::SingletonCleaner()
{
	fprintf(stderr, "CSingletonCleaner::CSingletonCleaner()\n");
	s_instance = this;
}

//Destruktor wirtualny
SingletonCleaner::~SingletonCleaner()
{
	fprintf(stderr, "SingletonCleaner::~SingletonCleaner()\n");
	assert(s_instance);
	while (m_cleanupables.size() > 0)
	{
		m_cleanupables[m_cleanupables.size()-1]->cleanup();
		m_cleanupables.pop_back();
		fprintf(stderr, "CSingletonCleaner - %d objects unregistered\n", m_cleanupables.size());
	}
	s_instance = nullptr;
}

//Metoda rejestruje obiekty dziedziczące po klasie ICleanupable (Singletony)
void SingletonCleaner::Register(ICleanupable *p_cleanupable)
{
	m_cleanupables.push_back(p_cleanupable);
	fprintf(stderr, "CSingletonCleaner - %d objects registered\n", m_cleanupables.size());
}

//Metoda statyczna zwracająca referencję do tego obiektu
SingletonCleaner& SingletonCleaner::GetSingleton()
{
	assert(s_instance);
	return (*s_instance);
}

//Nadanie wartości początkowej składowej statycznej
SingletonCleaner *SingletonCleaner::s_instance = nullptr;
