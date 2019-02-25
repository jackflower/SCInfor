//  ________________________________________
// | InfoManager.cpp - class implementation |
// | Jack Flower - April 2015               |
// |________________________________________|
//

#include "InfoManager.h"
#include "../Game/Game.h"
#include "BaseInformation.h"
#include "Information.h"
#include "Presentation.h"

using namespace game;


using namespace infologic;

template<> InfoManager* CSingleton<InfoManager>::m_singleton = 0;

namespace infologic
{
	//Konstruktor
	InfoManager::InfoManager()
	{
		fprintf(stderr, "InfoManager::InfoManager()\n");
		gGame.addFrameListener(this);
	}

	//Destruktor wirtualny
	InfoManager::~InfoManager()
	{
		fprintf(stderr, "InfoManager::~InfoManager()\n");
		clear(true);
	}

	//Wirtualna metoda - aktualizuje obiekty kontenera
	void InfoManager::frameStarted(float secondsPassed)
	{
		//std::cout << m_map_information[0]->GetUniqueId() << std::endl;
		//testy, czy listener nasłuchuje...
		//...
	}

	//Metoda tworzy obiekt klasy Information i zwraca wskaźnik na ten obiekt
	Information* InfoManager::createInformation(const std::wstring & unique_id)
	{
		fprintf(stderr, "Information created\n");
		return create<Information>(unique_id);
	}

	//Metoda tworzy obiekt klasy Presentation i zwraca wskaźnik na ten obiekt
	Presentation* InfoManager::createPresentation(const std::wstring & unique_id)
	{
		fprintf(stderr, "Presentation created\n");
		return create<Presentation>(unique_id);
	}

	//Metoda usuwa obiekt klasy Information z kontenera
	void InfoManager::destroyInformation(BaseInformation *mapinformation)
	{
		if (mapinformation->m_map_information_manager_index >= 0)
		{
			m_map_information[mapinformation->m_map_information_manager_index] = m_map_information[m_map_information.size()-1];
			m_map_information[mapinformation->m_map_information_manager_index]->m_map_information_manager_index = mapinformation->m_map_information_manager_index;
			m_map_information.pop_back();
			mapinformation->m_map_information_manager_index = -1;
			fprintf(stderr, "InfoManager::DestroyInformation - %ls\n", mapinformation->getUniqueId().c_str());
			destroyInformation(mapinformation->getUniqueId());
		}
	}
	    
	//Metoda usuwa obiekt klasy Information z kontenera
	void InfoManager::destroyInformation(const std::wstring& id_mapinformation)
	{
		if (m_named_map_information.find(id_mapinformation) != m_named_map_information.end())
		{
			BaseInformation* mapinformation = m_named_map_information[id_mapinformation];
			m_named_map_information.erase(m_named_map_information.find( id_mapinformation));
			destroyInformation(mapinformation);
		}
	}

	//Metoda usuwa wszystkie obiekty z kontenera
	void InfoManager::clear(bool force_destroy_instantly)
	{
		std::vector<BaseInformation*>::iterator it;
		for (it = m_map_information.begin(); it != m_map_information.end(); it++)
		{
			(*it)->markForDelete();
		}
	}

	//Metoda zwraca stała referencję do kontenera z nazwami wszystkich zarejestrowanych obiektów Information
	const std::map<std::wstring, BaseInformation*>& InfoManager::getNamedMapInformation()
	{
		return m_named_map_information;
	}

	//Metoda zwraca stała referencję do kontenera z wszystkimi wskaźnikami zarejestrowanych obiektów Information
	const std::vector<BaseInformation*>& InfoManager::getMapInformation()
	{
		return m_map_information;
	}

	//Metoda zwraca wskaźnik na obiekt klasy Information z kontenera na podstawie identyfikatora
	BaseInformation* InfoManager::getMapInformationById(const std::wstring & information_id)
	{
		if (m_named_map_information.find(information_id) != m_named_map_information.end())
			return m_named_map_information[information_id];
		else
		{
			fprintf(stderr, "InfoManager::GetMapInformationById - %ls key not found in m_named_map_information map", information_id.c_str());
			return NULL;
		}
	}

	//Wirtualny interfejs - implementacja
	void InfoManager::cleanup()
	{
		fprintf(stderr, "InfoManager::cleanup()\n");
		fprintf(stderr, "InfoManager::cleanup() done...\n");
	}

	//implementajca metod private:

	//Szablon metody tworzenia obiektów
	template<class T>
	T* InfoManager::create(const std::wstring & uniqueId)
	{
		std::wstring new_unique_id = uniqueId;
		if (uniqueId != L"")
		{
			checkUniqueId(new_unique_id);

			if (m_named_map_information.find(new_unique_id) != m_named_map_information.end())
			{
				fprintf(stderr, "InfoManager::create<T> - %ls key already in m_named_map_information map", new_unique_id.c_str());
				return NULL;
			}

			m_named_map_information[new_unique_id] = NULL; // zarezerwowanie nazwy przed utworzeniem obiektu
		}

		T* obj = new T(new_unique_id);
		obj->m_map_information_manager_index = (int)m_map_information.size();
		m_map_information.push_back(obj);
		if (uniqueId != L"")
			m_named_map_information[new_unique_id] = obj;
		return obj;
	}

	//Prywatna metoda sprawdzająca jaki identyfikator nadać obiektowi przy utworzeniu
	void InfoManager::checkUniqueId(std::wstring& new_unique_id)
	{
		static long informationCount = 0;
		//jeśli identyfikator jest ciągiem pustych znaków
		//lub w kontenerze są już jakieś nazwy
		if ((new_unique_id == L"" ) || (m_named_map_information.count(new_unique_id) > 0))
			do
			{
				//to tworzymy nazwę zsyntetyzowaną
				//do słowa "information" do dajemy wartość licznika zamienioną na string
				new_unique_id = L"information" + stringutils::ToWString(informationCount++);
			}
			while (m_named_map_information.find(new_unique_id) != m_named_map_information.end());
	}
}//namespace infologic
