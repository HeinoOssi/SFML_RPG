#include <SFML\Graphics.hpp>
#include <iostream>
#include "TheGame.h"
#include "GameState.h"
#include "MainMenu.h"

GameState coreState;

/*

Samat filut .vcproj kansioon ja debug kansioon näemmä

*/

int main() {
	
	// Ikkuna luodaan
	// TODO: settings ikkunan koon säätöön?
	sf::RenderWindow window(sf::VideoMode(1680, 900), "LIGHT CABLE - PROJEKTIOPINNOT 1");
	//sf::Style::Fullscreen);
	coreState.SetWindow(&window);
	coreState.SetState(new MainMenu());


	
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			// ikkunan sulkeminen -tapahtuma
			if (event.type == sf::Event::Closed) window.close();

		}
		coreState.Update();
		coreState.Render();


		window.display();

	}


}