#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
	this->window = new sf::RenderWindow(sf::VideoMode(960, 640), "shooter game");
	this->backGround.setSize(sf::Vector2f(10, 10));
	this->backGround.setFillColor(sf::Color::Red);
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::update()
{
		this->render();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		    this->window->close();

}

void MainMenuState::render()
{
	this->window->clear();
	this->window->draw(this->backGround);
	this->window->display();
}

void MainMenuState::changeState(std::stack<State*>* states)
{
	states->push(new GameState());
}
