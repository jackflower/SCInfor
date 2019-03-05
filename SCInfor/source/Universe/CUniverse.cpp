/*
 _______________________________________
| CUniverse.cpp - implementacja klasy.  |
| Jack Flower - May 2014.               |
|_______________________________________|

*/

#include "CUniverse.h"
#include "../XML/Xml.h"

using namespace universe;
using namespace xml;

template<> CUniverse* CSingleton<CUniverse>::m_singleton = 0;

namespace universe
{
	//Konstruktor
	CUniverse::CUniverse(void)
	:
		m_galaxy	()
	{
			fprintf(stderr, "CUniverse::CUniverse()\n");
			//gGame.AddFrameListener(this);//???

			//£adowanie pliku xml - wszechœwiat
			LoadUniverse("../data/xml_data/universe/universe.xml", "root");
			fprintf(stderr, "CUniverse::CUniverse() universe loaded...\n");
	}

	//Destruktor wirtualny
	CUniverse::~CUniverse(void)
	{
		//m_galaxy	not edit
	}

	//Wirtualna metoda czyszcz¹ca singleton
	void CUniverse::cleanup()
	{
		fprintf(stderr, "CUniverse::cleanup()\n");
		fprintf(stderr, "CUniverse::cleanup() done...\n");
	}

	//Metoda na podstawie nazwy zwraca z kontenera wskaŸnik na galaktykê
	Galaxy* CUniverse::GetGalaxy(const std::string& galaxy_name)
	{
		Galaxy* galaxyPtr = NULL;
		if (m_galaxy.find(galaxy_name) != m_galaxy.end())
			galaxyPtr = m_galaxy[galaxy_name];

		if (galaxyPtr == NULL)
		{
			if (galaxy_name != "")
				fprintf(stderr, "warning: CUniverse::getGalaxy - unable to find `%s' galaxy_name in m_galaxy map\n", galaxy_name.c_str());
			return NULL;
		}
		return galaxyPtr;
	}

	/*
	//Metoda tworzy galaktykê
	Galaxy* CUniverse::CreateGalaxy(const std::string& galaxy_name)
	{
		Galaxy* galaxyPtr = GetGalaxy(galaxy_name);
		return CreateGalaxy(galaxyPtr);
	}
	*/

	
	/*
	//Metoda tworzy galaktykê
	Galaxy* CUniverse::CreateGalaxy(Galaxy *p_galaxy)
	{
		if (p_galaxy == NULL)
			return NULL;
		Galaxy* p_new_galaxy = new Galaxy();
		m_galaxy[p_new_galaxy->galaxy_name] = p_new_galaxy;
		return p_new_galaxy;

		//czyli ³adujê dane z xml i tworzê...
		//gdzieœ po drodze muszê to jakoœ uzbroiæ...
		//w dane...
	}
	*/

	/////////////
	/*

	//Nad tym trzeba siê zastanowiæ...
		//Metoda usuwa funkcjonalny obiekt animowany
		void AnimationManager::DestroyAnimationState(AnimationState* p_animation_state)
		{
			if (!p_animation_state)
			{
				fprintf(stderr, "warning: AnimationManager::DestroyAnimationState - p_animation_state was NULL\n");
				return;
			}

			if (m_animation_states.find(p_animation_state) != m_animation_states.end())
			{
				m_animation_states.erase(m_animation_states.find(p_animation_state));
				delete p_animation_state;
				return;
			}
			else
			{
				fprintf(stderr, "error: AnimationManager::DestroyAnimationState - p_animation_state was not found in set\n");
				return;
			}
		}
	*/
	/////////////

		//metoda ³aduje dane (wszystkie obiekty wszechœwiata) z pliku xml (wywo³ywana w konstruktorze)
		//
		//@param &file_name - nazwa pliku - sta³a referencja na obiekt klasy std::string
		//
		//@param &node_name - nazwa wêz³a xml - sta³a referencja na obiekt klasy std::string
		//
		void CUniverse::LoadUniverse(const std::string &file_name, const std::string &node_name)
		{
			//zmienne pomocnicze, poza pêtl¹, aby nie obci¹¿aæ stosu
			std::string m_galaxy_name = "";

			Xml xml(file_name, node_name);
			//dodatkowo odczytaæ dane dla klasy CUniverse (wszechœwiata...)
			//

			for(xml_node<> *node = xml.getChild(xml.getRootNode(),"galaxy_name"); node; node = xml.getSibling(node,"galaxy_name"))
			{
				m_galaxy_name = xml.getString(node, "name");	//odczutujê nazwê galaktyki - (unikalna nazwa dla kontenera)
				Galaxy* galaxy = new Galaxy();				//tworzê galaktykê
				for(xml_node<> *second_node = xml.getChild(node,"galaxy_data"); second_node; second_node = xml.getSibling(second_node,"galaxy_data"))
				{
					//przepisujê dane galaktyki
					galaxy->setName(xml.getString(second_node, "galaxy_name"));
					galaxy->setGalaxyType(xml.getString(second_node, "galaxy_type"));
					
					
					//dodajê galaktykê do kontenera
					m_galaxy[m_galaxy_name] = galaxy;
				}
			}
			int x = 0;
		}


}//namespace universe