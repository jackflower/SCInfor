//  ________________________________________
// | Information.cpp - class implementation |
// | Jack Flower - April 2015               |
// |________________________________________|
//

#include "Information.h"
#include "../Rendering/Drawable/DrawableManager.h"
#include "../Factory/InformationFactory/InformationTemplate.h"

namespace information
{
	RTTI_IMPL(Information, BaseInformation);

	//Chroniony konstruktor domyślny - używany wyłącznie przez InfoManager
	Information::Information(const std::wstring & uniqueId)
	:
		BaseInformation			(uniqueId),//chroniony konstruktor klasy bazowej
		p_digit_displayable		(nullptr),
		p_mask_displayable		(nullptr),
		m_texture_digit_name	(""),
		m_texture_mask_name		(""),
		p_template				(nullptr),
		m_tranformable_digit	(),
		m_tranformable_mask		()
	{
	}

	//Chroniony konstruktor kopiujący
	Information::Information(const Information & InformationCopy)
	:
		BaseInformation			(InformationCopy),//chroniony konstruktor kopiujący klasy bazowej
		p_digit_displayable		(InformationCopy.p_digit_displayable),
		p_mask_displayable		(InformationCopy.p_mask_displayable),
		m_texture_digit_name	(InformationCopy.m_texture_digit_name),
		m_texture_mask_name		(InformationCopy.m_texture_mask_name),
		p_template				(InformationCopy.p_template),
		m_tranformable_digit	(InformationCopy.m_tranformable_digit),
		m_tranformable_mask		(InformationCopy.m_tranformable_mask)
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez InfoManager
	Information::~Information()
	{
		if (p_digit_displayable != nullptr)
			gDrawableManager.destroyDrawable(p_digit_displayable);
		if (p_mask_displayable != nullptr)
			gDrawableManager.destroyDrawable(p_mask_displayable);
		m_texture_digit_name	= "";
		m_texture_mask_name		= "";
		p_template				= nullptr;
		//m_tranformable_digit	not edit
		//m_tranformable_mask	not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Information::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda ustawia flagę dla obiektów gotowych do destrukcji
	void Information::markForDelete()
	{
		//m_ready_for_destruction = true;
		BaseInformation::markForDelete();
	}

	//Metoda zwraca nazwę tekstury - digit
	const std::string& Information::getTextureDigit() const
	{
		return m_texture_digit_name;
	}

	//Metoda ustatawia teksturę - digit
	void Information::setTextureDigit(const std::string& texture_digit)
	{
		m_texture_digit_name = texture_digit;	//ustawiam nazwę dla tekstury
		checkDisplayable_digit();				//spradzam, czy obiekt renderowalny jest zainicjowany
		if (p_digit_displayable)				//jeśli tak - ustawiam jego teksturę
			p_digit_displayable->setTexture(texture_digit);
	}

	//Metoda zwraca nazwę tekstury - mask
	const std::string& Information::getTextureMask() const
	{
		return m_texture_mask_name;
	}

	//Metoda ustawia nazwę oraz inicjuje teskturą - mask
	void Information::setTextureMask(const std::string& texture_mask)
	{
		m_texture_mask_name = texture_mask;		//ustawiam nazwę dla tekstury
		checkDisplayable_mask();				//spradzam, czy obiekt renderowalny jest zainicjowany
		if (p_mask_displayable)					//jeśli tak - ustawiam jego teksturę
			p_mask_displayable->setTexture(texture_mask);
	}

	//Metoda zwraca pozycję obiektu - digit
	const sf::Vector2f & Information::getPositionDigit() const
	{
		return m_tranformable_digit.getPosition();
	}

	//Metoda ustawia pozycję obiektu - digit
	void Information::setPositionDigit(const sf::Vector2f &position_digit)
	{
		m_tranformable_digit.setPosition(position_digit);
		if(p_digit_displayable)
			p_digit_displayable->setPosition(position_digit);
	}

	//Metoda ustawia pozycję obiektu
	void Information::setPositionDigit(float x, float y)
	{
		m_tranformable_digit.setPosition(x, y);
		if(p_digit_displayable)
			p_digit_displayable->setPosition(x, y);
	}

	//Metoda zwraca pozycję obiektu - mask
	const sf::Vector2f & Information::getPositionMask() const
	{
		return m_tranformable_mask.getPosition();
	}
		
	//Metoda ustawia pozycję obiektu - mask
	void Information::setPositionMask(const sf::Vector2f &position_mask)
	{
		m_tranformable_mask.setPosition(position_mask);
		if(p_mask_displayable)
			p_mask_displayable->setPosition(position_mask);
	}

	//Metoda ustawia pozycję obiektu - mask
	void Information::setPositionMask(float x, float y)
	{
		m_tranformable_mask.setPosition(x, y);
		if(p_mask_displayable)
			p_mask_displayable->setPosition(x, y);
	}

	//Metoda zwraca obrót obiektu - digit
	float Information::getRotationDigit() const
	{
		return m_tranformable_digit.getRotation();
	}

	//Metoda ustawia obrót obiektu - digit
	void Information::setRotationDigit(float angle_digit)
	{
		m_tranformable_digit.setRotation(angle_digit);
		if(p_digit_displayable)
			p_digit_displayable->setRotation(angle_digit);
	}

	//Metoda obraca obiekt zadany kąt - digit
	void Information::rotateDigit(float angle_digit)
	{
		m_tranformable_digit.rotate(angle_digit);
		if(p_digit_displayable)
			p_digit_displayable->rotate(angle_digit);
	}

	//Metoda zwraca obrót obiektu - mask
	float Information::getRotationMask() const
	{
		return m_tranformable_mask.getRotation();
	}

	//Metoda ustawia obrót obiektu - mask
	void Information::setRotationMask(float angle_mask)
	{
		m_tranformable_mask.setRotation(angle_mask);
		if(p_mask_displayable)
			p_mask_displayable->setRotation(angle_mask);
	}

	//Metoda obraca obiekt zadany kąt - mask
	void Information::rotateMask(float angle_mask)
	{
		m_tranformable_mask.rotate(angle_mask);
		if(p_mask_displayable)
			p_mask_displayable->rotate(angle_mask);
	}

	//Metoda zwraca wektor skali obiektu - digit
	const sf::Vector2f& Information::getScaleDigit() const
	{
		return m_tranformable_digit.getScale();
	}

	//Metoda ustawia skalę obiektu - digit
	void Information::setScaleDigit(const sf::Vector2f& factors_digit)
	{
		m_tranformable_digit.setScale(factors_digit);
		if(p_digit_displayable)
			p_digit_displayable->setScale(factors_digit);
	}

	//Metoda ustawia skalę obiektu - digit
	void Information::setScaleDigit(float factorX_digit, float factorY_digit)
	{
		m_tranformable_digit.setScale(factorX_digit, factorY_digit);
		if(p_digit_displayable)
			p_digit_displayable->setScale(factorX_digit, factorY_digit);
	}
		
	//Metoda skaluje obiekt - digit
	void Information::scaleDigit(const sf::Vector2f& factor_digit)
	{
		m_tranformable_digit.scale(factor_digit);
		if(p_digit_displayable)
			p_digit_displayable->scale(factor_digit);
	}

	//Metoda skaluje obiekt - digit
	void Information::scaleDigit(float factorX_digit, float factorY_digit)
	{
		m_tranformable_digit.scale(factorX_digit, factorY_digit);
		if(p_digit_displayable)
			p_digit_displayable->scale(factorX_digit, factorY_digit);
	}

	//Metoda zwraca wektor skali obiektu - mask
	const sf::Vector2f& Information::getScaleMask() const
	{
		return m_tranformable_mask.getScale();
	}

	//Metoda ustawia skalę obiektu - mask
	void Information::setScaleMask(const sf::Vector2f& factors_mask)
	{
		m_tranformable_mask.setScale(factors_mask);
		if(p_mask_displayable)
			p_mask_displayable->setScale(factors_mask);
	}

	//Metoda ustawia skalę obiektu - mask
	void Information::setScaleMask(float factorX_mask, float factorY_mask)
	{
		m_tranformable_mask.setScale(factorX_mask, factorY_mask);
		if(p_mask_displayable)
			p_mask_displayable->setScale(factorX_mask, factorY_mask);
	}
		
	//Metoda skaluje obiekt - mask
	void Information::scaleMask(const sf::Vector2f& factor_mask)
	{
		m_tranformable_mask.scale(factor_mask);
		if(p_mask_displayable)
			p_mask_displayable->scale(factor_mask);
	}

	//Metoda skaluje obiekt - mask
	void Information::scaleMask(float factorX_mask, float factorY_mask)
	{
		m_tranformable_mask.scale(factorX_mask, factorY_mask);
		if(p_mask_displayable)
			p_mask_displayable->scale(factorX_mask, factorY_mask);
	}

	//Metoda zwraca origin obiektu - digit
	const sf::Vector2f& Information::getOriginDigit() const
	{
		return m_tranformable_digit.getOrigin();
	}

	//Metoda ustawia origin obiektu - digit
	void Information::setOriginDigit(const sf::Vector2f& origin_digit)
	{
		m_tranformable_digit.setOrigin(origin_digit);
		if(p_digit_displayable)
			p_digit_displayable->setOrigin(origin_digit);
	}

	//Metoda ustawia origin obiektu - digit
	void Information::setOriginDigit(float x, float y)
	{
		m_tranformable_digit.setOrigin(x, y);
		if(p_digit_displayable)
			p_digit_displayable->setOrigin(x, y);
	}

	//Metoda zwraca origin obiektu - mask
	const sf::Vector2f& Information::getOriginMask() const
	{
		return m_tranformable_mask.getOrigin();
	}

	//Metoda ustawia origin obiektu - mask
	void Information::setOriginMask(const sf::Vector2f& origin_mask)
	{
		m_tranformable_mask.setOrigin(origin_mask);
		if(p_mask_displayable)
			p_mask_displayable->setOrigin(origin_mask);
	}

	//Metoda ustawia origin obiektu - mask
	void Information::setOriginMask(float x, float y)
	{
		m_tranformable_mask.setOrigin(x, y);
		if(p_mask_displayable)
			p_mask_displayable->setOrigin(x, y);
	}

	//Metoda zwraca pozycję obiektu
	const sf::Vector2f & Information::getPosition() const
	{
		return m_tranformable_digit.getPosition();
		//return m_tranformable_mask.getPosition();
	}
		
	//Metoda ustawia pozycję obiektu
	void Information::setPosition(const sf::Vector2f &position)
	{
		m_tranformable_digit.setPosition(position);
		m_tranformable_mask.setPosition(position);
		if(p_digit_displayable)
			p_digit_displayable->setPosition(position);
		if(p_mask_displayable)
			p_mask_displayable->setPosition(position);
	}

	//Metoda ustawia pozycję obiektu
	void Information::setPosition(float x, float y)
	{
		m_tranformable_digit.setPosition(x, y);
		m_tranformable_mask.setPosition(x, y);
		if(p_digit_displayable)
			p_digit_displayable->setPosition(x, y);
		if(p_mask_displayable)
			p_mask_displayable->setPosition(x, y);
	}

	//Metoda zwraca obrót obiektu
	float Information::getRotation() const
	{
		return m_tranformable_digit.getRotation();
		//return m_tranformable_mask.getRotation();
	}

	//Metoda ustawia obrót obiektu
	void Information::setRotation(float angle)
	{
		m_tranformable_digit.setRotation(angle);
		m_tranformable_mask.setRotation(angle);
		if(p_digit_displayable)
			p_digit_displayable->setRotation(angle);
		if(p_mask_displayable)
			p_mask_displayable->setRotation(angle);
	}

	//Metoda obraca obiekt zadany kąt
	void Information::rotate(float angle)
	{
		m_tranformable_digit.rotate(angle);
		m_tranformable_mask.rotate(angle);
		if(p_digit_displayable)
			p_digit_displayable->rotate(angle);
		if(p_mask_displayable)
			p_mask_displayable->rotate(angle);
	}

	//Metoda zwraca wektor skali obiektu
	const sf::Vector2f& Information::getScale() const
	{
		return m_tranformable_digit.getScale();
		//return m_tranformable_mask.getScale();
	}

	//Metoda ustawia skalę obiektu
	void Information::setScale(const sf::Vector2f& factors)
	{
		m_tranformable_digit.setScale(factors);
		m_tranformable_mask.setScale(factors);
		if(p_digit_displayable)
			p_digit_displayable->setScale(factors);
		if(p_mask_displayable)
			p_mask_displayable->setScale(factors);
	}

	//Metoda ustawia skalę obiektu
	void Information::setScale(float factorX, float factorY)
	{
		m_tranformable_digit.setScale(factorX, factorY);
		m_tranformable_mask.setScale(factorX, factorY);
		if(p_digit_displayable)
			p_digit_displayable->setScale(factorX, factorY);
		if(p_mask_displayable)
			p_mask_displayable->setScale(factorX, factorY);
	}
		
	//Metoda skaluje obiekt
	void Information::scale(const sf::Vector2f& factor)
	{
		m_tranformable_digit.scale(factor);
		m_tranformable_mask.scale(factor);
		if(p_digit_displayable)
			p_digit_displayable->scale(factor);
		if(p_mask_displayable)
			p_mask_displayable->scale(factor);
	}

	//Metoda skaluje obiekt
	void Information::scale(float factorX, float factorY)
	{
		m_tranformable_digit.scale(factorX, factorY);
		m_tranformable_mask.scale(factorX, factorY);
		if(p_digit_displayable)
			p_digit_displayable->scale(factorX, factorY);
		if(p_mask_displayable)
			p_mask_displayable->scale(factorX, factorY);
	}

	//Metoda zwraca origin obiektu
	const sf::Vector2f& Information::getOrigin() const
	{
		return m_tranformable_digit.getOrigin();
		//return m_tranformable_mask.getOrigin();
	}

	//Metoda ustawia origin obiektu
	void Information::setOrigin(const sf::Vector2f& origin)
	{
		m_tranformable_digit.setOrigin(origin);
		m_tranformable_mask.setOrigin(origin);
		if(p_digit_displayable)
			p_digit_displayable->setOrigin(origin);
		if(p_mask_displayable)
			p_mask_displayable->setOrigin(origin);
	}

	//Metoda ustawia origin obiektu
	void Information::setOrigin(float x, float y)
	{
		m_tranformable_digit.setOrigin(x, y);
		m_tranformable_mask.setOrigin(x, y);
		if(p_digit_displayable)
			p_digit_displayable->setOrigin(x, y);
		if(p_mask_displayable)
			p_mask_displayable->setOrigin(x, y);
	}

	//Metoda zwraca referencję na obiekt klasy sf::Transformable - digit
	sf::Transformable &Information::getTransformableDigit()
	{
		return m_tranformable_digit;
	}

	//Metoda ustawia referencję na obiekt klasy sf::Transformable - digit
	void Information::setTransformableDigit(const sf::Transformable & tranformable_digit)
	{
		m_tranformable_digit = tranformable_digit;
	}

	//Metoda zwraca referencję na obiekt klasy sf::Transformable - mask
	sf::Transformable &Information::getTransformableMask()
	{
		return m_tranformable_mask;
	}

	//Metoda ustawia referencję na obiekt klasy sf::Transformable - mask
	void Information::setTransformableMask(const sf::Transformable & tranformable_mask)
	{
		m_tranformable_mask = tranformable_mask;
	}

	//Wirtualna metoda aktualizująca obiekt
	void Information::update(float dt)
	{
		//to do...
	}


	//implementajca metod private:

	//prywatna metoda sprawdza, czy trzeba utworzyć
	//obiekt klasy Displayable (digit),
	//np. gdy chcemy dodać teksturę, animację, syntetyk, etc...
	void Information::checkDisplayable_digit()
	{
		if (!p_digit_displayable)
			p_digit_displayable = gDrawableManager.createDisplayable(Z_INFORMATION_FRONT);
	}

	//prywatna metoda sprawdza, czy trzeba utworzyć
	//obiekt klasy Displayable (mask),
	//np. gdy chcemy dodać teksturę, animację, syntetyk, etc...
	void Information::checkDisplayable_mask()
	{
		if (!p_mask_displayable)
			p_mask_displayable = gDrawableManager.createDisplayable(Z_INFORMATION_BACK);
	}
}//namespace information
