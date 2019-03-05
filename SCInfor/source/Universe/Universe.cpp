//  _____________________________________
// | Universe.cpp - class implementation |
// | Jack Flower - May 2014              |
// |_____________________________________|
//

#include "Universe.h"
#include "../XML/Xml.h"

using namespace universe;
using namespace xml;

template<> Universe* CSingleton<Universe>::m_singleton = 0;

namespace universe
{
	//Konstruktor
	Universe::Universe()
	:
		m_galaxy{}
	{
			fprintf(stderr, "Universe::Universe()\n");
			//gGame.AddFrameListener(this);//???

			//Ładowanie pliku xml - wszechświat
			LoadUniverse("../data/xml_data/universe/universe.xml", "root");
			fprintf(stderr, "Universe::Universe() universe loaded...\n");
	}

	//Destruktor wirtualny
	Universe::~Universe(void)
	{
		m_galaxy;
	}

	//Wirtualna metoda czyszcząca singleton
	void Universe::cleanup()
	{
		fprintf(stderr, "Universe::cleanup()\n");
		fprintf(stderr, "Universe::cleanup() done...\n");
	}

	//Metoda na podstawie nazwy zwraca z kontenera wskaźnik na galaktykę
	Galaxy *Universe::getGalaxy(const std::string & galaxy_name)
	{
		Galaxy *galaxyPtr = NULL;
		if (m_galaxy.find(galaxy_name) != m_galaxy.end())
			galaxyPtr = m_galaxy[galaxy_name];

		if (galaxyPtr == NULL)
		{
			if (galaxy_name != "")
				fprintf(stderr, "warning: Universe::getGalaxy - unable to find `%s' galaxy_name in m_galaxy map\n", galaxy_name.c_str());
			return NULL;
		}
		return galaxyPtr;
	}

		
	//metoda ładuje dane (wszystkie obiekty wszechświata) z pliku xml (wywoływana w konstruktorze)
	void Universe::LoadUniverse(const std::string &file_name, const std::string &node_name)
	{
		//zmienne pomocnicze, poza pętlą, aby nie obciążać stosu
		std::string m_galaxy_name = "";

		Xml xml(file_name, node_name);
		//dodatkowo odczytać dane dla klasy Universe (wszechświata...)
		//

		for (xml_node<> *node = xml.getChild(xml.getRootNode(), "galaxy_name"); node; node = xml.getSibling(node, "galaxy_name"))
		{
			m_galaxy_name = xml.getString(node, "name"); //odczutuję nazwę galaktyki - (unikalna nazwa dla kontenera)
			Galaxy* galaxy = new Galaxy(); //tworzę galaktykę
			for (xml_node<> *second_node = xml.getChild(node, "galaxy_data"); second_node; second_node = xml.getSibling(second_node, "galaxy_data"))
			{
				//przepisuję dane galaktyki
				galaxy->setName(xml.getString(second_node, "galaxy_name"));
				galaxy->setGalaxyType(xml.getString(second_node, "galaxy_type"));

				//dodaję galaktykę do kontenera
				m_galaxy[m_galaxy_name] = galaxy;
			}
		}
		int x = 0;
	}

}//namespace universe
