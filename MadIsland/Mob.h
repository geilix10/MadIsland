#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "player.h"
#include "Collision.h"
#define MAX_MOBHEALTH 120

class Mob
{
public:
	Mob(sf::Vector2f pos);
	~Mob();
	void update(float frametime, player *pPlayer);
	void render(sf::RenderWindow *window);
	void giveDamage(int dmg, player *pPlayer);
	const int &getMobHealth() { return mobHealth; }
	const sf::Sprite &getSprite() { return *mobSprite; }
	void resetSprite() { mobSprite = new sf::Sprite; }
private:
	sf::Texture *mobTexture;
	sf::Texture *mobTexture2;
	sf::Sprite *mobSprite;
	bool isMobSpriteOne = false;
	sf::Clock *changeSprite;
	int mobHealth;
	sf::Texture *mobHealthBar;
	sf::Sprite *mobHealthBarSP;
};

