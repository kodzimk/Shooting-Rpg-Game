#pragma once
#include"stdfah.h"
#include"State.h"
#include"GameState.h"

class MainMenuState:public State
{
public:
	//Variables
	sf::Sprite backGround;
	sf::Texture backTexture;
	sf::RectangleShape shape;
	sf::Vector2f mousePosView;

	sf::Font font;

	sf::Text playText;
	sf::Text quitText;


	void initTexts();

	MainMenuState();
	~MainMenuState();

	//Functions
	void update(std::stack<State*>& states);
	void render();
	void changeState(std::stack<State*>& states, bool isQuit);
	void updateInputs(std::stack<State*>& states);
};

