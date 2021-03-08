//  _______________________________________
// | MapManager.h - class definition       |
// | Jack Flower June 2013                 |
// |_______________________________________|
//

#ifndef H_MAP_MANAGER_JACK
#define H_MAP_MANAGER_JACK

#include "Map.h"
#include "../Game/Listener/IFrameListener.h"
#include "../Utilities/Singleton/Singleton.h"
//#include "SceneManager/CQuadTreeSceneManager.h"
#include "CollisionMap.h"
#include <string>
#include <vector>

#define gMapManager mapengine::MapManager::GetSingleton()
#define gScene mapengine::MapManager::GetSingleton().GetSceneManager()

//Mapy można ładować tylko przez gMapManager.SetMap( string ), która to metoda 
//automatycznie czyści bieżącą scenę i np. usuwa losową ilość gniazd, żeby po ponownym 
//wejściu na mapę było na niej mniej powtorów.


namespace mapengine
{
    //stała wartość - czas ładowania mapy, jeśli jest czas ładowania mapy -  widoczny loading-screen
    const float LOADING_TOO_SLOW = 0.5f;

	///
	///Klasa reprezentuje mechanizm tworzenia i zarządzania mapami świata
	///
	class MapManager : public Singleton<MapManager>, IFrameListener
	{
	
	public:

		///
		///Konstruktor
		///
		MapManager();

		///
		///Destruktor wirtualny
		///
		virtual ~MapManager();

		//opakowanie do struktury mechanizmu mapy
		struct NextMapData
		{
			const std::string *m_next_map;
			const std::string *m_next_map_region;
            bool m_load_complete_map;
		};

		///
		///Metoda ustawia parametry mapy na podstawie stałego wskaźnika void
		///
		///@param *data - stały wskaźnik void
		///
		void setMapFromData(const void *data);

		///
		///Metoda inline zwraca wskaźnik na bieżącą mapę - obiekt klasy Map
		///
		inline Map *getCurrent()
		{
			return p_map;
		}

		///
		///Metoda inline zwraca referencję na obiekt klasy CQuadTreeSceneManager - quadtree
		///
		//inline CQuadTreeSceneManager& GetSceneManager() { return *p_scene_manager; }

		///
		///Metoda inline zwraca wskaźnik na obiekt klasy CollisionMap - mapa kolizji
		///
		inline CollisionMap *getCollisionMap()
		{
			return p_collision_map;
		}
		
		///
		///Metoda inline zwraca czas upływający na aktualnej mapie
		///
		inline float getCurrentMapTimeElapsed()
		{
			return m_current_map_time_elapsed;
		}

		///
		///Logika zarzędza harmonogramem zmian przemieszczania się na mapach świata gry
		///
		///@param *p_map_file - stały wskaźnik na std::string - nazwa pliku z mapą
		///
		///@param load_complete_map - flaga określająca, czy mapa została załadowana w całości
		///
		///@param *region - stały wskaźnik na std::string - nazwa regionu
		///
		void scheduleSetMap(const std::string *p_map_file, bool load_complete_map, const std::string *region = nullptr);

		///
		///Metoda sprawdza i ustawiam mapę na odwiedzoną (gracz opuszcza mapę - następna)
		///
		void setCurrentMapAsVisited();

		///
		///Metoda ładuje i/lub udostepnia mapę z zasobów. Automatycznie czyście scenę
		///
		///@param map_file - referencja na std::string - nazwa pliku z mapą
		///
		///@param load_complete_map - flaga okreslająca, czy mapa została załadowana w całości
		///
		///@param region - stała referencja na std::string - nazwa regionu
		///
		bool setMap(const std::string & map_file, bool load_complete_map, const std::string & region = "");

		///
		///Wirtualna metoda aktualizująca logikę mapy
		///
		///@param secondsPassed - upływający czas
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Wirtualna metoda zwracająca stan zatrzymania gry
		///
		///@param pause_variant - wyliczenie wariantu zatrzymania gry
		///
		//virtual bool FramesDuringPause(EPauseVariant pause_variant) { return pause_variant == PAUSE_VARIANT_LOGIC_ONLY || pause_variant == PAUSE_VARIANT_PAUSE_MENU || pause_variant == PAUSE_VARIANT_LOADING; };

		///
		///Metoda zapisuje mapę
		///
		///@param map_file - stała referncja na obiekt klasy std::string - nazwa pliku mapy
		///
        bool saveMap(const std::string & map_file);

		///
		///Metoda zapisuje pustą mapę
		///
		///@param filename - stała referncja na obiekt klasy std::string - nazwa pliku
		///
		///@param size - stała referencja na obiekt klasy sf::Vector2i - rozmiar mapy
		///
		//void SaveEmptyMap(const std::string & filename, const sf::Vector2i & size);

	private:

		Map *p_map; //wskaźnik na obiekt klasy Map
		//CQuadTreeSceneManager *p_scene_manager; //wskaźnik na obiekt klasy CQuadTreeSceneManager (manager quadtree)
		CollisionMap *p_collision_map; //wskaźnik na obiekt klasy CollisionMap - mapa kolizji
		std::vector<Map*> m_visited_maps; //kontener na wskaźniki do obiektów klasy Map, które zostały już odwiedzone
        float m_current_map_time_elapsed; //czas upływający na aktualnej mapie
        bool m_hide_loading_screen; //flaga sprawdzająca warunek prezentacji grafiki podczas ładowania zasobów gry

	};
}//namespace mapengine
#endif//H_MAP_MANAGER_JACK
