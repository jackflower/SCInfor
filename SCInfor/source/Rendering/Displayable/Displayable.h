//  _________________________________________
// | Displayable.h - class definition        |
// | Jack Flower - August 2012               |
// |_________________________________________|
//

#ifndef H_DISPLAYABLE_JACK
#define H_DISPLAYABLE_JACK

#include "../Drawable/Drawable.h"
#include "Sprite.h"
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
		class AnimationState;
		class AnimationFrame;
		class Animation;
	}
}

///
///Forward declaration
///
namespace resource
{
	class ResourceTexture;
}

using namespace rendering::animation;
using namespace resource;
using namespace rendering::drawable;

namespace rendering
{
	namespace displayable
	{
		///
		///Klasa reprezentuje obiekt, który potrafi być renderowany (może być także animowany)
		///
		class Displayable : public rendering::drawable::Drawable
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domyślny
			///
			Displayable();

			///
			///Konstruktor kopiujący
			///
			///@param DisplayableCopy - stała referencja na obiekt klasy Displayable
			///
			Displayable(const Displayable & DisplayableCopy);

			///
			///Destruktor wirtualny
			///
			virtual ~Displayable();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca wskaźnik na obiekt sf::Sprite
			///
			Sprite *getSprite();

			///
			///Metoda zwraca pozycję obiektu
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param x - współrzędna x obiektu
			///
			///@param y - współrzędna y obiektu
			///
			void setPosition(float x, float y);

			///
			//Metoda ustawia pozycję obiektu
			///
			///@param vector - referenacja - obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & vector);

			///
			///Metoda zwraca wartość obrotu
			///
			float getRotation() const;
		
			///
			///Metoda ustawia wartość obrotu
			///
			///@param rotation_value - wartość obrotu
			///
			void setRotation(float rotation_value);

			///
			///Metoda obraca wartość obrotu
			///
			///@param angle - wartość obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca skalę
			///
			const sf::Vector2f & getScale() const;
		
			///
			///Metoda ustawia skalę
			///
			///@param x - współrzędna x wektora
			///
			///@param y - współrzędna y wektora
			///
			void setScale(float x, float y);

			///
			///Metoda ustawia skalę
			///
			///@param &new_scale_value - referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f & new_scale_value);

			///
			///Metoda ustawia skalę
			///
			///@param factors - jednolita wartość skalująca w osi x i y
			///
			void setScale(float factors);

			///
			///Metoda ustawia skalę w stosunku do obecnej skali
			///
			///@param factorX - współczynnik w osi x
			///
			///@param factorY - spółczynnik w osi y
			///
			void scale(float factorX, float factorY);
			
			///
			///Metoda ustawia skalę w stosunku do obecnej skali
			///
			///@param &factor - stała referencja na obiekt klasy sf::Vector2f
			///
			void scale(const sf::Vector2f & factor);

			///
			///Metoda zwraca współrzędne punktu uchwytu obiektu
			///
			const sf::Vector2f & getOrigin() const;

			///
			///Metoda ustawia współrzędne punktu uchwytu obiektu
			///
			///@param x - współrzędna x
			///
			///@param y - współrzędna y
			///
			void setOrigin(float x, float y);

			///
			///Metoda ustawia współrzędne punktu uchwytu obiektu
			///
			///@param origin - stała referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f & origin);

			///
			///Metoda zwraca obszar prostokątny zajmowany przez teksturę
			///
			const sf::IntRect & getTextureRect() const;

			///
			///Metoda ustawia obszar prostokątny zajmowany przez teksturę
			///
			///@param rectLeft - lewy róg prostokątnego obszaru
			///
			///@param rectTop - górny róg prostokątnego obszaru
			///
			///@param rectWidth - szerokość prostokątnego obszaru
			///
			///@param rectHeight - wysokość prostokątnego obszaru
			///
			void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);

			///
			///Metoda ustawia obszar prostokątny zajmowany przez teksturę
			///
			///@param rectangle - stała referencja na obiekt klasy sf::IntRect
			///
			void setTextureRect (const sf::IntRect & rectangle);

			///
			///Metoda zwraca granice obiektu w lokalnym w układzie współrzędnych
			///
			sf::FloatRect getLocalBounds() const;

			///
			///Metoda zwraca granice obiektu w globalnym w układzie współrzędnych
			///
			sf::FloatRect getGlobalBounds() const;
			
			///
			///Metoda przemieszcza obiekt o wartość podaną w parametrach względem aktualnej pozycji
			///
			///@param offsetX - wartość przesunięcia w osi x
			///
			///@param offsetX - wartość przesunięcia w osi x
			///
			void move(float offsetX, float offsetY);

			///
			///Metoda przemieszcza obiekt o wartość wektora przesunięcia
			///
			///@param offset - stała referencja na obiekt klasy sf::Vector2f - wektora przesunięcia
			///
			void move(const sf::Vector2f& offset);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color & getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param color - kolor obiektu
			///
			void setColor(const sf::Color & color);

			///
			///Metoda ustawia teksturę obiektu
			///
			///@param texture_name - stała referencja na obiekt std::string - nazwa tekstury
			///
			void setTexture(const std::string & texture_name, bool smoothing = true);

			///
			///Metoda ustawia teksturę obiektu
			///
			///@param *p_texture - wskaźnik na obiekt klasy ResourceTexture
			///
			void setTexture(ResourceTexture *p_texture, bool smoothing = true);

			///
			///Metoda generuje obraz tekstury
			///
			///@param width - szerokość tekstury (obiektu) w pikselach
			///
			///@param height - wysokość tekstury (obiektu) w pikselach
			///
			///@param color - & color - stała referencja na obiekt klasy sf::Color
			///
			void setTexture(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

			///
			///Metoda generuje obraz tekstury
			///
			///@param width - szerokość tekstury (obiektu) w pikselach
			///
			///@param height - wysokość tekstury (obiektu) w pikselach
			///
			///@param r - składowa red koloru
			///
			///@param g - składowa green koloru
			///
			///@param b - składowa blue koloru
			///
			///@param a - składowa alpha koloru
			///
			void setTexture(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

			///
			///Metoda ustawia animację
			///
			///@param animation_name - stała referencja na obiekt std::string - nazwa animacji
			///
			void setAnimation( const std::string & animation_name );

			///
			///Metoda ustawia animację
			///
			///@param *p_animation - wskaźnik na obiekt klasy Animation
			///
			void setAnimation(Animation *p_animation);

			///
			///Metoda zwraca wskaźnik na obiekt klasy AnimationState
			///
			AnimationState *getAnimationState();

			///
			////Metoda zwraca tryb wygładzania tekstury
			///
			const bool getSmoothing() const;

			///
			///Metoda ustawia tryb wygładzania tekstury
			///
			///@param smooth - flaga wygładzania tekstury
			///
			void setSmoothing(bool smooth);

			///
			///Wirtualna metoda renderująca obiekt
			///
			///@render render - parametr drawable
			///
			virtual void draw(sf::RenderWindow *render);
		
		protected:
		
			Sprite *m_sprite; //wskaźnik na obiekt klasy Sprite (kontekst graficzny)
			AnimationState *m_animation_state; //wskaźnik na obiekt AnimationState
			std::string m_animation_name; //nazwa animacji
			bool m_smooth; //flaga, czy obiekt wygładza piksele tekstury

		private:

			sf::Image *p_synthetic_image; //wskaźnik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
			sf::Texture *p_synthetic_texture; //wskaźnik na obiekt klasy sf::Texture
		};
	} //namespace displayable
}//namespace rendering
#endif //H_DISPLAYABLE_JACK
