#include "Enemy.h"

Enemy::Enemy()
{
	this->animationTimer = 0.f;

	this->texture.loadFromFile("res/Images/Enemy/ZOMBIE_SHEET.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(90, 0, 25, 48));
	this->sprite.setPosition(500, 500);
	this->sprite.setScale(1.5, 1.2);

	this->font.loadFromFile("res/Fonts/Dosis-Light.ttf");
	this->hpText.setFont(this->font);
	this->hpText.setCharacterSize(25);

	this->hp = 20;
}

Enemy::~Enemy()
{
}

void Enemy::update(const float& dt, bool isPause, bool isCan,sf::Vector2f pos,Player& hp,std::vector<Bullet*>* bullets)
{
	int x = static_cast<int>(pos.x / 64);
	int y = static_cast<int>(pos.y / 64);

	this->collide(bullets);

	int x1 = static_cast<int>(this->sprite.getPosition().x / 64);
	int y1= static_cast<int>(this->sprite.getPosition().y/64);


	if (x1 == x1 && y1 == y)
	{
		this->takeDamage(hp);
		this->updateAnimation(dt, isPause, isCan, STATE::IDLE);
	}
	else if (x < x1)
	{
		this->updateAnimation(dt, isPause, isCan, STATE::WALK_LEFT);
	}
	 else if (x>x1)
		this->updateAnimation(dt, isPause, isCan, STATE::WALK_RIGHT);
	 else  if (y>y1)
		this->updateAnimation(dt, isPause, isCan, STATE::WALK_DOWN);
	 else if (y<y1)
		this->updateAnimation(dt, isPause, isCan, STATE::WALK_UP);
}

void Enemy::render(sf::RenderWindow* window)
{
	this->hpText.setString(std::to_string(this->hp));
	this->hpText.setPosition(this->sprite.getPosition().x + 10,this->sprite.getPosition().y-20);

	window->draw(this->sprite);
	window->draw(this->hpText);
}

void Enemy::updateAnimation(const float& dt,bool isPause,bool isCan,STATE state)
{
	bool isIdle = true;
	

	if (!isPause)
	{
		
		if (state==STATE::WALK_UP&&!isCan)
		{
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer > 3)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(90+30 * int(animationTimer), 144, 30, 48));
			this->sprite.move(0,-0.05);
		}
		if (state==STATE::WALK_LEFT&&!isCan)
		{
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer > 3)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(90+(30 * int(animationTimer)), 48, 30, 48));
			this->sprite.move(-0.05,0);
		}
		if (state==STATE::WALK_RIGHT&&!isCan)
		{
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer > 3)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(90+30 * int(animationTimer), 96, 30, 48));
			this->sprite.move(0.05,0);
		}
		if (state == STATE::WALK_DOWN&&!isCan)
		{
			isIdle = false;
			this->animationTimer += dt * 10.f;
			if (animationTimer > 3)animationTimer -= 3;
			this->sprite.setTextureRect(sf::IntRect(90+30 * int(animationTimer), 0, 30, 48));
			this->sprite.move(0, 0.05);
		}
	}
}

const sf::Vector2f Enemy::getPosition()
{
	return this->sprite.getPosition();
}

const sf::FloatRect Enemy::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

void Enemy::takeDamage(Player& hp)
{

	hp.hp -= 1;

	hp.filler.innerText.setString(std::to_string(hp.hp/100));
	hp.filler.innerShape.setSize(sf::Vector2f((hp.hp/100) * 1.5f, 40.f));
}

void Enemy::collide(std::vector<Bullet*>* bullets)
{
	auto iter = bullets->begin();
	for (size_t i = 0; i < bullets->size(); i++,iter++)
	{
		if (this->sprite.getGlobalBounds().intersects(bullets->at(i)->getGloablBounds()))
		{
			bullets->erase(iter);
			int a = rand() % 5;
			this->hp -= a;
			
		}
	}
}
