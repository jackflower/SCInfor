//  __________________________________________________
// | CPhysicalInfoTemplate.h - class definition       |
// | Jack Flower - April 2014                         |
// |__________________________________________________|
//

#ifndef H_PHYSICAL_INFO_TEMPLATE_JACK
#define H_PHYSICAL_INFO_TEMPLATE_JACK

#include "CPhysicalTemplate.h"
#include "../Rendering/Displayable/CRectangle.h"
#include "../Logic/Physical/PhysicalInfo/CPhysicalInfo.h"
#include <string>

///
///Forward declaration
///
namespace xml
{
	class CXml;
}

using namespace logic;
using namespace rendering::primitives;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec logicznej i graficznej informacji o stanie obiektu
	///
	class CPhysicalInfoTemplate : public CPhysicalTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPhysicalInfoTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CPhysicalInfoTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CPhysicalInfo
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CPhysicalInfo* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_physical_info - wska�nik na obiekt klasy CPhysicalInfo
		///
		virtual void fill(CPhysicalInfo *p_physical_info);
	
	private:

		std::string		m_templ_physical_info_name;		//nazwa logicznej i graficznej informacji o stanie obiektu
		int				m_templ_z_index_rectangle;		//indeks warstwy rysowania
		bool			m_templ_use_status_bar_energy;	//flaga, czy obiekt posiada progress bar (energia-�ycie)
		bool			m_templ_use_status_bar_fuel;	//flaga, czy obiekt posiada progress bar (paliwo/tlen)
		sf::Color		m_templ_color_bar_energy;		//kolor status progress bar (energia-�ycie)
		sf::Color		m_templ_color_bar_fuel;			//kolor status progress bar (paliwo/tlen)
		sf::Vector2f	m_templ_size_energy;			//rozmiar paska - progress bar (energia-�ycie)
		sf::Vector2f	m_templ_size_fuel;				//rozmiar paska - progress bar (paliwo/tlen)
		sf::Vector2f	m_templ_position_offset_energy;	//wektor kalibracji po�o�enia obiektu - progress bar (energia-�ycie)
		sf::Vector2f	m_templ_position_offset_fuel;	//wektor kalibracji po�o�enia obiektu - progress bar (paliwo/tlen)
		CRectangle*		p_templ_status_bar_energy;		//wska�nik na obiekt CRectangle (energia-�ycie)
		CRectangle*		p_templ_status_bar_fuel;		//wska�nik na obiekt CRectangle (paliwo/tlen)
		bool			m_templ_use_animation;			//flaga, czy obiekt u�ywa animacji/tekstury
		bool			m_templ_use_texture;			//flaga, czy obiekt u�ywa tekstury/animacji
		std::string		m_templ_animation_name;			//nazwa animacji
		std::string		m_templ_texture_name;			//nazwa tekstury - static image

	};
}//namespace factory
#endif//H_PHYSICAL_INFO_TEMPLATE_JACK
