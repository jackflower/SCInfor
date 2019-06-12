//  _____________________________________________
// | GameProperties.cpp - class implementatation |
// | Jack Flower -  July 2012                    |
// |_____________________________________________|
//

#include <iostream>
#include "GameProperties.h"
#include "Game.h"

using namespace game;

template<> GameProperties* CSingleton<GameProperties>::m_singleton = 0;

namespace game
{
	//Konstruktor
	GameProperties::GameProperties(void)
	:
		m_width{ 0 },
		m_height{ 0 },
		m_bits_per_pixel_depth{ 0 },
		m_fullscreen{ false },
		m_vsync{ false },
		m_sound_volume{ 0.0f },
		m_music_volume{ 0.0f },
		m_windows_name{},
		m_time_step{ 0.0f }
	{
		std::cout << "CGameProperties::GameProperties()" << std::endl;
	}

	//Konstruktor kopiujący
	GameProperties::GameProperties(const GameProperties& GamePropertiesCopy)
	:
		m_width{ GamePropertiesCopy.m_width },
		m_height{ GamePropertiesCopy.m_height },
		m_bits_per_pixel_depth{ GamePropertiesCopy.m_bits_per_pixel_depth },
		m_fullscreen{ GamePropertiesCopy.m_fullscreen },
		m_vsync{ GamePropertiesCopy.m_vsync },
		m_sound_volume{ GamePropertiesCopy.m_sound_volume },
		m_music_volume{ GamePropertiesCopy.m_music_volume },
		m_windows_name{ GamePropertiesCopy.m_windows_name },
		m_time_step{ GamePropertiesCopy.m_time_step }
	{
	}

	//Destruktor
	GameProperties::~GameProperties(void)
	{
		m_width = 0;
		m_height = 0;
		m_bits_per_pixel_depth = 0;
		m_fullscreen = false;
		m_vsync = false;
		m_sound_volume = 0;
		m_music_volume = 0;
		m_windows_name = "";
		m_time_step = 0.0f;
	}

	//Metoda zwraca szerokość okna
	unsigned int GameProperties::getWidth()
	{
		return m_width;
	}

	//Metoda ustawia szerokość okna
	void GameProperties::setWidth(unsigned int width)
	{
		m_width = width;
	}

	//Metoda zwraca wysokość okna
	unsigned int GameProperties::getHeight()
	{
		return m_height;
	}

	//Metoda ustawia wysokość okna
	void GameProperties::setHeight(unsigned int height)
	{
		m_height = height;
	}

	//Metoda zwraca głebię kolorów
	unsigned int GameProperties::getBitsPerPixel()
	{
		return m_bits_per_pixel_depth;
	}

	//Metoda ustawia głębię kolorów
	void GameProperties::setBitsPerPixel(unsigned int bits_per_pixel_depth)
	{
		m_bits_per_pixel_depth = bits_per_pixel_depth;
	}

	//Metoda zwraca tryb pełnoekranowy
	bool GameProperties::isFullscreen()
	{
		return m_fullscreen;
	}

	//Metoda ustawia tryb pełnoekranowy
	void GameProperties::setFullscreen(bool fullscreen)
	{
		m_fullscreen = fullscreen;
	}

	//Metora zwraca tryb synchronizacji pionowej
	bool GameProperties::isVSync()
	{
		return m_vsync;
	}

	//Metoda ustawia tryb synchronizacji pionowej
	void GameProperties::setVSync(bool vsync)
	{
		m_vsync = vsync;
	}

	//Metoda zwraca głośność dźwięku
	float GameProperties::getSoundVolume()
	{
		return m_sound_volume;
	}

	//Metoda ustawia głośność dźwięku
	void GameProperties::setSoundVolume(float sound_volume)
	{
		m_sound_volume = sound_volume;
	}

	//Metoda zwraca głośność muzyki
	float GameProperties::getMusicVolume()
	{
		return m_music_volume;
	}

	//Metoda ustawia głośność muzyki
	void GameProperties::setMusicVolume(float music_volume)
	{
		m_music_volume = music_volume;
	}

	//Metoda zwraca nazwę okna
	const std::string GameProperties::getWindowName() const
	{
		return m_windows_name;
	}

	//Metoda ustawia nazwę okna
	const void GameProperties::setWindowName(std::string &windows_name)
	{
		m_windows_name = windows_name;
	}

	//Metoda ładująca dane
	bool GameProperties::load(const std::string &name)
	{
		std::cout << "GameProperties::load ...game properties loading..." << std::endl;
		Xml xml(name, "root" );
		return load(xml);
	}

	//Metoda ładująca dane z xml
	bool GameProperties::load(Xml &xml)
	{
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "game_config"))
		{
			m_width = xml.getInt(node, "width");
			m_height = xml.getInt(node, "height");
			m_bits_per_pixel_depth = xml.getInt(node, "bits_per_pixel_depth");
			m_fullscreen = xml.getBool(node, "fullscreen");
			m_vsync	= xml.getBool(node, "vsync");
			m_sound_volume = xml.getFloat(node, "sound_volume");
			m_music_volume = xml.getFloat(node, "music_volume");
			m_windows_name = xml.getString(node, "windows_name");
			m_time_step = xml.getFloat(node, "time_step");

			if(m_time_step <=0.f)
				m_time_step = 0.025f;//gdyby coś się nie powiodło...
		}
		std::cout << "GameProperties::load ...game properties loaded..." << std::endl;
		return true;
	}

	//Metoda tworzy okno
	void GameProperties::updateWindow()
	{
		std::cout << "updateWindow()" << std::endl;
		//na wszelki wypadek usuwamy okno...
		if(gGame.getRenderWindow())
		{
			gGame.getRenderWindow()->close();
			delete gGame.getRenderWindow();
		}
		//tworzymy okno
		std::cout << "setRenderWindow()" << std::endl;
		gGame.setRenderWindow(new sf::RenderWindow(sf::VideoMode(m_width, m_height, m_bits_per_pixel_depth), m_windows_name,sf::Style::Close));
		gGame.setTimeStep(m_time_step);
		gGame.getRenderWindow()->setKeyRepeatEnabled(false);
		//blokujemy powtarzalność generatora klawiatury
		//gdy mamy wciśnięty jakiś klawisz
		//(czyli przy wciśniętym klawiszu coś się "zrobi" jeden raz)
		std::cout << "gGame.getRenderWindow()->setKeyRepeatEnabled(false)" << std::endl;
	}

	//Wirtualna metoda czyszcząca singleton
	void GameProperties::cleanup()
	{
		std::cout << "CGameProperties::cleanup()" << std::endl;
		std::cout << "CGameProperties::cleanup() done..." << std::endl;
	}
}//namespace game
