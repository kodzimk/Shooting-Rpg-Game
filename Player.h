#pragma once
#include"stdfah.h"


class Player
{
public:
	//Variabls
	sf::Texture texture;
	sf::Sprite sprite;
	float animationTimer;
	int currentAnimation;
	sf::Clock clock;
	float dt;

	void initVariables();

	Player();
	~Player();

	//Functions
	void update();
	void updateInputs();
	void render(sf::RenderWindow* target);

	const sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
};

