#include "TileMap.h"

void TileMap::initTileMap()
{
	this->textureSheet.loadFromFile("res/Images/Tiles/tilesheet3.png");
	this->itemSheet.loadFromFile("res/Images/Player/stuff.png");

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++) {
			if ((y == 3&&x==8)||(y==9&&x==5)||(y==6&&x==9)|| (y == 7 && x == 10) || (y == 8 && x == 13) || (y == 4 && x == 10))
			{
				this->tiles.push_back(new tile(sf::Vector2f(x * 32, y * 32), 32, 32, 32, 32, false, this->itemSheet, true, 0));
				this->tiles.at(this->tiles.size() - 1)->sprite.setScale(1.5f, 1.5f);
			}

			if ((y == 7 && x == 9) || (y == 3 && x == 12) || (y == 9 && x == 14))
			{
				this->tiles.push_back(new tile(sf::Vector2f(x * 32, y * 32), 0, 0, 32, 32, false, this->itemSheet, true, 1));
				this->tiles.at(this->tiles.size() - 1)->sprite.setScale(1.5f, 1.5f);
			}

			if (this->map[y][x] == '0')
			{
				this->tiles.push_back(new tile(sf::Vector2f(x*64,y*64),0,64,64,64,true,this->textureSheet,false,0));
			}
			if (this->map[y][x] == '1')
			{
				this->tiles.push_back(new tile(sf::Vector2f(x * 64, y * 64), 0, 0, 64, 64, false, this->textureSheet, false, 0));
			}
			if (this->map[y][x] == '2')
			{
				this->tiles.push_back(new tile(sf::Vector2f(x * 64, y * 64), 0, 64, 64, 64, true, this->textureSheet, false, 0));
				this->tiles.at(this->tiles.size() - 1)->sprite.rotate(-90);
				this->tiles.at(this->tiles.size() - 1)->sprite.setPosition(x*64,(y+1)*64);
			}
		}
	}
}

TileMap::TileMap()
{
	this->initTileMap();
}

TileMap::~TileMap()
{
	for (size_t i = 0; i < this->tiles.size(); i++)
	{
		delete this->tiles[i];
	}
}

const bool TileMap::isCollide(Player* rect)
{

	for (size_t i = 0; i < this->tiles.size(); i++)
	{
		if (tiles[i]->collision)
		{
			if (this->tiles[i]->sprite.getGlobalBounds().intersects(rect->getGlobalBounds()))
			{
				if (rect->getPosition().y > 500)
				{
					rect->sprite.move(0, -0.1);
				}
				if (rect->getPosition().y < 150)
				{
					rect->sprite.move(0, 0.1);
				}

				if (rect->getPosition().x > 800)
				{
					rect->sprite.move(-0.05,0);
				}

				if (rect->getPosition().x <150)
				{
					rect->sprite.move(0.05,0);
				}
				return true;
			}
		}
		else if (this->tiles[i]->isCanTake)
		{
			if (this->tiles[i]->sprite.getGlobalBounds().intersects(rect->getGlobalBounds()))
			{
				if (this->tiles[i]->type == 0)
				{
					rect->patronCount += 10;
					rect->filler.backText.setString("P:" + std::to_string(rect->patronCount));
					this->tiles[i]->sprite.setScale(0, 0);
				}
				else if (this->tiles[i]->type == 1)
				{
					int a = rand() % 1500;
					int b = 10000 - rect->hp;
					int c = a - b;
					if (rect->hp + a <= 10000)
					{
						rect->hp += a;
						rect->filler.innerText.setString(std::to_string(rect->hp/100));
						this->tiles[i]->sprite.setScale(0, 0);
					}
					else
					{
						rect->hp += c;
						rect->filler.innerText.setString(std::to_string(rect->hp / 100));
						this->tiles[i]->sprite.setScale(0, 0);
					}
				}
				
			}
		}
	}
	return false;
}

const bool TileMap::isCollide(Enemy* rect)
{

	for (size_t i = 0; i < this->tiles.size(); i++)
	{
		if (tiles[i]->collision)
		{
			if (this->tiles[i]->sprite.getGlobalBounds().intersects(rect->getGlobalBounds()))
			{
				if (rect->getPosition().y > 500)
				{
					rect->sprite.move(0, -0.1);
				}
				if (rect->getPosition().y < 150)
				{
					rect->sprite.move(0, 0.1);
				}

				if (rect->getPosition().x > 800)
				{
					rect->sprite.move(-0.05, 0);
				}

				if (rect->getPosition().x < 150)
				{
					rect->sprite.move(0.05, 0);
				}
				return true;
			}
		}
	}
	return false;
}

void TileMap::render(sf::RenderWindow* window)
{
	for (size_t i = 0; i < this->tiles.size(); i++)
	{
		window->draw(this->tiles[i]->sprite);
	}
	for (size_t i = 0; i < this->items.size(); i++)
	{
		window->draw(this->items[i]->sprite);
	}
}
