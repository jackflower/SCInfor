//  __________________________________
// | CGame.h - class definition       |
// | Jack Flower - July 2012          |
// |__________________________________|
//

#ifndef H_GAME_JACK
#define H_GAME_JACK

#include <set>
#include <SFML/Graphics.hpp>
#include "GameProperties.h"
#include "../Utilities/Singleton/CSingleton.h"
#include "../Utilities/StringUtils/StringUtils.h"
#include "../Rendering/Displayable/HudStaticText.h"

#define gGame Game::GetSingleton()

///
///Forward declaration
///
namespace listener
{
	class IFrameListener;
	class IKeyListener;
	class IMouseListener;
}


namespace game
{
	///
	///Klasa reprezentuje okno gry
	///
	class Game : public CSingleton<Game>
	{
	public:

		///
		///Konstruktor domyślny
		///
		Game(void);

		///
		///Destruktor
		///
		~Game(void);

		///
		///Metoda zwraca wskaźnik na okno gry
		///
		sf::RenderWindow * getRenderWindow();

		///
		///Metoda ustawia wskaźnik na okno gry
		///
		///@param *p_renderWindow - wskaźnik na obiekt klasy sf::RenderWindow
		///
		void setRenderWindow(sf::RenderWindow *p_renderWindow);

		///
		///Metoda zwraca wartość kroku czasowego
		///
		const float getTimeStep() const;

		///
		///Metoda ustawia wartość kroku czasowego
		///
		///@param time_step - wartość kroku czasowego
		///
		void setTimeStep(float time_step);

		///
		///Metoda uruchamia główną pętlę gry
		///
		void run();

		///
		///Metoda aktualizuje stan gry
		///
		///@param dt - delta time
		///
		void updateGame(float dt);

		///
		///Metoda zwraca referencję do obiektu klasy sf::Event
		///
		sf::Event & getGameEvent();

		///
		///Metoda dodaje do zbioru wskaźniki obiektów aktualizowanych aktualizujących logikę
		///
		///@param *frameListener - wskaźnik na obiekt klasy IFrameListener
		///
		void addFrameListener(listener::IFrameListener *frameListener);
	    
		///
		///Metoda dodaje do zbioru wskaźniki obiektów aktualizowanych zdarzenia klawiatury
		///
		///@param *keyListener - wskaźnik na obiekt klasy IKeyListener
		//
		void addKeyListener(listener::IKeyListener *keyListener);
		
		///
		///Metoda dodaje do zbioru wskaźniki obiektów aktualizowanych zdarzenia myszy
		///
		///@param *mouseListener - wskaźnik na obiekt klasy IMouseListener
		///
		void addMouseListener(listener::IMouseListener *mouseListener);

	protected:
		
		///
		///Wirtualna metoda czyszcząca singleton
		///
		virtual void cleanup();

	private:

		std::set<listener::IFrameListener*>	m_frameListeners; //zbiór na wskaźniki obiektów aktualizowanych aktualizującymi logikę
		std::set<listener::IKeyListener*>	m_keyListeners; //zbiór na wskaźniki obiektów aktualizowanych zdarzenia klawiatury
		std::set<listener::IMouseListener*>	m_mouseListeners; //zbiór na wskaźniki obiektów aktualizowanych zdarzenia myszy
		sf::RenderWindow* m_render_window; //wskaźnik na renderowany obszar okna
		sf::Text m_fps_text; //obiekt do diagonostyki - wyświetlenie FPT...
		sf::Event m_event; //zdarzenia
		
		float m_seconds_passed; //czas w sekundach jaki upłynął od ostatniej aktualizacji
		float m_last_update_time; //czas ostatniej aktualizacji
		float m_accumulator; //akumulator czasu
		float m_time_step; //wartość kroku czasowego

		//maksymalny czas jaki może być zgromadzony w pojedynczym obiegu petli głównej
		const float MAX_ACCUMULATED_TIME; 
		void mainLoop(); //main game loop
		const void initSingletons(); //metoda inicjuje singletony
		void gameTest(); //metoda pomocnicza
	};
}//namespace game
#endif //H_GAME_JACK
