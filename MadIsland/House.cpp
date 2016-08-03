#include "House.h"


House::House(std::string texturePath, sf::Vector2f pos)
{
	houseTexture = new sf::Texture;
	houseSprite = new sf::Sprite;

	sf::Image subImage;
	subImage.loadFromFile(texturePath);
	subImage.createMaskFromColor(sf::Color::White);

	houseTexture->loadFromImage(subImage);
	houseSprite->setTexture(*houseTexture);
	houseSprite->setPosition(pos);
	houseSprite->setScale(0.9f, 0.9f);
}


House::~House()
{
}

void House::render(sf::RenderWindow *window)
{
	window->draw(*houseSprite);
}