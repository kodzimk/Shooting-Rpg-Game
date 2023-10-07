#include "Player.h"

void Player::initVariables()
{
	this->animationTimer = 0.f;
	this->currentAnimation = 0;
	this->dt = 0.f;
	this->keyMaxTime = 10.f;
	this->hp = 10000;
	this->keyTime = 0.f;
	this->patronCount = 50;
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

void Player::update(const sf::Vector2f mouse_pos_view, const bool isPause,bool isCan)
{
	this->dt = this->clock.restart().asSeconds();


	this->updateKeytime();

	if (!isPause)
	{
		this->sword->update(mouse_pos_view, this->sprite.getPosition() + sf::Vector2f(this->sprite.getGlobalBounds().width / 2.f,
			this->sprite.getGlobalBounds().height / 2.2f));
	}
	this->updateInputs(isPause,isCan);
}

void Player::updateInputs(const bool isPause,bool isCan)
{
	bool isIdle = true;

	if (!isPause)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&!isCan)
		{
			if (this->animationTimer < 12)
				this->animationTimer = 12;
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer >= 15)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
			this->sprite.move(0,-0.05);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&!isCan)
		{
			if (this->animationTimer < 4)
				this->animationTimer = 4;
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer >= 7) animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
			this->sprite.move(-0.05,0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&!isCan)
		{
			if (this->animationTimer < 8)
				this->animationTimer = 8;
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer >= 11)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
			this->sprite.move(0.05,0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&!isCan)
		{
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer > 3)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(64 * int(animationTimer), 64, 64, 64));
			this->sprite.move(0, 0.05);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeytime()&&this->patronCount>0)
		{
			this->patronCount -= 1;
			std::string s = "P:" + std::to_string(this->patronCount);
			this->filler.backText.setString(s);

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
	this->filler.render(target);
}

sf::FloatRect Player::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
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

void Player::gainHP(int xp)
{
	int x = std::stoi(this->filler.innerText.getString().toWideString());
	x += xp;
	if (x <= 100)
	{
		this->filler.innerText.setString(std::to_string(x));
		this->filler.innerShape.setSize(sf::Vector2f(x * 1.5f, 40));
		hp = std::stoi(this->filler.innerText.getString().toWideString());
	}
}

void Player::loseHP(int hp)
{
	int x = std::stoi(this->filler.innerText.getString().toWideString());
	x -= hp;

	if (x >=0)
	{
		this->filler.innerText.setString(std::to_string(x));
		this->filler.innerShape.setSize(sf::Vector2f(x * 1.5f, 40));
		hp = std::stoi(this->filler.innerText.getString().toWideString());
	}
}
