//  ________________________________________
// | InfoManager.h - class definition       |
// | Jack Flower - April 2015               |
// |________________________________________|
//

#ifndef H_INFO_MANAGER_JACK
#define H_INFO_MANAGER_JACK

#include "../Utilities/Singleton/Singleton.h"
#include "../Game/Listener/IFrameListener.h"
#include <map>

#define gInfoManager InfoManager::GetSingleton()

///
///Forward declaration
///
namespace information
{
	class BaseInformation;
	class Information;
	
	namespace presentation
	{
		class Presentation;
	}
}
//fabryka może produkować obiekty wyżej wymienionych klasy

using namespace listener;
using namespace information;
using namespace information::presentation;

namespace infologic
{
	///
	///Klasa reprezentuje fabrykę produkującą obiekty, będące obiektami
	///informacyjnymi, np. licznik, tablica informacyjna, wskaźnik,
	///które to obiekty prezentują dane za pomocą dostępnych środków
	///multimedialnych (wykresy, wyświetlanie tekstu, paski stanu, etc...)
	///
	class InfoManager : public Singleton<InfoManager>, public IFrameListener
	{
	public:

		///
		///Konstruktor
		///
		InfoManager();

		///
		///Destruktor wirtualny
		///
		virtual ~InfoManager();

		///
		///Wirtualna metoda - aktualizuje obiekty kontenera
		///
		///@param secondsPassed - upływający czas
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Metoda tworzy obiekt klasy Information i zwraca wskaźnik na ten obiekt
		///
		///@param uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Information *createInformation(const std::wstring & unique_id = L"");

		///
		///Metoda tworzy obiekt klasy Presentation i zwraca wskaźnik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - stała referencja na obiekt klasy std::wstring
		///
		Presentation *createPresentation(const std::wstring & unique_id = L"");

		///
		///Metoda usuwa obiekt klasy Information z kontenera
		///
		///@param *mapinformation - wskaźnik na obiekt klasy Information
		///
		void destroyInformation(BaseInformation *mapinformation);
	    
		///
		///Metoda usuwa obiekt klasy Information z kontenera
		///
		///@param id_mapinformation - stała referencja na obiekt klasy std::wstring - unikalny identyfikator obiektu
		///
		void destroyInformation(const std::wstring & id_mapinformation);

		///
		///Metoda usuwa wszystkie obiekty z kontenera
		///
		///@param force_destroy_instantly - flaga, czy usunąć z kontenera wszystkie obiekty
		///
		void clear(bool force_destroy_instantly = false);

		///
		///Metoda zwraca stałą referencję do kontenera z nazwami wszystkich zarejestrowanych obiektów Information
		///
		const std::map<std::wstring, BaseInformation*> & getNamedMapInformation();

		///
		///Metoda zwraca stałą referencję do kontenera ze wskaźnikami zarejestrowanych obiektów Information
		///
		const std::vector<BaseInformation*> & getMapInformation();

		///
		///Metoda zwraca wskaźnik na obiekt klasy Information z kontenera na podstawie identyfikatora
		///
		///@param information_id - stała referencja na obiekt klasy std::wstring
		///
		BaseInformation *getMapInformationById(const std::wstring & information_id);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void cleanup();

	private:

		//
		//Szablon metody tworzenia obiektów
		//
		template<class T> T* create(const std::wstring &uniqueId);
	    
		std::map<std::wstring, BaseInformation*> m_named_map_information; //kontener <map> na nazwane obiekty klasy Information
		std::vector<BaseInformation*> m_map_information; //kontener <vector> na wskaźniki na obiekty klasy Information

		//
		//Prywatna metoda sprawdzająca jaki identyfikator nadać obiektowi przy utworzeniu
		//
		//@param new_unique_id - referencja na obiekt klasy std::wstring
		//
		void checkUniqueId(std::wstring & new_unique_id);

	};
}//namespace infologic
#endif//H_INFO_MANAGER_JACK
