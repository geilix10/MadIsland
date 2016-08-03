#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

#define MAX_HORIZONTAL 4
#define MAX_VERTICAL 2

class fence
{
public:
	fence();
	~fence();
	void render(sf::RenderWindow *window);
	sf::Sprite getSprite(int i, bool horVert);
private:
	sf::Texture *horizontalTexture;
	sf::Texture *verticalTexture;
	sf::Sprite *horizontalSprite[MAX_HORIZONTAL];
	sf::Sprite *verticalSprite[MAX_VERTICAL];
};

