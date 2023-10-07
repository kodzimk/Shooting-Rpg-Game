#include "GameState.h"

GameState::GameState()
{

	this->font.loadFromFile("res/Fonts/Dosis-Light.ttf");

	this->timerText.setFont(this->font);
	this->timerText.setPosition(400, 10);
	this->timerText.setCharacterSize(30);

	this->window = new sf::RenderWindow(sf::VideoMode(960, 640), "game");
	this->player = new Player();
	this->pauseMenu = new PauseMenu();
	this->map = new TileMap();
	this->enemies.push_back(new Enemy());
	this->time = 0.f;
	this->timer = 100.f;
}

GameState::~GameState()
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		delete this->enemies[i];
	}

	delete this->player;
	delete this->pauseMenu;
	delete this->map;
}

void GameState::update(std::stack<State*>& states)
{
	this->mousePosView = sf::Vector2f(sf::Mouse::getPosition(*window));

	this->updateInputs(states);

	if (!isPause)
	{
		this->timerText.setString(std::to_string(int(abs(this->timer))));
		this->player->update(this->mousePosView, this->getPause(), this->map->isCollide(this->player));
		this->time = this->clock.getElapsedTime().asSeconds();
		this->t = this->clock1.getElapsedTime().asSeconds();

		this->timer -= t;

		if (this->time > 10)
		{
			clock.restart();
			this->time = 0;
			this->enemies.push_back(new Enemy());
		}
		this->clock1.restart();

		if (this->player->hp <= 0||this->timer <=0)
		{
			while (states.size() > 0)
			{
				states.pop();
			}
			window->close();
		}

		for (size_t i = 0; i < this->enemies.size(); i++)
		{
			this->enemies[i]->update(this->player->dt, this->isPause, this->map->isCollide(this->enemies[i]), this->player->getPosition(), *this->player, &this->player->sword->bullets);
		}
	}
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

	this->player->render(this->window);

	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i]->render(window);
	}
	window->draw(this->timerText);

	window->display();
}


