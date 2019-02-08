//  ___________________________________________
// | CMapObjectType.cpp - class implementation |
// | Jack Flower April 2013                    |
// |___________________________________________|
//

#include "CMapObjectType.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CMapObjectType);

	//Konstruktor
	CMapObjectType::CMapObjectType()
	:
		m_code		(""),
		p_template	(NULL)
	{
	}

	//Konstruktor kopiuj¹cy
	CMapObjectType::CMapObjectType(const CMapObjectType& CMapObjectTypeCopy)
	:
		m_code		(CMapObjectTypeCopy.m_code),
		p_template	(CMapObjectTypeCopy.p_template)
	{
	}

	//Destruktor
	CMapObjectType::~CMapObjectType()
	{	
		m_code		= "";
		p_template	= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CMapObjectType::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwê znacznika obiektu na mapie
	const std::string & CMapObjectType::GetCode() const
	{
		return m_code;
	}

	//Metoda ustawia nazwê znacznika obiektu na mapie
	void CMapObjectType::SetCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca wskaŸnik na wzorzec danych
	PhysicalTemplate* CMapObjectType::GetTemplate() const
	{
		return p_template;
	}

	//Metoda ustawia wskaŸnik na wzorzec danych
	void CMapObjectType::SetTemplate(PhysicalTemplate* template_param)
	{
		p_template = template_param;
	}
}//namespace mapengine
