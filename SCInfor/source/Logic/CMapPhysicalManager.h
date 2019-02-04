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
//fabryka mo�e produkowa� obiekty wy�ej wymienionych klasy

using namespace listener;
using namespace mapengine;
using namespace mapengine::groundwork;

namespace logic
{
	///
	///Klasa reprezentuje fabryk� produkuj�c� obiekty, b�d�ce obiektami
	///narz�dziowymi, np. pod�o�e, mapa kolizji (tarcie), mapa wp�ywu,
	///mapa strategii, nat�enie ruchu, g�sto�ci, a kt�re mog� by� tak�e
	///wy�wietlane na mapie, jak tekstury, tekstury programowo wygenerowane,
	///animacj�, etc...
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
		///Wirtualna metoda - czy�ci obiekty z kontenera
		///
		///@param secondsPassed - up�ywaj�cy czas
		///
		virtual void FrameStarted(float secondsPassed);

		///
		///Metoda tworzy obiekt klasy CMapPhysical i zwraca wska�nik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta�a referencja na obiekt klasy std::wstring
		///
		CMapPhysical* CreateMapPhysical(const std::wstring& unique_id = L"");

		///
		///Metoda tworzy obiekt klasy CGroundWork i zwraca wska�nik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta�a referencja na obiekt klasy std::wstring
		///
		CGroundWork* CreateGroundWork(const std::wstring& unique_id = L"");

		///
		///Metoda usuwa obiekt klasy CMapPhysical z kontenera
		///
		///@param *mapphysical - wska�nik na obiekt klasy CMapPhysical
		///
		void DestroyMapPhysical(CMapPhysical* mapphysical);
	    
		///
		///Metoda usuwa obiekt klasy CMapPhysical z kontenera
		///
		///@param &id_mapphysical - sta�a referencja na obiekt klasy std::wstring - unikalny identyfikator obiektu
		///
		void DestroyMapPhysical(const std::wstring& id_mapphysical);

		///
		///Metoda usuwa wszystkie obiekty z kontenera
		///
		///@param force_destroy_instantly - flaga, czy usun�� z kontenera wszystkie obiekty
		///
		void Clear(bool force_destroy_instantly = false);

		///
		///Metoda zwraca sta�a referencj� do kontenera z nazwami wszystkich zarejestorwanych obiekt�w CMapPhysical
		///
		const std::map<std::wstring, CMapPhysical*>& GetNamedMapPhysicals();

		///
		///Metoda zwraca sta�a referencj� do kontenera z wszystkimi wska�nikami zarejestorwanych obiekt�w CMapPhysical
		///
		const std::vector<CMapPhysical*>& GetMapPhysicals();

		///
		///Metoda zwraca wska�nik na obiekt klasy CMapPhysical z kontenera na podstawie identyfikatora
		///
		///@param &mapphysical_id - sta�a referencja na obiekt klasy std::wstring
		///
		CMapPhysical* GetMapPhysicalById(const std::wstring& mapphysical_id);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void Cleanup();

	private:

		//
		//Szablon metody tworzenia obiekt�w
		//
		template<class T> T* Create(const std::wstring &uniqueId);
	    
		std::map<std::wstring, CMapPhysical*>	m_named_mapphysicals;	//kontener <map> na nazwane obiekty klasy CMapPhysical
		std::vector<CMapPhysical*>				m_mapphysicals;			//kontener <vector> na wska�niki na obiekty klasy CMapPhysical

		//
		//Prywatna metoda sprawdzaj�ca jaki identyfikator nada� obiektowi przy utworzeniu
		//
		//@param &new_unique_id - referencja na obiekt klasy std::wstring
		//
		void CheckUniqueId(std::wstring& new_unique_id);
	};
}//namespace logic
#endif //H_MAP_PHYSICAL_MANAGER_JACK
