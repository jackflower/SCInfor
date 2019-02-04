//  ___________________________________
// | CEnemy.cpp - class implememtation |
// | Jack Flower - March 2014          |
// |___________________________________|
//

#include "CEnemy.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Game/Game.h"

using namespace rendering::displayable;
using namespace game;


namespace logic
{
	RTTI_IMPL(CEnemy, CActor);

	//Chroniony konstruktor domy�lny
	CEnemy::CEnemy(const std::wstring &uniqueId) 
	:	
		CActor					(uniqueId)//konstruktor klasy bazowej
	{
	}

	//Chroniony konstruktor kopiuj�cy
	CEnemy::CEnemy(const CEnemy &CEnemyCopy)
	:
		CActor					(CEnemyCopy)//konstruktor kopiuj�cy klasy bazowej
	{
	}

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
	CEnemy::~CEnemy(void) 
	{
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEnemy::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda aktualizuj�ca obiekt
	void CEnemy::update(float dt)
	{
		CActor::update(dt);

		//2014-05-12
		//waste - testy pogl�dowe....
		sf::Vector2i position = sf::Mouse::getPosition(*gGame.getRenderWindow());
		//zamiana koordynat�w na wsp�rz�dne �wiata u�ywaj�cego kamery
		position.x = (int)gGame.getRenderWindow()->mapPixelToCoords(position).x;
		position.y = (int)gGame.getRenderWindow()->mapPixelToCoords(position).y;

		//uwaga: Gdyby co� nie dzia�a�o, to jako drugi parament - kamera...
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
			//RotateHead(0.62f);	//brakuje wrappera w tej klasie dla metody void RotateHead(float angle) - equipment
			//RotateBody(-0.62f);	//brakuje wrappera w tej klasie dla metody void RotateBody(float angle) - equipment
			SetRotationHead(this->GetRotationHead() + 0.62f);
			SetRotationBody(this->GetRotationBody() - 0.62f);
		}
	}

	//Wirtualan metoda zabija obiekt klasy CEnemy i wywo�uje odpowiednie czynno�ci z tym zwi�zane
	void CEnemy::Kill() 
	{
		CActor::Kill();
		//to do...
	}
}//namespace logic
