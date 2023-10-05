#pragma once
#include"stdfah.h"

class Filler
{
public:
	sf::RectangleShape backShape;
	sf::RectangleShape innerShape;
	sf::Font font;

	sf::Text innerText;
	sf::Text backText;

	void initGui();

	Filler();
	~Filler();

	void render(sf::RenderWindow* window);
};

