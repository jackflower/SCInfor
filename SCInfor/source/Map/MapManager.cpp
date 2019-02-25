//  _______________________________________
// | MapManager.cpp - class implementation |
// | Jack Flower June 2013                 |
// |_______________________________________|
//

#include <iostream>
#include <cstdio>
#include "MapManager.h"
//#include "../Editor/CEditor.h"
#include "../Game/Game.h"
#include "../Rendering/Drawable/DrawableManager.h"
//#include "../Rendering/Camera/CCamera.h"
#include "../ResourceManager/ResourceManager.h"
//#include "../Logic/Player.h"
//#include "../Logic/CPlayerManager.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Logic/Logic.h"
//#include "../Logic/Boss/CBossManager.h"
//#include "../Commands/CCommands.h"
#include "../Game/GameProperties.h"
//#include "../Utilities/HRTimer.h"
//#include "../Utilities/FileUtils/FileUtils.h"

//template<> mapengine::MapManager* CSingleton<mapengine::MapManager>::m_Singleton = 0;
using namespace mapengine;
template<> mapengine::MapManager* CSingleton<mapengine::MapManager>::m_singleton = 0;

using namespace resource;
using namespace game;

namespace mapengine
{
	//Konstruktor
	MapManager::MapManager()
	:
		p_map(NULL)//,
	//	p_scene_manager				(new CQuadTreeSceneManager()),
	//	p_collision_map				(new CollisionMap()),
    //  m_current_map_time_elapsed	(0.0f),
    //    m_hide_loading_screen		(false)
	{
		fprintf(stderr, "MapManager::MapManager()\n");
		gGame.addFrameListener(this);
		m_visited_maps.clear();
	}

	//Destruktor wirtualny
	MapManager::~MapManager()
	{
		printf("MapManager::~MapManager()\n");

		//blokuję (luty 2015)

		//if (p_scene_manager)
		//	delete p_scene_manager;
		if (p_map)
			gResourceManager.dropResource(p_map->getFilename());

		for (unsigned i = 0; i < m_visited_maps.size(); i++)
			gResourceManager.dropResource(m_visited_maps[i]->getFilename());

		m_visited_maps.clear();
	}

	//Metoda ustawia parametry mapy na podstawie stałego wskaźnika void
	void MapManager::setMapFromData(const void *data)
	{
		//blokuję (luty 2015)
		//MapManager::NextMapData *p_data = (MapManager::NextMapData*)data;
		//SetMap(*(p_data->m_next_map), p_data->m_load_complete_map, *(p_data->m_next_map_region));
	}

	//Logika zarzędza harmonogramem zmian przemieszczania się na mapach świata gry
	void MapManager::scheduleSetMap(const std::string *p_map_file, bool load_complete_map, const std::string *region)
	{
		setMap(*p_map_file, true, *region);
	}

	//Metoda sprawdza i ustawiam mapę na odwiedzoną (gracz opuszcza mapę - następna)
	void MapManager::setCurrentMapAsVisited()
	{
		//blokuję (luty 2015)
		/*
		if (p_map != NULL)
		{
			//gEditor.SetSelectedToErase( NULL );
			p_scene_manager->ClearScene();

			for (unsigned i = 0; i < m_visited_maps.size(); i++)
			{
				if (m_visited_maps[i]->GetFilename() == p_map->GetFilename()) break;
				if (i == m_visited_maps.size() - 1) m_visited_maps.push_back(p_map);
			}
			sf::FloatRect zero(0.0f,0.0f,0.0f,0.0f);
			p_map->CullVisibility(zero);//zerujemy widoczność kafli znajdujących się w obszarze kamery
			p_map = NULL;
		}
		*/
		p_map = NULL;
	}

	//Metoda ładuje i/lub udostepnia mapę z zasobów. Automatycznie czyście scenę
	bool MapManager::setMap(const std::string & map_file, bool load_complete_map, const std::string & region)
	{
        // mierzenie czasu zaladowania
		//blokuję (luty 2015)
        //sf::Clock timer;
        //timer.Reset();

		//#ifndef __NONAME___
		//		if ( p_map != NULL && p_map->GetFilename() == mapFile ){
		//			if ( region != "" )
		//			{
		//              gPlayerManager.MovePlayersToRegion(region);
		//            }
		//			return true;
		//		}
		//#endif

		setCurrentMapAsVisited();

		//#ifdef __NONAME___
		//		gResourceManager.LoadMap( mapFile );
		//#endif
				// bo segfault przy ominieciu bossa..
				//gBossManager.ClearData();
		//jeszcze tego nie mam...

		p_map = gResourceManager.getMap( map_file );
		if ( p_map )
		{
			fprintf( stderr, "mapFile = %s\n", map_file.c_str() );
			fprintf( stderr, "m_CurrentMap->GetFilename() = %s\n", p_map->getFilename().c_str() );
			//p_scene_manager->Initialize( p_map->GetSize() );
			           
			p_map->respawnMapObjects(load_complete_map);
			
			int x = 0;//
			//p_map->RespawnDoodahs();
			//TUTAJ inicjuję wskaźnik na mapę kolizji, a dokładniej
			//ustawiam rozmiar mapy kolizji zgodnie w rozmiarem
			//wczytanej wcześniej mapy świata..
			//bo tylko ta klasa (MapManager)
			//może ładować mapy oraz nimi zarządzać...
			//ale dlaczego razy cztery?
			//czyżby quadtree?


			//na razie zablokuję mechanizm mapy kolizji...
			//p_collision_map->Initialize( p_map->GetSize() * 4 );
			//for ( unsigned i = 0; i < gPlayerManager.GetPlayerCount(); i++ )
			//{
			//	p_scene_manager->AddSceneNode( gPlayerManager.GetPlayerByOrder(i)->GetSceneNode() );
			//}

            //if ( region != "" )
			//{
            //    gPlayerManager.MovePlayersToRegion(region);
			//	gCamera.update(0.0f);
            //}

            m_current_map_time_elapsed = 0.0f;

            // save przeniesione do CGame::MainLoopStep

            //gLogic.GetGameScreens()->ResetCompass();
            //gLogic.GetGameScreens()->Show(L"hud");

            // jak stoimy z czasem? oplaca sie pokazywac loading screena czy nie?
            //float time = timer.GetElapsedTime();
            //fprintf(stderr, "Map %s loaded in %.4fs, will %s loading screen\n", mapFile.c_str(), time, (time < LOADING_TOO_SLOW ? "hide" : "show"));
            //m_hide_loading_screen = (time < LOADING_TOO_SLOW);

			return true;
		}
		//*/

        //timer.GetElapsedTime();
        //gConsole.Printf(L"Cannot load map: %s\n", mapFile.c_str());

		return false;
	}

	//Wirtualna metoda aktualizująca logikę mapy
	void MapManager::frameStarted(float secondsPassed)
	{
		//sf::FloatRect cameraRect
		//(
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Left / mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Top / mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Right / mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Bottom / mapengine::TILE_SIZE
			//to odblokować...poniżej
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Left,	//	/ mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Top,	//	/ mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Right,	//	/ mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Bottom	//	/ mapengine::TILE_SIZE

		//);

		//p_scene_manager->UpdateScene();
		//p_scene_manager->CullVisibility(cameraRect);

		//if (p_map)
		//	p_map->CullVisibility(cameraRect);//aktualizacja widoczności kafli

        //TODO: potencjalny bug: jeśli gra bedzie w trybie pause, ten czas nadal leci
        m_current_map_time_elapsed += secondsPassed;
		//diagnostyka
		//ok...działa...
		//std::cout << m_current_map_time_elapsed << std::endl;
	}

	//Metoda zapisuje mapę
    bool MapManager::saveMap(const std::string & map_file)
	{
        if (p_map == NULL)
            return false;
        else
           return p_map->save(map_file);
    }

	/*
	//Metoda zapisuje pustą mapę
	void MapManager::SaveEmptyMap(const std::string& filename, const sf::Vector2i& size)
	{
		std::stringstream ss;
		ss << "<map>\n";
		ss << "<version>" << mapengine::CURRENT_MAP_VERSION << "</version>\n";
		ss << "<width>" << size.x << "</width>\n";
		ss << "<height>" << size.y << "</height>\n";

		//do tego napisać coś rozsądniejszego...jakoś podłożyć defaultową grafikę fabrycznego kafla
		//lub utworzyć taki obiekt syntetycznie
		ss << "<tiletype code=\"aa\" image=\"data/maps/themes/test/rgrass.png\"/>\n";
		//do tego napisać coś rozsądniejszego...

		// kafle
		ss << "<tiles>";
		for (int i = 0; i < size.x*size.y; i++)
			ss << "aa ";
		ss << "</tiles>\n";

		ss << "</map>\n";
		
		fileutils::WriteToFile(filename, ss.str().c_str());
	}
	*/
}//namespace mapengine
