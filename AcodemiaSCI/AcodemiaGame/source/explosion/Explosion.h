////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////


#ifndef H_EXPLOSION_ACODEMIA
#define H_EXPLOSION_ACODEMIA

#include "../animation/Animated.h"
#include "../animation/Animation.h"

namespace acodemia
{
	namespace animation
	{
		///
		///Klasa reprezentuje eksplozję
		///
		class Explosion
		{
		public:

			///
			///Konstruktor domyślny
			///
			Explosion();

			///
			///Konstruktor kopiujący
			///
			///@param copy - stała referencja na obiekt klasy Explosion
			///
			Explosion(const Explosion & copy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Explosion(Explosion && other);

			///
			///Destruktor
			///
			~Explosion();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Explosion
			///
			Explosion & operator=(const Explosion & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Explosion & operator=(Explosion && other);

			///
			///Metoda zwraca stałą referencję pozycji obiektu
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
			///Metoda ustawia pozycję obiektu
			///
			///@param vector - stała referenacja na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & vector);

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
			///@param new_scale_value - stała referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f & new_scale_value);

			///
			///Metoda ustawia skalę
			///
			///@param factors - jednolita wartość skalująca w osi x i y
			///
			void setScale(float factors);

			///
			///Metoda zwraca prędkość odtwarzania animacji
			///
			const float getAnimationSpeed() const;

			///
			///Metoda ustawia prędkość odtwarzania animacji
			///
			///@param speed - prędkość odtwarzania animacji
			///
			void setAnimationSpeed(float speed);

			///
			///Metoda ustawia teksturę eksplozji
			///
			///@param texture_filename - stała referencja na nazwę pliku tekstury
			///
			///@param explosion_frame_width - szerokość klatki animacji eksplozji
			///
			///@param explosion_frame_height - wysokość klatki animacji eksplozji
			///
			void setExplosionTexture(const acodemia::rendering::Texture & texture, int explosion_frame_width, int explosion_frame_height);

			///
			///Metoda zwraca informację, czy eksplozja ma być zniszczona
			///
			const bool getDestruction() const;

			///
			///Metoda aktualizuje eksplozję
			///
			///@param elapsed_time - czas
			///
			void update(float elapsed_time);

			///
			///Metoda renderująca obiekt klasy Explosion
			///
			///@param render - wskaźnik na kontekst graficzny
			///
			virtual void draw(sf::RenderWindow & render) const;

		private:

			Animation explosion_animation;//animacja eksplozji
			Animated explosion;//obiekt animowany eksplozji
			bool m_destruction; //flaga destrukcji

		};
	}//animation
}//acodemia
#endif//H_EXPLOSION_ACODEMIA
