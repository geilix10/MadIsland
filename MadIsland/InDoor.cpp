#include "InDoor.h"


InDoor::InDoor(std::string texturepath)
{
	inTexture = new sf::Texture;
	inSprite = new sf::Sprite;

	inTexture->loadFromFile(texturepath);
	inSprite->setTexture(*inTexture);
	inSprite->setPosition(sf::Vector2f(19.0f, 284.0f));
}


InDoor::~InDoor()
{
}

void InDoor::update()
{

}

void InDoor::render(sf::RenderWindow *window)
{
	window->draw(*inSprite);
}
