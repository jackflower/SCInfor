//  ______________________________________________
// | CPhysicalTemplate.h - class definition       |
// | Jack Flower - November 2012                  |
// |______________________________________________|
//

#ifndef H_PHYSICAL_TEMPLATE_JACK
#define H_PHYSICAL_TEMPLATE_JACK

#include "../ResourceManager/IResource.h"
#include "../Logic/Physical/CPhysical.h"
#include "../Logic/CPhysicalManager.h"
#include "../XML/CXml.h"
#include "../RTTI/RTTI.h"
#include <string>
#include <ostream>
#include <map>
#include <SFML/Graphics/Color.hpp>

///
///Forward declaration
///
namespace xml
{
	class CXml;
}

namespace logic
{
	class CActor;
}

namespace equipment
{
	class CFuelTank;
	class Engine;
}
using namespace resource;
using namespace xml;
using namespace logic;
using namespace equipment;

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich wzorc�w
	///
	class CPhysicalTemplate : public IResource
	{
		RTTI_DECL;

	public:
		
		///
		///Konstruktor
		///
		CPhysicalTemplate(void);

		///
		///Destruktor wirtualny
		///
		virtual ~CPhysicalTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop() = 0;

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool Load(CXml &xml);

		///
		///Wirtualna metoda tworzenie obiekt�w pochodnych klasy CPhysical
		///
		///implementowana przez w pe�ni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual CPhysical* Create(std::wstring id = L"") = 0 ;

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *physical - wska�nik na obiekt klasy CPhysical
		///
		virtual void Fill(CPhysical *physical);

		///
		///Metoda zwraca nazw� pliku zasobu
		///
		inline const std::string& GetFilename() const { return m_templ_filename; }

		//metody pomocnicze - get
		inline std::wstring	  GetGenre()				{ return m_templ_genre;					}
		inline float		  GetCircleRadius()			{ return m_templ_circle_radius;			}
		inline sf::Vector2f & GetRectangleSize()		{ return m_templ_rect_size;				}
		inline sf::Vector2f & GetRectangleSizeBody()	{ return m_templ_rect_size_body;		}
		inline sf::Vector2f & GetRectangleSizeHead()	{ return m_templ_rect_size_head;		}
		inline std::string	& GetTextureNameBody()		{ return m_templ_texture_body;			}
		inline std::string	& GetTextureNameHead()		{ return m_templ_texture_head;			}
		inline float		  GetAltitude()				{ return m_templ_altitude;				}
		inline bool			  GetUseDisplayableBody()	{ return m_templ_use_displayable_body;	}
		inline bool			  GetUseShadowBody()		{ return m_templ_use_shadow_body;		}
		inline bool			  GetUseDisplayableHead()	{ return m_templ_use_displayable_head;	}
		inline bool			  GetUseShadowHead()		{ return m_templ_use_shadow_head;		}
		inline sf::Color	& GetColorBody()			{ return m_templ_color_body;			}
		inline sf::Color	& GetColorHead()			{ return m_templ_color_head;			}
		inline float		  GetScaleBody()			{ return m_templ_scale_body;			}
		inline float		  GetScaleHead()			{ return m_templ_scale_head;			}

	protected:

		std::string			m_templ_filename;				//nazwa pliku xml
		std::string			m_templ_type;					//typ obiektu odczytanego z xml'a, na podstawie kt�rego CResourceManager tworzy zas�b
		std::wstring		m_templ_genre;					//nazwa "gatunku" obiektu (np. robot, human, gun, etc.)
		float				m_templ_circle_radius;			//promie� detekcji kolizji
		sf::Vector2f		m_templ_rect_size;				//wektor przechowuj�cy rozmiar obszaru prostok�tnego
		sf::Vector2f		m_templ_rect_size_body;			//wektor przechowuj�cy rozmiar obszaru prostok�tnego - body
		sf::Vector2f		m_templ_rect_size_head;			//wektor przechowuj�cy rozmiar obszaru prostok�tnego - head
		std::string			m_templ_texture_body;			//nazwa tekstury reprezentacji graficznej obiektu - body
		std::string			m_templ_texture_head;			//nazwa tekstury reprezentacji graficznej obiektu - head
		float				m_templ_altitude;				//warto�� pu�apu obiektu wzgl�dem pod�o�a
		bool				m_templ_use_displayable_body;	//flaga okre�la, czy CPhysical posiada reprezentacj� graficzn� - body
		bool				m_templ_use_shadow_body;		//flaga okre�la, czy CPhysical posiada reprezentacj� graficzn� - body - cie�
		bool				m_templ_use_displayable_head;	//flaga okre�la, czy CPhysical posiada reprezentacj� graficzn� - head
		bool				m_templ_use_shadow_head;		//flaga okre�la, czy CPhysical posiada reprezentacj� graficzn� - head - cie�
		sf::Color			m_templ_color_body;				//kolor - body
		sf::Color			m_templ_color_head;				//kolor - body
		float				m_templ_scale_body;				//skala - body
		float				m_templ_scale_head;				//skala - body
		CPartCollisionData	m_templ_part_collision_data;	//opakowanie informacji o kolidowaniu

	private:

	};
}//namespace factory
#endif //H_PHYSICAL_TEMPLATE_JACK
