#include "MainMenu.h"
#include <iostream>
#include "TheGame.h"

void MainMenu::Initialize(sf::RenderWindow* window) {
	this->selected = 0;
	this->font = new sf::Font();
	this->texture = new sf::Texture();
	this->sprite = new sf::Sprite();

	if (!font->loadFromFile("Resources/Xipital.ttf")) {
		// Ei ladannu fonttia, tee jotain
		// TODO: kehitetään joku perusfontti että kuitenkin toimisi
		// ja ladatanaan se tässä silloin.

	}
	if (!texture->loadFromFile("Resources/mainmenu.jpg")) {
		// Ei ladannu tekstuuria, tee jotain
		// TODO: kehitetään joku perusfontti että kuitenkin toimisi
		// ja ladatanaan se tässä silloin.


	}

	this->sprite->setTexture(*texture);

	this->play = new sf::Text("START A NEW ADVENTURE", *this->font, 22);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->quit = new sf::Text("QUIT", *this->font, 22);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 100 + this->play->getGlobalBounds().height);

	//this->play->setColor(sf::Color::White);
	//this->quit->setColor(sf::Color::White);


}


void MainMenu::Update(sf::RenderWindow* window) {
	sf::Vector2i mousepos = sf::Mouse::getPosition(*window);
	std::cout << "x: " << mousepos.x << ", y: " << mousepos.y << std::endl;

	if (mousepos.x > 248 && mousepos.x < 552 && mousepos.y >295
		&& mousepos.y < 314) {
		// hiiri on start-napin päällä
		play->setFillColor(sf::Color::Red);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			coreState.SetState(new TheGame());

		}

	} else if (mousepos.x > 369 && mousepos.x < 427 
		&& mousepos.y > 410 && mousepos.y < 425){
		// hiiri on quitin päällä
		quit->setFillColor(sf::Color::Red);
		// quit
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			window->close();
		}


	}

	else {
		play->setFillColor(sf::Color::White);
		quit->setFillColor(sf::Color::White);

	}

}



void MainMenu::Render(sf::RenderWindow* window) {


	// temp



	window->draw(*this->sprite);
	window->draw(*this->play);
	window->draw(*this->quit);


}

void MainMenu::Destroy(sf::RenderWindow* window) {
	// poistetaan kaikki
	delete this->font;
	delete this->play;
	delete this->quit;

}