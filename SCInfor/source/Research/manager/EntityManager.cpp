////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek 2021
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

#include "EntityManager.h"
#include "../logic/Actor.hpp"
#include "../logic/Enemy.hpp"
#include "../logic/Player.hpp"
#include "../logic/Bullet.hpp"

// Default constructor
EntityManager::EntityManager() : m_entity()
{
}

// Virtual destructor
EntityManager::~EntityManager()
{
	std::vector<Actor*>::iterator it;
	for (it = m_entity.begin(); it != m_entity.end(); it++)
	{
		if((*it))
			delete (*it);
	}
	m_entity.clear();
}

// The method returns a constant container reference
const std::vector<Actor *>& EntityManager::getEntities()
{
	return m_entity;
}

// The method registers pointers to Entity objects in the container
void EntityManager::registerEntity(Actor* entity)
{
	if(entity)
		m_entity.push_back(entity);
}

// Create a Bullet object and return a pointer to that object
Bullet *EntityManager::CreateBullet()
{
	return Create<Bullet>();
}

// Create a Actor object and return a pointer to that object
Actor *EntityManager::CreateActor()
{
	return Create<Actor>();
}

// Create a Player object and return a pointer to that object
Player *EntityManager::CreatePlayer()
{
	return Create<Player>();
}

// Create a Enemy object and return a pointer to that object
Enemy *EntityManager::CreateEnemy()
{
	return Create<Enemy>();
}

// Container update with pointers to Entity objects
void EntityManager::update(float dt)
{
	for (unsigned int i = 0; i < m_entity.size(); i++)
	{
		m_entity.at(i)->update(dt);

		//jeśli obiekt jest oznaczony do zniszczaenia
		if (m_entity.at(i)->getDestruction())
		{
			delete m_entity.at(i);
			m_entity.at(i) = nullptr;
			m_entity.erase(m_entity.begin() + i);
		}
	}

}

// Virtual object rendering method
void EntityManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//draw entities...
	std::vector<Actor*>::const_iterator it;//iterator /const/ this container
	for (it = m_entity.begin(); it != m_entity.end(); it++)
	{
		if ((*it) != nullptr)
			if (!(*it)->getDestruction())
				(*it)->draw(target, states);
	}
}

// implementation
// object creation method template
// and registering the pointer to them in the container 

template<class T>
T* EntityManager::Create()
{
	T* obj = new T();
	m_entity.push_back(obj);
	return obj;
}
