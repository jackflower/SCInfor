//  ______________________________________________
// | AnimatedAnimation.h - class definition       |
// | Jack Flower - March 2009                     |
// |______________________________________________|
//

#ifndef H_ANIMATED_ANIMATION_JACK
#define H_ANIMATED_ANIMATION_JACK

#include "AnimatedFrame.h"
#include "../../RTTI/RTTI.h"
#include <vector>


namespace animated
{

	///
	///Klasa reprezentuje animację
	///
	class AnimatedAnimation
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor domyślny
		///
		AnimatedAnimation();

		///
		///Konstruktor kopiujący
		///
		///@param copy - stała referencja na obiekt klasy AnimatedAnimation
		///
		AnimatedAnimation(const AnimatedAnimation & copy);

		///
		///Konstruktor przenoszący
		///
		///@param other = referencja do r-wartości
		///
		AnimatedAnimation(AnimatedAnimation && other);

		///
		///Konstruktor parametryczny
		///
		///@param texture - tekstura
		///
		///@param width_frame - szerokość klatki animacji
		///
		///@param height_frame - wysokość klatki animacji
		///
		AnimatedAnimation(const rendering::displayable::Texture & texture, int width_frame, int height_frame);
		
		///
		///Destruktor
		///
		virtual ~AnimatedAnimation();

		///
		///Przeciążony operator przypisania kopiowania
		///
		///@param copy - stała referencja na obiekt klasy Animation
		///
		AnimatedAnimation & operator=(const AnimatedAnimation & copy);

		///
		///Przeciążony operator przypisania przenoszenia
		///
		///@param other -  referencja do r-wartości
		///
		AnimatedAnimation & operator=(AnimatedAnimation && other);

		///
		///Deklaracja operatora dla obiektu klasy AnimatedFrame
		///
		AnimatedFrame & operator[] (unsigned N);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca ilość obiektów klasy AnimatedFrame w wektorze
		///
		unsigned int size() const;

		///
		///Metoda dodaje do wektora obiekty klasy AnimatedFrame
		///
		///@param texture - tekstura
		///
		///@param width_frame - szerokość klatki animacji
		///
		///@param height_frame - wysokość klatki animacji
		///
		bool setAnimationFramesFromAtlasTexture(const Texture & texture, int width_frame, int height_frame);

		///
		///Metoda dodaje do wektora obiekt klasy AnimatedFrame
		///
		///@param texture - tekstura
		///
		///@param rectangle - obszar prostokątny
		///
		void setSingleAnimationFrameTexture(const Texture & texture, const sf::IntRect & rectangle );

		///
		///Metoda usuwa z wektora obiekt klasy CAnimFrame o podanym indeksie
		///
		///@param index - indeks klatki do usunięcia
		///
		void deleteAnimFrame(int index);

		///
		///Metoda usuwa z wektora wszystkie elementy
		///
		void clearAllAnimFrame();
	
		///
		///Metoda zwraca z wektora szerokość klatki animacji o podanym indeksie
		///
		///@param animframe_index - indeks klatki animacji
		///
		int const getAnimFrameWidth(int animframe_index);
	
		///
		///Metoda zwraca z wektora wysokość klatki animacji o podanym indeksie
		///
		///@param animframe_index - indeks klatki animacji
		///
		int const getAnimFrameHeight(int animframe_index);

	private:

		std::vector<AnimatedFrame> m_frame; //kontener na klatki animacji

		//metoda wstawia do wektora pojedynczy obiekt klasy AnimatedFrame
		void pushFrame(const AnimatedFrame & new_frame);
	};
}//namespace animated
#endif //H_ANIMATED_ANIMATION_JACK
