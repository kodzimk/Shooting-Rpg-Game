#pragma once
#include"stdfah.h"
#include"Enemy.h"

class Bullet {
public:
	sf::Texture texture;
	sf::Sprite sprite;
	float x, y;

	Bullet(float rot,float x, float y)
	{
		texture.loadFromFile("res/Images/Player/Bullet.png");
		this->sprite.setTexture(this->texture);
		this->sprite.setTextureRect(sf::IntRect(500,0,50,70));
		this->sprite.setScale(0.3, 0.3);
		rot = rot * 3.14 / 180;

		this->x = std::cos(rot);
		this->y = std::sin(rot);

		this->sprite.setPosition(x , y);
		std::cout << this->x << " " << this->y<<"  "<<rot << "\n";
	}

	void render(sf::RenderWindow* window,float time)
	{
		this->sprite.move(x,y);
		window->draw(this->sprite);
	}
	const sf::FloatRect getGloablBounds()
	{
		return this->sprite.getGlobalBounds();
	}
};

class Weapon
{
public:
	sf::Texture texture;
	sf::Sprite sprite;


	

	std::vector<Bullet*> bullets;

	Weapon();
	~Weapon();

	
	float getRotaion();
	void setPosition(const sf::Vector2f pos);
	void update(const sf::Vector2f mouse_pos_view,const sf::Vector2f center);
	void render(sf::RenderWindow* window, float time);
	const sf::Vector2f getPosition();
};

