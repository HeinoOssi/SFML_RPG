#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "Entity.h"
#include <unordered_map>
#include <vector>


class EntityManager
{
public:
	void Add(std::string name, Entity* entity);
	Entity* GetEntity(std::string name);
	
	bool Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);


	EntityManager();
	~EntityManager();
private:

	std::unordered_map<std::string, Entity*> entities;

};

#endif
