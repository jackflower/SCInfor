/*
 _______________________________________
| CUniverse.cpp - implementacja klasy.  |
| Jack Flower - May 2014.               |
|_______________________________________|

*/

#include "CUniverse.h"
#include "../XML/CXml.h"

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

			//�adowanie pliku xml - wszech�wiat
			LoadUniverse("../data/xml_data/universe/universe.xml", "root");
			fprintf(stderr, "CUniverse::CUniverse() universe loaded...\n");
	}

	//Destruktor wirtualny
	CUniverse::~CUniverse(void)
	{
		//m_galaxy	not edit
	}

	//Wirtualna metoda czyszcz�ca singleton
	void CUniverse::Cleanup()
	{
		fprintf(stderr, "CUniverse::Cleanup()\n");
		fprintf(stderr, "CUniverse::Cleanup() done...\n");
	}

	//Metoda na podstawie nazwy zwraca z kontenera wska�nik na galaktyk�
	CGalaxy* CUniverse::GetGalaxy(const std::string& galaxy_name)
	{
		CGalaxy* galaxyPtr = NULL;
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
	//Metoda tworzy galaktyk�
	CGalaxy* CUniverse::CreateGalaxy(const std::string& galaxy_name)
	{
		CGalaxy* galaxyPtr = GetGalaxy(galaxy_name);
		return CreateGalaxy(galaxyPtr);
	}
	*/

	
	/*
	//Metoda tworzy galaktyk�
	CGalaxy* CUniverse::CreateGalaxy(CGalaxy *p_galaxy)
	{
		if (p_galaxy == NULL)
			return NULL;
		CGalaxy* p_new_galaxy = new CGalaxy();
		m_galaxy[p_new_galaxy->galaxy_name] = p_new_galaxy;
		return p_new_galaxy;

		//czyli �aduj� dane z xml i tworz�...
		//gdzie� po drodze musz� to jako� uzbroi�...
		//w dane...
	}
	*/

	/////////////
	/*

	//Nad tym trzeba si� zastanowi�...
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

		//metoda �aduje dane (wszystkie obiekty wszech�wiata) z pliku xml (wywo�ywana w konstruktorze)
		//
		//@param &file_name - nazwa pliku - sta�a referencja na obiekt klasy std::string
		//
		//@param &node_name - nazwa w�z�a xml - sta�a referencja na obiekt klasy std::string
		//
		void CUniverse::LoadUniverse(const std::string &file_name, const std::string &node_name)
		{
			//zmienne pomocnicze, poza p�tl�, aby nie obci��a� stosu
			std::string m_galaxy_name = "";

			CXml xml(file_name, node_name);
			//dodatkowo odczyta� dane dla klasy CUniverse (wszech�wiata...)
			//

			for(xml_node<> *node = xml.GetChild(xml.GetRootNode(),"galaxy_name"); node; node = xml.GetSibling(node,"galaxy_name"))
			{
				m_galaxy_name = xml.GetString(node, "name");	//odczutuj� nazw� galaktyki - (unikalna nazwa dla kontenera)
				CGalaxy* galaxy = new CGalaxy();				//tworz� galaktyk�
				for(xml_node<> *second_node = xml.GetChild(node,"galaxy_data"); second_node; second_node = xml.GetSibling(second_node,"galaxy_data"))
				{
					//przepisuj� dane galaktyki
					galaxy->setName(xml.GetString(second_node, "galaxy_name"));
					galaxy->setGalaxyType(xml.GetString(second_node, "galaxy_type"));
					
					
					//dodaj� galaktyk� do kontenera
					m_galaxy[m_galaxy_name] = galaxy;
				}
			}
			int x = 0;
		}


}//namespace universe