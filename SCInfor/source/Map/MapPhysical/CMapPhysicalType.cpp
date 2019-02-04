//  _____________________________________________
// | CMapPhysicalType.cpp - class implementacion |
// | Jack Flower - March 2015                    |
// |_____________________________________________|
//

#include "CMapPhysicalType.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CMapPhysicalType);

	//Konstruktor
	CMapPhysicalType::CMapPhysicalType()
	:
		m_code		(),
		p_template	(NULL)
	{
	}

	//Konstruktor kopiuj�cy
	CMapPhysicalType::CMapPhysicalType(const CMapPhysicalType & CMapPhysicalTypeCopy)
	:
		m_code		(CMapPhysicalTypeCopy.m_code),
		p_template	(CMapPhysicalTypeCopy.p_template)
	{
	}

	//Destruktor
	CMapPhysicalType::~CMapPhysicalType()
	{
		m_code		= "";
		p_template	= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CMapPhysicalType::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca unikaln� nazw� obiektu wzorca nadawan� w pliku xml
	const std::string & CMapPhysicalType::GetCode() const
	{
		return m_code;
	}

	//Metoda nadaje unikaln� nazw� obiektu wzorca nadawan� w pliku xml
	void CMapPhysicalType::SetCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca wska�nik na wzorzec fabryczny - obiekt klasy CMapPhysicalTemplate
	CMapPhysicalTemplate* CMapPhysicalType::GetTemplate()
	{
		return p_template;
	}
		
	//Metoda ustawia wska�nik na wzorzec fabryczny - obiekt klasy CMapPhysicalTemplate
	void CMapPhysicalType::SetTemplate(CMapPhysicalTemplate* template_param)
	{
		p_template = template_param;
	}
}//namespace mapengine
