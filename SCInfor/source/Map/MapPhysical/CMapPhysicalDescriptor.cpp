//  ___________________________________________________
// | CMapPhysicalDescriptor.cpp - class implementation |
// | Jack Flower - March 2015                          |
// |___________________________________________________|
//

#include "CMapPhysicalDescriptor.h"
#include "../../Factory/MapPhysicalFactory/MapPhysicalTemplate.h"
#include "../../Utilities/StringUtils/StringUtils.h"
#include <iostream>

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CMapPhysicalDescriptor);

	//Konstruktor
	CMapPhysicalDescriptor::CMapPhysicalDescriptor()
	:
		p_template		(NULL),
		m_unique_id		(0),
		m_code			(),
		m_name			(),
		m_position		(0.0f, 0.0f),
		m_scale			(1.0f, 1.0f),
		m_rotation		(0.0f),
		m_size			(0.0f, 0.0f),
		m_smooth		(false)
	{
		m_unique_id = nextId++;	//unikalna warto�� identyfikatora zwi�kszana w konstruktorze
		//nazwa z pliku xml, lub liczba wygenerowana...
	}

	//Konstruktor kopiuj�cy
	CMapPhysicalDescriptor::CMapPhysicalDescriptor(const CMapPhysicalDescriptor & CMapPhysicalDescriptorCopy)
	:
		p_template		(CMapPhysicalDescriptorCopy.p_template),
		m_unique_id		(CMapPhysicalDescriptorCopy.m_unique_id),//zerujemy licznik, czy kopia to kopia?
		m_code			(CMapPhysicalDescriptorCopy.m_code),
		m_name			(CMapPhysicalDescriptorCopy.m_name),
		m_position		(CMapPhysicalDescriptorCopy.m_position),
		m_scale			(CMapPhysicalDescriptorCopy.m_scale),
		m_rotation		(CMapPhysicalDescriptorCopy.m_rotation),
		m_size			(CMapPhysicalDescriptorCopy.m_size),
		m_smooth		(CMapPhysicalDescriptorCopy.m_smooth)
	{
	}

	//Destruktor
	CMapPhysicalDescriptor::~CMapPhysicalDescriptor()
	{
		p_template		= NULL;
		m_unique_id		= 0;
		m_code			= "";
		m_name			= "";
		m_position.x	= 0.0f;
		m_position.y	= 0.0f;
		m_scale.x		= 0.0f;
		m_scale.x		= 0.0f;
		m_rotation		= 0.0f;
		m_size.x		= 0.0f;
		m_size.y		= 0.0f;
		m_smooth		= false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CMapPhysicalDescriptor::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda tworzy obiekt mapy
	void CMapPhysicalDescriptor::create()
	{
		CMapPhysical *mapphys = p_template->create(stringutils::ConvertToWString(m_name));
		if (mapphys != 0)
		{
			mapphys->SetTemplate(p_template);
			mapphys->setCode(m_code);
			mapphys->setPosition(m_position);
			mapphys->setScale(m_scale);
			mapphys->setRotation(m_rotation);
			mapphys->setSize(m_size);
			mapphys->setSmooth(m_smooth);
			mapphys->setVisible(m_visible);
		}
	}

	//Metoda zwraca wska�nik na wzorzec fabryczny obiektu
	MapPhysicalTemplate* CMapPhysicalDescriptor::GetTemplate() const
	{ 
		return p_template;
	}

	//Metoda ustawia wska�nik na wzorzec fabryczny obiektu
	void CMapPhysicalDescriptor::SetTemplate(MapPhysicalTemplate* template_param)
	{
		p_template = template_param;
	}

	//Metoda zwraca unikalny identyfikator (nadawany w CMapPhysicalManager)
	const int CMapPhysicalDescriptor::GetUniqueId() const
	{
		return m_unique_id;
	}

	//Metoda zwraca referencj� na nazw� kodu dla typu pod�o�a zapisanego w pliku xml
	const std::string & CMapPhysicalDescriptor::GetCode() const
	{
		return m_code;
	}
		
	//Metoda zwraca nazw� kodu dla typu pod�o�a zapisanego w pliku xml
	void CMapPhysicalDescriptor::SetCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca referencj� na nazw� w�asn� obiektu nadawan� na poziomie wpisu w pliku xml
	const std::string & CMapPhysicalDescriptor::GetName() const
	{
		return m_name;
	}

	//Metoda ustawia nazw� w�asn� obiektu nadawan� na poziomie wpisu w pliku xml
	void CMapPhysicalDescriptor::SetName(const std::string & name)
	{
		m_name = name;
	}

	//Metoda zwraca pozycj� obiektu
	///
	const sf::Vector2f & CMapPhysicalDescriptor::GetPosition() const
	{
		return m_position;
	}

	//Metoda ustawia pozycj� obiektu
	void CMapPhysicalDescriptor::SetPosition(const sf::Vector2f & position)
	{
		m_position = position;
	}

	//Metoda ustawia na pozycj� obiektu
	void CMapPhysicalDescriptor::SetPosition(float position_x, float position_y)
	{
		m_position.x = position_x;
		m_position.y = position_y;
	}

	//Metoda zwraca skal�
	const sf::Vector2f & CMapPhysicalDescriptor::GetScale() const
	{
		return m_scale;
	}
		
	//Metoda ustawia skal�
	void CMapPhysicalDescriptor::SetScale(float x, float y)
	{
		m_scale.x = x;
		m_scale.y = y;
	}

	//Metoda ustawia skal�
	void CMapPhysicalDescriptor::SetScale(const sf::Vector2f & scale)
	{
		m_scale = scale;
	}

	//Metoda ustawia skal�
	void CMapPhysicalDescriptor::SetScale(float factors)
	{
		m_scale.x = factors;
		m_scale.y = factors;
	}

	//Metoda zwraca warto�� obrotu
	float CMapPhysicalDescriptor::GetRotation() const
	{ 
		return m_rotation;
	}

	//Metoda ustawia warto�� obrotu
	void CMapPhysicalDescriptor::SetRotation(float rotation_value)
	{
		m_rotation = rotation_value;
	}

	//Metoda zwraca rozmiar obiektu
	const sf::Vector2f & CMapPhysicalDescriptor::GetSize() const
	{
		return m_size;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysicalDescriptor::SetSize(const sf::Vector2f & size)
	{
		m_size = size;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysicalDescriptor::SetSize(float x, float y)
	{
		m_size.x = x;
		m_size.y = y;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysicalDescriptor::SetSize(float uniform)
	{
		m_size.x = uniform;
		m_size.y = uniform;
	}

	//Metoda zwraca flag� okre�laj�c� filtr wyg�adzaj�cy tekstur�
	const bool CMapPhysicalDescriptor::GetSmooth() const
	{
		return m_smooth;
	}

	//Metoda ustawia flag� okre�laj�c� filtr wyg�adzaj�cy tekstur�
	void CMapPhysicalDescriptor::SetSmooth(bool smooth)
	{
		m_smooth = smooth;
	}

	//Metoda zwraca flag� okre�laj�c� czy obiekt jest widoczny
	const bool CMapPhysicalDescriptor::GetVisible() const
	{
		return m_visible;
	}

	//Metoda ustawia flag� okre�laj�c� czy obiekt b�dzie widoczny
	void CMapPhysicalDescriptor::SetVisible(bool visible)
	{
		m_visible = visible;
	}
}//namespace mapengine

//Nadanie warto�ci sta�ym sk�adowum statycznym
int mapengine::CMapPhysicalDescriptor::nextId = 1;
