#pragma once
#include"stdfah.h"

class State
{
public:
	sf::RenderWindow* window;

	State();
	~State();

	virtual void update(std::stack<State*>& states) = 0;
	virtual void render() = 0;
};

