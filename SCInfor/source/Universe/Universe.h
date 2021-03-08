//  _____________________________________
// | Universe.h - class definition       |
// | Jack Flower - May 2014              |
// |_____________________________________|
//

#ifndef H_UNIVERSE_JACK
#define H_UNIVERSE_JACK

#include <map>
#include <string>
#include "../Utilities/Singleton/Singleton.h"
#include "Galaxy/Galaxy.h"

using namespace universe::galaxy;

#define gUniverse Universe::GetSingleton()


namespace universe
{
	///
	///Klasa repezentuje root wszechświata - singleton - wszechświat jest jeden
	///
	class Universe : public Singleton<Universe>
	{
	public:

		///
		///Konstruktor
		///
		Universe();

		///
		///Destruktor wirtualny
		///
		virtual ~Universe();

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void cleanup();

		///
		///Metoda na podstawie nazwy zwraca z kontenera wskaźnik na galaktykę
		///
		///@param animation_name - nazwa animacji
		///
		Galaxy *getGalaxy(const std::string & galaxy_name);

	private:

		//metoda ładuje dane (wszystkie obiekty wszechświata) z pliku xml (wywoływana w konstruktorze)
		//
		//@param file_name - nazwa pliku - stała referencja na obiekt klasy std::string
		//
		//@param node_name - nazwa węzła xml - stała referencja na obiekt klasy std::string
		//
		void LoadUniverse(const std::string & file_name, const std::string & node_name);

		//definicja typu - kontener (mapa) - galaktyki
		typedef std::map<std::string, Galaxy*> GalaxyMap;
		GalaxyMap m_galaxy; //kontener (mapa) na galaktyki
	};
}//namespace universe
#endif//H_UNIVERSE_JACK

