#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Shop.h"

#define MAX_ENERGY 200
#define MAX_HEALTH 100

class player
{
public:
	player(std::string texturePath,sf::Vector2f pos);
	~player();

	void update(float frametime);
	void render(sf::RenderWindow *window);
	void handle();
	int GetWeaponStyle(int val);
	const sf::Sprite &getSprite() { return *playerSprite; }
	const int &getPlayerHealth() { return playerHealth; }
	const int &getPlayerEnergy() { return energy; }
	const int &getPlayerArmor() { return playerArmor; }
	const int &getPlayerCoins() { return coins; }
	const int &getPlayerLevel() { return playerLevel; }
	const int &getPlayerXP() { return playerXP; }
	const int &getPlayerMaxXP() { return playerMaxXP; }
	const sf::Sprite &getWeaponSprite() { return *playerWeaponSprite; }
	const void GivePlayerCoins(int coin) { coins += coin; }
	const void givePlayerXP(int xp) { playerXP += xp; }
	void takeDamage(int val);
	sf::Vector2f getPlayerPosition();
	int getPlayerWalkingSite();
	int cantWalk;
	bool canEnter;
	bool inHouse;
	bool gameOver;
	bool canBuyEPill,canBuyArmor,canBuyLaserBeam,canBuyFireBall;

private:
	sf::Texture *playerTexture;
	sf::Sprite *playerSprite;
	sf::Texture *playerWeaponTexture;
	sf::Sprite *playerWeaponSprite;
	int playerHealth; 
	int playerArmor;
	int coins;
	int energy;
	int energyLoadTime;
	int playerMaxXP;
	int playerXP;
	int playerLevel;
	bool sprintActivated;
	bool setTransparent;
	void SetWeaponSpritePosition();
};

