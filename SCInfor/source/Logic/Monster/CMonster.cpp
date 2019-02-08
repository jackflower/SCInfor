/*
 _______________________________________
| CMonster.cpp - implementacja klasy.   |
| Jack Flower - January 2014.           |
|_______________________________________|

*/

#include "CMonster.h"
#include "../Physical/PhysicalInfo/CPhysicalInfo.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Rendering/Animations/CAnimationState.h"
#include "../../Rendering/Animations/CAnimation.h"
#include "../../Game/Game.h"
#include <SFML/Window.hpp>

using namespace rendering::displayable;
using namespace rendering::animation;
using namespace game;

namespace logic
{
	//Chroniony konstruktor domy�lny
	CMonster::CMonster(const std::wstring& uniqueId)
		:
		Actor(uniqueId),//konstruktor klasy bazowej
		m_time_do_death(0.0f)
	{
	}

	//Destruktor wirtualny
	CMonster::~CMonster(void)
	{
		m_time_do_death = 0.0f;
	}

	//Wirtualna metoda aktualizuj�ca obiekt
	void CMonster::update(float dt)
	{
		CPhysical::update(dt);
		Actor::updateComponents(dt);

		////////na razie testy..., bo w Actor b�dzie ju� opakowana metoda...
		//////if (p_physical_info)
		//////	p_physical_info->SetPosition(this->GetPosition());


		sf::Vector2i position = sf::Mouse::getPosition(*gGame.getRenderWindow());
		//zamiana koordynat�w na wsp�rz�dne �wiata u�ywaj�cego kamery
		position.x = (int)gGame.getRenderWindow()->mapPixelToCoords(position).x;
		position.y = (int)gGame.getRenderWindow()->mapPixelToCoords(position).y;

		if (position.x >= GetPosition().x - GetDisplayableBody()->getLocalBounds().width * GetDisplayableBody()->getScale().x * 0.5f &&
			position.x <= GetPosition().x + GetDisplayableBody()->getLocalBounds().width * GetDisplayableBody()->getScale().x * 0.5f &&
			position.y >= GetPosition().y - GetDisplayableBody()->getLocalBounds().height * GetDisplayableBody()->getScale().y * 0.5f &&
			position.y <= GetPosition().y + GetDisplayableBody()->getLocalBounds().height * GetDisplayableBody()->getScale().y * 0.5f)
		{
			//RotateHead(0.62f);	//brakuje wrappera w tej klasie dla metody void RotateHead(float angle) - equipment
			//RotateBody(-0.62f);	//brakuje wrappera w tej klasie dla metody void RotateBody(float angle) - equipment
			SetRotationHead(this->GetRotationHead() + 0.62f);
			SetRotationBody(this->GetRotationBody() - 0.62f);
			//tutaj obs�uga klawiatury...
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
				fprintf(stderr, "Test key pressed...\n");
		}

		//atrapa odroczonej �mierci...
		//if(p_animation_body)
		//{
		//	m_time_do_death = m_time_do_death + 0.01f;//kumuluj�...
		//	if(m_time_do_death > p_animation_body->TotalLength())
		//		kill();
		//}

		//
		//float anim_spped_body = GetAnimSpeedBody();

		//jest ok, speed factor = 1
		//int demo = 0;


		//Obs�ugiwane klawisze: RGBTY
		//to dzia�a...
		//uwaga, z racji tego, �e jestemm w update, tak wszystko co testuj�
		//odbywa si� w p�tli czasu rzeczywistego...
		//zatem, nale�y pami�ta�, aby obs�uga odbywa�a si� "jeden raz",
		//czyli ob�uga zdarze�...
		//////sf::Event::KeyEvent &e  = gGame.GetGameEvent().key;
		//////if (e.code == sf::Keyboard::T)
		//////{
		//////	GetDisplayableBody()->setColor(sf::Color::Yellow);
		//////	fprintf(stderr, "Test key pressed...\n");//strzelam seriami...
		//////}


		////////ten kod dzia�a
		//////if (gGame.GetGameEvent().key.code == sf::Keyboard::Y)
		//////{
		//////	GetDisplayableBody()->setColor(sf::Color::Yellow);
		//////	fprintf(stderr, "Yellow key pressed...\n");//strzelam seriami...
		//////}

		//ten kod dzia�a poprawnie
		if (gGame.getGameEvent().key.code == sf::Keyboard::K)
			RestoreColorBody();
	

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			//key R is pressed: set Red color our character
			GetDisplayableBody()->setColor(sf::Color::Red);
			fprintf(stderr, "Red key pressed...\n");//single...(ale w update trudno upilnowa�)
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			//key G is pressed: set Green color our character
			GetDisplayableBody()->setColor(sf::Color::Green);
			fprintf(stderr, "Green key pressed...\n");//single...(ale w update trudno upilnowa�)
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			//key B is pressed: set Blue color our character
			GetDisplayableBody()->setColor(sf::Color::Blue);
			fprintf(stderr, "Blue key pressed...\n");//single...(ale w update trudno upilnowa�)
		}
	}
}//namespace logic
