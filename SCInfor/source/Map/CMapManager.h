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

//Mapy mo�na �adowa� tylko przez gMapManager.SetMap( string ), kt�ra to metoda 
//automatycznie czy�ci bie��c� scen� i np. usuwa losow� ilo�� gniazd, �eby po ponownym 
//wej�ciu na map� by�o na niej mniej powtor�w.


namespace mapengine
{
    //sta�a warto�� - czas �adowania mapy, je�li jest czas �adowania mapy -  widoczny loading-screen
    const float LOADING_TOO_SLOW = 0.5f;

	///
	///Klasa reprezentuje mechanizm tworzenia i zarz�dzania mapami �wiata
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
		///Metoda ustawia parametry mapy na podstawie sta�ego wska�nika void
		///
		///@param *data - sta�y wska�nik void
		///
		void SetMapFromData(const void *data);

		///
		///Metoda inline zwraca wska�nik na bie��c� map� - obiekt klasy CMap
		///
		inline CMap * GetCurrent() { return p_map; }

		///
		///Metoda inline zwraca referencj� na obiekt klasy CQuadTreeSceneManager - quadtree
		///
		//inline CQuadTreeSceneManager& GetSceneManager() { return *p_scene_manager; }

		///
		///Metoda inline zwraca wska�nik na obiekt klasy CCollisionMap - mapa kolizji
		///
		inline CCollisionMap * GetCollisionMap() { return p_collision_map; }
		
		///
		///Metoda inline zwraca czas up�ywaj�cy na aktualnej mapie
		///
		inline float GetCurrentMapTimeElapsed() { return m_current_map_time_elapsed; }

		///
		///Logika zarz�dza harmonogramem zmian przemieszczania si� na mapach �wiata gry
		///
		///@param *p_map_file - sta�y wska�nik na std::string - nazwa pliku z map�
		///
		///@param load_complete_map - flaga okre�laj�ca, czy mapa zosta�a za�adowana w ca�o�ci
		///
		///@param *region - sta�y wska�nik na std::string - nazwa regionu
		///
		void ScheduleSetMap(const std::string *p_map_file, bool load_complete_map, const std::string *region = NULL);

		///
		///Metoda sprawdza i ustawiam map� na odwiedzon� (gracz opuszcza map� - nast�pna)
		///
		void SetCurrentMapAsVisited();

		///
		///Metoda �aduje i/lub udostepnia map� z zasob�w. Automatycznie czy�cie scen�
		///
		///@param &map_file - referencja na std::string - nazwa pliku z map�
		///
		///@param load_complete_map - flaga okreslaj�ca, czy mapa zosta�a za�adowana w ca�o�ci
		///
		///@param &region - sta�a referencja na std::string - nazwa regionu
		///
		bool SetMap(const std::string &map_file, bool load_complete_map, const std::string &region = "");

		///
		///Wirtualna metoda aktualizuj�ca logik� mapy
		///
		///@param secondsPassed - up�ywaj�cy czas
		///
		virtual void FrameStarted(float secondsPassed);

		///
		///Wirtualna metoda zwracaj�ca stan zatrzymania gry
		///
		///@param pause_variant - wyliczenie wariantu zatrzymania gry
		///
		//virtual bool FramesDuringPause(EPauseVariant pause_variant) { return pause_variant == PAUSE_VARIANT_LOGIC_ONLY || pause_variant == PAUSE_VARIANT_PAUSE_MENU || pause_variant == PAUSE_VARIANT_LOADING; };

		///
		///Metoda zapisuje map�
		///
		///@param &map_file - sta�a referncja na obiekt klasy std::string - nazwa pliku mapy
		///
        bool SaveMap(const std::string &map_file);

		///
		///Metoda zapisuje pust� map�
		///
		///@param &filename - sta�a referncja na obiekt klasy std::string - nazwa pliku
		///
		///@param &size - sta�a referencja na obiekt klasy sf::Vector2i - rozmiar mapy
		///
		//void SaveEmptyMap(const std::string& filename, const sf::Vector2i& size);

	private:

		CMap*						p_map;						//wska�nik na obiekt klasy CMap
		//CQuadTreeSceneManager*		p_scene_manager;			//wska�nik na obiekt klasy CQuadTreeSceneManager (manager quadtree)
		CCollisionMap*				p_collision_map;			//wska�nik na obiekt klasy CCollisionMap - mapa kolizji
		std::vector<CMap*>			m_visited_maps;				//kontener na wska�niki do obiekt�w klasy CMap, kt�re zosta�y ju� odwiedzone
        float						m_current_map_time_elapsed;	//czas up�ywaj�cy na aktualnej mapie
        bool						m_hide_loading_screen;		//flaga sprawdzj�ca warunek prezentacji grafiki podczas �adowania zasob�w gry

	};
}//namespace mapengine
#endif//H_MAP_MANAGER_JACK