#include "Player.h"

void Player::initVariables()
{
	this->animationTimer = 0.f;
	this->currentAnimation = 0;
	this->dt = 0.f;
	this->keyMaxTime = 10.f;
	this->keyTime = 0.f;
}

Player::Player()
{
	this->texture.loadFromFile("res/Images/Player/PLAYER_SHEET2.png");

	this->sword = new Weapon();
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0,0,64,64));
	this->sprite.setScale(1, 1);
	this->sprite.setPosition(300, 300);
	

	this->initVariables();
}

Player::~Player()
{
	delete this->sword;
}


//Functions

void Player::update(const sf::Vector2f mouse_pos_view, const bool isPause)
{
	this->dt = this->clock.restart().asSeconds();


	this->updateKeytime();

	if (!isPause)
	{
		this->sword->update(mouse_pos_view, this->sprite.getPosition() + sf::Vector2f(this->sprite.getGlobalBounds().width / 2.f,
			this->sprite.getGlobalBounds().height / 2.2f));
	}
	this->updateInputs(isPause);
}

void Player::updateInputs(const bool isPause)
{
	bool isIdle = true;

	if (!isPause)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (this->animationTimer < 12)
				this->animationTimer = 12;
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer >= 15)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (this->animationTimer < 4)
				this->animationTimer = 4;
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer >= 7) animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (this->animationTimer < 8)
				this->animationTimer = 8;
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer >= 11)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer > 3)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeytime())
		{
			this->sword->bullets.push_back(new Bullet(this->sword->getRotaion(), this->sword->getPosition().x, this->sword->getPosition().y));
		}
	}


	if(isIdle)
	{
		this->animationTimer += dt * 10.f;
		if (animationTimer >= 7)animationTimer -=3;
		this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 0, 64, 64));
	}


	
}

void Player::render(sf::RenderWindow* target)
{
	target->draw(this->sprite);
	this->sword->render(target,this->dt);
}

const sf::Vector2f Player::getPosition()
{
	return this->sprite.getPosition();
}

void Player::updateKeytime()
{
	if (this->keyTime < this->keyMaxTime)
		this->keyTime += 100.f * this->dt;
}

const bool Player::getKeytime()
{
	if (this->keyTime > this->keyMaxTime)
	{
		this->keyTime = 0.f;
		return true;
	}
	return false;
}

void Player::setPosition(sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}
