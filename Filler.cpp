#include "Filler.h"

void Filler::initGui()
{
	this->font.loadFromFile("res/Fonts/Dosis-Light.ttf");

	this->backShape.setSize(sf::Vector2f(150, 40));
	this->backShape.setFillColor(sf::Color::Black);

	this->innerShape.setSize(sf::Vector2f(150, 40));
	this->innerShape.setFillColor(sf::Color::Red);

	this->innerText.setString("100");
	this->innerText.setFont(this->font);
	this->innerText.setPosition(40, 5);
	this->innerText.setCharacterSize(30);

	this->backText.setString("P:50");
	this->backText.setFont(this->font);
	this->backText.setPosition(170, 5);
	this->backText.setCharacterSize(30);

}

Filler::Filler()
{
	this->initGui();
}

Filler::~Filler()
{
}

void Filler::render(sf::RenderWindow* window)
{
	window->draw(backShape);
	window->draw(this->innerShape);
	window->draw(this->innerText);
	window->draw(this->backText);
}
