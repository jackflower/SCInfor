//  _________________________________________
// | CInfoManager.h - class definition       |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#ifndef H_INFO_MANAGER_JACK
#define H_INFO_MANAGER_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "../Game/Listener/IFrameListener.h"
#include <string>
#include <map>

#define gInfoManager CInfoManager::GetSingleton()

///
///Forward declaration
///
namespace information
{
	class IInformation;
	class CInformation;
	
	namespace presentation
	{
		class CPresentation;
	}
}
//fabryka mo�e produkowa� obiekty wy�ej wymienionych klasy

using namespace listener;
using namespace information;
using namespace information::presentation;

namespace infologic
{
	///
	///Klasa reprezentuje fabryk� produkuj�c� obiekty, b�d�ce obiektami
	///informacyjnymi, np. licznik, tablica informacyjna, wska�nik,
	///kt�re to obiekty prezentuj� dane za pomoc� dost�pnych �rodk�w
	///multimedialnych (wykresy, wy�wietlanie tekstu, paski stanu, etc...)
	///
	class CInfoManager : public CSingleton<CInfoManager>, public IFrameListener
	{
	public:

		///
		///Konstruktor
		///
		CInfoManager();

		///
		///Destruktor wirtualny
		///
		virtual ~CInfoManager();

		///
		///Wirtualna metoda - czy�ci obiekty z kontenera
		///
		///@param secondsPassed - up�ywaj�cy czas
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Metoda tworzy obiekt klasy CInformation i zwraca wska�nik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta�a referencja na obiekt klasy std::wstring
		///
		CInformation* CreateInformation(const std::wstring& unique_id = L"");

		///
		///Metoda tworzy obiekt klasy CPresentation i zwraca wska�nik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta�a referencja na obiekt klasy std::wstring
		///
		CPresentation* CreatePresentation(const std::wstring& unique_id = L"");

		///
		///Metoda usuwa obiekt klasy IInformation z kontenera
		///
		///@param *mapinformation - wska�nik na obiekt klasy IInformation
		///
		void DestroyInformation(IInformation* mapinformation);
	    
		///
		///Metoda usuwa obiekt klasy IInformation z kontenera
		///
		///@param &id_mapinformation - sta�a referencja na obiekt klasy std::wstring - unikalny identyfikator obiektu
		///
		void DestroyInformation(const std::wstring& id_mapinformation);

		///
		///Metoda usuwa wszystkie obiekty z kontenera
		///
		///@param force_destroy_instantly - flaga, czy usun�� z kontenera wszystkie obiekty
		///
		void Clear(bool force_destroy_instantly = false);

		///
		///Metoda zwraca sta�a referencj� do kontenera z nazwami wszystkich zarejestrowanych obiekt�w IInformation
		///
		const std::map<std::wstring, IInformation*>& GetNamedMapInformation();

		///
		///Metoda zwraca sta�a referencj� do kontenera z wszystkimi wska�nikami zarejestrowanych obiekt�w IInformation
		///
		const std::vector<IInformation*>& GetMapInformation();

		///
		///Metoda zwraca wska�nik na obiekt klasy IInformation z kontenera na podstawie identyfikatora
		///
		///@param &information_id - sta�a referencja na obiekt klasy std::wstring
		///
		IInformation* GetMapInformationById(const std::wstring& information_id);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void Cleanup();

	private:

		//
		//Szablon metody tworzenia obiekt�w
		//
		template<class T> T* create(const std::wstring &uniqueId);
	    
		std::map<std::wstring, IInformation*>	m_named_map_information;	//kontener <map> na nazwane obiekty klasy IInformation
		std::vector<IInformation*>				m_map_information;			//kontener <vector> na wska�niki na obiekty klasy IInformation

		//
		//Prywatna metoda sprawdzaj�ca jaki identyfikator nada� obiektowi przy utworzeniu
		//
		//@param &new_unique_id - referencja na obiekt klasy std::wstring
		//
		void CheckUniqueId(std::wstring& new_unique_id);

	};
}//namespace infologic
#endif//H_INFO_MANAGER_JACK
