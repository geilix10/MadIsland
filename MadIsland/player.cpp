#include "player.h"

sf::Texture downwards[3];
sf::Texture upwards[3];
sf::Texture left[3];
sf::Texture right[3];

sf::Texture weapon[8];


int walkStyle;
int walkingSite;

player::player(std::string texturePath, sf::Vector2f pos)
{
	playerTexture = new sf::Texture;
	playerSprite = new sf::Sprite;
	playerWeaponSprite = new sf::Sprite;
	playerWeaponTexture = new sf::Texture;

	sf::Image subImage;
	subImage.loadFromFile(texturePath);
	subImage.createMaskFromColor(sf::Color::White);

	playerTexture->loadFromImage(subImage);
	playerSprite->setTexture(*playerTexture);
	playerSprite->setPosition(pos);
	playerSprite->setScale(0.8f, 0.8f);

	downwards[0].loadFromFile("Images\\Character_Sprites_Walking_Downwards.png");
	downwards[1].loadFromFile("Images\\Character_Sprites_Walking_Downwards(2).png");
	downwards[2].loadFromFile("Images\\Character_Sprites_Walking_Downwards(3).png");

	upwards[0].loadFromFile("Images\\Character_Sprites_Walking_Upwards.png");
	upwards[1].loadFromFile("Images\\Character_Sprites_Walking_Upwards(2).png");
	upwards[2].loadFromFile("Images\\Character_Sprites_Walking_Upwards(3).png");

	left[0].loadFromFile("Images\\Character_Sprites_Walking_Left.png");
	left[1].loadFromFile("Images\\Character_Sprites_Walking_Left(2).png");
	left[2].loadFromFile("Images\\Character_Sprites_Walking_Left(3).png");

	right[0].loadFromFile("Images\\Character_Sprites_Walking_Right.png");
	right[1].loadFromFile("Images\\Character_Sprites_Walking_Right(2).png");
	right[2].loadFromFile("Images\\Character_Sprites_Walking_Right(3).png");

	weapon[0].loadFromFile("Images\\Sword(r1).png");
	weapon[1].loadFromFile("Images\\Sword(r2).png");

	weapon[2].loadFromFile("Images\\Sword(l1).png");
	weapon[3].loadFromFile("Images\\Sword(l2).png");

	weapon[4].loadFromFile("Images\\Sword(o1).png");
	weapon[5].loadFromFile("Images\\Sword(o2).png");

	weapon[6].loadFromFile("Images\\Sword(u1).png");
	weapon[7].loadFromFile("Images\\Sword(u2).png");


	walkStyle = 0;
	walkingSite = 0;
	playerHealth = MAX_HEALTH;
	gameOver = false;
	coins = 0;
	setTransparent = false;
	energy = MAX_ENERGY;
	energyLoadTime = MAX_ENERGY;
	sprintActivated = false;
	playerArmor = 10;
	inHouse = false;
	canBuyEPill = false;
	canBuyArmor = false;
	playerLevel = 0;
	playerMaxXP = 50;
	playerXP = 0;
	canBuyLaserBeam = false;
	canBuyFireBall = false;
}


player::~player()
{
}

sf::Clock delay;
sf::Clock fightDelay;
sf::Clock energyLoad;
sf::Clock sprintAbzieher;
int fightCounter = 0;
bool buyActive = false;
void player::update(float frametime)
{
	if (walkStyle >= 3)
	{
		walkStyle = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Left
	{
		if (cantWalk != 1)
		{
			if (sprintActivated == true)
			{
				playerSprite->move(-300 * frametime, 0);
			}
			else { playerSprite->move(-100 * frametime, 0); }
			playerSprite->setTexture(left[walkStyle]);
			walkingSite = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Right
	{
		if (cantWalk != 2)
		{
			if (sprintActivated == true)
			{
				playerSprite->move(+300 * frametime, 0);
			}
			else { playerSprite->move(+100 * frametime, 0); }
			playerSprite->setTexture(right[walkStyle]);
			walkingSite = 2;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Updwards
	{
		if (cantWalk != 3)
		{
			if (sprintActivated == true)
			{
				playerSprite->move(0, -300 * frametime);
			}
			else { playerSprite->move(0, -100 * frametime); }
			playerSprite->setTexture(upwards[walkStyle]);
			walkingSite = 3;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //Downwars
	{
		if (cantWalk != 4)
		{
			if (sprintActivated == true)
			{
				playerSprite->move(0, +300 * frametime);
			}
			else { playerSprite->move(0, +100 * frametime); }
			playerSprite->setTexture(downwards[walkStyle]);
			walkingSite = 4;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		if (fightDelay.getElapsedTime().asMilliseconds() >= 150)
		{
			if (fightCounter == 0)
			{
				playerWeaponSprite->setTexture(weapon[GetWeaponStyle(0)]);
				//fightCounter = 1;
			}
			else
			{
				playerWeaponSprite->setTexture(weapon[GetWeaponStyle(1)]);
				//fightCounter = 0;
			}
			SetWeaponSpritePosition();
			playerWeaponSprite->setScale(0.8f, 0.8f);
		}
	}
	else { playerWeaponSprite->setPosition(-1280.0f, -720.0f); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (energy >= 10)
		{
			sprintActivated = true;
		}
		else sprintActivated = false;
	}
	else sprintActivated = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		if (canEnter == true)
		{
			if (inHouse == false)
			{
				inHouse = true;
				playerSprite->setPosition(sf::Vector2f(88.0f, 292.0f));
				cantWalk = 0;
				canEnter = false;
			}
			else
			{
				inHouse = false;
				playerSprite->setPosition(sf::Vector2f(447.0f, 211.0f));
				cantWalk = 0;
				canEnter = false;
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		if (buyActive == false)
		{
			if (canBuyEPill == true)
			{
				if (coins >= PILL_PRICE)
				{
					coins -= PILL_PRICE;
					energyLoadTime -= 5;
					std::cout << "Bill bought" << std::endl;
				}
			}
			else if (canBuyArmor == true)
			{
				if (coins >= ARMOR_PRICE)
				{
					coins -= ARMOR_PRICE;
					playerArmor += 10;
					std::cout << "Armor bought" << std::endl;
				}
			}
			else if (canBuyLaserBeam == true)
			{
				if (coins >= LASER_PRICE)
				{
					coins -= LASER_PRICE;
					std::cout << "Not Implemented!!!" << std::endl;
				}
			}
			else if (canBuyFireBall == true)
			{
				if (coins >= FIRE_BALL_PRICE)
				{
					coins -= FIRE_BALL_PRICE;
					std::cout << "Not implemented!!" << std::endl;
				}
			}
			buyActive = true;
		}
	}
	else { buyActive = false; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) //Debug Koords
	{
		coins++;
		std::cout << "X: " << playerSprite->getPosition().x << "Y: " << playerSprite->getPosition().y << " HP: " << playerHealth << " Armor: " << playerArmor << std::endl;
		playerXP++;
	}
	if (delay.getElapsedTime().asMilliseconds() >= 300)
	{
		delay.restart();
		walkStyle++;
	}
	if (fightDelay.getElapsedTime().asMilliseconds() >= 150)
	{
		fightDelay.restart();
		if (fightCounter == 0)
			fightCounter = 1;
		else if (fightCounter == 1)
			fightCounter = 0;
		//Other Function
		if (setTransparent == true)
		{
			setTransparent = false;
			playerSprite->setColor(sf::Color::White);
		}
	}
	if (energy <= 10)
		sprintActivated = false;
	if (energyLoad.getElapsedTime().asMilliseconds() >= energyLoadTime)
	{
		energyLoad.restart();
		if (energy <= MAX_ENERGY)
			energy++;
	} 
	if (sprintActivated == true && sprintAbzieher.getElapsedTime().asMilliseconds() >= 200)
	{
		sprintAbzieher.restart();
		energy -= 10;
	}
	if (playerArmor >= 100)
		playerArmor = 100;
	if (playerXP >= playerMaxXP)
	{
		playerLevel++;
		playerXP = 0;
		playerMaxXP = playerMaxXP + 25;
	}
	//std::cout << "SprintActivated: " << sprintActivated << std::endl;
}

void player::render(sf::RenderWindow *window)
{
	window->draw(*playerSprite);
	window->draw(*playerWeaponSprite);
}

void player::handle()
{

}

void player::takeDamage(int val)
{
	playerSprite->setColor(sf::Color::Red);
	if (playerArmor > 0)
	{
		if (val/2 > playerArmor)
		{
			playerHealth -= val/2 - playerArmor;
			playerArmor = 0;
		}
		else playerArmor -= val/2;
	}
	else
	{
		playerHealth -= val;
	}
	if (playerHealth <= 0)
	{
		playerHealth = 0;
		gameOver = true;
	}
	setTransparent = true;
	switch (getPlayerWalkingSite())
	{
		case 1: playerSprite->setPosition(playerSprite->getPosition().x + 50, playerSprite->getPosition().y); break;
		case 2: playerSprite->setPosition(playerSprite->getPosition().x - 50, playerSprite->getPosition().y); break;
		case 3: playerSprite->setPosition(playerSprite->getPosition().x, playerSprite->getPosition().y + 50); break;
		case 4: playerSprite->setPosition(playerSprite->getPosition().x, playerSprite->getPosition().y - 50); break;
	}
}

int player::getPlayerWalkingSite()
{
	return walkingSite;
}

sf::Vector2f player::getPlayerPosition()
{
	return sf::Vector2f(playerSprite->getPosition().x, playerSprite->getPosition().y);
}

int player::GetWeaponStyle(int val)
{
	int style = 0;
	if (val == 0)
	{
		switch (walkingSite)
		{
		case 1: style = 2; break;
		case 2: style = 0; break;
		case 3: style = 4; break;
		case 4: style = 6; break;
		default: break;
		}
	}
	else
	{
		switch (walkingSite)
		{
		case 1: style = 3; break;
		case 2: style = 1; break;
		case 3: style = 5; break;
		case 4: style = 7; break;
		default: break;
		}
	}
	return style;
}

void player::SetWeaponSpritePosition()
{
	if (walkingSite == 1)
	{
		playerWeaponSprite->setPosition(playerSprite->getPosition().x - 100,playerSprite->getPosition().y);
	}
	else if (walkingSite == 2)
	{
		playerWeaponSprite->setPosition(playerSprite->getPosition().x + 50, playerSprite->getPosition().y);
	}
	else if (walkingSite == 3)
	{
		playerWeaponSprite->setPosition(playerSprite->getPosition().x, playerSprite->getPosition().y - 60);
	}
	else if (walkingSite == 4)
	{
		playerWeaponSprite->setPosition(playerSprite->getPosition().x, playerSprite->getPosition().y + 30);
	}
}
