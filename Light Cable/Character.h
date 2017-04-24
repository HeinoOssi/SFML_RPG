#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Map.h"

class Character : public Entity
{
public:
	Character(EntityManager* entityManager, Map* map, float x, float y);
	bool Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
	~Character();

private:
	Map* map;
	float speed;
	EntityManager* entityManager;
	bool spaceKey, xKey, cKey, iKey;
	float direction;
	int Hitpoints;





};

#endif
