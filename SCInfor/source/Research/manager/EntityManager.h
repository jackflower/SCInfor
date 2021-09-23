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


#ifndef HPP_ENTITY_MANAGER_ACODEMIA
#define HPP_ENTITY_MANAGER_ACODEMIA

#include "SFML/Graphics.hpp"
#include "../utilities/Singleton.h"
#include <vector>

// forwad declarations
namespace entity
{
	class Entity;
}

namespace logic
{
	class Physical;
	class Actor;
	class Player;
	class Enemy;
	class Bullet;
}

using entity::Entity;
using logic::Actor;
using logic::Player;
using logic::Enemy;
using logic::Bullet;

#define gEntityManager EntityManager::getSingleton()

///
/// A class represents a factory that produces game objects,
/// object management, inherits from template,
/// which is a singleton pattern is a Singleton
///
class EntityManager : public Singleton<EntityManager>
{
public:

	///
	/// Default constructor
	///
	EntityManager();

	///
	/// Virtual destructor
	///
	virtual ~EntityManager();

	///
	/// The method returns a constant container reference
	///
	const std::vector<Actor* >& getEntities();

	///
	/// The method registers pointers to Entity objects in the container
	///
	/// @param *entity - a pointer to an Entity object 
	///
	void registerEntity(Actor* entity);

	///
	/// Create a Bullet object and return a pointer to that object
	///
	Bullet *CreateBullet();

	///
	/// Create a Bullet object and return a pointer to that object
	///
	Actor *CreateActor();

	///
	/// Create a Bullet object and return a pointer to that object
	///
	Player *CreatePlayer();

	///
	/// Create a Bullet object and return a pointer to that object
	///
	Enemy *CreateEnemy();

	///
	/// Container update with pointers to Entity objects
	///
	///@param dt - time
	///
	void update(float dt);

	///
	/// Virtual object rendering method
	///
	/// @param target - reference to the graphic context
	///
	/// @param states - render states
	///
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	// the container holds pointers to Actor objects
	std::vector<Actor* > m_entity;

	// the template of the method for creating objects
	// and registering a pointer to them in the container
	template<class T> T* Create();
};
#endif//HPP_ENTITY_MANAGER_ACODEMIA
