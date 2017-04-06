#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>


Map::Map(EntityManager* entityManager)
{
	this->texture = new sf::Texture();
	this->tileSetTexture = new sf::Image();
	this->entityManager = entityManager;

}

void Map::Load(std::string filename) {
	std::string temp;
	std::ifstream mapfile("Graphics/" + filename);
	
	if (!mapfile) {
		std::cout << "Could not load mapfile " << filename << std::endl;
		return;

	}

	std::getline(mapfile, this->tileSet);
	std::getline(mapfile, this->topArea);
	std::getline(mapfile, this->bottomArea);
	std::getline(mapfile, this->leftArea);
	std::getline(mapfile, this->rightArea);

	std::getline(mapfile, temp);
	this->tileWidth = std::stoi(temp, nullptr);
	std::getline(mapfile, temp);
	this->tileHeight = std::stoi(temp, nullptr);

	std::getline(mapfile, temp);
	this->width = std::stoi(temp, nullptr);
	std::getline(mapfile, temp);
	this->height = std::stoi(temp, nullptr);

	this->data = new int[this->width * this->height];
	for (int y = 0; y < this->height; y += 1)
	{
		for (int x = 0; x < this->width; x += 1)
		{
			char temp;
			mapfile >> this->data[x + y * this->width] >> temp;
		}
	}

	mapfile.close();

	this->texture->create(this->tileWidth * this->tileHeight,
		this->height * this->tileHeight);

	this->tileSetTexture->loadFromFile("Graphics/" + this->tileSet);

	sf::Image tile1, tile2, tile3, tile4, tile5;
	
	tile1.create(64, 64);
	tile2.create(64, 64);
	tile3.create(64, 64);
	tile4.create(64, 64);
	tile5.create(64, 64);

	tile1.copy(*this->tileSetTexture, 0, 0,
		sf::IntRect(0, 0, this->tileWidth, this->tileHeight), true);
	tile2.copy(*this->tileSetTexture, 0, 0, 
		sf::IntRect(this->tileWidth, 0, this->tileWidth, this->tileHeight), true);
	tile3.copy(*this->tileSetTexture, 0, 0, 
		sf::IntRect(0, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile4.copy(*this->tileSetTexture, 0, 0, 
		sf::IntRect(this->tileWidth, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile5.copy(*this->tileSetTexture, 0, 0, 
		sf::IntRect(0, 2 * this->tileHeight, this->tileWidth, this->tileHeight), true);

	for (int y = 0; y < this->height; y += 1)
	{
		for (int x = 0; x < this->width; x += 1)
		{
			switch (this->data[x + y * this->width])
			{
			case 0:
				break;
			case 1:
				this->texture->update(tile1, x * 64, y * 64);
				break;
			case 2:
				this->texture->update(tile2, x * 64, y * 64);
				break;
			case 3:
				this->texture->update(tile3, x * 64, y * 64);
				break;
			case 4:
				this->texture->update(tile4, x * 64, y * 64);
				break;
			case 5:
				this->texture->update(tile5, x * 64, y * 64);
				break;
			case 6:
				//this->texture->update(tile1, x * 64, y * 64);
				//this->entityManager->Add("npc1", new Npc1(speech, this, x * 64, y * 64));
				//this->data[x + y * this->width] = 1;
				break;
			case 7:
				//this->texture->update(tile1, x * 64, y * 64);
				//this->entityManager->Add("npc2", new Npc2(speech, this, x * 64, y * 64));
				//this->data[x + y * this->width] = 1;
				break;
			case 8:
				//this->texture->update(tile1, x * 64, y * 64);
				//this->entityManager->Add("mob1", new Mob1(this, x * 64, y * 64));
				//this->data[x + y * this->width] = 1;
				break;
			case 9:
				//this->texture->update(tile1, x * 64, y * 64);
				//this->entityManager->Add("mob2", new Mob2(this, x * 64, y * 64));
				//this->data[x + y * this->width] = 1;
				break;
			}
		}
	}

	this->setTexture(*this->texture);


}

int Map::CheckCollision(Entity* entity, Direction direction) {
	int x = (int)(entity->getPosition().x + entity->getGlobalBounds().width / 2) / this->tileWidth;
	int y = (int)(entity->getPosition().y + entity->getGlobalBounds().height / 2) / this->tileHeight;
	switch (direction)
	{
	case LEFT:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width) / this->tileWidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height / 2) / this->tileHeight;
		break;
	case RIGHT:
		x = (int)(entity->getPosition().x) / this->tileWidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height / 2) / this->tileHeight;
		break;
	case UP:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width / 2) / this->tileWidth;
		y = (int)(entity->getPosition().y) / this->tileHeight;
		break;
	case DOWN:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width / 2) / this->tileWidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height) / this->tileHeight;
		break;
	case TOP_LEFT:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width) / this->tileWidth;
		y = (int)(entity->getPosition().y) / this->tileHeight;
		break;
	case TOP_RIGHT:
		x = (int)(entity->getPosition().x) / this->tileWidth;
		y = (int)(entity->getPosition().y) / this->tileHeight;
		break;
	case BOTTOM_LEFT:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width) / this->tileWidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height) / this->tileHeight;
		break;
	case BOTTOM_RIGHT:
		x = (int)(entity->getPosition().x) / this->tileWidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height) / this->tileHeight;
		break;
	}
	return this->data[x + y * this->width];

}

Map::~Map()
{
	delete this->texture;
	delete this->tileSetTexture;
	delete this->data;
}
