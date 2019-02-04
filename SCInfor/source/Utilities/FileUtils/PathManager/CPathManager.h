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
//potrzebny machanizm ³adowania konfiguracji z pliku xml
//jak w tym xml maj¹ byæ uporz¹dkowane dane?
// - jakieœ drzewo?
// - jakaœ struktura?
// - jakieœ opakowanie?
// - jakieœ wyliczenie?
//potrzebny mechanizm zabezpieczaj¹cy przed b³êdem odczytu danych
//z pliku xml - jakaœ matoda default...
//czy plik game_config.xml, to dobre miejsce na umieszczenie
//œcie¿ek? A mo¿e lepiej w jakimœ innym pliku?
//A mo¿e we w³asnym formacie? A mo¿e w pliku binarnym?
//	a n a l i z a

namespace fileutils
{

	///
	///Klasa reprezentuje organizacjê œcie¿ek do plików
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
		///Metoda zwracaj¹ca œcie¿kê do pliku std::string na podstawie std::string
		///
		///@param &str_name - sta³a referencja na obiekt klasy std::string
		///
		const std::string GetDataPath (const std::string &str_name);

		///
		///Metoda rejestruje œcie¿kê do pliku na podstawie danych
		///
		///@param &data_str_name - sta³a referencja na obiekt klasy std::string
		///
		///@param &str_name - sta³a referencja na obiekt klasy std::string
		///
		bool Register (const std::string &data_str_name, const std::string &str_name);

		///
		///Metoda usuwa zasób na podstawie identyfikatora
		///
		///@param &data_str_name - sta³a referencja na obiekt klasy std::string
		///
		void ReleaseDataPath(const std::string &data_str_name);

		///
		///Metoda usuwa zasoby
		///
		void ReleaseAllDataPath();

	protected:

		///
		///Wirtualna metoda czyszcz¹ca singleton
		///
		virtual void Cleanup();

	private:

		//pojemnik na typy œcie¿ek dostêpu do ³adowania zasobów - key std::string
		typedef std::map <std::string, std::string> DataPathMap;
		DataPathMap m_data_path_map;
	};
}//namespace fileutils
#endif //H_PATH_MANAGER_JACK
