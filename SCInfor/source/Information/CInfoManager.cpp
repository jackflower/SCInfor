//  _________________________________________
// | CInfoManager.cpp - class implementation |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#include "CInfoManager.h"
#include "../Game/Game.h"
#include "IInformation.h"
#include "CInformation.h"
#include "CPresentation.h"

using namespace game;


using namespace infologic;

template<> CInfoManager* CSingleton<CInfoManager>::m_singleton = 0;

namespace infologic
{
	//Konstruktor
	CInfoManager::CInfoManager()
	{
		fprintf(stderr, "CInfoManager::CInfoManager()\n");
		gGame.addFrameListener(this);
	}

	//Destruktor wirtualny
	CInfoManager::~CInfoManager()
	{
		fprintf(stderr, "CInfoManager::~CInfoManager()\n");
		Clear(true);
	}

	//Wirtualna metoda - czyœci obiekty z kontenera
	void CInfoManager::frameStarted(float secondsPassed)
	{
		//std::cout << m_map_information[0]->GetUniqueId() << std::endl;
		//testy, czy listener nas³uchuje...
		//...
	}

	//Metoda tworzy obiekt klasy CInformation i zwraca wskaŸnik na ten obiekt
	CInformation* CInfoManager::CreateInformation(const std::wstring& unique_id)
	{
		fprintf(stderr, "CInformation created\n");
		return Create<CInformation>(unique_id);
	}

	//Metoda tworzy obiekt klasy CPresentation i zwraca wskaŸnik na ten obiekt
	CPresentation* CInfoManager::CreatePresentation(const std::wstring& unique_id)
	{
		fprintf(stderr, "CPresentation created\n");
		return Create<CPresentation>(unique_id);
	}

	//Metoda usuwa obiekt klasy IInformation z kontenera
	void CInfoManager::DestroyInformation(IInformation* mapinformation)
	{
		if (mapinformation->m_map_information_manager_index >= 0)
		{
			m_map_information[mapinformation->m_map_information_manager_index] = m_map_information[m_map_information.size()-1];
			m_map_information[mapinformation->m_map_information_manager_index]->m_map_information_manager_index = mapinformation->m_map_information_manager_index;
			m_map_information.pop_back();
			mapinformation->m_map_information_manager_index = -1;
			fprintf(stderr, "CInfoManager::DestroyInformation - %ls\n", mapinformation->GetUniqueId().c_str());
			DestroyInformation(mapinformation->GetUniqueId());
		}
	}
	    
	//Metoda usuwa obiekt klasy IInformation z kontenera
	void CInfoManager::DestroyInformation(const std::wstring& id_mapinformation)
	{
		if (m_named_map_information.find(id_mapinformation) != m_named_map_information.end())
		{
			IInformation* mapinformation = m_named_map_information[id_mapinformation];
			m_named_map_information.erase(m_named_map_information.find( id_mapinformation));
			DestroyInformation(mapinformation);
		}
	}

	//Metoda usuwa wszystkie obiekty z kontenera
	void CInfoManager::Clear(bool force_destroy_instantly)
	{
		std::vector<IInformation*>::iterator it;
		for (it = m_map_information.begin(); it != m_map_information.end(); it++)
		{
			(*it)->MarkForDelete();
		}
	}

	//Metoda zwraca sta³a referencjê do kontenera z nazwami wszystkich zarejestrowanych obiektów IInformation
	const std::map<std::wstring, IInformation*>& CInfoManager::GetNamedMapInformation()
	{
		return m_named_map_information;
	}

	//Metoda zwraca sta³a referencjê do kontenera z wszystkimi wskaŸnikami zarejestrowanych obiektów IInformation
	const std::vector<IInformation*>& CInfoManager::GetMapInformation()
	{
		return m_map_information;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy IInformation z kontenera na podstawie identyfikatora
	IInformation* CInfoManager::GetMapInformationById(const std::wstring& information_id)
	{
		if (m_named_map_information.find(information_id) != m_named_map_information.end())
			return m_named_map_information[information_id];
		else
		{
			fprintf(stderr, "CInfoManager::GetMapInformationById - %ls key not found in m_named_map_information map", information_id.c_str());
			return NULL;
		}
	}

	//Wirtualny interfejs - implementacja
	void CInfoManager::Cleanup()
	{
		fprintf(stderr, "CInfoManager::Cleanup()\n");
		fprintf(stderr, "CInfoManager::Cleanup() done...\n");
	}

	//implementajca metod private:

	//Szablon metody tworzenia obiektów
	template<class T>
	T* CInfoManager::Create(const std::wstring &uniqueId)
	{
		std::wstring new_unique_id = uniqueId;
		if (uniqueId != L"")
		{
			CheckUniqueId(new_unique_id);

			if (m_named_map_information.find(new_unique_id) != m_named_map_information.end())
			{
				fprintf(stderr, "CInfoManager::Create<T> - %ls key already in m_named_map_information map", new_unique_id.c_str());
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

	//Prywatna metoda sprawdzaj¹ca jaki identyfikator nadaæ obiektowi przy utworzeniu
	void CInfoManager::CheckUniqueId(std::wstring& new_unique_id)
	{
		static long informationCount = 0;
		//jeœli identyfikator jest ci¹giem pustych znaków
		//lub w kontenerze s¹ ju¿ jakieœ nazwy
		if ((new_unique_id == L"" ) || (m_named_map_information.count(new_unique_id) > 0))
			do
			{
				//to tworzymy nazwê zsyntetyzowan¹
				//do s³owa "information" do dajemy wartoœæ licznika zamienion¹ na string
				new_unique_id = L"information" + stringutils::ToWString(informationCount++);
			}
			while (m_named_map_information.find(new_unique_id) != m_named_map_information.end());
	}
}//namespace infologic
