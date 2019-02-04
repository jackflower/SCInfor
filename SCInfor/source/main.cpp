/*
#include <SFML/Graphics.hpp>
int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "SCInfor 2019", sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.display();
	}
	return 0;
}
*/



//poni¿ej - kod produkcyjny

#include "Game/Game.h"
#include <iostream>
#include "Utilities/Miscellaneous/Integer.h"
#include "Utilities/Miscellaneous/Float.h"
#include "Utilities/Miscellaneous/Miscellaneous.h"

using namespace game;

int main()
{
	//k o n i e c z n e !
	CSingletonCleaner cleaner;
	gGame.run();

	return 0;
}
