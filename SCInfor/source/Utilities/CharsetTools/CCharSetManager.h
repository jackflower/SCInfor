//  ____________________________________________
// | CCharSetManager.h - class definition       |
// | Jack Flower - May 2015                     |
// |____________________________________________|
//

#ifndef H_CHAR_SET_MANAGER_JACK
#define H_CHAR_SET_MANAGER_JACK

#include "CCharsetTranslator.h"
#include "../../Utilities/Singleton/CSingleton.h"
#include "../../XML/CXml.h"
#include <vector>

#define gCharSetManager CCharSetManager::GetSingleton()

using namespace xml;

namespace charsettools
{
	///
	///Klasa reprezentuje mechanizm transmisji i wyœwietlania dodatkowych znaków spoza ANSII
	///
	class CCharSetManager : public CSingleton<CCharSetManager>
	{
	public:

		///
		///Konstruktor
		///
		CCharSetManager();

		///
		///Destruktor
		///
		virtual ~CCharSetManager();

		///
		///Metoda inicjuje zbiór znaków
		///
		///@param & char_set_name - sta³a referencja na obiekt klasy std::string
		///
		void InitializeValidChars(const std::string & char_set_name);

		///
		///Metoda konweruje ³añcuch znaków std::std::string na std::std::wstring
		///
		///@param string_input - ³añcuch wejœciowy
		///
		std::wstring ReinterpretFromUTF8(std::string string_input);

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void Cleanup();

	private:

		CCharsetTranslator				m_translator;	//opakowanie danych - klasa pomocnicza
		std::vector<CCharsetTranslator> m_translators;	//kontener na obiekty klasy CCharsetTranslator
		std::wstring					m_valid_chars;	//tablica zawieraj¹ca polskie znaki diakrytyczne
	};
}//namespace charsettools
#endif//H_CHAR_SET_MANAGER_JACK
