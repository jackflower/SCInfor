//  ______________________________________________
// | CMapPhysicalManager.h - class implementation |
// | Jack Flower - March 2015                     |
// |______________________________________________|
//

#include "CMapPhysicalManager.h"
#include "../Map/MapPhysical/CMapPhysical.h"
#include "../Map/MapPhysical/GroundWork/CGroundWork.h"
#include "../Utilities/StringUtils/StringUtils.h"
#include "../Game/Game.h"
#include <iostream>

using namespace rendering;
using namespace game;

template<> CMapPhysicalManager* CSingleton<CMapPhysicalManager>::m_singleton = 0;

namespace logic
{

	//Konstruktor
	CMapPhysicalManager::CMapPhysicalManager(void)
	{
		fprintf(stderr, "CMapPhysicalManager::CMapPhysicalManager()\n");
		gGame.addFrameListener(this);
	}

	//Destruktor wirtualny
	CMapPhysicalManager::~CMapPhysicalManager(void)
	{
		fprintf(stderr, "CMapPhysicalManager::~CMapPhysicalManager()\n");
		Clear(true);
	}

	//Wirtualna metoda - czyœci obiekty z kontenera
	void CMapPhysicalManager::frameStarted(float secondsPassed)
	{
		//std::cout << m_mapphysicals[0]->getCode() << std::endl;
		//std::cout << "Zorro" << std::endl;//listener nas³uchuje...
		//jakby co, to w kontenerze s¹ wskaŸniki na CMapPhysical i potomne...
		//
		//2015-07-06
		//tutaj umieœciæ kod zarz¹dzaj¹cy logik¹
		//odpowiedzialn¹ za warstwê logiczn¹ - trakcja energetyczna
	}

	//Metoda tworzy obiekt klasy CMapPhysical i zwraca wskaŸnik na ten obiekt
	CMapPhysical* CMapPhysicalManager::CreateMapPhysical(const std::wstring& unique_id)
	{
		fprintf(stderr, "CMapPhysical created\n");
		return create<CMapPhysical>(unique_id);
	}

	//Metoda tworzy obiekt klasy CGroundWork i zwraca wskaŸnik na ten obiekt
	CGroundWork* CMapPhysicalManager::CreateGroundWork(const std::wstring& unique_id)
	{
		fprintf(stderr, "CGroundWork created\n");
		return create<CGroundWork>(unique_id);
	}

	//Metoda usuwa obiekt klasy CMapPhysical z kontenera
	void CMapPhysicalManager::DestroyMapPhysical(CMapPhysical* mapphysical)
	{
		if (mapphysical->m_mapphysical_manager_index >= 0)
		{
			m_mapphysicals[mapphysical->m_mapphysical_manager_index] = m_mapphysicals[m_mapphysicals.size()-1];
			m_mapphysicals[mapphysical->m_mapphysical_manager_index]->m_mapphysical_manager_index = mapphysical->m_mapphysical_manager_index;
			m_mapphysicals.pop_back();
			mapphysical->m_mapphysical_manager_index = -1;
			fprintf(stderr, "CMapPhysicalManager::DestroyMapPhysical - %ls\n", mapphysical->GetUniqueId().c_str());
			DestroyMapPhysical(mapphysical->GetUniqueId());
			delete mapphysical;
		}
	}

	//Metoda usuwa obiekt klasy CMapPhysical z kontenera
	void CMapPhysicalManager::DestroyMapPhysical(const std::wstring& id_mapphysical)
	{
		if (m_named_mapphysicals.find(id_mapphysical) != m_named_mapphysicals.end())
		{
			CMapPhysical* mapphysical = m_named_mapphysicals[id_mapphysical];
			m_named_mapphysicals.erase(m_named_mapphysicals.find( id_mapphysical));
			DestroyMapPhysical(mapphysical);
		}
	}

	//Metoda usuwa wszystkie obiekty z kontenera
	void CMapPhysicalManager::Clear(bool force_destroy_instantly)
	{
		std::vector<CMapPhysical*>::iterator it;

		for (it = m_mapphysicals.begin(); it != m_mapphysicals.end(); it++)
		{
			(*it)->MarkForDelete();
		}
	}

	//Metoda zwraca sta³¹ referencjê do kontenera z nazwami wszystkich zarejestorwanych obiektów CMapPhysical
	const std::map<std::wstring, CMapPhysical*>& CMapPhysicalManager::GetNamedMapPhysicals()
	{
		return m_named_mapphysicals;
	}

	//Metoda zwraca sta³¹ referencjê do kontenera z wszystkimi wskaŸnikami zarejestorwanych obiektów CMapPhysical
	const std::vector<CMapPhysical *> &CMapPhysicalManager::GetMapPhysicals()
	{
		return m_mapphysicals;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CMapPhysical z kontenera na podstawie identyfikatora
	CMapPhysical* CMapPhysicalManager::GetMapPhysicalById(const std::wstring& mapphysical_id)
	{
		if (m_named_mapphysicals.find(mapphysical_id) != m_named_mapphysicals.end())
			return m_named_mapphysicals[mapphysical_id];
		else
		{
			fprintf(stderr, "CMapPhysicalManager::GetMapPhysicalById - %ls key not found in m_named_mapphysicals map", mapphysical_id.c_str());
			return NULL;
		}
	}

	//Wirtualny interfejs - implementacja
	void CMapPhysicalManager::Cleanup()
	{
		fprintf(stderr, "CMapPhysicalManager::Cleanup()\n");
		
		//nie jestem do koñca pewien tego kodu...
		//std::vector<CMapPhysical*>::iterator it;
		//for (it = m_mapphysicals.begin(); it != m_mapphysicals.end(); it++)
		//	DestroyMapPhysical(*(it));
		fprintf(stderr, "CMapPhysicalManager::Cleanup() done...\n");
	}



	//implementajca metod private:

	////Szablon metody tworzenia obiektów
	template<class T>
	T* CMapPhysicalManager::create(const std::wstring &uniqueId)
	{
		std::wstring new_unique_id = uniqueId;
		if (uniqueId != L"")
		{
			CheckUniqueId(new_unique_id);

			if (m_named_mapphysicals.find(new_unique_id) != m_named_mapphysicals.end())
			{
				fprintf(stderr, "CMapPhysicalManager::create<T> - %ls key already in m_named_mapphysicals map", new_unique_id.c_str());
				return NULL;
			}

			m_named_mapphysicals[new_unique_id] = NULL; // zarezerwowanie nazwy przed utworzeniem obiektu
		}

		T* obj = new T(new_unique_id);
		obj->m_mapphysical_manager_index = (int)m_mapphysicals.size();
		m_mapphysicals.push_back(obj);
		if (uniqueId != L"")
			m_named_mapphysicals[new_unique_id] = obj;
		return obj;
	}

	//Prywatna metoda sprawdzaj¹ca jaki identyfikator nadaæ obiektowi przy utworzeniu
	void CMapPhysicalManager::CheckUniqueId(std::wstring& new_unique_id)
	{
		static long mapworksCount = 0;
		//jeœli identyfikator jest ci¹giem pustych znaków
		//lub w kontenerze s¹ ju¿ jakieœ nazwy
		if ((new_unique_id == L"" ) || (m_named_mapphysicals.count(new_unique_id) > 0))
			do
			{
				//to tworzymy nazwê zsyntetyzowan¹
				//do s³owa "mapworks" do dajemy wartoœæ licznika zamienion¹ na string
				new_unique_id = L"mapworks" + stringutils::ToWString(mapworksCount++);
			}
			while (m_named_mapphysicals.find(new_unique_id) != m_named_mapphysicals.end());
	}


}//namespace logic
