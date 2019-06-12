//  _____________________________________________
// | MapPhysicalManager.h - class implementation |
// | Jack Flower - March 2015                    |
// |_____________________________________________|
//

#include "MapPhysicalManager.h"
#include "../Map/MapPhysical/MapPhysical.h"
#include "../Map/MapPhysical/GroundWork/GroundWork.h"
#include "../Utilities/StringUtils/StringUtils.h"
#include "../Game/Game.h"
#include <iostream>

using namespace rendering;
using namespace game;

template<> MapPhysicalManager *CSingleton<MapPhysicalManager>::m_singleton = 0;

namespace logic
{

	//Konstruktor
	MapPhysicalManager::MapPhysicalManager(void)
	{
		fprintf(stderr, "MapPhysicalManager::MapPhysicalManager()\n");
		gGame.addFrameListener(this);
	}

	//Destruktor wirtualny
	MapPhysicalManager::~MapPhysicalManager(void)
	{
		fprintf(stderr, "MapPhysicalManager::~MapPhysicalManager()\n");
		clear(true);
	}

	//Wirtualna metoda - czyści obiekty z kontenera
	void MapPhysicalManager::frameStarted(float secondsPassed)
	{
		//std::cout << m_mapphysicals[0]->getCode() << std::endl;
		//std::cout << "Zorro" << std::endl;//listener nasłuchuje...
		//jakby co, to w kontenerze są wskaźniki na MapPhysical i potomne...
		//
		//2015-07-06
		//tutaj umieścić kod zarządzający logiką
		//odpowiedzialną za warstwę logiczną - trakcja energetyczna
	}

	//Metoda tworzy obiekt klasy MapPhysical i zwraca wskaźnik na ten obiekt
	MapPhysical *MapPhysicalManager::createMapPhysical(const std::wstring& unique_id)
	{
		fprintf(stderr, "MapPhysical created\n");
		return create<MapPhysical>(unique_id);
	}

	//Metoda tworzy obiekt klasy GroundWork i zwraca wskaźnik na ten obiekt
	GroundWork *MapPhysicalManager::createGroundWork(const std::wstring& unique_id)
	{
		fprintf(stderr, "GroundWork created\n");
		return create<GroundWork>(unique_id);
	}

	//Metoda usuwa obiekt klasy MapPhysical z kontenera
	void MapPhysicalManager::destroyMapPhysical(MapPhysical* mapphysical)
	{
		if (mapphysical->m_mapphysical_manager_index >= 0)
		{
			m_mapphysicals[mapphysical->m_mapphysical_manager_index] = m_mapphysicals[m_mapphysicals.size()-1];
			m_mapphysicals[mapphysical->m_mapphysical_manager_index]->m_mapphysical_manager_index = mapphysical->m_mapphysical_manager_index;
			m_mapphysicals.pop_back();
			mapphysical->m_mapphysical_manager_index = -1;
			fprintf(stderr, "MapPhysicalManager::DestroyMapPhysical - %ls\n", mapphysical->getUniqueId().c_str());
			destroyMapPhysical(mapphysical->getUniqueId());
			delete mapphysical;
		}
	}

	//Metoda usuwa obiekt klasy MapPhysical z kontenera
	void MapPhysicalManager::destroyMapPhysical(const std::wstring& id_mapphysical)
	{
		if (m_named_mapphysicals.find(id_mapphysical) != m_named_mapphysicals.end())
		{
			MapPhysical* mapphysical = m_named_mapphysicals[id_mapphysical];
			m_named_mapphysicals.erase(m_named_mapphysicals.find( id_mapphysical));
			destroyMapPhysical(mapphysical);
		}
	}

	//Metoda usuwa wszystkie obiekty z kontenera
	void MapPhysicalManager::clear(bool force_destroy_instantly)
	{
		std::vector<MapPhysical*>::iterator it;

		for (it = m_mapphysicals.begin(); it != m_mapphysicals.end(); it++)
		{
			(*it)->markForDelete();
		}
	}

	//Metoda zwraca stałą referencję do kontenera z nazwami wszystkich zarejestorwanych obiektów MapPhysical
	const std::map<std::wstring, MapPhysical*> & MapPhysicalManager::getNamedMapPhysicals()
	{
		return m_named_mapphysicals;
	}

	//Metoda zwraca stałą referencję do kontenera z wszystkimi wskaźnikami zarejestorwanych obiektów MapPhysical
	const std::vector<MapPhysical *> & MapPhysicalManager::getMapPhysicals()
	{
		return m_mapphysicals;
	}

	//Metoda zwraca wskaźnik na obiekt klasy MapPhysical z kontenera na podstawie identyfikatora
	MapPhysical* MapPhysicalManager::getMapPhysicalById(const std::wstring & mapphysical_id)
	{
		if (m_named_mapphysicals.find(mapphysical_id) != m_named_mapphysicals.end())
			return m_named_mapphysicals[mapphysical_id];
		else
		{
			fprintf(stderr, "MapPhysicalManager::GetMapPhysicalById - %ls key not found in m_named_mapphysicals map", mapphysical_id.c_str());
			return nullptr;
		}
	}

	//Wirtualny interfejs - implementacja
	void MapPhysicalManager::cleanup()
	{
		fprintf(stderr, "MapPhysicalManager::cleanup()\n");
		
		//nie jestem do końca pewien tego kodu...
		//std::vector<MapPhysical*>::iterator it;
		//for (it = m_mapphysicals.begin(); it != m_mapphysicals.end(); it++)
		//	DestroyMapPhysical(*(it));
		fprintf(stderr, "MapPhysicalManager::cleanup() done...\n");
	}

	//implementajca metod private:

	////Szablon metody tworzenia obiektów
	template<class T>
	T* MapPhysicalManager::create(const std::wstring &uniqueId)
	{
		std::wstring new_unique_id = uniqueId;
		if (uniqueId != L"")
		{
			CheckUniqueId(new_unique_id);

			if (m_named_mapphysicals.find(new_unique_id) != m_named_mapphysicals.end())
			{
				fprintf(stderr, "MapPhysicalManager::create<T> - %ls key already in m_named_mapphysicals map", new_unique_id.c_str());
				return nullptr;
			}

			m_named_mapphysicals[new_unique_id] = nullptr; // zarezerwowanie nazwy przed utworzeniem obiektu
		}

		T* obj = new T(new_unique_id);
		obj->m_mapphysical_manager_index = (int)m_mapphysicals.size();
		m_mapphysicals.push_back(obj);
		if (uniqueId != L"")
			m_named_mapphysicals[new_unique_id] = obj;
		return obj;
	}

	//Prywatna metoda sprawdzająca jaki identyfikator nadać obiektowi przy utworzeniu
	void MapPhysicalManager::CheckUniqueId(std::wstring& new_unique_id)
	{
		static long mapworksCount = 0;
		//jeśli identyfikator jest ciągiem pustych znaków
		//lub w kontenerze są już jakieś nazwy
		if ((new_unique_id == L"" ) || (m_named_mapphysicals.count(new_unique_id) > 0))
			do
			{
				//to tworzymy nazwę zsyntetyzowaną
				//do słowa "mapworks" do dajemy wartość licznika zamienioną na string
				new_unique_id = L"mapworks" + stringutils::ToWString(mapworksCount++);
			}
			while (m_named_mapphysicals.find(new_unique_id) != m_named_mapphysicals.end());
	}

}//namespace logic
