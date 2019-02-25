//  __________________________________
// | Logic.cpp - class implementation |
// | Jack Flower - January 2013       |
// |__________________________________|
//


#include "Logic.h"
#include "../Game/Game.h"
#include "../Logic/PhysicalManager.h"
#include "../Logic/Physical/Physical.h"
#include "../Logic/MapPhysicalManager.h"
#include "../Map/MapPhysical/MapPhysical.h"

//może się przyda, gdy jakiś uczeń napisze implementację...
//#include <cstdio>
//#include <fstream>
//#include <sstream>
//#include <iostream>

using namespace logic;
using namespace game;

template<> Logic* CSingleton<Logic>::m_singleton = 0;

namespace logic
{
	//Konstruktor
	Logic::Logic()
	:
		m_state(L"main-menu")//potrzebna będzie jakaś tablica stanów logiki gry...
	{
		fprintf(stderr, "Logic::Logic()\n");
		gGame.addFrameListener(this);
		gGame.addKeyListener(this);
		gGame.addMouseListener(this);
	}

	//Destruktor wirtualny
	Logic::~Logic()
	{
		fprintf(stderr, "Logic::~Logic()\n");
		delete PhysicalManager::GetSingletonPtr();
	}

	//Wirtualna metoda aktualizująca logikę obiektów - implementacja
	void Logic::frameStarted(float secondsPassed)
	{
		updatePhysicals(secondsPassed);
		updateMapPhysicals(secondsPassed);
	}

	//Wirtualna metoda aktualizująca logikę gry - zdarzenia klawiatury
	void Logic::keyPressed(const sf::Event::KeyEvent & e)
	{
		//zarządzanie planszami w rozgrywce
		// - menu
		// - opcje
		// - statystyki
		// - etc...
		//to do...

		//testy obsługi klawiatury
		//do stałej referencji podpinamy kontener ze wskaźnikami na obiekty klasy Physical
		//const std::vector<Physical*> &physicals = gPhysicalManager.GetPhysicals();
		if (e.code == sf::Keyboard::W)
		{
			//for (unsigned int i = 0; i < physicals.size(); ++i)
			//	physicals[i]->SetColorBody(sf::Color::Green);
			fprintf(stderr, "W key pressed...\n");
		}

		////ten kod reaguje na jedno wciśnięcie klaw
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		//	fprintf(stderr, "Red is red...\n");

		//tutaj można podpiąć zdarzenie shoot....
	}

	//Wirtualna metoda aktualizująca logikę gry - zdarzenia myszy
	void Logic::mousePressed(const sf::Event::MouseButtonEvent & e)
	{
		checkRestart();
		//to do...
	}

	//Metoda zwraca stan logiki gry
	const std::wstring & Logic::getState()
	{
		return m_state;
	}

	//Metoda ustaiwia stan logiki gry
	void Logic::setState( const std::wstring & state )
	{
		m_state = state;
	}

	//Metoda uruchamia nową rozgrywkę
	void Logic::startNewGame(const std::wstring & start_file)
	{
		//to do...
	}

	//Metoda restaruje rozgrywkę
	void Logic::checkRestart()
	{
		if (m_state == L"death-ready-to-restart")
		{
			exitToMainMenu();
		}
	}

	//Metoda powrotu do głównego menu ustawień gry
	void Logic::exitToMainMenu()
	{
		//to do...
	}

	//Metoda czyści stan rozgrywki
	void Logic::clear()
	{
		gPhysicalManager.clear(true);
	}


	//Metoda zapisuje stan gry
	void Logic::saveGame(const std::string & name)
	{
		//to do...
	}

	//Metoda odczytuje stan zapisanej gry
	void Logic::loadGame(const std::string & name)
	{
		//to do...
	}

	//Metoda aktualizuje wszystkie obiekty dziedziczące po Physical
	void Logic::updatePhysicals(float secondsPassed)
	{
		//do stałej referencji podpinamy kontener ze wskaźnikami na obiekty klasy Physical
		const std::vector<Physical*> & physicals = gPhysicalManager.getPhysicals();

		//aktualizacja - wywołanie wirtualnej metody z logiką
		for (unsigned int i = 0; i < physicals.size(); ++i)
			physicals[i]->update( secondsPassed );


		//int test = 0;

		//w klasie PhysicalManager można umieścić gotowe metody zwracające
		//stałe referencje na przefiltroane (przygotowane) kontenery
		//z obiektami według potrzebnych kryteriów (np. p o w e r s t a t i o n)

		////2015 - 07 - 07
		////p o w e r s t a t i o n
		////przepisanie  p o w e r s t a t i o n  do osobnego kontenera
		////posługuję się kategorią, bo w ten sposób będę mógł
		////składać kategorie według zbiorów, grupować, etc...
		////2016 - czerwiec
		////dodać do kodu fabryk, wywołanie metody ustawiajacej kategorię
		////danego obiektu (metoda fill(Typ *pointer)
		//std::vector<Physical*>				power;
		//std::vector<Physical*>::iterator	it_power;
		//for (unsigned int i = 0; i < physicals.size(); ++i)
		//	if(physicals[i]->GetCategory() == PHYSICAL_POWERSTATION)
		//		power.push_back(physicals[i]);
		////obsługa  p o w e r s t a t i o n
		//for (it_power = power.begin() ; it_power != power.end() ; it_power++)
		//{
		//	(*it_power)->SetColorBody(sf::Color::Red);
		//	(*it_power)->SetColorHead(sf::Color::Green);
		//}
		//std::cout << power.size() << std::endl;
		////p o w e r s t a t i o n

		
		//2015 - 07 - 06
		//przykład pokazuje, że zarzązanie kategoriami physicals działa
		//w ten sposób mogę zarządzać tylko takimi physicals, które
		//tworzą moduł logiki związany z [TrakcjaEnergetyczna]
		//for (unsigned int i = 0; i < physicals.size(); ++i)
		//{
		//	if(physicals[i]->GetCategory() == PHYSICAL_MONSTER)
		//	{
		//		physicals[i]->SetColorBody(sf::Color::Red);
		//	}
		//}
	}

	//Metoda aktualizuje wszystkie obiekty dziedziczące po MapPhysical
	void Logic::updateMapPhysicals(float secondsPassed)
	{
		const std::vector<MapPhysical*> &mapphysicals = gMapPhysicalManager.getMapPhysicals();
		for (unsigned int i = 0; i < mapphysicals.size(); ++i)
			mapphysicals[i]->update( secondsPassed );
	}

}//namespace logic
