#include "Weapon.h"

Weapon::Weapon()
{
	this->texture.loadFromFile("res/Images/Player/Weapon.png");

	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.2, 0.2);
}

Weapon::~Weapon()
{
	for (int i = 0;i< this->bullets.size();i++)
	{
		delete this->bullets[i];
	}
}

float Weapon::getRotaion()
{
	return this->sprite.getRotation();
}

void Weapon::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Weapon::update(const sf::Vector2f mouse_pos_view, const sf::Vector2f center)
{
	this->sprite.setPosition(center);

	float dx = mouse_pos_view.x - this->sprite.getPosition().x;
	float dY = mouse_pos_view.y - this->sprite.getPosition().y;

	float deg = atan2(dY, dx) * 180 / 3.14;

	this->sprite.setRotation(deg);

}

void Weapon::render(sf::RenderWindow* window,float time)
{
	window->draw(this->sprite);
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i]->render(window,time);
	}
}



const sf::Vector2f Weapon::getPosition()
{
	return this->sprite.getPosition();
}
