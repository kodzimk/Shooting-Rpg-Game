#pragma once
#include"stdfah.h"
#include"Weapon.h"
#include"Filler.h"


class Player
{
public:
	//Variabls
	sf::Texture texture;
	sf::Sprite sprite;
	float animationTimer;
	int currentAnimation;
	sf::Clock clock;
	float keyTime;
	float keyMaxTime;
	float dt;
	Filler filler;
	int hp;
	int patronCount;

	Weapon* sword;

	void initVariables();

	Player();
	~Player();

	//Functions
	void update(const sf::Vector2f mouse_pos_view, const bool isPause,bool isCan);
	void updateInputs(const bool isPause,bool isCan);
	void render(sf::RenderWindow* target);
	sf::FloatRect getGlobalBounds();

	const sf::Vector2f getPosition();
	void updateKeytime();
	const bool getKeytime();
	void setPosition(sf::Vector2f pos);
	void gainHP(int xp);
	void loseHP(int hp);
};

