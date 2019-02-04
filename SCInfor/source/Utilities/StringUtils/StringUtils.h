/*
 ____________________________________________________________________
| StringUtils.h - modu³ zawierajacy funkcje operuj¹ce na ³añcuchach. |
| Jack Flower October 2011.                                          |
|____________________________________________________________________|

*/

#ifndef H_STRING_UTILS_JACK
#define H_STRING_UTILS_JACK

#include <sstream>
#include <string>
#include <vector>

namespace stringutils
{

	///hack - kompatybilnosc minGW - g++
	#ifdef _WIN32
	#define vswprintf( buf, len, text, args) _vsnwprintf( buf, len, text, args )
	#endif

	#if !defined (get16bits)
	#define get16bits(d) ((((unsigned int)(((const unsigned char *)(d))[1])) << 8)+(unsigned int)(((const unsigned char *)(d))[0]))
	#endif

	//http://www.azillionmonkeys.com/qed/hash.html
	//Dla zaawansowanych - zainteresowaæ siê funkcjami tablicami/funkcjami haszuj¹cymi
	///
	///Funkcja hash - generuje unikalne wartoœci typu unsigned long long 
	///
	///param &str - sta³a referencja na obiekt std::string
	///
	unsigned long long GetStringHash( const std::string &str );

	///
	///Funkcja szablonowa sprawdzaj¹ca, czy mo¿na dokonaæ konwersji typu szablonowego
	///
	template< class T>
	inline bool FromString(const std::string& str, T& value)
	{
		std::istringstream streamIn(str);
		return !(streamIn >> value).fail();
	}

	///
	///Funkcja szablonowa konwertuj¹ca typ szablonowy na std::wstring
	///
	template< class type>
	inline std::wstring ToWString(const type & value)
	{
		std::wostringstream streamOut;
		streamOut << value;
		return streamOut.str();
	}

	///
	///Funkcja konwertuje std::string na std::wstring
	///
	inline std::wstring ConvertToWString(std::string string_param)
	{
		return std::wstring( string_param.begin(), string_param.end() );
	}

	///
	///Funkcja konwertuje std::string na std::wstring
	///
	inline std::string ConvertToString(std::wstring string_param)
	{
		return std::string(string_param.begin(), string_param.end());
	}

	///
	///Funkcja szablonowa konwertuj¹ca typ szablonowy na std::string
	///
	template <class T>
	inline std::string ToString(const T i)
	{
		std::stringstream ss;
		std::string temp;
		ss << i;
		ss >> temp;
		return temp;
	}

	///
	///Funkcja zamienia std::string na podany typ dla szablonu
	///
	///@param &str - sta³a referencja na obiekt klasy std::string
	///
	template< class type>
	inline type Parse(const std::string& str)
	{
		std::istringstream streamIn(str);
		type ret;
		streamIn >> ret;
	    return ret;
	}

	///
	///Funkcja zamienia std::string na podany typ dla szablonu
	///
	///@param &str - sta³a referencja na obiekt klasy std::wstring
	///
	template< class type>
	inline type Parse(const std::wstring& str)
	{
		std::wistringstream streamIn(str);
		type ret;
		streamIn >> ret;
		return ret;
	}

	///
	///Funckja zwraca kod znaku
	///
	inline int CharToCode(char c)
	{ 
		return c - 'a';
	}

	///
	///
	///
	std::wstring *WSplit(std::wstring &input, wchar_t s, int *out_cnt);

	///
	///
	///
	std::string ExtractParam(const std::string & input, const std::string & tag, int words = 1);

	///
	///Funkcja zwraca sparsowany wektor
	///
	///@param &input - sta³a referencja na obiekt klasy std::string
	///
	///@param separator - separator u¿ywany w ³añcuchu std::string
	///
	//usage:
	//input		=>	[1] "Ala, ma, kota";
	//output	=>	[3]("Ala"," ma"," kota")
	std::vector<std::string> Tokenize(const std::string & input, char separator = ',');

	///
	///Funckja zwraca std::string na podstawie parametru bool
	///Wykorzystywana do zapisu s³ów "true", "false" w plikach xml
	///
	///@param param - flaga - obiekt typu bool
	///
	std::string BoolToString(bool param);

	///
	///Funkcja usuwa bia³e znaki
	///
	std::string TrimWhiteSpaces( const std::string &toTrim );

	///
	///Funkcja usuwa bia³e znaki
	///
	std::wstring TrimWhiteSpacesW( const std::wstring &toTrim );

	///
	///Metoda generuje wszystkie kombinacje elementów zbioru
	///
	///@param &chars - referencja na tablicê char
	///
	///@param maxLength - maksymalna d³ugoœæ elementów w kombinacji
	///
	///@param has - wartoœæ haszuj¹ca - liczb aca³kowita
	///
	std::string GenerateCode(std::vector<char> &chars,int maxLength,int hash);

	///
	///
	///
	void Exclude(const std::string& s, char ch, std::vector<std::string>& out);

	///
	///
	///
	std::string ToUpper(const std::string& s);

}//namespace stringutils
#endif //H_STRING_UTILS_JACK
