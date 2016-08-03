#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "player.h"

class Backer
{
public:
	Backer();
	~Backer();
	void render(sf::RenderWindow *window);
	void update(player *pPlayer);
private:
	sf::Texture *backerTexture;
	sf::Sprite *backerSprite;
	sf::Texture *backerXPTexture;
	sf::Sprite *backerXPSprite;
	sf::Texture *backerLevelTexture;
	sf::Sprite *backerLevelSprite;
	sf::Text *backerLevelText;
	sf::Font *font;
	sf::Text *textHealth;
	sf::Text *textCoins;
	sf::Texture *playerHealthBarTexture;
	sf::Sprite *playerHealthBarSprite;
	sf::Sprite *playerEnergyBarSprite;
	sf::Text *textEnergy;
	sf::Text *textArmor;
	sf::Sprite *playerArmorBarSprite;
	sf::Text *enterText;
};

