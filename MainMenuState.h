#pragma once
#include"stdfah.h"
#include"State.h"
#include"GameState.h"

class MainMenuState:public State
{
public:
	//Variables
	sf::RectangleShape backGround;

	MainMenuState();
	~MainMenuState();

	//Functions
	void update();
	void render();
	void changeState(std::stack<State*>* states);
};

