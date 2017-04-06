#ifndef THEGAME_H
#define THEGAME_H
#include <SFML\Graphics.hpp>
#include "Character.h"
#include <iostream>
#include "GameState.h"
#include "EntityManager.h"
#include "Map.h"

class TheGame : public TinyState
{
public:
	TheGame();
	~TheGame();

	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);



private:

	sf::RenderWindow* window;
	sf::Texture* texture;
	sf::Sprite* sprite;

	sf::Text text;
	sf::Font* font;

	EntityManager* manager;
	Map* map;



};

#endif