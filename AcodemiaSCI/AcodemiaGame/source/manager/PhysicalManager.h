////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#ifndef H_PHYSICAL_MANAGER_ACODEMIA
#define H_PHYSICAL_MANAGER_ACODEMIA

#include "SFML/Graphics.hpp"
#include "../utilities/Singleton.h"
#include <vector>
#include <typeinfo>
#include "../explosion/Explosion.h"

//deklaracje zapowiadające (forwad declarations)
namespace acodemia
{
	namespace physical
	{
		class Physical;
		class Bullet;
		class Actor;
		class Player;
		class Enemy;
	}
}

namespace acodemia
{
	namespace animation
	{
		class Explosion;
	}
}

using namespace acodemia::physical;
using namespace acodemia::animation;

#define gPhysicalManager PhysicalManager::getSingleton()

///
///Klasa reprezentuje fabrykę produkującą obiekty gry,
///zarządzanie obiektami, dziedziczy po szablonie,
///który jest wzorcem singletona - jest Singletonem
///
class PhysicalManager : public Singleton<PhysicalManager>
{
public:

	///
	///Konstruktor domyślny
	///
	PhysicalManager();

	///
	///Destruktor wirtualny
	///
	virtual ~PhysicalManager();

	///
	///Metoda zwraca stałą referencję kontenera
	///
	const std::vector<Physical*> & getPhysicals();

	///
	///Metoda rejestruje w kontenerze wskaźniki na obiekty Physical
	///
	///@param *physical - wskaźnik na obiekt Physical
	///
	void registerPhysical(Physical * physical);

	///
	///Metoda tworzy obiekt klasy Physical i zwraca wskaźnik na ten obiekt
	///
	Physical *CreatePhysical();

	///
	///Metoda tworzy obiekt klasy Bullet i zwraca wskaźnik na ten obiekt
	///
	Bullet *CreateBullet();

	///
	///Metoda tworzy obiekt klasy Actor i zwraca wskaźnik na ten obiekt
	///
	Actor *CreateActor();

	///
	///Metoda tworzy obiekt klasy Player i zwraca wskaźnik na ten obiekt
	///
	Player *CreatePlayer();

	///
	///Metoda tworzy obiekt klasy Enemy i zwraca wskaźnik na ten obiekt
	///
	Enemy *CreateEnemy();

	///
	///Metoda tworzy obiekt klasy Explosion i zwraca wskaźnik na ten obiekt
	///
	Explosion *CreateExplosion();

	///
	///Metoda aktualizuje  wskaźniki na obiekty Physical
	///
	///@param dt - czas
	///
	void updatePhysical(float dt);

	///
	///Wirtualna metoda rysująca obiekt
	///
	///@param render - kontekst graficzny
	///
	virtual void draw(sf::RenderWindow & render) const;

	///
	///Metoda sprawdza, czy nastąpiła jakaś kolizja
	///
	///@param *collider - wskaźnik na obiekt klasy Physical
	///
	bool checkCollision(Physical *collider);

	float width;
	float height;

private:

	//prywatna metoda aktualizuje pozycję obiektu w wyniku kolizji
	void updatePosition(Physical *object, Physical *collider);

	//kontener przechowuje wskaźniki na obiekty klasy Physical
	std::vector<Physical*> m_physicals;

	//szablon metody tworzenia obiektów
	template<class T> T* Create();

	//kontener przechowuje wskaźniki na obiekty klasy Explosion
	std::vector<acodemia::animation::Explosion*> m_explosions;

};
#endif//H_PHYSICAL_MANAGER_ACODEMIA
