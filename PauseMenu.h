#pragma once
#include"stdfah.h"
#include"State.h"
#include"MainMenuState.h"


class PauseMenu
{
public:
	sf::Text quitText;
	sf::Text titleText;
	sf::RectangleShape shape;
	sf::Font font;


	void initGui();

	PauseMenu();
	~PauseMenu();

	
	void render(sf::RenderWindow* window);
	void updateInputs(sf::Vector2f pos, std::stack<State*>& states, bool isCan, sf::RenderWindow* window);
};

