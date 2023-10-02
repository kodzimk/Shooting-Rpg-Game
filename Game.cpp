#include "Game.h"

Game::Game()
{
	this->states.push(new MainMenuState());
}

Game::~Game()
{
	while (!this->states.empty())
	{
		delete this->states.top();
	}
}

void Game::update()
{
	while (this->states.size()!=0)
	{
		this->states.top()->update(this->states);
		if(this->states.size()!=0)
		this->states.top()->render();
	}
}

