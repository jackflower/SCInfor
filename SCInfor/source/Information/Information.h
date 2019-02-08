//  ________________________________________
// | Information.h - class definition       |
// | Jack Flower - April 2015               |
// |________________________________________|
//

#ifndef H_INFORMATION_JACK
#define H_INFORMATION_JACK

#include "../RTTI/RTTI.h"
#include "BaseInformation.h"
#include "../Rendering/Displayable/CDisplayable.h"

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
	class InfoManager;
}

namespace factory
{
	class InformationTemplate;
}

using namespace infologic;
using namespace rendering::displayable;
using namespace factory;

namespace information
{
	///
	///Klasa bazowa reprezentująca informację - graficzna reprezentacja
	///
	class Information : public BaseInformation
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class InfoManager;

		//Aby uzyskać obiekt Information, należy wywołać InfoManager::CreateInformation();
		
	protected:

		///
		///Chroniony konstruktor domyślny - używany wyłącznie przez InfoManager
		///
		///@param uniqueId - unikalny identyfikator (nadawany w InfoManager)
		///
		Information(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param InformationCopy stała referencja na obiekt klasy Information
		///
		Information(const Information & InformationCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez InfoManager
		///
		virtual ~Information();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda ustawia flagę dla obiektów gotowych do destrukcji
		///
		void markForDelete();

		///
		///Metoda zwraca wskaźnik na obiekt klasy InformationTemplate
		///
		inline InformationTemplate *getTemplate() const
		{ 
			return p_template;
		}

		///
		///Metoda ustawia wskaźnik na obiekt klasy InformationTemplate
		///
		///@param *p_template - wskaźnik na obiekt klasy InformationTemplate
		///
		inline void setTemplate(InformationTemplate *p_template_param)
		{
			p_template = p_template_param;
		}

		///
		///Metoda zwraca nazwę tekstury - digit
		///
		const std::string & getTextureDigit() const;

		///
		///Metoda ustawia nazwę oraz inicjuje teskturą - digit
		///
		///@param texture_digit - nazwa tekstury
		///
		void setTextureDigit(const std::string & texture_digit);

		///
		///Metoda zwraca nazwę tekstury - mask
		///
		const std::string & getTextureMask() const;

		///
		///Metoda ustawia nazwę oraz inicjuje teskturą - mask
		///
		///@param texture_mask - nazwa tekstury
		///
		void setTextureMask(const std::string & texture_mask);

		///
		///Metoda zwraca pozycję obiektu - digit
		///
		const sf::Vector2f & getPositionDigit() const;
		
		///
		///Metoda ustawia pozycję obiektu - digit
		///
		///@param positon_digit - stała referencaja na obiekt klasy sf::Vector2f
		///
		void setPositionDigit(const sf::Vector2f & position_digit);

		///
		///Metoda ustawia pozycję obiektu - digit
		///
		///@param x - współrzędna X
		///
		///@param y - współrzędna Y
		///
		void setPositionDigit(float x, float y);

		///
		///Metoda zwraca pozycję obiektu - mask
		///
		const sf::Vector2f & getPositionMask() const;
		
		///
		///Metoda ustawia pozycję obiektu - mask
		///
		///@param positon_mask - stała referencaja na obiekt klasy sf::Vector2f
		///
		void setPositionMask(const sf::Vector2f & position_mask);

		///
		///Metoda ustawia pozycję obiektu - mask
		///
		///@param x - współrzędna X
		///
		///@param y - współrzędna Y
		///
		void setPositionMask(float x, float y);

		///
		///Metoda zwraca obrót obiektu - digit
		///
		float getRotationDigit() const;

		///
		///Metoda ustawia obrót obiektu - digit
		///
		///@param angle_digit - kąt obrotu
		///
		void setRotationDigit(float angle_digit);

		///
		///Metoda obraca obiekt zadany kąt - digit
		///
		///@param angle_digit - kąt obrotu
		///
		void rotateDigit(float angle_digit);

		///
		///Metoda zwraca obrót obiektu - mask
		///
		float getRotationMask() const;

		///
		///Metoda ustawia obrót obiektu - mask
		///
		///@param angle_mask - kąt obrotu
		///
		void setRotationMask(float angle_mask);

		///
		///Metoda obraca obiekt zadany kąt - mask
		///
		///@param angle_mask - kąt obrotu
		///
		void rotateMask(float angle_mask);

		///
		///Metoda zwraca wektor skali obiektu - digit
		///
		const sf::Vector2f & getScaleDigit() const;

		///
		///Metoda ustawia skalę obiektu - digit
		///
		///@param factors_digit - wektor współczynnika skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setScaleDigit(const sf::Vector2f & factors_digit);

		///
		///Metoda ustawia skalę obiektu - digit
		///
		///@param factorX_digit - współczynnik X
		///
		///@param factorY_digit - współczynnik Y
		///
		void setScaleDigit(float factorX_digit, float factorY_digit);
		
		///
		///Metoda skaluje obiekt - digit
		///
		///@param factor_digit - współczynnik skali
		///
		void scaleDigit(const sf::Vector2f & factor_digit);

		///
		///Metoda skaluje obiekt - digit
		///
		///@param factorX_digit - współczynnik X
		///
		///@param factorY_digit - współczynnik Y
		///
		void scaleDigit(float factorX_digit, float factorY_digit);

		///
		///Metoda zwraca wektor skali obiektu - mask
		///
		const sf::Vector2f & getScaleMask() const;

		///
		///Metoda ustawia skalę obiektu - mask
		///
		///@param factors_mask - wektor współczynika skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setScaleMask(const sf::Vector2f & factors_mask);

		///
		///Metoda ustawia skalę obiektu - mask
		///
		///@param factorX_mask - współczynnik X
		///
		///@param factorY_mask - współczynnik Y
		///
		void setScaleMask(float factorX_mask, float factorY_mask);
		
		///
		///Metoda skaluje obiekt - mask
		///
		///@param factor_mask - współczynnik skali
		///
		void scaleMask(const sf::Vector2f & factor_mask);

		///
		///Metoda skaluje obiekt - mask
		///
		///@param factorX_mask - współczynnik X
		///
		///@param factorY_mask - współczynnik Y
		///
		void scaleMask(float factorX_mask, float factorY_mask);

		///
		///Metoda zwraca origin obiektu - digit
		///
		const sf::Vector2f & getOriginDigit() const;

		///
		///Metoda ustawia origin obiektu - digit
		///
		///@param origin_digit - stała referencja na obiekt klasy sf::Vector2f
		///
		void setOriginDigit(const sf::Vector2f & origin_digit);

		///
		///Metoda ustawia origin obiektu - digit
		///
		///@param x - współrzędna X
		///
		///@param y - współrzędna Y
		///
		void setOriginDigit(float x, float y);

		///
		///Metoda zwraca origin obiektu - mask
		///
		const sf::Vector2f & getOriginMask() const;

		///
		///Metoda ustawia origin obiektu - mask
		///
		///@param origin_mask - stała referencja na obiekt klasy sf::Vector2f
		///
		void setOriginMask(const sf::Vector2f & origin_mask);

		///
		///Metoda ustawia origin obiektu - mask
		///
		///@param x - współrzędna X
		///
		///@param y - współrzędna Y
		///
		void setOriginMask(float x, float y);

		///
		///Metoda zwraca pozycję obiektu
		///
		const sf::Vector2f & getPosition() const;
		
		///
		///Metoda ustawia pozycję obiektu
		///
		///@param positon - stała referecnaj na obiekt klasy sf::Vector2f
		///
		void setPosition(const sf::Vector2f & position);

		///
		///Metoda ustawia pozycję obiektu
		///
		///@param x - współrzędna X
		///
		///@param y - współrzędna Y
		///
		void setPosition(float x, float y);

		///
		///Metoda zwraca obrót obiektu
		///
		float getRotation() const;

		///
		///Metoda ustawia obrót obiektu
		///
		///@param angle - kąt obrotu
		///
		void setRotation(float angle);

		///
		///Metoda obraca obiekt zadany kąt
		///
		///@param angle - kąt obrotu
		///
		void rotate(float angle);

		///
		///Metoda zwraca wektor skali obiektu
		///
		const sf::Vector2f & getScale() const;

		///
		///Metoda ustawia skalę obiektu
		///
		///@param factors - wektor współczynika skali - stała referncja na obiekt klasy sf::Vector2f
		///
		void setScale(const sf::Vector2f & factors);

		///
		///Metoda ustawia skalę obiektu
		///
		///@param factorX - współczynnik X
		///
		///@param factorY - współczynnik Y
		///
		void setScale(float factorX, float factorY);
		
		///
		///Metoda skaluje obiekt
		///
		///@param factor - współczynnik skali
		///
		void scale(const sf::Vector2f & factor);

		///
		///Metoda skaluje obiekt
		///
		///@param factorX - współczynnik X
		///
		///@param factorY - współczynnik Y
		///
		void scale(float factorX, float factorY);

		///
		///Metoda zwraca origin obiektu
		///
		const sf::Vector2f & getOrigin() const;

		///
		///Metoda ustawia origin obiektu
		///
		///@param origin - stała referencja na obiekt klasy sf::Vector2f
		///
		void setOrigin(const sf::Vector2f & origin);

		///
		///Metoda ustawia origin obiektu
		///
		///@param x - współrzędna X
		///
		///@param y - współrzędna Y
		///
		void setOrigin(float x, float y);

		///
		///Metoda zwraca referencję na obiekt klasy sf::Transformable - digit
		///
		sf::Transformable & getTransformableDigit();

		///
		///Metoda ustawia referencję na obiekt klasy sf::Transformable - digit
		///
		///@param tranformable_digit - stała referencja na obiekt klasy sf::Transformable
		///
		void setTransformableDigit(const sf::Transformable & tranformable_digit);

		///
		///Metoda zwraca referencję na obiekt klasy sf::Transformable - mask
		///
		sf::Transformable & getTransformableMask();

		///
		///Metoda ustawia referencję na obiekt klasy sf::Transformable - mask
		///
		///@param tranformable_mask - stała referencja na obiekt klasy sf::Transformable
		///
		void setTransformableMask(const sf::Transformable & tranformable_mask);

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:

		CDisplayable *p_digit_displayable; //wskaźnik na graficzną reprezentację obiektu - cyfra
		CDisplayable *p_mask_displayable; //wskaźnik na graficzną reprezentację obiektu - maska
		std::string m_texture_digit_name; //nazwa tekstury - digit
		std::string m_texture_mask_name; //nazwa tekstury - mask
		InformationTemplate *p_template; //wskaźnik na wzorzec
		sf::Transformable m_tranformable_digit; //opakowanie danych do transforamcji geometrycznej - digit
		sf::Transformable m_tranformable_mask; //opakowanie danych do transforamcji geometrycznej - mask

	private:

		//prywatna metoda sprawdza, czy trzeba utworzyć
		//obiekt klasy CDisplayable (digit),
		//np. gdy chcemy dodać teksturę, animację, syntetyk, etc...
		void checkDisplayable_digit();

		//prywatna metoda sprawdza, czy trzeba utworzyć
		//obiekt klasy CDisplayable (mask),
		//np. gdy chcemy dodać teksturę, animację, syntetyk, etc...
		void checkDisplayable_mask();

	};
}//namespace information
#endif//H_INFORMATION_JACK
