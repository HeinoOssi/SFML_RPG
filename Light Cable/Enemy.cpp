#include "Enemy.h"


Enemy::Enemy(Map* map, float x, float y) {
	
	// aseta sijainnit etc
	this->setPosition(x, y);
	this->Load("enemy.png");
	this->setColor(sf::Color::Red);
	this->map = map;
	this->groupid = 5;
	this->Speed = 0.10f;
	this->Hitpoints = 11;
	this->State = 0;
}
bool Enemy::Update(sf::RenderWindow* window) {
	if (this->Hitpoints <= 0) {
		// this enemy has no hitpoints left, destroy it
		// TODO: let the player get some points for killing enemy
		this->Destroy();

	}
	
	if (State == 0) {
		sf::Color enemyThrough = this->getColor();
		enemyThrough.a = 255;
		this->setColor(enemyThrough);

	}
	else if (State > 0) {
		State -= 1;

	}
	Entity::Update(window);

	switch (this->map->CheckCollision(this, NONE))
	{
	case 0:
		break;
	case 1:
		this->Speed = 0.10f;
		this->setColor(sf::Color::White);
		break;
	case 2:
		this->Speed = 0.10f;
		this->setColor(sf::Color::Blue);
		break;
	}

	if (this->map->CheckCollision(this, LEFT) > 2)
	{
		this->move(-abs(this->Speed), 0);
	}
	if (this->map->CheckCollision(this, RIGHT) > 2)
	{
		this->move(abs(this->Speed), 0);
	}
	if (this->map->CheckCollision(this, UP) > 2)
	{
		this->move(0, abs(this->Speed));
	}
	if (this->map->CheckCollision(this, DOWN) > 2)
	{
		this->move(0, -abs(this->Speed));
	}

	return true;

}
void Enemy::Collision(Entity* entity) {
	switch (entity->GroupID())
	{
	case 4:
		entity->Destroy();
		this->Hitpoints -= 1;
		break;
	}
}
