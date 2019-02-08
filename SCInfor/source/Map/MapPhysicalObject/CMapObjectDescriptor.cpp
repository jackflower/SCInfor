//  _________________________________________________
// | CMapObjectDescriptor.cpp - class implementation |
// | Jack Flower April 2013                          |
// |_________________________________________________|
//

#include "CMapObjectDescriptor.h"
#include "../../Factory/PhysicalTemplate.h"
#include "../../Utilities/StringUtils/StringUtils.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CMapObjectDescriptor);

	//Konstruktor
	CMapObjectDescriptor::CMapObjectDescriptor()
	:
		m_code				(""),
		m_name				(""),
		p_templ				(NULL),
		m_x_position		(0.0f),
		m_y_position		(0.0f),
		m_rotation_body		(0),
		m_rotation_head		(0),
		m_uniqueId			(0),
		m_smooth			(false)
	{
		m_uniqueId = nextId++;	//unikalna warto�� identyfikatora zwi�kszana w konstruktorze
	}
	
	//Konstruktor kopiuj�cy
	CMapObjectDescriptor::CMapObjectDescriptor(const CMapObjectDescriptor& CMapObjectDescriptorCopy)
	:
		m_code				(CMapObjectDescriptorCopy.m_code),
		m_name				(CMapObjectDescriptorCopy.m_name),
		p_templ				(CMapObjectDescriptorCopy.p_templ),
		m_x_position		(CMapObjectDescriptorCopy.m_x_position),
		m_y_position		(CMapObjectDescriptorCopy.m_y_position),
		m_rotation_body		(CMapObjectDescriptorCopy.m_rotation_body),
		m_rotation_head		(CMapObjectDescriptorCopy.m_rotation_head),
		m_uniqueId			(CMapObjectDescriptorCopy.m_uniqueId),
		m_smooth			(CMapObjectDescriptorCopy.m_smooth)
	{
	}

	//Destruktor
	CMapObjectDescriptor::~CMapObjectDescriptor()
	{
		m_code				= "";
		m_name				= "";
		p_templ				= NULL;
		m_x_position		= 0.0f;
		m_y_position		= 0.0f;
		m_rotation_body		= 0;
		m_rotation_head		= 0;
		m_uniqueId			= 0;
		m_smooth			= false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CMapObjectDescriptor::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda tworzy obiekt mapy
	void CMapObjectDescriptor::create()
	{
		CPhysical *phys = p_templ->create(stringutils::ConvertToWString(m_name));
		if (phys != 0)
		{
			phys->SetPosition(sf::Vector2f(m_x_position, m_y_position));
			phys->SetRotationBody(m_rotation_body);
			phys->SetRotationHead(m_rotation_head);
			phys->setSmoothing(m_smooth);
		}
	}

	//Metoda zwraca nazw� znacznika obiektu na mapie
	const std::string & CMapObjectDescriptor::GetCode() const
	{
		return m_code;
	}

	//Metoda ustawia nazw� znacznika obiektu na mapie
	void CMapObjectDescriptor::SetCode(const std::string &code)
	{
		m_code = code;
	}

	//Metoda zwraca nazw�, kt�r� nadajemy obiektowi
	const std::string & CMapObjectDescriptor::GetName() const
	{
		return m_name;
	}

	//Metoda ustawia nazw�, kt�r� nadajemy obiektowi
	void CMapObjectDescriptor::SetName(const std::string & name)
	{
		m_name = name;
	}


	//Metoda zwraca wska�nik na wzorzec produkcyjny
	PhysicalTemplate* CMapObjectDescriptor::GetTemplate() const
	{
		return p_templ;
	}

	//Metoda ustawia wska�nik na wzorzec produkcyjny
	void CMapObjectDescriptor::SetTemplate(PhysicalTemplate* template_param)
	{
		p_templ = template_param;
	}

	//Metoda zwraca pozycj� obietu - sk�adowa X (plik xml operuje body)
	const float CMapObjectDescriptor::GetXPosition() const
	{
		return m_x_position;
	}

	//Metoda ustawia pozycj� obietu - sk�adowa X (plik xml operuje body)
	void CMapObjectDescriptor::SetXPosition(float x_position)
	{
		m_x_position = x_position;
	}

	//Metoda zwraca pozycj� obietu - sk�adowa Y (plik xml operuje body)
	const float CMapObjectDescriptor::GetYPosition() const
	{
		return m_y_position;
	}

	//Metoda ustawia pozycj� obietu - sk�adowa Y (plik xml operuje body)
	void CMapObjectDescriptor::SetYPosition(float y_position)
	{
		m_y_position = y_position;
	}

	//Metoda zwraca obr�t obiektu - body
	const float CMapObjectDescriptor::GetRotationBody() const
	{
		return m_rotation_body;
	}

	//Metoda ustawia obr�t obiektu - body
	void CMapObjectDescriptor::SetRotationBody(float rotation_body)
	{
		m_rotation_body = rotation_body;
	}

	//Metoda zwraca obr�t obiektu - head
	const float CMapObjectDescriptor::GetRotationHead() const
	{
		return m_rotation_head;
	}

	//Metoda ustawia obr�t obiektu - head
	void CMapObjectDescriptor::SetRotationHead(float rotation_head)
	{
		m_rotation_head = rotation_head;
	}

	//Metoda zwraca flaga filtru grafiki - smooth
	const bool CMapObjectDescriptor::GetSmooth() const
	{
		return m_smooth;
	}
		
	//Metoda ustawia flaga filtru grafiki - smooth
	void CMapObjectDescriptor::SetSmooth(bool smooth)
	{
		m_smooth = smooth;
	}
}//namespace mapengine

//Nadanie warto�ci sta�ym sk�adowum statycznym
int mapengine::CMapObjectDescriptor::nextId = 1;
