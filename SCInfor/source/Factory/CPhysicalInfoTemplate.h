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
		///Wirtualna metoda zwalniajπca zasÛb - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ≥adujπca dane
		///
		///@param &name - sta≥a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda ≥adujπca dane z xml
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
		///Wirtualna metoda wype≥niajπca wskazany obiekt danymi tej klasy
		///
		///@param *p_physical_info - wskaünik na obiekt klasy CPhysicalInfo
		///
		virtual void fill(CPhysicalInfo *p_physical_info);
	
	private:

		std::string		m_templ_physical_info_name;		//nazwa logicznej i graficznej informacji o stanie obiektu
		int				m_templ_z_index_rectangle;		//indeks warstwy rysowania
		bool			m_templ_use_status_bar_energy;	//flaga, czy obiekt posiada progress bar (energia-øycie)
		bool			m_templ_use_status_bar_fuel;	//flaga, czy obiekt posiada progress bar (paliwo/tlen)
		sf::Color		m_templ_color_bar_energy;		//kolor status progress bar (energia-øycie)
		sf::Color		m_templ_color_bar_fuel;			//kolor status progress bar (paliwo/tlen)
		sf::Vector2f	m_templ_size_energy;			//rozmiar paska - progress bar (energia-øycie)
		sf::Vector2f	m_templ_size_fuel;				//rozmiar paska - progress bar (paliwo/tlen)
		sf::Vector2f	m_templ_position_offset_energy;	//wektor kalibracji po≥oøenia obiektu - progress bar (energia-øycie)
		sf::Vector2f	m_templ_position_offset_fuel;	//wektor kalibracji po≥oøenia obiektu - progress bar (paliwo/tlen)
		CRectangle*		p_templ_status_bar_energy;		//wskaünik na obiekt CRectangle (energia-øycie)
		CRectangle*		p_templ_status_bar_fuel;		//wskaünik na obiekt CRectangle (paliwo/tlen)
		bool			m_templ_use_animation;			//flaga, czy obiekt uøywa animacji/tekstury
		bool			m_templ_use_texture;			//flaga, czy obiekt uøywa tekstury/animacji
		std::string		m_templ_animation_name;			//nazwa animacji
		std::string		m_templ_texture_name;			//nazwa tekstury - static image

	};
}//namespace factory
#endif//H_PHYSICAL_INFO_TEMPLATE_JACK
