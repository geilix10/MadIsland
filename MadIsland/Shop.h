#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

#define PILL_PRICE 20
#define ARMOR_PRICE 50
#define LASER_PRICE 450
#define FIRE_BALL_PRICE 120

class Shop
{
public:
	Shop();
	~Shop();
	void render(sf::RenderWindow *window);
	void update();
	const sf::Sprite &getPillSprite() { return *pillSprite; }
	const sf::Sprite &getAmbosSprite() { return *ambosSprite; }
	const sf::Sprite &getLaserSprite() { return *laserBeamSprite; }
	const sf::Sprite &getFireBallSprite(){ return *fireBallSprite; }
private:
	sf::Texture *pillTexture;
	sf::Sprite *pillSprite;
	sf::Text *pillText;
	sf::Font *font;
	sf::Texture *ambosTexture;
	sf::Sprite *ambosSprite;
	sf::Text *ambosText;
	sf::Texture *laserBeam[3];
	sf::Sprite *laserBeamSprite;
	sf::Text *laserBeamText;
	sf::Texture *fireBallTexture[2];
	sf::Sprite *fireBallSprite;
	sf::Text *fireBallText;
};

