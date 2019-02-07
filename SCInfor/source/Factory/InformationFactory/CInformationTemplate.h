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
	///Klasa reprezentuje prawzorzec wszystkich wzorc�w
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
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		virtual void drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml &xml);

		///
		///Wirtualna metoda tworzenie obiekt�w pochodnych klasy CInformation
		///
		///implementowana przez w pe�ni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual CInformation* create(std::wstring id = L"");// = 0 ;

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *information - wska�nik na obiekt klasy CInformation
		///
		virtual void fill(CInformation *information);

		///
		///Metoda zwraca nazw� pliku zasobu
		///
		inline const std::string& GetFilename() const
		{
			return m_templ_filename;
		}

		///
		///Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie kt�rego CResourceManager tworzy zas�b
		///
		inline const std::string& GetTypeName() const
		{
			return m_templ_type;
		}

		///
		///Metoda zwraca wska�nik na graficzn� reprezentacj� obiektu - cyfra
		///
		inline const CDisplayable *GetDisplayableDigit() const
		{
			return p_templ_digit_displayable;
		}

		///
		///Metoda zwraca wska�nik na graficzn� reprezentacj� obiektu - mask
		///
		inline const CDisplayable *GetDisplayableMask() const
		{
			return p_templ_mask_displayable;
		}

		///
		///Metoda zwraca nazw� tekstury - digit
		///
		inline const std::string& GetTextureDigitName() const
		{
			return m_templ_texture_digit_name;
		}

		///
		///Metoda zwraca nazw� tekstury - digit
		///
		inline const std::string& GetTextureMaskName() const
		{
			return m_templ_texture_mask_name;
		}

		///
		///Metoda zwraca referencj� na obiekt klasy sf::Transformable - digit
		///
		inline const sf::Transformable getTransformableDigit() const
		{
			return m_templ_tranformable_digit;
		}
		
		///
		///Metoda ustawia referencj� na obiekt klasy sf::Transformable - digit
		///
		///@param & templ_tranformable_digit - sta�a referencja na obiekt klasy sf::Transformable
		///
		inline void setTransformableDigit(const sf::Transformable & templ_tranformable_digit)
		{
			m_templ_tranformable_digit = templ_tranformable_digit;
		}

		///
		///Metoda zwraca referencj� na obiekt klasy sf::Transformable - mask
		///
		inline const sf::Transformable getTransformableMask() const
		{
			return m_templ_tranformable_mask;
		}

		///
		///Metoda ustawia referencj� na obiekt klasy sf::Transformable - mask
		///
		///@param & templ_tranformable_mask - sta�a referencja na obiekt klasy sf::Transformable
		///
		inline void setTransformableMask(const sf::Transformable & templ_tranformable_mask)
		{
			m_templ_tranformable_mask = templ_tranformable_mask;
		}

	protected:

		std::string			m_templ_filename;			//nazwa pliku xml
		std::string			m_templ_type;				//typ obiektu odczytanego z xml'a, na podstawie kt�rego CResourceManager tworzy zas�b
		CDisplayable*		p_templ_digit_displayable;	//wska�nik na graficzn� reprezentacj� obiektu - cyfra
		CDisplayable*		p_templ_mask_displayable;	//wska�nik na graficzn� reprezentacj� obiektu - maska
		std::string			m_templ_texture_digit_name;	//nazwa tekstury - digit
		std::string			m_templ_texture_mask_name;	//nazwa tekstury - mask
		sf::Transformable	m_templ_tranformable_digit;	//opakowanie danych do transforamcji geometrycznej - digit
		sf::Transformable	m_templ_tranformable_mask;	//opakowanie danych do transforamcji geometrycznej - mask

	private:

	};
}//namespace factory
#endif //H_INFORMATION_TEMPLATE_JACK
