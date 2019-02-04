//  __________________________________________
// | CDisplayable.h - class definition        |
// | Jack Flower - August 2012                |
// |__________________________________________|
//

#ifndef H_DISPLAYABLE_JACK
#define H_DISPLAYABLE_JACK

#include "../Drawable/IDrawable.h"
#include "CSprite.h"
#include <SFML/Graphics/Image.hpp>
#include <string>

///
///Forward declaration
///
namespace sf
{
    class Sprite;
    class RenderWindow;
}

///
///Forward declaration
///
namespace rendering
{
	namespace animation
	{
		class CAnimationState;
		class CAnimationFrame;
		class CAnimation;
	}
}

///
///Forward declaration
///
namespace resource
{
	class CTexture;
}

using namespace rendering::animation;
using namespace resource;
using namespace rendering::drawable;

namespace rendering
{
	namespace displayable
	{
		///
		///Klasa reprezentuje obiekt, kt�ry potrafi by� renderowany (mo�e by� tak�e animowany)
		///
		class CDisplayable : public IDrawable
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domy�lny
			///
			CDisplayable();

			///
			///Konstruktor kopiuj�cy
			///
			///@param &CDisplayableCopy - sta�a referencja na obiekt klasy CDisplayable
			///
			CDisplayable(const CDisplayable& CDisplayableCopy);

			///
			///Destruktor wirtualny
			///
			virtual ~CDisplayable();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca wska�nik na obiekt sf::Sprite
			///
			CSprite *GetSprite();

			///
			///Metoda zwraca pozycj� obiektu
			///
			const sf::Vector2f& getPosition() const;

			///
			///Metoda ustawia pozycj� obiektu
			///
			///@param x - wsp�rz�dna x obiektu
			///
			///@param y - wsp�rz�dna y obiektu
			///
			void setPosition(float x, float y);

			///
			//Metoda ustawia pozycj� obiektu
			///
			///@param &vector - referenacja - obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f& vector);

			///
			///Metoda zwraca warto�� obrotu
			///
			float getRotation() const;
		
			///
			///Metoda ustawia warto�� obrotu
			///
			///@param rotation_value - warto�� obrotu
			///
			void setRotation(float rotation_value);

			///
			///Metoda obraca warto�� obrotu
			///
			///@param angle - warto�� obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca skal�
			///
			const sf::Vector2f& getScale() const;
		
			///
			///Metoda ustawia skal�
			///
			///@param x - wsp�rz�dna x wektora
			///
			///@param y - wsp�rz�dna y wektora
			///
			void setScale(float x, float y);

			///
			///Metoda ustawia skal�
			///
			///@param &new_scale_value - referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f& new_scale_value);

			///
			///Metoda ustawia skal�
			///
			///@param factors - jednolita warto�� skaluj�ca w osi x i y
			///
			void setScale(float factors);

			///
			///Metoda ustawia skal� w stosunku do obecnej skali
			///
			///@param factorX - wsp�czynnik w osi x
			///
			///@param factorY - sp�czynnik w osi y
			///
			void scale(float factorX, float factorY);
			
			///
			///Metoda ustawia skal� w stosunku do obecnej skali
			///
			///@param &factor - sta�a referencja na obiekt klasy sf::Vector2f
			///
			void scale(const sf::Vector2f& factor);

			///
			///Metoda zwraca wsp�rz�dne punktu uchwytu obiektu
			///
			const sf::Vector2f& getOrigin() const;

			///
			///Metoda ustawia wsp�rz�dne punktu uchwytu obiektu
			///
			///@param x - wsp�rz�dna x
			///
			///@param y - wsp�rz�dna y
			///
			void setOrigin(float x, float y);

			///
			///Metoda ustawia wsp�rz�dne punktu uchwytu obiektu
			///
			///@param &origin - sta�a referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f& origin);

			///
			///Metoda zwraca obszar prostok�tny zajmowany przez tekstur�
			///
			const sf::IntRect& getTextureRect() const;

			///
			///Metoda ustawia obszar prostok�tny zajmowany przez tekstur�
			///
			///@param rectLeft - lewy r�g prostok�tnego obszaru
			///
			///@param rectTop - g�rny r�g prostok�tnego obszaru
			///
			///@param rectWidth - szeroko�� prostok�tnego obszaru
			///
			///@param rectHeight - wysoko�� prostok�tnego obszaru
			///
			void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);

			///
			///Metoda ustawia obszar prostok�tny zajmowany przez tekstur�
			///
			///@param rectangle - sta�a referencja na obiekt klasy sf::IntRect
			///
			void setTextureRect (const sf::IntRect& rectangle);

			///
			///Metoda zwraca granice obiektu w lokalnym w uk�adzie wsp�rz�dnych
			///
			sf::FloatRect getLocalBounds() const;

			///
			///Metoda zwraca granice obiektu w globalnym w uk�adzie wsp�rz�dnych
			///
			sf::FloatRect getGlobalBounds() const;
			
			///
			///Metoda przemieszcza obiekt o warto�� podan� w parametrach wzgl�dem aktualnej pozycji
			///
			///@param offsetX - warto�� przesuni�cia w osi x
			///
			///@param offsetX - warto�� przesuni�cia w osi x
			///
			void move(float offsetX, float offsetY);

			///
			///Metoda przemieszcza obiekt o warto�� wektora przesuni�cia
			///
			///@param &offset - sta�a referencja na obiekt klasy sf::Vector2f - wektora przesuni�cia
			///
			void move(const sf::Vector2f& offset);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color& getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param color - kolor obiektu
			///
			void setColor(const sf::Color& color);

			///
			///Metoda ustawia tekstur� obiektu
			///
			///@param &texture_name - sta�a referencja na obiekt std::string - nazwa tekstury
			///
			void setTexture(const std::string& texture_name, bool smoothing = true);

			///
			///Metoda ustawia tekstur� obiektu
			///
			///@param *p_texture - wska�nik na obiekt klasy CTexture
			///
			void setTexture(CTexture *p_texture, bool smoothing = true);

			///
			///Metoda generuje obraz tekstury
			///
			///@param width - szeroko�� tekstury (obiektu) w pikselach
			///
			///@param height - wysoko�� tekstury (obiektu) w pikselach
			///
			///@param color - & color - sta�a referencja na obiekt klasy sf::Color
			///
			void SetTexture(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

			///
			///Metoda generuje obraz tekstury
			///
			///@param width - szeroko�� tekstury (obiektu) w pikselach
			///
			///@param height - wysoko�� tekstury (obiektu) w pikselach
			///
			///@param r - sk�adowa red koloru
			///
			///@param g - sk�adowa green koloru
			///
			///@param b - sk�adowa blue koloru
			///
			///@param a - sk�adowa alpha koloru
			///
			void SetTexture(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

			///
			///Metoda ustawia animacj�
			///
			///@param &animation_name - sta�a referencja na obiekt std::string - nazwa animacji
			///
			void SetAnimation( const std::string& animation_name );

			///
			///Metoda ustawia animacj�
			///
			///@param *p_animation - wska�nik na obiekt klasy CAnimation
			///
			void SetAnimation(CAnimation *p_animation);

			///
			///Metoda zwraca wska�nik na obiekt klasy CAnimationState
			///
			CAnimationState* GetAnimationState();

			///
			////Metoda zwraca tryb wyg�adzania tekstury
			///
			const bool getSmoothing() const;

			///
			///Metoda ustawia tryb wyg�adzania tekstury
			///
			///@param smooth - flaga wyg�adzania tekstury
			///
			void setSmoothing(bool smooth);

			///
			///Wirtualna metoda renderuj�ca obiekt
			///
			///@render render - parametr drawable
			///
			virtual void Draw(sf::RenderWindow* render);
		
		protected:
		
			CSprite*			m_sprite;				//wska�nik na obiekt klasy CSprite (kontekst graficzny)
			CAnimationState*	m_animation_state;		//wska�nik na obiekt CAnimationState
			std::string			m_animation_name;		//nazwa animacji
			bool				m_smooth;				//flaga, czy obiekt wyg�adza piksele tekstury

		private:

			sf::Image*			p_synthetic_image;		//wska�nik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
			sf::Texture*		p_synthetic_texture;	//wska�nik na obiekt klasy sf::Texture
		};
	} //namespace displayable
}//namespace rendering
#endif //H_DISPLAYABLE_JACK
