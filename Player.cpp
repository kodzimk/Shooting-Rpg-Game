#include "Player.h"

void Player::initVariables()
{
	this->animationTimer = 0.f;
	this->currentAnimation = 0;
	this->dt = 0.f;
}

Player::Player()
{
	this->texture.loadFromFile("res/Images/Player/PLAYER_SHEET2.png");

	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0,0,64,64));
	this->sprite.setScale(1, 1);
	this->sprite.setPosition(300, 300);
	

	this->initVariables();
}

Player::~Player()
{

}


//Functions

void Player::update()
{
	this->dt = clock.getElapsedTime().asMicroseconds();
	this->clock.restart();
	this->dt =dt/ 800;

	this->updateInputs();
}

void Player::updateInputs()
{
	bool isIdle = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (this->animationTimer < 12)
			this->animationTimer = 12;
		isIdle = false;
		this->animationTimer += dt*0.005;
		if (animationTimer > 16)animationTimer -= 3;
		this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		 if (this->animationTimer < 4)
			 this->animationTimer = 4;
		 isIdle = false;
		 this->animationTimer += dt * 0.005;
		 if (animationTimer >= 7) animationTimer -= 3;
		 this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		 if (this->animationTimer < 8)
			 this->animationTimer = 8;
		 isIdle = false;
		 this->animationTimer += dt * 0.005;
		 if (animationTimer >= 11)animationTimer -= 3;
		 this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		 isIdle = false;
		 this->animationTimer += dt * 0.005;
		 if (animationTimer > 3)animationTimer -= 3;
		 this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
	}

	if(isIdle)
	{
		this->animationTimer += dt * 0.005;
		if (animationTimer >= 7)animationTimer -=3;
		this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 0, 64, 64));
	}


	
}

void Player::render(sf::RenderWindow* target)
{
	target->draw(this->sprite);
}

const sf::Vector2f Player::getPosition()
{
	return this->sprite.getPosition();
}

void Player::setPosition(sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}
