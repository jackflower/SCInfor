//  _________________________________________
// | Displayable.cpp - class implementation  |
// | Jack Flower - August 2012               |
// |_________________________________________|
//

#include "Displayable.h"
#include "../Animations/Animation.h"
#include "../Animations/AnimationManager.h"
#include "../Animations/AnimationState.h"
#include "../../ResourceManager/ResourceManager.h"
#include "../../ResourceManager/RTexture.h"
#include <SFML/Graphics.hpp>

namespace rendering
{
	namespace displayable
	{
		RTTI_IMPL(Displayable, Drawable);

		//Konstruktor domyślny
		Displayable::Displayable()
		:
			Drawable(),//konstruktor klasy bazowej
			m_sprite(),
			m_animation_state(NULL),
			m_animation_name(""),
			m_smooth(false),
			p_synthetic_texture(NULL),
			p_synthetic_image(NULL)
		{
			m_sprite = new Sprite();
			p_synthetic_texture = new sf::Texture;
			p_synthetic_image = new sf::Image;
		}

		//Konstruktor kopiujący
		Displayable::Displayable(const Displayable & DisplayableCopy)
		:
			Drawable(DisplayableCopy),//konstruktor kopiujący klasy bazowej
			//m_sprite //tego nie kopiujemy...(2019-02-19: poddać analizie...)
			m_animation_state(DisplayableCopy.m_animation_state),
			m_animation_name(DisplayableCopy.m_animation_name),
			m_smooth(DisplayableCopy.m_smooth),
			p_synthetic_texture(DisplayableCopy.p_synthetic_texture),
			p_synthetic_image(DisplayableCopy.p_synthetic_image)
		{
		}

		//Destruktor wirtualny
		Displayable::~Displayable() 
		{
			delete m_sprite;//usuwamy obiekt (mamy pewność, że istnieje, bo konstruktor go stworzył)
			m_sprite = NULL;

			if(m_animation_state)
				gAnimationManager.destroyAnimationState(m_animation_state);
			
			m_animation_state = NULL;
			m_animation_name = "";
			m_smooth = false;

			delete p_synthetic_texture;
			p_synthetic_texture	= NULL;
			delete p_synthetic_image;
			p_synthetic_image = NULL;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Displayable::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca wskaźnik na obiekt sf::Sprite
		Sprite *Displayable::getSprite()
		{
			return m_sprite;
		}

		//Metoda zwraca pozycję obiektu
		const sf::Vector2f & Displayable::getPosition() const
		{
			return m_sprite->getPosition();
		}

		//Metoda ustawia pozycję obiektu
		void Displayable::setPosition(float x, float y)
		{
			m_sprite->setPosition(x, y);
		}

		//Metoda ustawia pozycję obiektu
		void Displayable::setPosition(const sf::Vector2f & vector)
		{
			setPosition(vector.x, vector.y);
		}

		//Metoda zwraca wartość obrotu
		float Displayable::getRotation() const
		{ 
			return m_sprite->getRotation();
		}

		//Metoda ustawia wartość obrotu
		void Displayable::setRotation(float rotation_value)
		{
			m_sprite->setRotation(rotation_value);
		}

		//Metoda obraca wartość obrotu
		void Displayable::rotate(float angle)
		{
			m_sprite->rotate(angle);
		}

		//Metoda zwraca skalę
		const sf::Vector2f & Displayable::getScale() const
		{
			return m_sprite->getScale();
		}

		//Metoda ustawia skalę
		void Displayable::setScale(float x, float y)
		{
			m_sprite->setScale(x, y);
		}

		//Metoda ustawia skalę
		void Displayable::setScale(const sf::Vector2f & new_scale_value)
		{
			m_sprite->setScale(new_scale_value);
		}

		//Metoda ustawia skalę
		void Displayable::setScale(float factors)
		{
			setScale(factors, factors);
		}

		//Metoda ustawia skalę w stosunku do obecnej skali
		void Displayable::scale(float factorX, float factorY)
		{
			m_sprite->scale(factorX, factorY);
		}

		//Metoda ustawia skalę w stosunku do obecnej skali
		void Displayable::scale(const sf::Vector2f & factor)
		{
			m_sprite->scale(factor);
		}

		//Metoda zwraca współrzędne punktu uchwytu obiektu
		const sf::Vector2f & Displayable::getOrigin() const
		{
			return m_sprite->getOrigin();
		}

		//Metoda ustawia współrzędne punktu uchwytu obiektu
		void Displayable::setOrigin(float x, float y)
		{
			m_sprite->setOrigin(x, y);
		}

		//Metoda ustawia współrzędne punktu uchwytu obiektu
		void Displayable::setOrigin(const sf::Vector2f & origin)
		{
			m_sprite->setOrigin(origin);
		}

		//Metoda zwraca obszar prostokątny zajmowany przez teksturę
		const sf::IntRect & Displayable::getTextureRect() const
		{
			return m_sprite->getTextureRect();
		}

		//Metoda ustawia obszar prostokątny zajmowany przez teksturę
		void Displayable::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight)
		{
			setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
		}

		//Metoda ustawia obszar prostokątny zajmowany przez teksturę
		void Displayable::setTextureRect (const sf::IntRect& rectangle)
		{
			m_sprite->setTextureRect(rectangle);
		}

		//Metoda zwraca granice obiektu w lokalnym w układzie współrzędnych
		sf::FloatRect Displayable::getLocalBounds() const
		{
			return m_sprite->getLocalBounds();
		}

		//Metoda zwraca granice obiektu w globalnym w układzie współrzędnych
		sf::FloatRect Displayable::getGlobalBounds() const
		{
			return m_sprite->getGlobalBounds();
		}

		//Metoda przemieszcza obiekt o wartość podaną w parametrach względem aktualnej pozycji
		void Displayable::move(float offsetX, float offsetY)
		{
			m_sprite->move(offsetX, offsetY);
		}

		//Metoda przemieszcza obiekt o wartość wektora przesunięcia
		void Displayable::move(const sf::Vector2f & offset)
		{
			m_sprite->move(offset);
		}

		//Metoda zwraca kolor obiektu
		const sf::Color & Displayable::getColor() const
		{
			return m_sprite->getColor();
		}

		//Metoda ustawia kolor obiektu
		void Displayable::setColor(const sf::Color & color)
		{
			m_sprite->setColor(color);
		}

		//Metoda ustawia teksturę obiektu
		void Displayable::setTexture(const std::string & texture_name, bool smoothing)
		{
			m_smooth = smoothing;
			RTexture* p_texture = gResourceManager.getTexture(texture_name);
			if (!p_texture)
			{
				fprintf(stderr, "warning: Displayable::setTexture: unable to obtain image `%s'\n", texture_name.c_str());
				setTexture(NULL);
				return;
			}
			setTexture(p_texture, m_smooth);
		}

		//Metoda ustawia teksturę obiektu
		void Displayable::setTexture(RTexture *p_texture, bool smoothing)
		{
			if (m_animation_state)					//jeśli wskaźnik na AnimationState jest zainicjowany
			{
				gAnimationManager.destroyAnimationState(m_animation_state);//usuwamy animację
				m_animation_state = NULL;			//ustawiamy wskaźnik na NULL
			}

			if (p_texture != NULL)					//jeśli mamy wskaźnik poprawnie wskazujący na teksturę
			{
				p_texture->setSmooth(m_smooth);
				m_sprite->setTexture(*p_texture);	//ustawiamy teskturę
				//po załadowaniu tekstury wyznaczamy punkt uchwytu sprite'a na jego środek geometryczny
				m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 0.5f);
			}
		}

		//Metoda generuje obraz tekstury
		void Displayable::setTexture(unsigned width, unsigned height, const sf::Color & color)
		{
			if (m_animation_state)					//jeśli wskaźnik na AnimationState jest zainicjowany
			{
				gAnimationManager.destroyAnimationState(m_animation_state);//usuwamy animację
				m_animation_state = NULL;			//ustawiamy wskaźnik na NULL
			}

			p_synthetic_texture->create(width, height);
			p_synthetic_image->create(width, height, color);
			p_synthetic_texture->update(*p_synthetic_image);
			m_sprite->setTexture(*p_synthetic_texture);
		}

		//Metoda generuje obraz tekstury
		void Displayable::setTexture(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
		{
			if (m_animation_state)					//jeśli wskaźnik na AnimationState jest zainicjowany
			{
				gAnimationManager.destroyAnimationState(m_animation_state);//usuwamy animację
				m_animation_state = NULL;			//ustawiamy wskaźnik na NULL
			}
			
			p_synthetic_texture->create(width, height);
			p_synthetic_image->create(width, height, sf::Color(r, g, b, a));
			p_synthetic_texture->update(*p_synthetic_image);
			m_sprite->setTexture(*p_synthetic_texture);
		}

		//Metoda ustawia animację
		void Displayable::setAnimation(const std::string & animation_name)
		{
			//warunki, gdy zamiana animacji się nie powiedzie:
			//nie jest ładowana animacja, jeśli próbujemy
			//zamienić ją na taką samą (istniejącą pod taką samą nazwą)
			if (m_animation_name == animation_name) return;

			m_animation_name = animation_name;

			//usuwamy animację, jeśli wcześniej jakaś była
			if (m_animation_state)
				gAnimationManager.destroyAnimationState(m_animation_state);

			//tworzymy nową animację
			m_animation_state = gAnimationManager.createAnimationState(animation_name);

			if (!m_animation_state)
			{
				fprintf(stderr, "warning: Displayable::SetAnimation: unable to obtain animation `%s'\n", animation_name.c_str());
			} 
		}

		//Metoda ustawia animację
		void Displayable::setAnimation(Animation *p_animation)
		{
			//warunki, gdy zamiana animacji się nie powiedzie:
			//jeśli wskaźnik jest NULL - return
			//jeśli wskaźnik jest zainicjowany, a próbujemy go zainicjować takim samym wskaźnikiem - return

			if (p_animation == NULL)
				return;
			if ((m_animation_state != NULL) && (m_animation_state->getAnimation() == p_animation))
				return;

			m_animation_name = p_animation->getAnimationName();

			if (m_animation_state)
				gAnimationManager.destroyAnimationState(m_animation_state);
			m_animation_state = gAnimationManager.createAnimationState(p_animation);

			if (!m_animation_state)
			{
				fprintf(stderr, "warning: CDrawable::SetAnimation: unable to obtain animation '%s'\n", m_animation_name.c_str());
			} 
		}

		//Metoda zwraca wskaźnik na obiekt klasy AnimationState
		AnimationState *Displayable::getAnimationState()
		{
			return m_animation_state;
		}
		
		///Metoda zwraca tryb wygładzania tekstury
		const bool Displayable::getSmoothing() const
		{
			return m_smooth;
		}

		//Metoda ustawia tryb wygładzania tekstury
		void Displayable::setSmoothing(bool smooth)
		{
			m_smooth = smooth;
		}

		//Wirtualna metoda renderująca obiekt
		void Displayable::draw(sf::RenderWindow* render)
		{
			//jeśli flaga nie pozwala - nie rysujemy obiektu - return
			if(m_can_draw == false)	return;

			//jeśli wskaźnik na obiekt AnimationState pokazuje na animację
			if (m_animation_state)
			{
				//tworzymy klatkę animacji i pobieramy bieżącą klatkę z AnimationState
				AnimationFrame frame = m_animation_state->getCurrentFrame();

				//tworzymy wskaźnik na obiekt klasy RTexture (tekstura)
				//inicjujemy ten wskaźnik obrazem pobranym na podstawie nazwy
				//tekstury, na której znajduje sie klatka animacji.
				//ResourceManager zwraca na podstawie tej nazwy wskaźnik na teksturę.
				RTexture *p_texture = gResourceManager.getTexture(frame.getTextureName());
				//ustawiamy flagę wygładzania tekstury
				p_texture->setSmooth(m_smooth);

				//jeśli wskaźnik nie jest zainicjowany - komunikat o błędzie
				if (!p_texture)
				{
					fprintf(stderr, "warning: Displayable::draw: animation: unable to obtain image `%s'\n", frame.getTextureName().c_str());
				}
				else
				{
					//w przeciwnym wypadku pobieramy obszar klatki animacji
					sf::IntRect rect = frame.getImageRectangle();

					//sprawdzamy, wielkość tekstury (czy ten kod jest potrzebny?)
					//niech na razie sobie tutaj poleży, najwyżej można to zakomentować...
					//if (rect.left == 0 && rect.top == 0 && rect.width == 0 && rect.height == 0)
					//{
					//	rect.width = p_texture->getSize().x;	//wyznaczamy szerokość
					//	rect.height = p_texture->getSize().y;	//wyznaczamy wysokość
					//}
					p_texture->setSmooth(m_smooth);				//filtr
					m_sprite->setTexture(*p_texture);			//podłączamy wskaźnik na teksturę pod sprite'a
					m_sprite->setTextureRect(rect);				//podłączamy wyliczony obszar tekstury pod sprite'a

					//wyznaczamy punkt uchwytu sprite'a na jego środek geometryczny
					m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 0.5f);
				}
			}
			
			if(m_can_draw == false) return;	//na wszelki wypadek, gdyby w ramce czasu flaga ustawiła się na false
			if (m_sprite)					//na wszelki wypadek, gdyby wskaźnik stracił adres...
			{
				render->draw(*m_sprite);	//rysujemy obiekt
			}
		}
	}//namespace displayable
}//namespace rendering
