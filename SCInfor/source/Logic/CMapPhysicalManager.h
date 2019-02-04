//  ______________________________________________
// | CMapPhysicalManager.h - class definition     |
// | Jack Flower - March 2015                     |
// |______________________________________________|
//

#ifndef H_MAP_PHYSICAL_MANAGER_JACK
#define H_MAP_PHYSICAL_MANAGER_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "../Game/Listener/IFrameListener.h"
#include <string>
#include <map>

#define gMapPhysicalManager CMapPhysicalManager::GetSingleton()

///
///Forward declaration
///
namespace mapengine
{
	class CMapPhysical;
	namespace groundwork
	{
		class CGroundWork;
	}
}
//fabryka mo¿e produkowaæ obiekty wy¿ej wymienionych klasy

using namespace listener;
using namespace mapengine;
using namespace mapengine::groundwork;

namespace logic
{
	///
	///Klasa reprezentuje fabrykê produkuj¹c¹ obiekty, bêd¹ce obiektami
	///narzêdziowymi, np. pod³o¿e, mapa kolizji (tarcie), mapa wp³ywu,
	///mapa strategii, natê¿enie ruchu, gêstoœci, a które mog¹ byæ tak¿e
	///wyœwietlane na mapie, jak tekstury, tekstury programowo wygenerowane,
	///animacjê, etc...
	///
	class CMapPhysicalManager : public CSingleton<CMapPhysicalManager>, public IFrameListener
	{
	public:

		///
		///Konstruktor
		///
		CMapPhysicalManager(void);

		///
		///Destruktor wirtualny
		///
		virtual ~CMapPhysicalManager(void);

		///
		///Wirtualna metoda - czyœci obiekty z kontenera
		///
		///@param secondsPassed - up³ywaj¹cy czas
		///
		virtual void FrameStarted(float secondsPassed);

		///
		///Metoda tworzy obiekt klasy CMapPhysical i zwraca wskaŸnik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta³a referencja na obiekt klasy std::wstring
		///
		CMapPhysical* CreateMapPhysical(const std::wstring& unique_id = L"");

		///
		///Metoda tworzy obiekt klasy CGroundWork i zwraca wskaŸnik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta³a referencja na obiekt klasy std::wstring
		///
		CGroundWork* CreateGroundWork(const std::wstring& unique_id = L"");

		///
		///Metoda usuwa obiekt klasy CMapPhysical z kontenera
		///
		///@param *mapphysical - wskaŸnik na obiekt klasy CMapPhysical
		///
		void DestroyMapPhysical(CMapPhysical* mapphysical);
	    
		///
		///Metoda usuwa obiekt klasy CMapPhysical z kontenera
		///
		///@param &id_mapphysical - sta³a referencja na obiekt klasy std::wstring - unikalny identyfikator obiektu
		///
		void DestroyMapPhysical(const std::wstring& id_mapphysical);

		///
		///Metoda usuwa wszystkie obiekty z kontenera
		///
		///@param force_destroy_instantly - flaga, czy usun¹æ z kontenera wszystkie obiekty
		///
		void Clear(bool force_destroy_instantly = false);

		///
		///Metoda zwraca sta³a referencjê do kontenera z nazwami wszystkich zarejestorwanych obiektów CMapPhysical
		///
		const std::map<std::wstring, CMapPhysical*>& GetNamedMapPhysicals();

		///
		///Metoda zwraca sta³a referencjê do kontenera z wszystkimi wskaŸnikami zarejestorwanych obiektów CMapPhysical
		///
		const std::vector<CMapPhysical*>& GetMapPhysicals();

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CMapPhysical z kontenera na podstawie identyfikatora
		///
		///@param &mapphysical_id - sta³a referencja na obiekt klasy std::wstring
		///
		CMapPhysical* GetMapPhysicalById(const std::wstring& mapphysical_id);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void Cleanup();

	private:

		//
		//Szablon metody tworzenia obiektów
		//
		template<class T> T* Create(const std::wstring &uniqueId);
	    
		std::map<std::wstring, CMapPhysical*>	m_named_mapphysicals;	//kontener <map> na nazwane obiekty klasy CMapPhysical
		std::vector<CMapPhysical*>				m_mapphysicals;			//kontener <vector> na wskaŸniki na obiekty klasy CMapPhysical

		//
		//Prywatna metoda sprawdzaj¹ca jaki identyfikator nadaæ obiektowi przy utworzeniu
		//
		//@param &new_unique_id - referencja na obiekt klasy std::wstring
		//
		void CheckUniqueId(std::wstring& new_unique_id);
	};
}//namespace logic
#endif //H_MAP_PHYSICAL_MANAGER_JACK
