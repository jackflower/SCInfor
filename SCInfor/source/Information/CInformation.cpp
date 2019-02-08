//  _________________________________________
// | CInformation.cpp - class implementation |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#include "CInformation.h"
#include "../Rendering/Drawable/CDrawableManager.h"
#include "../Factory/InformationFactory/InformationTemplate.h"

namespace information
{
	RTTI_IMPL(CInformation, IInformation);

	//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CInfoManager
	CInformation::CInformation(const std::wstring& uniqueId)
	:
		IInformation			(uniqueId),//chroniony konstruktor klasy bazowej
		p_digit_displayable		(NULL),
		p_mask_displayable		(NULL),
		m_texture_digit_name	(""),
		m_texture_mask_name		(""),
		p_template				(NULL),
		m_tranformable_digit	(),
		m_tranformable_mask		()
	{
	}

	//Chroniony konstruktor kopiuj¹cy
	CInformation::CInformation(const CInformation &CInformationCopy)
	:
		IInformation			(CInformationCopy),//chroniony konstruktor kopiuj¹cy klasy bazowej
		p_digit_displayable		(CInformationCopy.p_digit_displayable),
		p_mask_displayable		(CInformationCopy.p_mask_displayable),
		m_texture_digit_name	(CInformationCopy.m_texture_digit_name),
		m_texture_mask_name		(CInformationCopy.m_texture_mask_name),
		p_template				(CInformationCopy.p_template),
		m_tranformable_digit	(CInformationCopy.m_tranformable_digit),
		m_tranformable_mask		(CInformationCopy.m_tranformable_mask)
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CInfoManager
	CInformation::~CInformation()
	{
		if (p_digit_displayable != NULL)
			gDrawableManager.DestroyDrawable(p_digit_displayable);
		if (p_mask_displayable != NULL)
			gDrawableManager.DestroyDrawable(p_mask_displayable);
		m_texture_digit_name	= "";
		m_texture_mask_name		= "";
		p_template				= NULL;
		//m_tranformable_digit	not edit
		//m_tranformable_mask	not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CInformation::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda ustawia flagê dla obiektów gotowych do destrukcji
	void CInformation::MarkForDelete()
	{
		m_ready_for_destruction = true;
	}

	//Metoda zwraca nazwê tekstury - digit
	const std::string& CInformation::GetTextureDigit() const
	{
		return m_texture_digit_name;
	}

	//Metoda ustatawia teksturê - digit
	void CInformation::SetTextureDigit(const std::string& texture_digit)
	{
		m_texture_digit_name = texture_digit;	//ustawiam nazwê dla tekstury
		checkDisplayable_digit();				//spradzam, czy obiekt renderowalny jest zainicjowany
		if (p_digit_displayable)				//jeœli tak - ustawiam jego teksturê
			p_digit_displayable->setTexture(texture_digit);
	}

	//Metoda zwraca nazwê tekstury - mask
	const std::string& CInformation::GetTextureMask() const
	{
		return m_texture_mask_name;
	}

	//Metoda ustawia nazwê oraz inicjuje tesktur¹ - mask
	void CInformation::SetTextureMask(const std::string& texture_mask)
	{
		m_texture_mask_name = texture_mask;		//ustawiam nazwê dla tekstury
		checkDisplayable_mask();				//spradzam, czy obiekt renderowalny jest zainicjowany
		if (p_mask_displayable)					//jeœli tak - ustawiam jego teksturê
			p_mask_displayable->setTexture(texture_mask);
	}

	//Metoda zwraca pozycjê obiektu - digit
	const sf::Vector2f & CInformation::getPositionDigit() const
	{
		return m_tranformable_digit.getPosition();
	}

	//Metoda ustawia pozycjê obiektu - digit
	void CInformation::setPositionDigit(const sf::Vector2f &position_digit)
	{
		m_tranformable_digit.setPosition(position_digit);
		if(p_digit_displayable)
			p_digit_displayable->setPosition(position_digit);
	}

	//Metoda ustawia pozycjê obiektu
	void CInformation::setPositionDigit(float x, float y)
	{
		m_tranformable_digit.setPosition(x, y);
		if(p_digit_displayable)
			p_digit_displayable->setPosition(x, y);
	}

	//Metoda zwraca pozycjê obiektu - mask
	const sf::Vector2f & CInformation::getPositionMask() const
	{
		return m_tranformable_mask.getPosition();
	}
		
	//Metoda ustawia pozycjê obiektu - mask
	void CInformation::setPositionMask(const sf::Vector2f &position_mask)
	{
		m_tranformable_mask.setPosition(position_mask);
		if(p_mask_displayable)
			p_mask_displayable->setPosition(position_mask);
	}

	//Metoda ustawia pozycjê obiektu - mask
	void CInformation::setPositionMask(float x, float y)
	{
		m_tranformable_mask.setPosition(x, y);
		if(p_mask_displayable)
			p_mask_displayable->setPosition(x, y);
	}

	//Metoda zwraca obrót obiektu - digit
	float CInformation::getRotationDigit() const
	{
		return m_tranformable_digit.getRotation();
	}

	//Metoda ustawia obrót obiektu - digit
	void CInformation::setRotationDigit(float angle_digit)
	{
		m_tranformable_digit.setRotation(angle_digit);
		if(p_digit_displayable)
			p_digit_displayable->setRotation(angle_digit);
	}

	//Metoda obraca obiekt zadany k¹t - digit
	void CInformation::rotateDigit(float angle_digit)
	{
		m_tranformable_digit.rotate(angle_digit);
		if(p_digit_displayable)
			p_digit_displayable->rotate(angle_digit);
	}

	//Metoda zwraca obrót obiektu - mask
	float CInformation::getRotationMask() const
	{
		return m_tranformable_mask.getRotation();
	}

	//Metoda ustawia obrót obiektu - mask
	void CInformation::setRotationMask(float angle_mask)
	{
		m_tranformable_mask.setRotation(angle_mask);
		if(p_mask_displayable)
			p_mask_displayable->setRotation(angle_mask);
	}

	//Metoda obraca obiekt zadany k¹t - mask
	void CInformation::rotateMask(float angle_mask)
	{
		m_tranformable_mask.rotate(angle_mask);
		if(p_mask_displayable)
			p_mask_displayable->rotate(angle_mask);
	}

	//Metoda zwraca wektor skali obiektu - digit
	const sf::Vector2f& CInformation::getScaleDigit() const
	{
		return m_tranformable_digit.getScale();
	}

	//Metoda ustawia skalê obiektu - digit
	void CInformation::setScaleDigit(const sf::Vector2f& factors_digit)
	{
		m_tranformable_digit.setScale(factors_digit);
		if(p_digit_displayable)
			p_digit_displayable->setScale(factors_digit);
	}

	//Metoda ustawia skalê obiektu - digit
	void CInformation::setScaleDigit(float factorX_digit, float factorY_digit)
	{
		m_tranformable_digit.setScale(factorX_digit, factorY_digit);
		if(p_digit_displayable)
			p_digit_displayable->setScale(factorX_digit, factorY_digit);
	}
		
	//Metoda skaluje obiekt - digit
	void CInformation::scaleDigit(const sf::Vector2f& factor_digit)
	{
		m_tranformable_digit.scale(factor_digit);
		if(p_digit_displayable)
			p_digit_displayable->scale(factor_digit);
	}

	//Metoda skaluje obiekt - digit
	void CInformation::scaleDigit(float factorX_digit, float factorY_digit)
	{
		m_tranformable_digit.scale(factorX_digit, factorY_digit);
		if(p_digit_displayable)
			p_digit_displayable->scale(factorX_digit, factorY_digit);
	}

	//Metoda zwraca wektor skali obiektu - mask
	const sf::Vector2f& CInformation::getScaleMask() const
	{
		return m_tranformable_mask.getScale();
	}

	//Metoda ustawia skalê obiektu - mask
	void CInformation::setScaleMask(const sf::Vector2f& factors_mask)
	{
		m_tranformable_mask.setScale(factors_mask);
		if(p_mask_displayable)
			p_mask_displayable->setScale(factors_mask);
	}

	//Metoda ustawia skalê obiektu - mask
	void CInformation::setScaleMask(float factorX_mask, float factorY_mask)
	{
		m_tranformable_mask.setScale(factorX_mask, factorY_mask);
		if(p_mask_displayable)
			p_mask_displayable->setScale(factorX_mask, factorY_mask);
	}
		
	//Metoda skaluje obiekt - mask
	void CInformation::scaleMask(const sf::Vector2f& factor_mask)
	{
		m_tranformable_mask.scale(factor_mask);
		if(p_mask_displayable)
			p_mask_displayable->scale(factor_mask);
	}

	//Metoda skaluje obiekt - mask
	void CInformation::scaleMask(float factorX_mask, float factorY_mask)
	{
		m_tranformable_mask.scale(factorX_mask, factorY_mask);
		if(p_mask_displayable)
			p_mask_displayable->scale(factorX_mask, factorY_mask);
	}

	//Metoda zwraca origin obiektu - digit
	const sf::Vector2f& CInformation::getOriginDigit() const
	{
		return m_tranformable_digit.getOrigin();
	}

	//Metoda ustawia origin obiektu - digit
	void CInformation::setOriginDigit(const sf::Vector2f& origin_digit)
	{
		m_tranformable_digit.setOrigin(origin_digit);
		if(p_digit_displayable)
			p_digit_displayable->setOrigin(origin_digit);
	}

	//Metoda ustawia origin obiektu - digit
	void CInformation::setOriginDigit(float x, float y)
	{
		m_tranformable_digit.setOrigin(x, y);
		if(p_digit_displayable)
			p_digit_displayable->setOrigin(x, y);
	}

	//Metoda zwraca origin obiektu - mask
	const sf::Vector2f& CInformation::getOriginMask() const
	{
		return m_tranformable_mask.getOrigin();
	}

	//Metoda ustawia origin obiektu - mask
	void CInformation::setOriginMask(const sf::Vector2f& origin_mask)
	{
		m_tranformable_mask.setOrigin(origin_mask);
		if(p_mask_displayable)
			p_mask_displayable->setOrigin(origin_mask);
	}

	//Metoda ustawia origin obiektu - mask
	void CInformation::setOriginMask(float x, float y)
	{
		m_tranformable_mask.setOrigin(x, y);
		if(p_mask_displayable)
			p_mask_displayable->setOrigin(x, y);
	}

	//Metoda zwraca pozycjê obiektu
	const sf::Vector2f & CInformation::getPosition() const
	{
		return m_tranformable_digit.getPosition();
		//return m_tranformable_mask.getPosition();
	}
		
	//Metoda ustawia pozycjê obiektu
	void CInformation::setPosition(const sf::Vector2f &position)
	{
		m_tranformable_digit.setPosition(position);
		m_tranformable_mask.setPosition(position);
		if(p_digit_displayable)
			p_digit_displayable->setPosition(position);
		if(p_mask_displayable)
			p_mask_displayable->setPosition(position);
	}

	//Metoda ustawia pozycjê obiektu
	void CInformation::setPosition(float x, float y)
	{
		m_tranformable_digit.setPosition(x, y);
		m_tranformable_mask.setPosition(x, y);
		if(p_digit_displayable)
			p_digit_displayable->setPosition(x, y);
		if(p_mask_displayable)
			p_mask_displayable->setPosition(x, y);
	}

	//Metoda zwraca obrót obiektu
	float CInformation::getRotation() const
	{
		return m_tranformable_digit.getRotation();
		//return m_tranformable_mask.getRotation();
	}

	//Metoda ustawia obrót obiektu
	void CInformation::setRotation(float angle)
	{
		m_tranformable_digit.setRotation(angle);
		m_tranformable_mask.setRotation(angle);
		if(p_digit_displayable)
			p_digit_displayable->setRotation(angle);
		if(p_mask_displayable)
			p_mask_displayable->setRotation(angle);
	}

	//Metoda obraca obiekt zadany k¹t
	void CInformation::rotate(float angle)
	{
		m_tranformable_digit.rotate(angle);
		m_tranformable_mask.rotate(angle);
		if(p_digit_displayable)
			p_digit_displayable->rotate(angle);
		if(p_mask_displayable)
			p_mask_displayable->rotate(angle);
	}

	//Metoda zwraca wektor skali obiektu
	const sf::Vector2f& CInformation::getScale() const
	{
		return m_tranformable_digit.getScale();
		//return m_tranformable_mask.getScale();
	}

	//Metoda ustawia skalê obiektu
	void CInformation::setScale(const sf::Vector2f& factors)
	{
		m_tranformable_digit.setScale(factors);
		m_tranformable_mask.setScale(factors);
		if(p_digit_displayable)
			p_digit_displayable->setScale(factors);
		if(p_mask_displayable)
			p_mask_displayable->setScale(factors);
	}

	//Metoda ustawia skalê obiektu
	void CInformation::setScale(float factorX, float factorY)
	{
		m_tranformable_digit.setScale(factorX, factorY);
		m_tranformable_mask.setScale(factorX, factorY);
		if(p_digit_displayable)
			p_digit_displayable->setScale(factorX, factorY);
		if(p_mask_displayable)
			p_mask_displayable->setScale(factorX, factorY);
	}
		
	//Metoda skaluje obiekt
	void CInformation::scale(const sf::Vector2f& factor)
	{
		m_tranformable_digit.scale(factor);
		m_tranformable_mask.scale(factor);
		if(p_digit_displayable)
			p_digit_displayable->scale(factor);
		if(p_mask_displayable)
			p_mask_displayable->scale(factor);
	}

	//Metoda skaluje obiekt
	void CInformation::scale(float factorX, float factorY)
	{
		m_tranformable_digit.scale(factorX, factorY);
		m_tranformable_mask.scale(factorX, factorY);
		if(p_digit_displayable)
			p_digit_displayable->scale(factorX, factorY);
		if(p_mask_displayable)
			p_mask_displayable->scale(factorX, factorY);
	}

	//Metoda zwraca origin obiektu
	const sf::Vector2f& CInformation::getOrigin() const
	{
		return m_tranformable_digit.getOrigin();
		//return m_tranformable_mask.getOrigin();
	}

	//Metoda ustawia origin obiektu
	void CInformation::setOrigin(const sf::Vector2f& origin)
	{
		m_tranformable_digit.setOrigin(origin);
		m_tranformable_mask.setOrigin(origin);
		if(p_digit_displayable)
			p_digit_displayable->setOrigin(origin);
		if(p_mask_displayable)
			p_mask_displayable->setOrigin(origin);
	}

	//Metoda ustawia origin obiektu
	void CInformation::setOrigin(float x, float y)
	{
		m_tranformable_digit.setOrigin(x, y);
		m_tranformable_mask.setOrigin(x, y);
		if(p_digit_displayable)
			p_digit_displayable->setOrigin(x, y);
		if(p_mask_displayable)
			p_mask_displayable->setOrigin(x, y);
	}

	//Metoda zwraca referencjê na obiekt klasy sf::Transformable - digit
	sf::Transformable &CInformation::getTransformableDigit()
	{
		return m_tranformable_digit;
	}

	//Metoda ustawia referencjê na obiekt klasy sf::Transformable - digit
	void CInformation::setTransformableDigit(const sf::Transformable & tranformable_digit)
	{
		m_tranformable_digit = tranformable_digit;
	}

	//Metoda zwraca referencjê na obiekt klasy sf::Transformable - mask
	sf::Transformable &CInformation::getTransformableMask()
	{
		return m_tranformable_mask;
	}

	//Metoda ustawia referencjê na obiekt klasy sf::Transformable - mask
	void CInformation::setTransformableMask(const sf::Transformable & tranformable_mask)
	{
		m_tranformable_mask = tranformable_mask;
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CInformation::update(float dt)
	{
		//to do...
	}


	//implementajca metod private:

	//prywatna metoda sprawdza, czy trzeba utworzyæ
	//obiekt klasy CDisplayable (digit),
	//np. gdy chcemy dodaæ teksturê, animacjê, syntetyk, etc...
	void CInformation::checkDisplayable_digit()
	{
		if (!p_digit_displayable)
			p_digit_displayable = gDrawableManager.CreateDisplayable(Z_INFORMATION_FRONT);
	}

	//prywatna metoda sprawdza, czy trzeba utworzyæ
	//obiekt klasy CDisplayable (mask),
	//np. gdy chcemy dodaæ teksturê, animacjê, syntetyk, etc...
	void CInformation::checkDisplayable_mask()
	{
		if (!p_mask_displayable)
			p_mask_displayable = gDrawableManager.CreateDisplayable(Z_INFORMATION_FRONT);
	}
}//namespace information
