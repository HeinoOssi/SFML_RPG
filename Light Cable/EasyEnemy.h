#ifndef EASYENEMY_H
#define EASYENEMY_H
#include <SFML\Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "Map.h"
class EasyEnemy : public Entity

{
public:

	EasyEnemy(EntityManager* entityManager, Map* map, float x, float y);
	// TODO: if a player character is close by, let enemy use somekind of 
	// "magical attack"
	bool Update(sf::RenderWindow* window);				
	void Collision(Entity* entity);

	~EasyEnemy();

private:
	Map* map;
	float speed;
	EntityManager* entityManager;
	float Direction;


};

#endif
