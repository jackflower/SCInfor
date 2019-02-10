//  __________________________________
// | Enemy.cpp - class implememtation |
// | Jack Flower - March 2014         |
// |__________________________________|
//

#include "Enemy.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Game/Game.h"

using namespace rendering::displayable;
using namespace game;


namespace logic
{
	RTTI_IMPL(Enemy, Actor);

	//Chroniony konstruktor domyślny
	Enemy::Enemy(const std::wstring & uniqueId) 
	:	
		Actor(uniqueId)//konstruktor klasy bazowej
	{
	}

	//Chroniony konstruktor kopiujący
	Enemy::Enemy(const Enemy & EnemyCopy)
	:
		Actor(EnemyCopy)//konstruktor kopiujący klasy bazowej
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
	Enemy::~Enemy(void) 
	{
		//~Actor()
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Enemy::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda aktualizująca obiekt
	void Enemy::update(float dt)
	{
		Actor::update(dt);

		//2014-05-12
		//waste - testy poglądowe....
		sf::Vector2i position = sf::Mouse::getPosition(*gGame.getRenderWindow());
		//zamiana koordynatów na współrzędne świata używającego kamery
		position.x = (int)gGame.getRenderWindow()->mapPixelToCoords(position).x;
		position.y = (int)gGame.getRenderWindow()->mapPixelToCoords(position).y;

		//uwaga: Gdyby coś nie działało, to jako drugi parament - kamera...
		//Adventure:
		//sf::Vector2f worldPos = m_render_window.mapPixelToCoords(position, m_camera);

		//if(m_player.getGlobalBounds().contains((float)pixelPos.x, (float)pixelPos.y))
		//if(GetDisplayableBody()->getGlobalBounds().contains((float)position.x, (float)position.y))
		//{
		//	SetRotationHead(this->GetRotationHead() + 0.62f);
		//	SetRotationBody(this->GetRotationBody() - 0.62f);
		//}

		if(	position.x >= GetPosition().x - GetDisplayableBody()->getLocalBounds().width * GetDisplayableBody()->getScale().x * 0.5f && 
			position.x <= GetPosition().x + GetDisplayableBody()->getLocalBounds().width * GetDisplayableBody()->getScale().x * 0.5f && 
			position.y >= GetPosition().y - GetDisplayableBody()->getLocalBounds().height * GetDisplayableBody()->getScale().y * 0.5f &&
			position.y <= GetPosition().y + GetDisplayableBody()->getLocalBounds().height * GetDisplayableBody()->getScale().y * 0.5f)
		{
			//RotateHead(0.62f);	//2019-02-10 (jest) brakuje wrappera w tej klasie dla metody void RotateHead(float angle) - equipment
			//RotateBody(-0.62f);	//2019-02-10 (jest) brakuje wrappera w tej klasie dla metody void RotateBody(float angle) - equipment
			SetRotationHead(this->GetRotationHead() + 0.62f);
			SetRotationBody(this->GetRotationBody() - 0.62f);
		}
	}

	//Wirtualan metoda zabija obiekt klasy Enemy i wywołuje odpowiednie czynności z tym związane
	void Enemy::kill() 
	{
		//implementacja zachowania obiektu przed wywołaniem jego destrukcji...
		Actor::kill();
		//to do...
	}
}//namespace logic
