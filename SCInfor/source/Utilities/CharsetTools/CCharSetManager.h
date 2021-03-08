//  ____________________________________________
// | CCharSetManager.h - class definition       |
// | Jack Flower - May 2015                     |
// |____________________________________________|
//

#ifndef H_CHAR_SET_MANAGER_JACK
#define H_CHAR_SET_MANAGER_JACK

#include "CCharsetTranslator.h"
#include "../../Utilities/Singleton/Singleton.h"
#include "../../XML/Xml.h"
#include <vector>

#define gCharSetManager CCharSetManager::GetSingleton()

using namespace xml;

namespace charsettools
{
	///
	///Klasa reprezentuje mechanizm transmisji i wy�wietlania dodatkowych znak�w spoza ANSII
	///
	class CCharSetManager : public Singleton<CCharSetManager>
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
		///@param &xml - referencja na obiekt klasy Xml
		///
		bool load(Xml &xml);

		///
		///Wirtualny interfejs - implementacja
		///
		virtual void cleanup();

	private:

		CCharsetTranslator				m_translator;	//opakowanie danych - klasa pomocnicza
		std::vector<CCharsetTranslator> m_translators;	//kontener na obiekty klasy CCharsetTranslator
		std::wstring					m_valid_chars;	//tablica zawieraj�ca polskie znaki diakrytyczne
	};
}//namespace charsettools
#endif//H_CHAR_SET_MANAGER_JACK
