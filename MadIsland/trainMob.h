#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "player.h"

#define MAX_TRAINMOBS 10
#define MAX_KNOCKBACK 10

class trainMob
{
public:
	trainMob(std::string texturepath);
	~trainMob();
	void render(sf::RenderWindow *window);
	const int &getMobHealth(int i) { return mobHealth[i]; }
	void takeDamage(int i,int val, player *pPlayer);
	sf::Sprite getSprite(int i);
private:
	sf::Texture *mobTexture;
	sf::Sprite *mobSprite[MAX_TRAINMOBS];
	sf::Texture *healthBar;
	sf::Sprite *healthBarSP[MAX_TRAINMOBS];
	int mobHealth[MAX_TRAINMOBS];
};

