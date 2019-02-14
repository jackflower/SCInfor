//  _____________________________________
// | Animated.h - class definition       |
// | Jack Flower - March 2009            |
// |_____________________________________|
//

#ifndef H_ANIMATED_JACK
#define H_ANIMATED_JACK

#include <SFML/Graphics.hpp>
#include "AnimatedAnimation.h"
#include "../../RTTI/RTTI.h"
#include "../Displayable/CSprite.h"

using namespace rendering::displayable;

namespace animated
{
	///
	///Klasa reprezentuje animowany obiekt (sprite)
	///
	class Animated : public CSprite
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor domyślny
		///
		Animated();

		///
		///Konstruktor kopiujący
		///
		///@param copy - parametr - obiekt klasy Animated
		///
		Animated(const Animated & copy);

		///
		///Konstruktor przenoszący
		///
		///@param other - referencja do r-wartości
		///
		Animated(Animated && other);

		///
		///Konstruktor parametryczny
		///
		///@param p_animation - wskaźnik na obiekt klasy AnimatedAnimation (animacja)
		///
		///@param play - tryb Pause/Play
		///
		///@param loop - tryb Loop
		///
		///@param time - czas ekspozycji klatki
		///
		Animated (AnimatedAnimation *p_animation, bool play = true, bool Loop = true, float time = 0.f);
		
		///
		///Destruktor wirtualny
		///
		virtual ~Animated();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Przeciążony operator przypisania kopiowania
		///
		///@param copy - stała referencja na obiekt klasy Animated
		///
		Animated & operator=(const Animated & copy);

		///
		///Przeciążony operator przypisania przenoszenia
		///
		///@param other -  referencja do r-wartości
		///
		Animated & operator=(Animated && other);

		///
		///Metoda zwraca wskaźnik na obiekt klasy AnimatedAnimation
		///
		AnimatedAnimation *getAnimation() const;

		///
		///Metoda ustawia wskaźnik na obiekt klasy AnimatedAnimation
		///
		///@param animated - wskaźnik na obiekt klasy AnimatedAnimation (animacja)
		///
		///@param playmode - tryb pause/play
		///
		const void setAnimation(AnimatedAnimation *animated, bool playmode = false);

		///
		///Metoda wyrejestrowuje animację - obiekt klasy Animation
		///
		void unsetAnim();

		///
	    ///Metoda zwraca numer aktualnej klatki animacji obiektu klasy Animation
		///
		const int getCurrentFrame() const;

		///
		///Metoda ustawia numer klatki animacji obiektu klasy Animation
		///
		///@param frame - klatka animacji
		///
		const void setFrame(int frame);

		///
		///Metoda zwraca czas ekspozycji klatki animacji obiektu klasy Animation
		///
		const float getFrameTime() const;

		///
		///Metoda ustawia czas ekspozycji klatki animacji obiektu klasy Animation
		///
		///@param time - czas ekspozycji klatki animacji
		///
		const void setFrameTime(float time);

		///
		///Metoda zwraca tryb pause animacji
		///
		const bool getPaused() const;

		///
	    ///Metoda ustwia tryb pause animacji
		///
		///@param paused - tryb pause
		///
		const void setPaused(bool paused);

		///
		///Metoda sprawdza czy ustawiony jest tryb Loop
		///
		const bool isLoop() const;

		///
		///Metoda ustawiająca tryb Loop animacji
		///
		///@param loop - tryb Loop
		///
		const void setLoop(bool loop);
 
		///
	    ///Metoda zatrzymuje odtwarzanie animacji
		///
		void pause();
 
		///
		///Metoda uruchamia animację
		///
		void play();
 
		///
		///Metoda zatrzymuje animację
		///
		void stop();
 
		///
		///Metoda sprawdza, czy animacja jest w trybie pause
		///
		const bool isPaused() const;

		///
	    ///Metoda sprawdza, czy animacja jest zatrzymana
		///
		const bool isStoped() const;

		///
	    ///Metoda aktualizuje animację
		///
		///@param elapsed_time - czas
		///
	    void update(float elapsed_time);
	
		///
		///Metoda zwraca numer ostatnio wyświetlanej klatki animacji
		///
		const int getLastAnimFrame() const;

		///
		///Metoda zwraca ilość klatek animacji
		///
		const int getAnimSize() const;

		///
		///Metoda zwraca flagę standardowej konfiguracji animacji
		///
		const bool getAnimMode() const;

		///
		///Metoda zwraca stałą, zdefiniowaną statycznie wartość ekspozycji klatki animacji
		///
		const float getDefaultFrameTime() const;

		///
		///Metoda renderująca obiekt klasy Animated
		///
		///@render render - kontekst graficzny
		///
		virtual void draw(sf::RenderWindow *render);

	protected:

		float m_time; //czas ekspozycji klatki
	    float m_elapsedtime; //czas upływający
	    bool m_paused; //tryb Pause
	    bool m_loop; //tryb Loop
		AnimatedAnimation *p_animation; //wskaźnik na obiekt klasy AnimatedAnimation (animacja)
	    int m_currentframe; //bieżąca klatka animacji
		int m_lastanimframe; //klatka, na której zakończyła się animacja
		bool m_default_anim_mode; //flaga standardowej konfiguracji trybu animacji
		float m_animation_spped; //prędkość odtwarzania animacji
		static const float m_default_time; //wartość domyślna czasu ekspozycji klatki animacji
	};
}//namespace animated
#endif //H_ANIMATED_JACK


// //usage
//sf::Texture animation_texture;
//animation_texture.loadFromFile("../data/logo_sci_atlas.png");
//animated::AnimatedAnimation animacja;
//animacja.SetAnimationFramesFromAtlasTexture(animation_texture, 50, 50);
//animated::Animated animek;
//animek.SetAnimation(&animacja);
//animek.setPosition(150.f, 150.f);
////animek.update(time); loop update game
