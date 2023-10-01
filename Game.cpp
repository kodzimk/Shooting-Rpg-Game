#include "Game.h"

Game::Game()
{
	this->states.push(new MainMenuState());
}

Game::~Game()
{

}

void Game::update()
{
	while (this->states.top())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			this->states.top()->changeState(&this->states);

		this->states.top()->update();
	}
}

