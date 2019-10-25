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

#include "PhysicalManager.h"
#include "../physicals/physical/Physical.h"
#include "../physicals/bullet/Bullet.h"
#include "../physicals/actor/Actor.h"
#include "../physicals/player/Player.h"
#include "../physicals/enemy/Enemy.h"
#include "../explosion/Explosion.h"
#include<iostream>

using namespace acodemia::physical;

//Konstruktor domyślny
PhysicalManager::PhysicalManager()
	:
	m_physicals(),
	width(800),
	height(600.f)
{
}

//Destruktor wirtualny
PhysicalManager::~PhysicalManager()
{
	std::vector<Physical*>::iterator it;
	for (it = m_physicals.begin(); it != m_physicals.end(); it++)
	{
		if((*it))
			delete (*it);
	}
	m_physicals.clear();
}

//Metoda zwraca stałą referencję kontenera
const std::vector<Physical *> & PhysicalManager::getPhysicals()
{
	return m_physicals;
}

//Metoda rejestruje w kontenerze wskaźniki na obiekty Physical
void PhysicalManager::registerPhysical(Physical * physical)
{
	m_physicals.push_back(physical);
}

//Metoda tworzy obiekt klasy Physical i zwraca wskaźnik na ten obiekt
Physical *PhysicalManager::CreatePhysical()
{
	return Create<Physical>();
}

//Metoda tworzy obiekt klasy Bullet i zwraca wskaźnik na ten obiekt
Bullet *PhysicalManager::CreateBullet()
{
	return Create<Bullet>();
}

//Metoda tworzy obiekt klasy Actor i zwraca wskaźnik na ten obiekt
Actor *PhysicalManager::CreateActor()
{
	return Create<Actor>();
}

//Metoda tworzy obiekt klasy Player i zwraca wskaźnik na ten obiekt
Player *PhysicalManager::CreatePlayer()
{
	return Create<Player>();
}

//Metoda tworzy obiekt klasy Enemy i zwraca wskaźnik na ten obiekt
Enemy *PhysicalManager::CreateEnemy()
{
	return Create<Enemy>();
}

//Metoda tworzy obiekt klasy Explosion i zwraca wskaźnik na ten obiekt
Explosion *PhysicalManager::CreateExplosion()
{
	Explosion * p_explosion = new Explosion();
	m_explosions.push_back(p_explosion);
	return p_explosion;
}

//Metoda aktualizuje  wskaźniki na obiekty Physical
void PhysicalManager::updatePhysical(float dt)
{
	for (unsigned int i = 0; i < m_physicals.size(); i++)
	{
		checkCollision(m_physicals.at(i));//kolizje
		m_physicals.at(i)->update(dt);

		//jeśli obiekt jest oznaczony do zniszczaenia
		if(m_physicals.at(i)->getDestruction())
		{
				delete m_physicals.at(i);
				m_physicals.at(i) = nullptr;
				m_physicals.erase(m_physicals.begin() + i);
		}
	}

	//aktualizacja pojemnika z eksplozjami
	for (unsigned int i = 0; i < m_explosions.size(); i++)
	{
		m_explosions.at(i)->update(dt);

		if (m_explosions.at(i)->getDestruction())
		{
			delete m_explosions.at(i);
			m_explosions.at(i) = nullptr;
			m_explosions.erase(m_explosions.begin() + i);
		}
	}
}

//Wirtualna metoda rysująca obiekt
void PhysicalManager::draw(sf::RenderWindow & render) const
{
	//draw physicals...
	std::vector<Physical*>::const_iterator it;//iterator tego kontenera
	for (it = m_physicals.begin(); it != m_physicals.end(); it++)
	{
		if ((*it) != nullptr)
			if ((*it)->getUseDisplayable() and !(*it)->getDestruction())
				(*it)->draw(render);
	}

	//draw explosions...
	std::vector<acodemia::animation::Explosion*>::const_iterator iter;//iterator kontenera eksplozji
	for (iter = m_explosions.begin(); iter != m_explosions.end(); iter++)
	{
		if ((*iter) != nullptr)
			(*iter)->draw(render);
	}
}

//Metoda sprawdza, czy nastąpiła jakaś kolizja
bool PhysicalManager::checkCollision(Physical *collider)
{
	std::string typ = typeid(*collider).name();

	//iterujemy po kontenerze ze wskaźnikami na obiekty klasy Physical
	for (unsigned int i = 0; i < m_physicals.size(); i++)
	{
		if (m_physicals.at(i) != collider)//blokujemy kolizję "sam ze sobą"
		{
			//testy kolizji circle-circle (2019-04-10)
			if (m_physicals.at(i)->getGlobalBounds().intersects(collider->getGlobalBounds()))
			{
				if (typ == "class acodemia::physical::Enemy")
				{
					updatePosition(m_physicals.at(i), collider);
					return true;
				}

				if (typ == "class acodemia::physical::Player")
				{
					updatePosition(m_physicals.at(i), collider);
					return true;
				}

				if (typ == "class acodemia::physical::Bullet")
				{
					m_physicals.at(i)->setHealt
					(
						m_physicals.at(i)->getHealt() - static_cast<Bullet*>(collider)->getCaliber()
					);
					collider->setDestruction(true);
					static_cast<Bullet*>(collider)->explode();//eksplozja
					return true;
				}
			}
		}
	}
	return false;
}


//Szablon metody tworzenia obiektów
template<class T>
T* PhysicalManager::Create()
{
	T* obj = new T();
	m_physicals.push_back(obj);
	return obj;
}

//prywatna metoda aktualizuje pozycję obiektu w wyniku kolizji
void PhysicalManager::updatePosition(Physical *object, Physical *collider)
{
	//notatka:
	//docelowo silnik obsługi kolizji uzależnić od wektora prędkości (motion)
	//zasady dynamiki Newtona

	sf::Vector2f new_object_position;
	sf::Vector2f old_object_position;
	old_object_position = object->getPosition();//zapamiętujemy pozycję

	sf::Vector2f new_collider_position;
	sf::Vector2f old_collider_position;
	old_collider_position = collider->getPosition();//zapamiętujemy pozycję

	float factor = 0.1f; // współczynnik separacji

	// x
	if (object->getPosition().x <= collider->getPosition().x)
	{
		new_object_position.x = old_object_position.x - factor;
		new_collider_position.x = old_collider_position.x + factor;
	}
	else
	{
		new_object_position.x = old_object_position.x + factor;
		new_collider_position.x = old_collider_position.x - factor;
	}

	// y
	if (object->getPosition().y <= collider->getPosition().y)
	{
		new_object_position.y = old_object_position.y - factor;
		new_collider_position.y = old_collider_position.y + factor;
	}
	else
	{
		new_object_position.y = old_object_position.y + factor;
		new_collider_position.y = old_collider_position.y - factor;
	}

	object->setPosition(new_object_position);
	collider->setPosition(new_collider_position);
}
