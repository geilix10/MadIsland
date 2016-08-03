#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>

class House
{
public:
	House(std::string texturePath, sf::Vector2f pos);
	~House();
	void render(sf::RenderWindow *window);
	const sf::Sprite &getSprite() { return *houseSprite; }
private:
	sf::Texture *houseTexture;
	sf::Sprite *houseSprite;
};

