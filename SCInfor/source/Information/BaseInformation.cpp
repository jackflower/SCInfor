//  ____________________________________________
// | BaseInformation.cpp - class implementation |
// | Jack Flower - April 2015                   |
// |____________________________________________|
//

#include "BaseInformation.h"

namespace information
{
	RTTI_IMPL_NOPARENT(BaseInformation);

	//Chroniony konstruktor domyślny
	BaseInformation::BaseInformation(const std::wstring & uniqueId)
	:
		m_unique_id{ uniqueId },
		m_map_information_manager_index{ -1 },
		m_ready_for_destruction{ false }
	{
	}

	//Chroniony konstruktor kopiujący
	BaseInformation::BaseInformation(const BaseInformation & InformationCopy)
	:
		m_unique_id{ InformationCopy.m_unique_id },
		m_map_information_manager_index{ InformationCopy.m_map_information_manager_index },
		m_ready_for_destruction{ InformationCopy.m_ready_for_destruction }
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez InfoManager
	BaseInformation::~BaseInformation()
	{
		m_unique_id = L"";
		m_map_information_manager_index = 0;
		m_ready_for_destruction = false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string BaseInformation::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca unikalną nazwę obiektu (dla klasy CMapWork)
	const std::wstring & BaseInformation::getUniqueId() const
	{
		return m_unique_id;
	}

	//Metoda ustawia flagę dla obiektów gotowych do destrukcji
	void BaseInformation::markForDelete()
	{
		m_ready_for_destruction = true;
	}

	//Wirtualna metoda aktualizująca obiekt
	void BaseInformation::update(float dt)
	{
		//nothing todo...
	}
}//namespace information
