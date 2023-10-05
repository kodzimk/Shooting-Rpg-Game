#pragma once
#include"stdfah.h"
#include"Player.h"

class tile {
public:
	bool collision;
	sf::Texture texture;
	sf::Sprite sprite;
	bool isCanTake;
	int type;

	tile(sf::Vector2f pos,int x,int y,int width,int height,bool collision, sf::Texture& texture, bool isCanTake, int type)
	{
		this->collision = collision;
		this->texture = texture;
		this->isCanTake = isCanTake;
		this->type = type;
		this->sprite.setTexture(this->texture);
		this->sprite.setTextureRect(sf::IntRect(x,y,height,width));
		this->sprite.setPosition(pos.x, pos.y);
	}
};

class TileMap
{
public:
	std::string map[10] = {
		"000000000000000",
		"211111111111112",
		"211111111111112",
		"211111111111112",
		"211111111111112",
		"211111111111112",
		"211111111111112",
		"211111111111112",
		"211111111111112",
		"000000000000000",
	};
	sf::Texture textureSheet;
	sf::Texture itemSheet;

	std::vector<tile*> tiles;
	std::vector<tile*> items;

	void initTileMap();

	TileMap();
	~TileMap();

	const bool isCollide(Player* rect);
	void render(sf::RenderWindow* window);
};


