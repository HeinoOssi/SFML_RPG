#ifndef MAINMENU_H
#define MAINMENU_H
#include "GameState.h"


class MainMenu : public TinyState
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	sf::Font* font;
	sf::Text* play;
	sf::Text* quit;
	sf::Texture* texture;
	sf::Sprite* sprite;

	int selected;
};

#endif
