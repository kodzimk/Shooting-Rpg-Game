#pragma once
#include"State.h"
#include"stdfah.h"
#include"Player.h"
#include"TileMap.h"
#include"PauseMenu.h"

class PauseMenu;

class GameState:public State
{
public:
	//Variables
	Player* player;
	sf::Vector2f mousePosView;
	bool isPause;
	PauseMenu* pauseMenu;
	TileMap* map;


	GameState();
	~GameState();


	//Functions
	const bool getPause();
	void update(std::stack<State*>& states);
	void updateInputs(std::stack<State*>& states);
	void render();
};

