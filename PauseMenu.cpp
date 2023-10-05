#include "PauseMenu.h"

void PauseMenu::initGui()
{
	this->font.loadFromFile("res/Fonts/Dosis-Light.ttf");

	this->shape.setSize(sf::Vector2f(200, 640));
	this->shape.setPosition(300, 0); 
	this->shape.setFillColor(sf::Color(10, 10, 10, 220));

	this->quitText.setString("Quit");
	this->quitText.setCharacterSize(50);
	this->quitText.setPosition(350, 500);
	this->quitText.setFont(this->font);

	this->titleText.setString("Pause");
	this->titleText.setCharacterSize(50);
	this->titleText.setPosition(350, 100);
	this->titleText.setFont(this->font);
}

PauseMenu::PauseMenu()
{
	this->initGui();
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
	window->draw(this->quitText);
	window->draw(this->titleText);
}

void PauseMenu::updateInputs(sf::Vector2f pos,std::stack<State*>& states,bool isCan, sf::RenderWindow* window)
{
	if (quitText.getGlobalBounds().contains(pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)&&isCan)
	{
		
		while (!states.empty()) {
			states.pop();
		}
		states.emplace();
		window->close();
		states.push(new MainMenuState());
	}
}
