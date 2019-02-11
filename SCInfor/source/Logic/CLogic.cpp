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

//mo¿e siê przyda, gdy jakiœ uczeñ napisze implementacjê...
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
		m_state				(L"main-menu")//potrzebna bêdzia jakaœ tablica stanów logiki gry...
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

	//Wirtualna metoda aktualizuj¹ca logikê obiektów - implementacja
	void CLogic::frameStarted(float secondsPassed)
	{
		UpdatePhysicals(secondsPassed);
		UpdateMapPhysicals(secondsPassed);
	}

	//Wirtualna metoda aktualizuj¹ca logikê gry - zdarzenia klawiatury
	void CLogic::KeyPressed(const sf::Event::KeyEvent &e)
	{
		//zarz¹dzanie planszami w rozgrywce
		// - menu
		// - opcje
		// - statystyki
		// - etc...
		//to do...

		//testy obs³ugi klawiatury
		//do sta³ej referencji podpinamy kontener ze wskaŸnikami na obiekty klasy Physical
		//const std::vector<Physical*> &physicals = gPhysicalManager.GetPhysicals();
		if (e.code == sf::Keyboard::W)
		{
			//for (unsigned int i = 0; i < physicals.size(); ++i)
			//	physicals[i]->SetColorBody(sf::Color::Green);
			fprintf(stderr, "W key pressed...\n");
		}

		////ten kod reaguje na jedno wciœniêcie klaw
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		//	fprintf(stderr, "Red is red...\n");

		//tutaj mo¿na podpi¹æ zdarzenie shoot....
	}

	//Wirtualna metoda aktualizuj¹ca logikê gry - zdarzenia myszy
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

	//Metoda uruchamia now¹ rozgrywkê
	void CLogic::StartNewGame(const std::wstring& start_file)
	{
		//to do...
	}

	//Metoda restaruje rozgrywkê
	void CLogic::CheckRestart()
	{
		if (m_state == L"death-ready-to-restart")
		{
			ExitToMainMenu();
		}
	}

	//Metoda powrotu do g³ównego menu ustawieñ gry
	void CLogic::ExitToMainMenu()
	{
		//to do...
	}

	//Metoda czyœci stan rozgrywki
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

	//Metoda aktualizuje wszystkie obiekty dziedzicz¹ce po Physical
	void CLogic::UpdatePhysicals(float secondsPassed)
	{
		//do sta³ej referencji podpinamy kontener ze wskaŸnikami na obiekty klasy Physical
		const std::vector<Physical*> &physicals = gPhysicalManager.GetPhysicals();

		//aktualizacja - wywo³anie wirtualnej metody z logik¹
		for (unsigned int i = 0; i < physicals.size(); ++i)
			physicals[i]->update( secondsPassed );


		//int test = 0;

		//w klasie CPhysicalManager mo¿na umieœciæ gotowe metody zwracaj¹ce
		//sta³e referencje na przefiltroane (przygotowane) kontenery
		//z obiektami wed³ug potrzenych kryteriów (np. p o w e r s t a t i o n)

		////2015 - 07 - 07
		////p o w e r s t a t i o n
		////przepisanie  p o w e r s t a t i o n  do osobnego kontenera
		////pos³ugujê siê katwegori¹, bo w ten sposób bêdê móg³
		////sk³adaæ kategorie wed³ug zbiorów, grupowaæ, etc...
		////2016 - czerwiec
		////dodaæ do kodu fabryk, wywo³anie metody ustawiajacej kategoriê
		////danego obiektu (metoda fill(Typ *pointer)
		//std::vector<Physical*>				power;
		//std::vector<Physical*>::iterator	it_power;
		//for (unsigned int i = 0; i < physicals.size(); ++i)
		//	if(physicals[i]->GetCategory() == PHYSICAL_POWERSTATION)
		//		power.push_back(physicals[i]);
		////obs³uga  p o w e r s t a t i o n
		//for (it_power = power.begin() ; it_power != power.end() ; it_power++)
		//{
		//	(*it_power)->SetColorBody(sf::Color::Red);
		//	(*it_power)->SetColorHead(sf::Color::Green);
		//}
		//std::cout << power.size() << std::endl;
		////p o w e r s t a t i o n

		
		//2015 - 07 - 06
		//przyk³ad pokazuje, ¿e zarz¹zanie kategoriami physicals dzia³a
		//w ten sposób mogê zarz¹dzaæ tylko takimi physicals, które
		//tworz¹ modu³ logiki zwi¹zany z [TrakcjaEnergetyczna]
		//for (unsigned int i = 0; i < physicals.size(); ++i)
		//{
		//	if(physicals[i]->GetCategory() == PHYSICAL_MONSTER)
		//	{
		//		physicals[i]->SetColorBody(sf::Color::Red);
		//	}
		//}
	}

	//Metoda aktualizuje wszystkie obiekty dziedzicz¹ce po CMapPhysical
	void CLogic::UpdateMapPhysicals(float secondsPassed)
	{
		const std::vector<CMapPhysical*> &mapphysicals = gMapPhysicalManager.GetMapPhysicals();
		for (unsigned int i = 0; i < mapphysicals.size(); ++i)
			mapphysicals[i]->update( secondsPassed );
	}

}//namespace logic
