//  __________________________________
// | CGame.cpp - class implementation |
// | Jack Flower - July 2012          |
// |__________________________________|
//

#include <vector>
#include <iostream>
#include <string>
#include "Game.h"
#include "../ResourceManager/CResourceManager.h"
#include "../ResourceManager/CTexture.h"
#include "../ResourceManager/CFont.h"
#include "../Rendering/Animations/CAnimationManager.h"
#include "../Rendering/Drawable/CDrawableManager.h"
#include "../Rendering/Displayable/CDisplayable.h"
#include "../Rendering/Displayable/CRectangle.h"
#include "../Rendering/Displayable/CHudStaticText.h"
#include "../Universe/CUniverse.h"
#include "../Weather/CWeather.h"
#include "../Factory/CPhysicalTemplate.h"
#include "../Logic/CLogic.h"
#include "../Map/CMap.h"
#include "../Utilities/Random/CRandom.h"
#include "../Utilities/EntityTranslator/CEntityTranslator.h"
#include "../Equipment/Industrial/PowerModuleType/WindTurbine.h"
#include "../Equipment/Industrial/PowerModuleType/SolarCell.h"
#include "../Utilities/MathFunctions/MathFunctions.h"
#include "../Utilities/TimeUtilities/CClock.h"
#include "../Utilities/Translation/Directions.h"
#include "../Utilities/CharsetTools/CCharSetManager.h"
#include "../Utilities/FileUtils/PathManager/CPathManager.h"
#include "../Map/Tile/CTile.h"
#include "../Map/CMapManager.h"
#include "../Equipment/Lightingequipment/ELightingEquipmentState.h"
#include "../Universe/CUniverse.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/AirconditioningFactory/CAirconditioningTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/CWindPowerStationTemplate.h"
#include "../Factory/MapPhysicalFactory/CMapPhysicalTemplate.h"
#include "../Factory/MapPhysicalFactory/CGroundWorkTemplate.h"
#include "../Factory/InformationFactory/CInformationTemplate.h"
#include "../Factory/InformationFactory/CPresentationTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/PowerRelayFactory/CPowerRelayStationTemplate.h"
#include "../Logic/CMapPhysicalManager.h"
#include "../Map/MapPhysical/CMapPhysical.h"
#include "../Logic/Actor/CActorController.h"
#include "../Logic/Energetics/PowerRelay/CPowerRelayStation.h"
#include "../Logic/CPhysicalManager.h"
#include "../Information/CInformation.h"
#include "../Map/Ground/CGround.h"
#include "../Equipment/Weapon/Ammo/Ammo.h"
#include "../Equipment/Weapon/Gun/Gun.h"
#include "../Factory/EquipmentFactory/CommunicationFactory/CommunicationTemplate.h"
#include "../Logic/Communication/CCommunication.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/AirconditioningFactory/CAirconditioningTemplate.h"
#include "../Equipment/Thermodynamics/Airconditioning/Airconditioning.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/ThermalInsulationFactory/CThermalInsulationTemplate.h"
#include "../Equipment/Thermodynamics/ThermalInsulation/ThermalInsulation.h"


using namespace logic;
using namespace listener;
using namespace game;
using namespace factory;
using namespace weather;
using namespace mapengine;
using namespace equipment;
using namespace equipment::weapon;
using namespace fileutils;
using namespace universe;
using namespace rendering;
using namespace rendering::primitives;
using namespace rendering::displayable;
using namespace information;
using namespace information::presentation;
using namespace charsettools;
using namespace logic::energetics;
using namespace logic::communication;
using namespace equipment::battery;

//p a u s e
//docelowo opakować, uporządkować, etc...
bool go = false;
float timeToGo = 1.f;
//p a u s e

template<> Game* CSingleton<Game>::m_singleton = 0;

namespace game
{
	//Konstruktor domyślny
	Game::Game(void)
	:
		m_render_window(0),
		m_fps_text(),
		m_seconds_passed(0.0f),
		m_last_update_time(0.0f),
		m_accumulator(0.0f),
		m_time_step(0.025f),//gdyby nie udało się załadować tego z pliku konfiguracji
		MAX_ACCUMULATED_TIME(1.f)
	{
		std::cout << "Game::Game()" << std::endl;
		gGameProperties.load("../data/xml_data/gameconfiguration/game-config.xml");
		gGameProperties.updateWindow();
	}

	//Destruktor
	Game::~Game(void)
	{
		std::cout << "Game::~Game()" << std::endl;
		//m_fps_text
		m_seconds_passed = 0.0f;
		m_last_update_time = 0.0f;
		m_accumulator = 0.0f;
		m_time_step = 0.0f;
		//MAX_ACCUMULATED_TIME
		Cleanup();
	}

	//Wirtualna metoda czyszcząca singleton
	void Game::cleanup()
	{
		std::cout << "Game::Cleanup()" << std::endl;
		m_render_window = NULL;
		std::cout << "Game::Cleanup() done..." << std::endl;
	}

	//Metoda zwraca wskaźnik na okno gry
	sf::RenderWindow * Game::getRenderWindow()
	{
		return m_render_window;
	}

	//Metoda ustawia wskaźnik na okno gry
	void Game::setRenderWindow(sf::RenderWindow *p_render_window)
	{
		m_render_window = p_render_window;
		std::cout << "Game::setRenderWindow()" << std::endl;
	}

	//Metoda zwraca wartość kroku czasowego
	const float Game::getTimeStep() const
	{
		return m_time_step;
	}

	//Metoda ustawia wartość kroku czasowego
	void Game::setTimeStep(float time_step)
	{
		m_time_step = time_step;
	}

	//Metoda uruchamia główną pętlę gry
	void Game::run()
	{
		mainLoop();
	}

	//Metoda aktualizuje stan gry
	void Game::updateGame(float dt)
	{
		//aktulizacja listenerów...
		std::set<IFrameListener*>::iterator i;
		for (i = m_frameListeners.begin(); i != m_frameListeners.end(); i++)
			(*i)->frameStarted(dt);

		//czyszczenie okna gry
		m_render_window->clear(sf::Color(255,255,255));
		//rysujemy obiekty na scenie
		gDrawableManager.DrawFrame();
		//statystyki
		m_fps_text.setString("FPS: "+ stringutils::ToString<float>(gClock.GetFPS()));
		//m_fps_text.setString(L"ęęźźÓÓĄŻłń");
		m_render_window->setView(m_render_window->getDefaultView());
		m_render_window->draw(m_fps_text);
		
		//2014-11-04
		//to należy napisać lepiej, jak będzie czas...
		//najprawdopodobniej, zamiast czysczenia ekranu
		//będzie wyświetlany ekran startowy gry...
		//mini wait...(wymaga dopracowania)
		//zmienne gdzieś opakować...
		//zmiana nazw zmiennych...
		if(go == false)
		{
			timeToGo -= dt;
			if(timeToGo >= 0.f)
			{
				m_render_window->clear(sf::Color(255,255,255));
				//std::cout << "czekam... " << timeToGo << std::endl;
				std::cout << ".";
			}
			
			if(timeToGo <= 0.f)
			{
				timeToGo = 0.f;
				go = true;
				std::cout << std::endl;
				std::cout << "game is   s t a r t i n g... " << std::endl;
			}
		}
		//2014-11-04

		//wyświetlenie sceny w oknie
		m_render_window->display();
		//aktualizacja zegara
		gClock.update();
	}

	//Metoda zwraca referencję do obiektu klasy sf::Event
	sf::Event & Game::getGameEvent()
	{
		return m_event;
	}

	//Metoda dodaje do zbioru wskaźniki obiektów aktualizowanych aktualizujących logikę
	void Game::addFrameListener(listener::IFrameListener *frameListener)
	{
		m_frameListeners.insert(frameListener);
	}

	//Metoda dodaje do zbioru wskaźniki obiektów aktualizowanych zdarzenia klawiatury
	void Game::addKeyListener(listener::IKeyListener *keyListener)
	{
		m_keyListeners.insert(keyListener);
	}

	//Metoda dodaje do zbioru wskaźniki obiektów aktualizowanych zdarzenia myszy
	void Game::addMouseListener(listener::IMouseListener *mouseListener)
	{
		m_mouseListeners.insert(mouseListener);
	}


	//implementacja metod private:

	//pętla główna gry
	void Game::mainLoop()
	{
		//inicjacja seed...
		gRandom.Seed((unsigned) gClock.GetTime());

		//ręczna, bezpieczna inicjacja niektórych singleton
		initSingletons();

		//
		//To Do...
		//
		//Dodać poniższy mechanizm do klasy CGameProperties,
		//która aktywuje tę flagę dla obiektu klasy CGame
		//
		//ograniczenie dla generatora klawiatury...
		//należy pamiętać, że obsługa klawiarury z poziomu class CMonster
		//wygeneruje na konsoli komunikat testowy tyle razy ile jest
		//zarejestrowanych obiektów klasy CMonster
		//
		//prawidłowa (implementacja z projektu Testowy), determinuje
		//obsługę klawiatury poprzez flagę aktywowania poprzez wskazanie
		//myszą samego obiektu (m_is_checked)...
		m_render_window->setKeyRepeatEnabled(false);

		//inicjalizacja zestawu polskich znaków diaktrytycznymi
		gCharSetManager.InitializeValidChars("../data/xml_data/gameconfiguration/unicode-cheatsheet.xml");

		//bardzo źle napisane...można poniższe opakować do jakiejś klasy/metody?
		CFont font = *gResourceManager.GetFont("../data/fonts/tahoma.ttf");
		m_fps_text.setString("ZaczynamyęęśśććźźĄĄ");
		m_fps_text.setFont(font);
		m_fps_text.setCharacterSize(20);
		m_fps_text.setFillColor(sf::Color::Blue);
		m_fps_text.setPosition(10,10);

		// m a p a
		gMapManager.SetMap("../data/xml_data/maps/dark_forest.xml", true);
		//gMapManager.SaveMap("../data/xml_data/maps/alabama.xml");

		gameTest();

		std::cout << "Game::run()" << std::endl;
		//camera 2014-12-11
		sf::View camera_1(sf::FloatRect(0,0,800,600));	//testy...camera_game
		camera_1.setViewport(sf::FloatRect(0, 0, 1, 1));
		//camera_1.zoom(2.5f);
		sf::View camera_2(sf::FloatRect(0,0,800,600));//testy...camera_game
		camera_2.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
		//camera 2014-12-11

		while (m_render_window->isOpen())
		{
			
			//obliczenie ile minęło czasu od ostatniej klatki
			m_seconds_passed = gClock.GetElapsedTime() - m_last_update_time;
			//podmiana (aktualizacja czasu ostatniej aktualizacji)
			m_last_update_time += m_seconds_passed;
			//upewniamy się, że secondsPassed >= 0
			m_seconds_passed = std::max(0.0f, m_seconds_passed);
			//kumulacja czasu
			m_accumulator += m_seconds_passed;
			//zapobiegamy zbyt dużej ilości aktualizacji w danym obiegu pętli głównej
			m_accumulator = maths::Clamp(m_accumulator, 0, MAX_ACCUMULATED_TIME);

			//f u t u r e...
			//wersja alternatywna (zmienna dt)
			//secondsPassed = m_clock.GetElapsedTime();
			//UpdateGame(secondsPassed);
			//wersja alternatywna (zmienna dt)

			while (m_render_window->pollEvent(m_event))
			{
				switch (m_event.type)
				{
				case sf::Event::Closed:
					m_render_window->close();
					return;

				case sf::Event::KeyPressed:
					for (std::set<IKeyListener*>::iterator i = m_keyListeners.begin() ; i != m_keyListeners.end(); i++ )
						(*i)->KeyPressed(m_event.key);
					break;
				
				default:
					break;
				}
			}

			while(m_accumulator > m_time_step)
			{
				//docelowo umieścić ten kod w UpdateGame(...)
				//camera_1.move(50.f * m_time_step, 50.f * m_time_step);//camera update
				//camera_1.setCenter(camera_1.getCenter().x + 0.25f, camera_1.getCenter().y);//kamera podąża da obiektem

				//projekcja
				m_render_window->setView(camera_1);

				updateGame(m_time_step); //logic and physics update
				m_accumulator -= m_time_step;
			}
		}
	}

	//Metoda inicjuje singletny
	const void Game::initSingletons()
	{
		gRandom;
		gCharSetManager;
		gGame;
		gPathManager;
		gGameProperties;
		gResourceManager;
		gDrawableManager;
		gAnimationManager;
		gMapManager;
		gUniverse;
		gWeather;
		gPhysicalManager;
		gLogic;
		//gMapPhysicalManager;
		gEntityTranslator;
	}
}//namespace game

 //metoda pomocnicza
void game::Game::gameTest()
{
	//do testów jednostkowych
	std::string file_name = "../data/xml_data/units_enemy/unit_alpha.xml";
	std::string file_name_weapon_ammo = "../data/xml_data/equipment/weapon/ammo_alpha.xml";
	std::string file_name_weapon_gun = "../data/xml_data/equipment/weapon/gun_alpha.xml";
	std::string file_name_energy = "../data/xml_data/equipment/energy/equipment_energy_alpha.xml";
	std::string file_name_windturbine = "../data/xml_data/equipment/industrial/windturbinebeta.xml";
	std::string file_name_powerstation = "../data/xml_data/powerstation/wind_power_station_alpha.xml";
	std::string file_name_power_relay_station = "../data/xml_data/powerrelaystation/power_relay_station_alpha.xml";
	std::string file_name_battery = "../data/xml_data/equipment/energy/battery/battery_alpha.xml";


	//p h y s i c a l - obiekt testowy - mam być tylko jeden tej klasy (respawn używa innych)
	CPhysicalTemplate *p_enemy_factory = gResourceManager.GetPhysicalTemplate(file_name);
	CPhysical *p_enemy = p_enemy_factory->create(L"ID_Enemy");
	if (p_enemy)
	{
		p_enemy->SetPosition(300, 100);
		p_enemy->SetRotationHead(45.f);
		//p_enemy->SetScaleBody(2.5f, 2.5f);
		//p_enemy->SetScaleHead(2.5f, 2.5f);
		p_enemy->SetScale(2.5f);
		p_enemy->setSmoothing(true);
		//do testów...jak znalazł...
		//p_enemy->GetDisplayableHead()->setVisible(false);
		//p_enemy->GetDisplayableHeadShadow()->setVisible(false);
		//p_enemy->GetDisplayableBody()->setVisible(false);
		//p_enemy->GetDisplayableBodyShadow()->setVisible(false);
		//Play(); Stop()...
		//p_enemy->GetDisplayableBody()->GetAnimationState()->
	}

	//for (int i = 0; i < 5; i++)
	//{
	//	CPhysical *p_object = p_enemy_factory->create(L"ID_Object");
	//	p_object->SetPosition((i * 64)+200, 520);
	//	p_object->setSmoothing(true);
	//}

	//CPresentation
	//CPresentationTemplate *demo = gResourceManager.GetPresentationTemplate("data/xml_data/information/presentation.xml");
	//CPresentation *prezes = demo->create(L"Pitek");
	//prezes->setPosition(420, 420);

}
