#pragma once
#include"stdfah.h"
#include"Weapon.h"


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

	Weapon* sword;

	void initVariables();

	Player();
	~Player();

	//Functions
	void update(const sf::Vector2f mouse_pos_view);
	void updateInputs();
	void render(sf::RenderWindow* target);

	const sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
};

