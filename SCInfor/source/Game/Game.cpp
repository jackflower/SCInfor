//  __________________________________
// | CGame.cpp - class implementation |
// | Jack Flower - July 2012          |
// |__________________________________|
//

#include <vector>
#include <iostream>
#include <string>
#include "Game.h"
#include "../ResourceManager/ResourceManager.h"
#include "../ResourceManager/ResourceTexture.h"
#include "../ResourceManager/Font.h"
#include "../Rendering/Animations/AnimationManager.h"
#include "../Rendering/Drawable/DrawableManager.h"
#include "../Rendering/Displayable/Displayable.h"
#include "../Rendering/Displayable/Rectangle.h"
#include "../Rendering/Displayable/HudStaticText.h"
#include "../Universe/Universe.h"
#include "../Weather/Weather.h"
#include "../Factory/PhysicalTemplate.h"
#include "../Logic/Logic.h"
#include "../Map/Map.h"
#include "../Utilities/Random/CRandom.h"
#include "../Utilities/EntityTranslator/CEntityTranslator.h"
#include "../Equipment/Industrial/PowerModuleType/WindTurbine.h"
#include "../Equipment/Industrial/PowerModuleType/SolarCell.h"
#include "../Utilities/MathFunctions/MathFunctions.h"
#include "../Utilities/TimeUtilities/CClock.h"
#include "../Utilities/Translation/Directions.h"
#include "../Utilities/CharsetTools/CCharSetManager.h"
#include "../Utilities/FileUtils/PathManager/CPathManager.h"
#include "../Map/Tile/Tile.h"
#include "../Map/MapManager.h"
#include "../Equipment/Lightingequipment/ELightingEquipmentState.h"
#include "../Universe/Universe.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/AirconditioningFactory/AirconditioningTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/WindPowerStationTemplate.h"
#include "../Factory/MapPhysicalFactory/MapPhysicalTemplate.h"
#include "../Factory/MapPhysicalFactory/GroundWorkTemplate.h"
#include "../Factory/InformationFactory/InformationTemplate.h"
#include "../Factory/InformationFactory/PresentationTemplate.h"
#include "../Factory/IndustrialFactory/PowerStationFactory/PowerRelayFactory/PowerRelayStationTemplate.h"
#include "../Logic/MapPhysicalManager.h"
#include "../Map/MapPhysical/MapPhysical.h"
#include "../Logic/Actor/ActorController.h"
#include "../Logic/Energetics/PowerRelay/PowerRelayStation.h"
#include "../Logic/PhysicalManager.h"
#include "../Information/BaseInformation.h"
#include "../Map/Ground/Ground.h"
#include "../Equipment/Weapon/Ammo/Ammo.h"
#include "../Equipment/Weapon/Gun/Gun.h"
#include "../Factory/EquipmentFactory/CommunicationFactory/CommunicationTemplate.h"
#include "../Logic/Communication/Communication.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/AirconditioningFactory/AirconditioningTemplate.h"
#include "../Equipment/Thermodynamics/Airconditioning/Airconditioning.h"
#include "../Factory/EquipmentFactory/ThermodynamicsFactory/ThermalInsulationFactory/ThermalInsulationTemplate.h"
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
		cleanup();
	}

	//Wirtualna metoda czyszcząca singleton
	void Game::cleanup()
	{
		std::cout << "Game::cleanup()" << std::endl;
		m_render_window = nullptr;
		std::cout << "Game::cleanup() done..." << std::endl;
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
		gDrawableManager.drawFrame();
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
		//należy pamiętać, że obsługa klawiarury z poziomu class Monster
		//wygeneruje na konsoli komunikat testowy tyle razy ile jest
		//zarejestrowanych obiektów klasy Monster
		//
		//prawidłowa (implementacja z projektu Testowy), determinuje
		//obsługę klawiatury poprzez flagę aktywowania poprzez wskazanie
		//myszą samego obiektu (m_is_checked)...
		m_render_window->setKeyRepeatEnabled(false);

		//inicjalizacja zestawu polskich znaków diaktrytycznymi
		gCharSetManager.InitializeValidChars("../data/xml_data/gameconfiguration/unicode-cheatsheet.xml");

		//bardzo źle napisane...można poniższe opakować do jakiejś klasy/metody?
		resource::Font font = *gResourceManager.getFont("../data/fonts/tahoma.ttf");
		m_fps_text.setString("ZaczynamyęęśśććźźĄĄ");
		m_fps_text.setFont(font);
		m_fps_text.setCharacterSize(20);
		m_fps_text.setFillColor(sf::Color::Blue);
		m_fps_text.setPosition(10,10);

		// m a p a
		gMapManager.setMap("../data/xml_data/maps/dark_forest.xml", true);
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
	PhysicalTemplate *p_enemy_factory = gResourceManager.getPhysicalTemplate(file_name);
	Physical *p_enemy = p_enemy_factory->create(L"ID_Enemy");
	if (p_enemy)
	{
		p_enemy->setPosition(300, 100);
		p_enemy->setRotationHead(45.f);
		//p_enemy->setScaleBody(2.5f, 2.5f);
		//p_enemy->setScaleHead(2.5f, 2.5f);
		p_enemy->setScale(2.5f);
		p_enemy->setSmoothing(true);
		//do testów...jak znalazł...
		//p_enemy->getDisplayableHead()->setVisible(false);
		//p_enemy->getDisplayableHeadShadow()->setVisible(false);
		//p_enemy->getDisplayableBody()->setVisible(false);
		//p_enemy->getDisplayableBodyShadow()->setVisible(false);
		//Play(); Stop()...
		//p_enemy->getDisplayableBody()->GetAnimationState()->
	}

	//for (int i = 0; i < 5; i++)
	//{
	//	Physical *p_object = p_enemy_factory->create(L"ID_Object");
	//	p_object->setPosition((i * 64)+200, 520);
	//	p_object->setSmoothing(true);
	//}

	//Presentation
	//PresentationTemplate *demo = gResourceManager.GetPresentationTemplate("data/xml_data/information/presentation.xml");
	//Presentation *prezes = demo->create(L"Pitek");
	//prezes->setPosition(420, 420);

}
