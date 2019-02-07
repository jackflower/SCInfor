//  _________________________________________________
// | CInformationTemplate.h - class definition       |
// | Jack Flower - April 2015                        |
// |_________________________________________________|
//

#ifndef H_INFORMATION_TEMPLATE_JACK
#define H_INFORMATION_TEMPLATE_JACK

#include "../../ResourceManager/IResource.h"
#include "../../Information/CInformation.h"
#include "../../XML/CXml.h"
#include "../../RTTI/RTTI.h"
#include <string>

using namespace resource;
using namespace xml;
using namespace information;

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich wzorców
	///
	class CInformationTemplate : public IResource
	{
		RTTI_DECL;

	public:
		
		///
		///Konstruktor
		///
		CInformationTemplate(void);

		///
		///Destruktor wirtualny
		///
		virtual ~CInformationTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		virtual void drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml &xml);

		///
		///Wirtualna metoda tworzenie obiektów pochodnych klasy CInformation
		///
		///implementowana przez w pe³ni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual CInformation* create(std::wstring id = L"");// = 0 ;

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *information - wskaŸnik na obiekt klasy CInformation
		///
		virtual void fill(CInformation *information);

		///
		///Metoda zwraca nazwê pliku zasobu
		///
		inline const std::string& GetFilename() const
		{
			return m_templ_filename;
		}

		///
		///Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
		///
		inline const std::string& GetTypeName() const
		{
			return m_templ_type;
		}

		///
		///Metoda zwraca wskaŸnik na graficzn¹ reprezentacjê obiektu - cyfra
		///
		inline const CDisplayable *GetDisplayableDigit() const
		{
			return p_templ_digit_displayable;
		}

		///
		///Metoda zwraca wskaŸnik na graficzn¹ reprezentacjê obiektu - mask
		///
		inline const CDisplayable *GetDisplayableMask() const
		{
			return p_templ_mask_displayable;
		}

		///
		///Metoda zwraca nazwê tekstury - digit
		///
		inline const std::string& GetTextureDigitName() const
		{
			return m_templ_texture_digit_name;
		}

		///
		///Metoda zwraca nazwê tekstury - digit
		///
		inline const std::string& GetTextureMaskName() const
		{
			return m_templ_texture_mask_name;
		}

		///
		///Metoda zwraca referencjê na obiekt klasy sf::Transformable - digit
		///
		inline const sf::Transformable getTransformableDigit() const
		{
			return m_templ_tranformable_digit;
		}
		
		///
		///Metoda ustawia referencjê na obiekt klasy sf::Transformable - digit
		///
		///@param & templ_tranformable_digit - sta³a referencja na obiekt klasy sf::Transformable
		///
		inline void setTransformableDigit(const sf::Transformable & templ_tranformable_digit)
		{
			m_templ_tranformable_digit = templ_tranformable_digit;
		}

		///
		///Metoda zwraca referencjê na obiekt klasy sf::Transformable - mask
		///
		inline const sf::Transformable getTransformableMask() const
		{
			return m_templ_tranformable_mask;
		}

		///
		///Metoda ustawia referencjê na obiekt klasy sf::Transformable - mask
		///
		///@param & templ_tranformable_mask - sta³a referencja na obiekt klasy sf::Transformable
		///
		inline void setTransformableMask(const sf::Transformable & templ_tranformable_mask)
		{
			m_templ_tranformable_mask = templ_tranformable_mask;
		}

	protected:

		std::string			m_templ_filename;			//nazwa pliku xml
		std::string			m_templ_type;				//typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
		CDisplayable*		p_templ_digit_displayable;	//wskaŸnik na graficzn¹ reprezentacjê obiektu - cyfra
		CDisplayable*		p_templ_mask_displayable;	//wskaŸnik na graficzn¹ reprezentacjê obiektu - maska
		std::string			m_templ_texture_digit_name;	//nazwa tekstury - digit
		std::string			m_templ_texture_mask_name;	//nazwa tekstury - mask
		sf::Transformable	m_templ_tranformable_digit;	//opakowanie danych do transforamcji geometrycznej - digit
		sf::Transformable	m_templ_tranformable_mask;	//opakowanie danych do transforamcji geometrycznej - mask

	private:

	};
}//namespace factory
#endif //H_INFORMATION_TEMPLATE_JACK
