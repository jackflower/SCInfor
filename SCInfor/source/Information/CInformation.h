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
	///Klasa bazowa repreentuj¹ca informacjê - graficzna reprezentacja
	///
	class CInformation : public IInformation
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CInfoManager;

		//Aby uzyskaæ obiekt CInformation, nale¿y wywo³aæ CInfoManager::CreateInformation();
		
	protected:

		///
		///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CInfoManager
		///
		///@param & uniqueId - unikalny identyfikator (nadawany w CInfoManager)
		///
		CInformation(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CInformationCopy - parametr - obiekt klasy CInformation
		///
		CInformation(const CInformation &CInformationCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CInfoManager
		///
		virtual ~CInformation();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda ustawia flagê dla obiektów gotowych do destrukcji
		///
		void MarkForDelete();

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CInformationTemplate
		///
		inline CInformationTemplate *GetTemplate() const { return p_template; }

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CInformationTemplate
		///
		///@param *p_template - wskaŸnik na obiekt klasy CInformationTemplate
		///
		inline void SetTemplate(CInformationTemplate* p_template_param) { p_template = p_template_param; }

		///
		///Metoda zwraca nazwê tekstury - digit
		///
		const std::string& GetTextureDigit() const;

		///
		///Metoda ustawia nazwê oraz inicjuje tesktur¹ - digit
		///
		///@param texture_digit - nazwa tekstury
		///
		void SetTextureDigit(const std::string& texture_digit);

		///
		///Metoda zwraca nazwê tekstury - mask
		///
		const std::string& GetTextureMask() const;

		///
		///Metoda ustawia nazwê oraz inicjuje tesktur¹ - mask
		///
		///@param texture_mask - nazwa tekstury
		///
		void SetTextureMask(const std::string& texture_mask);

		///
		///Metoda zwraca pozycjê obiektu - digit
		///
		const sf::Vector2f & getPositionDigit() const;
		
		///
		///Metoda ustawia pozycjê obiektu - digit
		///
		///@param & positon_digit - sta³a referecnaj na obiekt klasy sf::Vector2f
		///
		void setPositionDigit(const sf::Vector2f &position_digit);

		///
		///Metoda ustawia pozycjê obiektu - digit
		///
		///@param x - wspó³rzêdna X
		///
		///@param y - wspó³rzêdna Y
		///
		void setPositionDigit(float x, float y);

		///
		///Metoda zwraca pozycjê obiektu - mask
		///
		const sf::Vector2f & getPositionMask() const;
		
		///
		///Metoda ustawia pozycjê obiektu - mask
		///
		///@param & positon_mask - sta³a referecnaj na obiekt klasy sf::Vector2f
		///
		void setPositionMask(const sf::Vector2f &position_mask);

		///
		///Metoda ustawia pozycjê obiektu - masK
		///
		///@param x - wspó³rzêdna X
		///
		///@param y - wspó³rzêdna Y
		///
		void setPositionMask(float x, float y);

		///
		///Metoda zwraca obrót obiektu - digit
		///
		float getRotationDigit() const;

		///
		///Metoda ustawia obrót obiektu - digit
		///
		///@param angle_digit - k¹t obrotu
		///
		void setRotationDigit(float angle_digit);

		///
		///Metoda obraca obiekt zadany k¹t - digit
		///
		///@param angle_digit - k¹t obrotu
		///
		void rotateDigit(float angle_digit);

		///
		///Metoda zwraca obrót obiektu - mask
		///
		float getRotationMask() const;

		///
		///Metoda ustawia obrót obiektu - mask
		///
		///@param angle_mask - k¹t obrotu
		///
		void setRotationMask(float angle_mask);

		///
		///Metoda obraca obiekt zadany k¹t - mask
		///
		///@param angle_mask - k¹t obrotu
		///
		void rotateMask(float angle_mask);

		///
		///Metoda zwraca wektor skali obiektu - digit
		///
		const sf::Vector2f& getScaleDigit() const;

		///
		///Metoda ustawia skalê obiektu - digit
		///
		///@param &factors_digit - wektor wspó³czynika skali - sta³a referncja na obiekt klasy sf::Vector2f
		///
		void setScaleDigit(const sf::Vector2f& factors_digit);

		///
		///Metoda ustawia skalê obiektu - digit
		///
		///@param factorX_digit - wspó³czynnik X
		///
		///@param factorY_digit - wspó³czynnik Y
		///
		void setScaleDigit(float factorX_digit, float factorY_digit);
		
		///
		///Metoda skaluje obiekt - digit
		///
		///@param &factor_digit - wspó³czynnik skali
		///
		void scaleDigit(const sf::Vector2f& factor_digit);

		///
		///Metoda skaluje obiekt - digit
		///
		///@param factorX_digit - wspó³czynnik X
		///
		///@param factorY_digit - wspó³czynnik Y
		///
		void scaleDigit(float factorX_digit, float factorY_digit);

		///
		///Metoda zwraca wektor skali obiektu - mask
		///
		const sf::Vector2f& getScaleMask() const;

		///
		///Metoda ustawia skalê obiektu - mask
		///
		///@param &factors_mask - wektor wspó³czynika skali - sta³a referncja na obiekt klasy sf::Vector2f
		///
		void setScaleMask(const sf::Vector2f& factors_mask);

		///
		///Metoda ustawia skalê obiektu - mask
		///
		///@param factorX_mask - wspó³czynnik X
		///
		///@param factorY_mask - wspó³czynnik Y
		///
		void setScaleMask(float factorX_mask, float factorY_mask);
		
		///
		///Metoda skaluje obiekt - mask
		///
		///@param &factor_mask - wspó³czynnik skali
		///
		void scaleMask(const sf::Vector2f& factor_mask);

		///
		///Metoda skaluje obiekt - mask
		///
		///@param factorX_mask - wspó³czynnik X
		///
		///@param factorY_mask - wspó³czynnik Y
		///
		void scaleMask(float factorX_mask, float factorY_mask);

		///
		///Metoda zwraca origin obiektu - digit
		///
		const sf::Vector2f& getOriginDigit() const;

		///
		///Metoda ustawia origin obiektu - digit
		///
		///@param &origin_digit - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void setOriginDigit(const sf::Vector2f& origin_digit);

		///
		///Metoda ustawia origin obiektu - digit
		///
		///@param x - wspó³rzêdna X
		///
		///@param y - wspó³rzêdna Y
		///
		void setOriginDigit(float x, float y);

		///
		///Metoda zwraca origin obiektu - mask
		///
		const sf::Vector2f& getOriginMask() const;

		///
		///Metoda ustawia origin obiektu - mask
		///
		///@param &origin_mask - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void setOriginMask(const sf::Vector2f& origin_mask);

		///
		///Metoda ustawia origin obiektu - mask
		///
		///@param x - wspó³rzêdna X
		///
		///@param y - wspó³rzêdna Y
		///
		void setOriginMask(float x, float y);

		///
		///Metoda zwraca pozycjê obiektu
		///
		const sf::Vector2f & getPosition() const;
		
		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param & positon - sta³a referecnaj na obiekt klasy sf::Vector2f
		///
		void setPosition(const sf::Vector2f &position);

		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param x - wspó³rzêdna X
		///
		///@param y - wspó³rzêdna Y
		///
		void setPosition(float x, float y);

		///
		///Metoda zwraca obrót obiektu
		///
		float getRotation() const;

		///
		///Metoda ustawia obrót obiektu
		///
		///@param angle - k¹t obrotu
		///
		void setRotation(float angle);

		///
		///Metoda obraca obiekt zadany k¹t
		///
		///@param angle - k¹t obrotu
		///
		void rotate(float angle);

		///
		///Metoda zwraca wektor skali obiektu
		///
		const sf::Vector2f& getScale() const;

		///
		///Metoda ustawia skalê obiektu
		///
		///@param &factors - wektor wspó³czynika skali - sta³a referncja na obiekt klasy sf::Vector2f
		///
		void setScale(const sf::Vector2f& factors);

		///
		///Metoda ustawia skalê obiektu
		///
		///@param factorXt - wspó³czynnik X
		///
		///@param factorY - wspó³czynnik Y
		///
		void setScale(float factorX, float factorY);
		
		///
		///Metoda skaluje obiekt
		///
		///@param &factor - wspó³czynnik skali
		///
		void scale(const sf::Vector2f& factor);

		///
		///Metoda skaluje obiekt
		///
		///@param factorX - wspó³czynnik X
		///
		///@param factorY - wspó³czynnik Y
		///
		void scale(float factorX, float factorY);

		///
		///Metoda zwraca origin obiektu
		///
		const sf::Vector2f& getOrigin() const;

		///
		///Metoda ustawia origin obiektu
		///
		///@param &origin - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void setOrigin(const sf::Vector2f& origin);

		///
		///Metoda ustawia origin obiektu
		///
		///@param x - wspó³rzêdna X
		///
		///@param y - wspó³rzêdna Y
		///
		void setOrigin(float x, float y);

		///
		///Metoda zwraca referencjê na obiekt klasy sf::Transformable - digit
		///
		sf::Transformable &getTransformableDigit();

		///
		///Metoda ustawia referencjê na obiekt klasy sf::Transformable - digit
		///
		///@param & tranformable_digit - sta³a referencja na obiekt klasy sf::Transformable
		///
		void setTransformableDigit(const sf::Transformable & tranformable_digit);

		///
		///Metoda zwraca referencjê na obiekt klasy sf::Transformable - mask
		///
		sf::Transformable &getTransformableMask();

		///
		///Metoda ustawia referencjê na obiekt klasy sf::Transformable - mask
		///
		///@param & tranformable_mask - sta³a referencja na obiekt klasy sf::Transformable
		///
		void setTransformableMask(const sf::Transformable & tranformable_mask);

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

	protected:

		CDisplayable*			p_digit_displayable;	//wskaŸnik na graficzn¹ reprezentacjê obiektu - cyfra
		CDisplayable*			p_mask_displayable;		//wskaŸnik na graficzn¹ reprezentacjê obiektu - maska
		std::string				m_texture_digit_name;	//nazwa tekstury - digit
		std::string				m_texture_mask_name;	//nazwa tekstury - mask
		CInformationTemplate*	p_template;				//wskaŸnik na wzorzec
		sf::Transformable		m_tranformable_digit;	//opakowanie danych do transforamcji geometrycznej - digit
		sf::Transformable		m_tranformable_mask;	//opakowanie danych do transforamcji geometrycznej - mask

	private:

		//prywatna metoda sprawdza, czy trzeba utworzyæ
		//obiekt klasy CDisplayable (digit),
		//np. gdy chcemy dodaæ teksturê, animacjê, syntetyk, etc...
		void checkDisplayable_digit();

		//prywatna metoda sprawdza, czy trzeba utworzyæ
		//obiekt klasy CDisplayable (mask),
		//np. gdy chcemy dodaæ teksturê, animacjê, syntetyk, etc...
		void checkDisplayable_mask();

	};
}//namespace information
#endif//H_INFORMATION_JACK
