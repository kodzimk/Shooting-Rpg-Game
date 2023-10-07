#include "GameState.h"

GameState::GameState()
{
	this->window = new sf::RenderWindow(sf::VideoMode(960, 640), "game");
	this->player = new Player();
	this->pauseMenu = new PauseMenu();
	this->map = new TileMap();
	this->enemy = new Enemy();
}

GameState::~GameState()
{
	delete this->enemy;
	delete this->player;
	delete this->pauseMenu;
	delete this->map;
}

void GameState::update(std::stack<State*>& states)
{
	this->mousePosView = sf::Vector2f(sf::Mouse::getPosition(*window));

	this->updateInputs(states);

	this->player->update(this->mousePosView,this->getPause(),this->map->isCollide(this->player));
	this->enemy->update(this->player->dt, this->isPause, this->map->isCollide(this->enemy), this->player->getPosition(),*this->player,&this->player->sword->bullets);
}

const bool GameState::getPause()
{
	return this->isPause;
}

void GameState::updateInputs(std::stack<State*>& states)
{

	if(this->isPause)
	this->pauseMenu->updateInputs(this->mousePosView,states,this->player->getKeytime(),this->window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->player->getKeytime())
	{
		
		if (this->isPause)
			this->isPause = false;
		else
			this->isPause = true;
	}
}

void GameState::render()
{
	window->clear();
	if (this->isPause)
	{
		this->pauseMenu->render(window);
	}


	this->map->render(window);
	this->enemy->render(this->window);
	this->player->render(this->window);
	window->display();
}


