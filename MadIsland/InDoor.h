#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class InDoor
{
public:
	InDoor(std::string texturepath);
	void update();
	void render(sf::RenderWindow *window);
	const sf::Sprite &getSprite() { return *inSprite; }
	~InDoor();
private:
	sf::Texture *inTexture;
	sf::Sprite *inSprite;
};

