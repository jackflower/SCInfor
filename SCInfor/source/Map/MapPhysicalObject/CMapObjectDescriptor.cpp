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
		m_uniqueId = nextId++;	//unikalna wartoœæ identyfikatora zwiêkszana w konstruktorze
	}
	
	//Konstruktor kopiuj¹cy
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

	//Metoda zwraca nazwê znacznika obiektu na mapie
	const std::string & CMapObjectDescriptor::GetCode() const
	{
		return m_code;
	}

	//Metoda ustawia nazwê znacznika obiektu na mapie
	void CMapObjectDescriptor::SetCode(const std::string &code)
	{
		m_code = code;
	}

	//Metoda zwraca nazwê, któr¹ nadajemy obiektowi
	const std::string & CMapObjectDescriptor::GetName() const
	{
		return m_name;
	}

	//Metoda ustawia nazwê, któr¹ nadajemy obiektowi
	void CMapObjectDescriptor::SetName(const std::string & name)
	{
		m_name = name;
	}


	//Metoda zwraca wskaŸnik na wzorzec produkcyjny
	PhysicalTemplate* CMapObjectDescriptor::GetTemplate() const
	{
		return p_templ;
	}

	//Metoda ustawia wskaŸnik na wzorzec produkcyjny
	void CMapObjectDescriptor::SetTemplate(PhysicalTemplate* template_param)
	{
		p_templ = template_param;
	}

	//Metoda zwraca pozycjê obietu - sk³adowa X (plik xml operuje body)
	const float CMapObjectDescriptor::GetXPosition() const
	{
		return m_x_position;
	}

	//Metoda ustawia pozycjê obietu - sk³adowa X (plik xml operuje body)
	void CMapObjectDescriptor::SetXPosition(float x_position)
	{
		m_x_position = x_position;
	}

	//Metoda zwraca pozycjê obietu - sk³adowa Y (plik xml operuje body)
	const float CMapObjectDescriptor::GetYPosition() const
	{
		return m_y_position;
	}

	//Metoda ustawia pozycjê obietu - sk³adowa Y (plik xml operuje body)
	void CMapObjectDescriptor::SetYPosition(float y_position)
	{
		m_y_position = y_position;
	}

	//Metoda zwraca obrót obiektu - body
	const float CMapObjectDescriptor::GetRotationBody() const
	{
		return m_rotation_body;
	}

	//Metoda ustawia obrót obiektu - body
	void CMapObjectDescriptor::SetRotationBody(float rotation_body)
	{
		m_rotation_body = rotation_body;
	}

	//Metoda zwraca obrót obiektu - head
	const float CMapObjectDescriptor::GetRotationHead() const
	{
		return m_rotation_head;
	}

	//Metoda ustawia obrót obiektu - head
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

//Nadanie wartoœci sta³ym sk³adowum statycznym
int mapengine::CMapObjectDescriptor::nextId = 1;
