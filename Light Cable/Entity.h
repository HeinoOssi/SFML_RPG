#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <iostream>
#include <SFML\Graphics.hpp>
class Entity : public sf::Sprite
{
public:
	Entity() {
		this->groupid = 0;
		this->texture = new sf::Texture();
		this->active = 1;
		this->sprite = new sf::Sprite();

	}
	~Entity() {
		delete this->texture;
	}

	void Load(std::string filename) {
		if (!this->texture->loadFromFile("Graphics/" + filename)) {
			// tekstuurin lataamisessa ongelma

			std::cout << "Could not load file " << filename << std::endl;

		}

		this->setTexture(*this->texture);
		this->sprite->setTexture(*this->texture);
		
	}

	virtual bool Update(sf::RenderWindow* window) {
		this->move(this->velocity);
		return true;
	}

	virtual void Collision(Entity* entity){}

	sf::Vector2f velocity;

	int GroupID() {
		return this->groupid;
	}
	int Active() {
		return this->active;

	}
	void Destroy() {
		this->active = 0;

	}
	bool CheckCollision(Entity* entity) {
		//return this->getGlobalBounds().intersects(entity->getGlobalBounds());
		
		// TODO
		return true;

	}
protected:
	int active;
	int groupid;
private:
	sf::Texture* texture;
	sf::Sprite* sprite;


};

#endif