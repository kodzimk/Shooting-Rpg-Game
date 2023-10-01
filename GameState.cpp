#include "GameState.h"

GameState::GameState()
{
	this->window = new sf::RenderWindow(sf::VideoMode(960, 640), "game");
}

GameState::~GameState()
{
}

void GameState::update()
{
	while(this->window->isOpen())
	{
		this->render();
	}
}

void GameState::render()
{
}

void GameState::changeState(std::stack<State*>* states)
{

}

