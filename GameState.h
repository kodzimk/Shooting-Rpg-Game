#pragma once
#include"State.h"
#include"stdfah.h"
#include"Player.h"

class GameState:public State
{
public:
	//Variables
	Player* player;
	sf::Vector2f mousePosView;

	GameState();
	~GameState();


	//Functions
	void update(std::stack<State*>& states);
	void render();
};

