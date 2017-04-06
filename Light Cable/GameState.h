#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML\Graphics.hpp>

class TinyState {
public:
	virtual void Initialize(sf::RenderWindow* window) {}
	virtual void Update(sf::RenderWindow* window){}
	virtual void Render(sf::RenderWindow* window) {}
	virtual void Destroy(sf::RenderWindow* window) {}
};

class GameState 
{
public:

	GameState() {
		this->state = NULL;
	}
	~GameState() {
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}

	void SetWindow(sf::RenderWindow* window) {
		// Asettaa ikkunan
		this->window = window;

	}

	void SetState(TinyState* state) {
		if (this->state != NULL) {
			this->state->Destroy(this->window);

		}
		this->state=state;

		if (this->state != NULL) {
			this->state->Initialize(this->window);

		}
	
	}

	void Update() {
		if (this->state != NULL) {
			this->state->Update(this->window);

		}
	}

	void Render()
	{
		if (this->state != NULL)
		{
			this->state->Render(this->window);
		}
	}

private:
	sf::RenderWindow* window;
	TinyState* state;

};

extern GameState coreState;

#endif