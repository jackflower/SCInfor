/*
 ____________________________________
| CLogic.cpp - implementacja klasy.  |
| Jack Flower - January 2013.        |
|____________________________________|

*/


#include "CLogic.h"
#include "../Game/Game.h"
#include "../Logic/CPhysicalManager.h"
#include "../Logic/Physical/Physical.h"

#include "../Logic/CMapPhysicalManager.h"
#include "../Map/MapPhysical/CMapPhysical.h"

//mo�e si� przyda, gdy jaki� ucze� napisze implementacj�...
#include <cstdio>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace logic;
using namespace game;

template<> CLogic* CSingleton<CLogic>::m_singleton = 0;

namespace logic
{
	//Konstruktor
	CLogic::CLogic()
	:
		m_state				(L"main-menu")//potrzebna b�dzia jaka� tablica stan�w logiki gry...
	{
		fprintf(stderr, "CLogic::CLogic()\n");
		gGame.addFrameListener(this);
		gGame.addKeyListener(this);
		gGame.addMouseListener(this);
	}

	//Destruktor wirtualny
	CLogic::~CLogic()
	{
		fprintf(stderr, "CLogic::~CLogic()\n");
		delete CPhysicalManager::GetSingletonPtr();
	}

	//Wirtualna metoda aktualizuj�ca logik� obiekt�w - implementacja
	void CLogic::frameStarted(float secondsPassed)
	{
		UpdatePhysicals(secondsPassed);
		UpdateMapPhysicals(secondsPassed);
	}

	//Wirtualna metoda aktualizuj�ca logik� gry - zdarzenia klawiatury
	void CLogic::KeyPressed(const sf::Event::KeyEvent &e)
	{
		//zarz�dzanie planszami w rozgrywce
		// - menu
		// - opcje
		// - statystyki
		// - etc...
		//to do...

		//testy obs�ugi klawiatury
		//do sta�ej referencji podpinamy kontener ze wska�nikami na obiekty klasy Physical
		//const std::vector<Physical*> &physicals = gPhysicalManager.GetPhysicals();
		if (e.code == sf::Keyboard::W)
		{
			//for (unsigned int i = 0; i < physicals.size(); ++i)
			//	physicals[i]->SetColorBody(sf::Color::Green);
			fprintf(stderr, "W key pressed...\n");
		}

		////ten kod reaguje na jedno wci�ni�cie klaw
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		//	fprintf(stderr, "Red is red...\n");

		//tutaj mo�na podpi�� zdarzenie shoot....
	}

	//Wirtualna metoda aktualizuj�ca logik� gry - zdarzenia myszy
	void CLogic::MousePressed(const sf::Event::MouseButtonEvent &e)
	{
		CheckRestart();
		//to do...
	}

	//Metoda zwraca stan logiki gry
	const std::wstring& CLogic::GetState()
	{
		return m_state;
	}

	//Metoda ustaiwia stan logiki gry
	void CLogic::SetState( const std::wstring& state )
	{
		m_state = state;
	}

	//Metoda uruchamia now� rozgrywk�
	void CLogic::StartNewGame(const std::wstring& start_file)
	{
		//to do...
	}

	//Metoda restaruje rozgrywk�
	void CLogic::CheckRestart()
	{
		if (m_state == L"death-ready-to-restart")
		{
			ExitToMainMenu();
		}
	}

	//Metoda powrotu do g��wnego menu ustawie� gry
	void CLogic::ExitToMainMenu()
	{
		//to do...
	}

	//Metoda czy�ci stan rozgrywki
	void CLogic::Clear()
	{
		gPhysicalManager.Clear(true);
	}


	//Metoda zapisuje stan gry
	void CLogic::SaveGame(const std::string& name)
	{
		//to do...
	}

	//Metoda odczytuje stan zapisanej gry
	void CLogic::LoadGame(const std::string & name)
	{
		//to do...
	}

	//Metoda aktualizuje wszystkie obiekty dziedzicz�ce po Physical
	void CLogic::UpdatePhysicals(float secondsPassed)
	{
		//do sta�ej referencji podpinamy kontener ze wska�nikami na obiekty klasy Physical
		const std::vector<Physical*> &physicals = gPhysicalManager.GetPhysicals();

		//aktualizacja - wywo�anie wirtualnej metody z logik�
		for (unsigned int i = 0; i < physicals.size(); ++i)
			physicals[i]->update( secondsPassed );


		//int test = 0;

		//w klasie CPhysicalManager mo�na umie�ci� gotowe metody zwracaj�ce
		//sta�e referencje na przefiltroane (przygotowane) kontenery
		//z obiektami wed�ug potrzenych kryteri�w (np. p o w e r s t a t i o n)

		////2015 - 07 - 07
		////p o w e r s t a t i o n
		////przepisanie  p o w e r s t a t i o n  do osobnego kontenera
		////pos�uguj� si� katwegori�, bo w ten spos�b b�d� m�g�
		////sk�ada� kategorie wed�ug zbior�w, grupowa�, etc...
		////2016 - czerwiec
		////doda� do kodu fabryk, wywo�anie metody ustawiajacej kategori�
		////danego obiektu (metoda fill(Typ *pointer)
		//std::vector<Physical*>				power;
		//std::vector<Physical*>::iterator	it_power;
		//for (unsigned int i = 0; i < physicals.size(); ++i)
		//	if(physicals[i]->GetCategory() == PHYSICAL_POWERSTATION)
		//		power.push_back(physicals[i]);
		////obs�uga  p o w e r s t a t i o n
		//for (it_power = power.begin() ; it_power != power.end() ; it_power++)
		//{
		//	(*it_power)->SetColorBody(sf::Color::Red);
		//	(*it_power)->SetColorHead(sf::Color::Green);
		//}
		//std::cout << power.size() << std::endl;
		////p o w e r s t a t i o n

		
		//2015 - 07 - 06
		//przyk�ad pokazuje, �e zarz�zanie kategoriami physicals dzia�a
		//w ten spos�b mog� zarz�dza� tylko takimi physicals, kt�re
		//tworz� modu� logiki zwi�zany z [TrakcjaEnergetyczna]
		//for (unsigned int i = 0; i < physicals.size(); ++i)
		//{
		//	if(physicals[i]->GetCategory() == PHYSICAL_MONSTER)
		//	{
		//		physicals[i]->SetColorBody(sf::Color::Red);
		//	}
		//}
	}

	//Metoda aktualizuje wszystkie obiekty dziedzicz�ce po CMapPhysical
	void CLogic::UpdateMapPhysicals(float secondsPassed)
	{
		const std::vector<CMapPhysical*> &mapphysicals = gMapPhysicalManager.GetMapPhysicals();
		for (unsigned int i = 0; i < mapphysicals.size(); ++i)
			mapphysicals[i]->update( secondsPassed );
	}

}//namespace logic
