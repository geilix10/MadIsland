#include "fence.h"


fence::fence()
{
	verticalTexture = new sf::Texture;
	horizontalTexture = new sf::Texture;
	for (int i = 0; i < MAX_HORIZONTAL; i++)
	{
		horizontalSprite[i] = new sf::Sprite;
	}
	for (int i = 0; i < MAX_VERTICAL; i++)
	{
		verticalSprite[i] = new sf::Sprite;
	}

	horizontalTexture->loadFromFile("Images\\fence-horizontal.png");
	verticalTexture->loadFromFile("Images\\fence-vertical.png");

	for (int i = 0; i < MAX_HORIZONTAL; i++)
	{
		horizontalSprite[i]->setTexture(*horizontalTexture);
	}
	for (int i = 0; i < MAX_VERTICAL; i++)
	{
		verticalSprite[i]->setTexture(*verticalTexture);
	}
	horizontalSprite[0]->setPosition(370.0f, 0.0f);
	horizontalSprite[1]->setPosition(370.0f, 500.0f);
	horizontalSprite[2]->setPosition(525.0f, 245.0f);
	horizontalSprite[3]->setPosition(933.0f, 245.0f);
	verticalSprite[0]->setPosition(530.0f, 245.0f);
	verticalSprite[1]->setPosition(530.0f, 440.0f);
}


fence::~fence()
{
}

void fence::render(sf::RenderWindow *window)
{
	for (int i = 0; i < MAX_HORIZONTAL; i++)
	{
		window->draw(*horizontalSprite[i]);
	}
	for (int i = 0; i < MAX_VERTICAL; i++)
	{
		window->draw(*verticalSprite[i]);
	}
}

sf::Sprite fence::getSprite(int i, bool horVert)
{
	if (horVert == true)
		return *horizontalSprite[i];
	else
		return *verticalSprite[i];
}
