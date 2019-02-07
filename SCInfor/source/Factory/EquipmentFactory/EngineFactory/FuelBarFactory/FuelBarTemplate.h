//  ____________________________________________
// | FuelBarTemplate.h - class definition       |
// | Jack Flower - November 2014                |
// |____________________________________________|
//

#ifndef H_FUEL_BAR_TEMPLATE_JACK
#define H_FUEL_BAR_TEMPLATE_JACK

#include "../../../../ResourceManager/IResource.h"
#include "../../../../Factory/CActorTemplate.h"
#include "../../../../XML/CXml.h"
#include "../../../../RTTI/RTTI.h"
#include "../../../../Equipment/Engine/FuelBar/FuelBar.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec progress bar - paliwo
	///
	class FuelBarTemplate : public IResource
	{
		RTTI_DECL;

	public:
		
		///
		///Konstruktor
		///
		FuelBarTemplate(void);

		///
		///Destruktor
		///
		~FuelBarTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

		///
		///Wirtualna metoda ładująca dane
		///
		///@param &name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy FuelBar
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		FuelBar *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_fuelbar - wskaźnik na obiekt klasy FuelBar
		///
		virtual void fill(FuelBar *p_fuelbar);

	private:

		std::string	 m_templ_fuelbar_name; //nazwa wskaźnika paliwa - progress bar
		float m_templ_thickness; //grubość paska - progress bar
		sf::Vector2f m_templ_size; //rozmiar paska - progress bar
		sf::Vector2f m_templ_position_offset; //wektor kalibracji położenia obiektu - progress bar
		sf::Color m_templ_color; //kolor paska - progress bar
	};
}//namespace factory
#endif//H_FUEL_BAR_TEMPLATE_JACK
