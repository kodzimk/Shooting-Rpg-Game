#pragma once
#include"stdfah.h"
#include"State.h"
#include"GameState.h"
#include"MainMenuState.h"

class GameState;
class MainMenuState;

class Game
{
public:
	//Variables
	sf::RenderWindow* window;
	sf::RenderTarget* target;
	std::stack<State*> states;

	Game();
	~Game();

	//Functions
	void update();

};

