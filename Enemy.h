#pragma once
#include"stdfah.h"
#include"Player.h"

class Player;
class Bullet;
class Weapon;

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
	int hp;
	sf::Font font;
	sf::Text hpText;

	Enemy();
	~Enemy();

	void update(const float&dt,bool isPause, bool isCan, sf::Vector2f pos,Player& hp, std::vector<Bullet*>* bullets);
	void render(sf::RenderWindow* window);
	void updateAnimation(const float& dt,bool isPause, bool isCan, STATE state);
	const sf::Vector2f getPosition();
	const sf::FloatRect getGlobalBounds();
	void takeDamage(Player& hp);
	void collide(std::vector<Bullet*>* bullets);
	
};

