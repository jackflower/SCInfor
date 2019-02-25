//  _________________________________________
// | CPathManager.cpp - class implementation |
// | Jack Flower July 2012                   |
// |_________________________________________|
//

#include "CPathManager.h"

using namespace fileutils;
template<> CPathManager* CSingleton<CPathManager>::m_singleton = 0;

namespace fileutils
{

	//Konstruktor
	CPathManager::CPathManager(void)
	{
		fprintf(stderr, "CPathManager::CPathManager()\n");
	}

	//Destruktor
	CPathManager::~CPathManager(void)
	{
		ReleaseAllDataPath();
		fprintf(stderr, "CPathManager::~CPathManager\n");
	}

	//Metoda zwracaj¹ca œcie¿kê do pliku std::string na podstawie std::string
	const std::string CPathManager::GetDataPath (const std::string &str_name)
	{
		DataPathMap::iterator it = m_data_path_map.find(str_name);
		if (it == m_data_path_map.end())
		{
		  return "";
		}
		else
		{
			std::string  str_data = (*it).second;
			return str_data.c_str();
		}
	}

	//Metoda rejestruje œcie¿kê do pliku na podstawie danych
	bool CPathManager::Register (const std::string &data_str_name, const std::string &str_name)
	{
		DataPathMap::iterator it = m_data_path_map.find(data_str_name);
		if (it != m_data_path_map.end())
		{
			return false;
		}
			m_data_path_map[data_str_name] = str_name;
			return true;
	}

	//Metoda usuwa zasób na podstawie identyfikatora
	void CPathManager::ReleaseDataPath(const std::string &data_str_name)
	{
		DataPathMap::iterator it = m_data_path_map.find(data_str_name);
		if (it != m_data_path_map.end())
		{
			m_data_path_map.begin()->second = "";
			m_data_path_map.erase(data_str_name);
		}
	}

	//Metoda usuwa zasoby
	void CPathManager::ReleaseAllDataPath()
	{
		while(m_data_path_map.begin() != m_data_path_map.end())
		{
			m_data_path_map.erase(m_data_path_map.begin());
		}
	}

	//Wirtualna metoda czyszcz¹ca singleton
	void CPathManager::cleanup()
	{
		fprintf(stderr, "CPathManager::cleanup()\n");
		ReleaseAllDataPath();
		fprintf(stderr, "CPathManager::cleanup() done...\n");
	}
}//namespace fileutils
