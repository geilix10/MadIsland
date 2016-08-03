#include "trainMob.h"

float xy[10][2] = 
{
	{ 570.0f, 310.0f },
	{ 705.0f, 310.0f },
	{ 836.0f, 310.0f },
	{ 836.0f, 396.0f },
	{ 705.0f, 396.0f },
	{ 570.0f, 396.0f },
	{ 836.0f, 495.0f },
	{ 705.0f, 495.0f },
	{ 570.0f, 495.0f },
	{ 126.0f, 230.0f },
};


trainMob::trainMob(std::string texturepath)
{
	mobTexture = new sf::Texture;
	healthBar = new sf::Texture;
	mobTexture->loadFromFile(texturepath);
	healthBar->loadFromFile("Images\\balken.png");
	for (int i = 0; i < MAX_TRAINMOBS; i++)
	{
		mobSprite[i] = new sf::Sprite;
		mobSprite[i]->setTexture(*mobTexture);
		mobSprite[i]->setPosition(xy[i][0],xy[i][1]);
		mobSprite[i]->setScale(0.8f, 0.8f);
		mobHealth[i] = 100;

		healthBarSP[i] = new sf::Sprite;
		healthBarSP[i]->setTexture(*healthBar);
		healthBarSP[i]->setPosition(xy[i][0] + 5, xy[i][1] - 10.0f);
		healthBarSP[i]->setOrigin(healthBar->getSize().x / 2.0f - 27.0f, healthBar->getSize().y / 2.0f);
		healthBarSP[i]->setColor(sf::Color::Green);
		healthBarSP[i]->setScale(0.5f, 0.5f);
	}
}


trainMob::~trainMob()
{
}

void trainMob::render(sf::RenderWindow *window)
{
	for (int i = 0; i < MAX_TRAINMOBS; i++)
	{
		window->draw(*mobSprite[i]);
		healthBarSP[i]->setTextureRect(sf::IntRect(0, 0, mobHealth[i], healthBar->getSize().y));
		window->draw(*healthBarSP[i]);
	}
}

sf::Sprite trainMob::getSprite(int i)
{
	return *mobSprite[i];
}

void trainMob::takeDamage(int i, int val, player *pPlayer)
{
	mobHealth[i] -= val;
	switch (pPlayer->getPlayerWalkingSite())
	{
	case 1: mobSprite[i]->setPosition(mobSprite[i]->getPosition().x - 15, mobSprite[i]->getPosition().y); healthBarSP[i]->setPosition(mobSprite[i]->getPosition().x - 10, mobSprite[i]->getPosition().y -10); break;
	case 2: mobSprite[i]->setPosition(mobSprite[i]->getPosition().x + 15, mobSprite[i]->getPosition().y); healthBarSP[i]->setPosition(mobSprite[i]->getPosition().x + 20, mobSprite[i]->getPosition().y - 10); break;
	case 3: mobSprite[i]->setPosition(mobSprite[i]->getPosition().x, mobSprite[i]->getPosition().y - 15); healthBarSP[i]->setPosition(mobSprite[i]->getPosition().x +5, mobSprite[i]->getPosition().y - 25); break;
	case 4: mobSprite[i]->setPosition(mobSprite[i]->getPosition().x, mobSprite[i]->getPosition().y + 15); healthBarSP[i]->setPosition(mobSprite[i]->getPosition().x +5, mobSprite[i]->getPosition().y - 15); break;
	}
	if (mobHealth[i] <= 0)
	{
		mobSprite[i] = new sf::Sprite;
		mobHealth[i] = 0;
		
		pPlayer->GivePlayerCoins(3);
	}
}
