//  ________________________________________
// | CMapManager.h - class definition       |
// | Jack Flower June 2013.                 |
// |________________________________________|
//

#ifndef H_MAP_MANAGER_JACK
#define H_MAP_MANAGER_JACK

#include "../Game/Listener/IFrameListener.h"
#include "CMap.h"
#include "../Utilities/Singleton/CSingleton.h"
//To do...
//#include "SceneManager/CQuadTreeSceneManager.h"
//To do...
#include "CCollisionMap.h"
#include <string>
#include <vector>

#define gMapManager mapengine::CMapManager::GetSingleton()
#define gScene mapengine::CMapManager::GetSingleton().GetSceneManager()

//Mapy mo¿na ³adowaæ tylko przez gMapManager.SetMap( string ), która to metoda 
//automatycznie czyœci bie¿¹c¹ scenê i np. usuwa losow¹ iloœæ gniazd, ¿eby po ponownym 
//wejœciu na mapê by³o na niej mniej powtorów.


namespace mapengine
{
    //sta³a wartoœæ - czas ³adowania mapy, jeœli jest czas ³adowania mapy -  widoczny loading-screen
    const float LOADING_TOO_SLOW = 0.5f;

	///
	///Klasa reprezentuje mechanizm tworzenia i zarz¹dzania mapami œwiata
	///
	class CMapManager : public CSingleton<CMapManager>, IFrameListener
	{
	
	public:

		///
		///Konstruktor
		///
		CMapManager();

		///
		///Destruktor wirtualny
		///
		virtual ~CMapManager();

		//osobny plik!
		//opakowanie do struktury mechanizmu mapy
		struct NextMapData
		{
			const	std::string *m_next_map;
			const	std::string *m_next_map_region;
            bool	m_load_complete_map;
		};

		///
		///Metoda ustawia parametry mapy na podstawie sta³ego wskaŸnika void
		///
		///@param *data - sta³y wskaŸnik void
		///
		void SetMapFromData(const void *data);

		///
		///Metoda inline zwraca wskaŸnik na bie¿¹c¹ mapê - obiekt klasy CMap
		///
		inline CMap * GetCurrent() { return p_map; }

		///
		///Metoda inline zwraca referencjê na obiekt klasy CQuadTreeSceneManager - quadtree
		///
		//inline CQuadTreeSceneManager& GetSceneManager() { return *p_scene_manager; }

		///
		///Metoda inline zwraca wskaŸnik na obiekt klasy CCollisionMap - mapa kolizji
		///
		inline CCollisionMap * GetCollisionMap() { return p_collision_map; }
		
		///
		///Metoda inline zwraca czas up³ywaj¹cy na aktualnej mapie
		///
		inline float GetCurrentMapTimeElapsed() { return m_current_map_time_elapsed; }

		///
		///Logika zarzêdza harmonogramem zmian przemieszczania siê na mapach œwiata gry
		///
		///@param *p_map_file - sta³y wskaŸnik na std::string - nazwa pliku z map¹
		///
		///@param load_complete_map - flaga okreœlaj¹ca, czy mapa zosta³a za³adowana w ca³oœci
		///
		///@param *region - sta³y wskaŸnik na std::string - nazwa regionu
		///
		void ScheduleSetMap(const std::string *p_map_file, bool load_complete_map, const std::string *region = NULL);

		///
		///Metoda sprawdza i ustawiam mapê na odwiedzon¹ (gracz opuszcza mapê - nastêpna)
		///
		void SetCurrentMapAsVisited();

		///
		///Metoda ³aduje i/lub udostepnia mapê z zasobów. Automatycznie czyœcie scenê
		///
		///@param &map_file - referencja na std::string - nazwa pliku z map¹
		///
		///@param load_complete_map - flaga okreslaj¹ca, czy mapa zosta³a za³adowana w ca³oœci
		///
		///@param &region - sta³a referencja na std::string - nazwa regionu
		///
		bool SetMap(const std::string &map_file, bool load_complete_map, const std::string &region = "");

		///
		///Wirtualna metoda aktualizuj¹ca logikê mapy
		///
		///@param secondsPassed - up³ywaj¹cy czas
		///
		virtual void FrameStarted(float secondsPassed);

		///
		///Wirtualna metoda zwracaj¹ca stan zatrzymania gry
		///
		///@param pause_variant - wyliczenie wariantu zatrzymania gry
		///
		//virtual bool FramesDuringPause(EPauseVariant pause_variant) { return pause_variant == PAUSE_VARIANT_LOGIC_ONLY || pause_variant == PAUSE_VARIANT_PAUSE_MENU || pause_variant == PAUSE_VARIANT_LOADING; };

		///
		///Metoda zapisuje mapê
		///
		///@param &map_file - sta³a referncja na obiekt klasy std::string - nazwa pliku mapy
		///
        bool SaveMap(const std::string &map_file);

		///
		///Metoda zapisuje pust¹ mapê
		///
		///@param &filename - sta³a referncja na obiekt klasy std::string - nazwa pliku
		///
		///@param &size - sta³a referencja na obiekt klasy sf::Vector2i - rozmiar mapy
		///
		//void SaveEmptyMap(const std::string& filename, const sf::Vector2i& size);

	private:

		CMap*						p_map;						//wskaŸnik na obiekt klasy CMap
		//CQuadTreeSceneManager*		p_scene_manager;			//wskaŸnik na obiekt klasy CQuadTreeSceneManager (manager quadtree)
		CCollisionMap*				p_collision_map;			//wskaŸnik na obiekt klasy CCollisionMap - mapa kolizji
		std::vector<CMap*>			m_visited_maps;				//kontener na wskaŸniki do obiektów klasy CMap, które zosta³y ju¿ odwiedzone
        float						m_current_map_time_elapsed;	//czas up³ywaj¹cy na aktualnej mapie
        bool						m_hide_loading_screen;		//flaga sprawdzj¹ca warunek prezentacji grafiki podczas ³adowania zasobów gry

	};
}//namespace mapengine
#endif//H_MAP_MANAGER_JACK