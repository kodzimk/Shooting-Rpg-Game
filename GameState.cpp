#include "GameState.h"

GameState::GameState()
{
	this->window = new sf::RenderWindow(sf::VideoMode(960, 640), "game");
}

GameState::~GameState()
{
}

void GameState::update(std::stack<State*>& states)
{

}

void GameState::render()
{
}


