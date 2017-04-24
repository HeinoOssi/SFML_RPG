#ifndef ENEMY_H
#define ENEMY_H
#include "EntityManager.h"
#include "Map.h"
class Enemy : public Entity
{
public:

	Enemy(Map* map, float x, float y);

	bool Update(sf::RenderWindow* window);
	void Collision(Entity* entity);

	int State;
protected:
	float Speed;

	Map* map;
	int Hitpoints;
};

#endif
