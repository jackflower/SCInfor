//  _________________________________________________
// | PhysicalInfoTemplate.h - class definition       |
// | Jack Flower - April 2014                        |
// |_________________________________________________|
//

#ifndef H_PHYSICAL_INFO_TEMPLATE_JACK
#define H_PHYSICAL_INFO_TEMPLATE_JACK

#include "PhysicalTemplate.h"
#include "../Rendering/Displayable/Rectangle.h"
#include "../Logic/Physical/PhysicalInfo/PhysicalInfo.h"

///
///Forward declaration
///
namespace xml
{
	class Xml;
}

using namespace logic;
using namespace rendering::primitives;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec logicznej i graficznej informacji o stanie obiektu
	///
	class PhysicalInfoTemplate : public PhysicalTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		PhysicalInfoTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~PhysicalInfoTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

		///
		///Metoda tworzy obiekt klasy PhysicalInfo
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		PhysicalInfo *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_physical_info - wskaźnik na obiekt klasy PhysicalInfo
		///
		virtual void fill(PhysicalInfo *p_physical_info);
	
	private:

		std::string m_templ_physical_info_name; //nazwa logicznej i graficznej informacji o stanie obiektu
		int m_templ_z_index_rectangle; //indeks warstwy rysowania
		bool m_templ_use_status_bar_energy;	//flaga, czy obiekt posiada progress bar (energia-życie)
		bool m_templ_use_status_bar_fuel; //flaga, czy obiekt posiada progress bar (paliwo/tlen)
		sf::Color m_templ_color_bar_energy; //kolor status progress bar (energia-życie)
		sf::Color m_templ_color_bar_fuel; //kolor status progress bar (paliwo/tlen)
		sf::Vector2f m_templ_size_energy; //rozmiar paska - progress bar (energia-życie)
		sf::Vector2f m_templ_size_fuel; //rozmiar paska - progress bar (paliwo/tlen)
		sf::Vector2f m_templ_position_offset_energy; //wektor kalibracji położenia obiektu - progress bar (energia-życie)
		sf::Vector2f m_templ_position_offset_fuel; //wektor kalibracji położenia obiektu - progress bar (paliwo/tlen)
		Rectangle *p_templ_status_bar_energy; //wskaźnik na obiekt Rectangle (energia-życie)
		Rectangle *p_templ_status_bar_fuel; //wskaźnik na obiekt Rectangle (paliwo/tlen)
		bool m_templ_use_animation; //flaga, czy obiekt używa animacji/tekstury
		bool m_templ_use_texture; //flaga, czy obiekt używa tekstury/animacji
		std::string m_templ_animation_name; //nazwa animacji
		std::string m_templ_texture_name; //nazwa tekstury - static image

	};
}//namespace factory
#endif//H_PHYSICAL_INFO_TEMPLATE_JACK
