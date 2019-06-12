//  ____________________________________________
// | MapPhysicalType.cpp - class implementacion |
// | Jack Flower - March 2015                   |
// |____________________________________________|
//

#include "MapPhysicalType.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(MapPhysicalType);

	//Konstruktor
	MapPhysicalType::MapPhysicalType()
	:
		m_code		(),
		p_template	(nullptr)
	{
	}

	//Konstruktor kopiujący
	MapPhysicalType::MapPhysicalType(const MapPhysicalType & MapPhysicalTypeCopy)
	:
		m_code		(MapPhysicalTypeCopy.m_code),
		p_template	(MapPhysicalTypeCopy.p_template)
	{
	}

	//Destruktor
	MapPhysicalType::~MapPhysicalType()
	{
		m_code = "";
		p_template = nullptr;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string MapPhysicalType::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca unikalną nazwę obiektu wzorca nadawaną w pliku xml
	const std::string & MapPhysicalType::getCode() const
	{
		return m_code;
	}

	//Metoda nadaje unikalną nazwę obiektu wzorca nadawaną w pliku xml
	void MapPhysicalType::setCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca wskaźnik na wzorzec fabryczny - obiekt klasy MapPhysicalTemplate
	MapPhysicalTemplate *MapPhysicalType::getTemplate()
	{
		return p_template;
	}
		
	//Metoda ustawia wskaźnik na wzorzec fabryczny - obiekt klasy MapPhysicalTemplate
	void MapPhysicalType::setTemplate(MapPhysicalTemplate *template_param)
	{
		p_template = template_param;
	}
}//namespace mapengine
