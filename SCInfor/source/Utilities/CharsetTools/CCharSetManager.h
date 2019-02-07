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
	///Klasa reprezentuje mechanizm transmisji i wy�wietlania dodatkowych znak�w spoza ANSII
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
		///Metoda inicjuje zbi�r znak�w
		///
		///@param & char_set_name - sta�a referencja na obiekt klasy std::string
		///
		void InitializeValidChars(const std::string & char_set_name);

		///
		///Metoda konweruje �a�cuch znak�w std::std::string na std::std::wstring
		///
		///@param string_input - �a�cuch wej�ciowy
		///
		std::wstring ReinterpretFromUTF8(std::string string_input);

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Metoda �aduj�ca dane z xml
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
		std::wstring					m_valid_chars;	//tablica zawieraj�ca polskie znaki diakrytyczne
	};
}//namespace charsettools
#endif//H_CHAR_SET_MANAGER_JACK
