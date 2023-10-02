#include "MainMenuState.h"

void MainMenuState::initTexts()
{
	this->font.loadFromFile("res/Fonts/Dosis-Light.ttf");

	this->playText.setFont(this->font);
	this->playText.setFillColor(sf::Color::White);
	this->playText.setPosition(300, 400);
	this->playText.setCharacterSize(60);
	this->playText.setString("Play");

	this->quitText.setFont(this->font);
	this->quitText.setFillColor(sf::Color::White);
	this->quitText.setPosition(300, 600);
	this->quitText.setCharacterSize(60);
	this->quitText.setString("Quit");
}

MainMenuState::MainMenuState()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "shooter game");
	this->initTexts();
	
	this->shape.setFillColor(sf::Color(10, 10, 10, 220));

	this->shape.setPosition(150, 0);
	this->shape.setSize(sf::Vector2f(400, 1080));

	this->backTexture.loadFromFile("res/Backgrounds/bg2.png");
	this->backGround.setTexture(this->backTexture);	
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::update(std::stack<State*>& states)
{
	this->updateInputs(states);
}

void MainMenuState::render()
{
	this->window->clear();
	this->window->draw(this->backGround);
	this->window->draw(this->shape);
	this->window->draw(this->playText);
	this->window->draw(this->quitText);
	this->window->display();
}

void MainMenuState::changeState(std::stack<State*>& states,bool isQuit)
{
	if (isQuit)
	{
		while (states.size() != 0)
		{
			states.pop();
		}
		window->close();
	}
	else {
		while (states.size() != 0)
		{
			states.pop();
		}
		window->close();
		states.push(new GameState());
	}
}

void MainMenuState::updateInputs(std::stack<State*>& states)
{
	this->mousePosView = sf::Vector2f(sf::Mouse::getPosition(*window));

	if (this->playText.getGlobalBounds().contains(this->mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		changeState(states,false);
	}
	else if (this->quitText.getGlobalBounds().contains(this->mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		changeState(states, true);
	}
}
