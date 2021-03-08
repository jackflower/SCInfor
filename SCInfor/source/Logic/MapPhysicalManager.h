//  _____________________________________________
// | MapPhysicalManager.h - class definition     |
// | Jack Flower - March 2015                    |
// |_____________________________________________|
//

#ifndef H_MAP_PHYSICAL_MANAGER_JACK
#define H_MAP_PHYSICAL_MANAGER_JACK

#include "../Utilities/Singleton/Singleton.h"
#include "../Game/Listener/IFrameListener.h"
#include <string>
#include <map>

#define gMapPhysicalManager MapPhysicalManager::GetSingleton()

///
///Forward declaration
///
namespace mapengine
{
	class MapPhysical;
	namespace groundwork
	{
		class GroundWork;
	}
}
//fabryka może produkować obiekty wyżej wymienionych klasy

using namespace listener;
using namespace mapengine;
using namespace mapengine::groundwork;

namespace logic
{
	///
	///Klasa reprezentuje fabrykę produkującą obiekty, będące obiektami
	///narzędziowymi, np. podłoże, mapa kolizji (tarcie), mapa wpływu,
	///mapa strategii, natężenie ruchu, gęstości, a które mogą być także
	///wyświetlane na mapie, jak tekstury, tekstury programowo wygenerowane,
	///animację, etc...
	///
	class MapPhysicalManager : public Singleton<MapPhysicalManager>, public IFrameListener
	{
	public:

		///
		///Konstruktor
		///
		MapPhysicalManager();

		///
		///Destruktor wirtualny
		///
		virtual ~MapPhysicalManager();

		///
		///Wirtualna metoda - czyści obiekty z kontenera
		///
		///@param secondsPassed - upływający czas
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Metoda tworzy obiekt klasy MapPhysical i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		MapPhysical *createMapPhysical(const std::wstring & unique_id = L"");

		///
		///Metoda tworzy obiekt klasy GroundWork i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		GroundWork *createGroundWork(const std::wstring & unique_id = L"");

		///
		///Metoda usuwa obiekt klasy MapPhysical z kontenera
		///
		///@param *mapphysical - wskaźnik na obiekt klasy MapPhysical
		///
		void destroyMapPhysical(MapPhysical *mapphysical);
	    
		///
		///Metoda usuwa obiekt klasy MapPhysical z kontenera
		///
		///@param id_mapphysical - stała referencja na obiekt klasy std::wstring - unikalny identyfikator obiektu
		///
		void destroyMapPhysical(const std::wstring & id_mapphysical);

		///
		///Metoda usuwa wszystkie obiekty z kontenera
		///
		///@param force_destroy_instantly - flaga, czy usunąć z kontenera wszystkie obiekty
		///
		void clear(bool force_destroy_instantly = false);

		///
		///Metoda zwraca stała referencję do kontenera z nazwami wszystkich zarejestorwanych obiektów MapPhysical
		///
		const std::map<std::wstring, MapPhysical*> & getNamedMapPhysicals();

		///
		///Metoda zwraca stała referencję do kontenera z wszystkimi wskaźnikami zarejestorwanych obiektów MapPhysical
		///
		const std::vector<MapPhysical*> & getMapPhysicals();

		///
		///Metoda zwraca wskaźnik na obiekt klasy MapPhysical z kontenera na podstawie identyfikatora
		///
		///@param mapphysical_id - stała referencja na obiekt klasy std::wstring
		///
		MapPhysical *getMapPhysicalById(const std::wstring & mapphysical_id);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void cleanup();

	private:

		//
		//Szablon metody tworzenia obiektów
		//
		template<class T> T* create(const std::wstring & uniqueId);
	    
		std::map<std::wstring, MapPhysical*> m_named_mapphysicals; //kontener <map> na nazwane obiekty klasy MapPhysical
		std::vector<MapPhysical*> m_mapphysicals; //kontener <vector> na wskaźniki na obiekty klasy MapPhysical

		//
		//Prywatna metoda sprawdzająca jaki identyfikator nadać obiektowi przy utworzeniu
		//
		//@param new_unique_id - referencja na obiekt klasy std::wstring
		//
		void CheckUniqueId(std::wstring & new_unique_id);
	};
}//namespace logic
#endif //H_MAP_PHYSICAL_MANAGER_JACK
