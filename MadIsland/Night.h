#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

class Night
{
public:
	Night();
	~Night();
	void update();
	void render(sf::RenderWindow *window);
private:
	sf::Texture *nightTexture;
	sf::Sprite *nightSprite;
};

