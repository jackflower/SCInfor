/*
 ______________________________________________________________________
| StringUtils.cpp - modu³ zawierajacy funkcje operuj¹ce na ³añcuchach. |
| Jack Flower October 2011.                                            |
|______________________________________________________________________|

*/

#include "StringUtils.h"

namespace stringutils
{
	//Funkcja hash - generuje unikalne wartoœci typu unsigned long long
	unsigned long long GetStringHash( const std::string & str )
	{
		const char * data = str.c_str();
		unsigned int len = (unsigned int)str.length();

		unsigned long long hash = len, tmp;
		int rem;

		if (len <= 0 || data == nullptr) return 0;

		rem = len & 3;
		len >>= 2;

		for (;len > 0; len--)
		{
			hash  += get16bits (data);
			tmp    = (get16bits (data+2) << 11) ^ hash;
			hash   = (hash << 16) ^ tmp;
			data  += 2*sizeof (unsigned short);
			hash  += hash >> 11;
		}

		switch (rem) 
		{
		case 3: hash += get16bits (data);
			hash ^= hash << 16;
			hash ^= data[sizeof (unsigned short)] << 18;
			hash += hash >> 11;
			break;
		case 2: hash += get16bits (data);
			hash ^= hash << 11;
			hash += hash >> 17;
			break;
		case 1: hash += *data;
			hash ^= hash << 10;
			hash += hash >> 1;
		}

		//mieszanie poprzez przesuwanie bitowe (prawdopodobnie daje unikalnoœæ)
		hash ^= hash << 3;
		hash += hash >> 5;
		hash ^= hash << 4;
		hash += hash >> 17;
		hash ^= hash << 25;
		hash += hash >> 6;

		return hash + 0x10000000;
	}

	//
	std::wstring *WSplit(std::wstring &input, wchar_t s, int *out_cnt)
	{
		wchar_t *cstr, *p;
		std::wstring *result;
		size_t count = 1, len = input.size()+1;

		cstr = new wchar_t [len];
		wcscpy (cstr, input.c_str());

		for (unsigned int i = 0; i < len; i++)
			if (cstr[i] == s)
				count++;
		result = new std::wstring[count];

		p = cstr;
		int idx = 0;

		for (unsigned int i = 0; i < len; i++)
			if (cstr[i] == s)
			{
				cstr[i] = '\0';
				result[idx] = *(new std::wstring(p));
				idx++;
				p=cstr + i + 1;
			}
			
			result[idx] = *(new std::wstring(p));
	
			if (out_cnt != nullptr)
				*out_cnt = (int)count;
   
			return result;
	}


	//
	std::string ExtractParam( const std::string & input, const std::string & tag, int words)
	{
		size_t posOfTag = input.find( tag );
		if (posOfTag == std::string::npos)
			return "";

		if (words == 0)
		{
			return TrimWhiteSpaces(input.substr(posOfTag + tag.length()));
		}

		size_t start = posOfTag + tag.length();
		size_t end = start;
		bool isInWhiteSpace = false;
		if(input[end] == ' ' || input[end] == (char)9 || input[end] == (char)10 || input[end] == (char)13)
			isInWhiteSpace = true;

		for(; end < input.length(); end++)
		{
			if(input[end] == ' ' || input[end] == (char)9 || input[end] == (char)10 || input[end] == (char)13)
			{
				if (isInWhiteSpace)
					continue;
				else
				{
					isInWhiteSpace = true;
					words--;
					if (words == 0)
					{
						size_t length = end - start;
						return stringutils::TrimWhiteSpaces(input.substr(start, length));
					}
				}
			}
			else
	        {
				isInWhiteSpace = false;
			}
		}
		return stringutils::TrimWhiteSpaces(input.substr(start));
	}

	//Funkcja zwraca sparsowany wektor
	std::vector<std::string> Tokenize(const std::string & input, char separator)
	{
		std::vector< std::string > ret;
		size_t separatorPosition = 0;
		do
		{
			size_t nextSeparatorPosition = input.find(separator, separatorPosition + 1);
			size_t length = nextSeparatorPosition - separatorPosition;
			ret.push_back(input.substr(separatorPosition, length));
			separatorPosition = nextSeparatorPosition;
			if (separatorPosition != std::string::npos)
				separatorPosition++;
		}
		while (separatorPosition != std::string::npos);
		return ret;
	}

	//Funckja zwraca std::string na podstawie parametru bool
	//Wykorzystywana do zapisu s³ów "true", "false" w plikach xml
	std::string BoolToString(bool param)
	{
		if (param)
			return "true";
		return "false";
	}

	//Funkcja usuwa bia³e znaki
	std::string TrimWhiteSpaces(const std::string &toTrim)
	{
		size_t start = 0;
		size_t end = 0;

		for(start=0; start < toTrim.length(); start++)
		{
			if(toTrim[start] == ' ' || toTrim[start] == (char)9 || toTrim[start] == (char)10 || toTrim[start] == (char)13)
	            continue;
		    else
			    break;
		}

		for(end=toTrim.length(); end > 0; end--)
		{
	        if(toTrim[end-1] == ' ' || toTrim[end-1] == (char)9 || toTrim[end-1] == (char)10 || toTrim[end-1] == (char)13)
		        continue;
			else
				break;
		}

		if (start > end)
			return "";

		return toTrim.substr(start, end - start);
	}

	//Funkcja usuwa bia³e znaki
	std::wstring TrimWhiteSpacesW(const std::wstring &toTrim)
	{
		size_t start = 0;
		size_t end = 0;

		for(start=0; start < toTrim.length(); start++)
		{
			if(toTrim[start] == ' ' || toTrim[start] == (char)9 || toTrim[start] == (char)10 || toTrim[start] == (char)13)
				continue;
			else
				break;
		}

		for(end = toTrim.length(); end > 0; end--)
		{
			if(toTrim[end-1] == ' ' || toTrim[end-1] == (char)9 || toTrim[end-1] == (char)10 || toTrim[end-1] == (char)13)
				continue;
			else
				break;
		}
	
		if (start > end)
			return L"";

		return toTrim.substr(start, end - start);
	}

	//Metoda generuje wszystkie kombinacje elementów zbioru
	std::string GenerateCode(std::vector<char> &chars,int maxLength,int hash)
	{
		if (chars.size() > 0)
		{
			int index = hash % chars.size();
			int i = 0;
			std::string result = "";
			while (i < maxLength){
				result += chars[index];
				hash /= (int) chars.size();
				index = hash % chars.size();
				i++;
			}
			return result;
		}
		else
			return "";
	}

	//
	void Exclude(const std::string& s, char ch, std::vector<std::string>& out)
	{
		std::string curWord;
		out.clear();

		for (unsigned i = 0; i < s.size(); i++)
		{
			if (s[i] == ch && curWord != "")
			{
				out.push_back(curWord);
				curWord = "";
			}
			else
				curWord.push_back(s[i]);
		}

		if (curWord != "")
			out.push_back(curWord);
	}

	//
	std::string ToUpper(const std::string& s)
	{
		std::string str;
		std::string::const_iterator i = s.begin();
		std::string::const_iterator end = s.end();
		// zamiana na wielkie litery
		while (i != end)
		{
			str += (*i >= 'a' && *i <= 'z' ? *i - 'a' + 'A' : *i);
			++i;
		}
		return str;
	}

}//namespace stringutils
