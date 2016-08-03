#include "Fountain.h"

sf::Texture fountainTexture2;
Fountain::Fountain(sf::Vector2f pos)
{
	fountainTexture = new sf::Texture;
	fountainSprite = new sf::Sprite;

	sf::Image subImage;
	subImage.loadFromFile("Images\\fountain1.png");
	subImage.createMaskFromColor(sf::Color::White);

	fountainTexture->loadFromImage(subImage);
	fountainSprite->setTexture(*fountainTexture);
	fountainSprite->setPosition(pos);
	fountainSprite->setScale(0.9f, 0.9f);

	fountainTexture2.loadFromFile("Images\\fountain2.png");
}


Fountain::~Fountain()
{
}


void Fountain::render(sf::RenderWindow *window)
{
	window->draw(*fountainSprite);
}

int fountainCounter;
bool spriteOneActive;
void Fountain::update()
{
	if (fountainCounter >= 150)
	{
		if (spriteOneActive == true)
		{
			fountainSprite->setTexture(fountainTexture2);
			spriteOneActive = false;
		}
		else
		{
			fountainSprite->setTexture(*fountainTexture);
			spriteOneActive = true;
		}
		fountainCounter = 0;
	}
	fountainCounter++;
}
