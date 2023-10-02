#pragma once
#include"State.h"
#include"stdfah.h"

class GameState:public State
{
public:
	//Variables

	GameState();
	~GameState();


	//Functions
	void update(std::stack<State*>& states);
	void render();
};

