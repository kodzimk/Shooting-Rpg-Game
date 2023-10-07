#pragma once
#include"State.h"
#include"stdfah.h"
#include"Player.h"
#include"TileMap.h"
#include"PauseMenu.h"
#include"Enemy.h"

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
	std::vector<Enemy*> enemies;
	float time;
	sf::Clock clock;
	float timer;
	sf::Font font;
	sf::Text timerText;
	sf::Clock clock1;
	float t;


	GameState();
	~GameState();


	//Functions
	const bool getPause();
	void update(std::stack<State*>& states);
	void updateInputs(std::stack<State*>& states);
	void render();
};

