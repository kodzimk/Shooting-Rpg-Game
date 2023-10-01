#pragma once
#include"stdfah.h"

class State
{
public:
	sf::RenderWindow* window;

	State();
	~State();

	virtual void update() = 0;
	virtual void render() = 0;
	virtual void changeState(std::stack<State*>* states) = 0;
};
