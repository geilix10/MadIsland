#include "Mob.h"


Mob::Mob(sf::Vector2f pos)
{
	mobTexture = new sf::Texture;
	mobSprite = new sf::Sprite;
	mobTexture2 = new sf::Texture;
	changeSprite = new sf::Clock;
	mobHealthBar = new sf::Texture;
	mobHealthBarSP = new sf::Sprite;
	mobHealthBar->loadFromFile("Images\\balken.png");
	mobTexture->loadFromFile("Images\\mobSkull_new.png");
	mobTexture2->loadFromFile("Images\\mobSkull_new2.png");
	mobSprite->setTexture(*mobTexture);
	mobSprite->setPosition(pos);


	mobHealthBarSP = new sf::Sprite;
	mobHealthBarSP->setTexture(*mobHealthBar);
	mobHealthBarSP->setPosition(mobSprite->getPosition().x + 5, mobSprite->getPosition().y - 10.0f);
	mobHealthBarSP->setOrigin(mobHealthBar->getSize().x / 2.0f - 27.0f, mobHealthBar->getSize().y / 2.0f);
	mobHealthBarSP->setColor(sf::Color::Green);
	mobHealthBarSP->setScale(0.5f, 0.5f);

	isMobSpriteOne = false;
	mobHealth = MAX_MOBHEALTH;

}


Mob::~Mob()
{
}

void Mob::update(float frametime, player *pPlayer)
{
	if (Collision::CircleTest(pPlayer->getSprite(), *mobSprite))
	{
		/*float playerPosX = pPlayer->getSprite().getPosition().x - 50.0f;
		float playerPosY = pPlayer->getSprite().getPosition().y - 50.0f;
		float mobPosX = mobSprite->getPosition().x;
		float mobPosY = mobSprite->getPosition().y;*/

		if (pPlayer->getSprite().getPosition().x - 50.0f >  mobSprite->getPosition().x)
			mobSprite->move(+90 * frametime, 0);
		else
			mobSprite->move(-90 * frametime, 0);
		if (pPlayer->getSprite().getPosition().y - 50.0f >  mobSprite->getPosition().y)
			mobSprite->move(0, +90 * frametime);
		else
			mobSprite->move(0, -90 * frametime);
		std::cout << "Mob Position: " << mobSprite->getPosition().x << " Y: " << mobSprite->getPosition().y << "   Player Position: " << pPlayer->getSprite().getPosition().x << " Y: " << pPlayer->getSprite().getPosition().y << std::endl;
	}
	if (changeSprite->getElapsedTime().asMilliseconds() >= 150)
	{
		if (isMobSpriteOne == true)
		{
			mobSprite->setTexture(*mobTexture2);
			isMobSpriteOne = false;
		}
		else
		{
			mobSprite->setTexture(*mobTexture);
			isMobSpriteOne = true;
		}
		changeSprite->restart();
	}
	mobHealthBarSP->setTextureRect(sf::IntRect(0, 0, mobHealth, mobHealthBar->getSize().y));
	mobHealthBarSP->setPosition(mobSprite->getPosition().x + 90, mobSprite->getPosition().y + 60);
}

void Mob::render(sf::RenderWindow *window)
{
	window->draw(*mobSprite);
	window->draw(*mobHealthBarSP);
}

void Mob::giveDamage(int dmg, player *pPlayer)
{
	mobHealth -= dmg;
	switch (pPlayer->getPlayerWalkingSite())
	{
	case 1: mobSprite->setPosition(mobSprite->getPosition().x - 35, mobSprite->getPosition().y); break;
	case 2: mobSprite->setPosition(mobSprite->getPosition().x + 35, mobSprite->getPosition().y); break;
	case 3: mobSprite->setPosition(mobSprite->getPosition().x, mobSprite->getPosition().y - 35); break;
	case 4: mobSprite->setPosition(mobSprite->getPosition().x, mobSprite->getPosition().y + 35); break;
	}
	if (mobHealth <= 0)
	{
		mobHealth = 0;

		pPlayer->GivePlayerCoins(4);
	}
}