//  _________________________________________
// | CPathManager.h - class definition       |
// | Jack Flower July 2012                   |
// |_________________________________________|
//

#ifndef H_PATH_MANAGER_JACK
#define H_PATH_MANAGER_JACK

#include <map>
#include <string>
#include "../../Singleton/CSingleton.h"

#define gPathManager fileutils::CPathManager::GetSingleton()


//I'm here...
//refaktoryzajca
//potrzebny machanizm �adowania konfiguracji z pliku xml
//jak w tym xml maj� by� uporz�dkowane dane?
// - jakie� drzewo?
// - jaka� struktura?
// - jakie� opakowanie?
// - jakie� wyliczenie?
//potrzebny mechanizm zabezpieczaj�cy przed b��dem odczytu danych
//z pliku xml - jaka� matoda default...
//czy plik game_config.xml, to dobre miejsce na umieszczenie
//�cie�ek? A mo�e lepiej w jakim� innym pliku?
//A mo�e we w�asnym formacie? A mo�e w pliku binarnym?
//	a n a l i z a

namespace fileutils
{

	///
	///Klasa reprezentuje organizacj� �cie�ek do plik�w
	///
	class CPathManager : public CSingleton<CPathManager>
	{
	public:
	
		///
		///Konstruktor
		///
		CPathManager(void);

		///
		///Destruktor
		///
		~CPathManager(void);

		///
		///Metoda zwracaj�ca �cie�k� do pliku std::string na podstawie std::string
		///
		///@param &str_name - sta�a referencja na obiekt klasy std::string
		///
		const std::string GetDataPath (const std::string &str_name);

		///
		///Metoda rejestruje �cie�k� do pliku na podstawie danych
		///
		///@param &data_str_name - sta�a referencja na obiekt klasy std::string
		///
		///@param &str_name - sta�a referencja na obiekt klasy std::string
		///
		bool Register (const std::string &data_str_name, const std::string &str_name);

		///
		///Metoda usuwa zas�b na podstawie identyfikatora
		///
		///@param &data_str_name - sta�a referencja na obiekt klasy std::string
		///
		void ReleaseDataPath(const std::string &data_str_name);

		///
		///Metoda usuwa zasoby
		///
		void ReleaseAllDataPath();

	protected:

		///
		///Wirtualna metoda czyszcz�ca singleton
		///
		virtual void Cleanup();

	private:

		//pojemnik na typy �cie�ek dost�pu do �adowania zasob�w - key std::string
		typedef std::map <std::string, std::string> DataPathMap;
		DataPathMap m_data_path_map;
	};
}//namespace fileutils
#endif //H_PATH_MANAGER_JACK
