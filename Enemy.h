#pragma once
#include"stdfah.h"
#include"Player.h"

enum STATE {
	IDLE = 0,
	WALK_LEFT,
	WALK_RIGHT,
	WALK_UP,
	WALK_DOWN
};

class Enemy
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	float animationTimer;


	Enemy();
	~Enemy();

	void update(const float&dt,bool isPause, bool isCan, sf::Vector2f pos,Player& hp);
	void render(sf::RenderWindow* window);
	void updateAnimation(const float& dt,bool isPause, bool isCan, STATE state);
	const sf::Vector2f getPosition();
	const sf::FloatRect getGlobalBounds();
	void takeDamage(Player& hp);

};

