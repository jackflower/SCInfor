//  ______________________________________
// | CAnimated.h - class definition       |
// | Jack Flower - March 2009             |
// | update May 2017                      |
// |______________________________________|
//

#ifndef H_ANIMATED_JACK
#define H_ANIMATED_JACK
 
#include "CAnimatedAnimation.h"

namespace animated
{
	///
	///Klasa reprezentuje animowany obiekt (sprite)
	///
	class CAnimated : public sf::Sprite
	{
	public:

		///
		///Konstruktor domy�lny
		///
		CAnimated();

		///
		///Konstruktor parametryczny
		///
		///@param p_animation - wska�nik na obiekt klasy CAnimatedAnimation (animacja)
		///
		///@param play - tryb Pause/Play
		///
		///@param loop - tryb Loop
		///
		///@param time - czas ekspozycji klatki
		///
		CAnimated (CAnimatedAnimation* p_animation, bool play = true, bool Loop = true, float time = 0.f);

		///
		///Konstruktor kopiuj�cy
		///
		///@param & copy - parametr - obiekt klasy CAnimated
		///
		CAnimated(const CAnimated & copy);

		///
		///Destruktor wirtualny
		///
		virtual ~CAnimated();

		///
		///Metoda zwraca wska�nik na obiekt klasy CAnimatedAnimation
		///
		CAnimatedAnimation* GetAnimation() const;

		///
		///Metoda ustawia wska�nik na obiekt klasy CAnimatedAnimation
		///
		///@param animated - wska�nik na obiekt klasy CAnimatedAnimation (animacja)
		///
		///@param play - tryb Pause/Play
		///
		const void SetAnimation(CAnimatedAnimation* animated, bool play = false);

		///
		///Metoda wyrejestrowuje animacj� - obiekt klasy CAnimation
		///
		void UnsetAnim();

		///
	    ///Metoda zwraca numer aktualnej klatki animacji obiektu klasy CAnimation
		///
		const int GetCurrentFrame() const;

		///
		///Metoda ustawia numer klatki animacji obiektu klasy CAnimation
		///
		///@param frame - klatka animacji
		///
		const void SetFrame(int frame);

		///
		///Metoda zwraca czas ekspozycji klatki animacji obiektu klasy CAnimation
		///
		const float GetFrameTime() const;

		///
		///Metoda ustawia czas ekspozycji klatki animacji obiektu klasy CAnimation
		///
		///@param time - czas ekspozycji klatki animacji
		///
		const void SetFrameTime(float time);

		///
		///Metoda zwraca tryb pause animacji
		///
		const bool GetPaused() const;

		///
	    ///Metoda ustwia tryb pause animacji
		///
		///@param paused - tryb pause
		///
		const void SetPaused(bool paused);

		///
		///Metoda sprawdza czy ustawiony jest tryb Loop
		///
		const bool IsLoop() const;

		///
		///Metoda ustawiaj�ca tryb Loop animacji
		///
		///@param loop - tryb Loop
		///
		const void SetLoop(bool loop);
 
		///
	    ///Metoda zatrzymuje odtwarzanie animacji
		///
		void Pause();
 
		///
		///Metoda uruchamia animacj�
		///
		void Play();
 
		///
		///Metoda zatrzymuje animacj�
		///
		void Stop();
 
		///
		///Metoda sprawdza, czy animacja jest w trybie Pause
		///
		const bool IsPaused() const;

		///
	    ///Metoda sprawdza, czy animacja jest zatrzymana
		///
		const bool IsStoped() const;

		///
	    ///Metoda aktualizuje animacj�
		///
		///@param elapsed_time - czas
		///
	    void Update(float elapsed_time);
	
		///
		///Metoda zwraca numer ostatnio wy�wietlanej klatki animacji
		///
		const int GetLastAnimFrame() const;

		///
		///Metoda zwraca ilo�� klatek animacji
		///
		const int GetAnimSize() const;

		///
		///Metoda zwraca flag� standardowej konfiguracji animacji
		///
		const bool GetAnimMode() const;

		///
		///Metoda zwraca sta��, zdefiniowan� statycznie warto�� ekspozycji klatki animacji
		///
		const float GetDefaultFrameTime() const;

		///
		///Metoda renderuj�ca obiekt klasy CAnimated
		///
		///@render render - kontekst graficzny
		///
		virtual void draw(sf::RenderWindow* render);

	protected:

		float				m_time;					//czas ekspozycji klatki
	    float				m_elapsedtime;			//czas up�ywaj�cy
	    bool				m_paused;				//tryb Pause
	    bool				m_loop;					//tryb Loop
		CAnimatedAnimation*	p_animation;			//wska�nik na obiekt klasy CAnimatedAnimation (animacja)
	    int					m_currentframe;			//bie��ca klatka animacji
		int					m_lastanimframe;		//klatka, na kt�rej zako�czy�a si� animacja
		bool				m_default_anim_mode;	//flaga standardowej konfiguracji trybu animacji
		static const float	m_default_time;			//warto�� domy�lna czasu ekspozycji klatki animacji
	};
}//namespace animated
#endif //H_ANIMATED_JACK


// //usage
//sf::Texture animation_texture;
//animation_texture.loadFromFile("../data/logo_sci_atlas.png");
//animated::CAnimatedAnimation animacja;
//animacja.SetAnimationFramesFromAtlasTexture(animation_texture, 50, 50);
//animated::CAnimated animek;
//animek.SetAnimation(&animacja);
//animek.setPosition(150.f, 150.f);
////animek.Update(time); loop update game
