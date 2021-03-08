//  ____________________________________________
// | CCharSetManager.cpp - class implementation |
// | Jack Flower - May 2015                     |
// |____________________________________________|
//

#include "CCharSetManager.h"

using namespace charsettools;

template<> CCharSetManager* Singleton<CCharSetManager>::m_singleton = 0;

namespace charsettools
{
	//Konstruktor
	CCharSetManager::CCharSetManager()
	:
		m_translator		(),
		m_translators		(),
		m_valid_chars		()
	{
		//podstawowy zestaw znak�w ASCII (ANSII), kt�ry zostanie uzupe�niony
		//o polskie znaki diakrytyczne, zapisane i odczytanie z pliku xml,
		//z ustawionym kodowaniem UTF-8 (bez BOM)

		//http://pl.wikipedia.org/wiki/BOM_%28informatyka%29
		//
		//BOM (ang. Byte Order Mark) � znacznik kolejno�ci bajt�w[1].
		//Jest to znak niedrukowalny u�ywany w wielobajtowym kodowaniu znak�w,
		//kt�ry jest zapisywany na pocz�tku strumienia bajt�w (pliku) i informuje,
		//w jakiej kolejno�ci nale�y ustawi� bajty, aby odczyta� kod znaku.
		//BOM rozwi�zuje problem interpretacji kolejno�ci bajt�w w znaku
		//i umo�liwia automatyczn� detekcj� kodowania
		//UTF-8, UTF-16LE, UTF-16BE, UTF-32LE oraz UTF-32BE.
		//
		//To zainicjonowanie jest niezb�dne, poniewa�, aby mie� mo�liwo��
		//obs�ugi dodatkowych znak�w spoza obowi�zuj�cego ASCII,
		//musz� u�y� typu std::wstring, kt�ry zapisuje znak w dw�ch bajtach

		m_valid_chars =	L"!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ"
						L" [\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	}

	//Destruktor
	CCharSetManager::~CCharSetManager()
	{
		//m_translator		not edit
		m_translators.clear();
		//m_valid_chars		not edit
	}

	//Metoda inicjuje zbi�r znak�w
	void CCharSetManager::InitializeValidChars(const std::string & char_set_name)
	{
		if(!load(char_set_name))
			fprintf(stderr, "CCharSet::InitializeValidChars(CCharSet::InitializeValidChars)%s\n", char_set_name.c_str());
	}

	//Metoda konweruje �a�cuch znak�w std::std::string na std::std::wstring
	std::wstring CCharSetManager::ReinterpretFromUTF8(std::string string_input)
	{
		std::wstring out(L"");
		out.reserve(string_input.size());
		bool translated;
		for (unsigned int i = 0; i < string_input.size(); /* recznie zwieksze i */)
		{
			translated = false;
			if (i < string_input.size() -1){
				for (unsigned int j = 0; j < m_translators.size(); j++)
				{
					if ((m_translators[j].a == string_input[i]) && (m_translators[j].b == string_input[i+1]))
					{
						translated = true;
						out += m_translators[j].out;
						i+=2;
						break;
					}
				}
			}
			if (!translated)
			{
				out+=string_input[i];
				i++;
			}
		}
		return out;
	}

	//Metoda �aduj�ca dane
	bool CCharSetManager::load(const std::string &name)
	{
		Xml xml(name, "root" );
		return load(xml);
	}

	//Metoda �aduj�ca dane z xml
	bool CCharSetManager::load(Xml &xml)
	{
		std::string string_tmp;//odczytany z xml'a string (dwa bajty definiuj�ce znak)

		for(xml_node<> *node = xml.getChild(xml.getRootNode(),"letter"); node; node = xml.getSibling(node,"letter"))
		{
			string_tmp = xml.getString(node);//
			m_translator.a = string_tmp[0];//pierwszy bajt
			m_translator.b = string_tmp[1];//drugi bajt
			m_translator.out = static_cast<wchar_t>(xml.getInt(node, "code"));
			m_translators.push_back(m_translator);
			m_valid_chars += m_translator.out;
		}

		if(!m_translators.size())
		{
			fprintf(stderr, "Error character set loading\n");
			return false;
		}
		return true;
	}

	//Wirtualny interfejs - implementacja
	void CCharSetManager::cleanup()
	{
		fprintf(stderr, "CCharSet::cleanup()\n");
		fprintf(stderr, "CCharSet::cleanup() done...\n");
	}

}//namespace charsettools
