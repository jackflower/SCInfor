//  _____________________________________________
// | CFuelBarTemplate.h - definicja klasy.       |
// | Jack Flower - November 2014.                |
// |_____________________________________________|
//

#ifndef H_FUEL_BAR_TEMPLATE_JACK
#define H_FUEL_BAR_TEMPLATE_JACK

#include "../../../../ResourceManager/IResource.h"
#include "../../../../Factory/CActorTemplate.h"
#include "../../../../XML/CXml.h"
#include "../../../../RTTI/RTTI.h"
#include "../../../../Equipment/Engine/FuelBar/CFuelBar.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec progress bar - paliwo
	///
	class CFuelBarTemplate : public IResource
	{
		RTTI_DECL;

	public:
		
		///
		///Konstruktor
		///
		CFuelBarTemplate(void);

		///
		///Destruktor
		///
		~CFuelBarTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop();

		///
		///Wirtualna metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CFuelBar
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CFuelBar* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_fuelbar - wska�nik na obiekt klasy CFuelBar
		///
		virtual void Fill(CFuelBar *p_fuelbar);

	private:

		std::string		m_templ_fuelbar_name;		//nazwa wska�nika paliwa - progress bar
		float			m_templ_thickness;			//grubo�� paska - progress bar
		sf::Vector2f	m_templ_size;				//rozmiar paska - progress bar
		sf::Vector2f	m_templ_position_offset;	//wektor kalibracji po�o�enia obiektu - progress bar
		sf::Color		m_templ_color;				//kolor paska - progress bar
	};
}//namespace factory
#endif//H_FUEL_BAR_TEMPLATE_JACK