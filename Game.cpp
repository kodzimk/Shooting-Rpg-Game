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
		this->states.top()->update();
		this->states.top()->render();
	}
}

