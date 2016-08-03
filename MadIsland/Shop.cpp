#include "Shop.h"


Shop::Shop()
{
	font = new sf::Font;
	if (!font->loadFromFile("Other\\shopPack.ttf")) {}

	pillTexture = new sf::Texture;
	pillSprite = new sf::Sprite;
	pillText = new sf::Text;

	ambosText = new sf::Text;
	ambosTexture = new sf::Texture;
	ambosSprite = new sf::Sprite;

	laserBeam[0] = new sf::Texture; laserBeam[1] = new sf::Texture; laserBeam[2] = new sf::Texture;
	laserBeamSprite = new sf::Sprite;
	laserBeamText = new sf::Text;

	fireBallTexture[0] = new sf::Texture; fireBallTexture[1] = new sf::Texture;
	fireBallSprite = new sf::Sprite;
	fireBallText = new sf::Text;

	pillTexture->loadFromFile("Images\\energyPill.png");
	pillSprite->setTexture(*pillTexture);
	pillSprite->setPosition(450.0f, 60.0f);
	pillSprite->scale(0.8f, 0.8f);
	pillText->setFont(*font);
	pillText->setColor(sf::Color::White);
	pillText->setString("Buy Energy\nCosts: " + std::to_string(PILL_PRICE) + "c\nEnergy-Loadtime: -5\nBuy 'B'");
	pillText->setPosition(sf::Vector2f(450.0, 100.0));
	pillText->scale(0.5f, 0.5f);

	ambosTexture->loadFromFile("Images\\ambos.png");
	ambosSprite->setTexture(*ambosTexture);
	ambosSprite->setPosition(565.0f, 285.0f);
	ambosSprite->scale(0.8f, 0.8f);
	ambosText->setFont(*font);
	ambosText->setColor(sf::Color::White);
	ambosText->setString("Buy Armor\nCosts: " + std::to_string(ARMOR_PRICE) + "c\nArmor: +10\nBuy 'B'");
	ambosText->setPosition(sf::Vector2f(607.0f, 350.0f));
	ambosText->scale(0.5f, 0.5f);

	laserBeam[0]->loadFromFile("Images\\LaserBeam(1).png");
	laserBeam[1]->loadFromFile("Images\\LaserBeam(2).png");
	laserBeam[2]->loadFromFile("Images\\LaserBeam(3).png");
	laserBeamSprite->setTexture(*laserBeam[0]);
	laserBeamSprite->setPosition(1130.0f, 60.0f);
	laserBeamSprite->scale(0.8f, 0.8f);
	laserBeamText->setFont(*font);
	laserBeamText->setColor(sf::Color::White);
	laserBeamText->setString("Buy Laser-Beam\nCosts: " + std::to_string(LASER_PRICE) + "c\nDMG: +110\nBuy 'B'");
	laserBeamText->setPosition(sf::Vector2f(1130.0f, 100.0f));
	laserBeamText->scale(0.5f, 0.5f);

	fireBallTexture[0]->loadFromFile("Images\\fire_ball(1).png");
	fireBallTexture[1]->loadFromFile("Images\\fire_ball(2).png");
	fireBallSprite->setTexture(*fireBallTexture[0]);
	fireBallSprite->setPosition(600.0f, 60.0f);
	fireBallSprite->scale(0.8f, 0.8f);
	fireBallText->setFont(*font);
	fireBallText->setColor(sf::Color::White);
	fireBallText->setString("Buy Fire-Ball\nCosts: " + std::to_string(FIRE_BALL_PRICE) + "c\nDMG: +16\nBuy 'B'");
	fireBallText->setPosition(sf::Vector2f(600.0f, 100.0f));
	fireBallText->scale(0.5f, 0.5f);
}


Shop::~Shop()
{
}

void Shop::render(sf::RenderWindow *window)
{
	window->draw(*pillSprite);
	window->draw(*pillText);
	window->draw(*ambosSprite);
	window->draw(*ambosText);
	window->draw(*laserBeamSprite);
	window->draw(*laserBeamText);
	window->draw(*fireBallSprite);
	window->draw(*fireBallText);
}

sf::Clock laserBeamClock;
int laserBeamCount = 0;
int fireballCount = 0;
void Shop::update()
{
	if (laserBeamClock.getElapsedTime().asMilliseconds() >= 150)
	{
		laserBeamCount++;
		laserBeamSprite->setTexture(*laserBeam[laserBeamCount]);
		laserBeamClock.restart();
		if (laserBeamCount >= 2)
		{
			laserBeamCount = -1;
		}
		fireballCount++;
		fireBallSprite->setTexture(*fireBallTexture[fireballCount]);
		if (fireballCount >= 1)
		{
			fireballCount = -1;
		}
	}
}
