//  _________________________________________
// | IInformation.cpp - class implementation |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#include "IInformation.h"

namespace information
{
	RTTI_IMPL_NOPARENT(IInformation);

	//Chroniony konstruktor domy�lny
	IInformation::IInformation(const std::wstring& uniqueId)
	:
		m_unique_id						(uniqueId),
		m_map_information_manager_index	(-1),
		m_ready_for_destruction			(false)
	{
	}

	//Chroniony konstruktor kopiuj�cy
	IInformation::IInformation(const IInformation &IInformationCopy)
	:
		m_unique_id						(IInformationCopy.m_unique_id),
		m_map_information_manager_index	(IInformationCopy.m_map_information_manager_index),
		m_ready_for_destruction			(IInformationCopy.m_ready_for_destruction)
	{
	}

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CInfoManager
	IInformation::~IInformation()
	{
		m_unique_id						= L"";
		m_map_information_manager_index = 0;
		m_ready_for_destruction			= false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string IInformation::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca unikaln� nazw� obiektu klasy CMapWork
	const std::wstring & IInformation::GetUniqueId() const
	{
		return m_unique_id;
	}

	//Metoda ustawia flag� dla obiekt�w gotowych do destrukcji
	void IInformation::MarkForDelete()
	{
		m_ready_for_destruction = true;
	}

	//Wirtualna metoda aktualizuj�ca obiekt
	void IInformation::update(float dt)
	{
		//nothing todo...
	}
}//namespace information
