#include "TheGame.h"



TheGame::TheGame()
{

}

void TheGame::Initialize(sf::RenderWindow* window) {
	window->clear();
	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Xipital.ttf");
	//this->score = new Score(*font, 64U);
	//this->lives = new Lives(*font, 64U);
	//this->lives->setPosition(window->getSize().x - this->lives->getGlobalBounds().width, 0);
	//this->speech = new Speech(*font, 32U, window);

	//this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 64U);
	//this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
	//this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	
	// renderöi inventory x=1536
	
	manager = new EntityManager();

	map = new Map(manager);

	this->manager->Add("PlayerCharacter", 
		new Character(manager, map, 160,160));
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
