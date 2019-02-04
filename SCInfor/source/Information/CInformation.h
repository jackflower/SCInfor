//  _________________________________________
// | CInformation.h - class definition       |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#ifndef H_INFORMATION_JACK
#define H_INFORMATION_JACK

#include "../RTTI/RTTI.h"
#include "IInformation.h"
#include "../Rendering/Displayable/CDisplayable.h"
#include <string>

///
///Forward declaration
///
namespace rendering
{
	namespace displayable
	{
		class CDisplayable;
	}
}

namespace infologic
{
	class CInfoManager;
}

namespace factory
{
	class CInformationTemplate;
}

using namespace infologic;
using namespace rendering::displayable;
using namespace factory;

namespace information
{
	///
	///Klasa bazowa repreentuj�ca informacj� - graficzna reprezentacja
	///
	class CInformation : public IInformation
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CInfoManager;

		//Aby uzyska� obiekt CInformation, nale�y wywo�a� CInfoManager::CreateInformation();
		
	protected:

		///
		///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CInfoManager
		///
		///@param & uniqueId - unikalny identyfikator (nadawany w CInfoManager)
		///
		CInformation(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CInformationCopy - parametr - obiekt klasy CInformation
		///
		CInformation(const CInformation &CInformationCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CInfoManager
		///
		virtual ~CInformation();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda ustawia flag� dla obiekt�w gotowych do destrukcji
		///
		void MarkForDelete();

		///
		///Metoda zwraca wska�nik na obiekt klasy CInformationTemplate
		///
		inline CInformationTemplate *GetTemplate() const { return p_template; }

		///
		///Metoda ustawia wska�nik na obiekt klasy CInformationTemplate
		///
		///@param *p_template - wska�nik na obiekt klasy CInformationTemplate
		///
		inline void SetTemplate(CInformationTemplate* p_template_param) { p_template = p_template_param; }

		///
		///Metoda zwraca nazw� tekstury - digit
		///
		const std::string& GetTextureDigit() const;

		///
		///Metoda ustawia nazw� oraz inicjuje tesktur� - digit
		///
		///@param texture_digit - nazwa tekstury
		///
		void SetTextureDigit(const std::string& texture_digit);

		///
		///Metoda zwraca nazw� tekstury - mask
		///
		const std::string& GetTextureMask() const;

		///
		///Metoda ustawia nazw� oraz inicjuje tesktur� - mask
		///
		///@param texture_mask - nazwa tekstury
		///
		void SetTextureMask(const std::string& texture_mask);

		///
		///Metoda zwraca pozycj� obiektu - digit
		///
		const sf::Vector2f & getPositionDigit() const;
		
		///
		///Metoda ustawia pozycj� obiektu - digit
		///
		///@param & positon_digit - sta�a referecnaj na obiekt klasy sf::Vector2f
		///
		void setPositionDigit(const sf::Vector2f &position_digit);

		///
		///Metoda ustawia pozycj� obiektu - digit
		///
		///@param x - wsp�rz�dna X
		///
		///@param y - wsp�rz�dna Y
		///
		void setPositionDigit(float x, float y);

		///
		///Metoda zwraca pozycj� obiektu - mask
		///
		const sf::Vector2f & getPositionMask() const;
		
		///
		///Metoda ustawia pozycj� obiektu - mask
		///
		///@param & positon_mask - sta�a referecnaj na obiekt klasy sf::Vector2f
		///
		void setPositionMask(const sf::Vector2f &position_mask);

		///
		///Metoda ustawia pozycj� obiektu - masK
		///
		///@param x - wsp�rz�dna X
		///
		///@param y - wsp�rz�dna Y
		///
		void setPositionMask(float x, float y);

		///
		///Metoda zwraca obr�t obiektu - digit
		///
		float getRotationDigit() const;

		///
		///Metoda ustawia obr�t obiektu - digit
		///
		///@param angle_digit - k�t obrotu
		///
		void setRotationDigit(float angle_digit);

		///
		///Metoda obraca obiekt zadany k�t - digit
		///
		///@param angle_digit - k�t obrotu
		///
		void rotateDigit(float angle_digit);

		///
		///Metoda zwraca obr�t obiektu - mask
		///
		float getRotationMask() const;

		///
		///Metoda ustawia obr�t obiektu - mask
		///
		///@param angle_mask - k�t obrotu
		///
		void setRotationMask(float angle_mask);

		///
		///Metoda obraca obiekt zadany k�t - mask
		///
		///@param angle_mask - k�t obrotu
		///
		void rotateMask(float angle_mask);

		///
		///Metoda zwraca wektor skali obiektu - digit
		///
		const sf::Vector2f& getScaleDigit() const;

		///
		///Metoda ustawia skal� obiektu - digit
		///
		///@param &factors_digit - wektor wsp�czynika skali - sta�a referncja na obiekt klasy sf::Vector2f
		///
		void setScaleDigit(const sf::Vector2f& factors_digit);

		///
		///Metoda ustawia skal� obiektu - digit
		///
		///@param factorX_digit - wsp�czynnik X
		///
		///@param factorY_digit - wsp�czynnik Y
		///
		void setScaleDigit(float factorX_digit, float factorY_digit);
		
		///
		///Metoda skaluje obiekt - digit
		///
		///@param &factor_digit - wsp�czynnik skali
		///
		void scaleDigit(const sf::Vector2f& factor_digit);

		///
		///Metoda skaluje obiekt - digit
		///
		///@param factorX_digit - wsp�czynnik X
		///
		///@param factorY_digit - wsp�czynnik Y
		///
		void scaleDigit(float factorX_digit, float factorY_digit);

		///
		///Metoda zwraca wektor skali obiektu - mask
		///
		const sf::Vector2f& getScaleMask() const;

		///
		///Metoda ustawia skal� obiektu - mask
		///
		///@param &factors_mask - wektor wsp�czynika skali - sta�a referncja na obiekt klasy sf::Vector2f
		///
		void setScaleMask(const sf::Vector2f& factors_mask);

		///
		///Metoda ustawia skal� obiektu - mask
		///
		///@param factorX_mask - wsp�czynnik X
		///
		///@param factorY_mask - wsp�czynnik Y
		///
		void setScaleMask(float factorX_mask, float factorY_mask);
		
		///
		///Metoda skaluje obiekt - mask
		///
		///@param &factor_mask - wsp�czynnik skali
		///
		void scaleMask(const sf::Vector2f& factor_mask);

		///
		///Metoda skaluje obiekt - mask
		///
		///@param factorX_mask - wsp�czynnik X
		///
		///@param factorY_mask - wsp�czynnik Y
		///
		void scaleMask(float factorX_mask, float factorY_mask);

		///
		///Metoda zwraca origin obiektu - digit
		///
		const sf::Vector2f& getOriginDigit() const;

		///
		///Metoda ustawia origin obiektu - digit
		///
		///@param &origin_digit - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void setOriginDigit(const sf::Vector2f& origin_digit);

		///
		///Metoda ustawia origin obiektu - digit
		///
		///@param x - wsp�rz�dna X
		///
		///@param y - wsp�rz�dna Y
		///
		void setOriginDigit(float x, float y);

		///
		///Metoda zwraca origin obiektu - mask
		///
		const sf::Vector2f& getOriginMask() const;

		///
		///Metoda ustawia origin obiektu - mask
		///
		///@param &origin_mask - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void setOriginMask(const sf::Vector2f& origin_mask);

		///
		///Metoda ustawia origin obiektu - mask
		///
		///@param x - wsp�rz�dna X
		///
		///@param y - wsp�rz�dna Y
		///
		void setOriginMask(float x, float y);

		///
		///Metoda zwraca pozycj� obiektu
		///
		const sf::Vector2f & getPosition() const;
		
		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param & positon - sta�a referecnaj na obiekt klasy sf::Vector2f
		///
		void setPosition(const sf::Vector2f &position);

		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param x - wsp�rz�dna X
		///
		///@param y - wsp�rz�dna Y
		///
		void setPosition(float x, float y);

		///
		///Metoda zwraca obr�t obiektu
		///
		float getRotation() const;

		///
		///Metoda ustawia obr�t obiektu
		///
		///@param angle - k�t obrotu
		///
		void setRotation(float angle);

		///
		///Metoda obraca obiekt zadany k�t
		///
		///@param angle - k�t obrotu
		///
		void rotate(float angle);

		///
		///Metoda zwraca wektor skali obiektu
		///
		const sf::Vector2f& getScale() const;

		///
		///Metoda ustawia skal� obiektu
		///
		///@param &factors - wektor wsp�czynika skali - sta�a referncja na obiekt klasy sf::Vector2f
		///
		void setScale(const sf::Vector2f& factors);

		///
		///Metoda ustawia skal� obiektu
		///
		///@param factorXt - wsp�czynnik X
		///
		///@param factorY - wsp�czynnik Y
		///
		void setScale(float factorX, float factorY);
		
		///
		///Metoda skaluje obiekt
		///
		///@param &factor - wsp�czynnik skali
		///
		void scale(const sf::Vector2f& factor);

		///
		///Metoda skaluje obiekt
		///
		///@param factorX - wsp�czynnik X
		///
		///@param factorY - wsp�czynnik Y
		///
		void scale(float factorX, float factorY);

		///
		///Metoda zwraca origin obiektu
		///
		const sf::Vector2f& getOrigin() const;

		///
		///Metoda ustawia origin obiektu
		///
		///@param &origin - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void setOrigin(const sf::Vector2f& origin);

		///
		///Metoda ustawia origin obiektu
		///
		///@param x - wsp�rz�dna X
		///
		///@param y - wsp�rz�dna Y
		///
		void setOrigin(float x, float y);

		///
		///Metoda zwraca referencj� na obiekt klasy sf::Transformable - digit
		///
		sf::Transformable &getTransformableDigit();

		///
		///Metoda ustawia referencj� na obiekt klasy sf::Transformable - digit
		///
		///@param & tranformable_digit - sta�a referencja na obiekt klasy sf::Transformable
		///
		void setTransformableDigit(const sf::Transformable & tranformable_digit);

		///
		///Metoda zwraca referencj� na obiekt klasy sf::Transformable - mask
		///
		sf::Transformable &getTransformableMask();

		///
		///Metoda ustawia referencj� na obiekt klasy sf::Transformable - mask
		///
		///@param & tranformable_mask - sta�a referencja na obiekt klasy sf::Transformable
		///
		void setTransformableMask(const sf::Transformable & tranformable_mask);

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

	protected:

		CDisplayable*			p_digit_displayable;	//wska�nik na graficzn� reprezentacj� obiektu - cyfra
		CDisplayable*			p_mask_displayable;		//wska�nik na graficzn� reprezentacj� obiektu - maska
		std::string				m_texture_digit_name;	//nazwa tekstury - digit
		std::string				m_texture_mask_name;	//nazwa tekstury - mask
		CInformationTemplate*	p_template;				//wska�nik na wzorzec
		sf::Transformable		m_tranformable_digit;	//opakowanie danych do transforamcji geometrycznej - digit
		sf::Transformable		m_tranformable_mask;	//opakowanie danych do transforamcji geometrycznej - mask

	private:

		//prywatna metoda sprawdza, czy trzeba utworzy�
		//obiekt klasy CDisplayable (digit),
		//np. gdy chcemy doda� tekstur�, animacj�, syntetyk, etc...
		void checkDisplayable_digit();

		//prywatna metoda sprawdza, czy trzeba utworzy�
		//obiekt klasy CDisplayable (mask),
		//np. gdy chcemy doda� tekstur�, animacj�, syntetyk, etc...
		void checkDisplayable_mask();

	};
}//namespace information
#endif//H_INFORMATION_JACK
