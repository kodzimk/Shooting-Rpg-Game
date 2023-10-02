#pragma once
#include"stdfah.h"


class Entity
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

	Entity();
	~Entity();

	void update();
	void render();
};

