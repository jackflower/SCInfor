//  ________________________________________________
// | InformationTemplate.h - class definition       |
// | Jack Flower - April 2015                       |
// |________________________________________________|
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
	class InformationTemplate : public IResource
	{
		RTTI_DECL;

	public:
		
		///
		///Konstruktor
		///
		InformationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~InformationTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		virtual void drop();

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml & xml);

		///
		///Wirtualna metoda tworzenie obiektów pochodnych klasy CInformation
		///
		///implementowana przez w pełni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual CInformation *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *information - wskaźnik na obiekt klasy CInformation
		///
		virtual void fill(CInformation *information);

		///
		///Metoda zwraca nazwę pliku zasobu
		///
		inline const std::string & getFilename() const
		{
			return m_templ_filename;
		}

		///
		///Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
		///
		inline const std::string & getTypeName() const
		{
			return m_templ_type;
		}

		///
		///Metoda zwraca wskaźnik na graficzną reprezentację obiektu - cyfra
		///
		inline const CDisplayable *getDisplayableDigit() const
		{
			return p_templ_digit_displayable;
		}

		///
		///Metoda zwraca wskaźnik na graficzną reprezentację obiektu - mask
		///
		inline const CDisplayable *getDisplayableMask() const
		{
			return p_templ_mask_displayable;
		}

		///
		///Metoda zwraca nazwę tekstury - digit
		///
		inline const std::string & getTextureDigitName() const
		{
			return m_templ_texture_digit_name;
		}

		///
		///Metoda zwraca nazwę tekstury - digit
		///
		inline const std::string & getTextureMaskName() const
		{
			return m_templ_texture_mask_name;
		}

		///
		///Metoda zwraca referencję na obiekt klasy sf::Transformable - digit
		///
		inline const sf::Transformable getTransformableDigit() const
		{
			return m_templ_tranformable_digit;
		}
		
		///
		///Metoda ustawia referencję na obiekt klasy sf::Transformable - digit
		///
		///@param templ_tranformable_digit - stała referencja na obiekt klasy sf::Transformable
		///
		inline void setTransformableDigit(const sf::Transformable & templ_tranformable_digit)
		{
			m_templ_tranformable_digit = templ_tranformable_digit;
		}

		///
		///Metoda zwraca referencję na obiekt klasy sf::Transformable - mask
		///
		inline const sf::Transformable getTransformableMask() const
		{
			return m_templ_tranformable_mask;
		}

		///
		///Metoda ustawia referencję na obiekt klasy sf::Transformable - mask
		///
		///@param templ_tranformable_mask - stała referencja na obiekt klasy sf::Transformable
		///
		inline void setTransformableMask(const sf::Transformable & templ_tranformable_mask)
		{
			m_templ_tranformable_mask = templ_tranformable_mask;
		}

	protected:

		std::string m_templ_filename; //nazwa pliku xml
		std::string m_templ_type; //typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
		CDisplayable *p_templ_digit_displayable; //wskaźnik na graficzną reprezentację obiektu - cyfra
		CDisplayable *p_templ_mask_displayable; //wskaźnik na graficzną reprezentację obiektu - maska
		std::string m_templ_texture_digit_name;	//nazwa tekstury - digit
		std::string m_templ_texture_mask_name;	//nazwa tekstury - mask
		sf::Transformable m_templ_tranformable_digit; //opakowanie danych do transforamcji geometrycznej - digit
		sf::Transformable m_templ_tranformable_mask; //opakowanie danych do transforamcji geometrycznej - mask

	private:

	};
}//namespace factory
#endif //H_INFORMATION_TEMPLATE_JACK
