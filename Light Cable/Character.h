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
	//void Create(int lifep, sf::Texture texture_);

	//int getLifepoints() { return LifePoints; }
	//int getAgile() { return Agile; }
	//int getAttack() { return Attack; }
	//sf::Vector2f getPosition() { return Position; }
	//
	//sf::Sprite getSprite() { return sprite; }
	//sf::Texture getTexture() { return texture; }
	//
private:
	Map* map;
	float speed;
	EntityManager* entityManager;
	bool spaceKey, xKey, cKey, iKey;
	float direction;

	//int LifePoints;
	//int Agile;
	//int Attack;

	//sf::Vector2f Position;
	//bool isAlive;
	//// tavarat laitetaan inventoryyn
	//// TODO: item luokka
	//// Itemit id:n mukaan (int)
	//std::vector<int> Inventory;
	//// Kaikille charactereille on tekstuuri ja sprite
	//sf::Texture texture;
	//sf::Sprite sprite;
	//



};

#endif
