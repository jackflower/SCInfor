//  __________________________________
// | Logic.h - class definition       |
// | Jack Flower - January 2013       |
// |__________________________________|


#ifndef H_LOGIC_JACK
#define H_LOGIC_JACK

#include "../Utilities/Singleton/CSingleton.h"
#include "../Game/Listener/IFrameListener.h"
#include "../Game/Listener/IKeyListener.h"
#include "../Game/Listener/IMouseListener.h"

using namespace listener;

#define gLogic Logic::GetSingleton()

namespace logic
{
	///
	///Klasa reprezentuje mechanizm logiki rozgrywki
	///
	class Logic : public CSingleton<Logic>, IFrameListener, IKeyListener, IMouseListener
	{
	public:

		///
		///Konstruktor
		///
		Logic();

		///
		///Destruktor wirtualny
		///
		virtual ~Logic();

		///
		///Wirtualna metoda aktualizująca logikę obiektów
		///
		virtual void frameStarted(float secondsPassed);

		///
		///Wirtualna metoda aktualizująca logikę gry - zdarzenia klawiatury
		///
		///@param e - stała referencja na obiekt klasy sf::Event::KeyEvent
		///
		virtual void keyPressed(const sf::Event::KeyEvent & e);
	    
		///
		///Wirtualna metoda aktualizująca logikę gry - zdarzenia myszy
		///
		///@param e - stała referencja na obiekt klasy sf::Event::MouseButtonEvent
		///
		virtual void mousePressed(const sf::Event::MouseButtonEvent & e);

		///
		///Metoda zwraca stan logiki gry
		///
		const std::wstring & getState();

		///
		///Metoda ustawia stan logiki gry
		///
		///@param state - stała referencja na obiekt klasy std::wstring
		///
		void setState(const std::wstring & state);

		///
		///Metoda uruchamia nową rozgrywkę
		///
		///@param start_file - stała referncja na obiekt klasy std::wstring
		///
		void startNewGame(const std::wstring & start_file = L"new-game");
		
		///
		///Metoda restaruje rozgrywkę
		///
		void checkRestart();
		
		///
		///Metoda powrotu do głównego menu ustawień gry
		///
		void exitToMainMenu();
		
		///
		///Metoda czyści stan rozgrywki
		///
		void clear();

		///
		///Metoda zapisuje stan gry
		///
		///@param name - stała referencja na obiekt klasy std::string
		///
		void saveGame(const std::string & name);

		///
		///Metoda odczytuje stan zapisanej gry
		///
		///@param name - stała referencja na obiekt klasy std::string
		///
		void loadGame(const std::string & name);

		///
		///Metoda aktualizuje wszystkie obiekty dziedziczące po Physical
		///
		///@param secondsPassed - upływający czas gry
		///
		void updatePhysicals(float secondsPassed);

		///
		///Metoda aktualizuje wszystkie obiekty dziedziczące po MapPhysical
		///
		///@param secondsPassed - upływający czas gry
		///
		void updateMapPhysicals(float secondsPassed);

	private:
		
		std::wstring m_state; //stan logiki gry
	};
}//namespace logic
#endif//H_LOGIC_JACK
