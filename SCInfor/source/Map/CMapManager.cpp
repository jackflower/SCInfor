//  ________________________________________
// | CMapManager.cpp - class implementation |
// | Jack Flower June 2013.                 |
// |________________________________________|
//

#include <iostream>
#include <cstdio>
#include "CMapManager.h"
//#include "../Editor/CEditor.h"
#include "../Game/Game.h"
#include "../Rendering/Drawable/CDrawableManager.h"
//#include "../Rendering/Camera/CCamera.h"
#include "../ResourceManager/CResourceManager.h"
//#include "../Logic/CPlayer.h"
//#include "../Logic/CPlayerManager.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Logic/CLogic.h"
//#include "../Logic/Boss/CBossManager.h"
//#include "../Commands/CCommands.h"
#include "../Game/GameProperties.h"
//#include "../Utilities/HRTimer.h"
//#include "../Utilities/FileUtils/FileUtils.h"

//template<> mapengine::CMapManager* CSingleton<mapengine::CMapManager>::m_Singleton = 0;
using namespace mapengine;
template<> mapengine::CMapManager* CSingleton<mapengine::CMapManager>::m_singleton = 0;

using namespace resource;
using namespace game;

namespace mapengine
{
	//Konstruktor
	CMapManager::CMapManager()
	:
		p_map						(NULL)//,
	//	p_scene_manager				(new CQuadTreeSceneManager()),
	//	p_collision_map				(new CCollisionMap()),
    //  m_current_map_time_elapsed	(0.0f),
    //    m_hide_loading_screen		(false)
	{
		fprintf(stderr, "CMapManager::CMapManager()\n");
		gGame.addFrameListener(this);
		m_visited_maps.clear();
	}

	//Destruktor wirtualny
	CMapManager::~CMapManager()
	{
		printf("CMapManager::~CMapManager()\n");

		//blokujê (luty 2015)

		//if (p_scene_manager)
		//	delete p_scene_manager;
		if (p_map)
			gResourceManager.DropResource(p_map->getFilename());

		for (unsigned i = 0; i < m_visited_maps.size(); i++)
			gResourceManager.DropResource(m_visited_maps[i]->getFilename());

		m_visited_maps.clear();
	}

	//Metoda ustawia parametry mapy na podstawie sta³ego wskaŸnika void
	void CMapManager::SetMapFromData(const void *data)
	{
		//blokujê (luty 2015)
		//CMapManager::NextMapData *p_data = (CMapManager::NextMapData*)data;
		//SetMap(*(p_data->m_next_map), p_data->m_load_complete_map, *(p_data->m_next_map_region));
	}

	//Logika zarzêdza harmonogramem zmian przemieszczania siê na mapach œwiata gry
	void CMapManager::ScheduleSetMap(const std::string *p_map_file, bool load_complete_map, const std::string *region)
	{
		SetMap(*p_map_file, true, *region);
	}

	//Metoda sprawdza i ustawiam mapê na odwiedzon¹ (gracz opuszcza mapê - nastêpna)
	void CMapManager::SetCurrentMapAsVisited()
	{
		//blokujê (luty 2015)
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
			p_map->CullVisibility(zero);//zerujemy widocznoœæ kafli znajduj¹cych siê w obszarze kamery
			p_map = NULL;
		}
		*/
		p_map = NULL;
	}

	//Metoda ³aduje i/lub udostepnia mapê z zasobów. Automatycznie czyœcie scenê
	bool CMapManager::SetMap(const std::string &map_file, bool load_complete_map, const std::string &region)
	{
        // mierzenie czasu zaladowania
		//blokujê (luty 2015)
        //sf::Clock timer;
        //timer.Reset();

//#ifndef __I_AM_TOXIC__
//		if ( p_map != NULL && p_map->GetFilename() == mapFile ){
//			if ( region != "" )
//			{
//              gPlayerManager.MovePlayersToRegion(region);
//            }
//			return true;
//		}
//#endif

		SetCurrentMapAsVisited();

//#ifdef __I_AM_TOXIC__
//		gResourceManager.LoadMap( mapFile );
//#endif
        // bo segfault przy ominieciu bossa..
        //gBossManager.ClearData();

		//jeszcze tego nie mam...
		///*
		p_map = gResourceManager.GetMap( map_file );
		if ( p_map )
		{
			fprintf( stderr, "mapFile = %s\n", map_file.c_str() );
			fprintf( stderr, "m_CurrentMap->GetFilename() = %s\n", p_map->getFilename().c_str() );
			//p_scene_manager->Initialize( p_map->GetSize() );
			           
			p_map->RespawnMapObjects(load_complete_map);
			
			int x = 0;//
			//p_map->RespawnDoodahs();
			//TUTAJ inicjujê wskaŸnik na mapê kolizji, a dok³adniej
			//ustawiam rozmiar mapy kolizji zgodnie w rozmiarem
			//wczytanej wczeœniej mapy œwiata..
			//bo tylko ta klasa (CMapManager)
			//mo¿e ³adowaæ mapy oraz nimi zarz¹dzaæ...
			//ale dlaczego razy cztery?
			//czy¿by quadtree?


			//na razie zablokujê mechanizm mapy kolizji...
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

	//Wirtualna metoda aktualizuj¹ca logikê mapy
	void CMapManager::frameStarted(float secondsPassed)
	{
		//sf::FloatRect cameraRect
		//(
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Left / mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Top / mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Right / mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Bottom / mapengine::TILE_SIZE
			//to odblokowaæ...poni¿ej
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Left,	//	/ mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Top,	//	/ mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Right,	//	/ mapengine::TILE_SIZE,
			//gGame.GetRenderWindow()->GetDefaultView().GetRect().Bottom	//	/ mapengine::TILE_SIZE

		//);

		//p_scene_manager->UpdateScene();
		//p_scene_manager->CullVisibility(cameraRect);

		//if (p_map)
		//	p_map->CullVisibility(cameraRect);//aktualizacja widocznoœci kafli

        //TODO: potencjalny bug: jeœli gra bedzie w trybie pause, ten czas nadal leci
        m_current_map_time_elapsed += secondsPassed;
		//diagnostyka
		//ok...dzia³a...
		//std::cout << m_current_map_time_elapsed << std::endl;
	}

	//Metoda zapisuje mapê
    bool CMapManager::SaveMap(const std::string &map_file)
	{
        if (p_map == NULL)
            return false;
        else
           return p_map->save(map_file);
    }

	/*
	//Metoda zapisuje pust¹ mapê
	void CMapManager::SaveEmptyMap(const std::string& filename, const sf::Vector2i& size)
	{
		std::stringstream ss;
		ss << "<map>\n";
		ss << "<version>" << mapengine::CURRENT_MAP_VERSION << "</version>\n";
		ss << "<width>" << size.x << "</width>\n";
		ss << "<height>" << size.y << "</height>\n";

		//do tego napisaæ coœ rozs¹dniejszego...jakoœ pod³o¿yæ defaultow¹ grafikê fabrycznego kafla
		//lub utworzyæ taki obiekt syntetycznie
		ss << "<tiletype code=\"aa\" image=\"data/maps/themes/test/rgrass.png\"/>\n";
		//do tego napisaæ coœ rozs¹dniejszego...

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
