#include "Character.h"
#include "TheGame.h"
#include "MainMenu.h"



Character::Character(EntityManager* entityManager, 
	Map* map, float x, float y)
{
	this->Load("character.png");
	this->setPosition(x, y);
	this->speed = 0.07f;
	this->map = map;
	this->groupid = 1;
	this->entityManager = entityManager;

}

bool Character::Update(sf::RenderWindow* window) {
	this->velocity.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) * this->speed;
	this->velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) * this->speed;

	if (this->velocity.x > 0)
	{
		if (this->velocity.y > 0)
		{
			this->direction = 45.0f;
		}
		else if (this->velocity.y < 0)
		{
			this->direction = 315.0f;
		}
		else
		{
			this->direction = 0.0f;
		}
	}

	else if (this->velocity.x < 0)
	{
		if (this->velocity.y > 0)
		{
			this->direction = 135.0f;
		}
		else if (this->velocity.y < 0)
		{
			this->direction = 225.0f;
		}
		else
		{
			this->direction = 180.0f;
		}
	}
	else
	{
		if (this->velocity.y > 0)
		{
			this->direction = 90.0f;
		}
		else if (this->velocity.y < 0)
		{
			this->direction = 270.0f;
		}
	}


	// hit walls
	if (this->getPosition().y <= 0)
	{

	}
	if (this->getPosition().y + this->getGlobalBounds().height >= window->getSize().y)
	{

	}
	if (this->getPosition().x <= 0)
	{

	}
	if (this->getPosition().x + this->getGlobalBounds().width >= window->getSize().x)
	{

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->spaceKey)
	{
		std::cout << "Slash with sword!" << std::endl;

		//this->entityManager->Add("bullet", new Bullet(this->map, this->getPosition().x, this->getPosition().y, direction, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X) && !this->xKey)
	{
		std::cout << "Operate!" << std::endl;

		//this->entityManager->Add("pBullet", new PlayerBullet(this->map, this->getPosition().x, this->getPosition().y, direction, 800));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C) && !this->cKey) {
		std::cout << "Cast a spell!" << std::endl;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I) && !this->iKey) {
		std::cout << "Render inventory & stats!" << std::endl;

	}


	switch (this->map->CheckCollision(this, NONE))
	{
	case 0:
		break;
	case 1:
		this->speed = 0.09f;
		this->setColor(sf::Color::White);
		break;
	case 2:
		this->speed = 0.05f;
		this->setColor(sf::Color::Blue);
		break;
	}

	if (this->map->CheckCollision(this, LEFT) > 2)
	{
		this->move(-abs(this->speed), 0);
	}
	if (this->map->CheckCollision(this, RIGHT) > 2)
	{
		this->move(abs(this->speed), 0);
	}
	if (this->map->CheckCollision(this, UP) > 2)
	{
		this->move(0, abs(this->speed));
	}
	if (this->map->CheckCollision(this, DOWN) > 2)
	{
		this->move(0, -abs(this->speed));
	}

	this->spaceKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
	this->xKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X);
	this->cKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C);
	this->iKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I);


	Entity::Update(window);
	return true;

}
Character::~Character()
{
}

void Character::Collision(Entity* entity) {
	switch (entity->GroupID())
	{
	case 3:
		this->move(-this->velocity.x, -this->velocity.y);
		break;
	case 5:
		//enemy* temp = reinterpret_cast<enemy*>(entity);
		//temp->state = 5;

		//sf::Color seeThrough = temp->getColor();
		//seeThrough.a = 128;
		//temp->setColor(seeThrough);
		break;
	}
}



//void Character::Create(int lifep, sf::Texture texture_) {
//	LifePoints = lifep;
//	texture = texture_;
//	sprite.setTexture(texture);
//	Position.x = 1;
//	Position.y = 1;
//	// Pelaaja aloittaa koordinaatista x1 y1
//	sprite.setPosition(Position);
//
//
//
//
//}