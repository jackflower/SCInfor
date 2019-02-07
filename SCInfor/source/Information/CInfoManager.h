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
//fabryka mo¿e produkowaæ obiekty wy¿ej wymienionych klasy

using namespace listener;
using namespace information;
using namespace information::presentation;

namespace infologic
{
	///
	///Klasa reprezentuje fabrykê produkuj¹c¹ obiekty, bêd¹ce obiektami
	///informacyjnymi, np. licznik, tablica informacyjna, wskaŸnik,
	///które to obiekty prezentuj¹ dane za pomoc¹ dostêpnych œrodków
	///multimedialnych (wykresy, wyœwietlanie tekstu, paski stanu, etc...)
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
		///Wirtualna metoda - czyœci obiekty z kontenera
		///
		///@param secondsPassed - up³ywaj¹cy czas
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Metoda tworzy obiekt klasy CInformation i zwraca wskaŸnik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta³a referencja na obiekt klasy std::wstring
		///
		CInformation* CreateInformation(const std::wstring& unique_id = L"");

		///
		///Metoda tworzy obiekt klasy CPresentation i zwraca wskaŸnik na ten obiekt
		///
		///@param &uniqueId - unikalny identyfikator - sta³a referencja na obiekt klasy std::wstring
		///
		CPresentation* CreatePresentation(const std::wstring& unique_id = L"");

		///
		///Metoda usuwa obiekt klasy IInformation z kontenera
		///
		///@param *mapinformation - wskaŸnik na obiekt klasy IInformation
		///
		void DestroyInformation(IInformation* mapinformation);
	    
		///
		///Metoda usuwa obiekt klasy IInformation z kontenera
		///
		///@param &id_mapinformation - sta³a referencja na obiekt klasy std::wstring - unikalny identyfikator obiektu
		///
		void DestroyInformation(const std::wstring& id_mapinformation);

		///
		///Metoda usuwa wszystkie obiekty z kontenera
		///
		///@param force_destroy_instantly - flaga, czy usun¹æ z kontenera wszystkie obiekty
		///
		void Clear(bool force_destroy_instantly = false);

		///
		///Metoda zwraca sta³a referencjê do kontenera z nazwami wszystkich zarejestrowanych obiektów IInformation
		///
		const std::map<std::wstring, IInformation*>& GetNamedMapInformation();

		///
		///Metoda zwraca sta³a referencjê do kontenera z wszystkimi wskaŸnikami zarejestrowanych obiektów IInformation
		///
		const std::vector<IInformation*>& GetMapInformation();

		///
		///Metoda zwraca wskaŸnik na obiekt klasy IInformation z kontenera na podstawie identyfikatora
		///
		///@param &information_id - sta³a referencja na obiekt klasy std::wstring
		///
		IInformation* GetMapInformationById(const std::wstring& information_id);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void Cleanup();

	private:

		//
		//Szablon metody tworzenia obiektów
		//
		template<class T> T* create(const std::wstring &uniqueId);
	    
		std::map<std::wstring, IInformation*>	m_named_map_information;	//kontener <map> na nazwane obiekty klasy IInformation
		std::vector<IInformation*>				m_map_information;			//kontener <vector> na wskaŸniki na obiekty klasy IInformation

		//
		//Prywatna metoda sprawdzaj¹ca jaki identyfikator nadaæ obiektowi przy utworzeniu
		//
		//@param &new_unique_id - referencja na obiekt klasy std::wstring
		//
		void CheckUniqueId(std::wstring& new_unique_id);

	};
}//namespace infologic
#endif//H_INFO_MANAGER_JACK
