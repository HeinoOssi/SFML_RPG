#include "TheGame.h"



TheGame::TheGame()
{

}

void TheGame::Initialize(sf::RenderWindow* window) {
	window->clear();
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Xipital.ttf");

	
	// renderöi inventory x=1536
	
	manager = new EntityManager();

	map = new Map(manager);
	// add player character, first enemy
	this->manager->Add("PlayerCharacter", new Character(manager, map, 260,260));
	this->manager->Add("Enemy", new Enemy(map, 900, 600));

	// load  map
	map->Load("test.map");


	
}

void TheGame::Update(sf::RenderWindow* window) {
	if (!this->manager->Update(window))
	{
		return;
	}

}
void TheGame::Render(sf::RenderWindow* window) {
	window->clear();

	window->draw(*map);
	this->manager->Render(window);
	


}
void TheGame::Destroy(sf::RenderWindow* window) {
	delete this->font;

	delete this->manager;
}


TheGame::~TheGame()
{
}
